#include "Player/SPPlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "SPPlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Player/SPPlayerController.h"
#include "UI/SPChatWindow.h"

ASPPlayerCharacter::ASPPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->TargetArmLength = 400.f;
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	
}

void ASPPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASPPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (IsValid(EnhancedInputComponent) == true)
	{
		ASPPlayerController* PlayerController = Cast<ASPPlayerController>(GetController());
		if (IsValid(PlayerController) == true)
		{
			EnhancedInputComponent->BindAction(
				PlayerController->Move,
				ETriggerEvent::Triggered,
				this,
				&ASPPlayerCharacter::Move);
			EnhancedInputComponent->BindAction(
				PlayerController->Look,
				ETriggerEvent::Triggered,
				this,
				&ASPPlayerCharacter::Look);
			EnhancedInputComponent->BindAction(
				PlayerController->Enter,
				ETriggerEvent::Started,
				this,
				&ASPPlayerCharacter::Enter);
		}
	}
}

void ASPPlayerCharacter::Move(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Move"));

	FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator ControlRotation = GetController()->GetControlRotation();
	const FRotator ControlRotationYaw(0.f, ControlRotation.Yaw, 0.f);

	const FVector ForwardVector = FRotationMatrix(ControlRotationYaw).GetUnitAxis(EAxis::X);
	const FVector RightVector = FRotationMatrix(ControlRotationYaw).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardVector, MovementVector.X);
	AddMovementInput(RightVector, MovementVector.Y);
}

void ASPPlayerCharacter::Look(const FInputActionValue& Value)
{
	UE_LOG(LogTemp, Warning, TEXT("Look"));

	FVector2D LookVector = Value.Get<FVector2D>();

	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

void ASPPlayerCharacter::Enter(const FInputActionValue& Value)
{
	ASPPlayerController* PlayerController = Cast<ASPPlayerController>(GetController());
	if (IsValid(PlayerController) == true)
	{
		if (bEnter == false)
		{
			FInputModeGameAndUI InputModeUI;
			/*InputModeUI.SetWidgetToFocus(PlayerController->ChatWindowWidgetInstance->TakeWidget());
			InputModeUI.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);*/
			PlayerController->SetInputMode(InputModeUI);
			PlayerController->ChatWindowWidgetInstance->AddToViewport();
			bEnter = true;
		}
		else
		{
			FInputModeGameOnly InputModeGame;
			PlayerController->SetInputMode(InputModeGame);
			PlayerController->ChatWindowWidgetInstance->RemoveFromParent();
			bEnter = false;
		}
	}
}


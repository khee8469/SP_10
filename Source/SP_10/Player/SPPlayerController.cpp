#include "Player/SPPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "UI/SPChatWindow.h"

void ASPPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	bShowMouseCursor = false;

	//Input : IMC Add
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem
			= LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			EnhancedInputSubsystem->AddMappingContext(IMCPlayerCharacter, 0);
		}
	}
	

	if (HasAuthority() == false)
	{
		//Widget : ChatWindow Open
		FInputModeGameOnly InputModeGameOnly;
		SetInputMode(InputModeGameOnly);

		if (IsValid(ChatWindowWidgetClass) == true)
		{
			ChatWindowWidgetInstance = CreateWidget<USPChatWindow>(this, ChatWindowWidgetClass);
		}
	}
}

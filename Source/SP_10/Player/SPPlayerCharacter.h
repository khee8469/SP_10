#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SPPlayerCharacter.generated.h"

struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SP_10_API ASPPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASPPlayerCharacter();

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Move(const FInputActionValue& Value);

	void Look(const FInputActionValue& Value);

	void Enter(const FInputActionValue& Value);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	TObjectPtr<UCameraComponent> CameraComponent;

	bool bEnter;
};

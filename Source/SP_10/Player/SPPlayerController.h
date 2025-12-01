#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class SP_10_API ASPPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

//Input
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> IMCPlayerCharacter;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> Move;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> Look;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> Enter;

//Widget
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> ChatWindowWidgetClass;

public:
	UPROPERTY()
	TObjectPtr<UUserWidget> ChatWindowWidgetInstance;
};

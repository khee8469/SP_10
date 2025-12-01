#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SPChatWindow.generated.h"

class UEditableTextBox;

UCLASS()
class SP_10_API USPChatWindow : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UEditableTextBox> ChatWindow;
};

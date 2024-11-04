#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "GameOverWidget.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API UGameOverWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    UPROPERTY(meta = (BindWidgetAnim), BlueprintReadOnly, Transient)
    UWidgetAnimation* FadeOutScreenAnimation;

    UFUNCTION(BlueprintCallable)
    void PlayFadeOutAnimation();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading")
    TArray<FString> GameOverMessages;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* GameOverTextBlock;

    void SetGameOverMessage(bool IsPlayer1);

protected:
    virtual void NativeConstruct() override;
};

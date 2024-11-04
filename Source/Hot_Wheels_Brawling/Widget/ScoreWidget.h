#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/Image.h"
#include "ScoreWidget.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API UScoreWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

public:
    UPROPERTY(meta = (BindWidget))
    class UProgressBar* Player1Gauge;

    UPROPERTY(meta = (BindWidget))
    class UProgressBar* Player2Gauge;

    UFUNCTION()
    void IncreasePlayer1Gauge();

    UFUNCTION()
    void IncreasePlayer2Gauge();

private:
    void BindActions();

    FTimerHandle SmoothUpdateHandle_Player1;
    FTimerHandle SmoothUpdateHandle_Player2;

    float TargetPercent_Player1 = 0.0f;
    float TargetPercent_Player2 = 0.0f;

    UFUNCTION()
    void UpdatePlayer1GaugeSmoothly();

    UFUNCTION()
    void UpdatePlayer2GaugeSmoothly();
};
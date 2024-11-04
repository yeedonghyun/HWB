#include "ScoreWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ProgressBar.h"

void UScoreWidget::NativeConstruct()
{
    Super::NativeConstruct();

    BindActions();
}

void UScoreWidget::BindActions()
{
    if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0))
    {
        PlayerController->InputComponent->BindAction("Nitrous", IE_Pressed, this, &UScoreWidget::IncreasePlayer1Gauge);
        PlayerController->InputComponent->BindAction("Nitrous_2", IE_Pressed, this, &UScoreWidget::IncreasePlayer2Gauge);
    }
}

void UScoreWidget::IncreasePlayer1Gauge()
{
    if (Player1Gauge)
    {
        TargetPercent_Player1 = FMath::Clamp(Player1Gauge->Percent + 0.38f, 0.0f, 1.0f);
        GetWorld()->GetTimerManager().SetTimer(SmoothUpdateHandle_Player1, this, &UScoreWidget::UpdatePlayer1GaugeSmoothly, 0.02f, true);
    }
}

void UScoreWidget::IncreasePlayer2Gauge()
{
    if (Player2Gauge)
    {
        TargetPercent_Player2 = FMath::Clamp(Player2Gauge->Percent + 0.38f, 0.0f, 1.0f);
        GetWorld()->GetTimerManager().SetTimer(SmoothUpdateHandle_Player2, this, &UScoreWidget::UpdatePlayer2GaugeSmoothly, 0.02f, true);
    }
}

void UScoreWidget::UpdatePlayer1GaugeSmoothly()
{
    if (Player1Gauge)
    {
        float CurrentPercent = Player1Gauge->Percent;
        float NewPercent = FMath::Lerp(CurrentPercent, TargetPercent_Player1, 0.1f);

        Player1Gauge->SetPercent(NewPercent);
        if (FMath::IsNearlyEqual(NewPercent, TargetPercent_Player1, 0.01f))
        {
            GetWorld()->GetTimerManager().ClearTimer(SmoothUpdateHandle_Player1);
        }
    }
}

void UScoreWidget::UpdatePlayer2GaugeSmoothly()
{
    if (Player2Gauge)
    {
        float CurrentPercent = Player2Gauge->Percent;
        float NewPercent = FMath::Lerp(CurrentPercent, TargetPercent_Player2, 0.1f);

        Player2Gauge->SetPercent(NewPercent);

        if (FMath::IsNearlyEqual(NewPercent, TargetPercent_Player2, 0.01f))
        {
            GetWorld()->GetTimerManager().ClearTimer(SmoothUpdateHandle_Player2);
        }
    }
}
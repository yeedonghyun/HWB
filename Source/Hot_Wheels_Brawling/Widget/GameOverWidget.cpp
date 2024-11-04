#include "GameOverWidget.h"
#include "Kismet/KismetMathLibrary.h"

void UGameOverWidget::PlayFadeOutAnimation()
{
    if (FadeOutScreenAnimation)
    {
        PlayAnimation(FadeOutScreenAnimation);
    }
}

void UGameOverWidget::SetGameOverMessage(bool IsPlayer1)
{
    if (GameOverMessages.Num() > 0 && GameOverTextBlock)
    {
        FString Message;

        if (IsPlayer1) {
            Message = GameOverMessages[1];
        }
        else {
            Message = GameOverMessages[0];
        }

        GameOverTextBlock->SetText(FText::FromString(Message));
    }
}

void UGameOverWidget::NativeConstruct()
{
    Super::NativeConstruct();

    GameOverMessages = {
            TEXT("Player1 Win!!"),
            TEXT("Player2 Win!!")
    };
}

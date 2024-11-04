#include "LoadingWidget.h"
#include "Kismet/KismetMathLibrary.h"

void ULoadingWidget::HideLoaidngWidget()
{
	RemoveFromParent();

}

void ULoadingWidget::SetRandomLoadingMessage()
{
    if (LoadingMessages.Num() > 0 && LoadingTextBlock)
    {
        int32 RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, LoadingMessages.Num() - 1);
        FString RandomMessage = LoadingMessages[RandomIndex];

        LoadingTextBlock->SetText(FText::FromString(RandomMessage));
    }
}

void ULoadingWidget::NativeConstruct()
{
	Super::NativeConstruct();

    LoadingMessages = {
            TEXT("점점 빨라지는 트레드밀에서 끝까지 살아남아\n최후의 1인이 되세요")
    };
}

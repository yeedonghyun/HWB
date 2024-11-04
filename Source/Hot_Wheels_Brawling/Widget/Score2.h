#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Score2.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API UScore2 : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(meta = (BindWidget))
    UImage* Player2Progress; // 플레이어 2의 게이지 이미지
};

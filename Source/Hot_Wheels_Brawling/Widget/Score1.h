#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Score1.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API UScore1 : public UUserWidget
{
    GENERATED_BODY()

public:
    UPROPERTY(meta = (BindWidget))
    UImage* Player1Progress; // 플레이어 1의 게이지 이미지
};

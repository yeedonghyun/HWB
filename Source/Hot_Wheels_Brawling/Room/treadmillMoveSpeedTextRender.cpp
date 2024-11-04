#include "treadmillMoveSpeedTextRender.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

AtreadmillMoveSpeedTextRender::AtreadmillMoveSpeedTextRender()
{
    PrimaryActorTick.bCanEverTick = true;

    floorMaxSpeedTextRenderComp = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TimeText"));
    RootComponent = floorMaxSpeedTextRenderComp;

    textColor = FColor::White;

    floorMaxSpeedTextRenderComp->SetTextRenderColor(textColor);
    floorMaxSpeedTextRenderComp->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
    floorMaxSpeedTextRenderComp->SetWorldSize(200.0f);

    FRotator CurrentRotation = GetActorRotation();
    FRotator NewRotation = CurrentRotation + FRotator(0, 90, 0);
    SetActorRotation(NewRotation);

    floorSpeed = 9;
    speedIncreasePerSec = 0.2;
    floorMaxSpeed = 24.f;
    limitText = 2;
}

void AtreadmillMoveSpeedTextRender::BeginPlay()
{
    Super::BeginPlay();
}

void AtreadmillMoveSpeedTextRender::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (floorSpeed < floorMaxSpeed) {
        floorSpeed += speedIncreasePerSec * DeltaTime;
    }

    FString FloorSpeedString = FString::SanitizeFloat(floorSpeed);

    if (FloorSpeedString.Len() > limitText) {
        FloorSpeedString = FloorSpeedString.Left(limitText);
    }
    if (FloorSpeedString.EndsWith(TEXT("."))) {
        FloorSpeedString = FloorSpeedString.LeftChop(1);
    }

    floorMaxSpeedTextRenderComp->SetText(FText::FromString(FloorSpeedString));
}
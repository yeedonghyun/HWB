#include "DeathZone.h"
#include "Kismet/KismetMathLibrary.h"
#include "Characters/C_CH_CarBase.h"
#include "Characters/C_CH_CarBase_SecondPlayer.h"

ADeathZone::ADeathZone()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(FName("DeathZoneCollisionBox"));

    CollisionBox->SetupAttachment(StaticMesh);
    RootComponent = StaticMesh;
}

void ADeathZone::BeginPlay()
{
    Super::BeginPlay();

    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ADeathZone::OverlapBegin);
}

void ADeathZone::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (auto player1 = Cast<AC_CH_CarBase>(OtherActor)) {
        player1->bFalled = true;
    }
    else if (auto player2 = Cast<AC_CH_CarBase_SecondPlayer>(OtherActor)) {
        player2->bFalled = true;
    }    
}
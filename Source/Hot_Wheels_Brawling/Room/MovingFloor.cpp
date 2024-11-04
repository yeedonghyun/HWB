#include "MovingFloor.h"

AMovingFloor::AMovingFloor()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(FName("Box"));

    CollisionBox->SetupAttachment(StaticMesh);

    MoveDirection = FVector(0, 1, 0);
    Speed = 1000;
    SpeedIncreasePerSec = 100;
    MaxSpeed = 2000;
}

void AMovingFloor::BeginPlay()
{
    Super::BeginPlay();

    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AMovingFloor::OverlapBegin);
    CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AMovingFloor::OverlapEnd);
}

void AMovingFloor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (Speed < MaxSpeed) {
        Speed += SpeedIncreasePerSec * DeltaTime;
    }

    for (int32 i = 0; i < CollidedActors.Num(); i++)
    {
        if (CollidedActors[i]->GetFName() != "None" && CollidedActors[i] && CollidedActorsComponent[i] &&
            CollidedActorsComponent[i]->IsSimulatingPhysics() && CollidedActors[i] != this) {

            FVector CurLocation = CollidedActors[i]->GetActorLocation();
            FVector NewLocation = CurLocation + (MoveDirection * Speed * DeltaTime);
            CollidedActors[i]->SetActorLocation(NewLocation, false, nullptr, ETeleportType::TeleportPhysics);
        }
        else {
            CollidedActors.RemoveAt(i);
            CollidedActorsComponent.RemoveAt(i);
        }
    }
}

void AMovingFloor::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    int32 ActorIndex = CollidedActors.Find(OtherActor);
    if (ActorIndex == INDEX_NONE) {
        CollidedActors.Add(OtherActor);
        CollidedActorsComponent.Add(OtherComp);
    }
}

void AMovingFloor::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    int32 ActorIndex = CollidedActors.Find(OtherActor);
    if (OtherActor && (OtherActor != this) && ActorIndex != INDEX_NONE)
    {
        CollidedActors.RemoveAt(ActorIndex);
        CollidedActorsComponent.RemoveAt(ActorIndex);
    }
}
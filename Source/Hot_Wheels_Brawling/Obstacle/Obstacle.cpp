#include "Obstacle.h"
#include "Components/BoxComponent.h"

AObstacle::AObstacle()
{
    PrimaryActorTick.bCanEverTick = true;
    BaseStaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    RootComponent = BaseStaticMeshComp;

    BaseStaticMeshComp->SetSimulatePhysics(true);
    BaseStaticMeshComp->BodyInstance.SetCollisionProfileName("PhysicsActor");

    int index = SelectWeightedObject();
    UStaticMesh* mesh = MeshManager.GetObstaclesMesh(index);
    BaseStaticMeshComp->SetStaticMesh(mesh);

    RemoveAfterSec = 10.f;
}

void AObstacle::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld())
    {
        GetWorldTimerManager().SetTimer(TimerHandle, this, &AObstacle::RemoveOverlabEndActor, RemoveAfterSec, true);
    }
}

void AObstacle::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AObstacle::RemoveOverlabEndActor()
{
    GetWorldTimerManager().ClearTimer(TimerHandle);
    Destroy();
}

int AObstacle::SelectWeightedObject()
{
    int TotalWeight = 0;
    for (int Weight : ObjectWeights)
    {
        TotalWeight += Weight;
    }

    int RandomValue = FMath::RandRange(0, TotalWeight - 1);
    int CumulativeWeight = 0;

    for (int i = 0; i < ObjectWeights.Num(); i++)
    {
        CumulativeWeight += ObjectWeights[i];
        if (RandomValue < CumulativeWeight)
        {
            return i;
        }
    }
    return 0;
}
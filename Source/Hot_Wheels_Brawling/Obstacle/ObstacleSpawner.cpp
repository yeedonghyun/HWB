#include "ObstacleSpawner.h"
#include "Kismet/KismetMathLibrary.h"

AObstacleSpawner::AObstacleSpawner()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
    SpawnBox = CreateDefaultSubobject<UBoxComponent>(FName("ObstacleSpawnInBox"));

    SpawnBox->SetupAttachment(StaticMesh);

    SpawnIntervalSeconds = 2;
    ObstacleCountPerSpawn = 2;
    MaxObstacleCountPerSpawn = 10;
}

void AObstacleSpawner::BeginPlay()
{
    Super::BeginPlay();

    if (GetWorld()) {
        GetWorldTimerManager().SetTimer(ChanegeSpawnTimeHandle, this, &AObstacleSpawner::SetSpawnTimer, 10.f, true, 10.f);
        GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &AObstacleSpawner::SpawnRandomActor, SpawnIntervalSeconds, true);
    }
}

void AObstacleSpawner::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AObstacleSpawner::SpawnRandomActor()
{
    for (int32 i = 0; i < ObstacleCountPerSpawn; i++) {
        FVector Origin = SpawnBox->Bounds.Origin;
        FVector Extent = SpawnBox->Bounds.BoxExtent;

        FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extent);

        GetWorld()->SpawnActor<AObstacle>(AObstacle::StaticClass(), SpawnLocation, FRotator::ZeroRotator);
    }
}

void AObstacleSpawner::SetSpawnTimer()
{
    if (MaxObstacleCountPerSpawn > ObstacleCountPerSpawn) {
        ObstacleCountPerSpawn += 1;
    }
    else {
        GetWorldTimerManager().ClearTimer(ChanegeSpawnTimeHandle);
    }
}
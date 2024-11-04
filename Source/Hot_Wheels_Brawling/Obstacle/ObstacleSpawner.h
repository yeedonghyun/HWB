// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "../Obstacle/Obstacle.h"
#include "TimerManager.h"
#include "ObstacleSpawner.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API AObstacleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Editdefaultsonly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(Editdefaultsonly)
	UBoxComponent* SpawnBox;

	void SpawnRandomActor();
	void SetSpawnTimer();

	FTimerHandle SpawnTimerHandle;
	FTimerHandle ChanegeSpawnTimeHandle;

	int SpawnIntervalSeconds;
	int ObstacleCountPerSpawn;
	int MaxObstacleCountPerSpawn;

public:	
	virtual void Tick(float DeltaTime) override;
};

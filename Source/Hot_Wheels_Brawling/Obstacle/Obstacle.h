#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "../MeshManager.h"
#include "Obstacle.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API AObstacle : public AActor
{
	GENERATED_BODY()

public:
	AObstacle();

protected:
	virtual void BeginPlay() override;
	FTimerHandle TimerHandle;

	void RemoveOverlabEndActor();

	MeshManager MeshManager;

public:
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* BaseStaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
	float RemoveAfterSec;

private:
	int SelectWeightedObject();

	TArray<int> ObjectWeights = {
		3, // Bridge
		3, // Cogwheel
		3, // ConeBridge
		1, // Monkey
		3, // Cylinder
		3, // HalfCylinder
		1, // Hammer
		3, // LegoOne
		3, // LegoSix
		3  // LegoTwo
	};
};

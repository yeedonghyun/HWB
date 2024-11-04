// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MovingFloor.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API AMovingFloor : public AActor
{
	GENERATED_BODY()

public:
	AMovingFloor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly, Category = "Changeables")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(Editdefaultsonly)
	UBoxComponent* CollisionBox;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force")
	FVector MoveDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force")
	float SpeedIncreasePerSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Force")
	float MaxSpeed;

private:
	TArray<AActor*> CollidedActors;
	TArray<UPrimitiveComponent*> CollidedActorsComponent;
};
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "DeathZone.generated.h"

UCLASS()
class HOT_WHEELS_BRAWLING_API ADeathZone : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADeathZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Editdefaultsonly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(Editdefaultsonly)
	UBoxComponent* CollisionBox;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

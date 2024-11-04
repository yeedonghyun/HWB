#pragma once

#include "CoreMinimal.h"

class HOT_WHEELS_BRAWLING_API MeshManager
{
public:
    MeshManager();

    UFUNCTION(BlueprintCallable, Category = "MeshPath")
    UStaticMesh* GetRandomObstaclesMesh();

    UFUNCTION(BlueprintCallable, Category = "MeshPath")
    UStaticMesh* GetObstaclesMesh(int Index);

    UFUNCTION(BlueprintCallable, Category = "MeshPath")
    USkeletalMesh* GetRandomCharactersMesh(bool isPlayer1);

    UFUNCTION(BlueprintCallable, Category = "MeshPath")
    USkeletalMesh* GetCharactersMesh(int index, bool isPlayer1);

    UFUNCTION(BlueprintCallable, Category = "MeshPath")
    int GetObstaclesMeshCount() { return ObstacleStaticMeshes.Num(); }

    UFUNCTION(BlueprintCallable, Category = "MeshPath")
    int GetCharactersMeshCount(bool isPlayer1);

private:
    static TArray<UStaticMesh*> ObstacleStaticMeshes;
    static TArray<USkeletalMesh*> Player1SkeletalMeshes;
    static TArray<USkeletalMesh*> Player2SkeletalMeshes;

    static TArray<FString> ObstacleMeshPathes;
    static TArray<FString> Player1MeshPathes;
    static TArray<FString> Player2MeshPathes;
};

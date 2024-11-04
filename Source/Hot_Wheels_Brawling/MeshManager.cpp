#include "MeshManager.h"

TArray<UStaticMesh*> MeshManager::ObstacleStaticMeshes;
TArray<USkeletalMesh*> MeshManager::Player1SkeletalMeshes;
TArray<USkeletalMesh*> MeshManager::Player2SkeletalMeshes;


TArray<FString> MeshManager::ObstacleMeshPathes;
TArray<FString> MeshManager::Player1MeshPathes;
TArray<FString> MeshManager::Player2MeshPathes;

MeshManager::MeshManager()
{
    if (ObstacleMeshPathes.Num() == 0) {
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_bridge_toy_low.room_obstacle_bridge_toy_low'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_cogwheel_toy_low.room_obstacle_cogwheel_toy_low'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_Cone_bridge_low.room_obstacle_Cone_bridge_low'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_monkey_toy_low.room_obstacle_monkey_toy_low'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_Cylinder_toylow.room_obstacle_Cylinder_toylow'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_half_Cylinder_toy_low.room_obstacle_half_Cylinder_toy_low'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_Hammer_toy_low.room_obstacle_Hammer_toy_low'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_lego_one_toy_low.room_obstacle_lego_one_toy_low'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_lego_six_toy_low.room_obstacle_lego_six_toy_low'");
        ObstacleMeshPathes.Add("/Script/Engine.StaticMesh'/Game/TreadMill/Assets/Obstacles/room_obstacle_lego_two_toy_low.room_obstacle_lego_two_toy_low'");
    }

    if (ObstacleStaticMeshes.Num() == 0) {
        for (int i = 0; i < ObstacleMeshPathes.Num(); i++) {
            ConstructorHelpers::FObjectFinder<UStaticMesh> ObstacleMesh(*ObstacleMeshPathes[i]);
            if (ObstacleMesh.Succeeded()) {
                ObstacleStaticMeshes.Add(ObstacleMesh.Object);
            }
        }
    }

    if (Player1MeshPathes.Num() == 0) {
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/Epic/racing.racing'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/legendary/ambulance/ambulance.ambulance'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/legendary/delivery/delivery_car.delivery_car'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/rare/catpaw/cat_paw.cat_paw'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/rare/flowerpattern/flower_pattern.flower_pattern'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/rare/Military/Military.Military'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/uncommon/StuddedFabric/studded_fabric.studded_fabric'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/uncommon/verderGuatemalMarble/verder_guatemal_marble.verder_guatemal_marble'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/uncommon/Wood/wood.wood'");
        Player1MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/uncommon/GolaInlayMarbleTiles/gola_inlay_marble_tiles.gola_inlay_marble_tiles'");
    }

    if (Player1SkeletalMeshes.Num() == 0) {
        for (auto Path : Player1MeshPathes) {
            ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMesh(*Path);
            Player1SkeletalMeshes.Add(CharacterMesh.Object);
        }
    }

    if (Player2MeshPathes.Num() == 0) {
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Epic2/racing_car.racing_car'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Legen2/Ambulance/ambulance.ambulance'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Legen2/Delivery_Truck/delivery_truck.delivery_truck'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Rare2/CatFoot/cat_foot.cat_foot'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Rare2/GoldInlayMarbleTiles2/gold_inlay_marble_tiles.gold_inlay_marble_tiles'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Rare2/Military/military.military'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Uncommon2/GoldInlayMarbleTiles2/gold_inlay_marble_tiles.gold_inlay_marble_tiles'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Uncommon2/RrmakePrototypeVer3SkeletonMesh2/rrmake_prototype_ver3_skeleton_mesh.rrmake_prototype_ver3_skeleton_mesh'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Uncommon2/StuddedFabric2/studded_fabric.studded_fabric'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Uncommon2/VerdeGuatemalaMarble2/verde_guatemala_marble.verde_guatemala_marble'");
        Player2MeshPathes.Add("/Script/Engine.SkeletalMesh'/Game/TreadMill/Assets/Character/second/Uncommon2/Wood2/wood.wood'");
   }

    if (Player2SkeletalMeshes.Num() == 0) {
        for (auto Path : Player2MeshPathes) {
            ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMesh(*Path);
            Player2SkeletalMeshes.Add(CharacterMesh.Object);
        }
    }
}

UStaticMesh* MeshManager::GetRandomObstaclesMesh()
{
    int index = FMath::RandRange(0, ObstacleStaticMeshes.Num() - 1);
    return ObstacleStaticMeshes[index];
}

UStaticMesh* MeshManager::GetObstaclesMesh(int Index)
{
    if (Index >= ObstacleStaticMeshes.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("Obstacle index is out of array range: %d"), Index);
        return ObstacleStaticMeshes[0];
    }
    return ObstacleStaticMeshes[Index];
}

USkeletalMesh* MeshManager::GetRandomCharactersMesh(bool isPlayer1)
{
    if (isPlayer1) {
        int index = FMath::RandRange(0, Player1SkeletalMeshes.Num() - 1);
        return Player1SkeletalMeshes[index];
    }

    int index = FMath::RandRange(0, Player2SkeletalMeshes.Num() - 1);
    return Player2SkeletalMeshes[index];
}

USkeletalMesh* MeshManager::GetCharactersMesh(int index, bool isPlayer1)
{
    if (isPlayer1) {
        if (index >= Player1SkeletalMeshes.Num()) {
            UE_LOG(LogTemp, Warning, TEXT("Character index is out of array range: %d"), index);
            return Player1SkeletalMeshes[0];
        }

        return Player1SkeletalMeshes[index];
    }

    if (index >= Player2SkeletalMeshes.Num()) {
        UE_LOG(LogTemp, Warning, TEXT("Character index is out of array range: %d"), index);
        return Player2SkeletalMeshes[0];
    }

    return Player2SkeletalMeshes[index];
}

int MeshManager::GetCharactersMeshCount(bool isPlayer1)
{
    if (isPlayer1) {
        return Player1SkeletalMeshes.Num();
    }

    return Player2SkeletalMeshes.Num();
}

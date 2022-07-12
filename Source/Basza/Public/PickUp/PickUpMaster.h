// Basza. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUpMaster.generated.h"

class USphereComponent;
class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class BASZA_API APickUpMaster : public AActor
{
    GENERATED_BODY()

public:
    APickUpMaster();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* ItemMesh;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    UBoxComponent* CollisionComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    FVector ExtentCollisionComponent;

    UPROPERTY(VisibleAnywhere, Category = "PickUp")
    USphereComponent* SphereInteraction;

    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Weight;
};


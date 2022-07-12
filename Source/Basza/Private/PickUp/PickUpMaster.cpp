// Basza. All Rights Reserved


#include "PickUp/PickUpMaster.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine.h"


APickUpMaster::APickUpMaster()
{
 	PrimaryActorTick.bCanEverTick = true;

    Weight = 1.0f;
    Name = "Item";
    ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>("ItemMesh");
    SetRootComponent(ItemMesh);

	SphereInteraction = CreateDefaultSubobject<USphereComponent>("SphereInteraction");
    SphereInteraction->InitSphereRadius(40.0f);
    SphereInteraction->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    SphereInteraction->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

    CollisionComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
    CollisionComponent->InitBoxExtent(ExtentCollisionComponent);
    CollisionComponent->SetupAttachment(ItemMesh);
    CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    CollisionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
    
    SphereInteraction->SetupAttachment(ItemMesh);
    //SphereInteraction->AttachToComponent(WeaponMesh);
    

}


void APickUpMaster::BeginPlay()
{
	Super::BeginPlay();
	
    check(CollisionComponent);
}

void APickUpMaster::NotifyActorBeginOverlap(AActor* OtherActor) 
{
    Super::NotifyActorBeginOverlap(OtherActor);
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "PickUp ok");
    //Destroy();
}





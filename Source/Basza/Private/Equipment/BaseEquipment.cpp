// Basza. All Rights Reserved

#include "Components/StaticMeshComponent.h"
#include "Equipment/BaseEquipment.h"

ABaseEquipment::ABaseEquipment()
{
    PrimaryActorTick.bCanEverTick = true;

    LevelReg = 1;
    BaseDamageResist = 10.0f;
    ArmorType = EArmorType::E_Helmet;
}

void ABaseEquipment::BeginPlay() 
{
    Super::BeginPlay();
}

void ABaseEquipment::Tick(float DeltaTime) 
{
    Super::Tick(DeltaTime);
}
// Basza. All Rights Reserved

#include "Weapon/BaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

ABaseWeapon::ABaseWeapon()

{
    PrimaryActorTick.bCanEverTick = false;

    LevelReq = 1;
    WeaponType = EWeaponType::E_Default;
    DamageAmount = 1.0f;
}

void ABaseWeapon::BeginPlay()
{
    Super::BeginPlay();
}


AController* ABaseWeapon::GetController()
{
    const auto Pawn = Cast<APawn>(GetOwner());
    return Pawn ? Pawn->GetController() : nullptr;
}



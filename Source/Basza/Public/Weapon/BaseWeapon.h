// Basza. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "PickUp/PickUpMaster.h"
#include "BaseWeapon.generated.h"

//class UBoxComponent;
//class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EWeaponType: uint8
{
    E_Default   UMETA(DisplayName = "Default"),
    E_Sword     UMETA(DisplayName = "SWORD"),
    E_Hammer    UMETA(DisplayName = "HAMMER"),
    E_Axe       UMETA(DisplayName = "AXE"),
};

UCLASS()
class BASZA_API ABaseWeapon : public APickUpMaster
{
    GENERATED_BODY()

public:
    ABaseWeapon();
  

protected:

    virtual void BeginPlay() override;

private:
    AController* GetController();

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    float DamageAmount;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    int LevelReq;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
    EWeaponType WeaponType;


};

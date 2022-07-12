// Basza. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "PickUp/PickUpMaster.h"
#include "BaseEquipment.generated.h"




UENUM(BlueprintType)
enum class EArmorType : uint8
{
    E_Helmet       UMETA(DisplayName = "Helmet"),
    E_Chest        UMETA(DisplayName = "Chest"),
    E_Shield       UMETA(DisplayName = "Shield"),
};

UCLASS()
class BASZA_API ABaseEquipment : public APickUpMaster
{
    GENERATED_BODY()

public:
    ABaseEquipment();

    virtual void Tick(float DeltaTime) override;
    
    //The Level-requirement to use the armor
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
    int LevelReg;

    //The base damage resisitance
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
    float BaseDamageResist;

    // Type of armor
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment")
    EArmorType ArmorType;

protected:
    virtual void BeginPlay() override;


};

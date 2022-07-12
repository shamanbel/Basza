// Basza. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Weapon/BaseWeapon.h"
#include "PickUp/PickUpMaster.h"
#include "GameFramework/Character.h"
#include "BaszaBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UHealthComponent;
class UTextRenderComponent;
class UWeaponComponent;

USTRUCT(BlueprintType)
struct FInventory
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float WeightLimit;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<ABaseWeapon*> ItemList;

};

UCLASS()
class BASZA_API ABaszaBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaszaBaseCharacter(const FObjectInitializer& ObjInit);

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTextRenderComponent* HealthTextComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UWeaponComponent* WeaponComponent;

	virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimMontage* DeathAnimMontage;

    // The amout point till get next level
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int UpgradePoints;

    // Character is current Level
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int CurrentLevel;

    //The character is current exp points
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float ExperiencePoint;

    //The total amount of experience points required to level Up
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float ExperienceToLevel;


    // The amount of skill player currently has
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int Skill;

    // The amount of expirience player currently has
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int Experience;

    // The amount of might player currently has
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int Might;

    // The amount of dexterity player currently has
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int Dexterity;

    // The amount of endurance player currently has
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int Endurance;

    // The amount of intellect player currently has
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int Mind;

    // The attack spaad player currently has
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
     float AttackSpeed;

     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
     ABaseWeapon* CurrentWeapon;

     //The inventory structure for the character
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
     FInventory Inventory;

     //Determinate if character is overlapping an equipable item
     UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
     bool IsOverlappingItem;





    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool HasAttack;

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
    float GetMovementDirection() const;

    UFUNCTION(BlueprintCallable, Category = "Movement")
    bool IsRunning() const;

    //The character earns experience
    UFUNCTION(BlueprintCallable, Category = "Stats")
    void GainExperience(float expAmount);

    UFUNCTION(BlueprintCallable, Category = "Item")
    void AddToInventory(ABaseWeapon* item);

    //Allows the character to equip an item they are close to.
    void EquipItem();

    UFUNCTION()
    void StartHeal();

    UFUNCTION()
    void Attack();

private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);

    void OnDeath();
    void OnHealthChanged(float Health);

    bool IsMovingFWD = false;
    bool WantsToRun = false;
    void OnStartRunning();
    void OnStopRunning();
};

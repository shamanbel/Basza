// Basza. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASZA_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UHealthComponent();

	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintCallable, Category = "Health")
    void Heal(float HealAmount);
	
		UFUNCTION(BlueprintCallable)
    bool IsDead() const { return Health <= 0.0f; }

	FOnDeath OnDeath;
    FOnHealthChanged OnHealthChanged;

protected:
    virtual void BeginPlay() override;
    UFUNCTION()
    void TakeDamage(AActor* DamagedActor,     //
					float Damage,                         //
					const class UDamageType* DamageType,  //
					class AController* InstigatedBy,      //
					AActor* DamageCauser);


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClaimpMin = "0.0", ClampMax = "100.0"))
    float MaxHealth = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float Health = 0.0f;
	

	//The amount of armor player currently has
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    float Armor = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
    bool HasArmor;


private:
   

public:	
	

		
};

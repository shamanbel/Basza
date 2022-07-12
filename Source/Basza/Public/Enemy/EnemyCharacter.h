// Basza. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class BASZA_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AEnemyCharacter();

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Enemy")
    void TakeDamageEnemy(float damage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    float HealthEnemy;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    bool HasTakenDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
    bool IsEnemyDead;


public:	
	
	

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

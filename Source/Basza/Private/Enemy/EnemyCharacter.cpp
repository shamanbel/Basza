// Basza. All Rights Reserved


#include "Enemy/EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter()
{
 	PrimaryActorTick.bCanEverTick = false;

	HealthEnemy = 100.0f;
    IsEnemyDead = false;
    HasTakenDamage = false;
}


void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}



void AEnemyCharacter::TakeDamageEnemy(float damage)
{
    if (damage <= 0.0f) return;

    HealthEnemy = FMath::Clamp(HealthEnemy - damage, 0.0f, 100.0f);

    if (HealthEnemy == 0.0f)
    {
        IsEnemyDead = true;
    }
    else
    {
        HasTakenDamage = true;
    }
}




void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


// Basza. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Player/BaszaBaseCharacter.h"
#include "BaseWeaponTrigger.generated.h"


UCLASS()
class BASZA_API ABaseWeaponTrigger : public ATriggerBox
{
	GENERATED_BODY()

protected:
    virtual void BeginPlay() override;
public:
    ABaseWeaponTrigger();
	

};

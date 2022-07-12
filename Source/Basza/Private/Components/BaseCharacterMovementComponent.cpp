// Basza. All Rights Reserved


#include "Components/BaseCharacterMovementComponent.h"
#include "Player/BaszaBaseCharacter.h"



float UBaseCharacterMovementComponent::GetMaxSpeed() const 
{
    const float MaxSpeed = Super::GetMaxSpeed();
    const ABaszaBaseCharacter* Player = Cast<ABaszaBaseCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier: MaxSpeed;
}
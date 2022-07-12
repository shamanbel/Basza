// Basza. All Rights Reserved


#include "BaszaModeBase.h"
#include "Player/BaszaBaseCharacter.h"
#include "Player/BaszaPlayerController.h"

ABaszaModeBase::ABaszaModeBase() 
{
    DefaultPawnClass = ABaszaBaseCharacter::StaticClass();
    PlayerControllerClass = ABaszaPlayerController::StaticClass();
}
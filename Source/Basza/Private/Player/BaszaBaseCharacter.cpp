 // Basza. All Rights Reserved


#include "Player/BaszaBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/HealthComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/WeaponComponent.h"
#include "Components/BaseCharacterMovementComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Engine/SkeletalMeshSocket.h"



ABaszaBaseCharacter::ABaszaBaseCharacter(const FObjectInitializer& ObjInit)
     : Super(ObjInit.SetDefaultSubobjectClass<UBaseCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
 {
 	
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);

    HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
    HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
    HealthTextComponent->SetupAttachment(GetRootComponent());
	
    WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("WeaponComponent");


}


void ABaszaBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

   check(HealthComponent);
   check(HealthTextComponent);
   check(GetCharacterMovement());

   OnHealthChanged(HealthComponent->GetHealth());
   HealthComponent->OnDeath.AddUObject(this, &ABaszaBaseCharacter::OnDeath);
   HealthComponent->OnHealthChanged.AddUObject(this, &ABaszaBaseCharacter::OnHealthChanged);
   
   UpgradePoints = 5;
   Skill = 1;
   Experience = 1;
   Might = 1;
   Dexterity = 1;
   Mind = 1;
   Endurance = 1;

   ExperiencePoint = 0.0f;
   ExperienceToLevel = 2000.0f;
   CurrentLevel = 1;

   AttackSpeed = 1.0f;

   IsOverlappingItem = false;


}


void ABaszaBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ABaszaBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    check(WeaponComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABaszaBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaszaBaseCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &ABaszaBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &ABaszaBaseCharacter::AddControllerYawInput);

    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ABaszaBaseCharacter::OnStartRunning);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ABaszaBaseCharacter::OnStopRunning);

    PlayerInputComponent->BindAction("Heal", IE_Pressed, this, &ABaszaBaseCharacter::StartHeal);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABaszaBaseCharacter::Jump);
    PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ABaszaBaseCharacter::Attack);
    PlayerInputComponent->BindAction("Equip", IE_Pressed, this, &ABaszaBaseCharacter::EquipItem);

}

float ABaszaBaseCharacter::GetMovementDirection() const
{
    if (GetVelocity().IsZero()) return 0.0f;
    const auto VelocityNormal = GetVelocity().GetSafeNormal();
    const auto AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
    const auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
    const auto Degrees = FMath::RadiansToDegrees(AngleBetween);
	return CrossProduct.IsZero() ? Degrees : Degrees * FMath::Sign(CrossProduct.Z);
}

void ABaszaBaseCharacter::MoveForward(float Amount) 
{
    IsMovingFWD = Amount > 0.0f;
    if (Amount == 0.0f) return;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ABaszaBaseCharacter::MoveRight(float Amount) 
{
    if (Amount == 0.0f) return;
    AddMovementInput(GetActorRightVector(), Amount);
}

void ABaszaBaseCharacter::OnDeath() 
{
    PlayAnimMontage(DeathAnimMontage);

   // GetCharacterMovement()->DisableMovement();

    SetLifeSpan(5.0f);
}

void ABaszaBaseCharacter::OnHealthChanged(float Health) 
{
    HealthTextComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), Health)));
}

void ABaszaBaseCharacter::OnStartRunning() 
{
    WantsToRun = true;
}
 
void ABaszaBaseCharacter::OnStopRunning() 
{
    WantsToRun = false;
}

bool ABaszaBaseCharacter::IsRunning() const
{
    return WantsToRun && IsMovingFWD && !GetVelocity().IsZero();
}

void ABaszaBaseCharacter::GainExperience(float expAmount)
{
    ExperiencePoint += expAmount;

    if (ExperiencePoint >= ExperienceToLevel)
    {
        ++CurrentLevel;
        ExperiencePoint -= ExperienceToLevel;
        ExperienceToLevel += 500.0f;// next level more harder
    }  
    

}

void ABaszaBaseCharacter::AddToInventory(ABaseWeapon* item) 
{
    Inventory.ItemList.Add(item);
}

void ABaszaBaseCharacter::EquipItem() 
{
    if (IsOverlappingItem)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "We PickUp an Item");
    }
}

void ABaszaBaseCharacter::StartHeal() {}

void ABaszaBaseCharacter::ABaszaBaseCharacter::Attack()
{
    HasAttack = true;
}



//void ABaszaBaseCharacter::ForwardTraceC() 
//{
//    if (!GetWorld()) return;
//   
//
//    const FVector TraceStart = GetActorLocation();
//    const FVector TraceEnd = TraceStart + GetActorForwardVector() * 150.0f;
//    
//
//    FHitResult HitResult;
//
//
//    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
//
//
//    if (HitResult.bBlockingHit)
//    {
//        DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Green, false, 1.0f, 3.0f); 
//        WallNormal = HitResult.Normal;
//        WallLocation = HitResult.Location;
//    }
//
//}
//
//void ABaszaBaseCharacter::HeightTraceC() 
//{
//    if (!GetWorld()) return;
//   const FVector TraceStart = GetActorLocation() + (0, 0, 500.0f) + GetActorForwardVector() * 75.0f;
//    const FVector TraceEnd = TraceStart - (0, 0, 500.0f);
//    
//      DrawDebugLine(GetWorld(), TraceStart, TraceEnd, FColor::Red, false, 1.0f, 3.0f); 
//
//    FHitResult HitResult; 
//
//    GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
//
//    if (HitResult.bBlockingHit)
//    {
//        HeaghtLocation = HitResult.Location;
//    }
//
//}




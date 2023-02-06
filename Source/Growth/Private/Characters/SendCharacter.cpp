// Electrum Labs LLC 2023


#include "Characters/SendCharacter.h"

#include "Components/SphereComponent.h"

// Sets default values
ASendCharacter::ASendCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	CurrentHealth = MaximumHealth;
	SendState = ESendState::Moving;

	AttackRange.Add(125.f);

	AttackRangeLevel = 0;
	AttackDamageLevel = 0;
	AttackPenetrationLevel = 0;
	ArmorLevel = 0;
	AttackSpeedLevel = 0;

}

// Called when the game starts or when spawned
void ASendCharacter::BeginPlay()
{
	Super::BeginPlay();

	UpdateUpgradeLevels();

	if (OwningUpgradeComponent)
	{
		OwningUpgradeComponent->OnUpgrade.AddDynamic(this, &ASendCharacter::UpdateUpgradeLevels);
	}
}


// Called every frame
void ASendCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASendCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASendCharacter::UpdateUpgradeLevels()
{
	if (OwningUpgradeComponent)
	{
		AttackRangeLevel = OwningUpgradeComponent->ReturnAttackRangeLevel();
		AttackDamageLevel = OwningUpgradeComponent->ReturnAttackDamageLevel();
		AttackPenetrationLevel = OwningUpgradeComponent->ReturnAttackPenetrationLevel();
		ArmorLevel = OwningUpgradeComponent->ReturnArmorLevel();
		AttackSpeedLevel = OwningUpgradeComponent->ReturnAttackSpeedLevel();
	}
}

void ASendCharacter::HandleDamage(float IncomingDamage, float IncomingArmorPenetration, ASendCharacter* InstigatingSend)
{
	float FinalDamage;
	if (Armor[ArmorLevel] - IncomingArmorPenetration > 0)
	{
		FinalDamage = IncomingDamage * (100 / (100 + Armor[ArmorLevel] - IncomingArmorPenetration));
	}
	else
	{
		FinalDamage = IncomingDamage + IncomingArmorPenetration;
	}

	CurrentHealth -= FinalDamage;

	K2_PostDamageEvent(FinalDamage, InstigatingSend);
}

// Electrum Labs LLC 2023


#include "Components/UpgradesComponent.h"

// Sets default values for this component's properties
UUpgradesComponent::UUpgradesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUpgradesComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUpgradesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UUpgradesComponent::UpgradeAttackRangeLevel()
{
	AttackRangeLevel = FMath::Clamp(AttackRangeLevel+1, 0, 3);
	OnUpgrade.Broadcast();
}

void UUpgradesComponent::UpgradeDamageLevel()
{
	AttackDamageLevel = FMath::Clamp(AttackDamageLevel+1, 0, 3);
	OnUpgrade.Broadcast();
}

void UUpgradesComponent::UpgradeAttackPenetrationLevel()
{
	AttackPenetrationLevel = FMath::Clamp(AttackPenetrationLevel+1, 0, 3);
	OnUpgrade.Broadcast();
}

void UUpgradesComponent::UpgradeArmorLevel()
{
	ArmorLevel = FMath::Clamp(ArmorLevel+1, 0, 3);
	OnUpgrade.Broadcast();
}

void UUpgradesComponent::UpgradeAttackSpeedLevel()
{
	AttackSpeedLevel = FMath::Clamp(AttackSpeedLevel+1, 0, 3);
	OnUpgrade.Broadcast();
}


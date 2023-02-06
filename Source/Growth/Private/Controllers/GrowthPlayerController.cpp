// Electrum Labs LLC 2023


#include "Controllers/GrowthPlayerController.h"

#include "Components/UpgradesComponent.h"


AGrowthPlayerController::AGrowthPlayerController()
{
	ResourceComponent = CreateDefaultSubobject<UResourceComponent>(TEXT("Resource Manager"));

	UpgradesComponent = CreateDefaultSubobject<UUpgradesComponent>(TEXT("Upgrades Manager"));

}

bool AGrowthPlayerController::BCanUpgradeAttackRange()
{
	TMap<ResourceType, float> ResourcePreq;
	ResourcePreq.Add(ResourceType::Gold, 500.f);
	return (UpgradesComponent->ReturnAttackRangeLevel() < 3) && ResourceComponent->bCheckIfCanAfford(ResourcePreq);
}

bool AGrowthPlayerController::BCanUpgradeAttackDamage()
{
	TMap<ResourceType, float> ResourcePreq;
	ResourcePreq.Add(ResourceType::Gold, 500.f);
	return (UpgradesComponent->ReturnAttackDamageLevel() < 3) && ResourceComponent->bCheckIfCanAfford(ResourcePreq);
}

bool AGrowthPlayerController::BCanUpgradeAttackPenetration()
{
	TMap<ResourceType, float> ResourcePreq;
	ResourcePreq.Add(ResourceType::Gold, 500.f);
	return (UpgradesComponent->ReturnAttackPenetrationLevel() < 3) && ResourceComponent->bCheckIfCanAfford(ResourcePreq);
}

bool AGrowthPlayerController::BCanUpgradeAttackSpeed()
{
	TMap<ResourceType, float> ResourcePreq;
	ResourcePreq.Add(ResourceType::Gold, 500.f);
	return (UpgradesComponent->ReturnAttackSpeedLevel() < 3) && ResourceComponent->bCheckIfCanAfford(ResourcePreq);
}

bool AGrowthPlayerController::BCanUpgradeArmor()
{
	TMap<ResourceType, float> ResourcePreq;
	ResourcePreq.Add(ResourceType::Gold, 500.f);
	return (UpgradesComponent->ReturnArmorLevel() < 3) && ResourceComponent->bCheckIfCanAfford(ResourcePreq);
}


// Electrum Labs LLC 2023


#include "Components/ResourceComponent.h"

// Sets default values for this component's properties
UResourceComponent::UResourceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

	Wood = 50.f;
	WoodCollectionRate = 0.2;
	Food = 100.f;
	FoodCollectionRate = 0.25;
	Gold = 10.f;
	GoldCollectionRate = 0.1;
	Ore = 10.f;
	OreCollectionRate = 0.15f;

	MaximumSupply = 5;
}


// Called when the game starts
void UResourceComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GetWorld()->GetTimerManager().SetTimer(CollectionTimerHandle, this, &UResourceComponent::UpdateCollections, 0.1f, true, 0.f);

	
}


// Called every frame
void UResourceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	// ...
}

void UResourceComponent::UpdateCollections()
{
	DeltaWood(WoodCollectionRate);
	DeltaFood(FoodCollectionRate);
	DeltaGold(GoldCollectionRate);
	DeltaOre(OreCollectionRate);
}

void UResourceComponent::DeltaWood(float DeltaNum)
{
	Wood += DeltaNum;
}

void UResourceComponent::DeltaWoodCollectionRate(float DeltaNum)
{
	WoodCollectionRate += DeltaNum;
}

void UResourceComponent::DeltaFood(float DeltaNum)
{
	Food += DeltaNum;
}

void UResourceComponent::DeltaFoodCollectionRate(float DeltaNum)
{
	FoodCollectionRate += DeltaNum;
}

void UResourceComponent::DeltaGold(float DeltaNum)
{
	Gold += DeltaNum;
}

void UResourceComponent::DeltaGoldCollectionRate(float DeltaNum)
{
	GoldCollectionRate += DeltaNum;
}

void UResourceComponent::DeltaOre(float DeltaNum)
{
	Ore += DeltaNum;
}

void UResourceComponent::DeltaOreCollectionRate(float DeltaNum)
{
	OreCollectionRate += DeltaNum;
}

void UResourceComponent::DeltaCurrentSupply(int32 DeltaNum)
{
	CurrentSupply += DeltaNum;
}

void UResourceComponent::DeltaMaximumSupply(int32 DeltaNum)
{
	MaximumSupply += DeltaNum;
}

void UResourceComponent::HandleBuy(TMap<ResourceType, float> ResourceMap)
{
	for (auto& Resource : ResourceMap)
	{
		switch(Resource.Key)
		{
		case ResourceType::Food: DeltaFood(-Resource.Value);
			break;

		case ResourceType::Gold: DeltaGold(-Resource.Value);
			break;

		case  ResourceType::Ore: DeltaOre(-Resource.Value);	
			break;

		case ResourceType::Wood: DeltaWood(-Resource.Value);
			break;
		}
	}
}

void UResourceComponent::HandleSell(TMap<ResourceType, float> ResourceMap)
{
	for (auto& Resource : ResourceMap)
	{
		switch(Resource.Key)
		{
		case ResourceType::Food: DeltaFood(Resource.Value);
			break;

		case ResourceType::Gold: DeltaGold(Resource.Value);
			break;

		case  ResourceType::Ore: DeltaOre(Resource.Value);	
			break;

		case ResourceType::Wood: DeltaWood(Resource.Value);
			break;
		}
	}
}

bool UResourceComponent::bCheckIfCanAfford(TMap<ResourceType, float> ResourceMap)
{
	for (auto& Resource : ResourceMap)
	{
		switch(Resource.Key)
		{
		case ResourceType::Food:
			if (Food < Resource.Value) return false;
			break;

		case ResourceType::Gold: 
			if (Gold < Resource.Value) return false;
			break;

		case  ResourceType::Ore:
			if (Ore < Resource.Value) return false;
			break;

		case ResourceType::Wood:
			if (Wood < Resource.Value) return false;
			break;
		}
	}
	return true;
}

bool UResourceComponent::bCheckIfSupplyFits(int32 IncomingSupply)
{
	return IncomingSupply + CurrentSupply <= MaximumSupply;
}

bool UResourceComponent::HandleUpgrade(ResourceType ResourceToUpgrade)
{
	switch(ResourceToUpgrade)
	{
	case ResourceType::Food:
		return HandleFoodUpgrade();

	case ResourceType::Gold: 
		return HandleGoldUpgrade();

	case  ResourceType::Ore:
		return HandleOreUpgrade();

	case ResourceType::Wood:
		return HandleWoodUpgrade();

	default:
		return false;
	}
}

bool UResourceComponent::HandleFoodUpgrade()
{
	TMap<ResourceType, float> Prereq;
	Prereq.Add(ResourceType::Wood, 50.f);
	if (bCheckIfCanAfford(Prereq))
	{
		DeltaWood(-50.f);
		DeltaFoodCollectionRate(0.2);
		return true;
	}
	return false;
}

bool UResourceComponent::HandleGoldUpgrade()
{
	TMap<ResourceType, float> Prereq;
	Prereq.Add(ResourceType::Ore, 50.f);
	if (bCheckIfCanAfford(Prereq))
	{
		DeltaOre(-50.f);
		DeltaGoldCollectionRate(0.2);
		return true;
	}
	return false;
}

bool UResourceComponent::HandleWoodUpgrade()
{
	TMap<ResourceType, float> Prereq;
	Prereq.Add(ResourceType::Food, 50.f);
	if (bCheckIfCanAfford(Prereq))
	{
		DeltaFood(-50.f);
		DeltaWoodCollectionRate(0.2);
		return true;
	}
	return false;
}

bool UResourceComponent::HandleOreUpgrade()
{
	TMap<ResourceType, float> Prereq;
	Prereq.Add(ResourceType::Gold, 50.f);
	if (bCheckIfCanAfford(Prereq))
	{
		DeltaGold(-50.f);
		DeltaOreCollectionRate(0.2);
		return true;
	}
	return false;
}

bool UResourceComponent::HandleSupplyUpgrade()
{
	TMap<ResourceType, float> Prereq;
	Prereq.Add(ResourceType::Wood, 50.f);
	if (bCheckIfCanAfford(Prereq))
	{
		DeltaWood(-50.f);
		DeltaMaximumSupply(5);
		return true;
	}
	return false;
}




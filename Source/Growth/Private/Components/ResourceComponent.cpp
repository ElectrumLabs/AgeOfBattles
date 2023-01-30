// Electrum Labs LLC 2023


#include "Components/ResourceComponent.h"

// Sets default values for this component's properties
UResourceComponent::UResourceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

	Wood = 150.f;
	WoodCollectionRate = 0.15;
	Food = 200.f;
	FoodCollectionRate = 0.2;
	Gold = 100.f;
	GoldCollectionRate = 0.1;
	Ore = 0.f;
	OreCollectionRate = 0.f;

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
			if (Food < -Resource.Value) return false;
			break;

		case ResourceType::Gold: 
			if (Gold < -Resource.Value) return false;
			break;

		case  ResourceType::Ore:
			if (Ore < -Resource.Value) return false;
			break;

		case ResourceType::Wood:
			if (Wood < -Resource.Value) return false;
			break;
		}
	}
	return true;
}

bool UResourceComponent::bCheckIfSupplyFits(int32 IncomingSupply)
{
	return IncomingSupply + CurrentSupply <= MaximumSupply;
}




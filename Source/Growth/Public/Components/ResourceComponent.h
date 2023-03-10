// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Growth/Growth.h"

#include "ResourceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROWTH_API UResourceComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	int32 CurrentSupply;
	int32 MaximumSupply;

	float Wood;
	float WoodCollectionRate;

	float Food;
	float FoodCollectionRate;

	float Gold;
	float GoldCollectionRate;

	float Ore;
	float OreCollectionRate;
	
	float CurrentBaseHealth;
	float MaximumBaseHealth;

public:	
	// Sets default values for this component's properties
	UResourceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//  Update collection rate on timer
	FTimerHandle CollectionTimerHandle;
	
	void UpdateCollections();

	//  resource getters and setters

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	float GetWood()
	{
		return Wood;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	float GetWoodCollectionRate()
	{
		return WoodCollectionRate;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	float GetFood()
	{
		return Food;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	float GetFoodCollectionRate()
	{
		return FoodCollectionRate;
	}	
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	float GetGold()
	{
		return Gold;
	}
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	float GetGoldCollectionRate()
	{
		return GoldCollectionRate;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	float GetOre()
	{
		return Ore;
	}
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	float GetOreCollectionRate()
	{
		return OreCollectionRate;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	int32 GetCurrentSupply()
	{
		return CurrentSupply;
	}
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	int32 GetMaximumSupply()
	{
		return MaximumSupply;
	}

	//  setters/delta values
	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaWood(float DeltaNum);
	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaWoodCollectionRate(float DeltaNum);

	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaFood(float DeltaNum);
	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaFoodCollectionRate(float DeltaNum);

	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaGold(float DeltaNum);
	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaGoldCollectionRate(float DeltaNum);

	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaOre(float DeltaNum);
	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaOreCollectionRate(float DeltaNum);

	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaCurrentSupply(int32 DeltaNum);
	UFUNCTION(BlueprintCallable, Category = "Resources")
	void DeltaMaximumSupply(int32 DeltaNum);

	UFUNCTION(BlueprintCallable, Category = "Resources")
	void HandleBuy(TMap<ResourceType, float> ResourceMap);

	UFUNCTION(BlueprintCallable, Category = "Resources")
	void HandleSell(TMap<ResourceType, float> ResourceMap);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	bool bCheckIfCanAfford(TMap<ResourceType, float> ResourceMap);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resources")
	bool bCheckIfSupplyFits(int32 IncomingSupply);

	UFUNCTION(BlueprintCallable, Category = "Resource Upgrade")
	bool HandleUpgrade(ResourceType ResourceToUpgrade);

	UFUNCTION(Category = "Resource Upgrade")
	bool HandleFoodUpgrade();
	
	UFUNCTION(Category = "Resource Upgrade")
	bool HandleGoldUpgrade();

	UFUNCTION(Category = "Resource Upgrade")
	bool HandleWoodUpgrade();
	
	UFUNCTION(Category = "Resource Upgrade")
	bool HandleOreUpgrade();

	UFUNCTION(BlueprintCallable, Category = "Resource Upgrade")
	bool HandleSupplyUpgrade();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Resource Upgrade")
	bool BIsSupplyCapped();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float ReturnCurrentBaseHealth()
	{
		return CurrentBaseHealth;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float ReturnMaximumBaseHealth()
	{
		return MaximumBaseHealth;
	}

	UFUNCTION(BlueprintCallable)
	void DeltaCurrentBaseHealth(float Delta);
};

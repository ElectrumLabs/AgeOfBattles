// Electrum Labs LLC 2023

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "Growth/Growth.h"


#include "SendManager.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FSendInformation : public FTableRowBase
{

	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D* UnitImage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText SendName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EUnitType UnitType;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 UnitTier = 1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class ASendCharacter>  SendCharacter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TrainingTime;

	//  Send cost information
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	int32 SupplyCost;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	TMap<ResourceType, float> ResourceCost;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	float MaximumHealth;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	TArray<float> AttackRange;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	TArray<float> AttackDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	TArray<float> AttackPenetration;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	TArray<float> Armor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	TArray<float> AttackSpeed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	TMap<ResourceType, float> UnitTax;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	float GoldBounty;

};


UCLASS( BlueprintType, Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GROWTH_API USendManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USendManager();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	const int32 QueueLimit = 5;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	TArray<FSendInformation> SendQueue;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanAddToQueue();

	UPROPERTY(BlueprintReadWrite)
	EFactionType FactionType;

		
};

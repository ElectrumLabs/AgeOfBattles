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
	TSubclassOf<class ASendCharacter>  SendCharacter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TrainingTime;

	//  Send cost information
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	int32 SupplyCost;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Send Cost Information")
	TMap<ResourceType, float> ResourceCost;
	
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

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	TArray<FSendInformation> SendQueue;

		
};

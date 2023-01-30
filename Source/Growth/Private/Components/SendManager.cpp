// Electrum Labs LLC 2023


#include "Components/SendManager.h"

// Sets default values for this component's properties
USendManager::USendManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USendManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USendManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool USendManager::CanAddToQueue()
{
	return SendQueue.Num() < QueueLimit;
}


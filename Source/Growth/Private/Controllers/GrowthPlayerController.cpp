// Electrum Labs LLC 2023


#include "Controllers/GrowthPlayerController.h"

AGrowthPlayerController::AGrowthPlayerController()
{
	ResourceComponent = CreateDefaultSubobject<UResourceComponent>(TEXT("Resource Manager"));
}

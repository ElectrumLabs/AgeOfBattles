// Electrum Labs LLC 2023


#include "Controllers/GrowthController.h"

AGrowthController::AGrowthController()
{
	ResourceComponent = CreateDefaultSubobject<UResourceComponent>(TEXT("Resource Manager"));
}

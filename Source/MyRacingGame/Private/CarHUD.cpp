#include "CarHUD.h"
#include "CarStatsWidget.h"

void ACarHUD::BeginPlay()
{
	CarsStatWidget = CreateWidget<UCarStatsWidget>(Cast<APlayerController>(GetOwner()), CarStatsWidgetToCreate);
	CarsStatWidget->AddToViewport(); 

	InitWidgets(0.0f, 0);
}

void ACarHUD::SetCurrentSpeed(float inSpeed)
{
	CarsStatWidget->SetCurrentSpeed(inSpeed);
}

void ACarHUD::SetCurrentGear(int32 inGear)
{
	CarsStatWidget->SetCurrentGear(inGear);
}

void ACarHUD::InitWidgets(float inSpeed, int32 inGear)
{
	if (IsValid(CarsStatWidget))
	{
		CarsStatWidget->SetCurrentGear(inGear);
		CarsStatWidget->SetCurrentSpeed(inSpeed);
	}
}

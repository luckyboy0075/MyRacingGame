#include "CarHUD.h"
#include "CarStatsWidget.h"
#include "DebugStatOverlay.h"
#include "Engine/Canvas.h"
#include "Cars/BaseCar/BaseCar.h"
#include "Kismet/GameplayStatics.h"

void ACarHUD::BeginPlay()
{
	CarsStatWidget = CreateWidget<UCarStatsWidget>(Cast<APlayerController>(GetOwner()), CarStatsWidgetToCreate);
	CarsStatWidget->AddToViewport(); 
	
	DEBUG_SatsOverlay = CreateWidget<UDebugStatOverlay>(Cast<APlayerController>(GetOwner()), DEBUG_SatsOverlayWidgetToCreate);
	DEBUG_SatsOverlay->InitWidget(Cast<ABaseCar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)));

	InitWidgets(0.0f, 0);
}

void ACarHUD::DEBUG_UpdateOverlay()
{
	DEBUG_SatsOverlay->UpdateWidget();
}

void ACarHUD::SetCurrentSpeed(float inSpeed)
{
	CarsStatWidget->SetCurrentSpeed(inSpeed);
}

void ACarHUD::SetCurrentGear(int32 inGear)
{
	CarsStatWidget->SetCurrentGear(inGear);
}

void ACarHUD::ShowDEBUGOverlayWidget()
{
	CarsStatWidget->RemoveFromViewport();
	DEBUG_SatsOverlay->AddToViewport();
}

void ACarHUD::HideDEBUGOverlayWidget()
{
	DEBUG_SatsOverlay->RemoveFromViewport();
	CarsStatWidget->AddToViewport();
}

void ACarHUD::InitWidgets(float inSpeed, int32 inGear)
{
	if (IsValid(CarsStatWidget))
	{
		CarsStatWidget->SetCurrentGear(inGear);
		CarsStatWidget->SetCurrentSpeed(inSpeed);
	}
}

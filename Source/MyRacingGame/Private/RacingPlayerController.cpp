#include "RacingPlayerController.h"
#include "CarHUD.h"

void ARacingPlayerController::BeginPlay()
{
	CurrentCarHUD = Cast<ACarHUD>(GetHUD());
}

void ARacingPlayerController::UpdateHUD(float inSpeed, int32 inGear)
{
	if (CurrentCarHUD)
	{
		CurrentCarHUD->SetCurrentGear(inGear);
		CurrentCarHUD->SetCurrentSpeed(inSpeed);
	}
}

#include "CarStatsWidget.h"
#include "Components/TextBlock.h"
#include "Internationalization/Text.h"

void UCarStatsWidget::SetCurrentSpeed(float inSpeed)
{
	int32 onScreenSpeed = FMath::Floor(inSpeed);
	FString text = FString::FromInt(onScreenSpeed);

	SpeedNum->SetText(FText::FromString(text));
}

void UCarStatsWidget::SetCurrentGear(int32 inGear)
{
	FString text;

	if (inGear < 0)
	{
		text = "R";
	}
	else if (inGear == 0)
	{
		text = "N";
	}
	else
	{
		text = FString::FromInt(inGear);
	}

	GearNum->SetText(FText::FromString(text));
}

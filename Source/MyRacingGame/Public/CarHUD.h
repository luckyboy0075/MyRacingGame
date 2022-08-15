#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CarHUD.generated.h"

class UCarStatsWidget;
class UDebugStatOverlay;
class UCanvas;

UCLASS()
class MYRACINGGAME_API ACarHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	void DEBUG_UpdateOverlay();

	void SetCurrentSpeed(float inSpeed);
	void SetCurrentGear(int32 inGear);

	void ShowDEBUGOverlayWidget();
	void HideDEBUGOverlayWidget();

protected: 
	void InitWidgets(float inSpeed, int32 inGear);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UCarStatsWidget> CarStatsWidgetToCreate{};

	UPROPERTY()
	UCarStatsWidget* CarsStatWidget{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UDebugStatOverlay> DEBUG_SatsOverlayWidgetToCreate{};

	UPROPERTY()
	UDebugStatOverlay* DEBUG_SatsOverlay{};
};

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CarHUD.generated.h"

class UCarStatsWidget;

UCLASS()
class MYRACINGGAME_API ACarHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	void SetCurrentSpeed(float inSpeed);
	void SetCurrentGear(int32 inGear);

protected: 
	void InitWidgets(float inSpeed, int32 inGear);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UCarStatsWidget> CarStatsWidgetToCreate{};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCarStatsWidget* CarsStatWidget{};
};

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CarStatsWidget.generated.h"

class UTextBlock;

UCLASS()
class MYRACINGGAME_API UCarStatsWidget : public UUserWidget
{
	GENERATED_BODY()

public: 
	void SetCurrentSpeed(float inSpeed);
	void SetCurrentGear(int32 inGear);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* SpeedNum{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* GearNum{};
	
};

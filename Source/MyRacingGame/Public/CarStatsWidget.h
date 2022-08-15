#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CarStatsWidget.generated.h"

class UTextBlock;
class UCanvasPanel;

UCLASS()
class MYRACINGGAME_API UCarStatsWidget : public UUserWidget
{
	GENERATED_BODY()

public: 
	void SetCurrentSpeed(float inSpeed);
	void SetCurrentGear(int32 inGear);

	FORCEINLINE UCanvas* const GetCanvas() const { return nullptr; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* SpeedNum{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* GearNum{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UCanvasPanel* DebugCanvasPanel{};
	
};

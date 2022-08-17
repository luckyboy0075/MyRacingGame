#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RacingPlayerController.generated.h"

class ACarHUD;

UCLASS()
class MYRACINGGAME_API ARacingPlayerController : public APlayerController
{
	GENERATED_BODY()

public: 
	virtual void BeginPlay() override;
	void UpdateHUD(float inSpeed, int32 inGear);

	FORCEINLINE bool IsDebugOverlayActive() const { return debugOverlayActive; }
	FORCEINLINE void SetDebugOverlayActive(bool isNeededToActivate) { debugOverlayActive = isNeededToActivate; }

	FORCEINLINE ACarHUD* const GetCurrentHUD() { return CurrentCarHUD; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ACarHUD* CurrentCarHUD{};

private:
	UPROPERTY()
	bool debugOverlayActive{};
};

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
	
	FORCEINLINE ACarHUD* const GetCurrnetHUD() { return CurrentCarHUD; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	ACarHUD* CurrentCarHUD{};
};

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DebugStatOverlay.generated.h"

class ABaseCar;
class UTextBlock;
class UChaosVehicleMovementComponent;

UCLASS()
class MYRACINGGAME_API UDebugStatOverlay : public UUserWidget
{
	GENERATED_BODY()

public: 
	void InitWidget(ABaseCar* const car);
	void UpdateWidget();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* SpeedNum {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* GearNum {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* SteeringInput {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* HandbrakeInput {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* EngineSpeedRPM {};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* EngineTorque {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TransmissionRPM {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* TransmissionTorque {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ThrottleInput {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* ForwardSpeed {};

	//WHEELS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* FL_WheelRotation {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* FL_WheelAngle {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* FR_WheelRotation {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* FR_WheelAngle {};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* RL_WheelRotation {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* RL_WheelAngle {};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* RR_WheelRotation {};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* RR_WheelAngle {};
	//WHEELS


	UPROPERTY()
	ABaseCar* mBaseCar{};

	UPROPERTY()
	UChaosVehicleMovementComponent* mVechicleMovementComp{};
};

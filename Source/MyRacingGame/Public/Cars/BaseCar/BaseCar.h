#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "BaseCar.generated.h"

#define MPH_TO_KMH_VALUE 1.60934

class UAudioComponent;
class USceneComponent;
class UCameraComponent;
class USpringArmComponent;
class UPhysicalMaterial;

UCLASS()
class MYRACINGGAME_API ABaseCar : public AWheeledVehiclePawn
{
	GENERATED_BODY()
	
public:
	ABaseCar();

	FORCEINLINE bool IsInReverseGear() { return CurrentGear < 0; }

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float delta) override;

	virtual void SetupPlayerInputComponent(UInputComponent* playerInputComponent) override;

	void MoveAxisForward(float delta);
	void MoveBackwards(float delta);
	void MoveAxisRight(float delta);

	void HandleSwitchCamera();

	void ApplyHandbrakePressed();
	void ApplyHandbrakeReleased();

	void ShiftGearUp();
	void ShiftGearDown();

	//DEBUG STUFF
	void DEBUG_ShowCarOverlay();
	//DEBUG STUFF

	UFUNCTION(BlueprintImplementableEvent)
	void UpdatePhysicalMaterial();

private:
	void SetupInCarHUD();
	void UpdateHUDStings();
	void DEBUG_UpdateCarOverlay();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USceneComponent* InCarScene{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCameraComponent* InCarCamera{};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UCameraComponent* ChaseCamera{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USpringArmComponent* ChaseCameraArm{};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAudioComponent* EngineSound{};

// 	UPROPERTY(EditAnywhere, BlueprintReadOnly)
// 	UPhysicalMaterial* PhysicsMaterialLowFriction{};
// 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	bool isLowFriction { false };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game")
	bool isInReverse { false };
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game")
	bool isInCarCamera { true };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DEBUG")
	bool carDebugOverlayActive { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CurrentGear{};
};

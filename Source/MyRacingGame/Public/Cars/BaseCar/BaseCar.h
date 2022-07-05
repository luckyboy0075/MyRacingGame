#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "BaseCar.generated.h"

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
	void MoveAxisRight(float delta);

	void HandleSwitchCamera();

	void ApplyHandbrakePressed();
	void ApplyHandbrakeReleased();

	void ShiftGearUp();
	void ShiftGearDown();

private:
	void UpdatePhysicalMaterial();
	void SetupInCarHUD();
	void UpdateHUDStings();
	
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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game")
	bool isLowFriction { false };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game")
	bool isInReverse { false };
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Game")
	bool isInCarCamera { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 CurrentGear{};
};

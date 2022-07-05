#include "Cars/BaseCar/BaseCar.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/AudioComponent.h"
#include "ChaosVehicleMovementComponent.h"

ABaseCar::ABaseCar()
{
	InCarScene = CreateDefaultSubobject<USceneComponent>(TEXT("InCarScene"));
	InCarScene->SetupAttachment(InCarScene);

	InCarCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("InCarCamera"));
	InCarCamera->SetupAttachment(InCarScene);

	ChaseCameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("ChaseSpringArm"));
	ChaseCameraArm->SetupAttachment(RootComponent);

	ChaseCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ChaseCamera"));
	ChaseCamera->SetupAttachment(ChaseCameraArm);

	EngineSound = CreateDefaultSubobject<UAudioComponent>(TEXT("EngineSound"));
	EngineSound->SetupAttachment(RootComponent);
}

void ABaseCar::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCar::Tick(float delta)
{
	Super::Tick(delta);

	CurrentGear = GetVehicleMovementComponent()->GetCurrentGear();
	
	if (CurrentGear < 0)
	{
		isInReverse = true;
	}

	UpdatePhysicalMaterial();
	UpdateHUDStings();
	SetupInCarHUD();

	float forwardSpeed = GetVehicleMovementComponent()->GetForwardSpeed();
	EngineSound->SetFloatParameter(TEXT("RPM"), FMath::Abs(forwardSpeed));
}

void ABaseCar::SetupPlayerInputComponent(UInputComponent* playerInputComponent)
{
	Super::SetupPlayerInputComponent(playerInputComponent);
}

void ABaseCar::MoveAxisForward(float delta)
{
	if (!FMath::IsNearlyZero(delta))
	{
		GetVehicleMovementComponent()->SetThrottleInput(delta);
		GetVehicleMovementComponent()->SetBrakeInput(0.0f);
		}
	else
	{
		GetVehicleMovementComponent()->SetThrottleInput(0.0f);
		GetVehicleMovementComponent()->SetBrakeInput(delta);
	}
}

void ABaseCar::MoveAxisRight(float delta)
{
	GetVehicleMovementComponent()->SetSteeringInput(delta);
}

void ABaseCar::HandleSwitchCamera()
{
	if (isInCarCamera)
	{
		InCarCamera->Deactivate();
		ChaseCamera->Activate(false);
	}
	else
	{
		ChaseCamera->Deactivate();
		InCarCamera->Activate(false);
	}
}

void ABaseCar::ApplyHandbrakePressed()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void ABaseCar::ApplyHandbrakeReleased()
{
	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void ABaseCar::ShiftGearUp()
{

}

void ABaseCar::ShiftGearDown()
{

}

void ABaseCar::UpdatePhysicalMaterial()
{
	FVector upVector = GetActorUpVector();

	if (!FMath::IsNearlyZero(upVector.Z))
	{
		if (isLowFriction)
		{
			GetMesh()->SetPhysMaterialOverride(PhysicsMaterialLowFriction);
			isLowFriction = true;
		}
	}
	else
	{
		if (!isLowFriction)
		{
			GetMesh()->SetPhysMaterialOverride(nullptr);
			isLowFriction = false;
		}
	}
}

void ABaseCar::SetupInCarHUD()
{

}

void ABaseCar::UpdateHUDStings()
{

}

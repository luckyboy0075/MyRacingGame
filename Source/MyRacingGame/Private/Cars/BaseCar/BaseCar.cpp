#include "Cars/BaseCar/BaseCar.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Components/AudioComponent.h"
#include "ChaosVehicleMovementComponent.h"
#include "MyRacingGame/Public/CarHUD.h"
#include "MyRacingGame/Public/RacingPlayerController.h"

ABaseCar::ABaseCar()
{
	InCarScene = CreateDefaultSubobject<USceneComponent>(TEXT("InCarScene"));
	InCarScene->SetupAttachment(RootComponent);

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

	float forwardSpeed = GetVehicleMovementComponent()->GetForwardSpeed();
	EngineSound->SetFloatParameter(TEXT("RPM"), FMath::Abs(forwardSpeed));

	if (carDebugOverlayActive)
	{
		DEBUG_UpdateCarOverlay();
	}
}

void ABaseCar::SetupPlayerInputComponent(UInputComponent* playerInputComponent)
{
	Super::SetupPlayerInputComponent(playerInputComponent);

	InputComponent->BindAction("ApplyHandbrake", IE_Pressed, this, &ABaseCar::ApplyHandbrakePressed);
	InputComponent->BindAction("ApplyHandbrake", IE_Released, this, &ABaseCar::ApplyHandbrakeReleased);
	InputComponent->BindAction("SwitchCamera", IE_Pressed, this, &ABaseCar::HandleSwitchCamera);
	InputComponent->BindAction("ShiftUp", IE_Pressed, this, &ABaseCar::ShiftGearUp);
	InputComponent->BindAction("ShiftDown", IE_Pressed, this, &ABaseCar::ShiftGearDown);
	
	//DEBUG STUFF
	InputComponent->BindAction("DEBUG_CAR_OVERLAY", IE_Pressed, this, &ABaseCar::DEBUG_ShowCarOverlay);
	//DEBUG STAFF 

	InputComponent->BindAxis("MoveForward", this, &ABaseCar::MoveAxisForward);	
	InputComponent->BindAxis("MoveBackwards", this, &ABaseCar::MoveBackwards);
	InputComponent->BindAxis("TurnRigth", this, &ABaseCar::MoveAxisRight);
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
		GetVehicleMovementComponent()->SetBrakeInput(1.0f);
	}
}

void ABaseCar::MoveBackwards(float delta)
{
	if (!FMath::IsNearlyZero(delta))
	{
		GetVehicleMovementComponent()->SetBrakeInput(delta);
	}
}

void ABaseCar::MoveAxisRight(float delta)
{
	if (!FMath::IsNearlyZero(delta))
	{
		GetVehicleMovementComponent()->SetSteeringInput(delta);
	}
}

void ABaseCar::HandleSwitchCamera()
{
	if (isInCarCamera)
	{
		UE_LOG(LogClass, Error, TEXT("ChaseCamera - activating"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("ChaseCamera - activating"));

		InCarCamera->Deactivate();
		ChaseCamera->Activate(false);
		isInCarCamera = false;
	}
	else
	{
		UE_LOG(LogClass, Error, TEXT("InCar - activating"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("InCarCamera- activating"));

		ChaseCamera->Deactivate();
		InCarCamera->Activate(false);
		isInCarCamera = true;
	}
}

void ABaseCar::ApplyHandbrakePressed()
{
	UE_LOG(LogClass, Error, TEXT("HandBrake up"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("HandBrake up"));

	GetVehicleMovementComponent()->SetHandbrakeInput(true);
}

void ABaseCar::ApplyHandbrakeReleased()
{
	UE_LOG(LogClass, Error, TEXT("HandBrake down"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("HandBrake down"));

	GetVehicleMovementComponent()->SetHandbrakeInput(false);
}

void ABaseCar::ShiftGearUp()
{
	CurrentGear = GetVehicleMovementComponent()->GetCurrentGear();
	GetVehicleMovementComponent()->SetTargetGear(++CurrentGear, true);

	UE_LOG(LogClass, Error, TEXT("Shift Up, Current Gear - %i"), CurrentGear);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Shift Up"));
}

void ABaseCar::ShiftGearDown()
{
	CurrentGear = GetVehicleMovementComponent()->GetCurrentGear();
	GetVehicleMovementComponent()->SetTargetGear(--CurrentGear, true);

	UE_LOG(LogClass, Error, TEXT("Shift Down, Current Gear - %i"), CurrentGear);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Shift Down"));
}

void ABaseCar::DEBUG_ShowCarOverlay()
{
	ARacingPlayerController* localController = Cast<ARacingPlayerController>(Controller);

	if (IsValid(localController))
	{
		if (carDebugOverlayActive)
		{
			carDebugOverlayActive = false;
			localController->GetCurrentHUD()->HideDEBUGOverlayWidget();
		}
		else
		{
			carDebugOverlayActive = true;
			localController->GetCurrentHUD()->ShowDEBUGOverlayWidget();
		}
	}
}

void ABaseCar::SetupInCarHUD()
{
	
}

void ABaseCar::UpdateHUDStings()
{
	ARacingPlayerController* const localController = Cast<ARacingPlayerController>(Controller);

	if (IsValid(localController))
	{
		float currentSpeedInUnits = GetVehicleMovementComponent()->GetForwardSpeedMPH();
		float currentSpeedKMH = currentSpeedInUnits * MPH_TO_KMH_VALUE > 0.0f ? currentSpeedInUnits * MPH_TO_KMH_VALUE : currentSpeedInUnits * -MPH_TO_KMH_VALUE;


		int32 currentGear = GetVehicleMovementComponent()->GetCurrentGear();
		localController->UpdateHUD(currentSpeedKMH, currentGear);
	}
}

void ABaseCar::DEBUG_UpdateCarOverlay()
{
	if (ARacingPlayerController* const localController = Cast<ARacingPlayerController>(Controller))
	{
		localController->GetCurrentHUD()->DEBUG_UpdateOverlay();
	}
}

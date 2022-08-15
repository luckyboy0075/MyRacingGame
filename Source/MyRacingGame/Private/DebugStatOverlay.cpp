#include "DebugStatOverlay.h"
#include "ChaosVehicleMovementComponent.h"
#include "Cars/BaseCar/BaseCar.h"
#include "Components/TextBlock.h"

void UDebugStatOverlay::InitWidget(ABaseCar* const car)
{
	mBaseCar = car;
	SpeedNum->SetText(FText::FromString("NONE"));
	GearNum->SetText(FText::FromString("NONE"));
	SteeringInput->SetText(FText::FromString("NONE"));
	HandbrakeInput->SetText(FText::FromString("NONE"));
	EngineSpeedRPM->SetText(FText::FromString("NONE"));
	EngineTorque->SetText(FText::FromString("NONE"));
	TransmissionRPM->SetText(FText::FromString("NONE"));
	TransmissionTorque->SetText(FText::FromString("NONE"));
	ThrottleInput->SetText(FText::FromString("NONE"));
	ForwardSpeed->SetText(FText::FromString("NONE"));

	//WHEELS
	FL_WheelRotation->SetText(FText::FromString("NONE"));
	FL_WheelAngle->SetText(FText::FromString("NONE"));

	FR_WheelRotation->SetText(FText::FromString("NONE"));
	FR_WheelAngle->SetText(FText::FromString("NONE"));

	RL_WheelRotation->SetText(FText::FromString("NONE"));
	RL_WheelAngle->SetText(FText::FromString("NONE"));

	RR_WheelRotation->SetText(FText::FromString("NONE"));
	RR_WheelAngle->SetText(FText::FromString("NONE"));
	//WHEELS

	mVechicleMovementComp = mBaseCar->GetVehicleMovementComponent();
}

void UDebugStatOverlay::UpdateWidget()
{
	int32 speedNum = mVechicleMovementComp->GetForwardSpeedMPH() * MPH_TO_KMH_VALUE;
	int32 gearNum = mVechicleMovementComp->GetCurrentGear();
	float steeringInputNum = mVechicleMovementComp->GetSteeringInput();
	float throttleInput = mVechicleMovementComp->GetThrottleInput();
	float forwardSpeed = mVechicleMovementComp->GetForwardSpeed();

	TUniquePtr<FPhysicsVehicleOutput>&  physOutput = mVechicleMovementComp->PhysicsVehicleOutput();

	float engineSpeed = physOutput->EngineRPM;
	float engineTorque = physOutput->EngineTorque;

	float transmissionRPM = physOutput->TransmissionRPM;
	float transmissionTorque = physOutput->TransmissionTorque;

	for (FWheelsOutput& wheel : physOutput->Wheels)
	{

	}
}

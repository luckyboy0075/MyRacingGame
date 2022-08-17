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
	//FRONT_LEFT WHEEL
	FL_SteeringAngle->SetText(FText::FromString("NONE"));
	FL_AngularPosition->SetText(FText::FromString("NONE"));
	FL_InContact->SetText(FText::FromString("NONE"));
	FL_AngularVelocity->SetText(FText::FromString("NONE"));
	FL_WheelRadius->SetText(FText::FromString("NONE"));
	FL_LateralAdhesiveLimit->SetText(FText::FromString("NONE"));
	FL_LongitudinalAdhesiveLimit->SetText(FText::FromString("NONE"));
	FL_SlipAngle->SetText(FText::FromString("NONE"));
	FL_IsSlipping->SetText(FText::FromString("NONE"));
	FL_SlipMagnitude->SetText(FText::FromString("NONE"));
	FL_IsSkidding->SetText(FText::FromString("NONE"));
	FL_SkidMagnitude->SetText(FText::FromString("NONE"));
	FL_SkidNormal->SetText(FText::FromString("NONE"));
	
	//FRONT_LEFT

	//FRONT_RIGHT WHEEL	
	FR_SteeringAngle->SetText(FText::FromString("NONE"));
	FR_AngularPosition->SetText(FText::FromString("NONE"));
	FR_InContact->SetText(FText::FromString("NONE"));
	FR_AngularVelocity->SetText(FText::FromString("NONE"));
	FR_WheelRadius->SetText(FText::FromString("NONE"));
	FR_LateralAdhesiveLimit->SetText(FText::FromString("NONE"));
	FR_LongitudinalAdhesiveLimit->SetText(FText::FromString("NONE"));
	FR_SlipAngle->SetText(FText::FromString("NONE"));
	FR_IsSlipping->SetText(FText::FromString("NONE"));
	FR_SlipMagnitude->SetText(FText::FromString("NONE"));
	FR_IsSkidding->SetText(FText::FromString("NONE"));
	FR_SkidMagnitude->SetText(FText::FromString("NONE"));
	FR_SkidNormal->SetText(FText::FromString("NONE"));


	//FRONT_RIGHT

	// REAR_LEFT WHEEL
	RL_SteeringAngle->SetText(FText::FromString("NONE"));
	RL_AngularPosition->SetText(FText::FromString("NONE"));
	RL_InContact->SetText(FText::FromString("NONE"));
	RL_AngularVelocity->SetText(FText::FromString("NONE"));
	RL_WheelRadius->SetText(FText::FromString("NONE"));
	RL_LateralAdhesiveLimit->SetText(FText::FromString("NONE"));
	RL_LongitudinalAdhesiveLimit->SetText(FText::FromString("NONE"));
	RL_SlipAngle->SetText(FText::FromString("NONE"));
	RL_IsSlipping->SetText(FText::FromString("NONE"));
	RL_SlipMagnitude->SetText(FText::FromString("NONE"));
	RL_IsSkidding->SetText(FText::FromString("NONE"));
	RL_SkidMagnitude->SetText(FText::FromString("NONE"));
	RL_SkidNormal->SetText(FText::FromString("NONE"));

	//REAR_LEFT

	//REAR_RIGHT WHEEL
	RR_SteeringAngle->SetText(FText::FromString("NONE"));
	RR_AngularPosition->SetText(FText::FromString("NONE"));
	RR_InContact->SetText(FText::FromString("NONE"));
	RR_AngularVelocity->SetText(FText::FromString("NONE"));
	RR_WheelRadius->SetText(FText::FromString("NONE"));
	RR_LateralAdhesiveLimit->SetText(FText::FromString("NONE"));
	RR_LongitudinalAdhesiveLimit->SetText(FText::FromString("NONE"));
	RR_SlipAngle->SetText(FText::FromString("NONE"));
	RR_IsSlipping->SetText(FText::FromString("NONE"));
	RR_SlipMagnitude->SetText(FText::FromString("NONE"));
	RR_IsSkidding->SetText(FText::FromString("NONE"));
	RR_SkidMagnitude->SetText(FText::FromString("NONE"));
	RR_SkidNormal->SetText(FText::FromString("NONE"));
	
	//REAR_RIGHT
	//WHEELS

	mVechicleMovementComp = mBaseCar->GetVehicleMovementComponent();
}

void UDebugStatOverlay::UpdateWidget()
{
	float speedNum = mVechicleMovementComp->GetForwardSpeedMPH() * MPH_TO_KMH_VALUE;
	int32 gearNum = mVechicleMovementComp->GetCurrentGear();
	float steeringInputNum = mVechicleMovementComp->GetSteeringInput();
	float throttleInput = mVechicleMovementComp->GetThrottleInput();
	float forwardSpeed = mVechicleMovementComp->GetForwardSpeed();
	float handbrakeInputNum = mVechicleMovementComp->GetHandbrakeInput();

	TUniquePtr<FPhysicsVehicleOutput>&  physOutput = mVechicleMovementComp->PhysicsVehicleOutput();

	float engineSpeed = physOutput->EngineRPM;
	float engineTorque = physOutput->EngineTorque;

	float transmissionRPM = physOutput->TransmissionRPM;
	float transmissionTorque = physOutput->TransmissionTorque;

	int32 precision { 2 };

	SpeedNum->SetText(FText::FromString(FString::Printf(TEXT("Speed KM/h -  % .*f"), precision , speedNum)));
	GearNum->SetText(FText::FromString(FString::Printf(TEXT("Current Gear - %i"), gearNum)));
	SteeringInput->SetText(FText::FromString(FString::Printf(TEXT("Steering Input - % .*f"), precision, steeringInputNum)));
	HandbrakeInput->SetText(FText::FromString(FString::Printf(TEXT("Handbrake - % .*f"), precision, handbrakeInputNum)));
	EngineSpeedRPM->SetText(FText::FromString(FString::Printf(TEXT("Engine Speed RPM - % .*f"), precision, engineSpeed)));
	EngineTorque->SetText(FText::FromString(FString::Printf(TEXT("Engine Torque - % .*f"), precision, engineTorque)));
	TransmissionRPM->SetText(FText::FromString(FString::Printf(TEXT("Transmission RPM - % .*f"), precision, transmissionRPM)));
	TransmissionTorque->SetText(FText::FromString(FString::Printf(TEXT("Transmission Torque - % .*f"), precision, transmissionTorque)));
	ThrottleInput->SetText(FText::FromString(FString::Printf(TEXT("Throttle Input - % .*f"), precision, throttleInput)));
	ForwardSpeed->SetText(FText::FromString(FString::Printf(TEXT("Speed Units - % .*f"), precision, forwardSpeed)));

	// FRONT_LEFT WHEEL DATA
	FWheelsOutput& FL_Wheel = physOutput->Wheels[0];

	bool FL_inContact = FL_Wheel.InContact;
	float FL_steeringAngle = FL_Wheel.SteeringAngle;
	float FL_angularPosition = FL_Wheel.AngularPosition;
	float FL_angularVelocity = FL_Wheel.AngularVelocity;
	float FL_wheelRadius = FL_Wheel.WheelRadius;

	float FL_lateralAdhesiveLimit = FL_Wheel.LateralAdhesiveLimit;
	float FL_longitudinalAdhesiveLimit = FL_Wheel.LongitudinalAdhesiveLimit;

	float FL_slipAngle = FL_Wheel.SlipAngle;
	bool FL_isSlipping = FL_Wheel.bIsSlipping;
	float FL_slipMagnitude = FL_Wheel.SlipMagnitude;
	bool FL_isSkidding = FL_Wheel.bIsSkidding;
	float FL_skidMagnitude = FL_Wheel.SkidMagnitude;
	FVector FL_skidNormal = FL_Wheel.SkidNormal;

	FString FL_contact = FL_inContact ? "Wheel in contact" : "Wheel not in contact";
	FString FL_slipping = FL_isSlipping ? "Wheel slipping" : "Wheel not slipping";
	FString FL_skidding = FL_isSkidding ? "Wheel skidding" : "Wheel not skidding";

	FL_SteeringAngle->SetText(FText::FromString(FString::Printf(TEXT("Steering Angle - % .*f"), precision, FL_steeringAngle)));
	FL_AngularPosition->SetText(FText::FromString(FString::Printf(TEXT("Angular Position - % .*f"), precision, FL_AngularPosition)));
	FL_InContact->SetText(FText::FromString(FL_contact));
	FL_AngularVelocity->SetText(FText::FromString(FString::Printf(TEXT("Angular Velocity - % .*f"), precision, FL_angularVelocity)));
	FL_WheelRadius->SetText(FText::FromString(FString::Printf(TEXT("Wheel Radius - % .*f"), precision, FL_wheelRadius)));
	FL_LateralAdhesiveLimit->SetText(FText::FromString(FString::Printf(TEXT("Lateral Adhersive Limit - % .*f"), precision,FL_lateralAdhesiveLimit)));
	FL_LongitudinalAdhesiveLimit->SetText(FText::FromString(FString::Printf(TEXT("Longitude Adhersive Limit - % .*f"), precision,FL_LongitudinalAdhesiveLimit)));
	FL_SlipAngle->SetText(FText::FromString(FString::Printf(TEXT("Slip Angle - % .*f"), precision,FL_slipAngle)));
	FL_IsSlipping->SetText(FText::FromString(FL_slipping));
	FL_SlipMagnitude->SetText(FText::FromString(FString::Printf(TEXT("Slip Magnitude- % .*f"), precision,FL_slipMagnitude)));
	FL_IsSkidding->SetText(FText::FromString(FL_skidding));
	FL_SkidMagnitude->SetText(FText::FromString(FString::Printf(TEXT("Skid Magnitude - % .*f"), precision,FL_skidMagnitude)));
	//FL_SkidNormal->SetText(FText::FromString(FString::Printf(TEXT("Skid Normal.X - %f \nSkid Normal.Y - %f \nSkid Normal.Z - %f"), precision,FL_skidNormal.X, FL_skidNormal.Y, FL_skidNormal.Z)));

	// FRONT_RIGHT WHEEL DATA
	FWheelsOutput& FR_Wheel = physOutput->Wheels[1];

	bool FR_inContact = FR_Wheel.InContact;
	float FR_steeringAngle = FR_Wheel.SteeringAngle;
	float FR_angularPosition = FR_Wheel.AngularPosition;
	float FR_angularVelocity = FR_Wheel.AngularVelocity;
	float FR_wheelRadius = FR_Wheel.WheelRadius;

	float FR_lateralAdhesiveLimit = FR_Wheel.LateralAdhesiveLimit;
	float FR_longitudinalAdhesiveLimit = FR_Wheel.LongitudinalAdhesiveLimit;

	float FR_slipAngle = FR_Wheel.SlipAngle;
	bool FR_isSlipping = FR_Wheel.bIsSlipping;
	float FR_slipMagnitude = FR_Wheel.SlipMagnitude;
	bool FR_isSkidding = FR_Wheel.bIsSkidding;
	float FR_skidMagnitude = FR_Wheel.SkidMagnitude;
	FVector FR_skidNormal = FR_Wheel.SkidNormal;

	FString FR_contact = FR_inContact ? "Wheel in contact" : "Wheel not in contact";
	FString FR_slipping = FR_isSlipping ? "Wheel slipping" : "Wheel not slipping";
	FString FR_skidding = FR_isSkidding ? "Wheel skidding" : "Wheel not skidding";

	FR_SteeringAngle->SetText(FText::FromString(FString::Printf(TEXT("Steering Angle - % .*f"), precision,FR_steeringAngle)));
	FR_AngularPosition->SetText(FText::FromString(FString::Printf(TEXT("Angular Position - % .*f"), precision,FR_AngularPosition)));
	FR_InContact->SetText(FText::FromString(FR_contact));
	FR_AngularVelocity->SetText(FText::FromString(FString::Printf(TEXT("Angular Velocity - % .*f"), precision,FR_angularVelocity)));
	FR_WheelRadius->SetText(FText::FromString(FString::Printf(TEXT("Wheel Radius - % .*f"), precision,FR_wheelRadius)));
	FR_LateralAdhesiveLimit->SetText(FText::FromString(FString::Printf(TEXT("Lateral Adhersive Limit - % .*f"), precision,FR_lateralAdhesiveLimit)));
	FR_LongitudinalAdhesiveLimit->SetText(FText::FromString(FString::Printf(TEXT("Longitude Adhersive Limit - % .*f"), precision,FR_LongitudinalAdhesiveLimit)));
	FR_SlipAngle->SetText(FText::FromString(FString::Printf(TEXT("Slip Angle - % .*f"), precision,FR_slipAngle)));
	FR_IsSlipping->SetText(FText::FromString(FR_slipping));
	FR_SlipMagnitude->SetText(FText::FromString(FString::Printf(TEXT("Slip Magnitude- % .*f"), precision,FR_slipMagnitude)));
	FR_IsSkidding->SetText(FText::FromString(FR_skidding));
	FR_SkidMagnitude->SetText(FText::FromString(FString::Printf(TEXT("Skid Magnitude - % .*f"), precision,FR_skidMagnitude)));
	//FR_SkidNormal->SetText(FText::FromString(FString::Printf(TEXT("Skid Normal.X - % .*f \nSkid Normal.Y - % .*f \nSkid Normal.Z - % .*f"), precision,FR_skidNormal.X, FR_skidNormal.Y, FR_skidNormal.Z)));

	//REAR_LEFT WHEEL
	FWheelsOutput& RL_Wheel = physOutput->Wheels[2];

	bool RL_inContact = RL_Wheel.InContact;
	float RL_steeringAngle = RL_Wheel.SteeringAngle;
	float RL_angularPosition = RL_Wheel.AngularPosition;
	float RL_angularVelocity = RL_Wheel.AngularVelocity;
	float RL_wheelRadius = RL_Wheel.WheelRadius;

	float RL_lateralAdhesiveLimit = RL_Wheel.LateralAdhesiveLimit;
	float RL_longitudinalAdhesiveLimit = RL_Wheel.LongitudinalAdhesiveLimit;

	float RL_slipAngle = RL_Wheel.SlipAngle;
	bool RL_isSlipping = RL_Wheel.bIsSlipping;
	float RL_slipMagnitude = RL_Wheel.SlipMagnitude;
	bool RL_isSkidding = RL_Wheel.bIsSkidding;
	float RL_skidMagnitude = RL_Wheel.SkidMagnitude;
	FVector RL_skidNormal = RL_Wheel.SkidNormal;

	FString RL_contact = RL_inContact ? "Wheel in contact" : "Wheel not in contact";
	FString RL_slipping = RL_isSlipping ? "Wheel slipping" : "Wheel not slipping";
	FString RL_skidding = RL_isSkidding ? "Wheel skidding" : "Wheel not skidding";

	RL_SteeringAngle->SetText(FText::FromString(FString::Printf(TEXT("Steering Angle - % .*f"), precision,RL_steeringAngle)));
	RL_AngularPosition->SetText(FText::FromString(FString::Printf(TEXT("Angular Position - % .*f"), precision,RL_AngularPosition)));
	RL_InContact->SetText(FText::FromString(RL_contact));
	RL_AngularVelocity->SetText(FText::FromString(FString::Printf(TEXT("Angular Velocity - % .*f"), precision,RL_angularVelocity)));
	RL_WheelRadius->SetText(FText::FromString(FString::Printf(TEXT("Wheel Radius - % .*f"), precision,RL_wheelRadius)));
	RL_LateralAdhesiveLimit->SetText(FText::FromString(FString::Printf(TEXT("Lateral Adhersive Limit - % .*f"), precision,RL_lateralAdhesiveLimit)));
	RL_LongitudinalAdhesiveLimit->SetText(FText::FromString(FString::Printf(TEXT("Longitude Adhersive Limit - % .*f"), precision,RL_LongitudinalAdhesiveLimit)));
	RL_SlipAngle->SetText(FText::FromString(FString::Printf(TEXT("Slip Angle - % .*f"), precision,RL_slipAngle)));
	RL_IsSlipping->SetText(FText::FromString(RL_slipping));
	RL_SlipMagnitude->SetText(FText::FromString(FString::Printf(TEXT("Slip Magnitude- % .*f"), precision,RL_slipMagnitude)));
	RL_IsSkidding->SetText(FText::FromString(RL_skidding));
	RL_SkidMagnitude->SetText(FText::FromString(FString::Printf(TEXT("Skid Magnitude - % .*f"), precision,RL_skidMagnitude)));
//	RL_SkidNormal->SetText(FText::FromString(FString::Printf(TEXT("Skid Normal.X - % .*f \nSkid Normal.Y - % .*f \nSkid Normal.Z - % .*f"), precision,RL_skidNormal.X, RL_skidNormal.Y, RL_skidNormal.Z)));


	// REAR_RIGHT WHEEL DATA
	FWheelsOutput& RR_Wheel = physOutput->Wheels[3];
	
	bool RR_inContact = RR_Wheel.InContact;
	float RR_steeringAngle = RR_Wheel.SteeringAngle;
	float RR_angularPosition = RR_Wheel.AngularPosition;
	float RR_angularVelocity = RR_Wheel.AngularVelocity;
	float RR_wheelRadius = RR_Wheel.WheelRadius;

	float RR_lateralAdhesiveLimit = RR_Wheel.LateralAdhesiveLimit;
	float RR_longitudinalAdhesiveLimit = RR_Wheel.LongitudinalAdhesiveLimit;

	float RR_slipAngle = RR_Wheel.SlipAngle;
	bool RR_isSlipping = RR_Wheel.bIsSlipping;
	float RR_slipMagnitude = RR_Wheel.SlipMagnitude;
	bool RR_isSkidding = RR_Wheel.bIsSkidding;
	float RR_skidMagnitude = RR_Wheel.SkidMagnitude;
	FVector RR_skidNormal = RR_Wheel.SkidNormal;

	FString RR_contact = RR_inContact ? "Wheel in contact" : "Wheel not in contact";
	FString RR_slipping = RR_isSlipping ? "Wheel slipping" : "Wheel not slipping";
	FString RR_skidding = RR_isSkidding ? "Wheel skidding" : "Wheel not skidding";

	RR_SteeringAngle->SetText(FText::FromString(FString::Printf(TEXT("Steering Angle - % .*f"), precision,RR_steeringAngle)));
	RR_AngularPosition->SetText(FText::FromString(FString::Printf(TEXT("Angular Position - % .*f"), precision,RR_AngularPosition)));
	RR_InContact->SetText(FText::FromString(RR_contact));
	RR_AngularVelocity->SetText(FText::FromString(FString::Printf(TEXT("Angular Velocity - % .*f"), precision,RR_angularVelocity)));
	RR_WheelRadius->SetText(FText::FromString(FString::Printf(TEXT("Wheel Radius - % .*f"), precision,RR_wheelRadius)));
	RR_LateralAdhesiveLimit->SetText(FText::FromString(FString::Printf(TEXT("Lateral Adhersive Limit - % .*f"), precision,RR_lateralAdhesiveLimit)));
	RR_LongitudinalAdhesiveLimit->SetText(FText::FromString(FString::Printf(TEXT("Longitude Adhersive Limit - % .*f"), precision,RR_LongitudinalAdhesiveLimit)));
	RR_SlipAngle->SetText(FText::FromString(FString::Printf(TEXT("Slip Angle - % .*f"), precision,RR_slipAngle)));
	RR_IsSlipping->SetText(FText::FromString(RR_slipping));
	RR_SlipMagnitude->SetText(FText::FromString(FString::Printf(TEXT("Slip Magnitude- % .*f"), precision,RR_slipMagnitude)));
	RR_IsSkidding->SetText(FText::FromString(RR_skidding));
	RR_SkidMagnitude->SetText(FText::FromString(FString::Printf(TEXT("Skid Magnitude - % .*f"), precision,RR_skidMagnitude)));
	//RR_SkidNormal->SetText(FText::FromString(FString::Printf(TEXT("Skid Normal.X - % .*f \nSkid Normal.Y - % .*f \nSkid Normal.Z - % .*f"), precision,RR_skidNormal.X, RR_skidNormal.Y, RR_skidNormal.Z)));
}

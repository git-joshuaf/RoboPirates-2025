// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/RollerSubsystem.h"

using namespace RollerConstants;

RollerSubsystem::RollerSubsystem() : rollerMotor{ROLLER_MOTOR_ID} {
    
    rollerMotor.ConfigFactoryDefault(250);
    rollerMotor.ConfigVoltageCompSaturation(ROLLER_MOTOR_VOLTAGE_COMP);

    /*SparkBaseConfig rollerConfig;

    rollerMotor.SetCANTimeout(250);

    rollerConfig.VoltageCompensation(ROLLER_MOTOR_VOLTAGE_COMP);
    rollerConfig.SmartCurrentLimit(ROLLER_MOTOR_CURRENT_LIMIT);
    rollerMotor.Configure(rollerConfig, SparkBase::ResetMode::kResetSafeParameters, SparkBase::PersistMode::kPersistParameters);*/
};

// This method will be called once per scheduler run
void RollerSubsystem::Periodic() {}

void RollerSubsystem::RunRoller(double forward, double reverse) {
    rollerMotor.Set(motorcontrol::ControlMode::PercentOutput, forward - reverse);
}

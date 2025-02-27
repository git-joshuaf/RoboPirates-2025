// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/LinearActuatorsSubsystem.h"

using namespace LinearActuatorsConstants;

LinearActuatorsSubsystem::LinearActuatorsSubsystem() : backActuator1{BACK_ID1}, backActuator2{BACK_ID2}, frontActuator{FRONT_ID} {
    backActuator1.ConfigFactoryDefault();
    backActuator2.ConfigFactoryDefault();
    frontActuator.ConfigFactoryDefault();

    backActuator1.ConfigVoltageCompSaturation(ACTUATORS_VOLTAGE_COMP);
    backActuator2.ConfigVoltageCompSaturation(ACTUATORS_VOLTAGE_COMP);
    frontActuator.ConfigVoltageCompSaturation(ACTUATORS_VOLTAGE_COMP);

    backActuator1.Follow(frontActuator);
    backActuator2.Follow(frontActuator);
};

// This method will be called once per scheduler run
void LinearActuatorsSubsystem::Periodic() {}

void LinearActuatorsSubsystem::RunActuators(double forward, double reverse) {
    frontActuator.Set(motorcontrol::ControlMode::PercentOutput, forward - reverse);
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/ArmServoSubsystem.h"

using namespace ArmServoConstants;

ArmServoSubsystem::ArmServoSubsystem() : armServo{ARM_ID} {
};

// This method will be called once per scheduler run
void ArmServoSubsystem::Periodic() {}

void ArmServoSubsystem::UpdateArm(bool active) {
    if (active) {
        armServo.Set(0.8); //percentage. 1 would be fully turned, 0 default.
    } else {
        armServo.Set(0);
    }
}

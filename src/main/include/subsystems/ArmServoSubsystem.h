// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <Constants.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/Servo.h>

using namespace frc;

class ArmServoSubsystem : public frc2::SubsystemBase {
    public:
        ArmServoSubsystem();

        /**
        * Will be called periodically whenever the CommandScheduler runs.
        */
        void Periodic() override;

        void UpdateArm(bool active);

    private:
        // Components (e.g. motor controllers and sensors) should generally be
        // declared private and exposed only through public methods.
        Servo armServo;
};

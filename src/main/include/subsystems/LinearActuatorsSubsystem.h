// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <Constants.h>
#include <frc2/command/SubsystemBase.h>
#include <ctre/phoenix/motorcontrol/can/TalonSRX.h>

using namespace ctre::phoenix;

class LinearActuatorsSubsystem : public frc2::SubsystemBase {
    public:
        LinearActuatorsSubsystem();

        /**
         * Will be called periodically whenever the CommandScheduler runs.
         */
        void Periodic() override;

        void RunActuators(double forward, double reverse);

    private:
        // Components (e.g. motor controllers and sensors) should generally be
        // declared private and exposed only through public methods.
        motorcontrol::can::TalonSRX backActuator1;
        motorcontrol::can::TalonSRX backActuator2;
        motorcontrol::can::TalonSRX frontActuator;
};

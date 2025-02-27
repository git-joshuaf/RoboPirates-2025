// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <Constants.h>
#include <frc2/command/SubsystemBase.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h> //need special varient to work with differentialdrive.
#include <rev/SparkMax.h>

using namespace ctre::phoenix; // helps keep things shorter while still being clear, since we know these motors will use this

class DriveSubsystem : public frc2::SubsystemBase {
    public:
        DriveSubsystem();

        /**
         * Will be called periodically whenever the CommandScheduler runs.
         */
        void Periodic() override;

        void set(double leftSpeed, double rightSpeed);

        void stop();

        void ArcadeDrive(double xSpeed, double zRotation);

    private:
        // Components (e.g. motor controllers and sensors) should generally be
        // declared private and exposed only through public methods.
        motorcontrol::can::WPI_TalonSRX leftLeader;
        motorcontrol::can::WPI_TalonSRX leftFollower;
        motorcontrol::can::WPI_TalonSRX rightLeader;
        motorcontrol::can::WPI_TalonSRX rightFollower;
        
        frc::DifferentialDrive drive{leftLeader, rightLeader};
};

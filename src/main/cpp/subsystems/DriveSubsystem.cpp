// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveSubsystem.h"

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem() :
        leftLeader{LEFT_LEADER_ID},
        leftFollower{LEFT_FOLLOWER_ID},
        rightLeader{RIGHT_LEADER_ID},
        rightFollower{RIGHT_FOLLOWER_ID} {
    leftLeader.ConfigFactoryDefault();
    leftFollower.ConfigFactoryDefault();
    rightLeader.ConfigFactoryDefault();
    rightFollower.ConfigFactoryDefault();

    leftLeader.ConfigVoltageCompSaturation(12.0); //figure out what this does, + current limit
    rightLeader.ConfigVoltageCompSaturation(12.0);
    leftFollower.ConfigVoltageCompSaturation(12.0);
    rightFollower.ConfigVoltageCompSaturation(12.0);

    leftFollower.Follow(leftLeader);
    rightFollower.Follow(rightLeader);

    leftLeader.SetInverted(motorcontrol::InvertType::InvertMotorOutput);
    leftFollower.SetInverted(motorcontrol::InvertType::FollowMaster);
    rightLeader.SetInverted(motorcontrol::InvertType::None);
    rightFollower.SetInverted(motorcontrol::InvertType::FollowMaster);


    /* //old motor code
    SparkBaseConfig motorConfig;
    motorConfig.VoltageCompensation(12.0);
    motorConfig.SmartCurrentLimit(DRIVE_MOTOR_CURRENT_LIMIT);
    
    motorConfig.Follow(leftLeader);
    leftFollower.Configure(motorConfig, SparkBase::ResetMode::kResetSafeParameters, SparkBase::PersistMode::kPersistParameters);
    motorConfig.Follow(rightLeader);
    rightFollower.Configure(motorConfig, SparkBase::ResetMode::kResetSafeParameters, SparkBase::PersistMode::kPersistParameters);

    motorConfig.DisableFollowerMode();

    rightLeader.Configure(motorConfig, SparkBase::ResetMode::kResetSafeParameters, SparkBase::PersistMode::kPersistParameters);
    motorConfig.Inverted(true);
    leftLeader.Configure(motorConfig, SparkBase::ResetMode::kResetSafeParameters, SparkBase::PersistMode::kPersistParameters);
    */
};

// This method will be called once per scheduler run
void DriveSubsystem::Periodic() {}

void DriveSubsystem::set(double leftSpeed, double rightSpeed) { //simple example of motor usage. Unlikely to use for actual driving
    leftLeader.Set(motorcontrol::ControlMode::PercentOutput, leftSpeed); //num between -1 and 1. Like a percentage. 1 would be 100% of the motor's speed
    rightLeader.Set(motorcontrol::ControlMode::PercentOutput, rightSpeed);
}

void DriveSubsystem::stop() {
    leftLeader.Set(motorcontrol::ControlMode::PercentOutput, 0);
    rightLeader.Set(motorcontrol::ControlMode::PercentOutput, 0);
}

void DriveSubsystem::ArcadeDrive(double xSpeed, double zRotation) {
    drive.ArcadeDrive(xSpeed, zRotation);
}
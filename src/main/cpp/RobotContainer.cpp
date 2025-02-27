// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() {
    // Initialize all of your commands and subsystems here

    // Configure the button bindings
    ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
    // Configure your trigger bindings here

    driveSubsystem.SetDefaultCommand(DriveCommand(
        &driveSubsystem,
        [this] { return -driverController.GetLeftY(); },
        [this] { return -driverController.GetRightX(); }
    )); //weird lambdas(?), basically lets drive command get info from controller without passing in controller. Maybe change this

    driverController.A().WhileTrue(RollerCommand( //constant speed while held
        &rollerSubsystem,
        [this] { return RollerConstants::ROLLER_MOTOR_EJECT_SPEED; },
        [this] { return 0; })
        .WithName("Fixed speed"));

    linearActuatorsSubsystem.SetDefaultCommand(LinearActuatorsCommand( //uses triggers to raise robot
        &linearActuatorsSubsystem,
        [this] { return driverController.GetRightTriggerAxis(); },
        [this] { return driverController.GetLeftTriggerAxis(); }
    ));

    armServoSubsystem.SetDefaultCommand(ArmServoCommand(
        &armServoSubsystem,
        [this] { return driverController.B().Get(); }
    ));
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
    // An example command will be run in autonomous
    return AutoCommand(&driveSubsystem, &rollerSubsystem, &linearActuatorsSubsystem, &armServoSubsystem, &cameraSubsystem).ToPtr();
}

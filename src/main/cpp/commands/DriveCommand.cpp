// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/DriveCommand.h"

DriveCommand::DriveCommand(DriveSubsystem *driveSubsystem, function<double()> xSpeed, function<double()> zRotation)
    : driveSubsystem(driveSubsystem), xSpeed(), zRotation() {
    // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements(driveSubsystem);
}

// Called when the command is initially scheduled.
void DriveCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() {
    driveSubsystem->ArcadeDrive(xSpeed(), zRotation());
}

// Called once the command ends or is interrupted.
void DriveCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveCommand::IsFinished() {
    return false;
}

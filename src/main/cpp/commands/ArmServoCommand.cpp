// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ArmServoCommand.h"

ArmServoCommand::ArmServoCommand(ArmServoSubsystem *armServoSubsystem, function<bool()> active) 
    : armServoSubsystem(armServoSubsystem), active() {
    // Use AddRequirements() here to declare subsystem dependencies.
    AddRequirements(armServoSubsystem);
}

// Called when the command is initially scheduled.
void ArmServoCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArmServoCommand::Execute() {
    armServoSubsystem->UpdateArm(active());
}

// Called once the command ends or is interrupted.
void ArmServoCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool ArmServoCommand::IsFinished() {
    return false;
}

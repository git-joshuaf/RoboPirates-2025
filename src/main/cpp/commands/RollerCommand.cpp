// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/RollerCommand.h"

RollerCommand::RollerCommand(RollerSubsystem *rollerSubsystem, function<double()> forward, function<double()> reverse)
    : rollerSubsystem(rollerSubsystem), forward(), reverse() {
    // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements(rollerSubsystem);
};

// Called when the command is initially scheduled.
void RollerCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RollerCommand::Execute() {
    rollerSubsystem->RunRoller(forward(), reverse());
}

// Called once the command ends or is interrupted.
void RollerCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool RollerCommand::IsFinished() {
    return false;
}

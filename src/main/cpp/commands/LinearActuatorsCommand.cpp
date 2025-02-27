// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/LinearActuatorsCommand.h"

LinearActuatorsCommand::LinearActuatorsCommand(LinearActuatorsSubsystem *linearActuatorsSubsystem, function<double()> forward, function <double()> reverse) 
    : linearActuatorsSubsystem(linearActuatorsSubsystem), forward(), reverse() {
    // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements(linearActuatorsSubsystem);
}

// Called when the command is initially scheduled.
void LinearActuatorsCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LinearActuatorsCommand::Execute() {
    linearActuatorsSubsystem->RunActuators(forward(), reverse());
}

// Called once the command ends or is interrupted.
void LinearActuatorsCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool LinearActuatorsCommand::IsFinished() {
    return false;
}

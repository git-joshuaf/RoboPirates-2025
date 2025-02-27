// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CameraCommand.h"

CameraCommand::CameraCommand(CameraSubsystem *cameraSubsystem) :
    cameraSubsystem(cameraSubsystem) {
    // Use AddRequirements() here to declare subsystem dependencies.
    AddRequirements(cameraSubsystem);
}

// Called when the command is initially scheduled.
void CameraCommand::Initialize() {
  cameraTimer.Restart();
}

// Called repeatedly when this Command is scheduled to run
void CameraCommand::Execute() {
    cameraSubsystem->UpdateCamera();
  if (cameraTimer.Get().value() >= camUpdateTime) {
    //call process on subsystem
    cameraTimer.Restart();
  }
}

// Called once the command ends or is interrupted.
void CameraCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool CameraCommand::IsFinished() {
  return false;
}

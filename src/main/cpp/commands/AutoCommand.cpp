// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/AutoCommand.h"

AutoCommand::AutoCommand(DriveSubsystem *driveSubsystem, RollerSubsystem *rollerSubsystem,
    LinearActuatorsSubsystem *linearActuatorsSubsystem, ArmServoSubsystem *armServoSubsystem,
    CameraSubsystem *cameraSubsystem)
    : driveSubsystem(driveSubsystem), rollerSubsystem(rollerSubsystem),
        linearActuatorsSubsystem(linearActuatorsSubsystem), armServoSubsystem(armServoSubsystem),
        cameraSubsystem(cameraSubsystem) {
    // Use addRequirements() here to declare subsystem dependencies.
    AddRequirements({ driveSubsystem, rollerSubsystem, linearActuatorsSubsystem, armServoSubsystem, cameraSubsystem });
}

// Called when the command is initially scheduled.
void AutoCommand::Initialize() {
    phaseTimer.Restart();
}

// Called repeatedly when this Command is scheduled to run
void AutoCommand::Execute() {
    if (phaseTimer.Get().value() <= 3) {
        driveSubsystem->ArcadeDrive(0.5, 0.0); //drive forward at 50% power
    } else if (phaseTimer.Get().value() <= 4) {
        //align with april tag NOT IMPLEMENTED
        rollerSubsystem->RunRoller(RollerConstants::ROLLER_MOTOR_EJECT_SPEED, 0);
    } else if (phaseTimer.Get().value() <= 8) {
        linearActuatorsSubsystem->RunActuators(LinearActuatorsConstants::ACTUATORS_MOTOR_EJECT_SPEED, 0);
    } else {
        armServoSubsystem->UpdateArm(true);
    }
    wpi::outs() << std::to_string(std::round(phaseTimer.Get().value() * 1000) * 0.001) << '\n';
}

// Called once the command ends or is interrupted.
void AutoCommand::End(bool interrupted) {
    phaseTimer.Stop();
    armServoSubsystem->UpdateArm(false);
    driveSubsystem->ArcadeDrive(0.0, 0.0);
}

// Returns true when the command should end.
bool AutoCommand::IsFinished() {
    return phaseTimer.Get().value() >= phaseTimeSec;
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Timer.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/DriveSubsystem.h"
#include "subsystems/RollerSubsystem.h"
#include "subsystems/LinearActuatorsSubsystem.h"
#include "subsystems/ArmServoSubsystem.h"
#include "subsystems/CameraSubsystem.h"
/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending Command
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCommand : public frc2::CommandHelper<frc2::Command, AutoCommand> {
    public:
        /* You should consider using the more terse Command factories API instead
        * https://docs.wpilib.org/en/stable/docs/software/commandbased/organizing-command-based.html#defining-commands
        */
        AutoCommand(DriveSubsystem *driveSubsystem, RollerSubsystem *rollerSubsystem,
            LinearActuatorsSubsystem *linearActuatorSubsystem, ArmServoSubsystem *armServoSubsystem,
            CameraSubsystem *cameraSubsystem);

        void Initialize() override;

        void Execute() override;

        void End(bool interrupted) override;

        bool IsFinished() override;

    private:
        DriveSubsystem *driveSubsystem;
        RollerSubsystem *rollerSubsystem;
        LinearActuatorsSubsystem *linearActuatorsSubsystem;
        ArmServoSubsystem *armServoSubsystem;
        CameraSubsystem *cameraSubsystem;

        frc::Timer phaseTimer;

        double phaseTimeSec = 15; //15 second auto at beginning of match
};

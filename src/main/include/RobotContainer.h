// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandPS4Controller.h>
//#include <frc2/command/button/CommandJoystick.h>

#include "Constants.h"

#include "subsystems/DriveSubsystem.h"
#include "subsystems/RollerSubsystem.h"
#include "subsystems/LinearActuatorsSubsystem.h"
#include "subsystems/ArmServoSubsystem.h"
#include "subsystems/CameraSubsystem.h"

#include "commands/DriveCommand.h"
#include "commands/RollerCommand.h"
#include "commands/LinearActuatorsCommand.h"
#include "commands/ArmServoCommand.h"
#include "commands/CameraCommand.h"
#include "commands/AutoCommand.h"

using namespace frc2;
/**
* This class is where the bulk of the robot should be declared.  Since
* Command-based is a "declarative" paradigm, very little robot logic should
* actually be handled in the {@link Robot} periodic methods (other than the
* scheduler calls).  Instead, the structure of the robot (including subsystems,
* commands, and trigger mappings) should be declared here.
*/
class RobotContainer {
    public:
        RobotContainer();

        CommandPtr GetAutonomousCommand();

    private:
        // The robot's subsystems are defined here...
        CommandPS4Controller driverController{OperatorConstants::DRIVER_CONTROLLER_PORT};

        DriveSubsystem driveSubsystem;
        RollerSubsystem rollerSubsystem;
        LinearActuatorsSubsystem linearActuatorsSubsystem;
        ArmServoSubsystem armServoSubsystem;
        CameraSubsystem cameraSubsystem;

        void ConfigureBindings();
};

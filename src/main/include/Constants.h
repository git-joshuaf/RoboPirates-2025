// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace DriveConstants {
    constexpr int LEFT_LEADER_ID = 1; //motor ids. change these to match robot
    constexpr int LEFT_FOLLOWER_ID = 2;
    constexpr int RIGHT_LEADER_ID = 3;
    constexpr int RIGHT_FOLLOWER_ID = 4;
    
    constexpr int DRIVE_MOTOR_CURRENT_LIMIT = 60;
}
namespace RollerConstants {
    constexpr int ROLLER_MOTOR_ID = 5;
    constexpr int ROLLER_MOTOR_CURRENT_LIMIT = 60;
    constexpr double ROLLER_MOTOR_VOLTAGE_COMP = 10;
    constexpr double ROLLER_MOTOR_EJECT_SPEED = 0.44;
}
namespace LinearActuatorsConstants {
    constexpr int BACK_ID1 = 6;
    constexpr int BACK_ID2 = 7;
    constexpr int FRONT_ID = 8;

    constexpr double ACTUATORS_VOLTAGE_COMP = 10;
    constexpr double ACTUATORS_MOTOR_EJECT_SPEED = 0.44;
}
namespace ArmServoConstants {
    constexpr int ARM_ID = 9;
}
namespace CameraConstants {
    constexpr int WIDTH_PIX = 1280;
    constexpr int HEIGHT_PIX = 720;
    constexpr double UPDATE_TIME = 0.1;
}
namespace OperatorConstants {
    constexpr int DRIVER_CONTROLLER_PORT = 0;
    constexpr int OPERATOR_CONTROLLER_PORT = 1;
}

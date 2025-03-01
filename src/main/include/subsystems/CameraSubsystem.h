// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <frc/Timer.h>
#include <cameraserver/CameraServer.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <frc/apriltag/AprilTagDetector.h>
#include <frc/apriltag/AprilTagPoseEstimator.h>
#include <thread>
#include <vector>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

using namespace CameraConstants;

class CameraSubsystem : public frc2::SubsystemBase {
public:
    CameraSubsystem();

    /**
    * Will be called periodically whenever the CommandScheduler runs.
    */
    void Periodic() override;

    void UpdateCamera();

    static void VisionThread();

private:
    // Components (e.g. motor controllers and sensors) should generally be
    // declared private and exposed only through public methods.
    /*cs::UsbCamera camera;
    cs::CvSink cvSink;
    cs::CvSource outputStream;
    cv::Mat mat;*/
};

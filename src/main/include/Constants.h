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

namespace OperatorConstants {

constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants

namespace canid {
    constexpr int shootermotor {1};
    constexpr int intakemotor {2};
}

namespace pcm {
    constexpr int feederCylinderFoward =1;
    constexpr int feederCylinderReverse =2;
    constexpr int intakeCylinderFoward =3;
    constexpr int intakeCylinderReverse =4;
    // Can I put 2 Cylinders in one constexpr?
}
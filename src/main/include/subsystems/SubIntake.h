// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>

class SubIntake : public frc2::SubsystemBase {
 public:
  static SubIntake& GetInstance() {static SubIntake inst; return inst;}
  SubIntake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void StartIntake();
  void StopIntake();
  void ExtendIntake();
  void RetractIntake();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax _intakemotor{
    canid::intakemotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless
  };
  frc::DoubleSolenoid _intakeCylinder{1, frc::PneumaticsModuleType::CTREPCM,
    pcm::intakeCylinderFoward,
    pcm::intakeCylinderReverse
  };

};

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include "Constants.h"
#include <frc/DoubleSolenoid.h>

class SubShooter : public frc2::SubsystemBase {
 public:
  static SubShooter& GetInstance() {static SubShooter inst; return inst;}
  SubShooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void StartSpinning();
  void StopSpinning();
  void ExtendFeeder();
  void RetractFeeder();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::CANSparkMax _shooterMotor{
    canid::shootermotor, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  frc::DoubleSolenoid _feederCylinder{ 1, frc::PneumaticsModuleType::CTREPCM, 
    pcm::feederCylinderFoward,
    pcm::feederCylinderReverse
  };

};

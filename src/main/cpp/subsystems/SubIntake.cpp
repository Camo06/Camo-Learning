// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIntake.h"

SubIntake::SubIntake() = default;

// This method will be called once per scheduler run
void SubIntake::Periodic() {}

void SubIntake::StartIntake(){
    _intakemotor.Set(1);
}
void SubIntake::StopIntake(){
    _intakemotor.Set(0);
}
void SubIntake::ExtendIntake(){
    _intakeCylinder.Set(frc::DoubleSolenoid::kForward);
}
void SubIntake::RetractIntake(){
    _intakeCylinder.Set(frc::DoubleSolenoid::kReverse);
}
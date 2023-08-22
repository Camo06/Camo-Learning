// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubShooter.h"
#include "frc/smartdashboard/SmartDashboard.h"

SubShooter::SubShooter() = default;

// This method will be called once per scheduler run
void SubShooter::Periodic() {
    frc::SmartDashboard::PutNumber("Shooter Speed", _shooterMotor.Get());
}

void SubShooter::StartSpinning(){
    _shooterMotor.Set(0.8);
}

void SubShooter::StopSpinning(){
    _shooterMotor.Set(0);  
}
void SubShooter::ExtendFeeder(){
    _feederCylinder.Set(frc::DoubleSolenoid::kForward);
}
void SubShooter::RetractFeeder(){
    _feederCylinder.Set(frc::DoubleSolenoid::kForward);
}
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>

#include <frc2/command/Commands.h>
#include "subsystems/SubShooter.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here
  using namespace frc2::cmd;
  _driverController.A().OnTrue(RunOnce([]{
    SubShooter::GetInstance().StartSpinning();
    SubShooter::GetInstance().ExtendFeeder();
    }));
  _driverController.A().OnFalse(RunOnce([]{
    SubShooter::GetInstance().StopSpinning();
    SubShooter::GetInstance().RetractFeeder();
    }));
  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  frc2::Trigger([this] {
    return m_subsystem.ExampleCondition();
  }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  _driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}

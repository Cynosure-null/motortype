// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Timer.h>
#include <frc/XboxController.h>


#include "rev/CANSparkMax.h"

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  frc::XboxController m_stick{0};

  frc::Timer mainTimer;

  static const int theOneTrueMotorDeviceID = 1;
rev::CANSparkMax m_theOneTrueMotor{theOneTrueMotorDeviceID, rev::CANSparkMax::MotorType::kBrushless};\
rev::SparkMaxRelativeEncoder m_theOneTrueMotorEncoder = m_theOneTrueMotor.GetEncoder();

  frc::DoubleSolenoid m_shooterShifter{frc::PneumaticsModuleType::CTREPCM, 1, 2};

};

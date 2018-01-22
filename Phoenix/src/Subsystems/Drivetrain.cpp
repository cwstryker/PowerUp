// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ctre/Phoenix.h"


#include "Drivetrain.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/DriveWithJoy.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

Drivetrain::Drivetrain() : frc::Subsystem("Drivetrain") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    frontleft = RobotMap::drivetrainfrontleft;
    rearleft = RobotMap::drivetrainrearleft;
    frontright = RobotMap::drivetrainfrontright;
    rearright = RobotMap::drivetrainrearright;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    l_pos = 0.0;
    r_pos = 0.0;

    //left_y =-1*xbox->GetRawAxis(1);

}

void Drivetrain::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new DriveWithJoy());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void Drivetrain::Periodic() {
    // Put code here to be run every loop

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void Drivetrain::userDrive(std::shared_ptr<Joystick>xbox){
	double left_y =-1*xbox->GetRawAxis(1);
	double right_y = 1*xbox->GetRawAxis(5);
	if (fabs(left_y) < 0.10)
		left_y = 0;
	if (fabs(right_y) < 0.10)
		right_y = 0;

	frontleft->Set(ControlMode::PercentOutput, left_y); //TODO test If structure for multiple speeds
	frontright->Set(ControlMode::PercentOutput, right_y);

}

void Drivetrain::encoderPosition(double left, double right){
	frontleft->Set(ControlMode::Position, 80*left);
	frontright->Set(ControlMode::Position, -80*right);


	l_pos = left;
	r_pos = right;
}

void Drivetrain::encoderReset(){

	frontleft->SetSelectedSensorPosition(0, 0, 10);
	frontright->SetSelectedSensorPosition(0, 0, 10);

}

void Drivetrain::encoderDone(){
	frontleft->Set(ControlMode::PercentOutput, 0.0); //TODO test If structure for multiple speeds
	frontright->Set(ControlMode::PercentOutput, 0.0);

	l_pos = 0.0;
	r_pos = 0.0;

}

bool Drivetrain::isMove(){
	if ((frontleft->GetSelectedSensorPosition(0) < (l_pos + .1) && frontleft->GetSelectedSensorPosition(0) > (l_pos - .1))
				&& frontright->GetSelectedSensorPosition(0) < (r_pos + .1)
				&& frontright->GetSelectedSensorPosition(0) > (r_pos - .1)) {
			return true;
		} else {
			return false;
		}
}

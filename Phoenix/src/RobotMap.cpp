// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "ctre/Phoenix.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<WPI_TalonSRX> RobotMap::drivetrainfrontleft;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivetrainrearleft;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivetrainfrontright;
std::shared_ptr<WPI_TalonSRX> RobotMap::drivetrainrearright;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    frc::LiveWindow *lw = frc::LiveWindow::GetInstance();

    drivetrainfrontleft.reset(new WPI_TalonSRX(0));
    
    
    drivetrainrearleft.reset(new WPI_TalonSRX(1));
    
    
    drivetrainfrontright.reset(new WPI_TalonSRX(2));
    
    
    drivetrainrearright.reset(new WPI_TalonSRX(3));
    
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    /*Set up the talons */

    drivetrainrearleft->Follow(*drivetrainfrontleft); //rear left to follow front left

    drivetrainrearright->Follow(*drivetrainfrontright); //rear right to follow front right

    /*Set up the encoders */

    drivetrainfrontleft->SetSensorPhase(true); //reverse sensors?


    drivetrainfrontright->SetSensorPhase(true); //reverse sensors?

    drivetrainfrontleft->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 10); //Set the talons to use quad encoders
    drivetrainfrontright->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,10);

    drivetrainfrontleft->Config_kF(0, 0.0, 10.0);
    drivetrainfrontleft->Config_kP(0, 6.39375, 10.0);
    drivetrainfrontleft->Config_kI(0, 0.0, 10.0);
    drivetrainfrontleft->Config_kD(0, 639.375, 10.0);


    drivetrainfrontright->Config_kF(0, 0.0, 10.0);
    drivetrainfrontright->Config_kP(0, 6.39375, 10.0);
    drivetrainfrontright->Config_kI(0, 0.0, 10.0);
    drivetrainfrontright->Config_kD(0, 639.375, 10.0);




}
// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef MOTIONPROFILE_H
#define MOTIONPROFILE_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "Profiles.h"
#include "../Instrumentation.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class MotionProfile: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<WPI_TalonSRX> frontleft;
	std::shared_ptr<WPI_TalonSRX> frontright;





	public:
	MotionProfile();
	void InitDefaultCommand() override;
	void Periodic() override;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

	//std::shared_ptr<MotionProfileStatus> _status;

	MotionProfileStatus _status;

	//std::shared_ptr<Notifier> _notifier;

	Notifier _notifier;

	SetValueMotionProfile _setValue;


	double _lpos;
	double _rpos;
	double _lvel;
	double _rvel;
	double _lheading;
	double _rheading;

	int _state;

	int _loopTimeout;

	bool _bStart;

	static const int kMinPointsInTalon =5;

	static const int kNumLoopsTimeout=10;

	void PeriodicTask();

	void initMotionProfile();

	void removeUnderrun();

	void reset();

	void control();

	//void startFilling();

	void startFilling(const double leftprofile[][3], int leftCnt, const double rightprofile[][3], int rightCnt);

	void start();

	SetValueMotionProfile getSetValue();





};

#endif

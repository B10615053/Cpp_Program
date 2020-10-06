#pragma once

// Laser Vessel
#include "VesselObject.h"

#define LASER_ATTACK_TIME	9.0
#define LASER_ATTACK_RADIUS	0.6

#pragma region data table
#define NAME				("LV")
#define HP					1.0
#define MAX_VESSEL_SPEED	(4.0 / 60.0)
#define MAX_ATTACK_DIS		25.0
#define ATTACK_CD			90.0
#define MAX_DEFENSE_DIS		0.0
#define DEFENSE_CD			0.0
#define DAMAGE				6.0
#define SHELL_SPEED			(0.0 / 60.0)

#define LASER_CD			90.0
#pragma endregion

ref class VesselLV : public VesselObject {

public:
	VesselLV();
	VesselLV(VesselLV^&);
	VesselLV(String^, TeamSymbol, PointF);

	VesselLV^ operator=(VesselLV^);

	virtual bool render(Graphics^) override;

	//¹p®g§PÂ_¨ç¼Æ
	bool ShootLaser(double _xx, double _yy) {
		double X_Long = 0;
		if (LaserAngle >= 0 && LaserAngle <= 90 || LaserAngle <= 360 && LaserAngle >= 270) {
			X_Long = 20.0 - getCoord().X;
		}
		else {
			X_Long = getCoord().X - 0.0;
		}
		double slope_long = 0;
		if (Math::Cos(ANGLE_TO_RADIUS(LaserAngle)) == 0) { slope_long == 0; }
		else { slope_long = X_Long / Math::Cos(ANGLE_TO_RADIUS(LaserAngle)); }
		double Y_long;
		Y_long = slope_long * Math::Sin(ANGLE_TO_RADIUS(LaserAngle))*(-1);
		////////////////
		if (X_Long != 0) {
			double slopeofLaser = Y_long / X_Long;
			double dis = Math::Abs(slopeofLaser*_xx + (-1)*_yy + (-1)*(slopeofLaser*getCoord().X + getCoord().Y*(-1))) / Math::Sqrt(slopeofLaser*slopeofLaser + 1.0);
			if (dis <= 0.5) return true;
			else return false;
		}
		else {
			double dis = Math::Abs(_xx - getCoord().X);
			if (dis <= 0.5) return true;
			else return false;
		}
	}

	virtual bool DrawLaser(Graphics^) override;

	#pragma region getters and setters
	virtual void SetLaserAngle(double) override;
	virtual double GetLaserAngle() override;

	virtual void setIsLaserShooting(bool) override;
	virtual bool getIsLaserShooting() override;

	virtual void setLaserCD(double) override;
	virtual double getLaserCD() override;

	virtual void setRemainLaserCD(double) override;
	virtual void minus1RemainLaserCD() override;
	virtual double getRemainLaserCD() override;

	virtual void setIsLaserHitSomething(bool) override;
	virtual bool getIsLaserHitSomething() override;

	virtual void setLaserLog(String^) override;
	virtual void strcatLaserLog(String^) override;
	virtual String^ getLaserLog() override;
	#pragma endregion

private:
	double LaserAngle;
	double laserCD;
	double remainLaserCD;
	bool isLaserShooting;
	bool isLaserHitSomething;
	String^ laserLog;
};
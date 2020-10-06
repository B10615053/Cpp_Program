#pragma once

#include "HydrometeorologicSystem.h"

#define SPEED			(4.0 / 60.0)
#define DAMAGE			0.05
#define ATTACK_RANGE	2.0

ref class Typhoon : public HydrometeorologicSystem {
public:
	Typhoon();
	Typhoon(Typhoon^&);
	Typhoon(double, PointF);

	Typhoon^ operator=(Typhoon^);

	virtual double getRotatePictureAngle() override;
	virtual void setRotatePictureAngle(double) override;


	virtual bool render(Graphics^) override;

private:
	double rotatePictureAngle;
};


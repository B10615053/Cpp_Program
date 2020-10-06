#pragma once

#include "HydrometeorologicSystem.h"

#define SPEED			0.0
#define DAMAGE			6.0
#define ATTACK_RANGE	1.0

ref class Lightning : public HydrometeorologicSystem {
public:
	Lightning();
	Lightning(Lightning^&);
	Lightning(PointF);

	Lightning^ operator=(Lightning^);

	virtual bool render(Graphics^) override;

	virtual double getRotatePictureAngle() override;
	virtual void setRotatePictureAngle(double) override;

private:
	double biasX4Pic = 2.5;
	double biasY4Pic = -(BLOCK_LENGTH + 5.5);
};


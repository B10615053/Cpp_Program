#pragma once

#include "HydrometeorologicSystem.h"

#define SPEED			0.0
#define DAMAGE			0.0
#define ATTACK_RANGE	1.0

#define MAX_FOG_SIZE	15.0

ref class Fog : public HydrometeorologicSystem {
public:
	Fog();
	Fog(Fog^&);
	//Fog(PointF);

	Fog^ operator=(Fog^);

	virtual bool render(Graphics^) override;

	#pragma region getters and setters
	virtual double getRotatePictureAngle() override;
	virtual void setRotatePictureAngle(double) override;

	virtual SizeF getSize() override;
	virtual void setSize(SizeF) override;

	virtual SizeF getSize4Draw() override;
	virtual void setSize4Draw(SizeF) override;
	#pragma endregion


private:
	SizeF size;
	SizeF size4Draw;
};


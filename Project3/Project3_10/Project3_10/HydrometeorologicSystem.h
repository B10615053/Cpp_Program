#pragma once

#include "RenderParameter.h"
#include "Team.h"

#define PICTURE_LIGHTNING	dynamic_cast<Bitmap^>(Bitmap::FromFile("picture/lightning.png"))
#define PICTURE_TYPHOON		dynamic_cast<Bitmap^>(Bitmap::FromFile("picture/typhoon.png"))

#define ROTATE_ANGLE	3.0
#define TOTAL_FOG_TIME	100.0

enum HydroType{ TYPHOON, LIGHTNING, FOG, UNKNOWN_HYDRO_TYPE };

ref class HydrometeorologicSystem {
public:
	HydrometeorologicSystem();
	HydrometeorologicSystem(HydrometeorologicSystem^&);
	HydrometeorologicSystem(double, PointF);

	#pragma region getters and setters
	Bitmap^ getPicture();
	void setPicture(Bitmap^);

	HydroType getHydroType();
	void sethydroType(HydroType);

	double getDamage();
	void setDamage(double);

	double getAttackRange();
	void setAttackRange(double);

	double getSpeed();
	void setSpeed(double);

	PointF getNowCoord();
	void setNowCoord(PointF);

	PointF getNowCoord4Draw();
	void setNowCoord4Draw(PointF);

	int getExistTime();
	void setExistTime(int);

	GraphicsPath^ getGp();
	void setGp(GraphicsPath^);

	bool getMouseIn();
	void setMouseIn(bool);

	virtual SizeF getSize() override;
	virtual void setSize(SizeF) override;

	virtual SizeF getSize4Draw() override;
	virtual void setSize4Draw(SizeF) override;
	#pragma endregion

	void hydroMove();
	bool BoundaryJudgment(double, double);

	// Hydrometeorology list
	static List<HydrometeorologicSystem^> hydroList;

	virtual bool render(Graphics^) override;

	// rotate the image
	Bitmap^ RotateImage(Bitmap^, float);

	// helper function: calculate new size
	Size^ CalculateNewSize(int, int, double);

	virtual double getRotatePictureAngle() override;
	virtual void setRotatePictureAngle(double) override;

protected:
	Bitmap^ picture;
	HydroType hydroType;
	double damage;
	double attackRange;
	double speed;
	double angle;
	PointF nowCoord;
	PointF nowCoord4Draw;
	int existTime;
	GraphicsPath^ gpHydro;

	bool mouseIn;
};
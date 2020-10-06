#pragma once

// Weapon: Torpedo
#include "RenderParameter.h"

using namespace System;
using namespace System::Windows;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

// THE SAME ATTACK DISTANCE TO THE SHELL.
// DIFFERENCE CD TIME TO THE SHELL!
#define TORPEDO_EXPLODE_RANGE 0.3
#define PICTURE dynamic_cast<Bitmap^>(Bitmap::FromFile("picture/torpedo.png"))
#define INF 2147483647.0

ref class Torpedo {
public:
	Torpedo();
	Torpedo(Torpedo^&);
	Torpedo(String^, String^, TeamSymbol, double, double, double, PointF, PointF);

	Torpedo^ operator=(Torpedo^);

	#pragma region getters and setters
	Bitmap^ getPicture();
	void setPicture(Bitmap^);

	String^ getName();
	void setName(String^);

	String^ getVesselName();
	void setVesselName(String^);

	TeamSymbol getTeam();
	void setTeam(TeamSymbol);

	double getSpeed();
	void setSpeed(double);

	double getDamage();
	void setDamage(double);

	double getAngle();
	void setAngle(double);

	PointF getNowCoord();
	void setNowCoord(PointF);

	PointF getNowCoord4Draw();
	void setNowCoord4Draw(PointF);

	PointF getGoalCoord();
	void setGoalCoord(PointF);

	double getTotalFlyingTime();
	void setTotalFlyingTime(double);

	int getNowFlyingTime();
	void setNowFlyingTime(int);
	#pragma endregion

	void TorpedoMove();

	// Torpedo's Icon
	bool render(Graphics^);

private:
	Bitmap^ picture;
	String^ name;
	String^ vesselName;
	TeamSymbol team;
	double speed;
	double damage;
	double angle;
	PointF nowCoord;
	PointF nowCoord4Draw;
	PointF goalCoord;
	double totalFlyingTime;
	int nowFlyingTime;

	// Helper function of render
	// Rotate to icon
	Bitmap^ RotateImage(Bitmap^, float);

	// Calculate the new size
	Size^ CalculateNewSize(int, int, double);
};
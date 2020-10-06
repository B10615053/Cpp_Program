#pragma once

#include "RenderParameter.h"
#define EXPLOSION_RADIUS 1.5
#define PICTURE dynamic_cast<Bitmap^>(Bitmap::FromFile("picture/shell.png"))
#define INF 2147483647.0

using namespace System;
using namespace System::Windows;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

ref class Shell {

public:
	Shell();
	Shell(Shell^&);
	Shell(String^, TeamSymbol, double, double, double, PointF, PointF);

	Shell^ operator=(Shell^);

	#pragma region getters and setters
	Bitmap^ getPicture();
	void setPicture(Bitmap^);

	String^ getName();
	void setName(String^);

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

	void ShellMove();

	bool render(Graphics^);

	// rotate the image
	Bitmap^ RotateImage(Bitmap^, float);

	// helper function: calculate new size
	Size^ CalculateNewSize(int, int, double);

private:

	Bitmap^ picture;
	String^ name;
	TeamSymbol team;
	double speed;
	double damage;
	double angle;
	PointF nowCoord;
	PointF nowCoord4Draw;
	PointF goalCoord;
	double totalFlyingTime;
	int nowFlyingTime;
};


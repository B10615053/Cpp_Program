#pragma once

#include "RenderParameter.h"
#include "Team.h"

#define VESSEL_AND_GEO_COLLAPSION_DIS ((VESSEL_ICON_LENGTH / 2.0) / BLOCK_LENGTH)
#define SHELL_AND_GEO_COLLAPSION_DIS ((SHELL_ICON_LENGTH / 2.0) / BLOCK_LENGTH)
#define TORPEDO_AND_GEO_COLLAPSION_DIS ((SHELL_ICON_LENGTH / 2.0) / BLOCK_LENGTH)

#define ALPHA_UP_BOUND 255
#define ALPHA_LOW_BOUND 55
#define VIRTUAL_GEO_ALPHA 144

#define REEF_DAMAGE 1.0

using namespace System;
using namespace System::Windows;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;

// 暗礁、平地、高山
enum GeographyType { REEF, FLATLAND, MOUNTAIN, UNKNOWN_GEO_TYPE };

/*
	=====================================

	暗礁 Reef

	Vessel	-> F + Damage
	Shell	-> T
	Torpedo	-> F
	Laser	-> T

	=====================================

	平地 Flatland

	Vessel	-> F
	Shell	-> T
	Torpedo	-> F
	Laser	-> T

	=====================================

	高山 Mountain

	Vessel	-> F
	Shell	-> F
	Torpedo	-> F
	Laser	-> T

	=====================================
*/

ref class GeographicSystem {
public:
	GeographicSystem();
	GeographicSystem(const GeographicSystem^&);
	GeographicSystem(GeographyType, PointF, SizeF);

	#pragma region getters and setters
	GeographyType getGeoType();
	void setGeoType(GeographyType);

	String^ getName();
	void setName(String^);

	PointF getCoord();
	void setCoord(PointF);

	PointF getCoord4Draw();
	void setCoord4Draw(PointF);

	SizeF getSize();
	void setSize(SizeF);

	SizeF getSize4Draw();
	void setSize4Draw(SizeF);

	int getColorAlpha();
	void setColorAlpha(int);

	bool canVesselGoThrough();
	bool canGeneralFireGoThrough();
	bool canTorpedoGoThrough();
	bool canLaserGoThrough();

	double getReefDamage();
	void setReefDamage(double);

	GraphicsPath^ getGp();
	#pragma endregion

	String^ detectAll(Team^, int, int, int&);

	virtual bool render(Graphics^) override;

	// Geography list
	static List<GeographicSystem^> geoList;

	bool mouseIn;

protected:
	static array<String^>^ geoTypeStringList = gcnew array<String^>(12) { "Reef", "Flatland", "Mountain", "Unknown Geography Type" };

	GeographyType geoType;
	String^ name;
	GraphicsPath^ gpGeography;

	PointF coord;
	PointF coord4Draw;
	SizeF size;
	SizeF size4Draw;
	int colorAlpha;

	bool canGoThrough_vessel;
	bool canGoThrough_generalFire;
	bool canGoThrough_torpedo;
	bool canGoThrough_laser;

	double reefDamage;

	// 點到線段（注意：不是直線，是線段）距離
	double getDistanceBetweenPointAndSegment(PointF, PointF, PointF);
};


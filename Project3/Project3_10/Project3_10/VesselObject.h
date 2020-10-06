#pragma once

#include "RenderParameter.h"
#include "Shell.h"
#include "Torpedo.h"

#define COLLAPSION_DAMAGE 1.0
#define TORPEDO_DAMAGE_RADIUS 1.2

using namespace System;
using namespace System::Windows;
using namespace System::Drawing;
using namespace System::Collections::Generic;
using namespace System::Diagnostics;
//using namespace System::Globalization;
//using namespace System::IO;

enum VesselType {CV = 0, BB, CG, DD, LV, AH, UNKNOWN_VESSEL_TYPE};

ref class VesselObject {

public:
	VesselObject();
	VesselObject(const VesselObject^&);
	VesselObject(String^, TeamSymbol, VesselType, PointF, double, double, double, double, double, double, double, double);
	virtual ~VesselObject();

	static array<String^>^ typeStringList = gcnew array<String^> {"CV", "BB", "CG", "DD", "LV", "AH", "UNKNOWN_VESSEL_TYPE"};

	#pragma region getters and setters
	String^ getName();
	void setName(String^);

	TeamSymbol getTeam();
	void setTeam(TeamSymbol);

	VesselType getVesselType();
	void setVesselType(VesselType);

	PointF getCoord();
	void setCoord(PointF);

	PointF getCoord4Draw();
	void setCoord4Draw(PointF);

	GraphicsPath^ getGp();

	double getMaxHp();
	void setMaxHp(double);

	double getRemainHp();
	void setRemainHp(double);

	double getMaxVesselSpeed();
	void setMaxVesselSpeed(double);

	double getMaxAttackDistance();
	void setMaxAttackDistance(double);

	double getAttackCD();
	void setAttackCD(double);

	// Torpedo CD
	double getLaunchCD();
	void setLaunchCD(double);

	double getMaxDefenseDistance();
	void setMaxDefenseDistance(double);

	double getDefenseCD();
	void setDefenseCD(double);

	double getDamage();
	void setDamage(double);

	double getShellSpeed();
	void setShellSpeed(double);

	double getRemainAttackCD();
	void setRemainAttackCD(double);
	void minus1RemainAttackCD();

	// Torpedo only
	double getRemainLaunchCD();
	void setRemainLaunchCD(double);
	void minus1RemainLaunchCD();

	// Torpedo only
	double getTorpedoDamage();
	void setTorpedoDamage(double);
	double getTorpedoSpeed();
	void setTorpedoSpeed(double);

	double getRemainDefenseCD();
	void setRemainDefenseCD(double);
	void minus1RemainDefenseCD();

	double getNowSpeed();
	void setNowSpeed(double);

	double getNowAngle();
	void setNowAngle(double);

	void setCanMove(bool);
	bool getCanMove();
	void initializeMove();

	#pragma region LV only
	virtual void SetLaserAngle(double _angle) override;
	virtual double GetLaserAngle() override;

	virtual void setIsLaserShooting(bool _angle) override;
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

	#pragma region AH only
	virtual void setEnrichValue(double _EnrichValue) override;
	virtual double getEnrichValue() override;

	virtual void setEnrichValue_dis(double _EnrichValue_dis) override;
	virtual double getEnrichValue_dis() override;

	virtual void setEnrichValue_CD(double _EnrichValue_CD) override;
	virtual double getEnrichValue_CD() override;

	virtual void set_remain_Enrich_CD(double _remain_Enrich) override;
	virtual double get_remain_Enrich_CD() override;
	virtual void minus1remain_Enrich_CD() override;
	#pragma endregion

	#pragma endregion

	void VesselMove();
	void DaoTuiLu();
	bool BoundaryJudgment(double, double);

	virtual bool DrawLaser(Graphics^) override;
	virtual bool render(Graphics^) override;

	virtual bool isEnrichVessel(double, double) override;

	bool mouseIn;

protected:
	String^ name;
	TeamSymbol team;
	VesselType vesselType;
	PointF coord;
	PointF coord4Draw;
	GraphicsPath^ gpVessel;

	double maxHp;
	double remainHp;
	double maxVesselSpeed;
	double maxAttackDistance;
	double maxDefenseDistance;
	double attackCD;
	double launchCD;
	double defenseCD;
	double damage;
	double shellSpeed;

	double torpedoDamage;
	double torpedoSpeed;

	double remainAttackCD;
	double remainLaunchCD;
	double remainDefenseCD;

	double nowSpeed;
	double nowAngle;

	bool canMove;
};
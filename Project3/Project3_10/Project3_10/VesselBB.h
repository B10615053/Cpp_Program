#pragma once

// Battle Ship
#include "VesselObject.h"

#pragma region data table
#define NAME				("BB")
#define HP					4.0
#define MAX_VESSEL_SPEED	(1.0 / 60.0)
#define MAX_ATTACK_DIS		20.0
#define ATTACK_CD			30.0
#define MAX_DEFENSE_DIS		10.0
#define DEFENSE_CD			30.0
#define DAMAGE				3.0
#define SHELL_SPEED			(2.0 / 60.0)
#pragma endregion

ref class VesselBB : public VesselObject {
public:
	VesselBB();
	VesselBB(VesselBB^&);
	VesselBB(String^, TeamSymbol, PointF);

	VesselBB^ operator=(VesselBB^);

	virtual bool render(Graphics^) override;
};
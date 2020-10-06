#pragma once

// Battle Cruiser
#include "VesselObject.h"

#pragma region data table
#define NAME				("CG")
#define HP					3.0
#define MAX_VESSEL_SPEED	(2.0 / 60.0)
#define MAX_ATTACK_DIS		15.0
#define ATTACK_CD			30.0
#define MAX_DEFENSE_DIS		15.0
#define DEFENSE_CD			30.0
#define DAMAGE				2.0
#define SHELL_SPEED			(3.0 / 60.0)

#define LAUNCH_CD			60.0
#define TORPEDO_DAMAGE		3.0
#define TORPEDO_SPEED		(2.0 / 60.0)
#pragma endregion

ref class VesselCG : public VesselObject {

public:
	VesselCG();
	VesselCG(VesselCG^&);
	VesselCG(String^, TeamSymbol, PointF);

	VesselCG^ operator=(VesselCG^);

	virtual bool render(Graphics^) override;
};
#pragma once

// Destroyer
#include "VesselObject.h"

#pragma region data table
#define NAME				("DD")
#define HP					2.0
#define MAX_VESSEL_SPEED	(3.0 / 60.0)
#define MAX_ATTACK_DIS		10.0
#define ATTACK_CD			15.0
#define MAX_DEFENSE_DIS		20.0
#define DEFENSE_CD			60.0
#define DAMAGE				1.0
#define SHELL_SPEED			(3.0 / 60.0)

#define LAUNCH_CD			30.0
#define TORPEDO_DAMAGE		3.0
#define TORPEDO_SPEED		(2.0 / 60.0)
#pragma endregion

ref class VesselDD : public VesselObject {

public:
	VesselDD();
	VesselDD(VesselDD^&);
	VesselDD(String^, TeamSymbol, PointF);

	VesselDD^ operator=(VesselDD^);

	virtual bool render(Graphics^) override;
};
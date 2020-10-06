#pragma once

// Aircraft Carrier
#include "VesselObject.h"

#pragma region data table
#define NAME				("CV")
#define HP					5.0
#define MAX_VESSEL_SPEED	(1.0 / 60.0)
#define MAX_ATTACK_DIS		25.0
#define ATTACK_CD			60.0
#define MAX_DEFENSE_DIS		5.0
#define DEFENSE_CD			15.0
#define DAMAGE				3.0
#define SHELL_SPEED			(4.0 / 60.0)
#pragma endregion

ref class VesselCV : public VesselObject {

public:
	VesselCV();
	VesselCV(VesselCV^&);
	VesselCV(String^, TeamSymbol, PointF);

	VesselCV^ operator=(VesselCV^);

	virtual bool render(Graphics^) override;
};


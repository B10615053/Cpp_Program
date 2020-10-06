#pragma once

// Mercy
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

/*darling*/
#define MEnrichValue   1.0
#define MEnrichValue_dis  3.0
#define MEnrichValue_CD   50.0
#define l1ong 6.0;
#define halfl1ong 3.0;
#define w1ong 4.0;
#define halfw1long 2.0;
#pragma endregion

ref class VesselAH : public VesselObject {

public:
	VesselAH();
	VesselAH(VesselAH^&);
	VesselAH(String^, TeamSymbol, PointF);

	VesselAH^ operator=(VesselAH^);

	virtual bool render(Graphics^) override;

	/*darling*/

	virtual void setEnrichValue(double _EnrichValue) override;
	virtual double getEnrichValue() override;

	virtual void setEnrichValue_dis(double _EnrichValue_dis) override;
	virtual double getEnrichValue_dis() override;

	virtual void setEnrichValue_CD(double _EnrichValue_CD) override;
	virtual double getEnrichValue_CD() override;

	virtual void set_remain_Enrich_CD(double _remain_Enrich) override;
	virtual double get_remain_Enrich_CD() override;

	virtual void minus1remain_Enrich_CD() override;

	virtual bool isEnrichVessel(double, double) override;

private:
	double EnrichValue;
	double EnrichValue_dis;
	double EnrichValue_CD;
	double remain_Enrich_CD;
};
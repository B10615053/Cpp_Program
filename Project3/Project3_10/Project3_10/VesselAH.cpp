// Mercy
#include "VesselAH.h"



// Default constructor
VesselAH::VesselAH() :
	VesselObject(NAME, NONE, AH, PointF(), HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {
	/*darling*/
	EnrichValue = MEnrichValue;
	EnrichValue_CD = MEnrichValue_CD;
	EnrichValue_dis = MEnrichValue_dis;
	remain_Enrich_CD = 0;
}

// Copy constructor
VesselAH::VesselAH(VesselAH^& rSide) {
	mouseIn = rSide->mouseIn;

	name = rSide->name;
	team = rSide->team;
	vesselType = rSide->vesselType;
	coord = rSide->coord;
	coord4Draw = rSide->coord4Draw;
	gpVessel = rSide->gpVessel;

	maxHp = rSide->maxHp;
	remainHp = rSide->remainHp;
	maxVesselSpeed = rSide->maxVesselSpeed;
	maxAttackDistance = rSide->maxAttackDistance;
	attackCD = rSide->attackCD;
	maxDefenseDistance = rSide->maxDefenseDistance;
	defenseCD = rSide->defenseCD;
	damage = rSide->damage;
	shellSpeed = rSide->shellSpeed;

	remainAttackCD = rSide->remainAttackCD;
	remainDefenseCD = rSide->remainDefenseCD;

	nowSpeed = rSide->nowSpeed;
	nowAngle = rSide->nowAngle;

	/*darling*/
	this->EnrichValue = rSide->EnrichValue;
	this->EnrichValue_CD = rSide->EnrichValue_CD;
	this->EnrichValue_dis = rSide->EnrichValue_dis;
	this->remain_Enrich_CD = rSide->remain_Enrich_CD;

	canMove = rSide->canMove;
}

// Constructor
VesselAH::VesselAH(String^ _name, TeamSymbol _team, PointF _coord) :
	VesselObject(_name, _team, AH, _coord, HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {
	/*darling*/
	EnrichValue = MEnrichValue;
	EnrichValue_CD = MEnrichValue_CD;
	EnrichValue_dis = MEnrichValue_dis;
	remain_Enrich_CD = 0;
}

// Overload assignment operator
VesselAH^ VesselAH::operator=(VesselAH^ rSide) {
	mouseIn = rSide->mouseIn;

	name = rSide->name;
	team = rSide->team;
	vesselType = rSide->vesselType;
	coord = rSide->coord;
	coord4Draw = rSide->coord4Draw;
	gpVessel = rSide->gpVessel;

	maxHp = rSide->maxHp;
	remainHp = rSide->remainHp;
	maxVesselSpeed = rSide->maxVesselSpeed;
	maxAttackDistance = rSide->maxAttackDistance;
	attackCD = rSide->attackCD;
	maxDefenseDistance = rSide->maxDefenseDistance;
	defenseCD = rSide->defenseCD;
	damage = rSide->damage;
	shellSpeed = rSide->shellSpeed;

	remainAttackCD = rSide->remainAttackCD;
	remainDefenseCD = rSide->remainDefenseCD;

	nowSpeed = rSide->nowSpeed;
	nowAngle = rSide->nowAngle;

	this->EnrichValue = rSide->EnrichValue;
	this->EnrichValue_CD = rSide->EnrichValue_CD;
	this->EnrichValue_dis = rSide->EnrichValue_dis;
	this->remain_Enrich_CD = rSide->remain_Enrich_CD;

	canMove = rSide->canMove;

	return this;
}

// Icon of CV
bool VesselAH::render(Graphics^ g) {

	Brush^ bruVessel = gcnew SolidBrush((getTeam() == A) ? Color::Red : Color::Blue);
	Pen^ penVessel = gcnew Pen(Color::Black);

	/*darling*/
	array<PointF>^ point_Regular_cross = gcnew array<PointF>(12);
	point_Regular_cross[0].X = getCoord4Draw().X + halfw1long; point_Regular_cross[0].Y = getCoord4Draw().Y - halfw1long;
	point_Regular_cross[1].X = point_Regular_cross[0].X; point_Regular_cross[1].Y = point_Regular_cross[0].Y - l1ong;
	point_Regular_cross[2].X = getCoord4Draw().X - halfw1long; point_Regular_cross[2].Y = point_Regular_cross[1].Y;
	point_Regular_cross[3].X = point_Regular_cross[2].X; point_Regular_cross[3].Y = point_Regular_cross[0].Y;
	point_Regular_cross[4].X = point_Regular_cross[3].X - l1ong; point_Regular_cross[4].Y = point_Regular_cross[3].Y;
	point_Regular_cross[5].X = point_Regular_cross[4].X; point_Regular_cross[5].Y = getCoord4Draw().Y + halfw1long;
	point_Regular_cross[6].X = point_Regular_cross[3].X; point_Regular_cross[6].Y = point_Regular_cross[5].Y;
	point_Regular_cross[7].X = point_Regular_cross[6].X; point_Regular_cross[7].Y = point_Regular_cross[6].Y + l1ong;
	point_Regular_cross[8].X = point_Regular_cross[0].X; point_Regular_cross[8].Y = point_Regular_cross[7].Y;
	point_Regular_cross[9].X = point_Regular_cross[0].X; point_Regular_cross[9].Y = point_Regular_cross[6].Y;
	point_Regular_cross[10].X = point_Regular_cross[9].X + l1ong; point_Regular_cross[10].Y = point_Regular_cross[9].Y;
	point_Regular_cross[11].X = point_Regular_cross[10].X; point_Regular_cross[11].Y = point_Regular_cross[0].Y;

	gpVessel->Reset();
	gpVessel->AddPolygon(point_Regular_cross);

	g->FillPath(bruVessel, gpVessel);
	g->DrawPath(penVessel, gpVessel);

	//g->FillPolygon(bruVessel, point_Regular_cross);
	//g->DrawPolygon(penVessel, point_Regular_cross);

	VesselObject::render(g);

	return true;
}


/*darling*/
void VesselAH::setEnrichValue(double _EnrichValue) {

	this->EnrichValue = _EnrichValue;
}
double VesselAH::getEnrichValue() {
	return this->EnrichValue;
}

void VesselAH::setEnrichValue_CD(double _EnrichValueCD) {
	this->EnrichValue_CD = _EnrichValueCD;
	if (EnrichValue_CD< 0.0)
		EnrichValue_CD = 0.0;
}
double VesselAH::getEnrichValue_CD() {
	return this->EnrichValue_CD;
}

void VesselAH::setEnrichValue_dis(double _EnrichValue_dis) {
	this->EnrichValue_dis = _EnrichValue_dis;
	if (EnrichValue_dis< 0.0)
		EnrichValue_dis = 0.0;
}
double VesselAH::getEnrichValue_dis() {
	return this->EnrichValue_dis;
}

void VesselAH::set_remain_Enrich_CD(double _remain_Enrich) {
	this->remain_Enrich_CD = _remain_Enrich;
	if (remain_Enrich_CD< 0.0)
		remain_Enrich_CD = 0.0;
}
double VesselAH::get_remain_Enrich_CD() {
	return this->remain_Enrich_CD;
}

void VesselAH::minus1remain_Enrich_CD() {
	this->remain_Enrich_CD -= 1.0;
	if (remain_Enrich_CD< 0.0)
		remain_Enrich_CD = 0.0;
}

bool VesselAH::isEnrichVessel(double _x, double _y) {
	double fx = (getCoord().X - _x)*(getCoord().X - _x);
	double fy = (getCoord().Y - _y)*(getCoord().Y - _y);

	if (fx + fy <= MEnrichValue_dis * MEnrichValue_dis)
		return true;

	else
		return false;
}
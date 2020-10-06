// Battle Cruiser
#include "VesselCG.h"

// Default constructor
VesselCG::VesselCG() :
	VesselObject(NAME, NONE, CG, PointF(), HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {
}

// Copy constructor
VesselCG::VesselCG(VesselCG^& rSide) {
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
	maxDefenseDistance = rSide->maxDefenseDistance;
	attackCD = rSide->attackCD;
	launchCD = rSide->launchCD;
	defenseCD = rSide->defenseCD;
	damage = rSide->damage;
	shellSpeed = rSide->shellSpeed;

	torpedoDamage = rSide->torpedoDamage;
	torpedoSpeed = rSide->torpedoSpeed;

	remainAttackCD = rSide->remainAttackCD;
	remainLaunchCD = rSide->remainLaunchCD;
	remainDefenseCD = rSide->remainDefenseCD;

	nowSpeed = rSide->nowSpeed;
	nowAngle = rSide->nowAngle;

	canMove = rSide->canMove;
}

// Constructor
VesselCG::VesselCG(String^ _name, TeamSymbol _team, PointF _coord) :
	VesselObject(_name, _team, CG, _coord, HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {

	launchCD = LAUNCH_CD;
	remainLaunchCD = 0;

	torpedoDamage = TORPEDO_DAMAGE;
	torpedoSpeed = TORPEDO_SPEED;
}

// Overload assignment operator
VesselCG^ VesselCG::operator=(VesselCG^ rSide) {
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
	maxDefenseDistance = rSide->maxDefenseDistance;
	attackCD = rSide->attackCD;
	launchCD = rSide->launchCD;
	defenseCD = rSide->defenseCD;
	damage = rSide->damage;
	shellSpeed = rSide->shellSpeed;

	torpedoDamage = rSide->torpedoDamage;
	torpedoSpeed = rSide->torpedoSpeed;

	remainAttackCD = rSide->remainAttackCD;
	remainLaunchCD = rSide->remainLaunchCD;
	remainDefenseCD = rSide->remainDefenseCD;

	nowSpeed = rSide->nowSpeed;
	nowAngle = rSide->nowAngle;

	canMove = rSide->canMove;

	return this;
}

// Icon of CG
bool VesselCG::render(Graphics^ g) {

	Brush^ bruVessel = gcnew SolidBrush((getTeam() == A) ? Color::Red : Color::Blue);
	Pen^ penVessel = gcnew Pen(Color::Black);

	// Create array of points that define lines to draw.
	array<Point>^ points = gcnew array<Point>(4);
	points[0] = Point(getCoord4Draw().X, getCoord4Draw().Y + (VESSEL_ICON_LENGTH / 2.0) * 1.732);
	points[1] = Point(getCoord4Draw().X + (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y);
	points[2] = Point(getCoord4Draw().X, getCoord4Draw().Y - (VESSEL_ICON_LENGTH / 2.0) * 1.732);
	points[3] = Point(getCoord4Draw().X - (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y);

	gpVessel->Reset();
	gpVessel->AddPolygon(points);

	g->FillPath(bruVessel, gpVessel);
	g->DrawPath(penVessel, gpVessel);

	//g->FillPolygon(bruVessel, points);
	//g->DrawPolygon(penVessel, points);

	VesselObject::render(g);
	return true;
}
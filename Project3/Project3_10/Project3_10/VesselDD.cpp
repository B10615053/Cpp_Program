// Destroyer
#include "VesselDD.h"

// Default constructor
VesselDD::VesselDD() :
	VesselObject(NAME, NONE, DD, PointF(), HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {
}

// Copy constructor
VesselDD::VesselDD(VesselDD^& rSide) {
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
VesselDD::VesselDD(String^ _name, TeamSymbol _team, PointF _coord) :
	VesselObject(_name, _team, DD, _coord, HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {

	launchCD = LAUNCH_CD;
	remainLaunchCD = 0;

	torpedoDamage = TORPEDO_DAMAGE;
	torpedoSpeed = TORPEDO_SPEED;
}

// Overload assignment operator
VesselDD^ VesselDD::operator=(VesselDD^ rSide) {
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

// Icon of DD
bool VesselDD::render(Graphics^ g) {

	Brush^ bruVessel = gcnew SolidBrush((getTeam() == A) ? Color::Red : Color::Blue);
	Pen^ penVessel = gcnew Pen(Color::Black);

	// Create array of points that define lines to draw.
	array<Point>^ points = gcnew array<Point>(3);
	if (getTeam() == A) {
		points[0] = Point(getCoord4Draw().X, getCoord4Draw().Y + (VESSEL_ICON_LENGTH / 2.0) * 2);
		points[1] = Point(getCoord4Draw().X + (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y - (VESSEL_ICON_LENGTH / 2.0));
		points[2] = Point(getCoord4Draw().X - (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y - (VESSEL_ICON_LENGTH / 2.0));
	}
	else {
		points[0] = Point(getCoord4Draw().X, getCoord4Draw().Y - (VESSEL_ICON_LENGTH / 2.0) * 2);
		points[1] = Point(getCoord4Draw().X - (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y + (VESSEL_ICON_LENGTH / 2.0));
		points[2] = Point(getCoord4Draw().X + (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y + (VESSEL_ICON_LENGTH / 2.0));
	}

	gpVessel->Reset();
	gpVessel->AddPolygon(points);

	g->FillPath(bruVessel, gpVessel);
	g->DrawPath(penVessel, gpVessel);

	//g->FillPolygon(bruVessel, points);
	//g->DrawPolygon(penVessel, points);

	VesselObject::render(g);

	return true;
}
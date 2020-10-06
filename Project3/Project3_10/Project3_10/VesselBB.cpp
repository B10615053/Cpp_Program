// Battle Ship
#include "VesselBB.h"




// Default constructor
VesselBB::VesselBB() :
	VesselObject(NAME, NONE, UNKNOWN_VESSEL_TYPE, PointF(), HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {
}

// Constructor
VesselBB::VesselBB(String^ _name, TeamSymbol _team, PointF _coord) :
	VesselObject(_name, _team, BB, _coord, HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {
}

// Copy constructor
VesselBB::VesselBB(VesselBB^& rSide) {
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

	canMove = rSide->canMove;
}

// Overload assignment operator
VesselBB^ VesselBB::operator=(VesselBB^ rSide) {
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

	canMove = rSide->canMove;

	return this;
}

// Icon of BB
bool VesselBB::render(Graphics^ g) {

	Brush^ bruVessel = gcnew SolidBrush((getTeam() == A) ? Color::Red : Color::Blue);
	Pen^ penVessel = gcnew Pen(Color::Black);

	gpVessel->Reset();
	gpVessel->AddEllipse(getCoord4Draw().X - (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y - (VESSEL_ICON_LENGTH / 2.0), VESSEL_ICON_LENGTH, VESSEL_ICON_LENGTH);

	g->FillPath(bruVessel, gpVessel);
	g->DrawPath(penVessel, gpVessel);

	//g->FillEllipse(bruVessel, getCoord4Draw().X - (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y - (VESSEL_ICON_LENGTH / 2.0), VESSEL_ICON_LENGTH, VESSEL_ICON_LENGTH);
	//g->DrawEllipse(penVessel, getCoord4Draw().X - (VESSEL_ICON_LENGTH / 2.0), getCoord4Draw().Y - (VESSEL_ICON_LENGTH / 2.0), VESSEL_ICON_LENGTH, VESSEL_ICON_LENGTH);

	VesselObject::render(g);

	return true;
}
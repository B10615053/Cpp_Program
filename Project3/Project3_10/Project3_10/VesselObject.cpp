#include "VesselObject.h"




#pragma region constructors
VesselObject::VesselObject() {
	name = "Unknown";
	team = NONE;
	vesselType = UNKNOWN_VESSEL_TYPE;
	coord = PointF(0.0, 0.0);
	coord4Draw = coord;
	gpVessel = gcnew GraphicsPath();

	maxHp = 0;
	remainHp = 0;
	maxVesselSpeed = 0;
	maxAttackDistance = 0;
	maxDefenseDistance = 0;
	attackCD = 0;
	launchCD = 0;
	defenseCD = 0;
	damage = 0;
	shellSpeed = 0;

	torpedoDamage = 0;
	torpedoSpeed = 0;

	remainAttackCD = 0;
	remainLaunchCD = 0;
	remainDefenseCD = 0;

	nowSpeed = 0;
	nowAngle = 0;

	initializeMove();
}

VesselObject::VesselObject(const VesselObject^& rSide) {
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

	mouseIn = rSide->mouseIn;
}

VesselObject::VesselObject(String^ newName, TeamSymbol whichTeam, VesselType newVesselType, PointF newCoord, double newHp, double newMaxVesselSpeed, double newMaxAttackDistance, double newAttackCD, double newMaxDefenseDistance, double newDefenseCD, double newDamage, double newShellSpeed) {
	name = newName;
	team = whichTeam;
	vesselType = newVesselType;
	coord = newCoord;
	coord4Draw = COORD_TO_DRAWING_COORD(coord.X, coord.Y);
	gpVessel = gcnew GraphicsPath();

	maxHp = newHp;
	remainHp = newHp;
	maxVesselSpeed = newMaxVesselSpeed;;
	maxAttackDistance = newMaxAttackDistance;
	attackCD = newAttackCD;
	maxDefenseDistance = newMaxDefenseDistance;
	defenseCD = newDefenseCD;
	damage = newDamage;
	shellSpeed = newShellSpeed;

	remainAttackCD = 0;
	remainDefenseCD = 0;

	nowSpeed = 0;
	nowAngle = 0;

	initializeMove();
}
#pragma endregion

#pragma region deconstructor
VesselObject::~VesselObject() {
	//delete gpVessel;
	Debug::WriteLine("Deconstructor of VesselObject has been called!");
}
#pragma endregion

#pragma region getters and setters
String^ VesselObject::getName() {
	return name;
}
void VesselObject::setName(String^ newName) {
	name = newName;
}

TeamSymbol VesselObject::getTeam() {
	return team;
}
void VesselObject::setTeam(TeamSymbol newTeam) {
	team = newTeam;
}

VesselType VesselObject::getVesselType() {
	return vesselType;
}
void VesselObject::setVesselType(VesselType newVesselType) {
	vesselType = newVesselType;
}

PointF VesselObject::getCoord() {
	return coord;
}
void VesselObject::setCoord(PointF newCoord) {
	coord = newCoord;
}

PointF VesselObject::getCoord4Draw() {
	return coord4Draw;
}
void VesselObject::setCoord4Draw(PointF newCoord4Draw) {
	coord4Draw = newCoord4Draw;
}

GraphicsPath^ VesselObject::getGp() {
	return gpVessel;
}

double VesselObject::getMaxHp() {
	return maxHp;
}
void VesselObject::setMaxHp(double newMaxHp) {
	maxHp = newMaxHp;
}

double VesselObject::getRemainHp() {
	return remainHp;
}
void VesselObject::setRemainHp(double newHp) {
	remainHp = newHp;

	if (remainHp < 0.0)
		remainHp = 0.0;
	if (remainHp > maxHp)
		remainHp = maxHp;
}

double VesselObject::getMaxVesselSpeed() {
	return maxVesselSpeed;
}
void VesselObject::setMaxVesselSpeed(double newMaxVesselSpeed) {
	maxVesselSpeed = newMaxVesselSpeed;
}

double VesselObject::getMaxAttackDistance() {
	return maxAttackDistance;
}
void VesselObject::setMaxAttackDistance(double newMaxAttackDistance) {
	maxAttackDistance = newMaxAttackDistance;
}

double VesselObject::getAttackCD() {
	return attackCD;
}
void VesselObject::setAttackCD(double newAttackCD) {
	attackCD = newAttackCD;
}

double VesselObject::getLaunchCD() {
	return launchCD;
}
void VesselObject::setLaunchCD(double newLaunchCD) {
	launchCD = newLaunchCD;
}

double VesselObject::getMaxDefenseDistance() {
	return maxDefenseDistance;
}
void VesselObject::setMaxDefenseDistance(double newMaxDefenseDistance) {
	maxDefenseDistance = newMaxDefenseDistance;
}

double VesselObject::getDefenseCD() {
	return defenseCD;
}
void VesselObject::setDefenseCD(double newDefenseCD) {
	defenseCD = newDefenseCD;
}

double VesselObject::getDamage() {
	return damage;
}
void VesselObject::setDamage(double newDamage) {
	damage = newDamage;
}

double VesselObject::getShellSpeed() {
	return shellSpeed;
}
void VesselObject::setShellSpeed(double newShellSpeed) {
	shellSpeed = newShellSpeed;
}

double VesselObject::getTorpedoDamage() {
	return torpedoDamage;
}
void VesselObject::setTorpedoDamage(double newTorpedoDamage) {
	torpedoDamage = newTorpedoDamage;
}

double VesselObject::getTorpedoSpeed() {
	return torpedoSpeed;
}

void VesselObject::setTorpedoSpeed(double newTorpedoSpeed) {
	torpedoSpeed = newTorpedoSpeed;
}

double VesselObject::getRemainAttackCD() {
	return remainAttackCD;
}
void VesselObject::setRemainAttackCD(double newRemainAttackCD) {
	remainAttackCD = newRemainAttackCD;

	if (remainAttackCD < 0.0)
		remainAttackCD = 0.0;
}
void VesselObject::minus1RemainAttackCD() {
	remainAttackCD--;

	if (remainAttackCD < 0.0)
		remainAttackCD = 0.0;
}

double VesselObject::getRemainLaunchCD() {
	return remainLaunchCD;
}

void VesselObject::setRemainLaunchCD(double newRemainLaunchCD) {
	remainLaunchCD = newRemainLaunchCD;

	if (remainLaunchCD < 0.0)
		remainLaunchCD = 0.0;
}

void VesselObject::minus1RemainLaunchCD() {
	remainLaunchCD--;

	if (remainLaunchCD < 0.0)
		remainLaunchCD = 0.0;
}

double VesselObject::getRemainDefenseCD() {
	return remainDefenseCD;
}
void VesselObject::setRemainDefenseCD(double newRemainDefenseCD) {
	remainDefenseCD = newRemainDefenseCD;

	if (remainDefenseCD < 0.0)
		remainDefenseCD = 0.0;
}
void VesselObject::minus1RemainDefenseCD() {
	remainDefenseCD--;

	if (remainDefenseCD < 0.0)
		remainDefenseCD = 0.0;
}

double VesselObject::getNowSpeed() {
	return nowSpeed;
}
void VesselObject::setNowSpeed(double newNowSpeed) {
	nowSpeed = newNowSpeed;
}

double VesselObject::getNowAngle() {
	return nowAngle;
}
void VesselObject::setNowAngle(double newNowAngle) {
	nowAngle = newNowAngle;
}

void VesselObject::setCanMove(bool newCanMove) {
	canMove = newCanMove;
}
bool VesselObject::getCanMove() {
	return canMove;
}
void VesselObject::initializeMove() {
	canMove = true;
	mouseIn = false;
}

void VesselObject::SetLaserAngle(double _angle) {
	return;
}
double VesselObject::GetLaserAngle() {
	return 0.0;
}

void VesselObject::setIsLaserShooting(bool newLaserShooting) {
	return;
}
bool VesselObject::getIsLaserShooting() {
	return false;
}

void VesselObject::setLaserCD(double newLaserCD) {
	return;
}
double VesselObject::getLaserCD() {
	return 0.0;
}

void VesselObject::setRemainLaserCD(double newRemainLaserCD) {
	return;
}
void VesselObject::minus1RemainLaserCD() {
	return;
}
double VesselObject::getRemainLaserCD() {
	return 0.0;
}

void VesselObject::setEnrichValue(double _EnrichValue) {
	return;
}
double VesselObject::getEnrichValue() {
	return 0;
}

void VesselObject::setEnrichValue_CD(double _EnrichValueCD) {
	return;
}
double VesselObject::getEnrichValue_CD() {
	return 0;
}

void VesselObject::setEnrichValue_dis(double _EnrichValue_dis) {
	return;
}
double VesselObject::getEnrichValue_dis() {
	return 0;
}

void VesselObject::set_remain_Enrich_CD(double _remain_Enrich) {
	return;
}
double VesselObject::get_remain_Enrich_CD() {
	return 0;
}

void VesselObject::minus1remain_Enrich_CD() {
	return;
}

void VesselObject::setIsLaserHitSomething(bool newIsLaserHitSomething) {
	return;
}
bool VesselObject::getIsLaserHitSomething() {
	return false;
}

void VesselObject::setLaserLog(String^ newLaserLog) {
	return;
}
void VesselObject::strcatLaserLog(String^ newLaserLog) {
	return;
}
String^ VesselObject::getLaserLog() {
	return "";
}
#pragma endregion

bool VesselObject::BoundaryJudgment(double _X, double _Y) {

	if (_X < 0.0 || _Y < 0.0 || _X > 20.0 || _Y > 20.0)
		return false;
	else
		return true;
}

void VesselObject::VesselMove() {
	//Debug::WriteLine("[" + name + "] speed: " + nowSpeed);

	if (nowSpeed == 0.0 || canMove == false)
		return;

	if (nowSpeed < 0) {
		nowSpeed = nowSpeed * (-1);
		nowAngle += 180;
	}

	double dx;
	double dy;

	if (BoundaryJudgment(getCoord().X, getCoord().Y)) {
		dx = Math::Cos(ANGLE_TO_RADIUS(nowAngle));
		dy = -(Math::Sin(ANGLE_TO_RADIUS(nowAngle)));
		double dis = Math::Sqrt((dx * dx) + (dy * dy));

		setCoord(PointF(nowSpeed * dx + getCoord().X, nowSpeed * dy + getCoord().Y));
		setCoord4Draw(COORD_TO_DRAWING_COORD(getCoord().X, getCoord().Y));
	}
	else {
		nowSpeed = 0.0;
		nowAngle = 0.0;

		if (coord.X < 0.0)
			coord.X = 0.01;
		if (coord.Y < 0.0)
			coord.Y = 0.01;

		if (coord.X > 20.0)
			coord.X = 20.0;
		if (coord.Y > 20.0)
			coord.Y = 20.0;

		setCoord4Draw(COORD_TO_DRAWING_COORD(getCoord().X, getCoord().Y));
	}
}

void VesselObject::DaoTuiLu() {
	nowSpeed = -nowSpeed;
	VesselMove();
	nowSpeed = -nowSpeed;
}

bool VesselObject::render(Graphics^ g) {

	// draw name
	g->DrawString(name, gcnew Font("Consolas", 8), gcnew SolidBrush(team == A ? Color::Red : Color::Blue), PointF(coord4Draw.X + BIAS_X_4_DRAW_NAME, coord4Draw.Y - BIAS_Y_4_DRAW_NAME));

	#pragma region draw HP strip
	const double BIAS_X_4_HPSTRIP = BLOCK_LENGTH - 3.0;
	const double BIAS_Y_4_HPSTRIP = 18.5;
	double stripBaseLen = BIAS_X_4_HPSTRIP + BIAS_X_4_HPSTRIP;
	double stripValueLen = stripBaseLen * (remainHp / maxHp);

	Pen^ penHpStrip_base = gcnew Pen(Color::Black, 5.0);
	Pen^ penHpStrip_value = gcnew Pen((team == A ? Color::Red : Color::Blue), 5.0);

	g->DrawLine(penHpStrip_base, PointF(coord4Draw.X - BIAS_X_4_HPSTRIP, coord4Draw.Y - BIAS_Y_4_HPSTRIP), PointF(coord4Draw.X + BIAS_X_4_HPSTRIP, coord4Draw.Y - BIAS_Y_4_HPSTRIP));
	g->DrawLine(penHpStrip_value, PointF(coord4Draw.X - BIAS_X_4_HPSTRIP, coord4Draw.Y - BIAS_Y_4_HPSTRIP), PointF(coord4Draw.X - BIAS_X_4_HPSTRIP + stripValueLen, coord4Draw.Y - BIAS_Y_4_HPSTRIP));
	#pragma endregion

	if (mouseIn) {
		Pen^ penAttackRange = gcnew Pen(Color::CornflowerBlue, 2.0);
		Pen^ penDefenseRange = gcnew Pen(Color::Brown, 2.0);
		Brush^ bruAttackRange = gcnew SolidBrush(Color::FromArgb(50, 20, 30, 40));
		Brush^ bruDefenseRange = gcnew SolidBrush(Color::FromArgb(50, 240, 10, 40));

		double atkDis = COORD_TO_DRAWING_COORD(maxAttackDistance, 0.0).X;
		double defDis = COORD_TO_DRAWING_COORD(maxDefenseDistance, 0.0).X;

		g->FillEllipse(bruAttackRange, (float)(coord4Draw.X - atkDis), (float)(coord4Draw.Y - atkDis), (float)(atkDis * 2.0), (float)(atkDis * 2.0));
		g->FillEllipse(bruDefenseRange, (float)(coord4Draw.X - defDis), (float)(coord4Draw.Y - defDis), (float)(defDis * 2.0), (float)(defDis * 2.0));
		g->DrawEllipse(penAttackRange, (float)(coord4Draw.X - atkDis), (float)(coord4Draw.Y - atkDis), (float)(atkDis * 2.0), (float)(atkDis * 2.0));
		g->DrawEllipse(penDefenseRange, (float)(coord4Draw.X - defDis), (float)(coord4Draw.Y - defDis), (float)(defDis * 2.0), (float)(defDis * 2.0));
	}

	return true;
}

// LV only
bool VesselObject::DrawLaser(Graphics^ g) {
	return false;
}

// AH only
bool VesselObject::isEnrichVessel(double _x, double _y) {
	return false;
}
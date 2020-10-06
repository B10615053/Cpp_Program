// Laser Vessel
#include "VesselLV.h"



// Default constructor
VesselLV::VesselLV() :
	VesselObject(NAME, NONE, LV, PointF(), HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {
	laserCD = LASER_CD;
	isLaserHitSomething = false;
	laserLog = "";
}

// Copy constructor
VesselLV::VesselLV(VesselLV^& rSide) {
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

	laserCD = rSide->laserCD;
	isLaserHitSomething = rSide->isLaserHitSomething;
	laserLog = rSide->laserLog;

	canMove = rSide->canMove;
}

// Constructor
VesselLV::VesselLV(String^ _name, TeamSymbol _team, PointF _coord) :
	VesselObject(_name, _team, LV, _coord, HP, MAX_VESSEL_SPEED, MAX_ATTACK_DIS, ATTACK_CD, MAX_DEFENSE_DIS, DEFENSE_CD, DAMAGE, SHELL_SPEED) {
	laserCD = LASER_CD;
	isLaserHitSomething = false;
	laserLog = "";
}

// Overload assignment operator
VesselLV^ VesselLV::operator=(VesselLV^ rSide) {
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

	laserCD = rSide->laserCD;
	isLaserHitSomething = rSide->isLaserHitSomething;
	laserLog = rSide->laserLog;

	canMove = rSide->canMove;

	return this;
}

// Icon of LV
bool VesselLV::render(Graphics^ g) {

	Brush^ bruVessel = gcnew SolidBrush((getTeam() == A) ? Color::Red : Color::Blue);
	Pen^ penVessel = gcnew Pen(Color::Black);

	array<PointF>^ point_Regular_pentagon = gcnew array<PointF>(5);

	point_Regular_pentagon[0].X = getCoord4Draw().X; point_Regular_pentagon[0].Y = getCoord4Draw().Y - 10;
	point_Regular_pentagon[3].X = getCoord4Draw().X - 10 * Math::Cos(ANGLE_TO_RADIUS(54)); point_Regular_pentagon[3].Y = getCoord4Draw().Y + 10;
	point_Regular_pentagon[2].X = getCoord4Draw().X + 10 * Math::Cos(ANGLE_TO_RADIUS(54)); point_Regular_pentagon[2].Y = getCoord4Draw().Y + 10;
	double side = Math::Abs(10 * Math::Cos(ANGLE_TO_RADIUS(54)) * 2);
	point_Regular_pentagon[1].X = point_Regular_pentagon[2].X + (Math::Cos(ANGLE_TO_RADIUS(72))*side);
	point_Regular_pentagon[4].X = point_Regular_pentagon[3].X - (Math::Cos(ANGLE_TO_RADIUS(72))*side);

	point_Regular_pentagon[1].Y = point_Regular_pentagon[2].Y - (Math::Sin(ANGLE_TO_RADIUS(72))*side);
	point_Regular_pentagon[4].Y = point_Regular_pentagon[2].Y - (Math::Sin(ANGLE_TO_RADIUS(72))*side);

	gpVessel->Reset();
	gpVessel->AddPolygon(point_Regular_pentagon);

	g->FillPath(bruVessel, gpVessel);
	g->DrawPath(penVessel, gpVessel);

	//g->FillPolygon(bruVessel, point_Regular_pentagon);
	//g->DrawPolygon(penVessel, point_Regular_pentagon);


	VesselObject::render(g);
	return true;
}

#pragma region setters and getters
void VesselLV::SetLaserAngle(double _angle) {
	LaserAngle = _angle;
}
double VesselLV::GetLaserAngle() {
	//Debug::WriteLine("get laser angle called: angle " + LaserAngle);
	return LaserAngle;
}

void VesselLV::setIsLaserShooting(bool newLaserShooting) {
	isLaserShooting = newLaserShooting;
}
bool VesselLV::getIsLaserShooting() {
	return isLaserShooting;
}

void VesselLV::setLaserCD(double newLaserCD) {
	laserCD = newLaserCD;
}
double VesselLV::getLaserCD() {
	return laserCD;
}

void VesselLV::setRemainLaserCD(double newRemainLaserCD) {
	remainLaserCD = newRemainLaserCD;

	if (remainLaserCD < 0.0)
		remainLaserCD = 0.0;
}
void VesselLV::minus1RemainLaserCD() {
	remainLaserCD -= 1.0;

	if (remainLaserCD < 0.0)
		remainLaserCD = 0.0;
}
double VesselLV::getRemainLaserCD() {
	return remainLaserCD;
}

void VesselLV::setIsLaserHitSomething(bool newIsLaserHitSomething) {
	isLaserHitSomething = newIsLaserHitSomething;
}
bool VesselLV::getIsLaserHitSomething() {
	return isLaserHitSomething;
}

void VesselLV::setLaserLog(String^ newLaserLog) {
	laserLog = newLaserLog;
}
void VesselLV::strcatLaserLog(String^ newLaserLog) {
	laserLog += newLaserLog;
}
String^ VesselLV::getLaserLog() {
	return laserLog;
}
#pragma endregion

bool VesselLV::DrawLaser(Graphics ^ g) {
	Pen^ penVessel = gcnew Pen(Color::Green, 2);
	double X_Long = 0;
	double Y_long = 0;
	double slope_long = 0;
	if (LaserAngle > 360) LaserAngle -= 360;
	if (LaserAngle < 0)LaserAngle += 360;







	///////////
	if (LaserAngle >0 && LaserAngle <90 || LaserAngle < 360 && LaserAngle >270) {
		if (LaserAngle >= 0 && LaserAngle <= 45 || LaserAngle >= 315 && LaserAngle < 360) {

			X_Long = BOARD_LENGTH - getCoord4Draw().X + BIAS_X;
			slope_long = X_Long / Math::Cos(ANGLE_TO_RADIUS(LaserAngle));
			Y_long = Math::Abs(slope_long) * Math::Sin(ANGLE_TO_RADIUS(LaserAngle))*(1);


			/*if ((getCoord4Draw().X + X_Long) >( BOARD_LENGTH+BLOCK_LENGTH) || (getCoord4Draw().X + X_Long) < BIAS_X && (getCoord4Draw().Y - Y_long) > (BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().Y - Y_long < BIAS_Y)) {}
			else { g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X + X_Long, getCoord4Draw().Y - Y_long); }*/
			double fx = (getCoord4Draw().X + X_Long);
			double fy = getCoord4Draw().Y - Y_long;
			/*	if (fx >(BOARD_LENGTH + BLOCK_LENGTH)) fx = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fx < BIAS_X) fx = BIAS_X;
			if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) fy = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fy < BIAS_Y) fy = BIAS_Y;*/
			double slope = (getCoord4Draw().Y - fy) / (getCoord4Draw().X - fx);
			if (fx > (BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BOARD_LENGTH + BLOCK_LENGTH;
				fy = (c + slope * fx);
			}
			else	if (fx < BIAS_X) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BIAS_X;
				fy = (c + slope * fx);
			}
			else	if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fy = BOARD_LENGTH + BLOCK_LENGTH;
				fx = (fy + (-1)*c) / slope;
			}
			else if (fy < BIAS_Y) {
				double c = (-1)*slope*getCoord4Draw().X + getCoord4Draw().Y;
				fy = BIAS_Y;
				fx = (fy + (-1)*c) / slope;

				//fy = BIAS_X;

			}
			g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, fx, fy);



		}
		else if (LaserAngle >45 && LaserAngle <= 90) {

			Y_long = getCoord4Draw().Y - BIAS_Y;
			slope_long = Y_long / Math::Sin(ANGLE_TO_RADIUS(LaserAngle));
			X_Long = Math::Abs(slope_long)*Math::Cos(ANGLE_TO_RADIUS(LaserAngle));
			/*		if ((getCoord4Draw().X + X_Long) >(BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().X + X_Long) < BIAS_X && (getCoord4Draw().Y - Y_long) > (BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().Y - Y_long < BIAS_Y)) {}
			else { g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X + X_Long, getCoord4Draw().Y - Y_long); }
			*/
			double fx = (getCoord4Draw().X + X_Long);
			double fy = getCoord4Draw().Y - Y_long;
			/*if (fx > (BOARD_LENGTH + BLOCK_LENGTH)) fx = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fx < BIAS_X) fx = BIAS_X;
			if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) fy = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fy < BIAS_Y) fy = BIAS_Y;*/
			double slope = (getCoord4Draw().Y - fy) / (getCoord4Draw().X - fx);
			if (fx > BOARD_LENGTH + BLOCK_LENGTH) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BOARD_LENGTH + BLOCK_LENGTH;
				fy = (c + slope * fx);
			}
			else	if (fx < BIAS_X) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BIAS_X;
				fy = (c + slope * fx);
			}
			else	if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fy = BOARD_LENGTH + BLOCK_LENGTH;
				fx = (fy + (-1)*c) / slope;
			}
			else	if (fy < BIAS_Y) {
				double c = (-1)*slope*getCoord4Draw().X + getCoord4Draw().Y;
				fy = BIAS_Y;
				fx = (fy + (-1)*c) / slope;

				//fy = BIAS_X;

			}
			g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, fx, fy);
		}
		else {
			Y_long = BOARD_LENGTH - getCoord4Draw().Y + BIAS_Y;
			slope_long = Y_long / Math::Sin(ANGLE_TO_RADIUS(LaserAngle));
			X_Long = Math::Abs(slope_long)*Math::Cos(ANGLE_TO_RADIUS(LaserAngle));
			/*	if ((getCoord4Draw().X + X_Long) >(BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().X + X_Long) < BIAS_X && (getCoord4Draw().Y + Y_long) > (BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().Y + Y_long < BIAS_Y)) {}
			else { g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X + X_Long, getCoord4Draw().Y + Y_long); }
			*/
			double fx = (getCoord4Draw().X + X_Long);
			double fy = getCoord4Draw().Y + Y_long;
			/*if (fx > (BOARD_LENGTH + BLOCK_LENGTH)) fx = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fx < BIAS_X) fx = BIAS_X;
			if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) fy = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fy < BIAS_Y) fy = BIAS_Y;*/
			double slope = (getCoord4Draw().Y - fy) / (getCoord4Draw().X - fx);
			if (fx > (BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BOARD_LENGTH + BLOCK_LENGTH;
				fy = (c + slope * fx);
			}
			else	if (fx < BIAS_X) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BIAS_X;
				fy = (c + slope * fx);
			}
			else	if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fy = BOARD_LENGTH + BLOCK_LENGTH;
				fx = (fy + (-1)*c) / slope;
			}
			else	if (fy < BIAS_Y) {
				double c = (-1)*slope*getCoord4Draw().X + getCoord4Draw().Y;
				fy = BIAS_Y;
				fx = (fy + (-1)*c) / slope;

				//fy = BIAS_X;

			}
			g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, fx, fy);
		}
	}
	else if (LaserAngle == 180) {
		X_Long = getCoord4Draw().X - BIAS_X;
		/*if ((getCoord4Draw().X-X_Long) > BOARD_LENGTH || (getCoord4Draw().X-X_Long) < BIAS_X && (getCoord4Draw().Y - Y_long) > BOARD_LENGTH || (getCoord4Draw().Y - Y_long < BIAS_Y)) {}
		else { g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X-X_Long, getCoord4Draw().Y - Y_long); }*/
		g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, (double)(BIAS_X), getCoord4Draw().Y);
	}
	else if (LaserAngle == 0) {
		X_Long = BOARD_LENGTH - getCoord4Draw().X;
		/*	if ((getCoord4Draw().X + X_Long) > BOARD_LENGTH || (getCoord4Draw().X + X_Long) < BIAS_X && (getCoord4Draw().Y - Y_long) > BOARD_LENGTH || (getCoord4Draw().Y - Y_long < BIAS_Y)) {}
		else { g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X +X_Long, getCoord4Draw().Y - Y_long); }*/
		g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, (double)(BOARD_LENGTH + BLOCK_LENGTH), getCoord4Draw().Y);
	}
	else if (LaserAngle == 90) {
		Y_long = getCoord4Draw().Y - BIAS_Y;
		/*if ((getCoord4Draw().X ) > BOARD_LENGTH || (getCoord4Draw().X) < BIAS_X && (getCoord4Draw().Y - Y_long) > BOARD_LENGTH || (getCoord4Draw().Y - Y_long < BIAS_Y)) {}
		else { g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X, getCoord4Draw().Y - Y_long); }*/
		g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X, (double)(BIAS_Y));
	}
	else if (LaserAngle == 270) {
		Y_long = BOARD_LENGTH - getCoord4Draw().Y + BLOCK_LENGTH;
		g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X, (double)(BOARD_LENGTH + BLOCK_LENGTH));
	}
	else {
		if (LaserAngle >= 135 && LaserAngle <= 225) {

			X_Long = getCoord4Draw().X - BIAS_X;
			slope_long = X_Long / Math::Cos(ANGLE_TO_RADIUS(LaserAngle));
			Y_long = Math::Abs(slope_long) * Math::Sin(ANGLE_TO_RADIUS(LaserAngle));
			//	if ((getCoord4Draw().X - X_Long) >(BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().X - X_Long) < BIAS_X && (getCoord4Draw().Y - Y_long) >(BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().Y - Y_long < BIAS_Y))
			//{}
			//else {>
			double fx = (getCoord4Draw().X - X_Long);
			double fy = getCoord4Draw().Y - Y_long;
			double slope = (getCoord4Draw().Y - fy) / (getCoord4Draw().X - fx);
			if (fx > (BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BOARD_LENGTH + BLOCK_LENGTH;
				fy = (c + slope * fx);
			}
			else	if (fx < BIAS_X) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BIAS_X;
				fy = (c + slope * fx);
			}
			else	if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fy = BOARD_LENGTH + BLOCK_LENGTH;
				fx = (fy + (-1)*c) / slope;
			}
			else if (fy < BIAS_Y) {
				double c = (-1)*slope*getCoord4Draw().X + getCoord4Draw().Y;
				fy = BIAS_Y;
				fx = (fy + (-1)*c) / slope;

				//fy = BIAS_X;

			}
			g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, fx, fy);
		}


		//}
		else if (LaserAngle >90 && LaserAngle <135) {
			Y_long = getCoord4Draw().Y - BIAS_Y;
			slope_long = Y_long / Math::Sin(ANGLE_TO_RADIUS(LaserAngle));
			X_Long = Math::Abs(slope_long)*Math::Cos(ANGLE_TO_RADIUS(LaserAngle));
			/*	if ((getCoord4Draw().X + X_Long) >(BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().X + X_Long) < BIAS_X && (getCoord4Draw().Y - Y_long) >(BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().Y - Y_long < BIAS_Y)) {}
			else { g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X + X_Long, getCoord4Draw().Y - Y_long); }
			*/
			double fx = (getCoord4Draw().X + X_Long);
			double fy = getCoord4Draw().Y - Y_long;
			/*	if (fx >(BOARD_LENGTH + BLOCK_LENGTH)) fx = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fx < BIAS_X) fx = BIAS_X;
			if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) fy = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fy < BIAS_Y) fy = BIAS_Y;*/
			double slope = (getCoord4Draw().Y - fy) / (getCoord4Draw().X - fx);
			if (fx > (BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BOARD_LENGTH + BLOCK_LENGTH;
				fy = (c + slope * fx);
			}

			else if (fx < BIAS_X) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BIAS_X;
				fy = (c + slope * fx);
			}
			else	if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fy = BOARD_LENGTH + BLOCK_LENGTH;
				fx = (fy + (-1)*c) / slope;
			}
			else	if (fy < BIAS_Y) {
				double c = (-1)*slope*getCoord4Draw().X + getCoord4Draw().Y;
				fy = BIAS_Y;
				fx = (fy + (-1)*c) / slope;

				//fy = BIAS_X;

			}
			g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, fx, fy);
		}
		else {
			Y_long = BOARD_LENGTH - getCoord4Draw().Y + BIAS_Y;
			slope_long = Y_long / Math::Sin(ANGLE_TO_RADIUS(LaserAngle));
			X_Long = Math::Abs(slope_long)*Math::Cos(ANGLE_TO_RADIUS(LaserAngle));
			/*if ((getCoord4Draw().X + X_Long) >(BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().X + X_Long) < BIAS_X && (getCoord4Draw().Y + Y_long) > (BOARD_LENGTH + BLOCK_LENGTH) || (getCoord4Draw().Y + Y_long < BIAS_Y)) {}
			else { g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, getCoord4Draw().X + X_Long, getCoord4Draw().Y + Y_long); }

			*/
			double fx = (getCoord4Draw().X + X_Long);
			double fy = getCoord4Draw().Y + Y_long;
			/*if (fx > (BOARD_LENGTH + BLOCK_LENGTH)) fx = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fx < BIAS_X) fx = BIAS_X;
			if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) fy = (BOARD_LENGTH + BLOCK_LENGTH);
			if (fy < BIAS_Y) fy = BIAS_Y;*/
			double slope = (getCoord4Draw().Y - fy) / (getCoord4Draw().X - fx);
			if (fx > (BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BOARD_LENGTH + BLOCK_LENGTH;
				fy = (c + slope * fx);
			}
			else	if (fx < BIAS_X) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fx = BIAS_X;
				fy = (c + slope * fx);
			}
			else if (fy >(BOARD_LENGTH + BLOCK_LENGTH)) {
				double c = (-1)*(slope*getCoord4Draw().X - getCoord4Draw().Y);
				fy = BOARD_LENGTH + BLOCK_LENGTH;
				fx = (fy + (-1)*c) / slope;
			}
			else if (fy < BIAS_Y) {
				double c = (-1)*slope*getCoord4Draw().X + getCoord4Draw().Y;
				fy = BIAS_Y;
				fx = (fy + (-1)*c) / slope;

				//fy = BIAS_X;

			}
			g->DrawLine(penVessel, getCoord4Draw().X, getCoord4Draw().Y, fx, fy);
		}
	}


	//Debug::WriteLine("draw laser called", X_Long, Y_long);
	return true;
}

#include "GeographicSystem.h"




GeographicSystem::GeographicSystem() {
	geoType = UNKNOWN_GEO_TYPE;
	name = "Unknown Geography Type";
	gpGeography = gcnew GraphicsPath();
	mouseIn = false;

	coord = coord4Draw = PointF();
	size = size4Draw = SizeF();
	colorAlpha = ALPHA_UP_BOUND;

	reefDamage = REEF_DAMAGE;

	canGoThrough_vessel = canGoThrough_generalFire = canGoThrough_torpedo = canGoThrough_laser = true;
}

GeographicSystem::GeographicSystem(const GeographicSystem^& rSide) {
	geoType = rSide->geoType;
	name = rSide->name;
	gpGeography = rSide->gpGeography;
	mouseIn = false;

	coord = rSide->coord;
	coord4Draw = rSide->coord4Draw;
	size = rSide->size;
	size4Draw = rSide->size4Draw;
	colorAlpha = rSide->colorAlpha;

	reefDamage = rSide->reefDamage;

	canGoThrough_vessel = rSide->canGoThrough_vessel;
	canGoThrough_generalFire = rSide->canGoThrough_generalFire;
	canGoThrough_torpedo = rSide->canGoThrough_torpedo;
	canGoThrough_laser = rSide->canGoThrough_laser;
}

GeographicSystem::GeographicSystem(GeographyType newGeoType, PointF newCoord, SizeF newSize) {
	coord = newCoord;
	coord4Draw = COORD_TO_DRAWING_COORD(coord.X, coord.Y);
	size = newSize;
	size4Draw = SIZE_TO_DRAWING_SIZE(size.Width, size.Height);
	colorAlpha = ALPHA_UP_BOUND;

	geoType = newGeoType;
	name = geoTypeStringList[geoType];

	gpGeography = gcnew GraphicsPath();
	gpGeography->AddRectangle(RectangleF(coord4Draw, size4Draw));
	mouseIn = false;

	reefDamage = REEF_DAMAGE;

	canGoThrough_vessel = canGoThrough_generalFire = canGoThrough_torpedo = canGoThrough_laser = true;
}

#pragma region getters and setters
GeographyType GeographicSystem::getGeoType() {
	return geoType;
}
void GeographicSystem::setGeoType(GeographyType newGeoType) {
	geoType = newGeoType;
	name = geoTypeStringList[geoType];
}

String^ GeographicSystem::getName() {
	return name;
}
void GeographicSystem::setName(String^ newName) {
	name = newName;
}

PointF GeographicSystem::getCoord() {
	return coord;
}
void GeographicSystem::setCoord(PointF newCoord) {
	coord = newCoord;
}

PointF GeographicSystem::getCoord4Draw() {
	return coord4Draw;
}
void GeographicSystem::setCoord4Draw(PointF newCoord4Draw) {
	coord4Draw = newCoord4Draw;
}

SizeF GeographicSystem::getSize() {
	return size;
}
void GeographicSystem::setSize(SizeF newSize) {
	size = newSize;
}

SizeF GeographicSystem::getSize4Draw() {
	return size4Draw;
}
void GeographicSystem::setSize4Draw(SizeF newSize4Draw) {
	size4Draw = newSize4Draw;
}

int GeographicSystem::getColorAlpha() {
	return colorAlpha;
}
void GeographicSystem::setColorAlpha(int newAlpha) {
	if (newAlpha > ALPHA_UP_BOUND)
		newAlpha = ALPHA_UP_BOUND;
	if (newAlpha < ALPHA_LOW_BOUND)
		newAlpha = ALPHA_LOW_BOUND;

	colorAlpha = newAlpha;
}

bool GeographicSystem::canVesselGoThrough() {
	return canGoThrough_vessel;
}
bool GeographicSystem::canGeneralFireGoThrough() {
	return canGoThrough_generalFire;
}
bool GeographicSystem::canTorpedoGoThrough() {
	return canGoThrough_torpedo;
}
bool GeographicSystem::canLaserGoThrough() {
	return canGoThrough_laser;
}

double GeographicSystem::getReefDamage() {
	return reefDamage;
}
void GeographicSystem::setReefDamage(double newReefDamage) {
	reefDamage = newReefDamage;
}

GraphicsPath^ GeographicSystem::getGp() {
	return gpGeography;
}
#pragma endregion

String^ GeographicSystem::detectAll(Team^ team, int minute, int second, int& newColorAlpha) {

	double minDis = (double)BOARD_SIZE;
	double dis1 = 0.0, dis2 = 0.0, dis3 = 0.0, dis4 = 0.0;
	double dis1_move = 0.0, dis2_move = 0.0, dis3_move = 0.0, dis4_move = 0.0;
	String^ newLog = "";
	List<Shell^> destroyedShellList;
	List<Torpedo^> destroyedTorpedoList;

	destroyedShellList.Clear();
	destroyedTorpedoList.Clear();

	/*
	      2
	  ---------
	  |       |
	  |       |
	1 |       | 3
	  |       |
	  |       |
	  ---------
	      4
	*/

	#pragma region Wrong vessel detection
	//for each (KeyValuePair<String^, VesselObject^>^ vessel in team->vesselList) {
	//	VesselObject^ thisVessel = vessel->Value;
	//	thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove(); thisVessel->VesselMove();

	//	dis1 = getDistanceBetweenPointAndSegment(vessel->Value->getCoord(), coord, PointF(coord.X, coord.Y + size.Height));
	//	dis2 = getDistanceBetweenPointAndSegment(vessel->Value->getCoord(), coord, PointF(coord.X + size.Width, coord.Y));
	//	dis3 = getDistanceBetweenPointAndSegment(vessel->Value->getCoord(), PointF(coord.X + size.Width, coord.Y), PointF(coord.X + size.Width, coord.Y + size.Height));
	//	dis4 = getDistanceBetweenPointAndSegment(vessel->Value->getCoord(), PointF(coord.X, coord.Y + size.Height), PointF(coord.X + size.Width, coord.Y + size.Height));

	//	dis1_move = getDistanceBetweenPointAndSegment(thisVessel->getCoord(), coord, PointF(coord.X, coord.Y + size.Height));
	//	dis2_move = getDistanceBetweenPointAndSegment(thisVessel->getCoord(), coord, PointF(coord.X + size.Width, coord.Y));
	//	dis3_move = getDistanceBetweenPointAndSegment(thisVessel->getCoord(), PointF(coord.X + size.Width, coord.Y), PointF(coord.X + size.Width, coord.Y + size.Height));
	//	dis4_move = getDistanceBetweenPointAndSegment(thisVessel->getCoord(), PointF(coord.X, coord.Y + size.Height), PointF(coord.X + size.Width, coord.Y + size.Height));

	//	//Debug::WriteLine("Dis: " + dis1 + ", " + dis2 + ", " + dis3 + ", " + dis4);

	//	// 沒撞到 移動到 撞到：有傷害、有停止（沒功能，反正對了就好管 TM 的）
	//	if (!(dis1 <= VESSEL_AND_GEO_COLLAPSION_DIS || dis2 <= VESSEL_AND_GEO_COLLAPSION_DIS || dis3 <= VESSEL_AND_GEO_COLLAPSION_DIS || dis4 <= VESSEL_AND_GEO_COLLAPSION_DIS)
	//		&&
	//		(dis1_move <= VESSEL_AND_GEO_COLLAPSION_DIS || dis2_move <= VESSEL_AND_GEO_COLLAPSION_DIS || dis3_move <= VESSEL_AND_GEO_COLLAPSION_DIS || dis4_move <= VESSEL_AND_GEO_COLLAPSION_DIS)) {

	//		//// vessel can not go through
	//		//if (canVesselGoThrough() == false) {

	//		//	// Special case: vessel hit REEF, it will receive damage from REEF
	//		//	if (geoType == REEF) {
	//		//		vessel->Value->setNowSpeed(0.0);
	//		//		vessel->Value->setNowAngle(0.0);
	//		//		vessel->Value->setRemainHp(vessel->Value->getRemainHp() - reefDamage);

	//		//		newLog += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (vessel->Value->getTeam() == A ? "A " : "B ") + vessel->Value->getName() + " HIT a " + this->getName() + ", stopped and got some damage\r\n";
	//		//	}

	//		//	// General case
	//		//	else {
	//		//		vessel->Value->setNowSpeed(0.0);
	//		//		vessel->Value->setNowAngle(0.0);

	//		//		newLog += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (vessel->Value->getTeam() == A ? "A " : "B ") + vessel->Value->getName() + " HIT a " + this->getName() + " and stopped\r\n";
	//		//	}
	//		//}
	//	}

	//	// 撞到 移動到 撞到：沒傷害、有停止
	//	else if ((dis1 <= VESSEL_AND_GEO_COLLAPSION_DIS || dis2 <= VESSEL_AND_GEO_COLLAPSION_DIS || dis3 <= VESSEL_AND_GEO_COLLAPSION_DIS || dis4 <= VESSEL_AND_GEO_COLLAPSION_DIS)
	//		&&
	//		(dis1_move <= VESSEL_AND_GEO_COLLAPSION_DIS || dis2_move <= VESSEL_AND_GEO_COLLAPSION_DIS || dis3_move <= VESSEL_AND_GEO_COLLAPSION_DIS || dis4_move <= VESSEL_AND_GEO_COLLAPSION_DIS)) {

	//		// vessel can not go through
	//		if (canVesselGoThrough() == false && vessel->Value->getNowSpeed() != 0.0) {

	//			// Special case: vessel hit REEF, it will receive damage from REEF
	//			if (geoType == REEF) {
	//				vessel->Value->setNowSpeed(0.0);
	//				vessel->Value->setNowAngle(0.0);
	//				vessel->Value->setRemainHp(vessel->Value->getRemainHp() - reefDamage);

	//				newLog += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (vessel->Value->getTeam() == A ? "A " : "B ") + vessel->Value->getName() + " HIT a " + this->getName() + ", stopped and got some damage\r\n";
	//			}

	//			// General case
	//			else {
	//				vessel->Value->setNowSpeed(0.0);
	//				vessel->Value->setNowAngle(0.0);

	//				newLog += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (vessel->Value->getTeam() == A ? "A " : "B ") + vessel->Value->getName() + " HIT a " + this->getName() + " and stopped\r\n";
	//			}
	//		}
	//	}
	//}
	#pragma endregion
	#pragma region Vessel detection
	for each (KeyValuePair<String^, VesselObject^>^ vessel in team->vesselList) {
		if (gpGeography->IsVisible(vessel->Value->getCoord4Draw()) && canVesselGoThrough() == false) {

			vessel->Value->DaoTuiLu(); vessel->Value->DaoTuiLu(); vessel->Value->DaoTuiLu(); vessel->Value->DaoTuiLu(); vessel->Value->DaoTuiLu();

			// Special case: vessel hit REEF, it will receive damage from REEF
			if (geoType == REEF) {
				vessel->Value->setNowSpeed(0.0);
				vessel->Value->setNowAngle(0.0);
				vessel->Value->setRemainHp(vessel->Value->getRemainHp() - reefDamage);

				newLog += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (vessel->Value->getTeam() == A ? "A " : "B ") + vessel->Value->getName() + " HIT a " + this->getName() + ", stopped and got some damage\r\n";
			}

			// General case
			else {
				vessel->Value->setNowSpeed(0.0);
				vessel->Value->setNowAngle(0.0);

				newLog += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] Team" + (vessel->Value->getTeam() == A ? "A " : "B ") + vessel->Value->getName() + " HIT a " + this->getName() + " and stopped\r\n";
			}
		}
	}
	#pragma endregion

	#pragma region Shell detection
	for each (Shell^ shell in team->shellList) {
		dis1 = getDistanceBetweenPointAndSegment(shell->getNowCoord(), coord, PointF(coord.X, coord.Y + size.Height));
		dis2 = getDistanceBetweenPointAndSegment(shell->getNowCoord(), coord, PointF(coord.X + size.Width, coord.Y));
		dis3 = getDistanceBetweenPointAndSegment(shell->getNowCoord(), PointF(coord.X + size.Width, coord.Y), PointF(coord.X + size.Width, coord.Y + size.Height));
		dis4 = getDistanceBetweenPointAndSegment(shell->getNowCoord(), PointF(coord.X, coord.Y + size.Height), PointF(coord.X + size.Width, coord.Y + size.Height));

		if (dis1 <= SHELL_AND_GEO_COLLAPSION_DIS || dis2 <= SHELL_AND_GEO_COLLAPSION_DIS || dis3 <= SHELL_AND_GEO_COLLAPSION_DIS || dis4 <= SHELL_AND_GEO_COLLAPSION_DIS) {

			// shell can not go through
			if (canGeneralFireGoThrough() == false) {
				shell->setSpeed(0.0);
				destroyedShellList.Add(shell);

				newLog += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] " + shell->getName() + " HIT a " + this->getName() + " and vanished\r\n";
			}
		}

		if (dis1 < minDis) minDis = dis1;
		if (dis2 < minDis) minDis = dis2;
		if (dis3 < minDis) minDis = dis3;
		if (dis4 < minDis) minDis = dis4;
	}
	for each (Shell^ shell in destroyedShellList)
		team->shellList.Remove(shell);
	#pragma endregion

	#pragma region Torpedo detection
	for each (Torpedo^ torpedo in team->torpedoList) {
		dis1 = getDistanceBetweenPointAndSegment(torpedo->getNowCoord(), coord, PointF(coord.X, coord.Y + size.Height));
		dis2 = getDistanceBetweenPointAndSegment(torpedo->getNowCoord(), coord, PointF(coord.X + size.Width, coord.Y));
		dis3 = getDistanceBetweenPointAndSegment(torpedo->getNowCoord(), PointF(coord.X + size.Width, coord.Y), PointF(coord.X + size.Width, coord.Y + size.Height));
		dis4 = getDistanceBetweenPointAndSegment(torpedo->getNowCoord(), PointF(coord.X, coord.Y + size.Height), PointF(coord.X + size.Width, coord.Y + size.Height));

		if (dis1 <= TORPEDO_AND_GEO_COLLAPSION_DIS || dis2 <= TORPEDO_AND_GEO_COLLAPSION_DIS || dis3 <= TORPEDO_AND_GEO_COLLAPSION_DIS || dis4 <= TORPEDO_AND_GEO_COLLAPSION_DIS) {

			// torpedo can not go through
			if (canTorpedoGoThrough() == false) {
				torpedo->setSpeed(0.0);
				destroyedTorpedoList.Add(torpedo);

				newLog += "[" + minute.ToString("00") + ":" + second.ToString("00") + "] " + torpedo->getName() + " HIT a " + this->getName() + " and vanished\r\n";
			}
		}

		if (dis1 < minDis) minDis = dis1;
		if (dis2 < minDis) minDis = dis2;
		if (dis3 < minDis) minDis = dis3;
		if (dis4 < minDis) minDis = dis4;
	}
	for each (Torpedo^ torpedo in destroyedTorpedoList)
		team->torpedoList.Remove(torpedo);
	#pragma endregion

	newColorAlpha = (int)((double)ALPHA_UP_BOUND - (minDis * ((double)(ALPHA_UP_BOUND - ALPHA_LOW_BOUND) / (double)BOARD_SIZE)));
	return newLog;
}

bool GeographicSystem::render(Graphics^ g) {

	if (mouseIn) {
		g->DrawString(name, gcnew Font("Consolas", 12), gcnew SolidBrush(Color::Azure), PointF(coord4Draw.X, coord4Draw.Y));
	}

	return true;
}

// 點到線段（注意：不是直線，是線段）距離
double GeographicSystem::getDistanceBetweenPointAndSegment(PointF point, PointF nowLoc, PointF endLoc) {
	double x = point.X, y = point.Y;
	double x1 = nowLoc.X, y1 = nowLoc.Y;
	double x2 = endLoc.X, y2 = endLoc.Y;

	double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);

	if (cross <= 0)
		return Math::Sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));



	double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

	if (cross >= d2)
		return Math::Sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));



	double r = cross / d2;
	double px = x1 + (x2 - x1) * r;
	double py = y1 + (y2 - y1) * r;

	return Math::Sqrt((x - px) * (x - px) + (py - y) * (py - y));
}
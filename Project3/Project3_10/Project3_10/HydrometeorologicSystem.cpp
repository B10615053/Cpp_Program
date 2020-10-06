#include "HydrometeorologicSystem.h"




#pragma region Constructors
HydrometeorologicSystem::HydrometeorologicSystem() {
	hydroType = UNKNOWN_HYDRO_TYPE;
	damage = speed = angle = 0;
	attackRange = 0;
	nowCoord = nowCoord4Draw = PointF();
	existTime = 0;
}

HydrometeorologicSystem::HydrometeorologicSystem(HydrometeorologicSystem^& rSide) {
	picture = rSide->picture;
	hydroType = rSide->hydroType;
	damage = rSide->damage;
	attackRange = rSide->attackRange;
	speed = rSide->speed;
	angle = rSide->angle;
	nowCoord = rSide->nowCoord;
	nowCoord4Draw = rSide->nowCoord4Draw;
	existTime = rSide->existTime;
	gpHydro = rSide->gpHydro;
}

HydrometeorologicSystem::HydrometeorologicSystem(double newAngle, PointF newNowCoord) {
	angle = newAngle;
	nowCoord = newNowCoord;
	nowCoord4Draw = COORD_TO_DRAWING_COORD(newNowCoord.X, newNowCoord.Y);
	existTime = 0;
}
#pragma endregion

#pragma region getters and setters
Bitmap^ HydrometeorologicSystem::getPicture() {
	return picture;
}
void HydrometeorologicSystem::setPicture(Bitmap^ newPicture) {
	picture = newPicture;
}

HydroType HydrometeorologicSystem::getHydroType() {
	return hydroType;
}
void HydrometeorologicSystem::sethydroType(HydroType newHydroType) {
	hydroType = newHydroType;
}

double HydrometeorologicSystem::getDamage() {
	return damage;
}
void HydrometeorologicSystem::setDamage(double newDamage) {
	damage = newDamage;
}

double HydrometeorologicSystem::getAttackRange() {
	return attackRange;
}
void HydrometeorologicSystem::setAttackRange(double newAttackRange) {
	attackRange = newAttackRange;
}

double HydrometeorologicSystem::getSpeed() {
	return speed;
}
void HydrometeorologicSystem::setSpeed(double newSpeed) {
	speed = newSpeed;
}

PointF HydrometeorologicSystem::getNowCoord() {
	return nowCoord;
}
void HydrometeorologicSystem::setNowCoord(PointF newNowCoord) {
	nowCoord = newNowCoord;
}

PointF HydrometeorologicSystem::getNowCoord4Draw() {
	return nowCoord4Draw;
}
void HydrometeorologicSystem::setNowCoord4Draw(PointF newNowCoord4Draw) {
	nowCoord4Draw = newNowCoord4Draw;
}

double HydrometeorologicSystem::getRotatePictureAngle() {
	return 0.0;
}
void HydrometeorologicSystem::setRotatePictureAngle(double newRotatePictureAngle) {
	return;
}

int HydrometeorologicSystem::getExistTime() {
	return existTime;
}
void HydrometeorologicSystem::setExistTime(int newExistTime) {
	existTime = newExistTime;
}

GraphicsPath^ HydrometeorologicSystem::getGp() {
	return gpHydro;
}
void HydrometeorologicSystem::setGp(GraphicsPath^ newGpHydro) {
	gpHydro = newGpHydro;
}

bool HydrometeorologicSystem::getMouseIn() {
	return mouseIn;
}
void HydrometeorologicSystem::setMouseIn(bool isMouseIn) {
	mouseIn = isMouseIn;
}

SizeF HydrometeorologicSystem::getSize() {
	return SizeF();
}
void HydrometeorologicSystem::setSize(SizeF newSize) {
	return;
}

SizeF HydrometeorologicSystem::getSize4Draw() {
	return SizeF();
}
void HydrometeorologicSystem::setSize4Draw(SizeF newSize4Draw) {
	return;
}
#pragma endregion

void HydrometeorologicSystem::hydroMove() {
	if (speed == 0.0)
		return;

	if (speed < 0) {
		speed = speed * (-1);
		angle += 180;
	}

	double dx, dy;

	if (BoundaryJudgment(getNowCoord().X, getNowCoord().Y)) {
		dx = Math::Cos(ANGLE_TO_RADIUS(angle));
		dy = -(Math::Sin(ANGLE_TO_RADIUS(angle)));
		double dis = Math::Sqrt((dx * dx) + (dy * dy));

		setNowCoord(PointF(speed * dx + getNowCoord().X, speed * dy + getNowCoord().Y));
		setNowCoord4Draw(COORD_TO_DRAWING_COORD(getNowCoord().X, getNowCoord().Y));
	}
	else {
		speed = 0.0;
		angle = 0.0;

		if (nowCoord.X < 0.0)
			nowCoord.X = 0.0;
		if (nowCoord.Y < 0.0)
			nowCoord.Y = 0.0;

		if (nowCoord.X > 20.0)
			nowCoord.X = 20.0;
		if (nowCoord.Y > 20.0)
			nowCoord.Y = 20.0;

		setNowCoord4Draw(COORD_TO_DRAWING_COORD(getNowCoord().X, getNowCoord().Y));
	}

	setRotatePictureAngle(getRotatePictureAngle() + ROTATE_ANGLE);

	return;
}

bool HydrometeorologicSystem::BoundaryJudgment(double _X, double _Y) {
	double end0 = -10.0;
	double end20 = 30.0;

	if (_X < end0 || _Y < end0 || _X > end20 || _Y > end20)
		return false;
	else
		return true;
}

bool HydrometeorologicSystem::render(Graphics^ g) {

	Pen^ penHydro = gcnew Pen(Color::Black);
	Brush^ bruHydro = gcnew SolidBrush(Color::FromArgb(100, 200, 200, 200));

	if (mouseIn && hydroType == FOG) {
		g->DrawString("Fog", gcnew Font("Consolas", 12), gcnew SolidBrush(Color::Black), PointF(nowCoord4Draw.X, nowCoord4Draw.Y));
	}

	return true;
}

Size^ HydrometeorologicSystem::CalculateNewSize(int width, int height, double RotateAngle) {
	double r = Math::Sqrt(Math::Pow((double)width / 2.0, 2.0) + Math::Pow((double)height / 2.0, 2.0)); //畖L
	double OriginalAngle = Math::Acos((width / 2.0) / r) / Math::PI * 180.0;  //癸à絬㎝X禸à
	double minW = 0.0, maxW = 0.0, minH = 0.0, maxH = 0.0; //程㎝程 XY畒夹
	double drawPoint[4];
	drawPoint[0] = (-OriginalAngle + RotateAngle) * Math::PI / 180.0;
	drawPoint[1] = (OriginalAngle + RotateAngle) * Math::PI / 180.0;
	drawPoint[2] = (180.0 - OriginalAngle + RotateAngle) * Math::PI / 180.0;
	drawPoint[3] = (180.0 + OriginalAngle + RotateAngle) * Math::PI / 180.0;

	for (int i = 0; i < 4; i++) //パà翴衡XY程の程
	{
		double x = r * Math::Cos(drawPoint[i]);
		double y = r * Math::Sin(drawPoint[i]);

		if (x < minW)
			minW = x;
		if (x > maxW)
			maxW = x;
		if (y < minH)
			minH = y;
		if (y > maxH)
			maxH = y;
	}

	return gcnew Size((int)(maxW - minW), (int)(maxH - minH));
}

Bitmap^ HydrometeorologicSystem::RotateImage(Bitmap^ image, float RotateAngle) {
	Size^ newSize = CalculateNewSize(image->Width, image->Height, RotateAngle);
	//Debug::WriteLine("org: " + image->Width + " " + image->Height);
	Bitmap^ rotatedBmp = gcnew Bitmap(newSize->Width, newSize->Height);
	//Debug::WriteLine("new: " + newSize->Width + " " + newSize->Height);
	PointF^ centerPoint = gcnew PointF((float)rotatedBmp->Width / 2.0, (float)rotatedBmp->Height / 2.0);
	//Debug::WriteLine("newcen: " + rotatedBmp->Width / 2.0 + " " + rotatedBmp->Height / 2.0);
	Graphics^ g = Graphics::FromImage(rotatedBmp);

	g->CompositingQuality = CompositingQuality::HighQuality;
	g->SmoothingMode = SmoothingMode::HighQuality;
	g->InterpolationMode = InterpolationMode::HighQualityBicubic;

	g->TranslateTransform(centerPoint->X, centerPoint->Y);
	g->RotateTransform(RotateAngle);
	g->TranslateTransform(-centerPoint->X, -centerPoint->Y);

	g->DrawImage(image, (float)(newSize->Width - image->Width) / 2.0, (float)(newSize->Height - image->Height) / 2.0, image->Width, image->Height);
	//g->Dispose();

	return rotatedBmp;
}
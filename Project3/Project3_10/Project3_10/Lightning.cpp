#include "Lightning.h"




Lightning::Lightning(): HydrometeorologicSystem() {
	picture = PICTURE_LIGHTNING;
	gpHydro = gcnew GraphicsPath();
}

Lightning::Lightning(Lightning^& rSide) {
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

Lightning::Lightning(PointF newNowCoord): HydrometeorologicSystem(0.0, newNowCoord) {
	hydroType = LIGHTNING;
	picture = PICTURE_LIGHTNING;
	damage = DAMAGE;
	attackRange = ATTACK_RANGE;
	speed = SPEED;
	gpHydro = gcnew GraphicsPath();
	gpHydro->AddRectangle(RectangleF(getNowCoord4Draw().X - picture->Width / 2.0 + biasX4Pic, getNowCoord4Draw().Y - picture->Height / 2.0 + biasY4Pic, picture->Width, picture->Height));
}

Lightning^ Lightning::operator=(Lightning^ rSide) {
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

	return this;
}

double Lightning::getRotatePictureAngle() {
	return 0.0;
}
void Lightning::setRotatePictureAngle(double newRotatePictureAngle) {
	return;
}

bool Lightning::render(Graphics^ g) {
	//double biasX4Pic = 0.0;
	//double biasY4Pic = 0.0;

	Point ulCorner = Point(getNowCoord4Draw().X - picture->Width / 2.0 + biasX4Pic, getNowCoord4Draw().Y - picture->Height / 2.0 + biasY4Pic);
	g->DrawImage(picture, ulCorner);

	HydrometeorologicSystem::render(g);
	return true;
}
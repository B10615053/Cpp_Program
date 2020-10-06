#include "Typhoon.h"



Typhoon::Typhoon(): HydrometeorologicSystem() {
	picture = PICTURE_TYPHOON;
	rotatePictureAngle = 0.0;
	gpHydro = gcnew GraphicsPath();
}

Typhoon::Typhoon(Typhoon^& rSide) {
	picture = rSide->picture;
	hydroType = rSide->hydroType;
	damage = rSide->damage;
	attackRange = rSide->attackRange;
	speed = rSide->speed;
	angle = rSide->angle;
	nowCoord = rSide->nowCoord;
	nowCoord4Draw = rSide->nowCoord4Draw;
	rotatePictureAngle = rSide->rotatePictureAngle;
	existTime = rSide->existTime;
	gpHydro = rSide->gpHydro;
}

Typhoon::Typhoon(double newAngle, PointF newNowCoord): HydrometeorologicSystem(newAngle, newNowCoord) {
	hydroType = TYPHOON;
	picture = PICTURE_TYPHOON;
	damage = DAMAGE;
	attackRange = ATTACK_RANGE;
	speed = SPEED;
	rotatePictureAngle = 0.0;

	gpHydro = gcnew GraphicsPath();
	gpHydro->AddRectangle(RectangleF(getNowCoord4Draw().X - picture->Width / 2.0, getNowCoord4Draw().Y - picture->Height / 2.0, picture->Width, picture->Height));
}

Typhoon^ Typhoon::operator=(Typhoon^ rSide) {
	picture = rSide->picture;
	hydroType = rSide->hydroType;
	damage = rSide->damage;
	attackRange = rSide->attackRange;
	speed = rSide->speed;
	angle = rSide->angle;
	nowCoord = rSide->nowCoord;
	nowCoord4Draw = rSide->nowCoord4Draw;
	rotatePictureAngle = rSide->rotatePictureAngle;
	existTime = rSide->existTime;
	gpHydro = rSide->gpHydro;

	return this;
}

double Typhoon::getRotatePictureAngle() {
	return rotatePictureAngle;
}
void Typhoon::setRotatePictureAngle(double newRotatePictureAngle) {
	rotatePictureAngle = newRotatePictureAngle;

	if (rotatePictureAngle == 360.0)
		rotatePictureAngle = 0.0;
}

bool Typhoon::render(Graphics^ g) {
	#pragma region draw picture
	// Create image.
	//Bitmap^ bitmap1;
	//bitmap1 = PICTURE;
	// Image after rotate
	Bitmap^ bitmapRotate;
	bitmapRotate = RotateImage(picture, rotatePictureAngle + 180);
	// Create Point of center.
	Point ulCorner = Point(getNowCoord4Draw().X - bitmapRotate->Width / 2.0, getNowCoord4Draw().Y - bitmapRotate->Height / 2.0);
	// Draw image to screen.
	g->DrawImage(bitmapRotate, ulCorner);
	#pragma endregion

	HydrometeorologicSystem::render(g);
	return true;
}


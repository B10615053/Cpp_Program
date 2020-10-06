#include "Fog.h"




Fog::Fog() : HydrometeorologicSystem() {
	Random^ r = gcnew Random(DateTime::Now.Millisecond);

	hydroType = FOG;

	PointF centerNowCoord = PointF(r->NextDouble() * BOARD_SIZE, r->NextDouble() * BOARD_SIZE);
	SizeF centerSize = SizeF(r->NextDouble() * Math::Min((double)centerNowCoord.X, (double)BOARD_SIZE - (double)centerNowCoord.X), r->NextDouble() * Math::Min((double)centerNowCoord.Y, (double)BOARD_SIZE - (double)centerNowCoord.Y));

	nowCoord = PointF(centerNowCoord.X - (centerSize.Width / 2.0), centerNowCoord.Y - (centerSize.Height / 2.0));
	nowCoord4Draw = COORD_TO_DRAWING_COORD(nowCoord.X, nowCoord.Y);
	
	size = centerSize;
	size4Draw = SIZE_TO_DRAWING_SIZE(size.Width, size.Height);
	
	gpHydro = gcnew GraphicsPath();
	gpHydro->AddEllipse(nowCoord4Draw.X, nowCoord4Draw.Y, size4Draw.Width, size4Draw.Height);
}

Fog::Fog(Fog^& rSide) {
	picture = rSide->picture;
	hydroType = rSide->hydroType;
	damage = rSide->damage;
	attackRange = rSide->attackRange;
	speed = rSide->speed;
	angle = rSide->angle;
	nowCoord = rSide->nowCoord;
	nowCoord4Draw = rSide->nowCoord4Draw;
	existTime = rSide->existTime;
	size = rSide->size;
	size4Draw = rSide->size4Draw;
	gpHydro = rSide->gpHydro;
}

//Fog::Fog(PointF newNowCoord) : HydrometeorologicSystem(0.0, newNowCoord) {
//	hydroType = FOG;
//	damage = DAMAGE;
//	attackRange = ATTACK_RANGE;
//	speed = SPEED;
//}

Fog^ Fog::operator=(Fog^ rSide) {
	picture = rSide->picture;
	hydroType = rSide->hydroType;
	damage = rSide->damage;
	attackRange = rSide->attackRange;
	speed = rSide->speed;
	angle = rSide->angle;
	nowCoord = rSide->nowCoord;
	nowCoord4Draw = rSide->nowCoord4Draw;
	existTime = rSide->existTime;
	size = rSide->size;
	size4Draw = rSide->size4Draw;
	gpHydro = rSide->gpHydro;

	return this;
}

#pragma region getters and setters

double Fog::getRotatePictureAngle() {
	return 0.0;
}
void Fog::setRotatePictureAngle(double newRotatePictureAngle) {
	return;
}

SizeF Fog::getSize() {
	return size;
}
void Fog::setSize(SizeF newSize) {
	size = newSize;
}

SizeF Fog::getSize4Draw() {
	return size4Draw;
}
void Fog::setSize4Draw(SizeF newSize4Draw) {
	size4Draw = newSize4Draw;
}
#pragma endregion

bool Fog::render(Graphics^ g) {
	g->FillPath(gcnew SolidBrush(Color::FromArgb(199, 255, 255, 255)), gpHydro);

	return true;
}
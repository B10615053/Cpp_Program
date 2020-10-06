#include "Shell.h"



Shell::Shell() {
	picture = PICTURE;
	name = "Unknown";
	team = NONE;
	speed = damage = angle = 0.0;
	nowCoord = nowCoord4Draw = goalCoord = PointF();
	totalFlyingTime = 0.0;
	nowFlyingTime = 0;
}

Shell::Shell(Shell^& rSide) {
	picture = rSide->picture;
	name = rSide->name;
	team = rSide->team;
	speed = rSide->speed;
	damage = rSide->damage;
	angle = rSide->angle;
	nowCoord = rSide->nowCoord;
	nowCoord4Draw = rSide->nowCoord4Draw;
	goalCoord = rSide->goalCoord;
	totalFlyingTime = rSide->totalFlyingTime;
	nowFlyingTime = rSide->nowFlyingTime;
}

Shell::Shell(String^ newName, TeamSymbol whichTeam, double newSpeed, double newDamage, double newAngle, PointF beginCoord, PointF endCoord) {
	picture = PICTURE;
	name = newName;
	team = whichTeam;
	speed = newSpeed;
	damage = newDamage;
	angle = newAngle;
	nowCoord = beginCoord;
	nowCoord4Draw = COORD_TO_DRAWING_COORD(nowCoord.X, nowCoord.Y);
	goalCoord = endCoord;

	if (speed != 0.0)
		totalFlyingTime = Math::Sqrt( Math::Abs(((nowCoord.X - goalCoord.X) * (nowCoord.X - goalCoord.X)) + ((nowCoord.Y - goalCoord.Y) * (nowCoord.Y - goalCoord.Y))) ) / speed;
	else
		totalFlyingTime = INF;

	nowFlyingTime = 0;
}

Shell^ Shell::operator=(Shell^ rSide) {
	picture = rSide->picture;
	name = rSide->name;
	team = rSide->team;
	speed = rSide->speed;
	damage = rSide->damage;
	angle = rSide->angle;
	nowCoord = rSide->nowCoord;
	nowCoord4Draw = rSide->nowCoord4Draw;
	goalCoord = rSide->goalCoord;
	totalFlyingTime = rSide->totalFlyingTime;
	nowFlyingTime = rSide->nowFlyingTime;

	return this;
}

#pragma region getters and setters
Bitmap^ Shell::getPicture() {
	return picture;
}
void Shell::setPicture(Bitmap^ newPicture) {
	picture = newPicture;
}

String^ Shell::getName() {
	return name;
}
void Shell::setName(String^ newName) {
	name = newName;
}

TeamSymbol Shell::getTeam() {
	return team;
}
void Shell::setTeam(TeamSymbol whichTeam) {
	team = whichTeam;
}

double Shell::getSpeed() {
	return speed;
}
void Shell::setSpeed(double newSpeed) {
	speed = newSpeed;
}

double Shell::getDamage() {
	return damage;
}
void Shell::setDamage(double newDamage) {
	damage = newDamage;
}

double Shell::getAngle() {
	return angle;
}
void Shell::setAngle(double newAngle) {
	angle = newAngle;
}

PointF Shell::getNowCoord() {
	return nowCoord;
}
void Shell::setNowCoord(PointF newNowCoord) {
	nowCoord = newNowCoord;
}

PointF Shell::getNowCoord4Draw() {
	return nowCoord4Draw;
}
void Shell::setNowCoord4Draw(PointF newNowCoord4Draw) {
	nowCoord4Draw = newNowCoord4Draw;
}

PointF Shell::getGoalCoord() {
	return goalCoord;
}
void Shell::setGoalCoord(PointF newGoalCoord) {
	goalCoord = newGoalCoord;
}

double Shell::getTotalFlyingTime() {
	return totalFlyingTime;
}
void Shell::setTotalFlyingTime(double newTotalFlyingTime) {
	totalFlyingTime = newTotalFlyingTime;
}

int Shell::getNowFlyingTime() {
	return nowFlyingTime;
}
void Shell::setNowFlyingTime(int newNowFlyingTime) {
	nowFlyingTime = newNowFlyingTime;
}
#pragma endregion

void Shell::ShellMove() {
	double dx = (getGoalCoord().X - getNowCoord().X);
	double dy = (getGoalCoord().Y - getNowCoord().Y);
	double dis = Math::Sqrt((dx * dx) + (dy * dy));

	setNowCoord(PointF(getNowCoord().X + getSpeed() * (dx / dis), getNowCoord().Y + getSpeed() * (dy / dis)));
	setNowCoord4Draw(COORD_TO_DRAWING_COORD(getNowCoord().X, getNowCoord().Y));

	setNowFlyingTime(getNowFlyingTime() + 1);
}

bool Shell::render(Graphics^ g) {

	#pragma region draw picture
	// Create image.
	//Bitmap^ bitmap1;
	//bitmap1 = PICTURE;
	// Image after rotate
	Bitmap^ bitmapRotate;
	bitmapRotate = RotateImage(picture, angle + 180);
	// Create Point of center.
	Point ulCorner = Point(getNowCoord4Draw().X - bitmapRotate->Width / 2.0, getNowCoord4Draw().Y - bitmapRotate->Height / 2.0);
	// Draw image to screen.
	g->DrawImage(bitmapRotate, ulCorner);
	#pragma endregion

	#pragma region draw name
	g->DrawString(name, gcnew Font("Consolas", 8), gcnew SolidBrush(team == A ? Color::Red : Color::Blue), PointF(nowCoord4Draw.X + BIAS_X_4_DRAW_NAME, nowCoord4Draw.Y - BIAS_Y_4_DRAW_NAME));
	#pragma endreigon

	return true;
}

Size^ Shell::CalculateNewSize(int width, int height, double RotateAngle) {
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

Bitmap^ Shell::RotateImage(Bitmap^ image, float RotateAngle) {
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
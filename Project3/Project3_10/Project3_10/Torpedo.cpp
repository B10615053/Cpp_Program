// Weapon: Torpedo
#include "Torpedo.h"

// Default constructor
Torpedo::Torpedo() {
	picture = PICTURE;
	name = vesselName = "Unknown";
	team = NONE;
	speed = damage = angle = 0.0;
	nowCoord = nowCoord4Draw = goalCoord = PointF();
	totalFlyingTime = 0.0;
	nowFlyingTime = 0;
}

// Copy constructor
Torpedo::Torpedo(Torpedo^& rSide) {
	picture = rSide->picture;
	name = rSide->name;
	vesselName = rSide->vesselName;
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

// Constructor
Torpedo::Torpedo(String^ newName, String^ newVesselName, TeamSymbol whichTeam, double newSpeed, double newDamage, double newAngle, PointF beginCoord, PointF endCoord) {
	picture = PICTURE;
	name = newName;
	vesselName = newVesselName;
	team = whichTeam;
	speed = newSpeed;
	damage = newDamage;
	angle = newAngle;
	nowCoord = beginCoord;
	nowCoord4Draw = COORD_TO_DRAWING_COORD(nowCoord.X, nowCoord.Y);
	goalCoord = endCoord;

	if (speed != 0.0)
		totalFlyingTime = Math::Sqrt(Math::Abs(((nowCoord.X - goalCoord.X) * (nowCoord.X - goalCoord.X)) + ((nowCoord.Y - goalCoord.Y) * (nowCoord.Y - goalCoord.Y)))) / speed;
	else
		totalFlyingTime = INF;

	nowFlyingTime = 0;
}

// Overload assign operator
Torpedo^ Torpedo::operator=(Torpedo^ rSide) {
	picture = rSide->picture;
	name = rSide->name;
	vesselName = rSide->vesselName;
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
Bitmap^ Torpedo::getPicture() {
	return picture;
}
void Torpedo::setPicture(Bitmap^ newPicture) {
	picture = newPicture;
}

// Get torpedo's name
String^ Torpedo::getName() {
	return name;
}
// Set torpedo's name
void Torpedo::setName(String^ newName) {
	name = newName;
}

String^ Torpedo::getVesselName() {
	return vesselName;
}
void Torpedo::setVesselName(String^ newVesselName) {
	vesselName = newVesselName;
}

// Get torpedo's team
TeamSymbol Torpedo::getTeam() {
	return team;
}
// Set torpedo's team
void Torpedo::setTeam(TeamSymbol whichTeam) {
	team = whichTeam;
}
// Get torpedo's speed
double Torpedo::getSpeed() {
	return speed;
}
// Set torpedo's speed
void Torpedo::setSpeed(double newSpeed) {
	speed = newSpeed;
}
// Get torpedo's damage
double Torpedo::getDamage() {
	return damage;
}
// Set torpedo's damage
void Torpedo::setDamage(double newDamage) {
	damage = newDamage;
}
// Get torpedo's angle
double Torpedo::getAngle() {
	return angle;
}
// Set torpedo's angle
void Torpedo::setAngle(double newAngle) {
	angle = newAngle;
}
// Get coordinate now
PointF Torpedo::getNowCoord() {
	return nowCoord;
}
// Set coordinate now
void Torpedo::setNowCoord(PointF newNowCoord) {
	nowCoord = newNowCoord;
}
// Get coordinate on the graphic now
PointF Torpedo::getNowCoord4Draw() {
	return nowCoord4Draw;
}
// Set coordinate on the graphic now
void Torpedo::setNowCoord4Draw(PointF newNowCoord4Draw) {
	nowCoord4Draw = newNowCoord4Draw;
}
// Get goal Coordinate
PointF Torpedo::getGoalCoord() {
	return goalCoord;
}
// Set goal Coordinate
void Torpedo::setGoalCoord(PointF newgoalCoord) {
	goalCoord = newgoalCoord;
}

double Torpedo::getTotalFlyingTime() {
	return totalFlyingTime;
}
void Torpedo::setTotalFlyingTime(double newTotalFlyingTime) {
	totalFlyingTime = newTotalFlyingTime;
}

int Torpedo::getNowFlyingTime() {
	return nowFlyingTime;
}
void Torpedo::setNowFlyingTime(int newNowFlyingTime) {
	nowFlyingTime = newNowFlyingTime;
}
#pragma endregion

// Move function of torpedo
void Torpedo::TorpedoMove() {
	// Laplace x
	double dx = (getGoalCoord().X - getNowCoord().X);
	// Laplace y
	double dy = (getGoalCoord().Y - getNowCoord().Y);
	// Total difference
	double dis = Math::Sqrt((dx * dx) + (dy * dy));
	// Set new Coordinate
	setNowCoord(PointF(getNowCoord().X + getSpeed() * (dx / dis), getNowCoord().Y + getSpeed() * (dy / dis)));
	// Set Coordinate on the graphic
	setNowCoord4Draw(COORD_TO_DRAWING_COORD(getNowCoord().X, getNowCoord().Y));
}

// Icon of torpedo
bool Torpedo::render(Graphics^ g) {
	//// Create image.
	//Bitmap^ bitmap1;
	//bitmap1 = dynamic_cast<Bitmap^>(Bitmap::FromFile("picture/torpedo.png"));
	//// Image after rotate
	//Bitmap^ bitmapRotate;
	//bitmapRotate = RotateImage(bitmap1, angle + 180);
	//// Create Point of center.
	//Point ulCorner = Point(getNowCoord4Draw().X - bitmapRotate->Width / 2.0, getNowCoord4Draw().Y - bitmapRotate->Height / 2.0);
	//// Draw image to screen.
	//g->DrawImage(bitmapRotate, ulCorner);
	//return true;

	#pragma region draw picture
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

#pragma region Helper functions of render
// Rotate to icon
Bitmap^ Torpedo::RotateImage(Bitmap^ image, float angle) {
	Size^ newSize = CalculateNewSize(image->Width, image->Height, angle);
	Bitmap^ rotatedBmp = gcnew Bitmap(newSize->Width, newSize->Height);
	PointF^ centerPoint = gcnew PointF((float)rotatedBmp->Width / 2.0, (float)rotatedBmp->Height / 2.0);
	Graphics^ g = Graphics::FromImage(rotatedBmp);

	g->CompositingQuality = CompositingQuality::HighQuality;
	g->SmoothingMode = SmoothingMode::HighQuality;
	g->InterpolationMode = InterpolationMode::HighQualityBicubic;

	g->TranslateTransform(centerPoint->X, centerPoint->Y);
	g->RotateTransform(angle);
	g->TranslateTransform(-centerPoint->X, -centerPoint->Y);

	g->DrawImage(image, (float)(newSize->Width - image->Width) / 2.0, (float)(newSize->Height - image->Height) / 2.0, image->Width, image->Height);
	//g->Dispose();

	return rotatedBmp;
}

// Calculate the new size
Size^ Torpedo::CalculateNewSize(int width, int height, double angle) {
	double r = Math::Sqrt(Math::Pow((double)width / 2.0, 2.0) + Math::Pow((double)height / 2.0, 2.0)); //畖L
	double OriginalAngle = Math::Acos((width / 2.0) / r) / Math::PI * 180.0;  //癸à絬㎝X禸à
	double minW = 0.0, maxW = 0.0, minH = 0.0, maxH = 0.0; //程㎝程 XY畒夹
	double drawPoint[4];
	drawPoint[0] = (-OriginalAngle + angle) * Math::PI / 180.0;
	drawPoint[1] = (OriginalAngle + angle) * Math::PI / 180.0;
	drawPoint[2] = (180.0 - OriginalAngle + angle) * Math::PI / 180.0;
	drawPoint[3] = (180.0 + OriginalAngle + angle) * Math::PI / 180.0;

	// パà翴衡 XY 程の程
	for (int i = 0; i < 4; i++)
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
#pragma endregion
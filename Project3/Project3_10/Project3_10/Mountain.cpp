#include "Mountain.h"




Mountain::Mountain() : GeographicSystem() {}

Mountain::Mountain(Mountain^& rSide) {
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

Mountain::Mountain(PointF newCoord, SizeF newSize) : GeographicSystem(MOUNTAIN, newCoord, newSize) {
	canGoThrough_vessel = false;
	canGoThrough_generalFire = false;
	canGoThrough_torpedo = false;
	canGoThrough_laser = true;
}

Mountain^ Mountain::operator=(Mountain^ rSide) {
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

	return this;
}

bool Mountain::render(Graphics^ g) {
	//Debug::WriteLine("Color alpha = " + colorAlpha);
	Brush^ bruGeo = gcnew SolidBrush(Color::FromArgb(colorAlpha, 45, 45, 245));
	g->FillPath(bruGeo, gpGeography);

	GeographicSystem::render(g);
	return true;
}
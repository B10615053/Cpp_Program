#include "Reef.h"




Reef::Reef() : GeographicSystem() {
	reefDamage = REEF_DAMAGE;
}

Reef::Reef(Reef^& rSide) {
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

Reef::Reef(PointF newCoord, SizeF newSize) : GeographicSystem(REEF, newCoord, newSize) {
	reefDamage = REEF_DAMAGE;

	canGoThrough_vessel = false;
	canGoThrough_generalFire = true;
	canGoThrough_torpedo = false;
	canGoThrough_laser = true;
}

Reef^ Reef::operator=(Reef^ rSide) {
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

bool Reef::render(Graphics^ g) {
	//Debug::WriteLine("Color alpha = " + colorAlpha);
	Brush^ bruGeo = gcnew SolidBrush(Color::FromArgb(colorAlpha, 100, 100, 100));
	g->FillPath(bruGeo, gpGeography);

	GeographicSystem::render(g);
	return true;
}
#include "Flatland.h"




Flatland::Flatland() : GeographicSystem() {}

Flatland::Flatland(Flatland^& rSide) {
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

Flatland::Flatland(PointF newCoord, SizeF newSize) : GeographicSystem(FLATLAND, newCoord, newSize) {
	canGoThrough_vessel = false;
	canGoThrough_generalFire = true;
	canGoThrough_torpedo = false;
	canGoThrough_laser = true;
}

Flatland^ Flatland::operator=(Flatland^ rSide) {
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

bool Flatland::render(Graphics^ g) {
	//Debug::WriteLine("Color alpha = " + colorAlpha);
	Brush^ bruGeo = gcnew SolidBrush(Color::FromArgb(colorAlpha, 23, 100, 14));
	g->FillPath(bruGeo, gpGeography);

	GeographicSystem::render(g);
	return true;
}
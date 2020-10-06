#pragma once

#include "GeographicSystem.h"

ref class Flatland : public GeographicSystem {
public:
	Flatland();
	Flatland(Flatland^&);
	Flatland(PointF, SizeF);

	Flatland^ operator=(Flatland^);

	virtual bool render(Graphics^) override;

private:
};


#pragma once

#include "GeographicSystem.h"

ref class Reef : public GeographicSystem {
public:
	Reef();
	Reef(Reef^&);
	Reef(PointF, SizeF);

	Reef^ operator=(Reef^);

	virtual bool render(Graphics^) override;

private:
};


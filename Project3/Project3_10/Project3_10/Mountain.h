#pragma once

#include "GeographicSystem.h"

ref class Mountain : public GeographicSystem {
public:
	Mountain();
	Mountain(Mountain^&);
	Mountain(PointF, SizeF);

	Mountain^ operator=(Mountain^);

	virtual bool render(Graphics^) override;

private:
};


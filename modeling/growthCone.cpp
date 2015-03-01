#include "growthCone.h"
#include "cmn_defines.h"

GrowthCone& GrowthCone::operator=( GrowthCone &growthCone ) {
	growthEnabled = growthCone.isGrowthEnabled();
	somaDistance = growthCone.getSomaDistance();
	coordinates = growthCone.getCoordinates();
	TRACE("growthCone", "Growth cone copied. Soma distance = %d and coordinates are\n", somaDistance);
	coordinates.PrintCoordinates();
	return *this;
};

GrowthCone::GrowthCone() {
	growthEnabled = true;
	somaDistance  = 0;
};

bool GrowthCone::isGrowthEnabled() {
	return growthEnabled;
};

void GrowthCone::move(Coordinates coord, double delta) {
	coordinates = coord;
	increaseSomaDistance(delta);
};

void GrowthCone::increaseSomaDistance(double delta) {
	somaDistance += delta;
};

int GrowthCone::getSomaDistance() {
	return (int)somaDistance;
};

void GrowthCone::setCoordinates(Coordinates coord) {
	coordinates = coord;
};

Coordinates GrowthCone::getCoordinates() {
	return coordinates;
};
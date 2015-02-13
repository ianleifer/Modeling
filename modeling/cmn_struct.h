#ifndef CMN_STRUCT_H
#define CMN_STRUCT_H

#include "coordinates.h"

struct Cell {
	Coordinates coordinates;
	//(nothing / neuron / axon / dendrite) (0/1/2/3)
	int cellType;
};

#endif
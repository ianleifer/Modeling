#ifndef CMN_STRUCT_H
#define CMN_STRUCT_H

#include "coordinates.h"

class Cell {
private:
	bool IsEmpty;
public:
	Cell& operator=( Cell &cell );
	Coordinates coordinates;
	//(nothing / neuron / axon / dendrite) (0/1/2/3)
	int cellType;
	int NeuronId;
	int NeuriteId;
	int growthConeId;
	int somaDistance;
	void PrintCoordinates();

	void makeEmpty();
	void makeFull();
	bool isEmpty();
};

#endif
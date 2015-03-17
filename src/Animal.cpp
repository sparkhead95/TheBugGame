#include "Animal.h"
using namespace std;

	Animal::Animal()
	{
		xCoord = 0;
		yCoord = 1;
	}

	void Animal::setHeight(int newHeight){
		yCoord = newHeight;
	}

	void Animal::setLength(int newLength){
		xCoord = newLength;
	}

	pair<int, int> Animal::getPosition(){
		return make_pair(this->xCoord, this->yCoord);
	}

	Animal::~Animal(){

	}

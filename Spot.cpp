#include <iostream>
#include "Spot.h"
using namespace std;

//Default constructor setting an empty spot with -1 neighbors
Spot::Spot(){
   mIsOccupied = false;
   mNumNeighbors = -1;
}
Spot::~Spot(){}

void Spot::setNumNeighbors(int n){
   mNumNeighbors = n;
}

int Spot::getNumNeighbors(){
   return mNumNeighbors;
}

bool Spot::getIsOccupied(){
   return mIsOccupied;
}

void Spot::setIsOccupied(bool isOccupied){
   mIsOccupied = isOccupied;
}


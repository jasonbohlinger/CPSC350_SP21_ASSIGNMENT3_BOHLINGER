#include <iostream>
#include "Spot.h"
using namespace std;

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


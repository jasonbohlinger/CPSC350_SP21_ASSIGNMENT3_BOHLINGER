#include <iostream>
#ifndef SPOT_H
#define SPOT_H
using namespace std;

class Spot{
   public:
      Spot(); // Default constructor
      ~Spot(); // Destructor
      void setNumNeighbors(int n); // Sets mNumNeighbors to n
      int getNumNeighbors(); // Returns mNumNeighbors
      bool getIsOccupied(); // Returns mIsOccupied
      void setIsOccupied(bool isOccupied); // Sets mIsOccupied to isOccupied
   private:
      int mNumNeighbors; // Integer representing the number of neighbors a spot has
      bool mIsOccupied; // boolean representing whether the spot is occupied or not
};
#endif
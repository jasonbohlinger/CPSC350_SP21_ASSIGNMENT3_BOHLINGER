#include <iostream>
#ifndef SPOT_H
#define SPOT_H
using namespace std;

class Spot{
   public:
      Spot();
      ~Spot();
      void setNumNeighbors(int n);
      int getNumNeighbors();
      bool getIsOccupied();
      void setIsOccupied(bool isOccupied);
   private:
      int mNumNeighbors;
      bool mIsOccupied;
};
#endif
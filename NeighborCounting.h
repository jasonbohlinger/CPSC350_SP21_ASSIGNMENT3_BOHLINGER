#include <iostream>
#include "Grid.h"

#ifndef NEIGHBOR_COUNTING_H
#define NEIGHBOR_COUNTING_H
using namespace std;

class NeighborCounting{
   public:
      NeighborCounting(); // Default constructor
      ~NeighborCounting(); // Destructor
      void countNeighborsNormal(Grid* grid); // Counting neighbors in normal mode
      void countNeighborsDoughnut(Grid* grid); // Counting neighbors in doughnut mode
      void countNeighborsMirror(Grid* grid); // Counting neighbors in mirror mode
   private:
};

#endif

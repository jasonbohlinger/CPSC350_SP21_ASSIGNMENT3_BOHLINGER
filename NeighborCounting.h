#include <iostream>
#include "Grid.h"

#ifndef NEIGHBOR_COUNTING_H
#define NEIGHBOR_COUNTING_H
using namespace std;

class NeighborCounting{
   public:
      NeighborCounting();
      ~NeighborCounting();
      void countNeighborsNormal(Grid* grid);
      void countNeighborsDoughnut(Grid* grid);
      void countNeighborsMirror(Grid* grid);
   private:
};

#endif

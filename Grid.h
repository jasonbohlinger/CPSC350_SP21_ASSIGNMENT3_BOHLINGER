#include <iostream>
#include "Spot.h"

#ifndef GRID_H
#define GRID_H
using namespace std;

class Grid{
   public:
      Grid();
      Grid(int dimX, int dimY);
      ~Grid();
      Spot** getGrid();
      int getNumRows();
      int getNumCol();
      void populate(float density);
      void print();
      void reset();
      Spot* at(int row, int col);
      bool equals(Grid* other);
      bool isEmpty();
      void printToFile(string fileName, int genNumber);
   private:
      Spot** mGrid;
      int mNumRows;
      int mNumCol;
};

#endif
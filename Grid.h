#include <iostream>
#include "Spot.h"

#ifndef GRID_H
#define GRID_H
using namespace std;

class Grid{
   public:
      Grid(); // Default constructor
      Grid(int dimX, int dimY); // Overloaded constructor
      ~Grid(); // Destructor
      int getNumRows(); //Returns mNumRows
      int getNumCol(); //Returns mNumCol
      void populate(float density); // Fills a grid with a given density
      void print(); // Prints all elements of grid
      Spot* at(int row, int col); // Returns a Spot* at a given row and col of the grid
      bool equals(Grid* other); //Returns true if one grid equals Grid other
      bool isEmpty(); //Returns true if grid is empty. False otherwise
      void printToFile(string fileName, int genNumber); // Prints the current grid to a file given fileName and generation number
   private:
      Spot** mGrid;
      int mNumRows;
      int mNumCol;
};

#endif
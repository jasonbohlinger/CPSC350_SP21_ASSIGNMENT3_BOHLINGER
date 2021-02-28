#include <iostream>
#include <vector>
#include <algorithm>
#include "Grid.h"

#ifndef PAST_GENERATIONS_H
#define PAST_GENERATIONS_H
using namespace std;
class PastGenerations{
   public:
      PastGenerations(); // Default constructor
      ~PastGenerations(); // Destructor
      void append(Grid* g); // Appends a grid to the end of generations
      Grid* get(int pos); // Returns the Grid* at a given position in generations
      int size(); // Returns the size of generations
      void move(int oldIndex, int newIndex); //Moves element at oldIndex to newIndex
      float getAvgNeighbors(int row, int col); // Gets the average neighbors for a certain spot
   private:
      vector<Grid*> generations; // Vector holding Grid* objects representing prior generations
};
#endif
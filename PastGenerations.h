#include <iostream>
#include <vector>
#include <algorithm>
#include "Grid.h"

#ifndef PAST_GENERATIONS_H
#define PAST_GENERATIONS_H
using namespace std;
class PastGenerations{
   public:
      PastGenerations();
      ~PastGenerations();
      void append(Grid* g);
      Grid* get(int pos);
      int size();
      void removeFirstPosition();
      void print();
      void move(int oldIndex, int newIndex);
      float getAvgNeighbors(int row, int col);
   private:
      vector<Grid*> generations;
};
#endif
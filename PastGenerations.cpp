#include <iostream>
#include <vector>
#include "PastGenerations.h"
#include "NeighborCounting.h"
using namespace std;

PastGenerations::PastGenerations(){
   generations.push_back(nullptr); // Placeholder nullptr
}
PastGenerations::~PastGenerations(){
}

void PastGenerations::append(Grid* g){
   if(generations[0] == nullptr){ // If generations is empty
      generations.pop_back(); //Get rid of the placeholder nullptr
   }
   generations.push_back(g);
}

//Return the Grid* at position pos in generations
Grid* PastGenerations::get(int pos){
   return generations[pos];
}

int PastGenerations::size(){
   return generations.size();
}

void PastGenerations::move0ToEnd(){
   rotate(generations.begin(), generations.begin() + 1, generations.end());
}

float PastGenerations::getAvgNeighbors(int row, int col){
   //Check to make sure generations is not empty
   if(generations[0] != nullptr){
      //If there is only one grid, just return the number of neighbors at the given spot
      if(generations.size() == 1){
         float sum;
         sum = generations[0]->at(row, col)->getNumNeighbors();
         return sum;
      } else if(generations.size() == 2){ //Compute the average of the only 2 grids in generations
         float sum;
         sum = generations[generations.size() - 1]->at(row, col)->getNumNeighbors();
         sum += generations[generations.size() - 2]->at(row, col)->getNumNeighbors();
         return sum / 2.0;
      } else{ // Compute the average of the past 3 generations
         float sum;
         sum = generations[generations.size() - 2]->at(row, col)->getNumNeighbors();
         sum += generations[generations.size() - 3]->at(row, col)->getNumNeighbors();
         sum += generations[generations.size() - 4]->at(row, col)->getNumNeighbors();
         return sum / 3.0;
      }
   }
}
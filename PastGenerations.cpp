#include <iostream>
#include "PastGenerations.h"
#include "NeighborCounting.h"
using namespace std;

PastGenerations::PastGenerations(){
   generations.push_back(nullptr);
}
PastGenerations::~PastGenerations(){
}

void PastGenerations::append(Grid* g){
   if(generations[0] == nullptr){
      generations.pop_back();
   }
   generations.push_back(g);
}

Grid* PastGenerations::get(int pos){
   return generations[pos];
}

int PastGenerations::size(){
   return generations.size();
}

void PastGenerations::removeFirstPosition(){
   generations.erase(generations.begin());
}

void PastGenerations::print(){
   for(int i = 0; i < generations.size(); ++i){
      generations[i]->print();
      cout << endl << endl;
   }
}

void PastGenerations::move(int oldIndex, int newIndex){
   if(oldIndex > newIndex){
      rotate(generations.rend() - oldIndex - 1, generations.rend() - oldIndex, generations.rend() - newIndex);
   } else{
      rotate(generations.begin() + oldIndex, generations.begin() + oldIndex + 1, generations.begin() + newIndex + 1);
   }
}

float PastGenerations::getAvgNeighbors(int row, int col){
   if(generations[0] != nullptr){
      if(generations.size() == 1){
         float sum;
         sum = generations[0]->at(row, col)->getNumNeighbors();
         return sum;
      } else if(generations.size() == 2){
         float sum;
         sum = generations[generations.size() - 1]->at(row, col)->getNumNeighbors();
         sum += generations[generations.size() - 2]->at(row, col)->getNumNeighbors();
         return sum / 2.0;
      } else{
         float sum;
         sum = generations[generations.size() - 2]->at(row, col)->getNumNeighbors();
         sum += generations[generations.size() - 3]->at(row, col)->getNumNeighbors();
         sum += generations[generations.size() - 4]->at(row, col)->getNumNeighbors();
         return sum / 3.0;
      }
   }
}
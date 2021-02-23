#include <iostream>
#include "NeighborCounting.h"

NeighborCounting::NeighborCounting(){}

NeighborCounting::~NeighborCounting(){}

void NeighborCounting::countNeighborsNormal(Grid* grid){
   for(int row = 0; row < grid->getNumRows(); ++row){
      for(int col = 0; col < grid->getNumCol(); ++col){
         int count = 0;
         //top row
         if(row == 0){
            if(col == 0){
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
            } else{
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
            }
         } else if(row == grid->getNumRows() - 1){
            if(col == 0){
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
            } else{
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
            }
         } else{
            if(col == 0){
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
            } else{
               if(grid->at(row - 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
            }
         }
         grid->at(row, col)->setNumNeighbors(count);
      }
   }
}

void NeighborCounting::countNeighborsDoughnut(Grid* grid){
   countNeighborsNormal(grid);
   
   for(int row = 0; row < grid->getNumRows(); ++row){
      for(int col = 0; col < grid->getNumCol(); ++col){
         int count = 0;
         if(row == 0){
            if(col == 0){
               if(grid->at(row + 1, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(grid->getNumRows() - 1, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(grid->getNumRows() - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(grid->getNumRows() - 1, col + 1)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row + 1, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(0, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(grid->getNumRows() - 1, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(grid->getNumRows() - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(grid->getNumRows() - 1, col - 1)->getIsOccupied()){
                  ++count;
               }
            } else{
               if(grid->at(grid->getNumRows() - 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(grid->getNumRows() - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(grid->getNumRows() - 1, col + 1)->getIsOccupied()){
                  ++count;
               }
            }
         } else if(row == grid->getNumRows() - 1){
            if(col == 0){
               if(grid->at(0, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(0, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(0, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row - 1, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(0, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(0, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(0, col - 1)->getIsOccupied()){
                  ++count;
               }
            } else{
               if(grid->at(0, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(0, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(0, col + 1)->getIsOccupied()){
                  ++count;
               }
            }
         } else{
            if(col == 0){
               if(grid->at(row - 1, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row - 1, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, 0)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, 0)->getIsOccupied()){
                  ++count;
               }
            }
         }
         grid->at(row, col)->setNumNeighbors(grid->at(row, col)->getNumNeighbors() + count);
      }
   }
}

void NeighborCounting::countNeighborsMirror(Grid* grid){
   countNeighborsNormal(grid);
   
   for(int row = 0; row < grid->getNumRows(); ++row){
      for(int col = 0; col < grid->getNumCol(); ++col){
         int count = 0;
         
         if(row == 0){
            if(col == 0){
               if(grid->at(row, col)->getIsOccupied()){
                  count += 3;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row, col)->getIsOccupied()){
                  count += 3;
               }
            } else{
               if(grid->at(row, col)->getIsOccupied()){
                  ++count;
               }
            }
         } else if(row == grid->getNumRows() - 1){
            if(col == 0){
               if(grid->at(row, col)->getIsOccupied()){
                  count += 3;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row, col)->getIsOccupied()){
                  count += 3;
               }
            } else{
               if(grid->at(row, col)->getIsOccupied()){
                  ++count;
               }
            }
         } else{
            if(col == 0){
               if(grid->at(row, col)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){
               if(grid->at(row, col)->getIsOccupied()){
                  ++count;
               }
            }
         }
         grid->at(row, col)->setNumNeighbors(grid->at(row, col)->getNumNeighbors() + count);
      }
   }
}



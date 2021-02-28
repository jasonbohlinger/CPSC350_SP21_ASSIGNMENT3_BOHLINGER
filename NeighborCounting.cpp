#include <iostream>
#include "NeighborCounting.h"

NeighborCounting::NeighborCounting(){}

NeighborCounting::~NeighborCounting(){}

void NeighborCounting::countNeighborsNormal(Grid* grid){
   for(int row = 0; row < grid->getNumRows(); ++row){
      for(int col = 0; col < grid->getNumCol(); ++col){
         int count = 0;
         if(row == 0){ //Top row
            if(col == 0){ //Top left corner
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){ //Top right corner
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
            } else{ //Anywhere else in the top row
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
         } else if(row == grid->getNumRows() - 1){ // Bottom row
            if(col == 0){ //Bottom left corner
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col + 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){ //Bottom right corner
              if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
            } else{ // Anywhere else in the bottom row
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
         } else{ // Any other row
            if(col == 0){ // Any row, first column
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
            } else if(col == grid->getNumCol() - 1){ // Any row, last column
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
            } else{ // Any row, any column
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
   //Count the neighbors normally first, then add neighbors from doughnut specifically
   countNeighborsNormal(grid);
   
   for(int row = 0; row < grid->getNumRows(); ++row){
      for(int col = 0; col < grid->getNumCol(); ++col){
         int count = 0;
         if(row == 0){ // Top row
            if(col == 0){ // Top left corner
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
            } else if(col == grid->getNumCol() - 1){ // Top right corner
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
            } else{ // Top row any column
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
         } else if(row == grid->getNumRows() - 1){ // Bottom row
          if(col == 0){ // Bottom left corner
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
            } else if(col == grid->getNumCol() - 1){ // Bottom right corner
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
            } else{ // Bottom row any column
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
         } else{ // Any row
            if(col == 0){ // First column
               if(grid->at(row - 1, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, grid->getNumCol() - 1)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){ // Last column
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
   //Count neighbors normally and then add neighbors found specifically from mirror mode
   countNeighborsNormal(grid);
   
   for(int row = 0; row < grid->getNumRows(); ++row){
      for(int col = 0; col < grid->getNumCol(); ++col){
         int count = 0;
         
         if(row == 0){ // Top row
            if(col == 0){ // Top left corner
               if(grid->at(row, col)->getIsOccupied()){
                  count += 3;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){ // Top right corner
               if(grid->at(row, col)->getIsOccupied()){
                  count += 3;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
            } else{ // Top row any column
               if(grid->at(row, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
            }
         } else if(row == grid->getNumRows() - 1){ // Bottom row 
          if(col == 0){ // Bottom left corner
               if(grid->at(row, col)->getIsOccupied()){
                  count += 3;
               }
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){ // Bottom right corner
               if(grid->at(row, col)->getIsOccupied()){
                  count += 3;
               }
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
            } else{ // Bottom row any column
               if(grid->at(row, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col - 1)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row, col + 1)->getIsOccupied()){
                  ++count;
               }
            }
         } else{ // Any row
            if(col == 0){ // first column
               if(grid->at(row, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
            } else if(col == grid->getNumCol() - 1){ // last column
               if(grid->at(row, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row - 1, col)->getIsOccupied()){
                  ++count;
               }
               if(grid->at(row + 1, col)->getIsOccupied()){
                  ++count;
               }
            }
         }
         grid->at(row, col)->setNumNeighbors(grid->at(row, col)->getNumNeighbors() + count);
      }
   }
}



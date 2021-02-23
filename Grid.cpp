#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Grid.h"
using namespace std;

Grid::Grid(){
   mGrid = new Spot*[5];
   for(int i = 0; i < 5; ++i){
      mGrid[i] = new Spot[5];
   }
   mNumRows = 5;
   mNumCol = 5;
}

Grid::Grid(int numRows, int numCol){
   mGrid = new Spot*[numRows];
   for(int i = 0; i < numRows; ++i){
      mGrid[i] = new Spot[numCol];
   } 
   mNumRows = numRows;
   mNumCol = numCol;
}

Grid::~Grid(){
   for(int i = 0; i < mNumRows; ++i){
      delete [] mGrid[i];
   }
   delete [] mGrid;
   mGrid = 0;
}

int Grid::getNumRows(){
   return mNumRows;
}

int Grid::getNumCol(){
   return mNumCol;
}

void Grid::populate(float density){
   srand(time(NULL));
   for(int i = 0; i < mNumRows; ++i){
      for(int x = 0; x < mNumCol; ++x){
         float randNum = ((float)rand() / (float)(RAND_MAX));
         if((randNum <= density) && (density != 0)){
            mGrid[i][x].setIsOccupied(true);
         }
      }
   }
}

void Grid::print(){
   for(int row = 0; row < mNumRows; ++row){
      for(int col = 0; col < mNumCol; ++col){
         if(mGrid[row][col].getIsOccupied()){
            cout << "X";
         } else{
            cout << "-";
         }
      }
      cout << endl;
   }
   cout << endl << endl;
}

void Grid::printToFile(string fileName){
   
}

void Grid::reset(){
   for(int row = 0; row < mNumRows; ++row){
      for(int col = 0; col < mNumCol; ++col){
         mGrid[row][col].setIsOccupied(false);
      }
   }
}

Spot* Grid::at(int row, int col){
   return &mGrid[row][col];
}

bool Grid::equals(Grid* other){
   bool equals = true;
   for(int row = 0; row < this->mNumRows; ++row){
      for(int col = 0; col < this->mNumCol; ++ col){
         if(this->at(row, col)->getIsOccupied() != other->at(row, col)->getIsOccupied()){
            equals = false;
            break;
         }
      } 
      if(equals == false){
         break;
      }
   }
   return equals;
}

bool Grid::isEmpty(){
   bool empty = true;
   for(int row = 0; row < mNumRows; ++row){
      for(int col = 0; col < mNumCol; ++col){
         if(mGrid[row][col].getIsOccupied()){
            empty = false;
         }
      }
   }
   return empty;
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Grid.h"
using namespace std;

//Default constructor declares a grid with 5 rows and 5 columns
Grid::Grid(){
   mGrid = new Spot*[5];
   for(int i = 0; i < 5; ++i){
      mGrid[i] = new Spot[5];
   }
   mNumRows = 5;
   mNumCol = 5;
}

//Overloaded constructor declares a grid with numRows rows and numCol columns
Grid::Grid(int numRows, int numCol){
   mGrid = new Spot*[numRows];
   for(int i = 0; i < numRows; ++i){
      mGrid[i] = new Spot[numCol];
   } 
   mNumRows = numRows;
   mNumCol = numCol;
}

//Destructor
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
   int numOccupied = (mNumRows * mNumCol) * density; // The number of spots that are going to be filled
   int count = 0; // The number of spots filled so far
   while(count != numOccupied){
      int randRow = rand() % mNumRows; //Generates a random integer from 0 to mNumRows
      int randCol = rand() % mNumCol; //Generates a random integer from 0 to mNumCol
      //If that random spot is not occupied yet, set it to occupied
      if(!mGrid[randRow][randCol].getIsOccupied()){
         mGrid[randRow][randCol].setIsOccupied(true);
         ++count; //Increment the number of spots filled so far
      }
   }
}

void Grid::print(){
   //Go through every spot in the grid,
   //print 'X' if it is occupied
   //print '-' if it is not occupied
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

void Grid::printToFile(string fileName, int genNumber){
   ofstream oStream;
   if(genNumber == 0){ // If this is the initial generation, open a FRESH file
      oStream.open(fileName);
   } else{ // If this is not the initial generation, append to the file
      oStream.open(fileName, ios_base::app);
   }

   if(!oStream.is_open()){
      cout << "Unable to open " << fileName << "." << endl;
   }

   oStream << "Generation " << genNumber << ":" << endl;
   //If the current spot is occupied, print 'X' to the file,
   //If it is not occupied, print '-' to the file
   for(int row = 0; row < mNumRows; ++row){
      for(int col = 0; col < mNumCol; ++col){
         if(mGrid[row][col].getIsOccupied()){
            oStream << "X";
         } else{
            oStream << "-";
         }
      }
      oStream << endl;
   }
   oStream << endl << endl;
   if(genNumber == 1000){
      oStream << "Simulation stopped writing to file. Reason: infinite loop" << endl;
   }
   //close the stream
   oStream.close();
}

//Returns an address of the Spot at index [row][col] of mGrid
Spot* Grid::at(int row, int col){
   return &mGrid[row][col];
}

bool Grid::equals(Grid* other){
   bool equals = true;
   for(int row = 0; row < this->mNumRows; ++row){
      for(int col = 0; col < this->mNumCol; ++ col){
         //If at any point the two positions don't match up, 
         //quit the loop and return false
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
   for(int row = 0; row < mNumRows; ++row){
      for(int col = 0; col < mNumCol; ++col){
         //If at any point the current spot is occpuied,
         //return false
         if(mGrid[row][col].getIsOccupied()){
            return false;
         }
      }
   }
   return true;
}

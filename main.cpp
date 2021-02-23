#include "Spot.h"
#include "Grid.h"
#include "NeighborCounting.h"
#include "PastGenerations.h"
#include <iostream>
#include <fstream>

using namespace std;


int main(){
   string worldType;
   int rows;
   int cols;
   float density;
   Grid* aGrid;
   string userInput;
   NeighborCounting* n = new NeighborCounting;
   PastGenerations* p = new PastGenerations;
   cout << "Enter (1) to import a map file for the world." << endl;
   cout << "Enter (2) to use random assignment." << endl;
   cin >> worldType;
   
   if(worldType == "1"){
      ifstream input;
      string fileName;
      cout << "Enter your filename: " << endl;
      cin >> fileName;
      input.open(fileName);
      
      if(!input.is_open()){
         cout << "Error opening " << fileName << "." << endl;
      }
      input >> rows;
      input >> cols;
      input.ignore();
      aGrid = new Grid(rows, cols);
      int gridArrow = 0;
      string line;
      while(!input.fail()){
         getline(input, line);
         if(line.size() != 0){
            for(int i = 0; i < cols; ++i){
               if(line.at(i) == 'X'){
                  aGrid->at(gridArrow, i)->setIsOccupied(true);
               } else if(line.at(i) == '-'){
                  aGrid->at(gridArrow, i)->setIsOccupied(false);
               }
            }
            ++gridArrow;
         }
      }
      if(!input.eof()){
         cout << "Error while parsing " << fileName << "." << endl;
      }
      
      input.close();
      
   } else if(worldType == "2"){
      cout << "Enter the number of rows you would like (height): " << endl;
      cin >> rows;
      cout << "Enter the number of columns you would like (width): " << endl;
      cin >> cols;
      aGrid = new Grid(rows, cols);
      cout << "Enter the population density you would like: " << endl;
      float density;
      cin >> density;
      aGrid->populate(density);
   } else{
      cout << "Invalid input" << endl;
      return -1;
   }
   bool printToFile = false;
   bool automatic = false;
   cout << "Enter (1) to pause between generations on console" << endl;
   cout << "Enter (2) to progress automatically on console" << endl;
   cout << "Enter (3) to print results to a file" << endl;
   cin >> userInput;
   if(userInput == "1"){
      cout << "Hit enter to progresss generations!" << endl;
   } else if(userInput == "2"){
      automatic = true;
      userInput = "";
   } else if(userInput == "3"){
      automatic = true;
      printToFile = true;
      userInput = "";
   } else{
      cout << "Invalid input" << endl;
      return -1;
   }
   if(!automatic){
      cin.ignore();
      getline(cin, userInput);
   }
   int generationNumber = 0;
   p->append(aGrid);
   n->countNeighborsNormal(aGrid);
   Grid* bGrid = new Grid(rows, cols);
   Grid* cGrid = new Grid(rows, cols);
   Grid* dGrid = new Grid(rows, cols);
   if(userInput.size() == 0){
      cout << "Generation: " << generationNumber << endl;
      aGrid->print();
      for(int r = 0; r < aGrid->getNumRows(); ++r){
         for(int c = 0; c < aGrid->getNumCol(); ++c){
            float numNeighbors = p->getAvgNeighbors(r, c);
            
            if(numNeighbors < 1.5){
               bGrid->at(r, c)->setIsOccupied(false);
            } else if(numNeighbors <= 2.50){
               bGrid->at(r, c)->setIsOccupied(aGrid->at(r, c)->getIsOccupied());
            } else if(numNeighbors <= 3.50){
               bGrid->at(r, c)->setIsOccupied(true);
            } else{
               bGrid->at(r, c)->setIsOccupied(false);
            }
         }
      }
   } else{
      cout << "Finished game of life. Reason: user input ended game" << endl;
      return -1;
   }
   if(!automatic){
      getline(cin, userInput);
   }
   if(userInput.size() == 0){
      cout << "Generation: " << ++generationNumber << endl;
      bGrid->print();
      if(bGrid->isEmpty()){
         cout << "Finished game of life. Reason: empty map" << endl;
         return 0;
      }
      n->countNeighborsNormal(bGrid);
      p->append(bGrid);
      for(int r = 0; r < aGrid->getNumRows(); ++r){
         for(int c = 0; c < aGrid->getNumCol(); ++c){
            float numNeighbors = p->getAvgNeighbors(r, c);
            
            if(numNeighbors < 1.5){
               cGrid->at(r, c)->setIsOccupied(false);
            } else if(numNeighbors <= 2.50){
               cGrid->at(r, c)->setIsOccupied(bGrid->at(r, c)->getIsOccupied());
            } else if(numNeighbors <= 3.50){
               cGrid->at(r, c)->setIsOccupied(true);
            } else{
               cGrid->at(r, c)->setIsOccupied(false);
            }
         }
      }
   } else{
      cout << "Finished game of life. Reason: user input ended game" << endl;
      return -1;
   }
   if(!automatic){
      getline(cin, userInput);
   }
   if(userInput.size() == 0){
      cout << "Generation: " << ++generationNumber << endl;
      cGrid->print();
      if(cGrid->isEmpty()){
         cout << "Finished game of life. Reason: empty map" << endl;
         return 0;
      }
      n->countNeighborsNormal(cGrid);
      p->append(cGrid);
   } else{
      return -1;
   }
   p->append(dGrid);
   //looping now
   if(!automatic){
      getline(cin, userInput);
   }
   n->countNeighborsNormal(aGrid);
   n->countNeighborsNormal(bGrid);
   n->countNeighborsNormal(cGrid);
   bool isOscillating = false;
   bool isStable = false;
   bool isEmpty = false;
   while(!isStable && !isOscillating && !isEmpty && userInput.size() == 0){
      cout << "Generation: " << ++generationNumber << endl;
      for(int r = 0; r < aGrid->getNumRows(); ++r){
         for(int c = 0; c < aGrid->getNumCol(); ++c){
            float numNeighbors = p->getAvgNeighbors(r, c);
            if(numNeighbors < 1.50){
               p->get(p->size() - 1)->at(r, c)->setIsOccupied(false);
            } else if(numNeighbors <= 2.50){
               if(p->get(p->size() - 2)->at(r, c)->getIsOccupied()){
                  p->get(p->size() - 1)->at(r, c)->setIsOccupied(true);
               } else{
                  p->get(p->size() - 1)->at(r, c)->setIsOccupied(false);
               }
            } else if(numNeighbors <= 3.50){
               p->get(p->size() - 1)->at(r, c)->setIsOccupied(true);
            } else{
               p->get(p->size() - 1)->at(r, c)->setIsOccupied(false);
            }
         }
      }
      isEmpty = p->get(p->size() - 1)->isEmpty();
      //if(isEmpty){
         //break;
      //}
      p->get(p->size() - 1)->print();
      n->countNeighborsNormal(p->get(p->size() - 1));
      
      //check for stability:
      if(p->get(p->size() - 1)->equals(p->get(p->size() - 2)) &&
         p->get(p->size() - 1)->equals(p->get(p->size() - 3)) &&
         p->get(p->size() - 1)->equals(p->get(p->size() - 4))){
            isStable = true;
            break;
      }
         
      //check for oscillation:
      
      if(p->get(p->size() - 1)->equals(p->get(p->size() - 3)) &&
         p->get(p->size() - 2)->equals(p->get(p->size() - 4))){
            isOscillating = true;
            break;
      }
      p->move(0, p->size() - 1);
      if(!automatic){
         getline(cin, userInput);
      }
   }
   
   cout << "Finished game of life. Reason: ";
   if(isStable){
      cout << "stable map" << endl;
   } else if(isOscillating){
      cout << "oscillating map" << endl;
   } else if(isEmpty){
      cout << "empty map" << endl;
   } else{
      cout << "user input ended game" << endl;
   }
   delete aGrid;
   delete bGrid;
   delete cGrid;
   delete dGrid;
   delete n;
   delete p;
}
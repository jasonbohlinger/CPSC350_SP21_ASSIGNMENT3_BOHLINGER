#include "Spot.h"
#include "Grid.h"
#include "NeighborCounting.h"
#include "PastGenerations.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


int main(){

   //Declares variables necessary for running program
   string worldType;
   int rows;
   int cols;
   float density;
   Grid* aGrid;
   string userInput;
   NeighborCounting* n = new NeighborCounting;
   PastGenerations* p = new PastGenerations;
 
   //Prompts user to ask if they want to randomly generate a map or give one to the program

   cout << endl << "Welcome to the game of life!" << endl;
   cout << "Enter (1) to import a map file for the world." << endl;
   cout << "Enter (2) to use random assignment." << endl;
   cin >> worldType;
   
   //If the user wants to import a map, ask for the filename/path
   if(worldType == "1"){
      ifstream input;
      string fileName;
      cout << "Enter your filename or absolute path: " << endl;
      cin >> fileName;
      input.open(fileName);
      
      if(!input.is_open()){
         cout << "Error opening " << fileName << "." << endl;
         return -1;
      }
      //Grab the number of rows and columns from the first two lines of the file
      input >> rows;
      input >> cols;
      input.ignore(); //Ignore whitespace leftover from input >> cols
      aGrid = new Grid(rows, cols);
      //Variable representing the current row of the grid
      int gridRowArrow = 0;
      string line;
      while(!input.fail()){
         getline(input, line); // Grab grid input one line at a time
         if(line.size() != 0 && gridRowArrow < rows){
            for(int i = 0; i < cols; ++i){
               //Looping through the line, if there is an 'X',
               //Set the current spot to occupied
               //If there is a '-', set the current spot to empty
               if(line.at(i) == 'X'){
                  aGrid->at(gridRowArrow, i)->setIsOccupied(true);
               } else if(line.at(i) == '-'){
                  aGrid->at(gridRowArrow, i)->setIsOccupied(false);
               }
            }
            //Increment row 
            ++gridRowArrow;
         }
      }
      if(!input.eof()){
         cout << "Error while parsing " << fileName << "." << endl;
      }
      //Close input as it is no longer needed
      input.close();
      
   } else if(worldType == "2"){ // If the user wants to randomly generate a map
      //Prompt for the size of the grid
      cout << "Enter the number of rows you would like (height): " << endl;
      cin >> rows;
      cout << "Enter the number of columns you would like (width): " << endl;
      cin >> cols;
      //Declare the new Grid with given dimensions
      aGrid = new Grid(rows, cols);
      cout << "Enter the population density you would like (between 0 and 1): " << endl;
      float density;
      cin >> density;
      //Simple check to make sure that the density is between 0 and 1
      if(density < 0 || density > 1){
         cout << "Invalid input" << endl;
         return -1;
      }
      //Populate the grid with given density
      aGrid->populate(density);
   } else{
      cout << "Invalid input" << endl;
      return -1;
   }
   string countingMethod;
   //Prompt the user for a counting method (normal, mirror, or doughnut)
   cout << "Enter (1) to count with the normal mode" << endl;
   cout << "Enter (2) to count with the mirror mode" << endl;
   cout << "Enter (3) to count with the doughnut mode" << endl;
   cin >> countingMethod;
   //Use the user input to set the counting method
   if(countingMethod == "1"){
      countingMethod = "normal";
   } else if(countingMethod == "2"){
      countingMethod = "mirror";
   } else if(countingMethod == "3"){
      countingMethod = "doughnut";
   } else{
      cout << "Invalid input" << endl;
      return -1;
   }
   bool printToFile = false;
   string fileName;
   bool automatic = false; // Boolean representing if the user wants to progress automatically
                           //Is true if they choose to progress automatically on console or in file
   //Asks if the user wants to pause between generations, 
   //progress automatically, or print all results to a file
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
      cout << "Enter the filename you want to print to" << endl;
      cin >> fileName;
      userInput = "";
   } else{
      cout << "Invalid input" << endl;
      return -1;
   }
   if(!automatic){
      cin.ignore(); // Ignore whitespace left over from cin 
      getline(cin, userInput);
   }
   int generationNumber = 0;
   //Add aGrid to the pastGenerations' vector
   p->append(aGrid);
   
   //Count neighbors with specified counting method
   if(countingMethod == "mirror"){
      n->countNeighborsMirror(aGrid);
   } else if(countingMethod == "doughnut"){
      n->countNeighborsDoughnut(aGrid);
   } else{
      n->countNeighborsNormal(aGrid);
   }
   //Creates 3 new empty grids with the same dimensions as aGrid
   Grid* bGrid = new Grid(rows, cols);
   Grid* cGrid = new Grid(rows, cols);
   Grid* dGrid = new Grid(rows, cols);
   
   if(userInput.size() == 0){
      cout << "Generation: " << generationNumber << endl;
      if(printToFile){
         aGrid->printToFile(fileName, 0);
      } else{
         aGrid->print();
      }
      //setting up the generation after aGrid
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
   if(userInput.size() == 0){ // Checking if userInput is "" 
                              //which can be inputted by hitting only 'enter'
      cout << "Generation: " << ++generationNumber << endl;
      if(printToFile){ // If the user specifies to write to a file
                        //call grid's printToFile function
         bGrid->printToFile(fileName, 1);
      } else{
         bGrid->print(); // Print normally otherwise
      }
      if(bGrid->isEmpty()){
         cout << "Finished game of life. Reason: empty map" << endl;
         cout << "Press 'enter' to exit program.";
         cin.ignore();
         getline(cin, userInput);
         if(userInput.size() == 0){
            return 0;
         }
      }
      if(countingMethod == "mirror"){
         n->countNeighborsMirror(bGrid);
      } else if(countingMethod == "doughnut"){
         n->countNeighborsDoughnut(bGrid);
      } else{
         n->countNeighborsNormal(bGrid);
      }
      p->append(bGrid); // put bGrid at the end of PastGenerations' vector
      //Setting up the generation after bGrid
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
   if(userInput.size() == 0){ // If user inputs 'enter' again
      cout << "Generation: " << ++generationNumber << endl;
      if(printToFile){
         cGrid->printToFile(fileName, 2);
      } else{
         cGrid->print();
      }
      if(cGrid->isEmpty()){
         cout << "Finished game of life. Reason: empty map" << endl;
         cout << "Press 'enter' to exit program.";
         cin.ignore();
         getline(cin, userInput);
         if(userInput.size() == 0){
            return 0;
         }
      }
      if(countingMethod == "mirror"){
         n->countNeighborsMirror(cGrid);
      } else if(countingMethod == "doughnut"){
         n->countNeighborsDoughnut(cGrid);
      } else{
         n->countNeighborsNormal(cGrid);
      }
      p->append(cGrid); // put cGrid at the end of PastGenerations' vector
   } else{
      return -1;
   }
   p->append(dGrid); // put dGrid at the end of PastGenerations' vector

   if(!automatic){
      getline(cin, userInput);
   }

   //Predefining boolean values for while loop
   bool isOscillating = false;
   bool isStable = false;
   bool isEmpty = false;
   //As long as the generations are not stable, oscillating, or empty
   //and as long as the user hits 'enter'if the program is not automatic
   while(!isStable && !isOscillating && !isEmpty && userInput.size() == 0){
      cout << "Generation: " << ++generationNumber << endl;
      for(int r = 0; r < aGrid->getNumRows(); ++r){
         for(int c = 0; c < aGrid->getNumCol(); ++c){
            //Get the average number of neighbors at this point for past generations
            float numNeighbors = p->getAvgNeighbors(r, c);
            if(numNeighbors < 1.50){
               //Set this Spot to empty
               p->get(p->size() - 1)->at(r, c)->setIsOccupied(false);
            } else if(numNeighbors <= 2.50){
               //Set this spot to whatever it was in the prior generation
               if(p->get(p->size() - 2)->at(r, c)->getIsOccupied()){
                  p->get(p->size() - 1)->at(r, c)->setIsOccupied(true);
               } else{
                  p->get(p->size() - 1)->at(r, c)->setIsOccupied(false);
               }
            } else if(numNeighbors <= 3.50){
               //Set this spot to occupied
               p->get(p->size() - 1)->at(r, c)->setIsOccupied(true);
            } else{
               //Set this spot to empty
               p->get(p->size() - 1)->at(r, c)->setIsOccupied(false);
            }
         }
      }
      isEmpty = p->get(p->size() - 1)->isEmpty();
      
      if(printToFile){
         //Print the latest generation to the file
         p->get(p->size() - 1)->printToFile(fileName, generationNumber);
         if(generationNumber == 1000){
            cout << "Simulation stopped writing to file. Reason: infinite loop" << endl;
            break;
         }
      } else{
         //Print the latest generation to console
         p->get(p->size() - 1)->print();
      }

      //Count the number of neighbors in the new grid generated
      if(countingMethod == "mirror"){
         n->countNeighborsMirror(p->get(p->size() - 1));
      } else if(countingMethod == "doughnut"){
         n->countNeighborsDoughnut(p->get(p->size() - 1));
      } else{
         n->countNeighborsNormal(p->get(p->size() - 1));
      }
      
      //check for stability:
      //    if the new grid and the past three generations are equal, we have a stable map.
      //    end the game
      if(p->get(p->size() - 1)->equals(p->get(p->size() - 2)) &&
         p->get(p->size() - 1)->equals(p->get(p->size() - 3)) &&
         p->get(p->size() - 1)->equals(p->get(p->size() - 4))){
            isStable = true;
            break;
      }
         
      //check for oscillation:
      //    if the new grid is equal to the grid 2 generations before
      //    and the grid 1 generation before is equal to the grid 3 generations before,
      //    we have an oscillating map.
      //    end the game.
      if(p->get(p->size() - 1)->equals(p->get(p->size() - 3)) &&
         p->get(p->size() - 2)->equals(p->get(p->size() - 4))){
            isOscillating = true;
            break;
      }
      //Move the oldest generation (position 0 of PastGenerations' vector)
      //to the end of the vector to modify that grid as the new grid.
      //This enables PastGenerations to hold the new grid and the 3 grids prior to it. 
      p->move0ToEnd();
      
      if(!automatic){
         getline(cin, userInput);
      }
   }
   
   //Let the user know why the game finished
   if(isStable){
      cout << "Finished game of life. Reason: stable map" << endl;
   } else if(isOscillating){
      cout << "Finished game of life. Reason: oscillating map" << endl;
   } else if(isEmpty){
      cout << "Finished game of life. Reason: empty map" << endl;
   } else if(userInput.size() != 0){
      cout << "Finished game of life. Reason: user input ended game" << endl;
   }

   //Garbage collection
   delete aGrid;
   delete bGrid;
   delete cGrid;
   delete dGrid;
   delete n;
   delete p;

   cout << endl << "Press 'enter' to exit program";
   cin.ignore();
   getline(cin, userInput);
   if(userInput.size() == 0){
      return 0;
   }
}
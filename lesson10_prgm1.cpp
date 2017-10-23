/*
Programmer: Ben Diegel
Program: Drink machine
*/

#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;

const int MACHINESIZE = 5; // how many drinks the machine holds

//class delcared to hold all my object variables
class DrinkMachine {
public:
    string drinkName;
    int numInMachine;
    double cost;
};

// prototypes
void displayDrinks(DrinkMachine sodaNames[], DrinkMachine sodaQuantity[], DrinkMachine sodaCost[]);
char userSelection();
void drinkComputation(DrinkMachine sodaNames[], 
                      DrinkMachine (&sodaQuantity)[MACHINESIZE], 
                      DrinkMachine sodaCost[], char userInput);

int main(){
    ifstream sodaNameFile, costFile; //opens 2 files, names and cost
    sodaNameFile.open("SodaNames.txt");
    costFile.open("Cost.txt");
    int index;
    char userInput; // used to pass the users choice to funciton
    DrinkMachine sodaNames[MACHINESIZE]; // declating my class arrays
    DrinkMachine sodaQuantity[MACHINESIZE];
    DrinkMachine sodaCost[MACHINESIZE];
    
    // inits the arrays from the two files
    for(index = 0; index < MACHINESIZE; index++){
        getline(sodaNameFile, sodaNames[index].drinkName);
        sodaQuantity[index].numInMachine = 20;
        costFile >> sodaCost[index].cost;
    }
    sodaNameFile.close();
    costFile.close();

    //runs until the user exits the program within the displayDrinks() function
    while(true){
        system("clear");
        cout << "\n\n";
        displayDrinks(sodaNames, sodaQuantity, sodaCost);
        userInput = userSelection();
        drinkComputation(sodaNames, sodaQuantity, sodaCost, userInput);
    }
    return 0;
}

// displays all the drinks in a table fromat 
void displayDrinks(DrinkMachine sodaNames[], DrinkMachine sodaQuantity[], DrinkMachine sodaCost[]){
    int index;
    cout << "Drinks:\t\tCost:\tNumber in Machine:" << endl;

    for(index = 0; index < MACHINESIZE; index++){
        cout << sodaNames[index].drinkName << "\t"
             << sodaCost[index].cost << "\t\t"
             << sodaQuantity[index].numInMachine << "\n";
    }
    cout << "(E)xit\n\n";
}

// gets the user seleciton with valadation and exit command
char userSelection(){
    char userInput;

    while(true){
        cout << "\nPlease enter the drink that you want, or you may exit.\n>>";
        cin >> userInput;
        userInput = toupper(userInput);
        if(userInput == 'C'|| userInput == 'R' || userInput == 'L' || userInput == 'G' || userInput == 'S'){ // valadation
            break;
        }
        else if(userInput == 'E'){
            exit(0); // exits the program
        }
        else{
            cout << "You did not enter a correct selection.\n";
            continue;
        }
    }
    return userInput; // retruns for use in drinkComputation()
}

//tallys the price and removes the stock
void drinkComputation(DrinkMachine sodaNames[], 
                      DrinkMachine (&sodaQuantity)[MACHINESIZE], 
                      DrinkMachine sodaCost[], char userInput){
    double moneySpent, change;

    if(userInput == 'C'){
        cout << "Please enter the amount of money you want to spend on Cola. Costs: " << sodaCost[0].cost << "\n>>";
        cin >> moneySpent;
        sodaQuantity[0].numInMachine -= 1; // removes 1 from stock
        change = moneySpent - sodaCost[0].cost; // finds the change

        if(change >= 0){ // displays if they have enought
            cout << "You spent " << moneySpent << " your change is " << change << endl
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
        else if(change < 0){ // returns to menu if they dont
            cout << "You do not have enough money for this drink.\n"
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
    }
    else if(userInput == 'R'){
        cout << "Please enter the amount of money you want to spend on Root-Beer. Costs: " << sodaCost[1].cost << "\n>>";
        cin >> moneySpent;
        sodaQuantity[1].numInMachine -= 1;
        change = moneySpent - sodaCost[1].cost;

        if(change >= 0){
            cout << "You spent " << moneySpent << " your change is " << change << endl
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
        else if(change < 0){
            cout << "You do not have enough money for this drink.\n"
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
    }
    else if(userInput == 'L'){
        cout << "Please enter the amount of money you want to spend on Lemon-Lime. Costs: " << sodaCost[2].cost << "\n>>";
        cin >> moneySpent;
        sodaQuantity[2].numInMachine -= 1;
        change = moneySpent - sodaCost[2].cost;

        if(change >= 0){
            cout << "You spent " << moneySpent << " your change is " << change << endl
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
        else if(change < 0){
            cout << "You do not have enough money for this drink.\n"
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
    }
    else if(userInput == 'G'){
        cout << "Please enter the amount of money you want to spend on Grape-Soda. Costs: " << sodaCost[3].cost << "\n>>";
        cin >> moneySpent;
        sodaQuantity[3].numInMachine -= 1;
        change = moneySpent - sodaCost[3].cost;

        if(change >= 0){
            cout << "You spent " << moneySpent << " your change is " << change << endl
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
        else if(change < 0){
            cout << "You do not have enough money for this drink.\n"
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
    }
    else if(userInput == 'S'){
        cout << "Please enter the amount of money you want to spend on Cream-Soda. Costs: " << sodaCost[4].cost << "\n>>";
        cin >> moneySpent;
        sodaQuantity[4].numInMachine -= 1;
        change = moneySpent - sodaCost[4].cost;

        if(change >= 0){
            cout << "You spent " << moneySpent << " your change is " << change << endl
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
        else if(change < 0){
            cout << "You do not have enough money for this drink.\n"
                 << "Press enter to continue." << endl;
            cin.ignore();
            cin.get();
        }
    }
                               
}





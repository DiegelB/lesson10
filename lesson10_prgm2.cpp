/*
Programmer: Ben Diegel
Program: Speaker information tables
*/


#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

class Speaker{
public:
    string name,
           telephone,
           topic;
    double fee;
};

const int SPEAKERSIZE = 10;

// prototypes 
int menu(Speaker speakers[]);
void manageSpeakers(Speaker speakers[],
                    Speaker (&telephone)[SPEAKERSIZE],
                    Speaker (&topic)[SPEAKERSIZE],
                    Speaker (&fee)[SPEAKERSIZE], int choice);



int main(){
    int index, choice;
    Speaker speakers[SPEAKERSIZE];
    Speaker telephone[SPEAKERSIZE];
    Speaker topic[SPEAKERSIZE];
    Speaker fee[SPEAKERSIZE];

    for(index = 0; index < SPEAKERSIZE; index++){
        cout << "Please enter the name for speaker " << index +1 << ".\n>>";
        getline(cin,speakers[index].name);
        fee[index].fee = 0;
    }

    while(true){
        choice = menu(speakers);
        manageSpeakers(speakers, telephone, topic, fee, choice);
    }
    
}

int menu(Speaker speakers[]){
    int index, userInput;
    system("clear");
    cout << "\n\nSpeaker Names:\n";

    for(index = 0; index < SPEAKERSIZE; index++){
        cout << "(" << index + 1 << ")" << speakers[index].name << endl;
    }
    cout << "(0)Exit\n\n";
    
    cout << "Please choose a name to edit their details, or exit.\n>>";
    cin >> userInput;

    return userInput;
}

void manageSpeakers(Speaker speakers[],
                    Speaker (&telephone)[SPEAKERSIZE],
                    Speaker (&topic)[SPEAKERSIZE],
                    Speaker (&fee)[SPEAKERSIZE], int choice){
    int index, userInput;
    
    if(choice == 0){
        exit(0);
    }
    else{
        system("clear");
        cout << "\n\nName: " << speakers[choice-1].name << endl;
        cout << "Telephone Number: " << telephone[choice-1].telephone << endl;
        cout << "Topic: " << topic[choice-1].topic << endl;
        cout << "Fee: " << fee[choice-1].fee << endl;
        cout << "\n(1)To edit settings. (2)Head back to menu.\n>>";
        cin >> userInput;
        if(userInput == 1){
            cout << "\nPlease enter the telephone number. Ex xxx-xxx-xxxx\n>>";
            cin >> telephone[choice-1].telephone;
            cout << "\nPlease enter the topic.\n>>";
            cin >> topic[choice-1].topic;
            cout << "\nPlease enter the fee.\n>>";
            cin >> fee[choice-1].fee;
        }
    }
}
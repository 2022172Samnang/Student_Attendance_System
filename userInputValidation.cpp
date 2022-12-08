#include <iostream>
#include <regex>
using namespace std;

class Validation
{
public:

    bool isValidAttendance(string attendance){
        const regex pattern("[A a P p]");
        return regex_match(attendance, pattern);
    }  

    bool isValidTime(string time){
        const regex pattern("\\d{2}\\:\\d{2}");
        return regex_match(time, pattern);
    }

    bool isValidID(string ID){
        const regex pattern("[0-9]+");
        return regex_match(ID, pattern);
    }    

    bool isValidName(string name){
    const regex pattern("[A-Z a-z]+");
    return regex_match(name, pattern);
    }

    int getCommand(int choice){
        while(true){
            cout<<"Enter your option: ";
            cin>>choice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(cin.gcount()>1){
                continue;
            }
            if(choice<0){
                continue;
            }
            break;
        }
        return choice;
    }

};


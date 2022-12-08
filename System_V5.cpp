#include <iostream>
#include "userInputValidation.cpp"
using namespace std;

enum
{
    ENTER = 1,
    SHOW,
    SEARCH,
    UPDATE,
    DELETE,
    MARK_ATTENDANCE,
    EXIT
};

const int e = 100;
int total = 0;
int choice;
string username;
string password;
char ch;
string courses[e], times[e], PresentCheck[e];

struct Student
{
    string names[e];
    string ID[e];
};

Student students;
Validation validation;

void enter();
void show();
void search();
void update();
void deleteRecord();
bool authentication();
void mainMenu();
void showStudentName();
void markAttendance();
void markAllAsPresent(string time, string course);
bool checkCourseData();
bool checkDuplicatedID(string ID);



int main()
{
    if (authentication() == true)
    {
        system("cls");
        while (true)
        {
            mainMenu();
        }
    }

}

void enter()
{
    string ID;
    cout << "How many students to register?" << endl;
    choice = validation.getCommand(choice);
    if (total == 0)
    {
        for (int i = 0; i < choice; i++)
        {
            cout<< "Enter data of student: " << i + 1 <<endl;
            do{
                cout << "Enter name: ";
                getline(cin, students.names[i]);
            }while(!validation.isValidName(students.names[i]));
            do{
                cout << "Enter Student_ID: ";
                getline(cin, ID);
            }while(!validation.isValidID(ID));
            while(checkDuplicatedID(ID))
            {
                cout<<"This student ID has already taken!!!"<<endl;
                do{
                    cout << "Enter Student_ID: ";
                    getline(cin, ID);
                }while(!validation.isValidID(ID));
            } 
            students.ID[i] = ID;
            cout<<endl;
        }   
        total += choice;
    }
    else
    {
    for (int i = total; i < total + choice; i++)
        {
            cout<< "Enter data of student: " << i + 1 <<endl;
            do{
                cout << "Enter name: ";
                getline(cin, students.names[i]);
            }while(!validation.isValidName(students.names[i]));
            do{
                cout << "Enter Student_ID: ";
                getline(cin, ID);
            }while(!validation.isValidID(ID));
            while(checkDuplicatedID(ID))
            {
                cout<<"This student ID has already taken!!!"<<endl;
                do{
                    cout << "Enter Student_ID: ";
                    getline(cin, ID);
                }while(!validation.isValidID(ID));
            } 
            students.ID[i] = ID;
            cout<<endl;    
        }   
        total = total + choice;
    }
    cout<<"Students have been enrolled successfully!!!"<<endl;
}

void show()
{   
    if(total == 0)
    {
        cout << "No students data registered." << endl;
    }
    else
    {
    for (int i = 0; i < total; i++)
    {
        if(checkCourseData() == true)
        {
            cout << "Data of student: " << i + 1 << endl ;
            cout << "Name: " << students.names[i] << endl;
            cout << "Student_ID: " << students.ID[i] << endl;
            cout << "Course: " << courses[i] << endl;
            cout << "Time: " << times[i] << endl;
            cout << "Present Check: " << PresentCheck[i] << endl << endl;
        }
        else
        {
            cout << "Data of student: " << i + 1 << endl ;
            cout << "Name: " << students.names[i] << endl;
            cout << "Student_ID: " << students.ID[i] << endl <<endl;
        }
    }
  }
}

void search()
{
    if(total == 0)
    {
        cout << "No students data registered." << endl;
    }
    else{
    string Student_ID;
    do{
        cout <<"Enter Student_ID of student which you want to search: ";
        getline(cin, Student_ID);
    }while(!validation.isValidID( Student_ID));
    for (int i = 0; i < total; i++)
    {
        if (Student_ID == students.ID[i])
        {
            if(checkCourseData() == true)
            {
                cout << "Data of student: " << i + 1 << endl ;
                cout << "Name: " << students.names[i] << endl;
                cout << "Student_ID: " << students.ID[i] << endl;
                cout << "Course: " << courses[i] << endl;
                cout << "Time: " << times[i] << endl;
                cout << "Present Check: " << PresentCheck[i] << endl << endl;
            }
            else
            {
                cout << "Data of student: " << i + 1 << endl ;
                cout << "Name: " << students.names[i] << endl;
                cout << "Student_ID: " << students.ID[i] << endl << endl;
            }

        }
    }
  }
}

void update()
{
    if(total == 0)
    {
        cout << "No students data registered." << endl;
    }
    else{
    string Student_ID;
    do{
        cout <<"Enter Student_ID of student which you want to update: ";
        getline(cin, Student_ID);
    }while(!validation.isValidID( Student_ID));
    for (int i = 0; i < total; i++)
    {
        if (Student_ID == students.ID[i])
        {
            if (checkCourseData() == true)
            {
                cout << "Previous data" << endl;
                cout << "Data of student: " << i + 1 << endl ;
                cout << "Name: " << students.names[i] << endl;
                cout << "Student_ID: " << students.ID[i] << endl;
                cout << "Course: " << courses[i] << endl;
                cout << "Time: " << times[i] << endl;
                cout << "Present Check " << PresentCheck[i] << endl << endl;
                cout << "\nEnter new data" << endl;
                do{
                    cout << "Enter name: ";
                    getline(cin, students.names[i]);
                }while(!validation.isValidName(students.names[i]));
                do{
                    cout << "Enter Student_ID: ";
                    getline(cin, students.ID[i]);
                }while(!validation.isValidID(students.ID[i]));
                cout << "Enter course: ";
                getline(cin, courses[i]);
                do{
                    cout << "Enter time (HH:MM): ";
                    getline(cin, times[i]);
                }while(!validation.isValidTime(times[i]));
                do{
                    cout << "Press P for Present or A for Absent ";
                    getline(cin, PresentCheck[i]);
                }while(!validation.isValidAttendance(PresentCheck[i]));
            }
            else
            {
                cout << "Previous data" << endl;
                cout << "Data of student: " << i + 1 << endl ;
                cout << "Name: " << students.names[i] << endl;
                cout << "Student_ID: " << students.ID[i] << endl;
                cout << "\nEnter new data" << endl;
                do{
                    cout << "Enter name: ";
                    getline(cin, students.names[i]);
                }while(!validation.isValidName(students.names[i]));
                do{
                    cout << "Enter Student_ID: ";
                    getline(cin, students.ID[i]);
                }while(!validation.isValidID(students.ID[i]));
            }
        }
    }
  } 
}

void deleteRecord()
{   
    if(total == 0)
    {
        cout << "No students data registered." << endl;
    }
    else
    {
    int opt;
    cout << "Press 1 to delete record by ID"<< endl;
    cout << "Press 2 to delete all records" << endl;
    opt = validation.getCommand(opt);
    if (opt == 1)
    {
        string Student_ID;
        int confirm = 0;
        do{
            cout<<"Please enter Student_ID of student to delete: ";
            getline(cin, Student_ID);
        }while(!validation.isValidID(Student_ID));

        for (int i = 0; i < total; i++)
        {
            if (Student_ID == students.ID[i])
            {
                for (int j=i; j<total; j++)
                {
                    students.names[j] = students.names[j+1];
                    students.ID[j] = students.ID[j+1];
                    courses[j] = courses[j+1];
                    times[j] = times[j+1];
                    PresentCheck[j] = PresentCheck[j+1];
                }
                total = total - 1;
                cout<<"Student has been deleted successfully!"<<endl; 
                confirm++;
            }
        }
        if (confirm == 0) cout<<"Student not found!!!"<<endl;
    }
    else if (opt == 2)
    {
        for (int i=0; i<total; i++)
        {
            students.names[i] = "";
            students.ID[i] = "";
            courses[i] = "";
            times[i] = "";
            PresentCheck[i] = "";
        }
        total = 0;
        cout << "All records deleted" << endl;
    }
  }
}

bool authentication() //verify login 
{ 
	while(true){
		cout<<"====== Login Window ======"<<endl;
		cout<<"Enter Username: ";
		cin>>username;
		cout<<"Enter Password: ";
		cin>>password;
		if (username == "admin" && password == "admin@123") {
			break;
			return true;
		}
		else{
			cout<<"Do you want to enter again? (Y or N): ";
			cin>>ch;
			if(ch == 'Y') {
				system("cls");
				continue;
			}
			else break;
			return false;
		}
	}
	
}

void mainMenu()
{ 
    int option;
    cout<<"=====================================================\n";
    cout<<"\tWelcome to student attendance system"<<endl;
    cout<<"=====================================================\n";
    cout << "Press 1 to register student" << endl;
    cout << "Press 2 to show student records" << endl;
    cout << "Press 3 to search record" << endl;
    cout << "Press 4 to update record" << endl;
    cout << "Press 5 to delete record" << endl;
    cout << "Press 6 to mark attendance"<<endl;
    cout << "Press 7 to exit" << endl;
    cout<<"Please enter your option (1 -> 7): ";
    option = validation.getCommand(option);

    switch(option)
    {
        case ENTER: 
            system("cls");
            enter();
            break;
        case SHOW:
            system("cls");
            show();
            break;
        case SEARCH:
            system("cls");
            search();
            break;
        case UPDATE:
            system("cls");
            update();
            break;
        case DELETE:
            system("cls");
            deleteRecord();
            break;
        case MARK_ATTENDANCE:
            system("cls");
            markAttendance();
            break;
        case EXIT:
            exit(0);
            markAttendance();
            break;
        default:
            cout << "Invalid input" << endl;
            break;
        }
}

void showStudentName()
{
    cout<<"======== List of students name ========"<<endl;
    for(int i=0; i<total; i++)
    {
        cout<<"(ID) "<<students.ID[i]<<". "<<students.names[i]<<endl;
    }
    cout<<"======================================="<<endl;
}

void markAttendance()
{   
    string id;
    string course;
    string time;
    int choice;
    showStudentName();
    cout << "Enter course name: ";
    getline(cin, course);
    do{
        cout << "Enter class time (HH:MM): ";
        getline(cin, time);
    }while(!validation.isValidTime(time));
    if(total == 0)
    {
        cout<<"No Students enrolled in!!!"<<endl;
    }
    else
    {
        cout<<"1. Mark attandence by student id"<<endl;
        cout<<"2. Mark all students as present"<<endl;
        cout<<"Please enter your choice: ";
        choice = validation.getCommand(choice);
        if(choice == 1)
        {
            cout<<"PLease enter student id to mark attendance: ";
            cin>>id;
            for (int i = 0; i < total; i++)
            {
                if (id == students.ID[i])
                {
                    do{
                        cout << "Press P for Present or A for Absent: ";
                        cin >> PresentCheck[i];
                    }while(!validation.isValidAttendance(PresentCheck[i]));
                    courses[i] = course;
                    times[i] = time;
                    cout<<students.names[i]<<" has been marked as "<<PresentCheck[i]<<endl;
                }
            }    
        }
        else if(choice == 2)
        {
            markAllAsPresent(time, course);
        }
    }

}

void markAllAsPresent(string time, string course)
{
    for (int i = 0; i < total; i++)
    {
        courses[i] = course;
        times[i] = time;
        PresentCheck[i] = "P";
    }
    cout<<"All students have been marked as present!!!"<<endl;
}

bool checkCourseData()
{
    for (int i=0; i<total; i++)
    {
        if (courses[i] != "")
        {
            return true;
            break;
        }
    }
    return false;
}

bool checkDuplicatedID(string ID)
{
    if(total>=0)
    {
        for(int i=0; i<total + choice; i++)
        {
            if(students.ID[i]==ID && students.ID[0]!="")
            {
                return true;
                break;
            }
        }
        return false;
    }

}

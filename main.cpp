#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int SIZESTULIST = 1000;
const int SIZETUTLIST = 50;

struct studentData // Data structure to store students information.
{
    string username;
    string stuName;
    int lesson;
    int day;
    float startTime;
    float endTime;
    float maxRate;
};

struct tutorData // Structure to store tutor information.
{
    string username;
    string tutName;
    int lesson;
    int day;
    double startTime;
    double endTime;
    double maxRate;
};

enum student_Menu {REQNEW = 1,REPORTS,VIEW_CLASSES,STUDENT_LOGOUT,STUDENT_EXIT};
enum user_Type {STUDENT = 1,TUTOR,ADMIN};
enum main_Menu {REGISTER = 1,LOGIN,MAIN_EXIT};
enum tutor_Menu {NEWLESSON = 1,VIEW_REPORTS,VIEW_LESSON,TUTOR_LOGOUT,TUTOR_EXIT};
enum admin_Menu {ASSIGN = 1,ADMIN_LOGOUT,ADMIN_EXIT};

// Data structures assigned to a global array.
studentData studentList[SIZESTULIST];
tutorData tutorList[SIZETUTLIST];

//Main menu functions
int choosingLoginType();
int choosingLogin();
void logIn(int,string &);
void newRegister(int);
int choosingRegisterType();
//Student Menu functions
void reqNew(string);
int studentMenu();
void assignChoice(int,string);
void viewClasses(string);
void studentBill(string);
//Tutor Menu functions
int tutorMenu();
void assignTutorChoice(int, string);
void addNewLesson(string );
void paySlip(string);
void viewTutorLessons(string);
void paySlip();
//Admin Menu function
void assignAdminChoice(int);
int adminMenu();
void assignClasses(int);


int main()
{
    system("CLS");

    int typeLoginChoice = 0,loginChoice =0,typeRegisterChoice = 0;//variables of the main menu
    string username;

    //main menu functions
    loginChoice = choosingLogin();


    switch(loginChoice)
    {
    case REGISTER:
    {
        typeRegisterChoice = choosingRegisterType();
        if(typeRegisterChoice == STUDENT || typeRegisterChoice == TUTOR )
        {
            newRegister(typeRegisterChoice);
        }
        else
        {
            cout << "\nInvalid user type!\n" << endl;
            system("PAUSE");
            main();
        }
        break;
    }
    case LOGIN:
    {
        typeLoginChoice = choosingLoginType();
        if(typeLoginChoice == STUDENT || typeLoginChoice == TUTOR || typeLoginChoice == ADMIN)//checking for the user type
        {
            logIn(typeLoginChoice,username);
        }
        else
        {
            cout << "\nInvalid user type!\n" << endl;
            system("PAUSE");
            main();
        }
        break;
    }
    case MAIN_EXIT:
    {
        exit(1);
        break;
    }
    default:
    {
        cout << "\nInvalid choice!\n" << endl;
        system("PAUSE");
        main();
    }
    }

    return 0;
}

///////////////////////////Main Menu Functions////////////////////////////////

int choosingLoginType()
{
    system("CLS");

    int choice = 0;
    cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
         << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)<< char(205) << char(205) << char(205)
         << char(205) << char(205)  << char(187)<< endl;
    cout  << char(186) << "   1)Student        " << char(186) << endl;
    cout << char(186) <<"   2)Tutor          " << char(186) << endl;
    cout << char(186) <<"   3)Administrator  "  << char(186) << endl;
    cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
         << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)<< char(205) << char(205) << char(205)
         << char(205) << char(205)<< char(188)<< endl;
    cout << "Enter your choice : ";
    cin >> choice;

    return choice;
}

int choosingRegisterType()
{
    system("CLS");

    int choice = 0;

    cout << setw(25) << "  1)Student \n  2) Tutor \n  3)Administrator \nEnter your choice : ";
    cin >> choice;

    return choice;
}
int choosingLogin()
{
    system("CLS");

    int choice = 0 ;
    cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
         << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)<< char(205) << char(205) << char(205)
         << char(205) << char(205)  << char(187)<< endl;

    cout<<char(186) << "    ABC ACADEMY     "<< char(186)  << endl;
    cout << char(186) <<"                    " << char(186)  << endl;
    cout <<char(186) <<"    1)Register " << "     " << char(186) <<endl;
    cout <<char(186) <<"    2)Login" << "\t     " << char(186)<< endl;
    cout <<char(186) <<"    3)Exit" << "\t     " << char(186)<< endl ;
    cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)
         << char(205) << char(205) << char(205) << char(205) << char(205) << char(205) << char(205)<< char(205) << char(205) << char(205)
         << char(205) << char(205)<< char(188)<< endl;
    cout <<"Enter your choice :";
    cin >> choice;

    return choice;
}


void logIn(int typeChoice, string &username) //log in function
{
    int tutorChoice = 0,studentChoice = 0,adminChoice = 0;
    system("CLS");

    bool found = false;
    string password,uName,pw;

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    if(typeChoice == 1)
    {
        ifstream studentFile;
        studentFile.open("studentLogin.txt");

        while(!studentFile.eof() && !found)
        {
            studentFile >> uName >> pw ;
            if(username == uName && password == pw)
            {
                found = true;
            }
        }
        studentFile.close();
        if(found)
        {
            cout << "\nWelcome "<< username << '\n' << endl;
            system("PAUSE");
            studentChoice = studentMenu();
            assignChoice(studentChoice,username);
        }
        else

        {
            cout << "\nUsername or password incorrect!\n" << endl;
            system("PAUSE");
            logIn(typeChoice,username);
        }
    }



    else if(typeChoice == 2)
    {
        ifstream tutorFile;
        tutorFile.open("tutorLogin.txt");

        while(!tutorFile.eof() && !found)
        {
            tutorFile >> uName >> pw ;
            if(username == uName && password == pw)
            {
                found = true;
            }
        }
        tutorFile.close();
        if(found)
        {
            cout << "\nWelcome "<< username << '\n' << endl;
            system("PAUSE");
            tutorChoice = tutorMenu();
            assignTutorChoice(tutorChoice,username);
        }
        else
        {
            cout << "\nUsername or password incorrect!\n" << endl;
            system("PAUSE");
            logIn(typeChoice,username);
        }
    }


    else if(typeChoice == 3)
    {
        ifstream adminFile;
        adminFile.open("adminLogin.txt");

        while(!adminFile.eof() && !found)
        {
            adminFile >> uName >> pw ;
            if(username == uName && password == pw)
            {
                found = true;
            }
        }
        adminFile.close();
        if(found)
        {
            cout << "\nWelcome "<< username << '\n' << endl;
            system("PAUSE");

            adminChoice = adminMenu();
            assignAdminChoice(adminChoice);
        }
        else
        {
            cout << "\nUsername or password incorrect!\n" << endl;
            system("PAUSE");
            logIn(typeChoice,username);
        }
    }
}

void newRegister(int typeChoice) //Function to get and store data for new users.
{
    system("CLS");

    string username,password;
    string studentUsername[SIZESTULIST][2];
    string tutorUsername[SIZETUTLIST][2];
    int i = 0, j=0;

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    ifstream studentUsernameCheck;
    studentUsernameCheck.open("studentLogin.txt");
    ifstream tutorUsernameCheck;
    tutorUsernameCheck.open("tutorLogin.txt");

    while(!studentUsernameCheck.eof())
    {
        studentUsernameCheck >> studentUsername[i][i] >> studentUsername[i][i+1];
        if(username == studentUsername[i][i])
        {
            cout << "This username is already in use! Try again." << endl << endl;
            system("PAUSE");
            newRegister(typeChoice);
        }
    }
    studentUsernameCheck.close();

    while(!tutorUsernameCheck.eof())
    {
        tutorUsernameCheck >> tutorUsername[j][j] >> tutorUsername[j][j+1];
        if(username == tutorUsername[j][j])
        {
            cout << "This username is already in use! Try again." << endl << endl;
            system("PAUSE");
            newRegister(typeChoice);
        }
    }

    if(typeChoice == 1) // Register for students
    {
        ofstream studentFile;
        studentFile.open("studentLogin.txt",ios::app);

        studentFile << username << '\t' << password << endl;

        studentFile.close();

        cout << "\nSuccessfully registered!\n" << endl ;
        system("PAUSE");

        main();
    }

    else if(typeChoice == 2) // Register for tutors
    {
        ofstream tutorFile;
        tutorFile.open("tutorLogin.txt",ios::app);

        tutorFile << username << '\t' << password << endl;

        tutorFile.close();

        cout << "\nSuccessfully registered!\n" << endl ;
        system("PAUSE");

        main();
    }
    else if(typeChoice = 3)
    {
        cout << "You cannot register as an administrator! If you are already an administrator please login.";
        system("PAUSE");
        main();
    }
    else
    {
        cout << "Invalid choice!";
    }
}


///////////////////////////Student Functions////////////////////////////////
int studentMenu() // Menu for students
{
    system("CLS");
    int studentChoice = 0;
    cout << "1)Request a new Lesson \n2)Reports \n3)View Classes \n4)Log Out \n5)Exit" << endl;
    cout << "Enter your choice : ";
    cin >> studentChoice;
    return studentChoice;
}

void assignChoice(int studentChoice,string username) // According to the user's choice student will be guided to one of the options in them student menu.
{
    switch(studentChoice)
    {
    case REQNEW :
    {
        reqNew(username);
        break;
    }
    case REPORTS:
    {
        studentBill(username);
        break;
    }
    case VIEW_CLASSES:
    {
        viewClasses(username);
        break;
    }
    case STUDENT_LOGOUT:
    {
        main();
        break;
    }
    case STUDENT_EXIT:
    {
        exit(1);
        break;
    }
    default:
    {
        cout << "Invalid Input";
    }
    }
}

void reqNew(string uname) // Function to add a new request
{
    system("CLS");
    int lessonDay = 0;
    float startingTime = 0;
    float endingTime = 0;
    float maximumRate = 0;
    char newReq = 0;
    string studentName;
    int studentLesson;



    int i =0;
    while(i>=0) // If the user needs to add more than one request a loop is used.
    {
        system("CLS");

        cout << "Name : ";
        cin >> studentName;
        cout << "1)Mathematics \n2)Physics \n3)Chemistry \n4)Biology \n5)English \n6)Music \nLesson : ";
        cin >> studentLesson;
        cout << "1)Sunday \n2)Monday \n3)Tuesday \n4)Wednesday \n5)Thursday \n6)Friday \n7)Saturday \nEnter the number of the day for the lesson: ";
        cin >> lessonDay;
        cout << "Time period for the lesson (Enter the time in 24h format. ex:- 2.30p.m. = 14.30),\n Starting Time : ";
        cin >> startingTime;
        cout << " Finishing Time : ";
        cin >> endingTime;
        cout << "Maximum rate willing to pay for the lesson : Rs.";
        cin >> maximumRate;

        //Assigning the user given data to the above made data structure.
        studentList[i].username = uname;
        studentList[i].stuName = studentName;
        studentList[i].lesson = studentLesson;
        studentList[i].day = lessonDay;
        studentList[i].startTime = startingTime;
        studentList[i].endTime = endingTime;
        studentList[i].maxRate = maximumRate;

        ofstream studentRequest;

        studentRequest.open("studentDetails.txt",ios::app);

        studentRequest << studentList[i].username << "\t" << studentList[i].stuName << "\t" << studentList[i].lesson << "\t" << studentList[i].day << "\t"
                       << studentList[i].startTime << "\t" << studentList[i].endTime <<"\t" << studentList[i].maxRate << endl;



        studentRequest.close();

        cout << "Do you want to add another request(Y/N): "; //Letting the user to add another request if needed.
        cin >> newReq;

        if(newReq == 'Y' || newReq == 'y')
        {
            i=i++;
        }
        else if(newReq == 'N' || newReq == 'n')
        {
            i=-1;
            studentMenu();
        }
        else
        {
            cout << "Invalid input!" << endl;
            i=-1;
            studentMenu();
        }
    }
}

void viewClasses(string username)
{
    system("CLS");
    int i = 0;
    ifstream studentClasses;
    studentClasses.open("assignedClasses.txt");

    while(!studentClasses.eof())
    {
        studentClasses >> studentList[i].username >> studentList[i].stuName >> tutorList[i].username >> tutorList[i].tutName >>
                       studentList[i].lesson >> studentList[i].day >> studentList[i].startTime >> studentList[i].endTime >> tutorList[i].maxRate;
        i++;
    }


    for(int j =0; j<i; j++)
    {
        if(username == studentList[j].username)
        {
            cout << "Tutor Name : " << tutorList[j].tutName << endl;
            if(studentList[j].lesson == 1)
            {
                cout << "Subject : " << "Mathematics" << endl;
            }
            else if(studentList[j].lesson == 2)
            {
                cout << "Subject : " << "Physics" << endl;
            }
            else if(studentList[j].lesson == 3)
            {
                cout << "Subject : " << "Chemistry" << endl;
            }
            else if(studentList[j].lesson == 4)
            {
                cout << "Subject : " << "Biology" << endl;
            }
            else if(studentList[j].lesson == 5)
            {
                cout << "Subject : " << "English" << endl;
            }
            else if(studentList[j].lesson == 6)
            {
                cout << "Subject : " << "Music" << endl;
            }
            cout << "Time : " << studentList[j].startTime << " to " << studentList[j].endTime << endl;
            cout << "Rate : " << tutorList[j].maxRate << endl;

            j = i;
            system("PAUSE");

        }
        else
        {
            cout << "A tutor haven't been assigned yet!";
            system("PAUSE");
            j = i;
        }
    }
    studentClasses.close();
    studentMenu();
}

void studentBill(string username)
{
    system("CLS");
    int i = 0;
    double endTime = 0;
    double startTime = 0;
    double rate = 0;
    double total = 0;
    ifstream studentFile;
    studentFile.open("assignedClasses.txt");

    while(!studentFile.eof())
    {
        studentFile >> studentList[i].username >> studentList[i].stuName >> tutorList[i].username >> tutorList[i].tutName >>
                    studentList[i].lesson >> studentList[i].day >> studentList[i].startTime >> studentList[i].endTime >> tutorList[i].maxRate;
        i++;
    }
    studentFile.close();

    for(int j =0; j<i; j++)
    {
        if(username == studentList[j].username)
        {
            cout.setf(ios::right);
            cout << setw(40) << "Student Bill" << endl;
            cout << "Student Name : " << studentList[j].stuName << endl;
            if(studentList[j].lesson == 1)
            {
                cout << "Subject : " << "Mathematics" << endl;
            }
            else if(studentList[j].lesson == 2)
            {
                cout << "Subject : " << "Physics" << endl;
            }
            else if(studentList[j].lesson == 3)
            {
                cout << "Subject : " << "Chemistry" << endl;
            }
            else if(studentList[j].lesson == 4)
            {
                cout << "Subject : " << "Biology" << endl;
            }
            else if(studentList[j].lesson == 5)
            {
                cout << "Subject : " << "English" << endl;
            }
            else if(studentList[j].lesson == 6)
            {
                cout << "Subject : " << "Music" << endl;
            }
            cout << "Time : " << studentList[j].startTime << " to " << studentList[j].endTime << endl;
            cout << "Hourly rate : " << tutorList[j].maxRate << endl;

            endTime = studentList[j].endTime;
            startTime = studentList[j].startTime;
            rate = (tutorList[j].maxRate);
            total = (endTime-startTime)*(rate)*4;
            cout << "Total amount of pay : " << total << endl << endl;
            system("PAUSE");
            j=i;
        }
        else
        {
            cout << "A tutor haven't been assigned yet!";
            system("PAUSE");
            j=i;
        }
    }
    studentMenu();
}

///////////////////////////Tutor Functions////////////////////////////////

int tutorMenu() // First menu for the tutor login.
{
    system("CLS");
    int choice = 0;
    cout << "1)Add Lessons \n2)View Reports \n3)View Classes \n4)Log Out \n5)Exit \nEnter your choice : ";
    cin >> choice;

    return choice;
}

void assignTutorChoice(int choice,string username) //assigning above menu choices to correct functions.
{
    switch(choice)
    {
    case NEWLESSON:
    {
        addNewLesson(username);
        break;
    }
    case VIEW_REPORTS:
    {
        paySlip(username);
        break;
    }
    case VIEW_LESSON:
    {
        viewTutorLessons(username);
        break;
    }
    case TUTOR_LOGOUT:
    {
        main();
        break;
    }
    case TUTOR_EXIT:
    {
        exit(1);
        break;
    }
    default:
    {
        cout << "Invalid input!";
        tutorMenu();
    }
    }
}

void addNewLesson(string username) // tutor adding his lessons.
{
    system("CLS");
    string tutorName;
    int tutorLesson = 0;
    int lessonDay = 0;
    double startingTime = 0;
    double endingTime = 0;
    double maximumRate = 0;
    int i =0;
    char moreChoice = 'a';
    int choice = 0;

    while(i>=0)
    {
        cout << "Name : ";
        cin >> tutorName;
        cout << "1)Mathematics \n2)Physics \n3)Chemistry \n4)Biology \n5)English \n6)Music \nLesson : ";
        cin >> tutorLesson;
        cout << "1)Sunday \n2)Monday \n3)Tuesday \n4)Wednesday \n5)Thursday \n6)Friday \n7)Saturday \nEnter the number of the day for the lesson: ";
        cin >> lessonDay;
        cout << "Available time period,(Enter the time in 24h format. ex:- 2.30p.m. = 14.30),\n Starting Time : ";
        cin >> startingTime;
        cout << " Finishing Time : ";
        cin >> endingTime;
        cout << "Expected hourly rate : Rs.";
        cin >> maximumRate;
        cout << "Do you want to add another lesson(Y/N): " << endl;
        cin >> moreChoice;

        tutorList[i].tutName = tutorName;
        tutorList[i].lesson = tutorLesson;
        tutorList[i].day = lessonDay;
        tutorList[i].startTime = startingTime;
        tutorList[i].endTime = endingTime;
        tutorList[i].maxRate = maximumRate;

        ofstream tutorFile;
        tutorFile.open("tutorDetails.txt",ios::app);

        tutorFile << username << '\t' << tutorList[i].tutName << '\t' << tutorList[i].lesson << '\t' << tutorList[i].day << '\t' <<
                  tutorList[i].startTime << '\t' << tutorList[i].endTime << '\t' << tutorList[i].maxRate;

        tutorFile.close();

        if(moreChoice == 'Y' || moreChoice == 'y')
        {
            i=i++;
        }
        else if(moreChoice == 'N' || moreChoice == 'n')
        {
            i=-2;
        }
        else
        {
            cout << "Invalid input!";
            tutorMenu();
        }
    }
    assignTutorChoice(choice,username);
}

void viewTutorLessons(string username)
{
    system("CLS");
    int i = 0;
    ifstream tutorLessons;
    tutorLessons.open("assignedClasses.txt");

    while(!tutorLessons.eof())
    {
        tutorLessons >> studentList[i].username >> studentList[i].stuName >> tutorList[i].username >> tutorList[i].tutName >>
                     studentList[i].lesson >> studentList[i].day >> studentList[i].startTime >> studentList[i].endTime >> tutorList[i].maxRate;
        i++;
    }


    for(int j =0; j<i; j++)
    {
        if(username == tutorList[j].username)
        {
            cout << "Student Name : " << studentList[j].stuName << endl;
            if(studentList[j].lesson == 1)
            {
                cout << "Subject : " << "Mathematics" << endl;
            }
            else if(studentList[j].lesson == 2)
            {
                cout << "Subject : " << "Physics" << endl;
            }
            else if(studentList[j].lesson == 3)
            {
                cout << "Subject : " << "Chemistry" << endl;
            }
            else if(studentList[j].lesson == 4)
            {
                cout << "Subject : " << "Biology" << endl;
            }
            else if(studentList[j].lesson == 5)
            {
                cout << "Subject : " << "English" << endl;
            }
            else if(studentList[j].lesson == 6)
            {
                cout << "Subject : " << "Music" << endl;
            }
            cout << "Time : " << studentList[j].startTime << " to " << studentList[j].endTime << endl;
            cout << "Rate : " << tutorList[j].maxRate << endl;

            j = i;
            system("PAUSE");

        }
        else
        {
            cout << "A lesson haven't been assigned yet!";
            system("PAUSE");
            j = i;
        }
    }
    tutorLessons.close();
    tutorMenu();
}


void paySlip(string username)
{
    system("CLS");
    int i = 0;
    double total = 0;
    ifstream tutorFile;
    tutorFile.open("assignedClasses.txt");

    while(!tutorFile.eof())
    {
        tutorFile >> studentList[i].username >> studentList[i].stuName >> tutorList[i].username >> tutorList[i].tutName >>
                  studentList[i].lesson >> studentList[i].day >> studentList[i].startTime >> studentList[i].endTime >> tutorList[i].maxRate;
        i++;
    }
    tutorFile.close();

    for(int j =0; j<i; j++)
    {
        if(username == tutorList[j].username)
        {
            cout.setf(ios::right);
            cout << setw(40) << "Tutor Pay slip" << endl;
            cout << "Tutor Name : " << tutorList[j].tutName << endl;
            if(studentList[j].lesson == 1)
            {
                cout << "Subject : " << "Mathematics" << endl;
            }
            else if(studentList[j].lesson == 2)
            {
                cout << "Subject : " << "Physics" << endl;
            }
            else if(studentList[j].lesson == 3)
            {
                cout << "Subject : " << "Chemistry" << endl;
            }
            else if(studentList[j].lesson == 4)
            {
                cout << "Subject : " << "Biology" << endl;
            }
            else if(studentList[j].lesson == 5)
            {
                cout << "Subject : " << "English" << endl;
            }
            else if(studentList[j].lesson == 6)
            {
                cout << "Subject : " << "Music" << endl;
            }
            cout << "Time : " << studentList[j].startTime << " to " << studentList[j].endTime << endl;
            cout << "Rate : " << tutorList[j].maxRate << endl;
            total = (studentList[j].endTime - studentList[j].startTime)*(tutorList[j].maxRate)*4;
            cout << "Total amount of pay : " << total << endl << endl;
            system("PAUSE");
            j=i;
        }
        else
        {
            cout << "A lesson haven't been assigned yet!";
            system("PAUSE");
            j=i;
        }
    }
    tutorMenu();
}

//////////////////////////////Admin Functions/////////////////////////////////////

int adminMenu()
{
    system("CLS");
    int choice = 0;

    cout << "1)Assign classes \n2)Logout \n3)Exit \n Enter your choice: ";
    cin >> choice;

    return choice;
}

void assignAdminChoice(int adminChoice)
{
    switch(adminChoice)
    {
    case ASSIGN :
    {
        assignClasses(adminChoice);
        break;
    }

    case ADMIN_LOGOUT:
    {
        main();
        break;
    }
    case ADMIN_EXIT:
    {
        exit(1);
        break;
    }
    default:
    {
        cout << "Invalid Input";
        system("PAUSE");
        assignAdminChoice(adminChoice);
    }
    }
}

void assignClasses(int adminChoice)
{
    int i =0,j=0;

    ifstream studentDetailsFile;
    studentDetailsFile.open("studentDetails.txt");
    while(!studentDetailsFile.eof())
    {
        studentDetailsFile >> studentList[i].username >> studentList[i].stuName >> studentList[i].lesson >> studentList[i].day >> studentList[i].startTime
                           >> studentList[i].endTime >> studentList[i].maxRate;
        i++;
    }

    studentDetailsFile.close();

    ifstream tutorDetailsFile;
    tutorDetailsFile.open("tutorDetails.txt");
    while(!tutorDetailsFile.eof())
    {
        tutorDetailsFile >> tutorList[j].username >> tutorList[j].tutName >> tutorList[j].lesson >> tutorList[j].day >> tutorList[j].startTime
                         >> tutorList[j].endTime >> tutorList[j].maxRate;
        j++;
    }

    tutorDetailsFile.close();

    ofstream assigningFile;
    assigningFile.open("assignedClasses.txt",ios::app);

    for(int k=0; k<i; k++)
    {
        for(int l=0; l<j; l++)
        {
            if(studentList[k].lesson == tutorList[l].lesson)
            {
                if(studentList[k].day == tutorList[l].day)
                {
                    if(studentList[k].startTime >= tutorList[l].startTime)
                    {
                        if(studentList[k].endTime <= tutorList[l].endTime)
                        {
                            if(studentList[k].maxRate >= tutorList[l].maxRate)
                            {
                                assigningFile << studentList[k].username << '\t' << studentList[k].stuName << '\t' << tutorList[l].username << '\t' <<
                                              tutorList[l].tutName << '\t' << studentList[k].lesson << '\t' << studentList[k].day << '\t' <<
                                              studentList[k].startTime << '\t' <<studentList[k].endTime << '\t' << tutorList[l].maxRate << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    assigningFile.close();

    cout << "Classes successfully assigned!" << endl;
    system("PAUSE");
    adminMenu();

}




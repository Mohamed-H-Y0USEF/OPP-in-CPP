#include "askFmhed.h"
#include <fstream>
void AskFmSystem::run() {
    while (true) {
        int choice = menu();
        if(isLogIN){
            switch (choice) {
                case 1:
                    printQuestToMe();break;
                case 2:
                    printQuestFromMe();break;
                case 3:
                    answerQuest();break;
                case 4:
                    DelQuest();break;
                case 5:
                    AskQuestTo();break;
                case 6:
                    listUsers();break;
                case 7:
                    feedQuest();break;
                case 8:
                    LogOut();break;
                default:
                    return;
            }
        }else
        {
            if(choice == 1)
                Login();
            else
                SignUP();
        }

    }
}

int AskFmSystem::menu() {
    int choice = -1 ;
    while (choice == -1)
    {
        if(isLogIN)
        {
            cout<<endl<<"Menu : " << endl;
            cout<<"\t 1: Print Questions To Me " << endl;
            cout<<"\t 2: Print Questions From Me " << endl;
            cout<<"\t 3: Answer Question " << endl;
            cout<<"\t 4: Delete Question " << endl;
            cout<<"\t 5: Ask Questions To" << endl;
            cout<<"\t 6: List System Users " << endl;
            cout<<"\t 7: Feed " << endl;
            cout<<"\t 8: Logout " << endl;
            cout<<"\t 9: Exit " << endl;
            cout<<"Enter number in range 1 - 9 : " ;
        }else
        {
            cout<<"\t 1: Login"<<endl;
            cout<<"\t 2: Sign UP"<<endl;
            cout<<"Enter number in range 1 - 2 : " ;
        }
        cin>>choice;
        bool validChoice = (choice < 1 || choice > 9 || (!isLogIN && (choice < 1 || choice > 2)));
        if(!validChoice){
            cout<<"ERROR: invalid number ... Try again."<<endl;
            choice = -1;
        }
    }
    return choice;
}

void AskFmSystem::SignUP() {
    user newUser;
    newUser.read();
    newUser.id = generateID();
    //append to file users
    //append to UserList;
    ofstream usersFile("usersInfo" , ios::app);
    if(usersFile.fail()) {
        cout << "ERROR : users file can't open ... tyr Again" << endl;
        return;
    }
    usersFile<<newUser.id<<','<<
         newUser.userName<<','<<
         newUser.passWord<<','<<
         newUser.name<<','<<
         newUser.email<<','<<
         newUser.anonymousQuest;
    UsersList[newUser.userName] = newUser;
    CurUserName = newUser.userName;
    isLogIN = true;
}

int AskFmSystem::generateID() {
    if(UsersList.empty())
        return 1;
    return prev(UsersList.end())->second.id + 1;
}

void AskFmSystem::Login() {
    string name , pass;
    cout<<"Enter userName & password : ";
    cin>>name>>pass;
    while (UsersList[name].passWord != pass)
    {
        cout<<"invalid username or passWord try again"<<endl;
        cin>>name >> pass;
    }
    CurUserName = name;
    isLogIN = true;
}

void user::read() {
    cout<<"Enter user name . (No spaces) :";cin>>userName;
    cout<<"Enter password :";cin>>passWord;
    cout<<"Enter name: " ; cin>>name;
    cout<<"Enter email :"; cin>>email;
    cout<<"Allow anonymous questions? : (0 or 1) " ; cin>>anonymousQuest;
}

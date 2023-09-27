#include <bits/stdc++.h>
using namespace std;

struct user{
    string name , passWord , userName, email;
    int id;
    bool anonymousQuest;
    void read();

};

struct AskFmSystem{
    string CurUserName;
    map<string,user>UsersList;
    int CurUserID;
    bool isLogIN = false;
    void run();
    int menu();
    int generateID();
    void Load();
    void printQuestToMe();
    void printQuestFromMe();
    void answerQuest();
    void DelQuest();
    void AskQuestTo();
    void listUsers();
    void feedQuest();
    void LogOut();
    void Login();
    void SignUP();
};






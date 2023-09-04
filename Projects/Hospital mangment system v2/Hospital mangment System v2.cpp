#include <bits/stdc++.h>

using namespace std;
const int queueSize = 6;
const int Special = 21;

struct hospitalQueue{
    string Names[queueSize];
    bool status[queueSize]{};
    int len , spec;

    hospitalQueue(int spec = -1): len(0) , spec(spec) {};


    bool add(string name , bool st)
    {
        if(st) return addFront(name);
        return addEnd(name);
    }


    bool addEnd(string &name)
    {
        if(len == 6) return false;
        Names[len + 1] = name;
        status[len + 1] = 0;
        len++;
        return true;
    }

    bool addFront(string &name)
    {
        if(len == 6) return false;
        for (int i = len; i >= 1 ; --i)
            swap(Names[i] , Names[i + 1]);

        Names[1] = name;
        status[1] = 1;
        len++;
        return true;
    }

    void GetFront()
    {
        if(len == 0) return cout<<"No patients for now , have rest Dr."<<endl , void();
        cout<<Names[1] << " Pleas go with the Dr. " <<endl;
        for (int i = 2; i <= len ; ++i)
            swap(Names[i] , Names[i - 1]);
        len--;
    }

    void print()
    {
        if(len == 0) return ;
        cout<<"there are " << len << " patients in specialization " << spec << endl;
        for (int i = 1; i <= len ; ++i) {
            cout<<Names[i] << ' ';
            if(status[i])   cout<<"Urgent";
            else cout<<"Normal";
            cout<<endl;
        }
        cout<<endl<<"*******************************************"<<endl;
    }
};



struct HospitalSystem{

    hospitalQueue queue[21];

    HospitalSystem(){
        for (int i = 1; i <= 20 ; ++i)
            queue[i] = hospitalQueue(i);
    }
    void run()
    {
        while(true)
        {
            int x = menu();
            if(x == 1)
                addPatient();
            else if(x == 2)
                printAllPatient();
            else if (x == 3)
                getNextPatient();
            else break;
        }
    }

    int menu()
    {
        int choice = -1;
        while (choice == -1) {
            cout << "\nEnter your choice:\n";
            cout << "1) Add new patient\n";
            cout << "2) Print all patients\n";
            cout << "3) Get next patient\n";
            cout << "4) Exit\n";

            cin >> choice;

            if (!(1 <= choice && choice <= 4)) {
                cout << "Invalid choice. Try again\n";
                choice = -1;	// loop keep working
            }
        }
        return choice;
    }

    void addPatient(){
        int specialization;
        string name  ;
        bool status;

        cout<<"enter specialization , name , status : ";

        cin>>specialization>>name>>status;

        bool alpha = queue[specialization].add(name , status);

        if(!alpha)
            cout<<"Sorry , we can't add more patients for this specialization."<<endl;
    }
    void getNextPatient(){
        cout<<"Enter Specialization : " ;
        int spec;cin>>spec;
        queue[spec].GetFront();
    }
    void printAllPatient(){
        for (int i = 1; i <= 20 ; ++i) {
            queue[i].print();
        }
    }
};

int main() {

    HospitalSystem system;
    system.run();
    return 0;
}

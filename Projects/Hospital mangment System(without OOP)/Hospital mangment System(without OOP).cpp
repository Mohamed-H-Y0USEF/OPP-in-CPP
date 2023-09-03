#include <bits/stdc++.h>

using namespace std;
const int queueSize = 6;
const int Special = 21;
string names[Special][queueSize];
int cnt[Special] , status[Special][queueSize];
void Shift_right(int special)
{
    int end = cnt[special];
    for (int i = end; i >= 1 ; --i)
        swap(names[special][i] , names[special][i + 1]);
}
void Shift_lift(int special)
{
    for (int i = 2; i <= 5 ; ++i)
        swap(names[special][i] , names[special][i - 1]);
}
void addNewPatient()
{
    int specialization;
    string name  ;
    bool IsUrgent;

    cout<<"enter specialization , name , status : ";

    cin>>specialization>>name>>IsUrgent;

    int len = cnt[specialization];
    if(len == 5)
    {
        cout<<"Sorry , we can't add more patients for this specialization."<<endl;
        return;
    }
     if(IsUrgent)
    {
        Shift_right(specialization);
        names[specialization][1] = name;
        status[specialization][1] = IsUrgent;
    }else
    {
        names[specialization][len + 1] = name;
        status[specialization][len + 1] = IsUrgent;
    }
    cnt[specialization]++;
}
void printSpecial(int special)
{
    int len = cnt[special];
    if(len == 0) return;
    cout<<"there are " << len << " patients in specialization  " << special<<endl;
    for (int i = 1; i <= len ; ++i) {
        cout<<names[special][i] << " " ;
        cout<<(status[special][i] ? "Urgent" : "Normal")<<endl;
    }
}
void printAllPatient()
{
    for (int i = 1; i <= 20 ; ++i)
        printSpecial(i);
}
void getNextPatient()
{
    int specialization;
    cout<<"enter int specialization : ";

    cin>>specialization;

    int len = cnt[specialization];
    if(len == 0)
        return cout<<"No patients at moment , have rest , Dr. "<<endl,void();

    cout<<names[specialization][1] << " please go with the Dr."<<endl;
    Shift_lift(specialization);
    cnt[specialization]--;
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
int main() {


    while (1)
    {
        int x = menu();
        if(x == 1)
            addNewPatient();
        else if(x == 2)
         printAllPatient();
        else if(x == 3)
            getNextPatient();
        else return 0;
    }
}

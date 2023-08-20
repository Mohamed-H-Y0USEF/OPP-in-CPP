#include<bits/stdc++.h>
using namespace std;
class invic{
private:
    string name;
    int id , price , quntity;
public:
    void setName(const string &name);

    void setId(int id);

    void setPrice(int price);
    invic(){}
    invic(const string &name, int id, int price, int quntity);

    void setQuntity(int quntity);

    const string &getName() const;

    int getId() const;

    int getPrice() const;

    int getQuntity() const;

    int getTotal() const;
    void print();
    string to_String();
};

void invic::setName(const string &name) {
    invic::name = name;
}

void invic::setId(int id) {
    invic::id = id;
}

void invic::setPrice(int price) {
    invic::price = price;
}

void invic::setQuntity(int quntity) {
    invic::quntity = quntity;
}

const string &invic::getName() const {
    return name;
}

int invic::getId() const {
    return id;
}

int invic::getPrice() const {
    return price;
}

int invic::getQuntity() const {
    return quntity;
}
int invic :: getTotal() const{
    return this->price * this->quntity;
}
void invic ::print() {
    cout<<"Name :" << name<<endl;
    cout<<"ID : " << id << endl;
    cout<<"Quntity : " << quntity << " , Price : " << price<<endl;
    cout<<"Toatal : " << this->getTotal() << endl;
}
string invic::to_String() {
    ostringstream ret;
    ret<<getName()<<','<<getId()<<',' <<getQuntity()<<',' <<getPrice()<<','<< getTotal();
    return ret.str();
}

invic::invic(const string &name, int id, int price, int quntity = 1) : name(name), id(id), price(price), quntity(quntity) {}

int main() {
    invic invOne("MO" , 12 , 5 , 2);

    cout<<invOne.to_String();
    return 0;
}

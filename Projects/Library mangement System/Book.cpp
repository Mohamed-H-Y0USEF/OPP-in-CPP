#include "System.h"

Book::Book() :name("") , id(0) , quantity(0) , Borrowed(0) {
}
bool Book::isPrefix(string &prefix) {
    if(name.size() < prefix.size())return false;
    for (int i = 0; i < prefix.size(); ++i)
        if(name[i] != prefix[i])return false;
    return true;
}

bool Book::CanBorrow() {
    if(quantity - Borrowed == 0) return false;
    Borrowed++;
    return true;
}

void Book::returnCopy() {
    assert(Borrowed > 0);
    --Borrowed;
}

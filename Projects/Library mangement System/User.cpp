#include "LibrarySystem.h"
int User::isBorrowed(int bookId) {
    for (int i = 1; i <= pos ; ++i)
        if(borrowedBooksIds[i] == bookId) return i;
    return -1;
}

void User::BorrowBook(int BookId) {
    borrowedBooksIds[++pos] = BookId;
}

void User::SiftLift(int idx) {

    for (int i = idx; i <= pos ; ++i)
        swap(borrowedBooksIds[idx] , borrowedBooksIds[idx + 1]);
    pos--;
}

void User::returnBook(int bookId) {
    int idx = isBorrowed(bookId);
    if(idx != -1)
        SiftLift(idx);
    else
        cout << "User " << Name << " never borrowed book id " << bookId << endl;
}

void User::print() {
    cout<<"User : " << Name << " id : " << id << " borrowed books ids : ";
    for (int i = 1; i <= pos ; ++i) cout<<borrowedBooksIds[i] << ' ';
    cout<<endl;
}

User::User(): pos(0) , id(0){

}


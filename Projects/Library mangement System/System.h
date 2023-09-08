#include<bits/stdc++.h>
using namespace std;
const int N = 200 + 5;


struct User{
    string Name;
    int id , pos;
    int borrowedBooksIds[N];
    User();
    void BorrowBook(int BookId);
    int isBorrowed(int bookId);
    void returnBook(int bookId);
    void SiftLift(int idx);
    void print();
};


struct Book{
    int id ;
    int quantity , Borrowed ;
    string name;
    Book();
    bool isPrefix(string &prefix);
    void returnCopy();
    bool CanBorrow();
};


struct System{
    Book books[N];
    User users[N];
    int len, len2;
    System() : len(0) , len2(0){};


    void run();
    int  menu();
    void addBook();
    void searchBooks_byPrefix();
    void print_who_borrowed_book_by_name();
    void print_library_by_id();
    void print_library_by_name();
    void add_user();
    void Borrow_book();
    void Return_book();
    void print_Users();




    bool read_user_name_and_book_name(int &userIdx , int &bookIdx , int trials = 3);
    int find_user_idx_by_name(string &name);
    int find_book_idx_by_name(string &name);


    int GetIdByName(string &str);
    static bool sortByName(Book &b1 , Book &b2);
    static bool sortById(Book &b1 , Book &b2);



};
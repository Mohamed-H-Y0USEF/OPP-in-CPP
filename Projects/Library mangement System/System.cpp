#include "System.h"

void System::run() {

    while (true)
    {
        int choice = menu();
        if(choice == 1)
            addBook();
        else if(choice == 2)
            searchBooks_byPrefix();
        else if(choice == 3)
            print_who_borrowed_book_by_name();
        else if(choice == 4)
            print_library_by_id();
        else if(choice == 5)
            print_library_by_name();
        else if(choice == 6)
            add_user();
        else if(choice == 7)
            Borrow_book();
        else if(choice == 8)
            Return_book();
        else if(choice == 9)
            print_Users();
        else break;
    }
}

int System::menu() {
    int choice = -1;
    while (choice < 1 || choice > 10)
    {
        cout<<endl<<"Library Menu : "<<endl;
        cout<<"1) "<<"Add Book."<<endl;
        cout<<"2) "<<"Search books by prefix."<<endl;
        cout<<"3) "<<"Print who borrowed book by name."<<endl;
        cout<<"4) "<<"Print library by id."<<endl;
        cout<<"5) "<<"Print library by name."<<endl;
        cout<<"6) "<<"Add user."<<endl;
        cout<<"7) "<<"User borrow book"<<endl;
        cout<<"8) "<<"User return book"<<endl;
        cout<<"9) "<<"Print users"<<endl;
        cout<<"10) "<<"Exit"<<endl;
        cout<<"Enter your menu choice [1 - 10] : ";
        cin>>choice;
        if(choice < 1 || choice > 10)
            cout<<endl<<"Try again .";
    }
    return choice;
}

void System::addBook() {
    Book newBook;
    cout<<"Enter ID , Name(without spaces) , Quantity : ";
    cin>>newBook.id >> newBook.name >> newBook.quantity;
    books[++len] = newBook;
}


void System::searchBooks_byPrefix() {
    string prefix;
    cout<<"Enter book name prefix : ";
    cin>>prefix;
    for (int i = 1; i <= len ; ++i)
        if(books[i].isPrefix(prefix))
            cout<<books[i].name<<endl;

}

void System::print_who_borrowed_book_by_name() {
    string bookName;
    cout<<"Enter Book name : ";
    cin>>bookName;
    int BookId = GetIdByName(bookName);
    for (int i = 1; i <= len2 ; ++i)
        if(users[i].isBorrowed(BookId) != -1)
            cout<<users[i].Name<<endl;

}

int System::GetIdByName(string &str) {
    for (int i = 1; i <= len; ++i)
     if(books[i].name == str) return books[i].id;
}

bool System::sortByName(Book &b1, Book &b2) {
    return b1.name < b2.name;
}

bool System::sortById(Book &b1, Book &b2){
    return b1.id < b2.id;
}

void System::print_library_by_id() {
    sort(books + 1 , books + len , sortById);
    for (int i = 1; i <= len ; ++i)
        cout<<books[i].id << ' ' << books[i].name << ' ' << books[i].quantity << ' ' << "Borrowed : " << books[i].Borrowed<<endl;
}

void System::print_library_by_name() {
    sort(books + 1 , books + len , sortByName);
    for (int i = 1; i <= len ; ++i)
        cout<<books[i].name << ' ' << books[i].id << ' ' << books[i].quantity << ' ' << "Borrowed : " << books[i].Borrowed<<endl;
}

void System::add_user() {
    User newUser;
    cout<<"Enter name , ID : ";
    cin>>newUser.Name >> newUser.id;
    users[++len2] = newUser;
}

void System::Borrow_book() {
   int idxBook , idxUser;
   if(!read_user_name_and_book_name(idxUser , idxBook))
       return;

    //int user_id = users[idxUser].id;
    int book_id = books[idxBook].id;

    if (!books[idxBook].CanBorrow())
        cout << "No more copies available right now\n";
    else
        users[idxUser].BorrowBook(book_id);
}

void System::Return_book() {
    int userIdx , bookIdx;

   if(!read_user_name_and_book_name(userIdx , bookIdx))
     return;
   int bookId = books[bookIdx].id;
   books[bookIdx].returnCopy();
   users[userIdx].returnBook(bookId);
}

void System::print_Users() {
    for (int i = 1; i <= len2 ; ++i)
        users[i].print();
}

bool System::read_user_name_and_book_name(int &userIdx, int &bookIdx, int trials) {
    string user_name;
    string book_name;

    while (trials--) {
        cout << "Enter user name and book name: ";
        cin >> user_name >> book_name;

        userIdx = find_user_idx_by_name(user_name);

        if (userIdx == -1) {
            cout << "Invalid user name. Try again\n";
            continue;
        }
        bookIdx = find_book_idx_by_name(book_name);

        if (bookIdx == -1) {
            cout << "Invalid book name. Try again\n";
            continue;
        }
        return true;
    }
    cout << "You did several trials! Try later.";
    return false;
}

int System::find_user_idx_by_name(string &name) {
    for (int i = 1; i <= len ; ++i)
        if(users[i].Name == name)return i;
    return -1;
}

int System::find_book_idx_by_name(string &name) {
    for (int i = 1; i <= len ; ++i)
        if(books[i].name == name)return i;
    return -1;
}




# Library Management System Documentation

## Introduction
This document provides an overview and documentation for a simple Library Management System implemented in C++. The system allows users to perform various library-related tasks, such as adding books, searching for books by name prefix, printing user information, borrowing and returning books, and more.

## Project Structure
- **library_System.h**: Header file containing class declarations and function prototypes.
- **library_System.cpp**: Implementation of the System class and its member functions.
- **User.cpp**: Implementation of the User class and its member functions.
- **Book.cpp**: Implementation of the Book class and its member functions.
- **main.cpp**: The main entry point for the program.

## Classes and Functions

### System Class
- `System::run()`: Main control loop for the Library Management System.
- `System::menu()`: Displays the menu and handles user choice.
- `System::addBook()`: Allows users to add a new book to the library.
- `System::searchBooks_byPrefix()`: Searches for books by name prefix.
- `System::print_who_borrowed_book_by_name()`: Prints users who borrowed a book by its name.
- `System::GetIdByName(string &str)`: Retrieves the book ID by its name.
- `System::sortByName(Book &b1, Book &b2)`: Comparator for sorting books by name.
- `System::sortById(Book &b1, Book &b2)`: Comparator for sorting books by ID.
- `System::print_library_by_id()`: Prints the library's book list sorted by ID.
- `System::print_library_by_name()`: Prints the library's book list sorted by name.
- `System::add_user()`: Allows users to add a new library user.
- `System::Borrow_book()`: Handles the process of borrowing a book.
- `System::Return_book()`: Handles the process of returning a book.
- `System::print_Users()`: Prints the list of library users.
- `System::read_user_name_and_book_name(int &userIdx, int &bookIdx, int trials)`: Reads user and book names and handles invalid inputs.
- `System::find_user_idx_by_name(string &name)`: Finds a user's index by their name.
- `System::find_book_idx_by_name(string &name)`: Finds a book's index by its name.

### User Class
- `User::User()`: Constructor for the User class.
- `User::isBorrowed(int bookId)`: Checks if a user has borrowed a book.
- `User::BorrowBook(int BookId)`: Records that a user has borrowed a book.
- `User::SiftLift(int idx)`: Helper function for returning a book.
- `User::returnBook(int bookId)`: Handles the process of returning a book.
- `User::print()`: Prints user information.

### Book Class
- `Book::Book()`: Constructor for the Book class.
- `Book::isPrefix(string &prefix)`: Checks if a string is a prefix of the book's name.
- `Book::CanBorrow()`: Checks if a book can be borrowed.
- `Book::returnCopy()`: Decreases the count of borrowed copies.

## Usage
To compile and run the program, ensure all source files are in the same directory and use a C++ compiler.

## Conclusion
This Library Management System provides basic functionality for managing books and users in a library. Users can add books, search for books, borrow and return books, and manage user records. Further improvements and features can be added to enhance the system's capabilities and usability.

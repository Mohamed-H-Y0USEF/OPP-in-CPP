## What is it ?
A copy constructor is a member function that initializes an object using another object of the same class.

---

### Types of Copy Constructors :
1. Default Copy Constructor
    * Compiler provid it.
1. User-defined copy constructor
    * A user-defined copy constructor is generally needed when an object owns pointers or non-shareable references,
     such as to a file, in which case a destructor and an assignment operator should also be written .

---

### When is the copy constructor called? 
* When an object of the class is returned by value. 
* When an object of the class is passed (to a function) by value as an argument. 
* When an object is constructed based on another object of the same class. 
* When the compiler generates a temporary object.

---

### When is a user-defined copy constructor needed ?

 We need to define our own copy constructor only if an object has pointers or any runtime allocation of the resource like a file handle, a network connection, etc.

 The default constructor does only <mark>shallow copy</mark>. 
 that is mean the objects point to the same location.

 <mark>Deep copy</mark> is possible only with a **user-defined copy constructor**. In a user-defined copy constructor, we make sure that pointers (or references) of copied objects point to new memory locations.  

---

### What is happening in user-defined copy constructor when pass object by Value ?

infinite recursion .<br>
coz Copy constructor itself is a function. So if we pass an argument by value in a copy constructor, a call to copy constructor 
	would be made to call copy constructor ==> infinite recursion
	Therefore compiler doesn’t allow parameters to be passed by value.
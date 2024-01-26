
# Initializer list
## What is it :
This type is used to access the
values in a C++ initialization list,
which is a list of elements of type
const T.
in simple why this list will recive elements sended in initializ object liks this obj{x , y , z};
``` c++
class adder{
private:
  int total_sum;
Public:
  Adder(){}
  //element send in init is here in lst
  Adder(const initializer_list<int> &lst ){
    Add(lst);
  }

 int Add(const initializer_list<int> &lst){
  int sum = 0;
  for(auto &val : lst)
      sum += val;
  total_sum += sum;
  return total_sum;
  }
};


int main(){
  Adder adder{1 , 2 , 3} // this element will recived in lst
return 0;
}
```
---
## Priorities 
``` c++
struct A{
  int x , y;
};

struct B{
  int x, y;
  B(int x , int y) : x{x} , y{y} {}
};

struct C{
  int x , y;
  C(int x , int y) : x{x} , y{y} {}
  C(const initializer_list<int> &lst){
      x = *(lst.begin());
      y = *(lst.end());
  }
};

int main(){
  A a  {1 , 3};    // Aggregate initialization
  B b  {2 , 9};    // Regulat constructor
  C c1 {3 , 7};    // Initializer_list
  C c2 (3 , 7);    // Regulat constructor
}
```
### Priority:
1. initializer_list
2. Regular
3. aggregate
<br>
aggregate : Aggregate initialization is a special case of list initialization. It is used when initializing arrays or simple structs (all-members-public, no user-provided c'tors) 

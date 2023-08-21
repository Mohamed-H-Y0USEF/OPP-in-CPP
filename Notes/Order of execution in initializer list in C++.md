## code 1 :
```c++
#include <iostream>
using namespace std;
  
class MyClass {
private:
    // Declared first
    int b;
  
    // Declared Second
    int a;
  
public:
    MyClass(int value) : b(value), a(b * 2)
    {
        cout << b << " " << a;
    }
};
  
int main()
{
    MyClass obj(10);
    return 0;
}

```

### Output :

```
10 20
```
---

## code 2 :

```c++
#include <iostream>
using namespace std;
  
class MyClass {
private:
    // Declared first
    int a;
  
    // Declared Second
    int b;
  
public:
    MyClass(int value) : b(value), a(b * 2)
    {
        cout << b << " " << a;
    }
};
  
int main()
{
    MyClass obj(10);
    return 0;
}

```

### Output :

```
10 546520
```

## Conclusion :

Both the outputs are different because the **<mark> execution takes place according to the order of declaration </mark>** :

* In the first program, b is declared first, so b is assigned the value of 10 and then a is declared, later a is assigned b*2. So, the output is 10 20.
* In the second program, a is declared first and then b.  So, first, a is assigned b*2, but b is not initialized yet. So, some garbage value is assigned to a. Later b is assigned the value of 10.
 


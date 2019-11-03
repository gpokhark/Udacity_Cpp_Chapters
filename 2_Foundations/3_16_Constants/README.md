# Constants
In [A Tour of C++, Bjarne Stroustrup](http://www.stroustrup.com/Tour.html) writes:

C++ supports two notions of immutability:

* `const`: meaning roughly " I promise not to change this value."...The compiler enforces the promise made by `const`....
* `constexpr`: meaning roughly "to be evaluated at compile time." This is used primarily to specify constants...

## Constants

This example highlights how to use `const` to promise not to modify a variable, even though the variable can only be evaluated at run time.

The example also show how to use `constexpr` to guarantee that a variable can be evaluated at compile time.


```c++
#include <iostream>

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    const int j = i * 2;  // "j can only be evaluated at run time."
                          // "But I promise not to change it after it is initialized."
    
    constexpr int k = 3;  // "k, in contrast, can be evaluated at compile time."
    
    std::cout << "j = " << j << "\n";
    std::cout << "k = " << k << "\n";
}
```

<span class="graffiti-highlight graffiti-id_9daoia7-id_p5h1y8n"><i></i><button>Compile & Run</button></span>&nbsp;
<span class="graffiti-highlight graffiti-id_d85518f-id_kg221qc"><i></i><button>Explain</button></span>

<i>Loading terminal (id_nau33ya), please wait...</i>

### Output
```
Enter an integer value for i: 5
j = 10
k = 3
```

The compiler will catch a `const` variable that changes.


```c++
int main()
{
    // Removing the const fixes the error
    const int i = 2; // "I promise not to change this."
    i++;             // "I just broke my promise."
}
```

<span class="graffiti-highlight graffiti-id_zpsfp04-id_vd4pmdf"><i></i><button>Compile & Run</button></span>&nbsp;
<span class="graffiti-highlight graffiti-id_yjqwwkk-id_eetvyh0"><i></i><button>Explain</button></span>

<i>Loading terminal (id_lxyl40r), please wait...</i>

### Output
```
main2.cpp: In function ‘int main()’:
main2.cpp:5:6: error: increment of read-only variable ‘i’
     i++;             // "I just broke my promise."
      ^~
```

Similarly, the compiler will catch a `constexpr` variable that changes.


```c++
int main()
{
    // Removing the constexpr fixes the error
    constexpr int i = 2;  // "i can be evaluated at compile time."
    i++;                  // "But changing a constexpr variable triggers an error."
}
```

<span class="graffiti-highlight graffiti-id_6cm8alc-id_ampzw92"><i></i><button>Compile & Run</button></span>&nbsp;
<span class="graffiti-highlight graffiti-id_pxb79hu-id_jldwnpn"><i></i><button>Explain</button></span>

<i>Loading terminal (id_ngddbd2), please wait...</i>

### Output
```
main3.cpp: In function ‘int main()’:
main3.cpp:4:6: error: increment of read-only variable ‘i’
     i++;                  // "But changing a constexpr variable triggers an error."
      ^~
```

The major difference between `const` and `constexpr`, though, is that `constexpr` must be evaluated at compile time.

The compiler will catch a `constexpr` variable that cannot be evaluated at compile time.


```c++
#include <iostream>

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    constexpr int j = i * 2;  // "j can only be evaluated at run time."
                              // "constexpr must be evaluated at compile time."
                              // "So this code will produce a compilation error."
}
```

<span class="graffiti-highlight graffiti-id_oc4cka0-id_6bvce88"><i></i><button>Compile & Run</button></span>&nbsp;
<span class="graffiti-highlight graffiti-id_i3xlazq-id_z1wopru"><i></i><button>Explain</button></span>

<i>Loading terminal (id_6207vcc), please wait...</i>

### Output
```
main4.cpp: In function ‘int main()’:
main4.cpp:8:27: error: the value of ‘i’ is not usable in a constant expression
     constexpr int j = i * 2;  // "j can only be evaluated at run time."
                           ^
main4.cpp:5:9: note: ‘int i’ is not const
     int i;
```

Now change `constexpr` to `const` and the code compile successfully. Also runs successfully.

```c++
#include <iostream>

int main()
{
    int i;
    std::cout << "Enter an integer value for i: ";
    std::cin >> i;
    const int j = i * 2;  // "j can only be evaluated at run time."
                              // "constexpr must be evaluated at compile time."
                              // "So this code will produce a compilation error."
}
```

### Output
```
$ g++ main4_const.cpp -o output4_const.out
$ ./output4_const.out 
Enter an integer value for i: 3
```

A common usage of `const` is to guard against accidentally changing a variable, especially when it is passed-by-reference as a function argument.


```c++
#include <iostream>
#include <vector>

int sum(const std::vector<int> &v)
{
    int sum = 0;
    for(int i : v)
        sum += i;
    return sum;
}

int main()
{
    std::vector<int> v {0, 1, 2, 3, 4};
    std::cout << sum(v) << "\n";
}
```

<span class="graffiti-highlight graffiti-id_q3f958n-id_imkk2gs"><i></i><button>Compile & Run</button></span>&nbsp;
<span class="graffiti-highlight graffiti-id_2jbu560-id_kmtghge"><i></i><button>Explain</button></span>

<i>Loading terminal (id_x6tnb0d), please wait...</i>

### Output
```
10
```

The distinction between `const` and `constexpr` is subtle. 

In general, though, `const` is much more common than `constexpr`.

When in doubt, use `const`, especially to guard against accidentally modifying a variable.

# Pointers

Pointers have traditionally been a stumbling block for many students learning C++, but they do not need to be!

> A C++ pointer is just a variable that stores the memory address of an object in your program.

That is the most important thing to understand and remember about pointers - they essentially keep track of where a variable is stored in the computer's memory.

In the previous lessons, you implemented A* search in a single file without using C++ pointers, except in `CellSort` code that was provided for you; a C++ program can be written without using pointers extensively (or at all). However, pointers give you better control over how your program uses memory. However, much like the pass-by-reference example that you saw previously, it can often be far more efficient to perform an operation with a pointer to an object than performing the same operation using the object itself.

Pointers are an extremely important part of the C++ language, and as you are exposed to more C++ code, you will certainly encounter them. In this notebook, you will become familiar with basic pointers so you get comfortable with the syntax, and you will be ready to use them in the course project code.


## Accessing a Memory Address

Each variable in a program stores its contents in the computer's memory, and each chunk of the memory has an address number. For a given variable, the memory address can be accessed using an ampersand in front of the variable. To see an example of this, execute the following code which displays the [hexadecimal](https://en.wikipedia.org/wiki/Hexadecimal) memory addresses of the variables `i` and `j`:


```c++
#include <iostream>
using std::cout;

int main() {
    int i = 5;
    int j = 6;

    // Print the memory addresses of i and j
    cout << "The address of i is: " << &i << "\n";
    cout << "The address of j is: " << &j << "\n";
}
```

<span class="graffiti-highlight graffiti-id_mj8723g-id_rvcpg55"><i></i><button>Compile & Execute</button></span> &nbsp;
<span class="graffiti-highlight graffiti-id_omx3gpk-id_ze8e3lh"><i></i><button>Explain</button></span>

<i>Loading terminal (id_1lhn359), please wait...</i>

### OUTPUT
```
The address of i is: 0x7fff36c7cc00
The address of j is: 0x7fff36c7cc04
```

At this point, you might be wondering why the same symbol `&` can be used to both access memory addresses and, as you've seen before, pass references into a function. This is a great thing to wonder about. The overloading of the ampersand symbol `&` and the `*` symbol probably contribute to much of the confusion around pointers.

> **The symbols `&` and `*` have a different meaning, depending on which side of an equation they appear.**

_This is extremely important to remember._ For the `&` symbol, if it appears on the left side of an equation (e.g. when declaring a variable), it means that the variable is declared as a reference. If the `&` appears on the right side of an equation, or before a previously defined variable, it is used to return a memory address, as in the example above.

Try using the cell above to create new variables and print out their addresses!

## Storing a Memory Address (int type)

Once a memory address is accessed, you can store it using a pointer. A pointer can be declared by using the `*` operator in the declaration. See the following code for an example:


```c++
#include <iostream>
using std::cout;

int main()
{
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;

    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
}
```

<span class="graffiti-highlight graffiti-id_fuseufk-id_9g9v3ka"><i></i><button>Compile & Execute</button></span> &nbsp; <span class="graffiti-highlight graffiti-id_qn2zbq0-id_60qo49s"><i></i><button>Explain</button></span>

<i>Loading terminal (id_okmu891), please wait...</i>

### OUTPUT
```
The address of i is:          0x7ffe58386a3c
The variable pointer_to_i is: 0x7ffe58386a3c
```

As you can see from the code, the variable `pointer_to_i` is declared as a pointer to an `int` using the `*` symbol, and `pointer_to_i` is set to the address of `i`. From the printout, it can be seen that `pointer_to_i` holds the same value as the address of `i`.

## Getting an Object Back from a Pointer Address

Once you have a pointer, you may want to retrieve the object it is pointing to. In this case, the `*` symbol can be used again. This time, however, it will appear on the right hand side of an equation or in front of an already-defined variable, so the meaning is different. In this case, it is called the "dereferencing operator", and it returns the object being pointed to. You can see how this works with the code below:


```c++
#include <iostream>
using std::cout;

int main()
{
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;

    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
    cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
}
```

<span class="graffiti-highlight graffiti-id_wemey0a-id_5aovsp9"><i></i><button>Compile & Execute</button></span> &nbsp; <span class="graffiti-highlight graffiti-id_nsgrn9m-id_om3tqer"><i></i><button>Explain</button></span>

<i>Loading terminal (id_azwdndx), please wait...</i>

### OUTPUT
```
The address of i is:          0x7ffca179ccfc
The variable pointer_to_i is: 0x7ffca179ccfc
The value of the variable pointed to by pointer_to_i is: 5
```

In the following example, the code is similar to above, except that the object that is being pointed to is changed before the pointer is dereferenced. Before executing the following code, guess what you think will happen to the value of the dereferenced pointer.


```c++
#include <iostream>
using std::cout;

int main() {
    int i = 5;
    // A pointer pointer_to_i is declared and initialized to the address of i.
    int* pointer_to_i = &i;

    // Print the memory addresses of i and j
    cout << "The address of i is:          " << &i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";

    // The value of i is changed.
    i = 7;
    cout << "The new value of the variable i is                     : " << i << "\n";
    cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << "\n";
    cout << "The variable pointer_to_i is: " << pointer_to_i << "\n";
}
```

<span class="graffiti-highlight graffiti-id_jmbies1-id_irsnop3"><i></i><button>Compile & Run</button></span> &nbsp; <span class="graffiti-highlight graffiti-id_3ezr9e9-id_dfwjvyv"><i></i><button>Explain</button></span>

<i>Loading terminal (id_4ooyod1), please wait...</i>

### OUTPUT
```
The address of i is:          0x7ffc084ab20c
The variable pointer_to_i is: 0x7ffc084ab20c
The new value of the variable i is                     : 7
The value of the variable pointed to by pointer_to_i is: 7
The variable pointer_to_i is: 0x7ffc084ab20c
```

As you can see, an object or variable can be changed while a pointer is pointing to it.

## Try it Yourself!

Don't forget to experiment with the code in the cells above! Coding a few pointer variables is a great way to get used to the syntax.


## Pointers to Other Object Types

Although the type of object being pointed to must be included in a pointer declaration, pointers hold the same kind of value for every type of object: just a memory address to where the object is stored. In the following code, a vector is declared. Write your own code to create a pointer to the address of that vector. Then, dereference your pointer and print the value of the first item in the vector.


```c++
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main() {
    // Vector v is declared and initialized to {1, 2, 3}
    vector<int> v {1, 2, 3};

    // Declare and initialize a pointer to the address of v here:

    // The following loops over each int a in the vector v and prints.
    // Note that this uses a "range-based" for loop:
    // https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Res-for-range
    for (int a: v) {
        cout << a << "\n";
    }

    // Dereference your pointer to v and print the int at index 0 here (note: you should print 1):
    // NOTE ******************* parenthesis () is needed around pv
    cout << "The first element of the pointer is = " << (*pv)[0] << "\n";
}
```

<span class="graffiti-highlight graffiti-id_319d11b-id_6cnfxb6"><i></i><button>Compile & Execute</button></span> &nbsp; <span class="graffiti-highlight graffiti-id_f709kp1-id_ltel3pu"><i></i><button>See Solution</button></span>

<i>Loading terminal (id_fr9qte8), please wait...</i>

### OUTPUT
```
1
2
3
The first element of the pointer is = 1
```

Hint: If you've created a pointer to `v`, say `pv`, you can retrieve `v` with `(*pv)`.

## Passing Pointers to a Function

Pointers can be used in another form of pass-by-reference when working with functions. When used in this context, they work much like the references that you used for pass-by reference previously. If the pointer is pointing to a large object, it can be much more efficient to pass the pointer to a function than to pass a copy of the object as with pass-by-value.

In the following code, a pointer to an int is created, and that pointer is passed to a function. The object pointed to is then modified in the function.


```c++
#include <iostream>
using std::cout;

void AddOne(int* j)
{
    // Dereference the pointer and increment the int being pointed to.
    (*j)++;
}

int main()
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";

    // Declare a pointer to i:
    int* pi = &i;
    AddOne(pi);
    cout << "The value of i is now: " << i << "\n";
}
```

<span class="graffiti-highlight graffiti-id_gbr1alm-id_tjl2yw0"><i></i><button>Compile & Execute</button></span> &nbsp; <span class="graffiti-highlight graffiti-id_gbr1alm-id_u91bpg4"><i></i><button>Explain</button></span>

<i>Loading terminal (id_699poaf), please wait...</i>

### OUTPUT
```
The value of i is: 1
The value of i is now: 2
```

When using pointers with functions, some care should be taken. If a pointer is passed to a function and then assigned to a variable in the function that goes out of scope after the function finishes executing, then the pointer will have undefined behavior at that point - the memory it is pointing to might be overwritten by other parts of the program.

## Returning a Pointer from a Function

You can also return a pointer from a function. As mentioned just above, if you do this, you must be careful that the object being pointed to doesn't go out of scope when the function finishes executing. If the object goes out of scope, the memory address being pointed to might then be used for something else.

In the example below, a reference is passed into a function and a pointer is returned. This is safe since the pointer being returned points to a reference - a variable that exists outside of the function and will not go out of scope in the function.


```c++
#include <iostream>
using std::cout;

int* AddOne(int& j)
{
    // Increment the referenced int and return the
    // address of j.
    j++;
    return &j;
}

int main()
{
    int i = 1;
    cout << "The value of i is: " << i << "\n";

    // Declare a pointer and initialize to the value
    // returned by AddOne:
    int* my_pointer = AddOne(i);
    cout << "The value of i is now: " << i << "\n";
    cout << "The value of the int pointed to by my_pointer is: " << *my_pointer << "\n";
}
```

<span class="graffiti-highlight graffiti-id_3q19eh4-id_cklt1kl"><i></i><button>Compile & Execute</button></span>&nbsp;
<span class="graffiti-highlight graffiti-id_3q19eh4-id_0oe8o5t"><i></i><button>Explain</button></span>

<i>Loading terminal (id_05lniic), please wait...</i>

### OUTPUT
```
The value of i is: 1
The value of i is now: 2
The value of the int pointed to by my_pointer is: 2
```

## Your turn!

Try modifying the code above to get a better sense of how things work. If you are curious, try printing the memory address of `i` in the `main`, and the address of `j` inside the `AddOne` function. Since `j` is a reference to `i`, they should have the address!


References vs Pointers
Pointers and references can have similar use cases in C++. As seen previously both references and pointers can be used in pass-by-reference to a function. Additionally, they both provide an alternative way to access an existing variable: pointers through the variable's address, and references through another name for that variable. But what are the differences between the two, and when should each be used? The following list summarizes some of the differences between pointers and references, as well as when each should be used:

|References	|Pointers|
|-------|----|
|References must be initialized when they are declared. This means that a reference will always point to data that was intentionally assigned to it. |Pointers can be declared without being initialized, which is dangerous. If this happens mistakenly, the pointer could be pointing to an arbitrary address in memory, and the data associated with that address could be meaningless, leading to undefined behavior and difficult-to-resolve bugs.|
|References can not be null. This means that a reference should point to meaningful data in the program.| Pointers can be null. In fact, if a pointer is not initialized immediately, it is often best practice to initialize to nullptr, a special type which indicates that the pointer is null.|
|When used in a function for pass-by-reference, the reference can be used just as a variable of the same type would be.| When used in a function for pass-by-reference, a pointer must be dereferenced in order to access the underlying object.|

References are generally easier and safer than pointers. As a decent rule of thumb, references should be used in place of pointers when possible.

However, there are times when it is not possible to use references. One example is object initialization. You might like one object to store a reference to another object. However, if the other object is not yet available when the first object is created, then the first object will need to use a pointer, not a reference, since a reference cannot be null. The reference could only be initialized once the other object is created.

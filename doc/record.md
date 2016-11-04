
#A Simple Object Model
each data member or function member has its own slot.
One object is consist of a series of slot.

[type_info class usage in C++](http://stackoverflow.com/questions/9248421/typeid-and-type-info-class)


# A defined vs a definition
A definition actually instantiates/implements this identifier.
It's what the linker needs in order to link reference to those entities.


The C++ standard considers struct X; to be a declaration and struct X {}; a definition


http://stackoverflow.com/questions/29797022/declaring-vs-defining-variables-in-c?noredirect=1&lq=1
Q:Does the compiler set aside memory for the declared(but not defined) variables?
A:No, compiler just take a note of this variable name and type. No memory is allocated for the declaration.


http://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration?noredirect=1&lq=1
in C++:
the following is declaration:(compiler needs)
    - external in bar;
    - external int g(int, int);
    - double f(int, double) // external can be omitted for function declarations
    - class foo; // no external allowed for type declarations

the following is definition:(linker needs)
    - int bar;
    - int g(int lhs, int rhs) { return lhs * rhs; }
    - double f(int i ,double d) {return i + d;}
    - class foo{};
And a definition can be used in the place of a declaration.

An identifier can be declared as often as you want. Thus, the following is legal in C and C++:
    double f(int , double);
    double f(int , double);
    external double f(int, double); // the same as above
    external double f(int ,double);

However, it must be defined exactly once.
If you have forg




# Why should I use a pointer rather than the object itself?
http://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself
I am coming from a Java background and have started working with objects in C++.
But one thing that occurred to me is that people often use pointers to objects rather than 
the objects themselves.
for example this definition:
    Object *myobject = new Object;
    rather than 
    Object myObject;

Or instead of usign a fucntion, let's say testFunc(), like this:
    myObject.testFunc();
we have to write:
    myObject->testFunc();

But I can't figure out why should we do it this way.
I would assume it has to do with efficiency and speed since it get direct access to the memory address.Am I right?




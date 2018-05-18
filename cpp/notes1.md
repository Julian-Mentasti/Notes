# CSPC 221: Notes 1:

Header file (the one that ends in .h) holds the API or what the class is supposed to do. While the implementation file (the one that ends in .cpp) is where the behaviour is specified.

An example of a header: Code 1.1

```cpp
#ifndef HSLAPIXEL_H
#define HSLAPIXEL_H

namespace cs221util {
	class HSLAPixel {
		public:	
			HSLAPixel();
			HSLAPixel(double hue, double saturation, double luminance);
			HSLAPixel(double hue, double saturation, double luminance, double aplha);
			double h;
			double s;
			double l;
			double a;
	};
}

#endif
```
An example of the related .cpp file: Code 1.2

```cpp
#include "HSLAPixel.h"

namespace cs221util {
	HSLAPixel::HSLAPixel() {
		h = 0.0;
		s = 0.0;
		l = 1.0;
		a = 1.0;
	}

	HSLAPixel::HSLAPixel(double hue, double saturation, double luminance) {
		h = hue;
		s = saturation;
		l = luminance;
		a = 1.0;
	}	

	HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha) {
		h = hue;
		s = saturation;
		l = luminance;
		a = alpha;
	}
}
```
In code 1.1 you can see the fragment
```cpp
#ifndef HSLAPIXEL_H
#define HSLAPIXEL_H
//code
#endif
```
These are the inclusion guards. 

Moreover you will see the use of }; is exclusivie to when the class definitions ends.

While in code 1.2 you can see:
```cpp
#include "HSLAPixel.h"
```
Indicating the included headerfile. 

You may also notice the use of a double colon '::' and its the scope resolution operator. It says that it belongs to the class specified before.

Now look at the following:

```cpp
#include "myclass.h" // (a)
#include <iostream>  // (b)
```

The difference between a and b is that the first one is looking for the file in our own directory while the second looks in the system headers.

### Constructors:
Every class in Cpp has a constructor, even if it is not defined. It will just be assigned essentially random values. However, as soon as we define a custom constructor(s) we must call one of them. 

### -------------> POINTERS ---------------->

#### * is a pointer to where the data is stored in memory
#### & is the actual address of where a variable is stored. 

Pointers have their own memoery, they store the memory address of the contents they are pointing to. Thus they store addressed and they can be initialized and still point to Null. 

Example: Code 2.1
```cpp
int main() {
	Sphere s;
	std::cout << "Address storing 's': " << &s << std::endl;
	
	Sphere *ptr = &s; //Pointer to the address of sphere s.
	std::cout << "Addr. storing ptr: << &ptr << std::endl;
	std::cout << "Contents of ptr: " << ptr << std::endl;
	
	return 0;
}
```
#### Outline of the operators:
1. &v: give the address storing the data - 0x0000
2. *v: give me the data. (Follow the pointer to where the data is pointing to)
3. v-> equivalent to the Class.something() but for pointers. a->b ≍ (*a).b if a is a pointer, a->b is the member b of which a points to. 

Suppose you have the written a program with a sphere and there is a getter to obtain the radius of said sphere. You make the Sphere s and then make a pointer called ptr to said sphere. if you were to type (*ptr.radius) it would do the following:
1. Follow the pointer.
2. Get the radius. 

### Example: Code 2.2
```cpp
int a = 5;
int *b = &a;
```
| Address       |    Value      |
|:-------------:|:-------------:|
| 0x1000        | 5             |
| 0x2000        |   0x1000      |

| Cout          | &a            |a              |*a             |&b             |b              |*b             |
|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| Content       | 0x1000        |0x1000         |ERROR          |0x2000         |0x1000         |5              |

### Stack Frames
All variables that are part of a function are part of that function's stack frame. They are created when a function is called and then made free when the function return. Note: the data is not deleted, the slots where the data used to be located now now be used for new information. 



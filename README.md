# Creating DLLs

## Compiling

	g++ dll.cpp -o mylib.dll -shared

## Exporting lib functions

To export a function from a dll, first we need to add the following code in it's beginning:

	extern "C" __declspec(dllexport) function_type function_name...

## Using lib functions

### Load Library

	HINSTANCE dll = LoadLibrary("Path\\to\\dll");

### Define a function pointer for the imported function

	typedef int (__stdcall *dll_function)(function arguments);

### Resolve function address

	dll_function new_function_name = (dll_function)GetProcAddress(dll, "original_function_name);

### Running function

	new_function_name(function arguments);

## Exporting lib class

### Interface

First of all we need to create an interface to be exported and used to build the library and import the class in the program which will use the library.

Is worth to note that when creating the interface we also need to export the function which will create the class instance also.

	extern "C" __declspec(dllexport) calc_api_interface* getDllClass();

### Building the library

After import and implement the function from the interface we need to implement a function to export the class instance which is already been exported by the interface and export it again.

	extern "C" calc_api_interface* getDllClass() {
		static calc_api instance;
		return &instance;
	}

## Using lib class

### Defining a function type to create the class

After importing the interface we need to create a type from our function which will create our class inside the program

	typedef class_interface_type* (*functionToCreateClass)();
	
### Load Library

	HINSTANCE dll = LoadLibrary("Path\\to\\dll");

### Creating function to create the class

	functionToCreateClass class_create = (functionToCreateClass)GetProcAddress(dll, "getDllClass");

### Creating object

	class_interface_type* object = class_create();

### Using the object

After the entire process we can just call the methods from our created object.

	object->initialize();
	object->sum(2, 5);
	object->multiply(2, 25);
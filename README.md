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
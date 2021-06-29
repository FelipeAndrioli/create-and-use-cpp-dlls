# Creating DLLs

## Exporting lib functions

To export a function from a dll, first we need to add the following code in it's beginning:

	__declspec(dllexport) function_type function_name...

## Compiling

	g++ dll.cpp -o mylib.dll -shared


## Using lib functions

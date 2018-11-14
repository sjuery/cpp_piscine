#include <stdio.h>

//Declaring global variable and setting it to 1
int gl_var = 0;
//Creating a function that simply returns the variable
int function(void) { return gl_var; }

//Using a namespace we can recreate these without using a different name
namespace diff {
	int gl_var = 1;
	int function(void) { return gl_var; }
}

//You can create copies of a namespace with a different name.
namespace sameDiff = diff;

int main(void)
{
	//The value or function we want can be accessed by adding the name of
	//the namespace before calling the them followed by a "::".
	printf("function:			[%d]\n", function());
	printf("diff::function:			[%d]\n", diff::function());
	printf("sameDiff:function:		[%d]\n", sameDiff::function());
}

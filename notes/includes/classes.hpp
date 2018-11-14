#ifndef CLASSES_HPP
#define CLASSES_HPP

class Sample {

//Declare public functions in Sample class
public:
	//Variable variable declared in our Sample class, const so can never be changed
	int const variable;
	char character;
	int integer;
	float decimal;
	//Function with class name will be called on function creation
	Sample(float const cc, char c1, int i1, float d1);
	//Function with class name prefixed by a "~" will be called on function end
	~Sample(void);
	//Function function declared in out Sample class (Const so nothing can be changed)
	void function(void) const;

	static int getNbInstances(void);
	int getPrivateVariable(void) const;
	void setPrivateVarible(int v);

//Declare private functions (cannot be accessed outside of the class)
private:
	int _privateVariable;
	static int _nbInstances;
	void _privateFunction(void) const;
};

#endif

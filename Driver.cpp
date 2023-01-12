/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file. 
During marking, we will use the exact same notation 
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't 
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK! 

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands


	while (userCommand.compare("exit") != 0) 
	{
		cout << "Enter the command: ";
		
		getline(cin, userCommand);

		char * cstr = new char[userCommand.length() + 1];

		strcpy(cstr,userCommand.c_str());
		
		// implement a string tokenizer to populate the parameters vector 
		// check function strtok_s
		string arguments = "";
		for(int i=0;i<userCommand.length();i++){
			if(cstr[i]==' '){
				parameters.push_back(arguments);
				arguments="";
			}
			else{
				arguments+=cstr[i];
			}
		}
		parameters.push_back(arguments);

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		string command = parameters[0];


		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format

		if (command.compare("addR") == 0) {
			// get parameters in the correct order
			// The following four lines have a type mismatch error
			// note that the the parameters vector contains ascii values
			// HINT: stoi function converts from string to int

			int x = stoi(parameters[1]); // fix me! also note that x is not previously defined :(
			// int y = ...
			// int h = ...
			// int w = ...
			int y = stoi(parameters[2]);
			int h= stoi(parameters[3]);
			int w = stoi(parameters[4]);

			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);
			r->toString(); /* instead of this, you may implement operator overloadig and 
									use cout << r which will give you additional points */
		}
		else if (command.compare("addS") == 0) {
			// get parameters
			// ...
			int x = stoi(parameters[1]);
			int y = stoi(parameters[2]);
			int e = stoi(parameters[3]);
			Square* s = new Square(x, y, e);

			shapes.push_back(s);
			s->toString();
		}

		if (command.compare("addC") == 0) {
			// get parameters
			// ...
			int x = stoi(parameters[1]);
			int y = stoi(parameters[2]);
			int r = stoi(parameters[3]);
			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);
			c->toString();
			
		}
		else if (command.compare("scale") == 0) {
			// scale object at index... the scaling needs to be isotropic in case of circle and square 
			// you may want to check if the index exists or not!
			
			// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
			// As a result all your derived classes have scale functions... 
			// You may need to use type casting wisely to use polymorphic functionality!
			int shapeNo;
			shapeNo = stoi(parameters[1]);
			if(shapeNo>shapes.size()){
				cout<<"Shape does not exist"<<endl;
				continue;
			}
			double x = stod(parameters[2]);
			double y = stod(parameters[3]);
			Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->scale(x, y);
			shapes[shapeNo - 1]->toString();
		}
		else if (command.compare("move") == 0) {
			// move object at index 
			int shapeNo; // read from parameters
			// you may want to check if the index exists or not!
			shapeNo = stoi(parameters[1]);
			if(shapeNo>shapes.size()){
				cout<<"Shape does not exist"<<endl;
				continue;
			}
			int x = stoi(parameters[2]);
			int y = stoi(parameters[3]);
			// Study the following code. A Shape object is not Movable, but all derived classes are...
			// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
			Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
			m->move(x, y);
			// shapes[shapeNo - 1]->move(x,y);
			// scale should work similarly...

			// note that here you should see the corresponding toString output for the derived classes...
			// if toString is not a virtual function, you may see the base class functionality :(
			shapes[shapeNo - 1]->toString();
		}
		else if (command.compare("display") == 0) {
			// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
			for(int i=0;i<shapes.size();i++){
				cout<<"Shape "<<i+1<<":"<<endl;
				shapes[i]->toString();
				cout<<endl;
			}
		}
		// do any necessary postprocessing at the end of each loop...
		// yes, there is some necessary postprocessing...
		cout << endl << endl;
		parameters.clear();
	}
	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}

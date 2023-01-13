// count no. of spaces, tabs, lines, and chars
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream file;
	int spaces = 0;
	int tabs = 0;
	int lines = 0;
	int chars = 0;
	char c;
	file.open("input.cpp");
	do {
		file.get(c);
		if(c == 32)	// space
			spaces++;
		else if(c == 9)	// tabs
			tabs++;
		else if(c == 10)	// linefeed
			lines++;
		else if(c >= 97 || c <= 122 || c <= 65 || c>= 90)
			chars++;
	} while(!file.eof());
	file.close();
	cout<<"Spaces = "<<spaces<<", tabs = " << tabs << ", number of lines: " <<lines<< ", characters = "<< chars<<endl;
}

// replace multiple spaces with single space
#include <iostream>
#include <fstream>
#include<string>
#include<cstdio>

using namespace std;

int main(){
	ifstream file;
	ofstream file1;
	char ch;
	int spaceCount = 0;
	streampos currPos;
	bool isString = false;
	char oldName[] = "temp.cpp";
	char newName[] = "input.cpp";

	// streampos currPos, end;	// spaces begin and end
	file.open(newName);
	file1.open(oldName);
	while(!file.eof()){
		file.get(ch);
        // cout<<ch<<"\n. ";
		/*if(ch == ' '){
			spaceCount++;
			cout<<"\n\t\t"<<spaceCount<<"\n";
			// begin = file.tellg();
			// cout<<"tellg = "<<begin<<endl;
		}
		else{
            if(spaceCount == 1){
                spaceCount = 0;
                file1<<ch;
            }

			else if(spaceCount > 1){
				// currPos = file.tellg();
				// file.seekp(-(spaceCount-1), ios::cur); // cursor will be at after first space
                spaceCount = 0;
                continue;
			}
		}*/
		if(ch == '"')
			if(isString)
				isString = false;
			else
				isString = true;
		if(ch == 32  && !isString)
		    spaceCount++;
        else
            spaceCount = 0;
        if(spaceCount <= 1){
            file1<<ch;
        }
    }
	file.close();
	file1.close();
    // delete old file
	remove(newName);
    // rename the temp
    rename(oldName, newName);
}

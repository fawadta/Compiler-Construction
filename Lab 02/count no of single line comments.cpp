// count the number of single line comments in the program written in input file
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>

using namespace std;

int main(){
    ifstream file;
    char ch;
    int singleLineComments = 0;
    bool isNextComment = true, isString = false;
    file.open("input.cpp");
    while(!file.eof()){
        file.get(ch);
        if(ch == 10) // lineFeed ascii
            isNextComment = true;
        if(ch == '"'){
            isString = true;
            while(1){
                file.get(ch);
                if(ch == '"'){
                    isString = false;
                    break;
                }
            }
        }
        if(ch == '/' && isNextComment && !isString) // / = 47
        {
            file.get(ch);
            if(ch == '/'){
                singleLineComments++;
                isNextComment = false;
            }
        }
    }
    file.close();
    cout<< "Number of single line comments = "<<singleLineComments;
}

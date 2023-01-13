// Delete single line comments from input file
#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>

using namespace std;

int main(){
    ifstream file;
    ofstream file1;
    char ch;
    int singleLineComments = 0;
    char original[] = "input.cpp", temp[] = "temp.cpp";
    bool isNextComment = true, isString = false, shouldWrite = true, isComment = false, isComment1 = false;;
    file.open(original);
    file1.open(temp);
    while(!file.eof()){
        file.get(ch);
        if(ch == 10) // lineFeed ascii
        {
            isNextComment = true;
            shouldWrite = true;
        }
        if(ch == '"')   // to handle strings
        {
            isString = true;
            while(1){
                if(ch != 9)   // to ignore tabs, and lineFeed
                    file1<<ch;
                file.get(ch);
                if(ch == '"'){
                    isString = false;
                    break;
                }
            }
        }
        if(ch == '/' && isNextComment && !isString) // / = 47
        {
            shouldWrite = false;
            file.get(ch);
            if(ch == '/'){
                shouldWrite = false;
                isNextComment = false;
                isComment = true;
            }
        }
        if(isComment){
            if(ch == 9 || ch == 10){
                isComment = false;
                isComment1 = true;
                continue;
            }
        }
        // if tab == 4 spaces
        /*
        if(isComment1 && ch == 32){
            file.get(ch);
            if(ch == 32){
                file.get(ch);
                if(ch == 32){
                    file.get(ch);
                    if(ch == 32){
                        isComment1 = false;
                        continue;
                    }
                }
            }
        }*/
        /*if(isComment) // it do the same func as below if condition
        {
            isComment = false;
            while(1){
                file.get(ch);
                if(ch == 10)
                    break;
            }
        }*/
        // if(shouldWrite && ch != 9){
        if(shouldWrite){
            file1<<ch;
        }
    }
    file.close();
    file1.close();
    cout<< "Number of single line comments = "<<singleLineComments;
}

/*
To store the following tokens in symbol table.
identifier: l(l+d))^*
keywords: if, while, switch, else, do, int, main, cout
operators: +, -, *, /, <, >, <=, >=, ==
special characters: (, ), {, }, [, ], ;
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<bits/stdc++.h>


using namespace std;

int main(){
    ifstream file;
    vector<vector<string>> symbolTable = {{}, {}, {}, {}};
    char ch;
    enum colName {iden = 1, kw = 2, op = 3, sc = 4};

    file.open("input.cpp");
    while(!file.eof()){
        file.get(ch);
        // symbolTable.push_back(newRow);
        // symbolTable[0].push_back("aaaa");
        //symbolTable[0][0] = "3331";
        //cout<<symbolTable[0][0];
        //for(auto x:symbolTable)
          //  cout<<x;
        //if(ch == )
        if(ch == '(' || ch == ')' ||  ch == '{' ||  ch == '}' ||  ch == '{' ||  ch == '}' ||  ch == ';')  // special characters
        {
            symbolTable[colName::sc].push_back(ch);
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '<' || ch == '>' || ch == '!' || ch == '' || ch == '' || )

    }




    file.close();
}

















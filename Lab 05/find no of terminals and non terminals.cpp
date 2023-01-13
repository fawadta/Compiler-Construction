// find number of terminals and non terminals in a given CFG. First load CFG in linked list
#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

bool isUpperString(string str){
    for(int i = 0; i < str.length(); i++){
        if(!isupper(str[i]))    // if any one char isn't an upper
            return false;
    }
	return true;
}
bool isLowerString(string str){
    // cout<<"\nCalled";
    if(str.length() == 1){  // for a single char
        char c = *str.c_str();	// string to char array
        //if(c > 90 || c < 65)	// not uppercase
        if(!isupper(c))	// not uppercase
		{
        	// cout<<"c:"<<c<<":\n";
			return true;
		}
		return false;
    }
    else{
        for(int i = 0; i < str.length(); i++){
			//cout<<str.length()<<":"<<str[i];
            if(!islower(str[i]))
                return false;
        }
        // cout<<"C;"<<str<<";\n";
        return true;
    }
}

bool isFound(vector<string> *V, string str){
    for(auto x:*V)
        if(str == x)
            return true;
    return false;
}

int main()
{
    ifstream file;
    char ch;
    int index;
    bool newLine = true;
    vector<char> vCh;   // one terminal or non terminal or rule
    list<string> list1; // all rules of one non terminal
    vector<list<string>> vList; // all lists in a list
    vector<string> foundV;  // found terminals
    int nonTerminal = 0, terminal = 0;

    file.open("input.txt");

    while(!file.eof()){
        file.get(ch);
        while(newLine){   // for non terminal
            vCh.push_back(ch);
            file.get(ch);
            if(ch == '-'){
                file.get(ch);
                if(ch == '>'){
                    file.get(ch);
                    newLine = false;
                    break;
                }
            }
            if(file.eof())
                break;
        }
        string str(vCh.begin(), vCh.end());
        vCh.clear();
        list1.push_back(str);
        str = "";
        while(1)
        {
            if(ch != '|' && ch != 10){
                vCh.push_back(ch);
            }
            if(ch == '|' || ch == 10){
                string st(vCh.begin(), vCh.end());
                list1.push_back(st);    // pushing in next node in list
                vCh.clear();
                str = "";
                if(ch == 10){    // linefeed
                    newLine = true;
                    break;
                }
            }
            file.get(ch);
        }
        vList.push_back(list1);
        list1.clear();
    }
    for(auto &x:vList){
        string str;
        for(auto &y:x)
        {
            // cout<<"   "<<y;
            if(y == *x.begin()){
                if(isUpperString(y) && !isFound(&foundV, y)){
                    //cout<<"+";
                    foundV.push_back(y);
                    nonTerminal++;
                }
            }
            else{
                stringstream S(y);
                while(getline(S, str, ' ')){
                    //<<str<<",\t";
					if(isLowerString(str) && !isFound(&foundV, str)){
						// cout<<"\nString:"<<str<<endl;
						terminal++;
						foundV.push_back(str);
                    }
                }
            }
        }
    }
    // cout<<"\nvec:\n";
    // sort(foundV.begin(), foundV.end());
    // for(auto x:foundV)
    // 	cout<<x<<endl;
    cout<<"Non terminals: "<<nonTerminal<<", Terminals: "<<terminal;
    file.close();
}

// store each non terminal and it's rules in a separate linked list, and then create a linked list of those linked list.
#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    ifstream file;
    char ch;
    int index;
    bool newLine = true;
    vector<char> vCh;   // one terminal or non terminal or rule
    list<string> list1; // all rules of one non terminal
    vector<list<string>> vList; // all lists in a list
    //list<list<string>> lList;
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
            if(ch != '|' && ch != 10){	// linefeed == 10
                vCh.push_back(ch);
            }
            if(ch == '|' || ch == 10){
                string st(vCh.begin(), vCh.end());
                list1.push_back(st);    // pushing in next node in list
                vCh.clear();
                str = "";	// ig its st instead of str
                if(ch == 10){    // linefeed
                    newLine = true;
                    break;
                }
            }
            file.get(ch);
        }
        vList.push_back(list1);
        //lList.push_back(list1);
        list1.clear();
    }
    // print linked list
    string st;
    for(auto &x:vList){
        for(auto &y:x)
        {
        	auto temp = x.begin();
			st += y;
        	if(y == *temp)
				st += "->";

			else if(y != *temp)
				st += "|";
        }
        st.pop_back();
        cout<<st;
        cout<<endl;
        st = "";
    }
    /*cout<<"\n-------------\n";
    for(auto &x:lList){
        for(auto &y:x)
        {
            cout<<y;
        }
        cout<<endl;
    }*/

    file.close();
}

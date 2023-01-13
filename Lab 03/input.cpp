#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>


using namespace std;

int main(){
    int num = 1;
    if(num == 1){
        for(int i = 2; i >= 0; i--)
            cout<<"Loop\n";
        num++;
    }
    else if(num == 2)
        num = num - 2;
    else
        num = num * 3;

}

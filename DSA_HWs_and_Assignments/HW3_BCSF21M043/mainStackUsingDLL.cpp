#include<iostream>
#include"stackUsingDLL.h"
#include"stackUsingDLL.cpp"
using namespace std;
int main(){
    Stack<char> s1;
    bool check = s1.paranthesisEvaluation(")((()))(");
    if(check == true){
        cout<<"Balanced Paranthesis\n"<<endl;
    }
    else{
        cout<<"Not balanced Paranthesis\n";
    }
    return 0;
}
#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> s;

    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.pop();

    if(s.empty()){
        cout<<"Stack is empty";
    }
    else{
        cout<<"Stack is not empty";
    }

    while(!s.empty()){
        int top=s.top();
        cout<<top<<" ";
        s.pop();
    }
}
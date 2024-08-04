#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> myStack;
    for (int i = 0; i < 5; i++)
    {
        myStack.push(5-i);
    }
    cout<<"Stack : ";
    for (int i = 0; i < 5; i++)
    {
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
    cout<<endl;
    myStack.emplace(10);
    myStack.emplace(20);
    myStack.emplace(30);
    myStack.emplace(40);
    cout<<"Stack : ";
    for (int i = 0; i < 4; i++)
    {
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
    cout<<endl;
    if (myStack.empty()){
        cout<<"Stack is empty"<<endl;
    } else {
        cout<<"Stack is not empty"<<endl;
    }
    stack<int> stack2;
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);
    stack2.push(4);
    myStack.swap(stack2);
    cout<<"Stack1 : ";
    while(!((myStack.size())==0))
    {
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
    cout<<endl;
    cout<<"Stack2 : ";
    while(!((stack2.size())==0))
    {
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
    cout<<endl;
}
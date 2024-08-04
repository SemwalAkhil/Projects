#include <iostream>
#include <queue> // FIFO

using namespace std;

int main(){
    priority_queue<int> myQueue; // prioritizes largest element , when top called
    // priority_queue<int,vector<int>,greater<int>>  myQueue; // prioritizes smallest element , when top called
    for (int i = 0; i < 5; i++)
    {
        myQueue.push(i);
    }
    cout<<"Size of myQueue : "<<myQueue.size()<<endl;
    cout<<"myQueue : ";
    while (!(myQueue.empty()))
    {
        cout<<myQueue.top()<<" ";
        myQueue.pop();
    } 
    cout<<endl<<"Size of myQueue : "<<myQueue.size()<<endl;
    for (int i = 0; i < 5; i++)
    {
        myQueue.emplace(i*2);
    }
    cout<<"Size of myQueue : "<<myQueue.size()<<endl;
    cout<<"myQueue : ";
    while (!(myQueue.empty()))
    {
        cout<<myQueue.top()<<" ";
        myQueue.pop();
    } 
    cout<<endl<<"Size of myQueue : "<<myQueue.size()<<endl;
    priority_queue<int> que2;
    // priority_queue<int,vector<int>,greater<int>> que2;
    for (int i = 0; i < 5; i++)
    {
        que2.push(i);
    }
    cout<<"Size of Queue2 : "<<que2.size()<<endl;
    myQueue.swap(que2);    
    cout<<"myQueue : ";
    while (!(myQueue.empty()))
    {
        cout<<myQueue.top()<<" ";
        myQueue.pop();
    } 
    cout<<endl;
    cout<<"Queue2 : ";
    while (!(que2.empty()))
    {
        cout<<que2.top()<<" ";
        que2.pop();
    } 
    cout<<endl;
}
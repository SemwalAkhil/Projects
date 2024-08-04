#include <iostream>
#include <map>
using namespace std;
void mapIt(map<int,string>& myMap){
    cout<<"Map = ";
    for (int i = 1; i < (myMap.size()+1); i++)
    {
        cout<<" "<<i<<" : "<<myMap[i];
    }
    cout<<endl;
}
int main() {
    map<int,string> myMap;
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";
    myMap[4] = "Four";
    myMap[5] = "Five";

    cout<<"Size of myMap : "<<myMap.size()<<endl;
    cout<<"Max Size of myMap : "<<myMap.max_size()<<endl;
    
    cout<<"myMap = ";
    for (int i = 1; i < (myMap.size()+1); i++)
    {
        cout<<" "<<i<<" : "<<myMap[i];
    }
    cout<<endl;
    
    /*
    cout<<"myMap = ";
    for (auto i = myMap.begin(); i != myMap.end(); i++)
    {
        cout<<" "<<i->first<<" : "<<i->second;
    }
    cout<<endl;
    cout<<"myMap = ";
    for (auto i = myMap.cbegin(); i != myMap.cend(); i++)
    {
        cout<<" "<<i->first<<" : "<<i->second;
    }
    cout<<endl;
    cout<<"myMap = ";
    for (auto i = myMap.rbegin(); i != myMap.rend(); i++)
    {
        cout<<" "<<i->first<<" : "<<i->second;
    }
    cout<<endl;
    cout<<"myMap = ";
    for (auto i = myMap.crbegin(); i != myMap.crend(); i++)
    {
        cout<<" "<<i->first<<" : "<<i->second;
    }
    cout<<endl;
    */
    /*
    cout<<"Value at key 3 : "<<myMap.at(3)<<endl;
    */
    /*
    myMap.clear();
    mapIt(myMap);
    */
    /*
    cout<<"Number of times key 3 present : "<<myMap.count(3)<<endl;
    cout<<"Number of times key 6 present : "<<myMap.count(6)<<endl;
    */
    myMap.emplace();
    mapIt(myMap);
    return 0;
}
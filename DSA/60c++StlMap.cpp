#include <iostream>
#include <map>
using namespace std;
void mapIt(map<int,string>& myMap){
    cout<<"Map = ";
    for (auto i:myMap)
    {
        cout<<" "<<i.first<<" : "<<i.second;
    }
    cout<<endl;
}
int main() {
    map<int,string> myMap;
    // myMap[0] = "Zero";
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
        cout<<" "<<i<<" : "<<myMap[i]; // will not work as expected if first element is < 1
    }
    cout<<endl;
    
    // mapIt(myMap);
    
    /* // BEGIN_END_CBEGIN_CEND_RBEGIN_REND_CRBEGIN_CREND
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
    /* // AT
    cout<<"Value at key 3 : "<<myMap.at(3)<<endl;
    */
    /* // CLEAR
    myMap.clear();
    mapIt(myMap);
    */
    /* // COUNT
    cout<<"Number of times key 3 present : "<<myMap.count(3)<<endl;
    cout<<"Number of times key 6 present : "<<myMap.count(6)<<endl;
    */
    /* // EMPLACE
    myMap.emplace(6,"Six");
    myMap.emplace(0,"Zero");
    mapIt(myMap);
    myMap.emplace_hint(myMap.begin(),-1,"Minus");
    myMap.emplace_hint(myMap.end(),7,"Seven");
    mapIt(myMap);
    */
    /* // EMPTY
    cout<<"myMap : ";
    while (!myMap.empty()){
        cout<<myMap.begin()->first<<" : "<<myMap.begin()->second<<" ";
        myMap.erase(myMap.begin());
    }
    */
    /* // EQUAL_RANGE
    pair<map<int,string>::iterator,map<int,string>::iterator> ret;
    ret = myMap.equal_range(4);
    cout<<"Lower Bound : "<<ret.first->first<<" : "<<ret.first->second<<endl;
    cout<<"Upper Bound : "<<ret.second->first<<" : "<<ret.second->second<<endl;
    */
    /* // FIND
    auto ret = myMap.find(5);
    cout<<"Finding 5 : "<<ret->first<<" : "<<ret->second<<endl;
    ret = myMap.find(10);
    // cout<<"Finding 10 : "<<ret->first<<" : "<<ret->second<<endl;
    // ret = myMap.find(0);
    cout<<"Finding 0 : "<<ret->first<<" : "<<ret->second<<endl;
    */
    /* // GET_ALLOCATOR
    map<int,char> Map;
    pair<const int,char> *p = Map.get_allocator().allocate(5);
    pair<int,char> temp;
    for (int i = 0; i < 5; i++)
    {
        temp = {i,(char)(i+65)};
        Map.get_allocator().construct((p+i),temp);
    }
    cout<<"Map = ";
    for (int i = 0; i < 5; i++)
    {
        cout<<(p+i)->first<<" : "<<(p+i)->second<<" ; ";
    }
    cout<<endl;
    Map.get_allocator().deallocate(p,5);
    */    
    /* // INSERT
    myMap.insert({6,"Six"});
    myMap.insert(myMap.begin(),{0,"Zero"});
    mapIt(myMap);
    */
    /* // KEY_COMP
    // Returns a copy of the comparison object used by the container to compare keys.
    auto mycomp = myMap.key_comp();
    int highest = myMap.rbegin()->first;     // key value of last element
    map<int,string>::iterator it = myMap.begin();
    do {
      cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, highest) ); // compares current element with the largest returns true if first element < highest
    cout << '\n';
    */
    /* // VALUE_COMP
    // Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.

    // The arguments taken by this function object are of member type value_type (defined in map as an alias of pair<const key_type,mapped_type>), but the mapped_type part of the value is not taken into consideration in this comparison.
    auto mycomp = myMap.value_comp();
    map<int,string>::iterator highest = myMap.end();
    map<int,string>::iterator it = myMap.begin();
    cout<<"myMap = ";
    do
    {
        cout<<it->first<<" : "<<it->second<<" ";
    } while (mycomp((*it++),*highest));
    cout<<endl; 
    */
    /* // LOWER_BOUND_UPPER_BOUND
    cout<<"Lower bound (3) :"<<myMap.lower_bound(3)->second<<"\nUpper bound (3) :"<<myMap.upper_bound(3)->second<<endl;
    */
    /* // SWAP
    map<int,string> map2;
    map2[1] = "uni";
    map2[2] = "di";
    map2[3] = "tri";
    map2[4] = "tetra";
    // map2[5] = "penta";
    myMap.swap(map2);
    mapIt(myMap);
    mapIt(map2);
    */
    
    return 0;
}
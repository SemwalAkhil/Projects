#include <iostream>
#include <set>
using namespace std;
void setIt(set<int> x){
    cout<<"Set : ";
    for (int i : x)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
}
int main() {
    set<int> mySet = {1,2,2,3,3,4,4,5};
    cout<<"mySet : ";
    for (auto i = mySet.begin(); i != mySet.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    /*
    cout<<"Size of mySet : "<<mySet.size()<<endl;
    cout<<"Max size of mySet : "<<mySet.max_size()<<endl;
    */
    /*
    cout<<"mySet : ";
    for (auto i = mySet.cbegin(); i != mySet.cend(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<"mySet(reverse) : ";
    for (auto i = mySet.rbegin(); i != mySet.rend(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    cout<<"mySet(reverse) : ";
    for (auto i = mySet.crbegin(); i != mySet.crend(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    */
    /*
    cout<<"Number of 2's : "<<mySet.count(2)<<endl;
    cout<<"Number of 6's : "<<mySet.count(6)<<endl;    
    */
    /*
    mySet.emplace(10);
    setIt(mySet);
    mySet.emplace_hint(mySet.end(),15);
    // The value in position is used as a hint on the insertion point. The element will nevertheless be inserted at its corresponding position following the order described by its internal comparison object, but this hint is used by the function to begin its search for the insertion point, speeding up the process considerably when the actual insertion point is either position or close to it.
    setIt(mySet);
    */
    /*
    cout<<"mySet : ";
    while (!(mySet.empty()))
    {
        cout<<*(mySet.begin())<<" ";
        mySet.erase(mySet.begin());
    }
    cout<<endl;
    */
   /*
    pair<set<int>::const_iterator,set<int>::const_iterator> ret = mySet.equal_range(3);
    cout<<"Lower bound : "<<*ret.first<<endl;
    cout<<"Upper bound : "<<*ret.second<<endl;
    ret = mySet.equal_range(6);
    cout<<"\nLower bound : "<<*ret.first<<endl;
    cout<<"Upper bound : "<<*ret.second<<endl;
    ret = mySet.equal_range(0);
    cout<<"\nLower bound : "<<*ret.first<<endl;
    cout<<"Upper bound : "<<*ret.second<<endl;
    */
    /*
    cout<<"Find(0) : "<<*mySet.find(0)<<endl;
    cout<<"Find(3) : "<<*mySet.find(3)<<endl;
    cout<<"Find(5) : "<<*mySet.find(5)<<endl;
    */
    /*
    set<int> set2;
    auto alloc = set2.get_allocator();
    int size = 5;
    int* ptr = alloc.allocate(size);
    for (int i = 0; i < size; i++)
    {
        alloc.construct(ptr+i,i);
    }
    cout<<"Set2 : ";
    for (int i = 0; i < size; i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    alloc.deallocate(ptr,size);
    */
    /*
    mySet.insert(++mySet.begin(),10);
    setIt(mySet);
    mySet.insert(++mySet.begin(),0);
    setIt(mySet);
    mySet.insert(++mySet.begin(),6);
    setIt(mySet);
    */
    /*
    int highest;
    set<int>::key_compare mycomp = mySet.key_comp();
    // This object determines the order of the elements in the container: it is a function pointer or a function object that takes two arguments of the same type as the container elements, and returns true if the first argument is considered to go before the second in the strict weak ordering it defines, and false otherwise.

    for (int i=0; i<=5; i++) mySet.insert(i);

    cout << "myset contains:";

    highest=*mySet.rbegin();
    set<int>::iterator it=mySet.begin();
    do {
      cout << ' ' << *it;
    } while ( mycomp(*(++it),highest) );

    cout << '\n';
    */
    /*
    int highest;
    set<int>::key_compare mycomp = mySet.value_comp();
    // In set containers, the keys to sort the elements are the values themselves, therefore key_comp and its sibling member function value_comp are equivalent.

    for (int i=0; i<=5; i++) mySet.insert(i);

    cout << "myset contains:";

    highest=*mySet.rbegin();
    set<int>::iterator it=mySet.begin();
    do {
      cout << ' ' << *it;
    } while ( mycomp(*(++it),highest) );

    cout << '\n';
    */
    /*
    cout<<"mySet : ";
    auto itLow = mySet.lower_bound(2);
    auto itHigh = mySet.upper_bound(4);
    for (auto i = itLow; i != itHigh; i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    */
    /*
    set<int> set2 = {2,2,2,2,3,3,3,3,4};
    mySet.swap(set2);
    setIt(mySet);
    setIt(set2);
    */
    return 0;
}
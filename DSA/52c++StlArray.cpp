#include <iostream>
#include <array>
using namespace std;
int main() {
    int basic[3] = {1,2,3}; // default array implemented without STL
    
    array<int,5> a = {1,2,3};// array implemented using STL
                             // implementation using the basic array
                             // static array 

    // In case of an array, size() and max_size() function always return the same value
    cout<<"Max size : "<<a.max_size()<<" Size : "<<a.size()<<endl;

    int size = a.size();
    
    // accessing array elements 
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // first element
    cout<<"First Element : "<<a.front()<<endl;
    cout<<"First Element : "<<*(a.data())<<" at address : "<<a.data()<<endl;
    // In C++, array::data() is a member function used with std::array containers to retrieve a pointer to the first element of the array's underlying contiguous memory block.

    // last element
    cout<<"Last Element : "<<a.back()<<endl;
    // at given index
    cout<<"Element at index 1 : "<<a.at(1)<<endl;
    
    // Iterators
    for (auto i = a.begin(); i != a.end(); ++i)
    {
        cout<< *i<<" ";
    }
    cout<<endl;
    /*
        begin():
        ->  Purpose: Returns an iterator that points to the first element of the container (like an std::array, std::vector, etc.).
        ->  Return Value: The type of iterator returned depends on the container. It could be a non-constant iterator (e.g., iterator) or a constant iterator (const_iterator).
        ->  Non-constant iterator: Allows modification of the element it points to (dereferencing followed by assignment).
        ->  Constant iterator: Only allows read-only access (dereferencing to get the value, but not assignment to change it).
    */

    for (auto i = a.cbegin(); i != a.cend(); ++i)
    {
        cout<< *i<<" ";
    }
    cout<<endl;
    /*
    cbegin():
        ->  Purpose: Returns a constant iterator that points to the first element of the container.
        ->  Return Value: Always a const_iterator, regardless of the container's underlying iterator type.
        ->  Usage: Ensures that elements are not accidentally modified during iteration or other operations.
    */

    // Reverse iterators
    for (auto i = a.rbegin(); i != a.rend(); ++i)
    {
        cout<< *i<<" ";
    }
    cout<<endl;

    for (auto i = a.crbegin(); i != a.crend(); ++i)
    {
        cout<< *i<<" ";
    }
    cout<<endl;


    

    // checking empty
    if (a.empty()){
        cout<<"Empty Array"<<endl;
    } else {
        cout<<"Not Empty Array"<<endl;
    }

    // swapping elements of two array
    array<int,5> a2 = {4,5,6};
    a.swap(a2); // array need to be of same size to perform swap
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < a2.size(); i++)
    {
        cout<<a2[i]<<" ";
    }
    cout<<endl;

    // fill array with a constant element
    a.fill(5);
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
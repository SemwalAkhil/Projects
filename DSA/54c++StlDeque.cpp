#include <deque>
#include <iostream>
using namespace std;
int main(){
    deque<int> d1(5,1);
    deque<int> d2 = {1,2,3,4,5};

    cout<<"Deque d1 : ";
    for (int i = 0; i < d1.size(); i++)
    {
        cout<<d1[i]<<" ";
    }
    cout<<endl;

    cout<<"Deque d2 : ";
    for (auto i = d2.begin(); i != d2.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    // MAX_SIZE
    // cout<<"d2.max_size() : "<<d2.max_size()<<endl;

    // deque<int> d3;
    
    // // ASSIGN
    // ASSIGNING_FROM ARRAY
    // int arr[] = {1,2,3,4};
    // d3.assign(arr,arr+4); //

    // ASSIGINING_FROM_DEQUE 
    // d3.assign(d2.begin()+2,d2.end()-1);
    // cout<<"Deque d3 : ";5
    // for (auto i = d3.cbegin(); i != d3.cend() ; i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;

    // cout<<"Deque d2 : ";
    // for (int i = 0; i < d2.size(); i++)
    // {
    //     cout<<d2.at(i)<<" ";
    // }
    // cout<<endl;

    // FRONT_BACK
    // cout<<"First Element of d2 : "<<d2.front()<<endl;
    // cout<<"Last Element of d2 : "<<d2.back()<<endl;

    // CLEAR
    // d2.clear();
    // cout<<"Size of d2 after clear : "<<d2.size()<<endl;

    // EMPLACE
    // d2.emplace(d2.begin()+2,6);
    // cout<<"Deque d2 : ";
    // for (auto i = d2.rbegin(); i != d2.rend(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;

    // EMPLACE_BACK
    // d2.emplace_back(6);
    // cout<<"Deque d2 : ";
    // for (auto i = d2.crbegin(); i != d2.crend(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;

    // EMPLACE_FRONT
    // d2.emplace_front(0);
    // cout<<"Deque d2 : ";
    // for (auto i = d2.begin(); i != d2.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;

    // EMPTY
    // if (d2.empty()){
    //     cout<<"Empty"<<endl;
    // } else {
    //     cout<<"Not Empty"<<endl;
    // }

    // ERASE
    // d2.erase(d2.begin()+1);
    // cout<<"Deque d2 : ";
    // for (auto i = d2.begin(); i != d2.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;
    // // ERASING_MULTIPLE_ELEMENTS
    // // d2.erase(d2.begin()+2,d2.end()-1);
    // // cout<<"Deque d2 : ";
    // // for (auto i = d2.begin(); i != d2.end(); i++)
    // // {
    // //     cout<<*i<<" ";
    // // }
    // // cout<<endl;

    // ALLOCATOR
    // deque<int> mydeque;
    // int * p;
    // // allocate an array with space for 5 elements using deque's allocator:
    // p = mydeque.get_allocator().allocate(5);    

    // // construct values in-place on the array:
    
    // cout<<"mydeque.size() : "<<mydeque.size()<<endl;
    // for (int i=0; i < 5; i++) {
    //     mydeque.get_allocator().construct(&p[i],i);
    // } 

    // cout<<"mydeque.size() : "<<mydeque.size()<<endl;
    // cout << "Deque d3 : ";
    // for (int i=0; i < 5; i++) {
    //     cout << p[i] << " "; 
    // }
    // cout << '\n';
    
    // // destroy and deallocate:
    // cout<<"mydeque.size() : "<<mydeque.size()<<endl;
    // for (int i=0; i < 5; i++) {
    //     mydeque.get_allocator().destroy(&p[i]);
    // }
    // cout<<"mydeque.size() : "<<mydeque.size()<<endl;
    // mydeque.get_allocator().deallocate(p,5);
    
    // INSERT
    // d1.insert(d1.begin()+2,7);
    // cout<<"Deque d1 : ";
    // for (int i = 0; i < d1.size(); i++)
    // {
    //     cout<<d1[i]<<" ";
    // }
    // cout<<endl;

    // POP_BACK_AND_POP_FRONT
    // d2.pop_back();
    // cout<<"Deque d2 : ";
    // for (auto i = d2.begin(); i != d2.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;
    // d2.pop_front();
    // cout<<"Deque d2 : ";
    // for (auto i = d2.begin(); i != d2.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }

    // PUSH_BACK_AND_PUSH_FRONT
    // cout<<endl;
    // d2.push_back(5);
    // cout<<"Deque d2 : ";
    // for (auto i = d2.begin(); i != d2.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;
    // d2.push_front(1);
    // cout<<"Deque d2 : ";
    // for (auto i = d2.begin(); i != d2.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;

    // RESIZE_AND_SHRINK_TO_FIT
    // d2.resize(10);
    // cout<<"Deque d2 : ";
    // for (auto i = d2.begin(); i != d2.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;
    // cout<<"Size of d2 : "<<d2.size()<<endl;
    // d1.resize(10,1);
    // cout<<"Deque d1 : ";
    // for (int i = 0; i < d1.size(); i++)
    // {
    //     cout<<d1[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"Size of d1 : "<<d2.size()<<endl;
    // d2.resize(2);
    // for (auto i = d2.begin(); i != d2.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<endl;
    // cout<<"Size of d2 : "<<d2.size()<<endl;

    // d1.shrink_to_fit();
    // d2.shrink_to_fit();

    // Shrink to fit
    /*
    Requests the container to reduce its memory usage to fit its size.

    A deque container may have more memory allocated than needed to hold its current elements: this is because most libraries implement deque as a dynamic array that can keep the allocated space of removed elements or allocate additional capacity in advance to allow for faster insertion operations.

    This function requests that the memory usage is adapted to the current size of the container, but the request is non-binding, and the container implementation is free to optimize its memory usage otherwise.

    Note that this function does not change the size of the container 
    */

// SWAP
//    d2.swap(d1);
//    cout<<"Deque d1 : ";
//     for (int i = 0; i < d1.size(); i++)
//     {
//         cout<<d1[i]<<" ";
//     }
//     cout<<endl;
//     cout<<"Deque d2 : ";
//     for (auto i = d2.begin(); i != d2.end(); i++)
//     {
//         cout<<*i<<" ";
//     }
//     cout<<endl;
    
    return 0;
}
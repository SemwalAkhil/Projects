#include <iostream>
#include <vector>
using namespace std;
int main() {
    // BASIC_ELEMENT_ACCESSING
    vector<int> vect = {1,2,3,4};
    // vector<int> vect(4,1);
    cout<<"Size of vector vect : "<<vect.size()<<endl;
    cout<<"{ ";
    for (int i = 0; i < vect.size(); i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<"}\n";

    vector<int> v;
    // vector<int> v(vect);
    cout<<"Size of vector v : "<<v.size()<<endl;
    cout<<"{ ";
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<"}\n";

    // CAPACITY
    cout<<"vect.capacity() : "<<vect.capacity()<<endl; 

    // MAX_SIZE
    cout<<"vect.max_size() : "<<vect.max_size()<<endl; // -> varies based on type of elements being stored

    // // ASSIGN
    // v.assign(5,10);
    // cout<<"v after v.assign(5,10)"<<endl<<"{ ";
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<"}\n";
    // vect.assign(5,10);
    // cout<<"\nvect after vect.assign(5,10)"<<endl<<"{ ";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" ";
    // }
    // cout<<"}";

    // // AT_FRONT_BACK
    // cout<<"vect.at(1) : "<<vect.at(1)<<endl;
    // cout<<"vect.front() : "<<vect.front()<<endl;
    // cout<<"vect.back() : "<<vect.back()<<endl;
    
    // // BEGIN_END
    // cout<<"{ ";
    // for (auto i = vect.begin(); i != vect.end(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<"}"<<endl;
    
    // // RBEGIN_REND
    // cout<<"{ ";
    // for (auto i = vect.rbegin(); i != vect.rend(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<"}"<<endl;

    // // CBEGIN_CEND
    // cout<<"{ ";
    // for (auto i = vect.cbegin(); i != vect.cend(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<"}"<<endl;

    // // CRBEGIN_CREND
    // cout<<"{ ";
    // for (auto i = vect.crbegin(); i != vect.crend(); i++)
    // {
    //     cout<<*i<<" ";
    // }
    // cout<<"}"<<endl;     

    // // CLEAR 
    // v.clear();
    // cout<<"v.size() after v.clear() : "<<v.size()<<endl;   
    // cout<<"v.capacity() after v.clear() : "<<v.capacity()<<endl;   
    
    // // DATA
    // cout<<"{ ";
    // auto p = vect.data();
    // for (int i = 0; i < vect.size(); i++,p++)
    // {
    //     cout<<*p<<" ";
    // }
    // cout<<"}"<<endl;
    
    // // EMPLACE
    // vect.emplace(vect.end(),5);
    // cout<<"{";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" ";
    // }
    // cout<<"}\n";
    
    // // EMPLACE_BACK
    // vect.emplace_back(6);
    // cout<<"{";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" ";
    // }
    // cout<<"}\n";

    // // EMPTY
    // if (vect.empty())
    // {
    //     cout<<"Empty"<<endl;
    // } else {
    //     cout<<"Not Empty"<<endl;
    // }

    // // ERASE
    // vect.erase(vect.begin()+2);
    // cout<<"vect.size() after vect.erase(vect.begin()+2) : "<<vect.size()<<endl;  
    // cout<<"vect.capacity() after vect.erase(vect.begin()+2) : "<<vect.capacity()<<endl; // capacity remains same         
    // cout<<"{ ";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" ";
    // }
    // cout<<"}\n";
    
    // // GET_ALLOCATOR
    // int * arr;
    // // allocate an array with size of vector using vector's allocator:
    // p = vect.get_allocator().allocate(vect.size()); // get_allocator() -> Returns a copy of the allocator object associated with the vector.
    // // construct values in-place on the array:
    // for (int i=0; i<vect.size(); i++) {
    //     vect.get_allocator().construct(&p[i],i);
    // };
    // cout << "The allocated array contains:";
    // for (int i=0; i<vect.size(); i++) {
    //     cout << ' ' << p[i];
    // };
    // cout << '\n';
    // // destroy and deallocate:
    // for (int i=0; i<vect.size(); i++) {
    //     vect.get_allocator().destroy(&p[i]);
    // };
    // vect.get_allocator().deallocate(p,vect.size());

    // // INSERT
    // vect.insert(vect.begin(),4);
    // cout<<"{ ";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" ";
    // }
    // cout<<"}\n";

    // POP_BACK
    // vect.pop_back();
    // cout<<"vect.capacity() : "<<vect.capacity()<<endl; // capacity remains same even after element is popped 
    // cout<<"{ ";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" ";
    // }
    // cout<<"}\n";

    // PUSH BACK
    // vect.push_back(5);
    // cout<<"vect.capacity() : "<<vect.capacity()<<endl; // doubles the previous capacity whenever element is pushed_back
    // cout<<"{ ";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" ";
    // }
    // cout<<"}\n";

    // // RESERVE
    // vect.reserve(10);
    // cout<<"vect.capacity() after reserving 10 blocks : "<<vect.capacity()<<endl;
    // cout<<"vect.size() after reserving 10 blocks : "<<vect.size()<<endl;
    // cout<<"{ ";
    // for (int i = 0; i < vect.capacity(); i++)
    // {
    //     cout<<vect[i]<<" "; // -> reserved elements get garbage value
    // }
    // cout<<"}\n";

    // // RESIZE
    // vect.resize(10);
    // cout<<"vect.capacity() after resizing to 10 blocks : "<<vect.capacity()<<endl;
    // cout<<"vect.size() after resizing to 10 blocks : "<<vect.size()<<endl;
    // cout<<"{ ";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" "; // -> reserved elements get garbage value
    // }
    // cout<<"}\n";

    // // SHRINK_TO_FIT
    // vect.reserve(10);
    // cout<<"vect.capacity() after reserving 10 blocks : "<<vect.capacity()<<endl;
    // vect.shrink_to_fit();
    // cout<<"vect.capacity() after shrink_to_fit : "<<vect.capacity()<<endl;

    // // SWAP
    // v.swap(vect);
    // cout<<"vector v after swap : ";
    // cout<<"{ ";
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<"}\n";
    // cout<<"vector vect after swap : ";
    // cout<<"{ ";
    // for (int i = 0; i < vect.size(); i++)
    // {
    //     cout<<vect[i]<<" ";
    // }
    // cout<<"}\n";

    return 0;
}
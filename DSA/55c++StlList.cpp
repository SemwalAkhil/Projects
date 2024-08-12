#include <iostream>
#include <list>
#include <cmath>
using namespace std;
void listIteration(list<int>& lst){
    cout<<"List : ";
    for (auto i = lst.begin() ; i != lst.end() ; i++)
    {
        cout<< *i <<" ";
    }
    cout<<endl;
}
bool is_odd(const int& val){
    if (( val % 2) == 1 ){
        return true;
    }
    return false;
}
bool diff_grt_2(const int& a,const int& b){
    return (fabs(a-b) > 2);
}
int main(){
    list<int> lst1 = {1,2,3,4,5};
    cout<<"Size of list : "<<lst1.size()<<endl;
    cout<<"Max size of list : "<<lst1.max_size()<<endl;
    /*
    cout<<"List 1 : ";
    for (int i = 0 ; i < lst1.size() ; i++)
    {
        cout<< lst1[i] <<" "; // this way of accessing element not allowed
    }
    cout<<endl;
    */
    cout<<"List 1 : ";
    for (auto i = lst1.begin() ; i != lst1.end() ; i++)
    {
        cout<< *i <<" ";
    }
    cout<<endl;
    /*
    cout<<"List 1 : ";
    for (int i : lst1)
    {
        cout<< i <<" ";
    }
    cout<<endl;
    */
    /*
    cout<<"List 1 : ";
    for (auto i = lst1.cbegin() ; i != lst1.cend() ; i++)
    {
        cout<< *i <<" ";
    }
    cout<<endl;

    cout<<"List 1(reverse) : ";
    for (auto i = lst1.rbegin() ; i != lst1.rend() ; i++)
    {
        cout<< *i <<" ";
    }
    cout<<endl;
    cout<<"List 1(reverse) : ";
    for (auto i = lst1.crbegin() ; i != lst1.crend() ; i++)
    {
        cout<< *i <<" ";
    }
    cout<<endl;
    */
    
    /*
    lst1.assign(2,7);
    listIteration(lst1);
    */

    /*
    cout<<lst1.front()<<endl;
    cout<<lst1.back()<<endl;
    */
    /*
    lst1.emplace(++(++lst1.begin()),100);
    listIteration(lst1);
    lst1.emplace_front(0);
    listIteration(lst1);
    lst1.emplace_back(999);
    listIteration(lst1);
    */
    /*
    // lst1.clear();
    if (lst1.empty()){
        cout<<"Empty"<<endl;
    } else {
        cout<<"Not Empty"<<endl;
    }
    */
    /*
    lst1.erase(++(++lst1.begin()));
    listIteration(lst1);
    lst1.erase(++lst1.begin(),--lst1.end());
    listIteration(lst1);
    */
    /*
    list<int> myList;
    int* p = myList.get_allocator().allocate(5);
    for (int i = 0; i < 5; i++){
        myList.get_allocator().construct(p+i , i);
    }
    cout << "Allocated elements: ";
    for (int i = 0; i < 5; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
    myList.get_allocator().deallocate(p,5);
    */
    /*
    lst1.insert(lst1.begin(),0);
    listIteration(lst1);
    */
    /*
    list<int> lst2 = {6,7,8,9};
    lst1.merge(lst2);
    listIteration(lst1);
    */
    /*
    lst1.pop_back();
    listIteration(lst1);
    lst1.pop_front();
    listIteration(lst1);
    lst1.push_back(1);
    listIteration(lst1);
    lst1.push_front(5);
    listIteration(lst1);
    */
    /*
    lst1.remove(3);
    listIteration(lst1);
    lst1.insert(++(++lst1.begin()),{3,3,5,3});
    listIteration(lst1);
    lst1.remove(3);
    listIteration(lst1);
    */
    /*
    lst1.remove_if(is_odd);
    listIteration(lst1);
    */
    /*
    lst1.resize(10);
    listIteration(lst1);
    lst1.resize(15,2);
    listIteration(lst1);
    lst1.resize(5);
    listIteration(lst1);
    */
    /*
    lst1.reverse();
    listIteration(lst1);
    */
    /*
    lst1 = {2,4,1,5,3};
    listIteration(lst1);
    lst1.sort();
    listIteration(lst1);
    */
    /*
    list<int> lst2 = {6,7,8,9};
    lst1.splice(lst1.end(),lst2);
    // lst1.splice(lst1.end(),lst2,++(++lst2.begin()));
    // lst1.splice(lst1.end(),lst2,++(++lst2.begin()),lst2.end());
    listIteration(lst1);
    */
    /*
    list<int> lst2 = {5,6,7,8,9};
    listIteration(lst1);
    listIteration(lst2);
    lst1.swap(lst2);
    listIteration(lst1);
    listIteration(lst2);
    */
    /*
    lst1 = {1,2,4,8,10,12,20,40};
    listIteration(lst1);
    lst1.unique(diff_grt_2);
    listIteration(lst1);
    lst1 = {1,1,2,2,2,3,3,3,3,4};
    lst1.unique();
    listIteration(lst1);
    */

    return 0;
}
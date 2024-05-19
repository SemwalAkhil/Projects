// 14. Program to determine whether one string is a rotation of another
#include <iostream>
#include <string>
using namespace std;
bool checkRot(string str1,string str2){
    if (str1.length() != str2.length()){
        return false;
    }
    string combined = str1 + str2; // abcdeabcde -> all rotation covered
    if (combined.find(str2) >= 0)
    {
        return true;
    }
    return false;
}
int main() {
    if (checkRot("abcde","deabc")){
        cout<<"Rotation"<<endl;
    }
    else{
        cout<<"Not Rotation"<<endl;
    }
    return 0;
}
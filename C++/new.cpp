#include <iostream>
#include <unistd.h>
using namespace std;

class ProPassword {
public:
    int SetPass, CheckPass;

    int SecurePass() {
        cout << "Set your password: ";
        cin >> SetPass;
        return SetPass;
    }

    int AccessPass() {
        cout << "Enter Your Password: ";
        cin >> CheckPass;
        return CheckPass;
    }
};

int main() {
    ProPassword P;
    int count = 0;
    int SecurePassResult = P.SecurePass();
    int AccessPassResult;

    do {
        AccessPassResult = P.AccessPass();

        if (SecurePassResult == AccessPassResult) {
            cout << "Access Successfully...!!" << endl;
        } else {
            cout << "Access Denied..!!" << endl;
            count += 1;
        }
        if(count == 4 ){
        for(int i=30;i>=1;i--){
            cout<<"Please wait"<<i<<"sec"<<endl;
            sleep(2);
        }
        count = 0;
    }

    } while (SecurePassResult != AccessPassResult && count <= 4);
    
    return 0;
}
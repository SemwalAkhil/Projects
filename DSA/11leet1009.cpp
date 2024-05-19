#include <iostream>
#include <cmath>
using namespace std;
/*
    5 -> 0000....1010
      -> 1111....0101
      -> 0000....1111 -> mask
*/

class Solution{
    public:
    int bitwiseComplement(int n) {
        int comp = ~n;
        int mask = pow(2,int(log2(n)) + 1) - 1;
        int answer = comp & mask;
        return answer;
    }
};
int main() {
    Solution a;
    cout<<a.bitwiseComplement(10)<<endl;
    return 0;
}
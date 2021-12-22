#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0){return 0;}
        int left = 1, right = x, mid, sqrt;
        while(left<=right){
            mid = left+(right-left)/2;
            sqrt = x/mid;
            if(sqrt==mid){
                return sqrt;
            }
            else if(sqrt>mid){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right;
    }
};

int main() {
    // g++ Solution.cpp -o Solution
    Solution s;

    int x1 = 4;
    std::cout<<s.mySqrt(x1)<<endl;

    int x2 = 8;
    std::cout<<s.mySqrt(x2)<<endl;

    int x3 = 0;
    std::cout<<s.mySqrt(x3)<<endl;
}

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int result = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<min){
                min = prices[i];
            }
            else if(prices[i]-min > result){
                result = prices[i]-min;
            }
        }
        return result;
    }
};


int main() {
    // g++ Solution.cpp -o Solution
    Solution s;

    vector<int> prices1 = {7,1,5,3,6,4};
    std::cout<<s.maxProfit(prices1)<<endl;

    vector<int> prices2 = {7,6,4,3,1};
    std::cout<<s.maxProfit(prices2)<<endl;
}

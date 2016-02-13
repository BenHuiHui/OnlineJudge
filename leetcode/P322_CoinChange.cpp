//
//  P322_CoinChange.cpp
//  CppPlayground
//
//  Created by Hui Hui on 13/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        
        vector<int> fewest(amount+1);
        
        //int fewest[amount+1];
        for (int i=0; i<=amount; i++) {
            fewest[i] = 0;
        }
        
        for (int i=1; i<=amount; i++) {
            
            int min = -1;
            for (int j=0; j<coins.size(); j++) {
                
                if (coins[j] <= i) {
                    
                    int am = fewest[i - coins[j]];
                    if (am >= 0 && ( min == -1 || (am+1)<min)) {
                        min = am+1;
                    }
                }
                
            }
            
            fewest[i] = min;
        }
        
        return fewest[amount];
        
    }
    
    /*
    int coinChange(vector<int>&coins, int amount, int *fewest){
        
        if (fewest[amount+1] != 0) {
            return fewest[amount+1];
        }
        
        if (amount == 0) {
            return 0;
        }
        
        int min = -1;
        
        for (int i=0; i<coins.size() && coins[i]<=amount; i++) {
            int k = coinChange(coins, amount-coins[i], fewest);
            if (k>0 && k<min) {
                min = k;
            }
        }
        
        return fewest[amount+1] = -1;
    }
    */
};

int main(int argc, char* argv[]){
    vector<int>coins = {1, 2, 5};
    int amount = 10;
    Solution s;
    cout << s.coinChange(coins, amount);
}

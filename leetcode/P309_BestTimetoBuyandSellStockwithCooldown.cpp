//
//  P309_BestTimetoBuyandSellStockwithCooldown.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 13/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <stdio.h>

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 2) {
            return 0;
        }
        
        vector<int>profit(prices.size(), 0);
        profit[1] = max(0, prices[1] - prices[0]);
        
        for (int i=2; i<prices.size(); i++) {
            
            int prev = profit[i-1];
            
            for (int j=0; j<i; j++) {
                
                int p = prices[i] - prices[j];
                if (j>1) {
                    p += profit[j-2];
                }
                
                if (prev < p) {
                    prev = p;
                }
            }
            
            profit[i] = prev;
        }
        
        
        return profit[profit.size()-1];
    }
};

int main(int argc, char *argv[]){
    vector<int>prices = {1, 2, 3, 0, 2};
    Solution sln;
    cout << sln.maxProfit(prices);
}

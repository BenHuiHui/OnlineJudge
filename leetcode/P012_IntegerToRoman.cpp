//
//  P012_IntegerToRoman.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 12/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        
        string results = "";
        
        while (num >= 1000) {
            results += "M";
            num -= 1000;
        }
        
        //num < 1000
        if (num >= 900) {
            results += "CM";
            num -= 900;
        }
        
        // num < 900
        if (num >= 500) {
            results += "D";
            num -= 500;
        }
        
        if (num >= 400) {
            results += "CD";
            num -= 400;
        }
        
        while (num >= 100) {
            results += "C";
            num -= 100;
        }
        
        //num < 100
        if (num >= 90) {
            results += "XC";
            num -= 90;
        }
        
        if (num >= 50) {
            results += "L";
            num -= 50;
        }
        
        if (num >= 40) {
            results += "XL";
            num -= 40;
        }
        
        while (num >= 10) {
            results += "X";
            num -= 10;
        }
        
        if (num >= 9) {
            results += "IX";
            num -= 9;
        }
        
        if (num >= 5) {
            results += "V";
            num -= 5;
        }
        
        if (num >= 4) {
            num -= 4;
            results += "IV";
        }
        
        while (num > 0) {
            num --;
            results += "I";
        }
        
        return results;
    }
};
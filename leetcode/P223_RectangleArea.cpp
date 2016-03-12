//
//  P223_RectangleArea.cpp
//  LeetCode-Template
//
//  Created by Hui Hui on 10/3/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

class Solution {
public:
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        
        //Overlap
        int h1 = max(A, E);
        int h2 = min(C, G);
        
        int h = h2 > h1 ? h2 - h1 : 0;
        
        int w1 = max(B, F);
        int w2 = min(D, H);
        int w = w2 > w1 ? w2- w1 : 0;
        
        int overlap = 0;
        
        if (h>0 && w>0) {
            overlap = h*w;
        }
        
        
        return area1 + area2 - overlap;
    }
};
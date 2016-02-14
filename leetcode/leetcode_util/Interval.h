//
//  Interval.h
//  CppPlayground
//
//  Created by Hui Hui on 14/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#ifndef Interval_h
#define Interval_h

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

#endif /* Interval_h */

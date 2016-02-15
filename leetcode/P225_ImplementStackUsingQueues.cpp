//
//  P225_ImplementStackUsingQueues.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <queue>

class Stack {
public:
    // Push element x onto stack.
    
    void push(int x) {
        myQueue.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        std::queue<int>newQueue;
        
        while (myQueue.size()>=2) {
            newQueue.push(myQueue.front());
            myQueue.pop();
        }
        
        myQueue.pop();
        while (!newQueue.empty()) {
            myQueue.push(newQueue.front());
            newQueue.pop();
        }
    }
    
    // Get the top element.
    int top() {
        std::queue<int>newQueue;
        
        while (myQueue.size()>=2) {
            newQueue.push(myQueue.front());
            myQueue.pop();
        }
        int a = myQueue.front();
        newQueue.push(a);
        myQueue.pop();
        while (!newQueue.empty()) {
            myQueue.push(newQueue.front());
            newQueue.pop();
        }
        return a;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return myQueue.empty();
    }
    
private:
    
    std::queue<int>myQueue;
};
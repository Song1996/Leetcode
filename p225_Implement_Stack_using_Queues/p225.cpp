#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q.size();
        int t;
        for(int i = 0; i < n-1; i++) {
            t = q.front();
            q.pop();
            q.push(t);
        }
        t = q.front();
        q.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        int n = q.size();
        int t;
        for(int i = 0; i < n-1; i++) {
            t = q.front();
            q.pop();
            q.push(t);
        }
        t = q.front();
        q.pop();
        q.push(t);
        return t;        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


int main () {
	return 0;
}

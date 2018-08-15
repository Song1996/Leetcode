#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

class MyQueue {
public:
    stack<int> s;
    stack<int> t;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        int ans = t.top();
        t.pop();
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        int ans = t.top();
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
        return ans;        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

int main () {
	return 0;
}
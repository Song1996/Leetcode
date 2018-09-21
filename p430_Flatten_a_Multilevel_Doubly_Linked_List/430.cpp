#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        return helper(head).first;
    }
    pair<Node*, Node*> helper(Node* head) {
        Node* p = head;
        pair<Node*, Node*> ans; 
        ans.first = head;
        ans.second = p;
        while(p) {
            if(p->child) {
                pair<Node*, Node*> t = helper(p->child);
                ans.second = t.second;
                p->child = NULL;
                t.second->next = p->next;
                if(p->next) p->next->prev = t.second;
                p->next = t.first;
                t.first->prev = p;
                p = t.second->next;
                continue;
            }
            ans.second = p;
            p = p->next;
        }
        return ans;
    }
};

int main() {
    return 0;
}
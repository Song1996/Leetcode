#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *fp = head, *lp = head;
        bool have_loop = false;
        while(fp&&fp->next) {
            fp = fp->next->next;
            lp = lp->next;
            if(fp==lp) {
                have_loop = true;
                break;
            }
        }
        if(!have_loop) return NULL;
        lp = head;
        while(lp!=fp) {
            fp = fp->next;
            lp = lp->next;
        }
        return fp;
    }
};

int main() {
    int n = 0;
    ListNode* head = new ListNode(n++);
    ListNode* p = head;
    for(int i = 0; i < 10; i ++) {
        p->next = new ListNode(n++);
        p = p->next;
    }
    p->next = head->next->next->next;
    printf("%d %d\n",head->val,p->next->val);
    Solution s;
    printf("%d\n",s.detectCycle(head)->val);
    return 0;
}
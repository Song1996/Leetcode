#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <assert.h>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<1) return NULL;
        ListNode* head;
        ListNode* p;
        bool fflag = true;
        int minp, minval;
        while(true) {
            minp = -1;
            for(int i = 0; i < lists.size(); i++) {
                if(lists[i]==NULL) continue;
                if(minp==-1) {
                    minp = i;
                    minval = lists[i]->val;
                }else if(minval>lists[i]->val) {
                    minp = i;
                    minval = lists[i]->val;
                }
            }
            if(minp==-1) break;
            if(fflag) {
                head = lists[minp]; 
                p = head;
                lists[minp] = lists[minp]->next;
                fflag = false;
            }else {
                p->next = new ListNode(lists[minp]->val);
                p = p->next;
                lists[minp] = lists[minp]->next;
            }
        }
        return head;
    }
};

int main () {
	return 0;
}
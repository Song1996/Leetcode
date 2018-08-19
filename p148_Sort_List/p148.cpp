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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        stack<ListNode*> st;
        ListNode* tail = NULL;
        ListNode* shead = head;
        ListNode* curp;
        ListNode* pivot;
        st.push(head); st.push(tail);
        while(st.size()>0) {
            tail = st.top(); st.pop();
            head = st.top(); st.pop();
            while(head!=tail && head->next!=tail) {
                pivot = head;
                curp  = head->next;
                while(curp!=tail) {
                    if(curp->val < pivot->val) {
                        int t = pivot->val;
                        pivot->val = curp->val;
                        curp->val = pivot->next->val;
                        pivot->next->val = t;
                        pivot = pivot->next;
                    }
                    curp = curp->next;
                }
                if(pivot->next!=tail && pivot->next->next!=tail){
                    st.push(pivot->next);
                    st.push(tail);
                }
                tail = pivot;
            }
        }
        return shead;
    }
};

int main () {
    ListNode* head;
    head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    //head->next->next->next->next = new ListNode(0);
    Solution s;
    s.sortList(head);
    while(head!=NULL) {
        printf("%d ",head->val);
        head = head->next;
    }printf("\n");
	return 0;
}
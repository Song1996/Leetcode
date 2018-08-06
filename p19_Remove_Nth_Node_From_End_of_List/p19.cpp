#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        ListNode* curp1 = head;
        ListNode* curp2 = head;
        for (int i = 0; i < n+1; i++) {
            curp1 = curp1->next;
            if (i<n && curp1==NULL) {
                head = (head->next);
                return head;
            }
        }
        while (curp1) {
            curp1 = curp1->next;
            curp2 = curp2->next;
        }
        curp1 = (curp2->next)->next;
        curp2->next = curp1;
        return head;
    }
};

int main () {
    ListNode* head; ListNode* curp;
    int x[] = {1, 2, 3, 4, 5};
    head = new ListNode(1);
    curp = new ListNode(2);
    head->next = curp;
    for (int i = 3; i < 6; i ++) {
        curp->next = new ListNode(i);
        curp = curp->next;
    }
    curp = head;
    while (curp) {
        printf("%d ",curp->val);
        curp = curp->next;
    }printf("\n");
    Solution s;
    curp = s.removeNthFromEnd(head, 4);
    while (curp) {
        printf("%d ",curp->val);
        curp = curp->next;
    }printf("\n");
}
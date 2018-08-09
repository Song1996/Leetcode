#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<=1) return head;
        int count = 0;
        ListNode* pcur = head;
        ListNode* ncur;
        while (pcur) {
            pcur = pcur->next;
            count ++;
            if (count == k) break;
        }
        if (count < k) return head;
        ncur = head->next;
        head->next = reverseKGroup(pcur,k);
        for ( int i = 0; i < k-2; i ++) {
            pcur = head;
            head = ncur;
            ncur = ncur->next;
            head->next = pcur;
        }
        pcur = head;
        head = ncur;
        head->next = pcur;
        return head;
    }
};

int main () {
    ListNode* head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    head = s.reverseKGroup(head,2);
    while (head) {
        printf("%d ",head->val);
        head = head->next;
    }printf("\n");
}
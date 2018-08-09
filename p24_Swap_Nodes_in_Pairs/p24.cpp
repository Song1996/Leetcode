#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        else if(head->next == NULL) return head;    
        ListNode* temp = head;
        head = head->next;
        temp->next = swapPairs( head->next );
        head->next = temp;
        return head;
        
    }
};

int main () {
    ListNode* head;
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    head = s.swapPairs(head);
    while (head) {
        printf("%d ",head->val);
        head = head->next;
    }printf("\n");
}
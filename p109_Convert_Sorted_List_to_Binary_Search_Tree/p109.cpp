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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        mylist = head;
        return gen(count(head));
    }
    ListNode* mylist;
    int count(ListNode* head) {
        int ans = 0;
        while(head!=NULL) {
            ans ++;
            head = head->next;
        }
        return ans;
    }
    TreeNode* gen(int n) {
        if(n==0) return NULL;
        TreeNode* root = new TreeNode(-1);
        root->left = gen(n/2);
        root->val = mylist->val;
        mylist = mylist->next;
        root->right = gen(n - n/2 -1);
        return root;
    }
    void display(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()>0) {
            TreeNode* t= s.top();
            s.pop();
            printf("%d ",t->val);
            if(t->right!=NULL) s.push(t->right);
            if(t->left!=NULL) s.push(t->left);
        }
        printf("\n");
    }
};

int main () {
    ListNode* x;
    x = new ListNode(-10);
    x->next = new ListNode(-3);
    x->next->next = new ListNode(0);
    x->next->next->next = new ListNode(9);
    x->next->next->next->next = new ListNode(5);
    Solution s;
    TreeNode* y = s.sortedListToBST(x);
    s.display(y);
	return 0;
}
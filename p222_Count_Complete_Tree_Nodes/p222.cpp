#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <assert.h>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        TreeNode* p;
        int hll = 1; p = root->left; while(p!=NULL) {hll++; p = p->left;}
        int hrr = 1; p = root->right; while(p!=NULL) {hrr++; p = p->right;}
        int hrl; int hlr; int ans = 0;
        while(root!=NULL) {
            if(hll==hrr) {
                ans += (1<<hll) - 1;
                break;
            }
            hrl = 1; p = root->right; while(p!=NULL) {hrl++; p = p->left;}
            if(hrl==hrr) {
                ans += (1<<(hrr-1));
                root = root->left;
                hll --;
                hrr = 0; p = root; while(p!=NULL) {hrr++; p = p->right;};
            } else {
                ans += (1<<(hll-1));
                root = root->right;
                hll = hrl - 1; hrr --;
            }
        }
        return ans;
    }
};

int main () {
	return 0;
}
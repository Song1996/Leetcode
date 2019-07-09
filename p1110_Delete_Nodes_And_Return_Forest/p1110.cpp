#include <iostream>
#include <fstream>
#include <sstream>
#include <memory.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_map<int, TreeNode*> val2Node;
        unordered_map<TreeNode*,TreeNode*> node2Par;
        createValNodeMap(root, val2Node);
        createNodeParMap(root, node2Par);
        unordered_set<TreeNode*> mem;
        mem.insert(root);
        for(auto k: to_delete) {
            auto it = val2Node.find(k);
            if(it != val2Node.end()) {
                auto parFindIt = node2Par.find(it->second);
                if(parFindIt != node2Par.end()) {
                    auto par = parFindIt->second;
                    if(par->left == it->second) par->left = NULL;
                    if(par->right == it->second) par->right = NULL;
                }
                if(mem.find(it->second) != mem.end()) 
                    mem.erase(it->second);
                if(it->second->left != NULL) 
                    mem.insert(it->second->left);
                if(it->second->right != NULL) 
                    mem.insert(it->second->right);
            }
        }
        for(auto it: mem) {
            ans.push_back(it);
        }
        return ans;
    }
private:
    void createValNodeMap(TreeNode* root, unordered_map<int, TreeNode*>& val2Node) {
        if(root == NULL) return;
        val2Node[root->val] = root;
        createValNodeMap(root->left, val2Node);
        createValNodeMap(root->right, val2Node);
        return;
    }
    void createNodeParMap(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& node2Par) {
        if(root == NULL) return;
        if(root->left != NULL) node2Par[root->left] = root;
        if(root->right != NULL) node2Par[root->right] = root;
        createNodeParMap(root->left, node2Par);
        createNodeParMap(root->right, node2Par);
        return;
    }
};
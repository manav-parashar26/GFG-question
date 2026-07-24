/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  void findst(Node* root,vector<int> v, vector<vector<int>>& ans) {
        if (!root)
            return;
        v.push_back(root->data);
        if (!root->left && !root->right) {
            ans.push_back(v);
            return;
        }

        findst(root->left,v, ans);
        findst(root->right,v, ans);
    }
    vector<vector<int>> paths(Node* root) {
        vector<vector<int>> ans;
         if (!root)
            return ans;
        findst(root,{}, ans);
        return ans;
        
    }
};
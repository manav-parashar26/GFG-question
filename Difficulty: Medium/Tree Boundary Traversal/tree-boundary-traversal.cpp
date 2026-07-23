/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isleaf(Node *root) {
       return root->left == NULL && root->right == NULL;
    }
    void addlb(Node* root ,vector<int>& res){
        Node* curr = root;
        while(curr){
            if(!isleaf(curr))res.push_back(curr->data);
            if(curr->left)curr = curr->left;
            else curr = curr->right;
        }
    }
    void addrb(Node* root ,vector<int>& res){
        Node* curr = root;
        vector<int> temp; 
        while(curr){
            if(!isleaf(curr))temp.push_back(curr->data);
            if(curr->right)curr = curr->right;
            else curr = curr->left;
        }
        for(int i = temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
        
    }
    void addleaf(Node* root ,vector<int>& res){
        if(root == NULL)return;
        if(isleaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left)addleaf(root->left,res);
        if(root->right)addleaf(root->right,res);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(!root)return res;
        if(!isleaf(root))res.push_back(root->data);
        addlb(root->left,res);
        addleaf(root,res);
        addrb(root->right,res);
        return res;
    }
};
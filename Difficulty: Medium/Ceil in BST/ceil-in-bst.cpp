/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
       int ans = -1;
       while(root){
           if(root->data == x){
               ans = root->data;
               return ans;
           }
           if(x < root->data){
               ans = root->data;
               root = root->left;
           }else root = root->right;
       }
       return ans;
    }
};

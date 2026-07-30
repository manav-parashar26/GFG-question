/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> serialize(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node == NULL) {
                ans.push_back(-1);
            } else {
                ans.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    Node *deSerialize(vector<int> &arr) {
         if (arr.size() == 0) return NULL;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < arr.size()) {

            Node* node = q.front();
            q.pop();

            // Left child
            if (arr[i] != -1) {
                node->left = new Node(arr[i]);
                q.push(node->left);
            }
            i++;

            // Right child
            if (i < arr.size() && arr[i] != -1) {
                node->right = new Node(arr[i]);
                q.push(node->right);
            }
            i++;
        }

        return root;
    }
};
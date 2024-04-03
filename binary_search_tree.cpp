
#include <iostream>
#include <queue>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode *left, *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

    ~TreeNode() {
        delete left;
        delete right;
    }
};

class BinarySearchTree {
private:
    TreeNode *root;

    TreeNode* insert(TreeNode* node, int value) {
        if (!node) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else if (value > node->value) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    TreeNode* search(TreeNode* node, int value) {
        if (!node || node->value == value) {
            return node;
        }
        if (value < node->value) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    TreeNode* findMinimum(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode* deleteNode(TreeNode* node, int value) {
        // Base case: If node is null, return null
        if (!node) return nullptr; 

        // If value is less than current node's value, go left
        if (value < node->value) { 
            // Recursive call on left subtree
            node->left = deleteNode(node->left, value); 
        } 
        // If value is greater than current node's value, go right
        else if (value > node->value) { 
            // Recursive call on right subtree
            node->right = deleteNode(node->right, value); 
        } // Node found: value matches current node's value
        else { 
            // Explicit check for node found
            if (value == node->value) { 
                // Node check for no left child
                if (!node->left) {
                    TreeNode* temp = node->right; // Save right child
                    // Delete current node
                    delete node; 
                    // Return right child
                    return temp; 
                } else if (!node->right) { // Node check for no right child
                    TreeNode* temp = node->left; // Save left child
                    delete node; // Delete current node
                    return temp; // Return left child
                }
                // Node has both children
                TreeNode* temp = findMinimum(node->right); // Find minimum value in right subtree (successor)
                node->value = temp->value; // Replace current node's value with successor's value
                node->right = deleteNode(node->right, temp->value); // Recursive call to delete successor from right subtree
            }
        }
    return node; // Return current node (or its replacement) to maintain BST structure
    }


    void inOrderTraversal(TreeNode* node) {
      // Add code
    }

    void preOrderTraversal(TreeNode* node) {
        // Add Code
    }

    void postOrderTraversal(TreeNode* node) {
        // Add Code
    }

    void printLevelOrder(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                cout << node->value << " ";

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << endl; // New line for each level
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        delete root;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void update(int oldValue, int newValue) {
        root = deleteNode(root, oldValue);
        root = insert(root, newValue);
    }


    // In-order Traversal: Left - Root - Right (LEFT, DATA, RIGHT) (SORTED LIST)
    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }

    // Pre-order Traversal: Root - Left - Right (DATA, LEFT, RIGHT) (BINARY SEARCH)
    void preOrderTraversal() {
        preOrderTraversal(root);
        cout << endl;
    }

   // Post-order Traversal: Left - Right - Root (LEFT, RIGHT, DATA) (DELETE THE WHOLE-TREE/ CLEAN UP MEMEORY)
    void postOrderTraversal() {
        postOrderTraversal(root);
        cout << endl;
    }

    void printLevelOrder(){
        printLevelOrder(root);
        cout << endl;
    }

    
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal: ";
    bst.inOrderTraversal();

    cout << "Pre-order traversal: ";
    bst.preOrderTraversal();

    cout << "Post-order traversal: ";
    bst.postOrderTraversal();

    return 0;
}

#include <iostream>
#include <algorithm> // For the max function
using namespace std;

class AVLTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

public:
    AVLTree() : root(nullptr) {}

    // Function to insert a value into the AVL tree
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Function to search for a value in the AVL tree
    bool search(int value) {
        return searchRec(root, value);
    }

    // Function to perform an in-order traversal of the AVL tree
    void inOrderTraversal() {
        inOrderTraversalRec(root);
        cout << endl;
    }

    // Function to perform a pre-order traversal of the AVL tree
    void preOrderTraversal() {
        preOrderTraversalRec(root);
        cout << endl;
    }

    // Function to perform a post-order traversal of the AVL tree
    void postOrderTraversal() {
        postOrderTraversalRec(root);
        cout << endl;
    }

    // Function to delete a node with a given value from the AVL tree
    void deleteNode(int value) {
        root = deleteNodeRec(root, value);
    }

private:
    // Helper function to get the height of a node
    int height(Node* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Helper function to get the balance factor of a node
    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    // Helper function to update the height of a node
    void updateHeight(Node* node) {
        if (node != nullptr) {
            node->height = 1 + max(height(node->left), height(node->right));
        }
    }

    // Helper function to rotate a subtree rooted with y to the right
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Helper function to rotate a subtree rooted with x to the left
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Helper function to insert a value recursively into the AVL tree
    Node* insertRec(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertRec(node->left, value);
        else if (value > node->data)
            node->right = insertRec(node->right, value);
        else
            return node; // Duplicate values are not allowed

        updateHeight(node);

        // Perform balancing
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // Helper function to search for a value recursively in the AVL tree
    bool searchRec(Node* node, int value) {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;
        else if (value < node->data)
            return searchRec(node->left, value);
        else
            return searchRec(node->right, value);
    }

    // Helper function to perform in-order traversal recursively of the AVL tree
    void inOrderTraversalRec(Node* node) {
        if (node != nullptr) {
            inOrderTraversalRec(node->left);
            cout << node->data << " ";
            inOrderTraversalRec(node->right);
        }
    }

    // Helper function to perform pre-order traversal recursively of the AVL tree
    void preOrderTraversalRec(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderTraversalRec(node->left);
            preOrderTraversalRec(node->right);
        }
    }

    // Helper function to perform post-order traversal recursively of the AVL tree
    void postOrderTraversalRec(Node* node) {
        if (node != nullptr) {
            postOrderTraversalRec(node->left);
            postOrderTraversalRec(node->right);
            cout << node->data << " ";
        }
    }

    // Helper function to find the node with the minimum value in the AVL tree
    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    // Helper function to delete a node with a given value from the AVL tree
    Node* deleteNodeRec(Node* root, int value) {
        if (root == nullptr)
            return root;

        if (value < root->data)
            root->left = deleteNodeRec(root->left, value);
        else if (value > root->data)
            root->right = deleteNodeRec(root->right, value);
        else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNodeRec(root->right, temp->data);
        }

        if (root == nullptr)
            return root;

        updateHeight(root);

        // Perform balancing
        int balance = getBalance(root);

        // Left Left Case
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        // Left Right Case
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        // Right Left Case
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }
};

int main() {
    AVLTree avl;

    // Insert elements into the AVL tree
    avl.insert(50);
    avl.insert(30);
    avl.insert(70);
    avl.insert(20);
    avl.insert(40);
    avl.insert(60);
    avl.insert(80);

    // Perform in-order traversal to print the sorted values
    cout << "Pre-order traversal: ";
    avl.preOrderTraversal();
    cout << "In-order traversal: ";
    avl.inOrderTraversal();
    cout << "Post-order traversal: ";
    avl.postOrderTraversal();

    // Search for a value in the AVL tree
    int searchValue = 40;
    if (avl.search(searchValue)) {
        cout << searchValue << " is found in the AVL tree." << endl;
    } else {
        cout << searchValue << " is not found in the AVL tree." << endl;
    }

    // Delete a node from the AVL tree
    avl.deleteNode(40);
    cout << "Pre-order traversal after deletion: ";
    avl.preOrderTraversal();
    cout << "In-order traversal after deletion: ";
    avl.inOrderTraversal();
    cout << "Post-order traversal after deletion: ";
    avl.postOrderTraversal();

    return 0;
}

/* OUTPUT
Pre-order traversal: 50 30 20 40 70 60 80 
In-order traversal: 20 30 40 50 60 70 80 
Post-order traversal: 20 40 30 60 80 70 50 
40 is found in the AVL tree.
Pre-order traversal after deletion: 50 30 20 70 60 80 
In-order traversal after deletion: 20 30 50 60 70 80 
Post-order traversal after deletion: 20 30 60 80 70 50 
*/

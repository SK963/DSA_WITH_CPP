#include <iostream>
#include <algorithm>
using namespace std;

class AVLTree 
{
private:
    struct Node 
    {
        int data;
        int left;
        int right;
        int height;

        Node() : data(0), left(-1), right(-1), height(1) {}
    };

    Node tree[100];
    int root;  

public:
    AVLTree() : root(-1) {}

    // Function to insert a value into the AVL tree
    void insert(int value) 
    {
        root = insertRec(root, value);
    }

    // Function to search for a value in the AVL tree
    bool search(int value) 
    {
        return searchRec(root, value);
    }

    // Function to perform an in-order traversal of the AVL tree
    void inOrderTraversal() 
    {
        inOrderTraversalRec(root);
        cout << endl;
    }


    void preOrderTraversal() 
    {
        preOrderTraversalRec(root);
        cout << endl;
    }


    void postOrderTraversal() 
    {
        postOrderTraversalRec(root);
        cout << endl;
    }

    // Function to delete a node with a given value from the AVL tree
    void deleteNode(int value) {
        root = deleteNodeRec(root, value);
    }

private:
    // Helper function to get the height of a node
    int height(int index) 
    {
        if (index == -1)
            return 0;
        return tree[index].height;
    }

    // Helper function to get the balance factor of a node
    int getBalance(int index) 
    {
        if (index == -1)
            return 0;
        return height(tree[index].left) - height(tree[index].right);
    }

    // Helper function to update the height of a node
    void updateHeight(int index) 
    {
        if (index != -1) 
        {
            tree[index].height = 1 + max(height(tree[index].left), height(tree[index].right));
        }
    }

    
    // Helper function to create a new node
    int createNode(int value) 
    {
        for (int i = 0; i < 100; ++i) 
        {
            if (tree[i].data == 0) 
            {
                tree[i].data = value;
                tree[i].left = -1;
                tree[i].right = -1;
                tree[i].height = 1;
                return i;   // INDEX 
            }
        }
        return -1; // Tree is full
    }

    // Helper function to rotate a subtree rooted with y to the right
    int rightRotate(int y)
    {
        int x = tree[y].left;
        int T2 = tree[x].right;

        tree[x].right = y;
        tree[y].left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    // Helper function to rotate a subtree rooted with x to the left
    int leftRotate(int x) 
    {
        int y = tree[x].right;
        int T2 = tree[y].left;

        tree[y].left = x;
        tree[x].right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    // Helper function to insert a value recursively into the AVL tree
    int insertRec(int index, int value) 
    {
        if (index == -1)  // EMPTY TREE 
        {
            int newNode = createNode(value);
            return newNode;
        }

        if (value < tree[index].data)
            tree[index].left = insertRec(tree[index].left, value);
        else if (value > tree[index].data)
            tree[index].right = insertRec(tree[index].right, value);
        else
            return index; // Duplicate values are not allowed

        updateHeight(index);

        int balance = getBalance(index);

        if (balance > 1 && value < tree[tree[index].left].data)
            return rightRotate(index);

        if (balance < -1 && value > tree[tree[index].right].data)
            return leftRotate(index);

        if (balance > 1 && value > tree[tree[index].left].data) {
            tree[index].left = leftRotate(tree[index].left);
            return rightRotate(index);
        }

        if (balance < -1 && value < tree[tree[index].right].data) {
            tree[index].right = rightRotate(tree[index].right);
            return leftRotate(index);
        }

        return index;
    }

    // Helper function to find the node with the minimum value in the AVL tree
    int minValueNode(int index) 
    {
        int current = index;

        while (tree[current].left != -1)
            current = tree[current].left;

        return current;
    }

    
    // Helper function to destroy a node
    void destroyNode(int index) 
    {
        if (index != -1)
        {
            tree[index].data = 0;
            tree[index].left = -1;
            tree[index].right = -1;
            tree[index].height = 0;
        }
    }


    // Helper function to delete a node with a given value from the AVL tree
    int deleteNodeRec(int root, int value) 
    {
        if (root == -1)
            return root;

        if (value < tree[root].data)
            tree[root].left = deleteNodeRec(tree[root].left, value);
        else if (value > tree[root].data)
            tree[root].right = deleteNodeRec(tree[root].right, value);
        else 
        {
            if (tree[root].left == -1) 
            {
                int temp = tree[root].right;
                destroyNode(root);
                return temp;
            } 
            else if (tree[root].right == -1)
            {
                int temp = tree[root].left;
                destroyNode(root);
                return temp;
            }

            int temp = minValueNode(tree[root].right);
            tree[root].data = tree[temp].data;
            tree[root].right = deleteNodeRec(tree[root].right, tree[temp].data);
        }

        if (root == -1)
            return root;

        updateHeight(root);

        int balance = getBalance(root);

        if (balance > 1 && getBalance(tree[root].left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(tree[root].left) < 0) {
            tree[root].left = leftRotate(tree[root].left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(tree[root].right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(tree[root].right) > 0) {
            tree[root].right = rightRotate(tree[root].right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrderTraversalRec(int index) {
        if (index != -1) 
        {
            inOrderTraversalRec(tree[index].left);
            cout << tree[index].data << " ";
            inOrderTraversalRec(tree[index].right);
        }
    }
    void preOrderTraversalRec(int index) {
        if (index != -1) 
        {
            cout << tree[index].data << " ";
            preOrderTraversalRec(tree[index].left);
            preOrderTraversalRec(tree[index].right);
        }
    }
    void postOrderTraversalRec(int index){
        if (index != -1) 
        {
            postOrderTraversalRec(tree[index].left);
            postOrderTraversalRec(tree[index].right);
            cout << tree[index].data << " ";
        }
    }
// Helper function to search for a value recursively in the AVL tree
    bool searchRec(int index, int value) {
        if (index == -1)
            return false;

        if (tree[index].data == value)
            return true;
        else if (value < tree[index].data)
            return searchRec(tree[index].left, value);
        else
            return searchRec(tree[index].right, value);
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
    cout << "In-order traversal: ";
    avl.inOrderTraversal();
    cout << "pre-order traversal: ";
    avl.preOrderTraversal();
    cout << "post-order traversal: ";
    avl.postOrderTraversal();

    // Search for a value in the AVL tree
    int searchValue = 40;
    if (avl.search(searchValue))
    {
        cout << searchValue << " is found in the AVL tree." << endl;
    } else {
        cout << searchValue << " is not found in the AVL tree." << endl;
    }

    // Delete a node from the AVL tree
    avl.deleteNode(40);
    cout << "In-order traversal after deletion: "<<endl;
    avl.inOrderTraversal();

    return 0;
}
/* OUTPUT
In-order traversal: 20 30 40 50 60 70 80 
pre-order traversal: 50 30 20 40 70 60 80 
post-order traversal: 20 40 30 60 80 70 50 
40 is found in the AVL tree.
In-order traversal after deletion: 
20 30 50 60 70 80 
*/
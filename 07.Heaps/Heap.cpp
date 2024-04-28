#include <iostream>
#include <climits> // For INT_MAX

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class MinHeap {
private:
    Node* root;

public:
    MinHeap() : root(nullptr) {}

    // Insert an element into the heap
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Extract the minimum element (root) from the heap
    int extractMin() {
        if (root == nullptr) {
            std::cerr << "Heap is empty." << std::endl;
            return INT_MAX;
        }

        int minValue = root->data;
        root = deleteMinRec(root);
        return minValue;
    }

    // Print the heap elements in level order
    void printHeap() {
        if (root == nullptr) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }

        std::cout << "Heap elements: ";
        printHeapRec(root);
        std::cout << std::endl;
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->data = value;
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    Node* deleteMinRec(Node* node) {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }

        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        if (node->left->data < node->right->data) {
            node->data = node->left->data;
            node->left = deleteMinRec(node->left);
        } else {
            node->data = node->right->data;
            node->right = deleteMinRec(node->right);
        }

        return node;
    }

    void printHeapRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        printHeapRec(node->left);
        printHeapRec(node->right);
    }
};

int main() {
    MinHeap minHeap;

    minHeap.insert(4);
    minHeap.insert(2);
    minHeap.insert(6);
    minHeap.insert(1);
    minHeap.insert(3);
    minHeap.insert(5);
    minHeap.insert(7);

    minHeap.printHeap();

    std::cout << "Min element: " << minHeap.extractMin() << std::endl;
    minHeap.printHeap();

    return 0;
}

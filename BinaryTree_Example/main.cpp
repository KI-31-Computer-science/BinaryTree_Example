#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct binary_tree {
private:
    Node* root;

    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    Node* insertNode(Node* root, int data) {
        if (root == nullptr) {
            root = createNode(data);
            return root;
        }
        if (data < root->data) {
            root->left = insertNode(root->left, data);
        }
        else if (data > root->data) {
            root->right = insertNode(root->right, data);
        }
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inOrderTraversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    binary_tree() {
        root = nullptr;
    }

    void insert(int data) {
        root = insertNode(root, data);
    }

    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void deleteNode(int data)
    {
        root = deleteNode(root, data);
    }

    Node* getRoot()
    {
        return root;
    }
};

int main() {
    binary_tree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    bst.insert(65);
    bst.insert(5);
    bst.insert(63);

    bst.deleteNode(20);

    cout << "In-order Traversal: ";
    bst.inOrder();

    return 0;
}
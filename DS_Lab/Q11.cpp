#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};
class BinarySearchTree{
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(int value){
        root = insertNode(root, value);
    }
    void remove(int value){
        root = deleteNode(root, value);
    }
    bool search(int value){
        return searchNode(root, value);
    }
    void inorderTraversal(){
        inorder(root);
        cout << endl;
    }
    void preorderTraversal(){
        preorder(root);
        cout << endl;
    }
    void postorderTraversal(){
        postorder(root);
        cout << endl;
    }
private:
    Node *root;
    Node *insertNode(Node *node, int value){
        if (node == nullptr){
            return new Node(value);
        }
        if (value < node->data){
            node->left = insertNode(node->left, value);
        }
        else if (value > node->data){
            node->right = insertNode(node->right, value);
        }
        return node;
    }
    Node *findMinValueNode(Node *node){
        while (node->left != nullptr){
            node = node->left;
        }
        return node;
    }
    Node *deleteNode(Node *root, int value){
        if (root == nullptr){
            return root;
        }
        if (value < root->data){
            root->left = deleteNode(root->left, value);
        }else if (value > root->data){
            root->right = deleteNode(root->right, value);
        }else{
            if (root->left == nullptr){
                Node *temp = root->right;
                delete root;
                return temp;
            }else if (root->right == nullptr){
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = findMinValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    bool searchNode(Node *root, int value){
        if (root == nullptr){
            return false;
        }
        if (root->data == value){
            return true;
        }
        if (value < root->data){
            return searchNode(root->left, value);
        }
        return searchNode(root->right, value);
    }
    void inorder(Node *node){
        if (node != nullptr){
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }
    void preorder(Node *node){
        if (node != nullptr){
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }
    void postorder(Node *node){
        if (node != nullptr){
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
};
int main(){
    BinarySearchTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    cout << "In-order traversal: ";
    tree.inorderTraversal();
    cout << "Pre-order traversal: ";
    tree.preorderTraversal();
    cout << "Post-order traversal: ";
    tree.postorderTraversal();
    int searchValue = 40;
    if (tree.search(searchValue)){
        cout << searchValue << " found in the tree." << endl;
    }else{
        cout << searchValue << " not found in the tree." << endl;
    }
    int deleteValue = 30;
    tree.remove(deleteValue);
    cout << "Deleted " << deleteValue << " from the tree." << endl;
    cout << "In-order traversal after deletion: ";
    tree.inorderTraversal();
    return 0;
}



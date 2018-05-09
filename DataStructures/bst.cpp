#include <iostream>
using namespace std;

struct BSTNode{
    BSTNode *parent;
    BSTNode *left;
    BSTNode *right;
    int val;
};

class BST{
public:
    BSTNode *root;

    BST();
    BSTNode * search(BSTNode *root, int key);
    void insert(int key);
    void makeExplTree();
    void inorderTreeWalk(BSTNode *node);
    BSTNode * successor(BSTNode *node);
    BSTNode * predecessor(BSTNode *node);
    BSTNode * minimum(BSTNode *root);
    BSTNode * maximum(BSTNode *root);

};


BST::BST() {
    root = NULL;
}

BSTNode *BST::search(BSTNode *root, int key) {
    while(root!=NULL){
        if(key == root->val) return root;
        else if(key < root->val) root = root->left;
        else root = root->right;
    }
    return root;
}

void BST::insert(int key) {
    BSTNode *node = new BSTNode;
    node->val = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    if(root==NULL){
        root = node;
    }
    else {
        BSTNode *tmp = root, *p = root;
        while(tmp!=NULL){
            p = tmp;
            if(key < tmp->val)
                tmp = tmp->left;
            else tmp = tmp->right;
        }
        if(key < p->val)
            p->left = node;
        else p->right = node;
        node->parent = p;
    }
}

void BST::makeExplTree() {
    this->insert(8);
    this->insert(10);
    this->insert(9);
    this->insert(4);
    this->insert(1);
    this->insert(5);
}

void BST::inorderTreeWalk(BSTNode *root) {
    while(root!=NULL){
        inorderTreeWalk(root->left);
        if(root==NULL) cout << "NULL  ";
        else cout << root->val << "  ";
        inorderTreeWalk(root->right);
    }
}

BSTNode *BST::successor(BSTNode *node) {
    if(node->right!=NULL) return minimum(node->right);
    else {
        BSTNode *p = node->parent;
        while(p!=NULL && node == p->left){
            node = p;
            p = p->parent;
        }
        return p;
    }
}

BSTNode *BST::predecessor(BSTNode *node) {
    if(node->left!=NULL) return maximum(node->left);
    else {
        BSTNode *p = node->parent;
        while(p!=NULL && node == p->left){
            node = p;
            p = p->parent;
        }
        return p;
    }
}

BSTNode *BST::minimum(BSTNode *root) {
    if(root==NULL) return NULL;
    while(root->left != NULL) root = root->left;
    return root;
}

BSTNode *BST::maximum(BSTNode *root) {
    if(root==NULL) return NULL;
    while(root->right != NULL) root = root->right;
    return root;
}


int main(){
    BST tree;
    tree.makeExplTree();
    BSTNode *tmp = tree.search(tree.root, 5);
    if(tmp!=NULL)cout << tmp->val;
    cout << endl;
    BSTNode *tmp2 = tree.maximum(tree.root);
    if(tmp2!=NULL)cout << tmp2->val;
    cout << endl;
    BSTNode *tmp3 = tree.minimum(tree.root);
    if(tmp3!=NULL)cout << tmp3->val;
    cout << endl;
}

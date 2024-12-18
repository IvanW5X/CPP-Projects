/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Function definitions for BST and
*                   BST based data structures
* Author: Ivan Wong
****************************************************/

#include "bst.h"

/****************************
 * Node Function Definitions
 ****************************/
TreeNode* BST::addNode(TreeNode* node, TYPE e) {
    //Location for node found
    if (node == nullptr) {
        //Create new node
        TreeNode *newNode = new TreeNode;
        newNode->left = newNode->right = nullptr;

        //Insert data, inc size, return new node
        newNode->val = e;
        this->size++;

        return newNode;
    }
    //New data is less than current node data, go left
    else if (node->val >= e)
        node->left = this->addNode(node->left, e);
    else
    //New data is more and current node data, go right
        node->right = this->addNode(node->right, e);

    //Return node for backtracking
    return node;
}

bool BST::containsNode(TreeNode* node, TYPE e) const {
    //Reached end of tree, return false
    if (node == nullptr)
        return false;
    
    //Val found, return true
    else if (node->val == e)
        return true;
    
    //Data is less than current node, search left
    else if (node->val > e)
        return this->containsNode(node->left, e);
    
    //Data is more than current node, search right
    else
        return this->containsNode(node->right, e);
}

TYPE BST::leftMostNode(TreeNode* node) {
    //Go left until end of tree
    while (node->left != nullptr)
        node = node->left;

    return node->val;
}

TreeNode* BST::removeLeftMostNode(TreeNode* node) {
    //Keep going left until left node doesn't exist
    if (node->left != nullptr) {
        node->left = this->removeLeftMostNode(node->left);

        return node;
    }
    //Get right node and delete the left node obtained through recursion
    TreeNode *temp = node->right;
    delete node;

    return temp;
}

TreeNode* BST::removeNode(TreeNode* node, TYPE e) {
    //Data found
    if (node->val == e) {
        //No right child
        if (node->right == nullptr) {
            //Get left node and delete the matching node
            TreeNode *temp = node->left;
            delete node;

            return temp;
        }
        //Right child exists
        else if (node->right != nullptr) {
            //Get left most value of the right child adn copy the value
            node->val = this->leftMostNode(node->right);

            //Remove the left most node of the right child
            node->right = this->removeLeftMostNode(node->right);
        }
    }
    //Data not found
    else {
        if (node->val > e)
            //Go left
            node->left = this->removeNode(node->left, e);
        else
            //Go right
            node->right = this->removeNode(node->right, e);
    }
    return node;
}

int BST::heightNode(TreeNode* node) const {
    //Nullptr found, return -1
    if (node == nullptr)
        return -1;
    else {
        //Finding height of left subtree
        int leftHeight = this->heightNode(node->left);

        //Finding height of right subtree
        int rightHeight = this->heightNode(node->right);

        //Return the greater height
        if (leftHeight > rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

void BST::freeNode(TreeNode* node) {
    //Post order removal of nodes
    if (node != nullptr) {
        this->freeNode(node->left);
        this->freeNode(node->right);

        delete node;
    }
}

/***************************
 * BST Function Definitions
 ***************************/
BST::BST() {
    this->root = nullptr;
    this->initBst();
}

void BST::initBst() {
    if (this->root != nullptr) {
        std::cout << "\nERROR, TREE ALREADY INITIALIZED\n";
        return;
    }
    this->size = 0;
}

void BST::addBst(TYPE e) {
    //Add node to root, inc size
    this->root = this->addNode(this->root, e);
    this->size++;
}

bool BST::containsBst(TYPE e) const {
    return this->containsNode(this->root, e);
}

void BST::removeBst(TYPE e) {
    if (this->root == nullptr) {
        std::cout << "\nDATA DOES NOT EXIST\n";
        return;
    }
    this->root = this->removeNode(this->root, e);
    this->size--;
}

int BST::heightTree() const {
    return this->heightNode(this->root);
}

void BST::clearBst() {
    this->freeNode(this->root);
    this->size = 0;
}

BST::~BST() {this->clearBst();}

/********************************************
 * Tree Traversal Print Function Definitions
 ********************************************/
void BST::preOrderPrintNode(TreeNode* node) const {
    if (node == nullptr)
        return;
    
    std::cout << node->val << " ";

    this->preOrderPrintNode(node->left);
    this->preOrderPrintNode(node->right);
}

void BST::postOrderPrintNode(TreeNode* node) const {
    if (node == nullptr)
        return;

    this->postOrderPrintNode(node->left);
    this->postOrderPrintNode(node->right);

    std::cout << node->val << " ";
}

void BST::inOrderPrintNode(TreeNode* node) const {
    if (node == nullptr)
        return;
    
    this->inOrderPrintNode(node->left);

    std::cout << node->val << " ";

    this->inOrderPrintNode(node->right);
}

void BST::preOrderPrintTree() const {
    this->preOrderPrintNode(this->root);
    std::cout << std::endl;
}

void BST::postOrderPrintTree() const {
    this->postOrderPrintNode(this->root);
    std::cout << std::endl;
}

void BST::inOrderPrintTree() const {
    this->inOrderPrintNode(this->root);
    std::cout << std::endl;
}

/***************************************
 * AVL Node Helper Function Definitions
 ***************************************/
TreeNode* AVLTree::rightRotation(TreeNode* node) {

}

TreeNode* AVLTree::leftRotation(TreeNode* node) {

}

int AVLTree::balanceFactor(TreeNode* node) const {
    return heightNode(node->right) - heightNode(node->left);
}

TreeNode* AVLTree::AVLTreebalanceTree() {

}

/********************************
 * AVL Tree Function Definitions
 ********************************/
AVLTree::AVLTree() {this->initBst();}

void AVLTree::initAvl() {

}

void AVLTree::addAvl(TreeNode* node, TYPE e) {

}

bool AVLTree::containsAvl(TYPE e) {

}

void AVLTree::removeAvl(TYPE e) {
    return;
}

int AVLTree::heightAvlTree() const {
    return this->heightTree();
}

void AVLTree::clearAvl() {

}

AVLTree::~AVLTree() {this->clearBst();}
/***************************************************
* Project Title: Data Structures
* Date (Started): 7/17/2024
* Date (Finished): TBD
* File Description: Header file for BST and BST based
*                   data structures
* Author: Ivan Wong
****************************************************/

#ifndef BST_H
#define BST_H

#include "types.h"
#include "dyn-array.h"

class BST {
private:
    TreeNode *root;
    int size;
public:

/************************
 * Node Helper Functions
 ************************/
TreeNode* addNode(TreeNode* node, TYPE e);
bool containsNode(TreeNode* node, TYPE e) const;
TYPE leftMostNode(TreeNode* node);
TreeNode* removeLeftMostNode(TreeNode* node);
TreeNode* removeNode(TreeNode* node, TYPE e);
int heightNode(TreeNode* node) const;
void freeNode(TreeNode* node);

/****************
 * BST Functions
 ****************/
BST();
void initBst();
void addBst(TYPE e);
bool containsBst(TYPE e) const;
void removeBst(TYPE e);
int heightTree() const;
void clearBst();
~BST();

/******************
 * Tree Traversals
 ******************/
void preOrderPrintNode(TreeNode* node) const;
void postOrderPrintNode(TreeNode* node) const;
void inOrderPrintNode(TreeNode* node) const;

void preOrderPrintTree() const;
void postOrderPrintTree() const;
void inOrderPrintTree() const;

};

class AVLTree : public BST {
private:
public:

/************************
 * Node Helper Functions
 ************************/
//Incompleted
TreeNode* rightRotation(TreeNode* node);
TreeNode* leftRotation(TreeNode* node);
int balanceFactor(TreeNode* node) const;
TreeNode* AVLTreebalanceTree();

/****************************
 * BST -> AVL Tree Functions
 ****************************/
//Incompleted
AVLTree();
void initAvl();
void addAvl(TreeNode* node, TYPE e);
bool containsAvl(TYPE e);
void removeAvl(TYPE e);
int heightAvlTree() const;
void clearAvl();
~AVLTree();

};

class Heap : public DynArray {
private:
public:
//Incompleted

/************************
 * BST -> Heap Functions
 ************************/

};

#endif
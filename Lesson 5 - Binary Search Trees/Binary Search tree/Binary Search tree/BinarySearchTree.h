//
//  BinarySearchTree.h
//  Binary Search tree
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include"Node.h"

class BinarySearchTree{
private:
    BstNode* root; //pointer to the root
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void destroyTree(BstNode* root);
    BstNode* GetNewNode(int data);
    BstNode* Insert(BstNode* root, int data);
    BstNode* Delete(BstNode* root, int data);
    BstNode* FindMinNode(BstNode* root);
    bool Search(BstNode* root, int data);
    BstNode* getRoot();
    void setRoot(BstNode* rootptr);
};

#endif /* BinarySearchTree_h */

//
//  BinarySearchTree.cpp
//  Binary Search tree
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
    cout<<"DESCRUCTOR CALLED"<<endl;
    destroyTree(root);
}

void BinarySearchTree::destroyTree(BstNode* root){
    if(root == NULL){
        return;
    }
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

BstNode* BinarySearchTree::GetNewNode(int data){

    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
    
}

BstNode* BinarySearchTree::Insert(BstNode* root,int data){
    //we have a few cases
    //1. tree maybe empty
    
    if(root == NULL){
        cout<<"Node:: Inserted"<<endl;
        root = GetNewNode(data);
    }else if(data < root->data){
        //we need to go left;
        root->left = Insert(root->left,data);
    }else if(data > root->data){
        //we need to go right;
        root->right = Insert(root->right,data);
    }else{
        //duplicate
        cout<<"DUPLICATE"<<endl;
    }
    
    return root;
}

BstNode* BinarySearchTree::Delete(BstNode* root, int data){
   
    if(root == NULL){
        return root; //nothing found
    }else if(data < root->data){
       root->left = Delete(root->left,data);
    }else if(data > root->data){
        root->right = Delete(root->right,data);
    }else{
        //node found time to delete
        //case1: no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL; //the node is set to the null
             //so anything that could be pointing to this node as a child, is now poiting to null
        }
        //case2: One  child: right only
        else if(root->left == NULL){ //only has right child
            BstNode* temp = root; //store the address of the current node;
            root = root->right;
            delete temp;
    
        }
        //case2: One child: left only
        else if(root->right == NULL){ //only has left child
            BstNode* temp = root; //store the address of the current node;
            root = root->left;
            delete temp;
        }
        //case3: 2 children
        else{
            BstNode* temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
        
        return root;
    }
    
    return root;
    
}

BstNode* BinarySearchTree::FindMinNode(BstNode* root){
    //we just have to keep going to the very far left;
    if(root == NULL){
        cout<<"ERROR: Tree is Empty"<<endl;
        return root;
    }
    BstNode* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    
    return current;
}

BstNode* BinarySearchTree::getRoot(){
    return root;
}

void BinarySearchTree::setRoot(BstNode* rootptr){
    root = rootptr;
}

bool BinarySearchTree::Search(BstNode* root, int data){
    if(root == NULL){
        return false;
    }else if(root->data == data){
        return true;
    }else if(data <= root->data){
        //go left
        return Search(root->left,data);
    }else{
        //go right
        return Search(root->right,data);
    }
}

//
//  BinarySearchTree.h
//  template binary tree
//
//  Created by Raman Nakarmi on 12/11/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

//when using templates it is better to define functions in h file.

#ifndef BinarySearchTree_h
#define BinarySearchTree_h
#include<iostream>

using namespace std;



template<class T>
class BinarySearchTree{
private:
    
    struct bstNode{
        bstNode* left;
        bstNode* right;
        T data;
    };
    typedef bstNode* nodeptr;
    typedef bstNode node;
    nodeptr root;
    
public:
    BinarySearchTree();//constructor
    bool isEmpty();
    void print_inOrder();
    void inOrder(bstNode* root);
    void print_postOrder();
    void postOrder(bstNode* root);
    void insert(T data);
    void remove(T data);
    bool search(T data);
    nodeptr findMinNode(nodeptr node){
        nodeptr current = node;
        nodeptr parent = current;
        while(current!= NULL){
            parent = current;
            current = current->left;
        }
        return parent;
    }
};

template<class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
}

template<class T>
bool BinarySearchTree<T>::isEmpty(){
    return root==NULL;
}

template<class T>
void BinarySearchTree<T>::inOrder(bstNode* root){
    if(root!=NULL){
        if(root->left)
            inOrder(root->left);
        cout<<" "<<root->data<<" ";
        if(root->right)
            inOrder(root->right);
        
    }else  return;
}

template<class T>
void BinarySearchTree<T>::postOrder(bstNode* root){
    
}

template<class T>
void BinarySearchTree<T>::print_inOrder(){
    inOrder(root);
    
}

template<class T>
void BinarySearchTree<T>::print_postOrder(){
    
}

template<class T>
void BinarySearchTree<T>::insert(T data){ //non recursive
    
    nodeptr newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    nodeptr current = root;
    nodeptr parent = NULL;
    
    if(isEmpty()){
        //first thing in the tree
        root = newNode;
        return;
    }
    
    while(current!=NULL){
        parent = current; //trying to find of the parent of the newNode;
        if(newNode->data <= current->data){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    
    if(newNode->data <= parent->data){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }
    
    return;
}

template<class T>
void BinarySearchTree<T>::remove(T data){
    
    bool found = false;
    if(isEmpty()){
        cout<<"Tree Empty"<<endl;
        return;
        
    }
    
    nodeptr current;
    nodeptr parent;
    current = root;
    parent = NULL;
    while(current != NULL){
        if(current->data == data){
            found = true;
            break;
        }else{
            parent = current;
            if(data <= current->data){
                current = current->left;
            }else{
                current = current->right;
            }
        }
    }
    
    //After the while loop we know whether the item exists, and if it does we know what node it is, and its parent.
    
    if(!found){
        cout<<"There was no item to be deleted"<<endl;
        return;
    }
    //if found is true
    
    //case 1: No child
    if(current->left == NULL && current->right == NULL){
        if(parent == NULL){
            delete current;
        }else{
            if(parent->left == current){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
            delete current;
        }
        
        return;
        
    }
    
    //case 2: One child
    if((current->left == NULL && current->right != NULL) || (current->left != NULL && current->right == NULL)){
        //if only right child or only left child;
        if(current->left == NULL && current->right != NULL){
            //node to be deleted only has right child
            if(parent->left == current){
                //if the node to be deleted is the left child of its parent
                parent->left = current->right;
                delete current;
            }else{
                parent->right = current->right;
                delete current;
            }
        }else{
            //node to be deleted only has left child
            if(parent->left == current){
                //if the node to be deleted is the left child of its parent
                parent->left = current->left;
                delete current;
            }else{
                parent->right = current->left;
                delete current;
            }
        }
        return;
    }
    
    //case 3: Two children
    if(current->left != NULL && current->right != NULL){
        //find the minimum value in the right subtree
        nodeptr checker;
        checker = current->right;
        if(checker->left == NULL && checker->right == NULL){
            //if the immediate right child has no children
            current = checker;
            delete checker;
            current->right = NULL;
        }else{
            if(checker->left!= NULL){
                nodeptr leftCurrent;
                nodeptr leftCurrentParent;
                leftCurrentParent = checker;
                leftCurrent = checker->left;
                while(leftCurrent != NULL){
                    leftCurrentParent = leftCurrent;
                    leftCurrent = leftCurrent->left;
                }
                current->data = leftCurrentParent->data;
                delete leftCurrent;
                delete leftCurrentParent;
            }else{
                current->data = checker->data;
                current->right = checker->right;
                delete checker;
            }
        }
        
        delete checker;
    }
    
}

template<class T>
bool BinarySearchTree<T>::search(T data){
    bool found = false;
    if(isEmpty()){
        cout<<"Tree is empty"<<endl;
        return false;
    }
    
    nodeptr current = root;
    nodeptr parent = NULL;
    while(current != NULL){
        if(data == current->data){
            found = true;
            break;
        }else if(data < current->data){
            parent = current;
            current = current->left;
        }else{
            parent = current;
            current = current->right;
        }
        
    }
    
    if(!found){
        return false;
    }else{
        return true;
    }
    
    
}



#endif /* BinarySearchTree_h */

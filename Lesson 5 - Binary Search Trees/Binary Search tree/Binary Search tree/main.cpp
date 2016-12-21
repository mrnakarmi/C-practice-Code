//
//  main.cpp
//  Binary Search tree
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"

using namespace std;


int main(){
    
    BinarySearchTree bst;
    bst.setRoot(bst.Insert(bst.getRoot(), 15));
    bst.setRoot(bst.Insert(bst.getRoot(), 10));
    bst.setRoot(bst.Insert(bst.getRoot(), 20));
    bst.setRoot(bst.Insert(bst.getRoot(), 11));
    bst.setRoot(bst.Insert(bst.getRoot(), 17));
    bst.setRoot(bst.Insert(bst.getRoot(),9));
    bst.setRoot(bst.Insert(bst.getRoot(), 9));//should not insert because it is a duplicate
    
    bst.Delete(bst.getRoot(), 10);
    bst.Delete(bst.getRoot(),9);
    
    cout<<"The minimum value in the tree is: "<<bst.FindMinNode(bst.getRoot())->data<<endl;
    
    int number = 0;
    
    cout<<"Enter the number to be searched"<<endl;
    cin>>number;
    if(bst.Search(bst.getRoot(), number) == true){
        cout<<"Item found!"<<endl;
    }else{
        cout<<"Item not found!"<<endl;
    }
    
    return 0;
}

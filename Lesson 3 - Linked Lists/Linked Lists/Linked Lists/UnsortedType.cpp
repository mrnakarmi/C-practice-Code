//
//  UnsortedType.cpp
//  Array Based Lists
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include "UnsortedType.h"
#include <stdio.h>
#include<iostream>
using namespace std;

//O(1)
UnsortedType::UnsortedType(){
    length = 0;
    start = NULL; //nothing in the list
}

//O(1)
void UnsortedType::InsertItem(int item){
    //not bound in size like an array
    NodeType* temp = new NodeType;
    temp->data = item;
    temp->next = start; //now holds the address of what start was pointing to.
    
    /*Insert first mentality
     This new item will now be pointing to whatever start was pointing to now
     And start will now be pointing to this new item
     So we insert at the beginning of the linked list
     And change start to reflect that the new item inserted is in the beginning*/
    
    start = temp; //start is now pointing to the new item inserted
    length++;
}

//O(1)
bool UnsortedType::IsFull()const{
    //A linked list is only full if it is out of memory
    //so we try to allocate a new node, and if it throws bad memory then we know it's full.
    NodeType* location;
    try{
        location = new NodeType;
        delete location;//we just wanted to see if there was room, so we remove it once it's job is done.
        return false;
    }
    catch(bad_alloc exception){
        return true;
    }
}

//O(n)
//We can't just make Start point to NULL like we did with length in arrays because then we will have memory issues.
//In java this won't be a problem.
void UnsortedType::MakeEmpty(){
    NodeType* temp;
    /*We have to use temp because if we just directly manipulate 'start' and use it to transit down the list,
     we will lose access to the previous things, and it gets ugly.*/
    
    while(start!=NULL){ //We need to keep repeating the process until Start points to null, and it that case it means that the list is empty
        temp = start;
        start = start->next;
        //we just did delete start, how are we supposed to access the next items that might exist?
        delete temp; //so here we just deleted the first thing in the node, then told start to point to the next thing. It will loop just like this
    }
    length = 0;
    
}

//O(1)
int UnsortedType::GetLength() const{
    return length;
}

//O(n)
void UnsortedType::Show(){
    NodeType* temp = start;
    
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    
    delete temp;
}

//O(n)
void UnsortedType::DeleteItem(int item){
    /*Not only do we have to delete,
     but we also have to repair the link after deleting the node*/
    
    if(start!=NULL){
        NodeType* temp = start;
        if(item == start->data){
            //item we want to delete is in the first node
            start = start->next;
            delete temp;//if you don't delete temp, then there is a dangling pointer
            length--;
        }else{
            //need to set a loop to go through each one
            while(temp->next != NULL && (item != temp->next->data)){
                //first,the next thing is not null
                //and the next item is not the node containing the item (the target).
                // so if the next thing is not the target, we are going to go to the next one.
                
                temp = temp->next;
                
            }
            
            NodeType* target = temp->next; // we get here after realizing that the next item is the one we want to delete
            
            if(target!=NULL){ //if it is NULL then the node never existed
                temp->next = target->next; //temp->next = temp->next->next; //basically jump over the target
                delete target;
                length--;
                
            }
        }
    }
    
}

//O(n)
UnsortedType::~UnsortedType(){
    MakeEmpty();
}


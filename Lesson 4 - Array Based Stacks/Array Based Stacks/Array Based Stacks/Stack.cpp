//
//  Stack.cpp
//  Array Based Stacks
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"

//O(1)
Stack::Stack(int size){
    maxStackSize = size;
    initializeStack();
    list = new int[maxStackSize];
}

//O(1)
void Stack::initializeStack(){
    stackTop = 0; // logically no items in the stack, but in reality there could be, but array helps us create this illusison
}

//O(1)
bool Stack::isEmptyStack() const{
    return stackTop == 0;
}

//O(1)
bool Stack::isFullStack() const{
    return stackTop == maxStackSize;
}

//O(n)
Stack::Stack(const  Stack& otherStack){
    //copy constructor
    //This builds a class(stack) based on another stack
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new int[maxStackSize];
    
    for(int i = 0; i < stackTop; i++){ //not maxStackSize because we want to only copy the occupied indexes.
        list[i] = otherStack.list[i];
    }
    
}

//O(1)
int Stack::top()const{
    if(isEmptyStack()){
        return -9999;
    }else{
        return list[stackTop - 1];
    }
}

//O(1)
void Stack::push(int newItem){
    if(!isFullStack()){
        list[stackTop] = newItem;
        stackTop++; //preparing for the next item
    }
    
}

//O(1)
void Stack::pop(){
    if(!isEmptyStack()){
        stackTop--; //the next push will just replace what is currently there
    }
}

//O(1)
Stack::~Stack(){
    delete[]list;
}




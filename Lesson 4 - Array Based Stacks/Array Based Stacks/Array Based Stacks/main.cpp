//
//  main.cpp
//  Array Based Stacks
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
    Stack firstStack(5); //maxStackSize = 5; stackTop = 0;
    
    firstStack.push(5);//now stackTop = 1;
    firstStack.push(15);//now stackTop = 2;
    firstStack.push(25);//now stackTop = 3;
    firstStack.push(35);//now stackTop = 4;
    firstStack.push(45);//now stackTop = 5; //stackTop = maxStackSize, so isFullStack() == true;
    
    cout<<"Top of the first stack: "<<firstStack.top()<<endl;
    Stack secondStack(firstStack); //copy constructor
    cout<<"Top of the second stack: "<<secondStack.top()<<endl;
    
    firstStack.push(500);//this should not happen because the stack is already full
    
    firstStack.pop();
    cout<< "First stack top after pop(): " << firstStack.top() <<endl;
    
    
    
    firstStack.initializeStack(); //sets stackTop = 0, making isEmptyStack() = true;
    cout<<"After initliazeStack() on the firstStack: "<<firstStack.top()<<endl;
    
    return 0;
}

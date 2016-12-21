//
//  Stack.h
//  Array Based Stacks
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

class Stack{
public:
    bool isEmptyStack() const; //const function will not modify any member variables
    bool isFullStack() const;
    void initializeStack();
    Stack(int size);
    Stack(const Stack& otherStack); //copy constructor //passing as reference to save memory, since we only need the data
                                    //const to ensure we don't modify anything about the reference that is passed
    int top() const;
    void push(int newItem);
    void pop();
    ~Stack();
    
private:
    int maxStackSize;
    int stackTop; //top of the list
    int* list;
};


#endif /* Stack_h */

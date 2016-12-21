//
//  UnsortedType.h
//  Array Based Lists
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#ifndef UnsortedType_h
#define UnsortedType_h

#include "NodeType.h"
//what do we want to expose to the user?

class UnsortedType{
public:
    //This is what we give to the users
    //They don't know how this is implemented but they just care that they can use it.
    UnsortedType();//constructor
    void MakeEmpty(); //the user calls it to make the data structure empty
    bool IsFull() const; //if data structure is full then it returns true //const makes it so that it can't change member fields.
    int GetLength() const;//how many elements in the collection
    void InsertItem(int item);
    void DeleteItem(int item);
    void Show();
    ~UnsortedType();
    
private:
    int length; //we still need this to make sure we can use it to maximize runtimes. Such as in getLength(),etc.
    NodeType* start;
    
};


#endif /* UnsortedType_h */

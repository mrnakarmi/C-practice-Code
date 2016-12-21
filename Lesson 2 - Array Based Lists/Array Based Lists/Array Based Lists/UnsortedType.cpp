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
}

//O(1)
void UnsortedType::InsertItem(int item){
    //we want to aim for O(1);
    if(IsFull()){
        cout<<"The data Structure is full."<<endl;
        return;
    }
    info[length] = item; //inserts at the end of the array
    length++;//increments to prepare for the next insertion
}

//O(1)
bool UnsortedType::IsFull()const {
    return(length == 10); //remember you can't insert more than 0-9, so if the next index is 10 then the array is full.
}

//O(1)
void UnsortedType::MakeEmpty(){
    //how would we make the array in O(1) runtime? Dont you have to loop through? NO!
    //REMEMBER: You just need to make the array "apparently" empty not actually empty.
    
    length = 0; //let's you overwrite the values when insert is called.
    
    //the array is not actually empty but this allows the user to insert from the very beginning again, so the array is basically empty to the user
    
}

//O(n)
//depends on how big the array is
void UnsortedType::DeleteItem(int item){
    /*so how would you make this as efficient as it can be?
    we need to find the item.
        Once found do we set it to 0? What is the most efficient thing to do?
        Maybe delete it and shift everything in the array?
     
     Looping through, and finding the item, and then shifting is inefficient
     
     REMEMBER the array is unsorted! It just needs to reflect that the item is deleted and the length is adjusted.
     So we can just take the last element value and use it to overwrite the found item*/
    
    for(int i = 0; i < length; i++){
        if(info[i] == item){
            //found item
            //doesn't consider duplicates
            info[i] = info[length-1]; //length would be pointing to an empty index for insert, so we use length-1;
            length--;
        }
    }
    
}

void UnsortedType::Show(){
    for(int i = 0; i < length; i++){
        //if we use '10', which is the array size, then it will show indexes that might be empty at the time the function is called.
        //Another problem with using the actual array size, is that our make empty isn't actually making the array empty so it might confuse the user to see that the length is 0 but show() is still showing all these fields that should have been deleted.
        //we need to use length instead
        cout<<info[i]<<endl;
    }
}


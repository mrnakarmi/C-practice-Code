//
//  main.cpp
//  Interview Studying
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include <iostream>

using namespace std ;

int* testArray;
int arraySize;

//Big O: O(n)
void DisplayArray(){
    for(int i = 0; i < arraySize; i++){
        //this is O(n) because the amount of comparisons we have depends on how many elements we have.
        cout<<testArray[i]<<endl;
    }
}

//Big O: O(1)
void InsertInFirstSlot(int value){
    //This is O(1) because it doesn't matter how many elements there are it just does 1 operation of changing the 1st value.
    //constant  time.
    testArray[0] = value;
}

int main(){
    cout<<"Enter Array Size: "<<endl;
    cin>>arraySize;
    testArray = new int[arraySize];
    InsertInFirstSlot(500);
    DisplayArray();
    delete[] testArray;
    return 0;
}

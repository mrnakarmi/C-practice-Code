//
//  main.cpp
//  Array Based Lists
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include <iostream>
#include "UnsortedType.h"
using namespace std;

int main(){
    
    UnsortedType ust;
    ust.InsertItem(5);
    ust.InsertItem(6);
    ust.InsertItem(7);
    ust.InsertItem(8);
    ust.DeleteItem(6); /*Finds 6 and then copies it with 8, and makes length go down by 1*/
    ust.MakeEmpty();
    ust.InsertItem(100);
    ust.Show();
    return 0;
    
}

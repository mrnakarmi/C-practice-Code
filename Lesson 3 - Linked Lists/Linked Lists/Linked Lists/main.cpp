//
//  main.cpp
//  Linked Lists
//
//  Created by Raman Nakarmi on 12/10/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include <iostream>
#include"UnsortedType.h"

using namespace std;

int main(){
    
    UnsortedType ust;
    ust.InsertItem(5);
    ust.InsertItem(6);
    ust.InsertItem(7);
    ust.DeleteItem(6);
    ust.MakeEmpty();
    cout<<"Length: "<<ust.GetLength()<<endl;
    ust.DeleteItem(65); 
    ust.Show();
    return 0;
}

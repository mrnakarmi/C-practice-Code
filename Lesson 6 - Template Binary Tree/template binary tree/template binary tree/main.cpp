//
//  main.cpp
//  template binary tree
//
//  Created by Raman Nakarmi on 12/11/16.
//  Copyright © 2016 Raman Nakarmi. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    BinarySearchTree<int> bst;
    char ch;
    int number;
    while(1){
        cout<<"i to insert"<<endl;
        cout<<"r to remove"<<endl;
        cout<<"s to search"<<endl;
        cout<<"p to print"<<endl;
        cout<<"e to exit"<<endl;
        cout<<"Please select an option: "<<endl;
        cin>>ch;
        switch(ch){
            case 'i': cout<<"Insert Mode"<<endl;
                cout<<"Please Insert a number to be inserted"<<endl;
                cin>>number;
                cout<<"The number to be inserted is: "<<number<<endl;
                bst.insert(number);
                break;
                
            case 'r': cout<<"Removal Mode"<<endl;
                cout<<"Please select the data of the node"<<endl;
                cin>>number;
                cout<<"The number to be deleted is: "<<number<<endl;
                bst.remove(number);
                break;
                
            case 's': cout<<"Search Mode"<<endl;
                cout<<"Please input the number to be searched"<<endl;
                cin>>number;
                cout<<"The number to be searched: "<<number<<endl;
                if(bst.search(number)){
                    cout<<"Valid Node"<<endl;
                }else{
                    cout<<"Invalid Node"<<endl;
                }
                
            case'p': cout<<"Printing InOrder"<<endl;
                bst.print_inOrder();
                cout<<endl;
                break;
                
            case 'e': cout<<"Exiting"<<endl;
                return 0;
                break;
                
        }
    
    }
    
    return 0;
}

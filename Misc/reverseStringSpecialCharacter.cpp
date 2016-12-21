/*Reverse an array without affecting special characters
Ab,c,de!$ -> ed,c,bA!$ */

#include <iostream>
#include<string>

using namespace std;

bool isAlphabet(char x){
	if((x >= 'A' && x <= 'Z')||(x >= 'a' && x <= 'z')){
		return true;
	}else{
		return false;
	}
}

void reverse(string& str){
	int r =str.length()-1; //the last character
	int l = 0; //the first character
	while(l < r){
		if(!isAlphabet(str[l])){ //if it is not an alphabet just go to the next one
			l++;
		}else if (!isAlphabet(str[r])){
			r--;
		}else{
			swap(str[l],str[r]);
			l++;
			r--;
		}
	}
}

int main(){
	string str = "a!!b.c.d,e'f,ghi";
	cout<<"Input: "<<str<<endl;
	reverse(str);
	cout<<str<<endl;
	return 0;
}
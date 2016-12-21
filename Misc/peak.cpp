#include <iostream>
#include<string>

using namespace std;

const int SIZE = 10;

void findPeak(int arr[],int arrSize){
	cout<<"findPeak:: Entered"<<endl;
	int peak = 0;
	for (int i = 1; i < arrSize - 1 ; i++){
		//starts at the second element and checks till the second to last element
		if(arr[i] > arr[i-1] && arr[i] > arr[i+1]){
			//a peak is found
			cout<<"findPeak:: Peak found: "<<arr[i]<<endl;
			
			if(peak == 0){
				peak = arr[i];
			}
			
			if(arr[i] < peak){
				//is the new found peak lower than the current peak?
				peak = arr[i];
			}
		}
		
	}
	
	if(peak == 0){
		cout<<"findPeak:: No real peak found"<<endl;
	}else{
		cout<<"findPeak:: Lowest peak = "<<peak<<endl;
	}
	
}

int main(){
	int arr[] = {5,8,7,9,6,1,3,2,11,10};
	int arrSize = sizeof(arr)/sizeof(arr[0]);
	cout<<"arr size: "<<arrSize<<endl;
	int arr2[SIZE] = {0,1,2,3,4,5,6,7,8,9};
	int arr3[] = {}
	findPeak(arr,arrSize);
	findPeak(arr2,SIZE);
	return 0;
}
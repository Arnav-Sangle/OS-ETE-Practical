//Fork Process

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

void selectionSort(int arr[], int n) {

	int min;
	
	for(int i=0; i<n-1; i++) {
		min = i;
		for(int j=i+1; j<n; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		
		if (min != i)
			swap(arr[min], arr[i]);
	}
	
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}

}

void bubbleSort(int arr[], int n) {
	bool swapped;
	
	for(int i=0; i<n-1; i++) {
		swapped = false;
		for(int j=0; j<n-i-1; j++) {
			if(arr[j] < arr[j+1]) {
				swap(arr[j], arr[j+1]);
				swapped = true;
			} 
		}
		
		if (swapped == false)
			break;
		
	}
	
	for(int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
}

int main() {
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
	
	int arr[n];
	cout<<"Enter elements: ";
	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}
	
	int p = fork();
	int childPid, waitstatus;
	if( p > 0 ) {
		cout<<endl<<"---------Parent Process---------"<<endl;
		cout<<"Parent Process ID: "<<getpid()<<endl;
		cout<<"Child Process ID: "<<p<<endl;
		
		childPid = wait(&waitstatus);
		
		cout<<endl<<"---------Parent Process---------"<<endl;
		cout<<"Child Process returned: "<<childPid<<endl;
		cout<<"Sorted array in ascending order: ";
		selectionSort(arr, n);
		cout<<endl;
	}
	else {
		cout<<endl<<endl<<"----------Child Process----------"<<endl;
		cout<<"Child Process ID: "<<getpid()<<endl;
		cout<<"Parent Process ID: "<<getppid()<<endl;
		
		cout<<"Sorted array in descending order: ";
		bubbleSort(arr, n);
		cout<<endl;
		exit(0);
	}
	
	return 0;

}

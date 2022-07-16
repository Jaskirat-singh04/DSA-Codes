#include <iostream>
#include <algorithm>
using namespace std;
// int j=0;
void pattern( int* arr, int n)
{
	int curr_val = n * (n + 1) / 2;
	for (int i = n; i >= 1; i--) {
		for ( int j = i; j >= 1; j--) {
            arr[j]=curr_val;
            curr_val--;
            
		}
         	for ( int j = 1; j <= i; j++) {
          
            sort(arr,arr+j);
            cout<<arr[j]<<"\t";
            
		} 
       

		cout << endl;
	}
}

int main()
{
	
   
    int n ;
    cout<<"enter input \t";
    cin>>n;
    int *arr= new int[n];
    for(int i=0;i<n;i++){
        arr[i]=0;
    }
	pattern(arr,n);
	return 0;
}



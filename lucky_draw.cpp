#include <bits/stdc++.h>

using namespace std;
void lis1( int arr[], int n ,int lis[])
{
    int  i, j;
 //   lis = (int*) malloc ( sizeof( int ) * n );
 
    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++ )
        lis[i] = 1;
 
    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++ ){
        for (j = 0; j < i; j++ ) {
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            //    cout<<arr[i]<<" ";
            }
        }        
    }
 
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[2*n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			arr[i+n]=arr[i];
		}
		int lis[2*n];
		lis1(arr,2*n,lis);
		int maxm=0;
		for(int i=0;i<2*n;i++){
			maxm=max(maxm,lis[i]);
		}
		cout<<maxm<<endl;
	}
	return 0;
}

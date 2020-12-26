// This is a program for printing this pattern

// 	1  2  3  4  5
// 	16 17 18 19 6
// 	15 24 25 20 7
// 	14 23 22 21 8
// 	13 12 11 10 9
// 



#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int arr[n][n];
	int curr =1;
	int x = 0,y=0;
	int cnt = 0;
	int bor = 0;
	int mx = n-bor-1;
	for(int i=0;i<(n/2+n%2);i++){
		for(int j=bor;j<=mx;j++){
			arr[bor][j]=curr;
			curr++;
		}
		for(int j=bor+1;j<=mx;j++){
			arr[j][mx] = curr;
			curr++;
		}
		for(int j=mx-1;j>=bor;j--){
			arr[mx][j] = curr;
			curr++;
		}
		for(int j = mx-1;j>bor;j--){
			arr[j][bor] = curr;
			curr++;
		}
		bor++;
		mx--;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cout<<arr[i][j]<<" ";
			cout<<endl;
	}

	
}
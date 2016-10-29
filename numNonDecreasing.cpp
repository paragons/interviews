#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int dp[n+1][10];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<10;i++)
			dp[1][i]=1;
		for(int i=2;i<=n;i++){
			for(int j=0;j<=9;j++){
				for(int k=0;k<=j;k++)
					dp[i][j]+=dp[i-1][k];
			}
		}
		int num=0;
		for(int i=0;i<10;i++)
			num+=dp[n][i];
		cout<<num<<endl;
	}
	return 0;
}

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,sum;
	    cin>>n>>sum;
	    int dp[n+5][sum+5];
	    memset(dp,0,sizeof(dp));
	    dp[0][0]=1;
	    int m=min(9,sum);
	    for(int i=0;i<=m;i++)
	        dp[1][i]=1;
	    for(int i=2;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            for(int k=0;k<=9;k++){
	                if(k<j)
	                    dp[i][j]= (dp[i-1][j-k]+dp[i][j])%mod;
	            }
	        }
	    }
	    if(dp[n][sum]==0)
	        cout<<-1<<endl;
	   else
	        cout<<dp[n][sum]<<endl;
	}
	return 0;
}

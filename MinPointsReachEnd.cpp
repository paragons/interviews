#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    int a[m][n],dp[m][n];
	    for(int i=0;i<m;i++)
	    for(int j=0;j<n;j++)
	        cin>>a[i][j];
	    dp[m-1][n-1]=(a[m-1][n-1]<=0?abs(a[m-1][n-1])+1:0);
	    for(int i=m-1;i>=0;i--)
	    for(int j=n-1;j>=0;j--){
	        if(i==m-1 and j==n-1)
	            continue;
	        else if(i==m-1){
	            if(a[i][j]<=0 and dp[i][j+1]>0)
	                dp[i][j]=dp[i][j+1]+abs(a[i][j]);
	            else if(a[i][j]<=0 and dp[i][j+1]==0)
	                dp[i][j]=abs(a[i][j])+1;
	            else
	                dp[i][j]=abs(min(0,a[i][j]-dp[i][j+1]));
	        }
	        else if(j==n-1){
	            if(a[i][j]<=0 and dp[i+1][j]>0)
	                dp[i][j]=dp[i+1][j]+abs(a[i][j]);
	            else if(a[i][j]<=0 and dp[i+1][j]==0)
	                dp[i][j]=abs(a[i][j])+1;
	            else
	                dp[i][j]=abs(min(0,a[i][j]-dp[i+1][j]));
	        }
	        else{
	            if(a[i][j]<=0 and (dp[i+1][j]==0 or dp[i][j+1]==0))
	                dp[i][j]=abs(a[i][j])+1;
	            else if(a[i][j]<=0)
	                dp[i][j]=abs(a[i][j]) + min(dp[i+1][j],dp[i][j+1]);
	            else
	                dp[i][j]=min(abs(min(0,a[i][j]-dp[i+1][j])),abs(min(0,a[i][j]-dp[i][j+1])));
	        }
	    }
	    if(dp[0][0]==0)
	        cout<<1<<endl;
	    else
	        cout<<dp[0][0]<<endl;
	}
	return 0;
}

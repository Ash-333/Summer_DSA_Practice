#include<iostream>
#include<vector>
using namespace std;

//BottomUP Approach
int minNoOfCoinsForChange(int m,vector<int> coins){
    vector<int> dp(m+1,0);
    dp[0]=0;

    for(int i=1;i<=m;i++){
        dp[i]=INT_MAX;
        for(int c:coins){
                if(i-c>=0 and dp[i-c]!=INT_MAX){
                    dp[i]=min(dp[i],dp[i-c]+1);
                }
        }
    }
    return dp[m]==INT_MAX?-1:dp[m];
    
}

int main(){
    vector<int> coins{1,5,7,10};
    int m=8;
    cout<<minNoOfCoinsForChange(m,coins);
}
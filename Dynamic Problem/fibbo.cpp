#include<iostream>
using namespace std;

//TopDown DP
int fibbo(int n,int dp[]){
    if(n==0 or n==1){
        return n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    return dp[n]=fibbo(n-1,dp)+fibbo(n-2,dp);
}

//BottomUp DP
int fibbo2(int n){
    int dp[n+1]={0};

    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i+2];
    }
    return dp[n];
}

int main(){
    int n=5;
    int dp[5]={0};

    cout<<fibbo2(n);
}
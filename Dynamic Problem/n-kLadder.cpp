#include<iostream>
#include<vector>
using namespace std;

//recursive solution O(n^k)
int ladder(int n,int k){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    int ans=0;

    for(int i=1;i<=k;i++){
        ans+=ladder(n-i,k);
    }

    return ans;
}

//TopDown approach O(n*k)
int ladderTP(int n,int k,int *dp){
    if(n==0){
        return 1;
    }

    if(n<0){
        return 0;
    }

    if(dp[n]!=0){
        return dp[n];
    }

    int ans=0;
    for(int i=1;i<=k;i++){
        ans+=ladderTP(n-i,k,dp);

    }
    return dp[n]=ans;
}

//BottomUp approach O(n*k)
int ladderBU(int n,int k){
    vector<int> dp(n+1,0);

    dp[0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[n];
}

int ladderOpt(int n,int k){
    vector<int> dp(n+1,0);

    dp[0]=dp[1]=1;

    for(int i=2;i<=k;i++){
        dp[i]=2*dp[i-1];
    }

    for(int i=k+1;i<=n;i++){
        if()
        dp[i]=2*dp[i-1]-dp[i-k-1];
    }
    return dp[n];
}

int main(){
    int n=84;
    int k=2;
    int dp[1000]={0};


    cout<<ladderOpt(n,k)<<endl;
}
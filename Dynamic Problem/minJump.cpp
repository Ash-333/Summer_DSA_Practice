#include<iostream>
#include<vector>
using namespace std;

//DP
int minJump(vector<int> arr,int n,vector<int> dp,int i){
    if(i==n-1){
        return 0;
    }

    if(i>=n){
        return INT_MAX;
    }

    if(dp[i]!=0){
        return dp[i];
    }

    int step=INT_MAX;
    int max_jump=arr[i];

    for(int jump=1;jump<=max_jump;jump++){
        int next_cell=i+jump;
        int subprob=minJump(arr,n,dp,next_cell);

        if(subprob!=INT_MAX){
            step=min(step,subprob+1);
        }
    }
    return dp[i]=step;
}

//
int min_jump(vector<int> arr,int n){
    if(n<=1){
        return 0;
    };

    if(arr[0]==0){
        return -1;
    }

    int maxReach=arr[0];
    int step=arr[0];
    int jump=1;

    int i;
    for(i=1;i<n;i++){
        if(i==n-1){
            return jump;
        }

        maxReach=max(maxReach,i+arr[i]);
        step--;
        if(step==0){
            jump++;
            if(i>=maxReach){
                return -1;
            }
            step=maxReach-i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr{2,3,1,1,2,4,2,0,1,1};
    int n=arr.size();
    vector<int> dp(n,0);

    cout<<min_jump(arr,n);
}
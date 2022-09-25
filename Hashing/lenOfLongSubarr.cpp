#include<bits/stdc++.h>
using namespace std;

int lenOfSubarr(vector<int> arr,int n,int k){
    int sum=0;
    int len=0;

    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==k){
            len=max(len,i+1);
        }

        if(mp.find(sum-k)!=mp.end()){
            len=max(len,i-mp[sum-k]);
        }
        if(mp.find(sum)==mp.end()){
            mp[sum]=i;
        }
    }

    return len;
}

int main(){
 vector<int> arr{-13 ,0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
 cout<<lenOfSubarr(arr,arr.size(),15);
}
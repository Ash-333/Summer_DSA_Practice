#include<bits/stdc++.h>
using namespace std;

void moveLeft(vector<int> &arr,int n){
    vector<int> temp;

    for(int i:arr){
        if(i>0){
            temp.push_back(i);
        }
    }

    for(int i:arr){
        if(i<0){
            temp.push_back(i);
        }
    }

    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}

int main(){
 vector<int> arr{1, -1, 3, 2, -7, -5, 11, 6};
 int n=arr.size();
 moveLeft(arr,n);
 for(int i:arr){
    cout<<i<<" ";
 }
}
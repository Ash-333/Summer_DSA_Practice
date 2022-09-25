#include<iostream>
#include<vector>
using namespace std;

vector<int> reverseArr(vector<int> arr){
    int n=arr.size();
    int mid=n/2;
    int s=0;
    int e=n-1;

    int m=0;

    while(m<mid){
        int temp=arr[e];
        arr[e]=arr[s];
        arr[s]=temp;
        s++;
        e--;
        m++;
    }

    return arr;
}

int main(){
    vector<int> arr{1,4,3,2};
    auto ans=reverseArr(arr);
    for(int i:ans){
        cout<<i<<" ";
    }
}
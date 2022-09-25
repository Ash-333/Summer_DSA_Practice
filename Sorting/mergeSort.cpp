#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int s,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;

    vector<int> temp;

    while(i<=m and j<=e){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=m){
        temp.push_back(arr[i++]);
    }

    while(j<=e){
        temp.push_back(arr[j++]);
    }

    int k=0;
    for(int i=s;i<=e;i++){
        arr[i]=temp[k++];
    }
    return;

}

void mergeSort(vector<int> &arr,int s,int e){
    if(s>=e){
        return;
    }

    int m=(s+e)/2;

    mergeSort(arr,s,m);
    mergeSort(arr,m+1,e);
    return merge(arr,s,e);
}


int main(){
    vector<int> arr{2,3,4,1,5};
    int e=arr.size()-1;
    mergeSort(arr,0,e);
    for(int i:arr){
        cout<<i<<" ";
    }
}
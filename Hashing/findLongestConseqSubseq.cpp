#include<bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(vector<int> arr){
    set<int> hashSet;
    for(int i:arr){
        (hashSet.insert(i));
    }

    int longest=0;

    for(int i:arr){
        if(!hashSet.count(i-1)){
            int currentNum=i;
            int currentLongest=1;

            while(hashSet.count(currentNum+1)){
                currentNum+=1;
                currentLongest+=1;
            }
            longest=max(longest,currentLongest);
        }
    }
    return longest;
}

int main(){

    vector<int> arr{2,6,1,9,4,5,3};
    cout<<findLongestConseqSubseq(arr);

 return 0;
}
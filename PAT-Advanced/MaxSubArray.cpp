#include<iostream>
#include<vector>

using namespace std;
int max3(int a,int b,int c) {
    return a>b?a>c?a:c:b>c?b:c;
}
int divideAndConquer(vector<int> arr,int left,int right) {
    int maxLeftSum,maxRightSum;
    int maxBorderLeftSum,maxBorderRightSum;
    int borderLeftSum,borderRightSum;
    
    if(right==left) {
        return arr[left]<=0?0:arr[left];
    }
    int center=(left+right)/2;
    maxLeftSum=divideAndConquer(arr,left,center);
    maxRightSum=divideAndConquer(arr,center+1,right);
    
    maxLeftSum=0;maxBorderLeftSum=0;
    for(int i=center;i>=left;--i) {
        borderLeftSum+=arr[i];
        if(borderLeftSum>maxBorderLeftSum)
            maxBorderLeftSum=borderLeftSum;
    }
    maxRightSum=0;maxBorderRightSum=0;
    for(int i=center+1;i<=right;++i) {
        borderRightSum+=arr[i];
        if(maxBorderRightSum<borderRightSum)
            maxBorderRightSum=borderRightSum;
    }
    return max3(maxLeftSum,maxRightSum,maxBorderRightSum+maxBorderLeftSum);
}
int main() {
    int num,tmp;
    cin>>num;
    vector<int> arr;
    while(num--) {
        cin>>tmp;
        arr.push_back(tmp);
    }
    int maxSum=divideAndConquer(arr,0,arr.size()-1);
    cout<<maxSum<<endl;
}
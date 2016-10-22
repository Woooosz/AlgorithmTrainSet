/*
1007. Maximum Subsequence Sum (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

Input Specification:

Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:

For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
PS: One test point failed
*/
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
struct boths {
    int rear;
    int front;
    int num;
};
bool sorts(const boths &v1,const boths &v2) {
    bool x;
    if(v1.num != v2.num) {
        x=v1.num > v2.num?1:0;
    } else {
        if(v1.front != v2.front) {
            x=v1.front < v2.front?1:0;
        } else {
            x=v1.rear < v2.rear?1:0;
        }
    }
    return x;
}
int main() {
    int num,front,rear,tmp,thisMax,Max,index;
    //freopen("/Users/shizhewu/Desktop/ls/1.txt","r",stdin);
    thisMax=0;index=0;Max=-32757;
    scanf("%d",&num);
    vector<boths> arr;
    boths tmps;
    rear=0;front=0;
    vector<int> nums;
    int flags=0;
    while(num--) {
        scanf("%d",&tmp);
        if(tmp>=0) flags=1;
        nums.push_back(tmp);
    }
    if (!flags) {
        printf("0 %d %d\n",nums[0],nums[nums.size()-1]);
        return 0;
    }
    for(int i=0;i<nums.size();++i) {
        thisMax+=nums[i];
        if(thisMax<0) {
            thisMax=0;
            rear=nums[i+1];
        } else {
            if(thisMax>Max) {
                Max=thisMax;
                tmps.front=nums[i];
                tmps.rear=rear;
                tmps.num=thisMax;
                arr.push_back(tmps);
            }
        }
    }
    sort(arr.begin(),arr.end(),sorts);
    printf("%d %d %d\n",arr[0].num,arr[0].rear,arr[0].front);
}
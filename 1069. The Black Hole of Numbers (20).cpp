/*
For any 4-digit integer except the ones with all the digits being the same, if we sort the digits in non-increasing order first, and then in non-decreasing order, a new number can be obtained by taking the second number from the first one. Repeat in this manner we will soon end up at the number 6174 -- the "black hole" of 4-digit numbers. This number is named Kaprekar Constant.

For example, start from 6767, we'll get:

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

Given any 4-digit number, you are supposed to illustrate the way it gets into the black hole.

Input Specification:

Each input file contains one test case which gives a positive integer N in the range (0, 10000).

Output Specification:

If all the 4 digits of N are the same, print in one line the equation "N - N = 0000". Else print each step of calculation in a line until 6174 comes out as the difference. All the numbers must be printed as 4-digit numbers.

Sample Input 1:
6767
Sample Output 1:
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
Sample Input 2:
2222
Sample Output 2:
2222 - 2222 = 0000
*/
#include<iostream>
#include<utility>
#include<queue>
using namespace std;
pair<int,int> asc(int x) {
    priority_queue<int,vector<int>,greater<int>> que;
    priority_queue<int> que_2;
    while(x>0) {
        que.push(x%10);
        que_2.push(x%10);
        x/=10;
    }
    int ans=0,ans1=0;
    while(que.size()!=4) que.push(0); //补位0
    while(que_2.size()!=4) que_2.push(0); //补位0
    while(!que.empty()) {
        ans=ans*10+que.top();
        que.pop();
    }
    while(!que_2.empty()) {
        ans1=ans1*10+que_2.top();
        que_2.pop();
    }
    pair<int,int> ss;
    ss.first=ans;
    ss.second=ans1;
    return ss;
}

int main() {
    int n;
    scanf("%d",&n);
    int ans=0;
    if(n%1111==0) {
        printf("%d - %d = 0000\n",n,n);
        return 0;
    }
    for(;;) {
        pair<int,int> x=asc(n);
        int asc_n=x.first;
        int dsc_n=x.second;
        ans=dsc_n-asc_n;
        printf("%04d - %04d = %04d\n",dsc_n,asc_n,ans);
        if(ans==6174) return 0;
        n=ans;
    }
}
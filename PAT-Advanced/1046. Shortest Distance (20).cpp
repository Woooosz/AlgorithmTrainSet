/*
1046. Shortest Distance (20)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

Input Specification:

Each input file contains one test case. For each case, the first line contains an integer N (in [3, 105]), followed by N integer distances D1 D2 ... DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (<=104), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 107.

Output Specification:

For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

Sample Input:
5 1 2 4 14 9
3
1 3
2 5
4 1
Sample Output:
3
10
7
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n,total=0;
    cin>>n;
    vector<int> x(n+1);
    for(int i=0;i<n;++i) {
        cin>>x[i+1];
        x[i+1]+=x[i];
    }
    total=x[n];
    cin>>n;
    for(int i=0;i<n;++i) {
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        int thissum=0;
        //for(int j=a;j<b;++j) thissum+=x[j];
        thissum=x[b-1]-x[a-1];
        int ans=thissum>total-thissum?total-thissum:thissum;
        cout<<ans<<endl;
    }
}
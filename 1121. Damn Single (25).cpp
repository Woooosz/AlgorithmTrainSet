/*
时间限制
300 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
"Damn Single (单身狗)" is the Chinese nickname for someone who is being single. You are supposed to find those who are alone in a big party, so they can be taken care of.

Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=50000), the total number of couples. Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M (<=10000) followed by M ID's of the party guests. The numbers are separated by spaces. It is guaranteed that nobody is having bigamous marriage (重婚) or dangling with more than one companion.

Output Specification:

First print in a line the total number of lonely guests. Then in the next line, print their ID's in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.

Sample Input:
3
11111 22222
33333 44444
55555 66666
7
55555 44444 10000 88888 22222 11111 23333
Sample Output:
5
10000 23333 44444 55555 88888
*/
#include <iostream>
#include <queue>
#include <map>
using namespace std;
priority_queue<int, vector<int>, greater<int>> ans;
typedef map<int,int>::iterator itor;
int main() {
    int n,m,p,q,r;
    scanf("%d",&n);
    map<int,int> d,o;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d",&p,&q);
        d[p] = q; d[q] = p;
    }
    scanf("%d",&m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &r);
        o[r] = 1;
    }
    for(itor pi = o.begin();pi != o.end(); ++pi) {
        if(d.find(pi->first) == d.end()) {
            ans.push(pi->first);
        } else if(o.find(d.find(pi->first)->second) == o.end())
            ans.push(pi->first);
    }
    printf("%d\n",ans.size());
    if(ans.size() == 0) return 0;
    printf("%05d",ans.top()); ans.pop();
    while(! ans.empty()) {
        printf(" %05d",ans.top());
        ans.pop();
    }
    printf("\n");
    return 0;
}
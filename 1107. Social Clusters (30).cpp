/*
1107. Social Clusters (30)

时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. A "social cluster" is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of people in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:

Ki: hi[1] hi[2] ... hi[Ki]

where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:

For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
Sample Output:
3
4 3 1
*/
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
vector<int> a;
int root(int x) {
    while(a[x]>0) x=a[x];
    return x;
}
void unions(int c,int d) {
    int pa=root(c);
    int pb=root(d);
    if(pa!=pb) {
        a[pa]+=a[pb];
        a[pb]=pa;
    }
}
int main() {
    int n,m,k;
    scanf("%d",&n);
    a.resize(n+1);
    fill(a.begin(),a.end(),-1);
    map<int,int> d;
    for(int i=1;i<=n;++i) {
        scanf("%d:",&m);
        for(int j=0;j<m;++j) {
            scanf("%d",&k);
            if(d.find(k)==d.end()) {
                d[k]=i;
            } else {
                unions(d[k],i);
            }
        }
    }
    priority_queue<int> q;
    for(int i=1;i<=n;++i)
        if(a[i]<0) q.push(a[i]*(-1));
    printf("%d\n",q.size());
    printf("%d",q.top()); q.pop();
    while(!q.empty()) {
        printf(" %d",q.top());
        q.pop();
    }
}

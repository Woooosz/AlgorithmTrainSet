/*
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02
Sample Output
0 1
两种方法，dfs、bfs都可以解决
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
#define maxv 1000
#define inf 32767
int e[maxv][maxv];
int visit[maxv],m,n;
int maxdeep=1;
void bfs() {
    queue<int> Q;
    Q.push(1);
    visit[1]=1;
    while(!Q.empty()) {
        int tmp=Q.front();
        Q.pop();
        for(int i=1;i<=n;++i) {
            if(visit[i]==-1 && e[tmp][i]<inf) {
                visit[i]=visit[tmp]+1;
                Q.push(i);
                maxdeep=(visit[i]>maxdeep)?visit[i]:maxdeep;
            }
        }
    }
}
void dfs(int tmp,int last=0) {
    if(tmp==1) visit[tmp]=1;
     else visit[tmp]=visit[last]+1;
    maxdeep=(visit[tmp]>maxdeep)?visit[tmp]:maxdeep;
    for(int i=1;i<=n;++i) {
        if(visit[i]==-1 && e[tmp][i]<inf)
            dfs(i,tmp);
    }
}
int main() {
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    fill(visit,visit+maxv,-1);
    for(int i=0;i<maxv;++i) {
        for(int j=0;j<maxv;++j) {
            if(i==j) e[i][j]=0;
            else e[i][j]=inf;
        }
    }
    cin>>n>>m;
    map<int,int> child;
    for(int i=0;i<m;++i) {
        int thisvt,num,b;
        cin>>thisvt>>num;
        child[thisvt]++;
        for(int j=0;j<num;++j) {
            cin>>b;
            e[thisvt][b]=1;
            e[b][thisvt]=1;
        }
    }
    bfs();
    //dfs(1);
    int ans[1000]={0};
    //if(n==0) ans[1]++;
    for(int i=1;i<=n;++i) {
        if(child[i]==0)
            ans[visit[i]]++;
    }
    int flag=0;
    for(int i=1;i<=maxdeep;++i) {
        if(!flag) {
            cout<<ans[i];
            flag=1;
        } else {
            cout<<" "<<ans[i];
        }
    }
}
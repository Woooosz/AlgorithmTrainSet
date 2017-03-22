/*
A graph which is connected and acyclic can be considered a tree. The height of the tree depends on the selected root. Now you are supposed to find the root that results in a highest tree. Such a root is called the deepest root.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:

For each test case, print each of the deepest roots in a line. If such a root is not unique, print them in increasing order of their numbers. In case that the given graph is not a tree, print "Error: K components" where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5
Sample Output 1:
3
4
5
Sample Input 2:
5
1 3
1 4
2 5
3 4
Sample Output 2:
Error: 2 components

*/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#define MAX 10001
using namespace std;
vector<int> map[MAX];
int visit[MAX];
int deep[MAX];
int vt;
int _max;
inline int max(int a,int b) {
    return a>b?a:b;
}
void dfs1(int index) {
    visit[index]=1;
    for(int i=0;i<map[index].size();++i) {
        if(!visit[map[index][i]])
            dfs1(map[index][i]);
    }
}
int dfs2(int index) {
    int deep=0;
    visit[index]=1;
    for(int i=0;i<map[index].size();++i) {
        if(!visit[map[index][i]]) {
            int tmp=dfs2(map[index][i]);
            deep=max(deep,tmp);
        }
    }
    return deep+1;
}
int main() {
    cin>>vt;
    int va,vb;
    for(int i=0;i<vt-1;++i) {
        cin>>va>>vb;
        map[va].push_back(vb);
        map[vb].push_back(va);
    }
    memset(visit,0,sizeof(visit));
    int count=0;
    for(int i=1;i<=vt;++i) {
        if(!visit[i]) {
            count++;
            dfs1(i);
        }
    }
    if(count!=1) {
        cout<<"Error: "<<count<<" components"<<endl;
        return 0;
    }
    
    memset(deep,0,sizeof(deep));
    for(int i=1;i<=vt;++i) {
        memset(visit,0,sizeof(visit));
        deep[i]=dfs2(i);
    }
    for(int i=1;i<=vt;++i) _max=max(_max,deep[i]);
    for(int i=1;i<=vt;++i) {
        if(deep[i]==_max) {
            cout<<i<<endl;
        }
    }
}
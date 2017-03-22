/*
A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 4 positive integers N, M, S, and D, where N (<=500) is the number of cities (and hence the cities are numbered from 0 to N-1); M is the number of highways; S and D are the starting and the destination cities, respectively. Then M lines follow, each provides the information of a highway, in the format:

City1 City2 Distance Cost

where the numbers are all integers no more than 500, and are separated by a space.

Output Specification:

For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distance and the total cost of the path. The numbers must be separated by a space and there must be no extra space at the end of output.

Sample Input
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
Sample Output
0 2 3 3 40
dijkstra解法，之所以能够直接用dijkstra解决是因为费用是能够满足最优子结构的性质
解法二，再用一步dfs求解最小费用，该揭发适合求解不满足最有子结构性质的问题
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define INF 32767
#define MAX 510
int e[MAX][MAX],cost[MAX][MAX],dis[MAX],vt,ve,s,d;
bool visit[MAX];
vector<int> pre[MAX];
vector<int> temppath;
vector<int> path;
int mincost=INF;
int find_min_dis() {
    int min=0x7fff,index=-1;
    for(int i=0;i<vt;++i) {
        if(min>dis[i] && visit[i]==false) {
            min=dis[i];
            index=i;
        }
    }
    return index;
}
void dijkstra() {
    for(int i=0;i<vt;++i) {
        dis[i]=e[s][i];
    }
    pre[s].push_back(s);
    for(;;) {
        int tmp=find_min_dis();
        if(tmp==-1) break;
        visit[tmp]=true;
        for(int i=0;i<vt;++i) {
            if(visit[i]==false && e[tmp][i]<INF) {
                if(dis[i]>dis[tmp]+e[tmp][i]) {
                    dis[i]=dis[tmp]+e[tmp][i];
                    pre[i].clear();
                    pre[i].push_back(tmp);
                } else if(dis[i]==dis[tmp]+e[tmp][i]) {
                    pre[i].push_back(tmp);
                }
            }
        }
    }
}
void dfs(int v) {
    if(v == s) {
        temppath.push_back(v);
        int tempcost = 0;
        for(int i = temppath.size() - 1; i > 0; i--) {
            int id = temppath[i], nextid = temppath[i-1];
            tempcost += cost[id][nextid];
        }
        if(tempcost < mincost) {
            mincost = tempcost;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    temppath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}
int main() {
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    fill(e[0],e[0]+MAX*MAX,INF);
    fill(cost[0],cost[0]+MAX*MAX,INF);
    fill(dis,dis+MAX,INF);
    cin>>vt>>ve>>s>>d;
    for(int i=0;i<MAX;++i) {
        for(int j=0;j<MAX;++j)
            if(i==j) e[i][j]=0,cost[i][j]=0;
    }
    for(int i=0;i<ve;++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%d",&e[a][b]);
        e[b][a]=e[a][b];
        scanf("%d",&cost[a][b]);
        cost[b][a]=cost[a][b];
    }
    dijkstra();
    dfs(d);
    for(int i = path.size() - 1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dis[d], mincost);
}
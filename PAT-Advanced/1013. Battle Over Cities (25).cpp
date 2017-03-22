/*
1013. Battle Over Cities (25)

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
It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

Input

Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

Output

For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

Sample Input
3 2 3
1 2
1 3
1 2 3
Sample Output
1
0
0
dfs 检索处x顶点外有多少个连通分量
网上还有一种是用并查集做的
*/
#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#define MAX 1000
using namespace std;
int arr[MAX][MAX];
int visit[MAX];
int nv;
void dfs(int index,int v) {
    visit[index]=1;
    for(int i=1;i<=nv;++i) {
        if(visit[i]==0 && arr[index][i]<MAX && i!=v)
            dfs(i,v);
    }
}
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#endif
    int M,K;
    int v1,v2;
    cin>>nv>>M>>K;
    for(int i=0;i<MAX;++i) {
        for(int j=0;j<MAX;++j) {
            if(i==j)
                arr[i][j]=0;
            else
                arr[i][j]=32767;
        }
        visit[i]=0;
    }
    for(int i=0;i<M;++i) {
        cin>>v1>>v2;
        arr[v1][v2]=arr[v2][v1]=1;
    }
    int v;
    int count=0;
    for(int i=0;i<K;++i) {
        cin>>v;
        memset(visit,0,sizeof(visit));
        if(nv==1||nv==2)
            cout<<0<<endl;
        else {
            for(int i=1;i<=nv;++i) {
                if(visit[i]==0 && i!=v) {
                    ++count;
                    dfs(i,v);
                }
            }
            cout<<count-1<<endl;
            count=0;
        }
    }
}
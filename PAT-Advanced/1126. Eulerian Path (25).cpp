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
In graph theory, an Eulerian path is a path in a graph which visits every edge exactly once. Similarly, an Eulerian circuit is an Eulerian path which starts and ends on the same vertex. They were first discussed by Leonhard Euler while solving the famous Seven Bridges of Konigsberg problem in 1736. It has been proven that connected graphs with all vertices of even degree have an Eulerian circuit, and such graphs are called Eulerian. If there are exactly two vertices of odd degree, all Eulerian paths start at one of them and end at the other. A graph that has an Eulerian path but not an Eulerian circuit is called semi-Eulerian. (Cited from https://en.wikipedia.org/wiki/Eulerian_path)

Given an undirected graph, you are supposed to tell if it is Eulerian, semi-Eulerian, or non-Eulerian.

Input Specification:

Each input file contains one test case. Each case starts with a line containing 2 numbers N (<= 500), and M, which are the total number of vertices, and the number of edges, respectively. Then M lines follow, each describes an edge by giving the two ends of the edge (the vertices are numbered from 1 to N).

Output Specification:

For each test case, first print in a line the degrees of the vertices in ascending order of their indices. Then in the next line print your conclusion about the graph -- either "Eulerian", "Semi-Eulerian", or "Non-Eulerian". Note that all the numbers in the first line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.

Sample Input 1:
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6
Sample Output 1:
2 4 4 4 4 4 2
Eulerian
Sample Input 2:
6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6
Sample Output 2:
2 4 4 4 3 3
Semi-Eulerian
Sample Input 3:
5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3
Sample Output 3:
3 3 4 3 3
Non-Eulerian
之前使用map记录每个顶点的度，改成数组就好了…这是为什么…
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
const int maxv=500+5;
const int INF=~(1<<31);
int arr[maxv][maxv];
using namespace std;
typedef map<int,int>::iterator itor;
int n,m;
int visit[maxv];
bool bfs(int v) {
    fill(visit,visit+n+1,0);
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        int k=q.front();
        q.pop();
        visit[k]=1;
        for(int i=1;i<=n;++i) {
            if(visit[i] == 0 && arr[k][i] < INF) {
                q.push(i);
            }
        }
    }
    int i=0;
    for(i=1;i<=n;++i)
        if(visit[i] == 0) break;
    return i == n+1 ? 1 : 0;
}

int main() {
    for(int i=0;i<maxv;++i) {
        for(int j=0;j<maxv;++j) {
            if(i==j) arr[i][j]=0;
            else arr[i][j]=INF;
        }
    }
    int ff=0;
    scanf("%d %d",&n,&m);
    vector<int> l(n+1);
    int ta,tb;
    for(int i=0;i<m;++i) {
        scanf("%d %d",&ta,&tb);
        arr[tb][ta]=arr[ta][tb]=1;
        l[ta]++;
        l[tb]++;
    }
    int f=0;
    for(int i=1;i<=n;++i) {
        if(l[i] % 2 == 1) ff++;
        if(f==0) {
            f=1;
            printf("%d",l[i]);
        } else {
            printf(" %d",l[i]);
        }
    }
    printf("\n");
    bool res=bfs(n);
    if(!res) {
        printf("Non-Eulerian\n");
        return 0;
    }
    if(ff == 0) {
        printf("Eulerian\n");
        return 0;
    } else if(ff==2){
        printf("Semi-Eulerian\n");
    } else {
        printf("Non-Eulerian\n");
    }
    
}
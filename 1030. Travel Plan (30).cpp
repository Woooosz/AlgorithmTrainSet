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
*/
#include<iostream>
#define MAX 1000
#define INF 32767
using namespace std;
struct node {
    int dis;
    int cos;
};
node arr[MAX][MAX];
int dist[MAX];
int visit[MAX];
int cost[MAX];
int path[MAX];
int vt,S;
int find_min_dist() {
    int min=MAX;
    int index=-1;
    for(int i=0;i<vt;++i) {
        if(dist[i]<min && visit[i]!=1) {
            min=dist[i];
            index=i;
        }
    }
    return index;
}
void print_x(int x) {
    if(path[x]!=-1) {
        print_x(path[x]);
    }
    if(path[x]==-1)
        printf("%d",x);
    else
        printf(" %d",x);
    
}
void dijkstra() {
    for(int i=0;i<vt;++i) {
        dist[i]=arr[S][i].dis;
        visit[i]=-1;
        path[i]=S;
        cost[i]=arr[S][i].cos;
    }
    path[S]=-1;
    while(true) {
        int tmp=find_min_dist();
        if(tmp==-1) break;
        visit[tmp]=1;
        for(int i=0;i<vt;++i) {
            if(visit[i]!=1) {
                if(dist[tmp]+arr[tmp][i].dis<dist[i]) {
                    dist[i]=dist[tmp]+arr[tmp][i].dis;
                    path[i]=tmp;
                    cost[i]=cost[tmp]+arr[tmp][i].cos;
                }
                else if(dist[tmp]+arr[tmp][i].dis==dist[i] && cost[tmp]+arr[tmp][i].cos<cost[i]) {
                    path[i]=tmp;
                    cost[i]=cost[tmp]+arr[tmp][i].cos;
                }
            }
        }
        
    }
}
int main() {
    int M,D;
    cin>>vt>>M>>S>>D;
    for(int i=0;i<MAX;++i) {
        for(int j=0;j<MAX;++j) {
            if(i==j) {
                arr[i][j].dis=0;
                arr[i][j].cos=0;
            }
            else {
                arr[i][j].dis=INF;
                arr[i][j].cos=INF;
            }
        }
    }
    for(int i=0;i<M;++i) {
        int va,vb,dis,mon;
        scanf("%d %d %d %d",&va,&vb,&dis,&mon);
        arr[va][vb].dis=dis;
        arr[va][vb].cos=mon;
        arr[vb][va].dis=dis;
        arr[vb][va].cos=mon;
    }
    dijkstra();
    print_x(D);
    printf(" %d %d",dist[D],cost[D]);
}
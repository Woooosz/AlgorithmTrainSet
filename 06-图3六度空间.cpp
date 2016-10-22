/*
“六度空间”理论虽然得到广泛的认同，并且正在得到越来越多的应用。但是数十年来，试图验证这个理论始终是许多社会学家努力追求的目标。然而由于历史的原因，这样的研究具有太大的局限性和困难。随着当代人的联络主要依赖于电话、短信、微信以及因特网上即时通信等工具，能够体现社交网络关系的一手数据已经逐渐使得“六度空间”理论的验证成为可能。

假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

输入格式:

输入第1行给出两个正整数，分别表示社交网络图的结点数NN（1<N\le 10^41<N≤10​4​​，表示人数）、边数MM（\le 33\times N≤33×N，表示社交关系数）。随后的MM行对应MM条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到NN编号）。

输出格式:

对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。

输入样例:

10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
输出样例:

1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%

PS:在陈越数据结构课程上讲的方法是引入两个变量标记层数，若当前出队的元素与last相等，则说明即将进入下一层。将last更新为tail,更新tail,重复直到level = 6或者队列空，不过这道题
我觉得用无向图单源最短路径算法做起来理解起来会更加方便。
*/
#include<iostream>
#include<queue>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAXNV 1000

using namespace std;


double BFS(int graph[][MAXNV],int *dist,int nv,int vertex) {
    queue<int> Q;
    dist[vertex]=0;
    Q.push(vertex);
    int tmp;
    while((!Q.empty())) {
        tmp=Q.front();
        Q.pop();
        for(int i=0;i<nv;++i) {
            if(graph[tmp][i]==1 && dist[i]==-1 && dist[tmp]<=6) {
                Q.push(i);
                dist[i]=dist[tmp]+1;
            }
        }
    }
    double sum=0;
    for(int i=0;i<nv;++i) {
        if(dist[i]<=6 && dist[i]>=0) ++sum;
    }
    double result= sum/nv;
    return result;
}
int main() {
    //freopen("D:\\1.txt","r",stdin);
    int graph[MAXNV][MAXNV];
    for(int i=0;i<MAXNV;++i) {
        for(int j=0;j<MAXNV;++j) {
            graph[i][j]= i==j?0:32767;
        }
    }
    int nv,ne;
    cin>>nv>>ne;
    int V,W,value;
    for(int i=0;i<ne;++i) {
        cin>>V>>W;
        graph[V-1][W-1]=1;
        graph[W-1][V-1]=1;
    }
    int *dist=(int*)malloc(sizeof(int)*nv);
    memset(dist,-1,sizeof(int)*nv);
    double result;
    for(int i=0;i<nv;++i) {
        result=BFS(graph,dist,nv,i);
        memset(dist,-1,sizeof(int)*nv);
        printf("%d: %.2f%%\n",i+1,result*100);
    }
}

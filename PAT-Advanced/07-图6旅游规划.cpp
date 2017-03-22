/*
有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。现在需要你写一个程序，帮助前来咨询的游客找一条出发地和目的地之间的最短路径。如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

输入格式:

输入说明：输入数据的第1行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0~(N−1)；M是高速公路的条数；S是出发地的城市编号；D是目的地的城市编号。随后的M行中，每行给出一条高速公路的信息，分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。输入保证解的存在。

输出格式:

在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

输入样例:

4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
输出样例:

3 40
*/
#include<iostream>
#include<stdlib.h>

#define MAXNV 501
#define INFINITY 32767
using namespace std;


int findMinDist(int *dist,int *collected,int nv);

struct {
    int length;
    int cost;
}arr[MAXNV][MAXNV];

int main() {
    int nv,ne,S,D;
    cin>>nv>>ne>>S>>D;
    for(int i=0;i<MAXNV;++i) {
        for(int j=0;j<MAXNV;++j) {
            if(i==j) {
                arr[i][j].cost=0;
                arr[i][j].length=0;
            } else {
                arr[i][j].cost=INFINITY;
                arr[i][j].length=INFINITY;
            }
        }
    }
    int v,w,l,c;
    for(int i=0;i<ne;++i) {
        cin>>v>>w>>l>>c;
        arr[v][w].length=l;
        arr[w][v].length=l;
        arr[v][w].cost=c;
        arr[w][v].cost=c;
    }
    int *collected=(int*)malloc(sizeof(int)*nv);
    int *dist=(int*)malloc(sizeof(int)*nv);
    int *path=(int*)malloc(sizeof(int)*nv);
    int *cost=(int*)malloc(sizeof(int)*nv);
    for(int i=0;i<nv;++i) {
        dist[i]=arr[S][i].length;
        path[i]=-1;
        cost[i]=arr[S][i].cost;
        collected[i]=-1;
    }
    dist[S]=0;
    cost[S]=0;
    collected[S]=1;
    int tmp;
    while (1) {
        tmp=findMinDist(dist, collected, nv);
        if(tmp==-1) break;
        collected[tmp]=1;
        for(int i=0;i<nv;++i) {
            if(collected[i]==-1) {
                if(dist[i]>dist[tmp]+arr[tmp][i].length) {
                    dist[i]=dist[tmp]+arr[tmp][i].length;
                    cost[i]=cost[tmp]+arr[tmp][i].cost;
                    path[i]=tmp;
                } else if(dist[i]==dist[tmp]+arr[tmp][i].length) {
                    if(cost[i]>cost[tmp]+arr[tmp][i].cost) {
                        cost[i]=cost[tmp]+arr[tmp][i].cost;
                        path[i]=tmp;
                    }
                }
            }
        }
    }
    cout<<dist[D]<<" "<<cost[D]<<endl;
    
}
int findMinDist(int *dist,int *collected,int nv) {
    int Min=INFINITY;
    int MinIndex=0;
    for(int i=0;i<nv;++i) {
        if(collected[i]==-1 && dist[i]<Min) {
            Min=dist[i];
            MinIndex=i;
        }
    }
    if(Min==INFINITY) {
        return -1;
    } else {
        return MinIndex;
    }
}
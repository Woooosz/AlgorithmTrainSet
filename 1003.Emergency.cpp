
/*
1003. Emergency (25)

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
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
PS:记得要理清题意，输出的是路径个数……
*/
#include<stdio.h>
#include<stdlib.h>

#define MAXNV 500
#define INFINTY 32767

int findMinDist(int *dist,int* collected,int nv) {
	int min=INFINTY;
	int minIndex=-1;
	for(int i=0;i<nv;++i) {
		if(dist[i]==-1 && dist[i]<min) {
			min=dist[i];
			minIndex=i;
		}
	}
	return min==INFINTY?-1:minIndex;
}
int main() {
	int nv,ne,l,m;
	scanf("%d %d %d %d",&nv,&ne,&l,&m);
	graph[MAXNV][MAXNV];
	for(int i=0;i<MAXNV;++i) {
		for(int j=0;j<MAXNV;++j) {
			if(i==j) {
				graph[i][j]=0;
			} else {
				graph[i][j]=INFINTY;
			}
		}
	}
	int *person=(int*)malloc(sizeof(int)*nv);
	int *collected=(int*)malloc(sizeof(int)*nv);
	int *per=(int*)malloc(sizeof(int)*nv);
	for(int i=0;i<ne;++i) 
		scanf("%d",&person[i]);
    int tmp1,tmp2,tmp3;
	for(int i=0;i<ne;++i) {
		scanf("%d %d %d",&tmp1,tmp2,tmp3);
		arr[tmp1][tmp2]=tmp3;
		arr[tmp2][tmp1]=tmp3;
	}
	for(int i=0;i<nv;++i) {
		collected[i]=-1;
		dist[i]=graph[S][i];
		per[i]=0;
	}
	collected[S]=1; per[S]=person[S];
	dist[i]=0;
	int tmp;
	while(true) {
		tmp=findMinDist(dist,collected,nv);
		if(tmp==-1) break;
		collected[tmp]=1;
		for(int i=0;i<nv;++i) {
			if(collected[i]==-1) {
				if(dist[tmp]+graph[tmp][i]<dist[i]) {
					dist[tmp]+graph[tmp][i]=dist[i];
					per[i]=per[tmp]+person[i];
				} else if(dist[tmp]+graph[tmp][i]<dist[i]) {
					if(per[i]<per[tmp]+person[i]) {
						per[i]=per[tmp]+person[i]
					}
				}
			}
		}
	}
	printf("%d %d",dist[D],per[D]);
}
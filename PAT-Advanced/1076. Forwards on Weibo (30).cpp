/*
1076. Forwards on Weibo (30)

时间限制
3000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N (<=1000), the number of users; and L (<=6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]

where M[i] (<=100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that are followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:

For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can triger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxv=1005;
const int inf=32767;
int arr[maxv][maxv],dist[maxv],visit[maxv],vt,m,counts;
void bfs(int v) {
    queue<int> q;
    counts=0;
    fill(visit,visit+vt+1,-1);
    fill(dist,dist+vt+1,0);
    visit[v]=1;
    q.push(v);
    while(!q.empty()) {
        int tmp=q.front();
        q.pop();
        if(dist[tmp]==m) return;
        for(int i=1;i<=vt;++i) {
            if(visit[i]==-1 && arr[tmp][i]<inf) {
                dist[i]=dist[tmp]+1;
                ++counts;
                
                    q.push(i);
                    visit[i]=1;
            }
        }
    }
}
int main() {
    //freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    scanf("%d %d",&vt,&m);
    for(int i=0;i<=vt;++i) {
        for(int j=0;j<=vt;++j) {
            if(i==j) arr[i][j]=0;
            else arr[i][j]=inf;
        }
    }
    for(int i=1;i<=vt;++i) {
        int num;
        scanf("%d",&num);
        for(int j=0;j<num;++j) {
            int x;
            scanf("%d",&x);
            arr[x][i]=1;
        }
    }
    int query_n;
    scanf("%d",&query_n);
    for(int i=0;i<query_n;++i) {
        int tmp;
        scanf("%d",&tmp);
        bfs(tmp);
        printf("%d\n",counts);
    }
}

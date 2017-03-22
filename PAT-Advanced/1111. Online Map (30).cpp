#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
const int maxv=505;
const int INF=32767;
struct node {
    int length;
    int time;
} a[maxv][maxv];
int vt,ve,d,s,mintime=INF;
vector<int> pre[maxv],tmppath,path,dist,visit,cnt,newpath;
int findMinDist() {
    int index=-1,min=INF;
    for(int i=0;i<vt;++i) {
        if(visit[i]==0 && dist[i]<min) {
            index=i;
            min=dist[i];
        }
    }
    return index;
}
void dfs(int v) {
    if(v==s) {
        tmppath.push_back(v);
        int thistime=0;
        for(int i=tmppath.size()-1;i>0;--i) {
            thistime+=a[tmppath[i]][tmppath[i-1]].time;
        }
        if(thistime<mintime) {
            path=tmppath;
            mintime=thistime;
        }
        tmppath.pop_back();
        return;
    }
    tmppath.push_back(v);
    for(int i=0;i<pre[v].size();++i) {
        dfs(pre[v][i]);
    }
    tmppath.pop_back();
}
void dfs_time(int v) {
    if(v==s) {
        tmppath.push_back(v);
        int thiscnt=0;
        for(int i=tmppath.size()-1;i>=0;--i) {
            thiscnt+=cnt[i];
        }
        if(thiscnt<mintime) {
            newpath=tmppath;
            mintime=thiscnt;
        }
        tmppath.pop_back();
        return;
    }
    tmppath.push_back(v);
    for(int i=0;i<pre[v].size();++i) {
        dfs_time(pre[v][i]);
    }
    tmppath.pop_back();
}
void dijkstra_time(int v) {
    dist.resize(vt);
    visit.resize(vt);
    fill(dist.begin(),dist.end(),0);
    fill(visit.begin(),visit.end(),0);
    cnt.resize(vt);
    tmppath.clear();
    for(int i=0;i<maxv;++i)
        pre[i].clear();
    for(int i=0;i<vt;++i) {
        dist[i]=a[v][i].time;
        if(a[v][i].length<INF) {
            pre[i].push_back(v);
            cnt[v]++;
        }
    }
    visit[v]=1;
    for(;;) {
        int p=findMinDist();
        if(p==-1) break;
        visit[p]=1;
        for(int i=0;i<vt;++i) {
            if(a[p][i].time<INF) {
                cnt[p]++;
                if(visit[i]==0) {
                    if(dist[p]+a[p][i].time<dist[i]) {
                        dist[i]=dist[p]+a[p][i].time;
                        pre[i].clear();
                        pre[i].push_back(p);
                    } else if(dist[p]+a[p][i].time==dist[i]) {
                        pre[i].push_back(p);
                    }
                }
            }
        }
    }
}

void dijkstra(int v) {
    dist.resize(vt);
    visit.resize(vt);
    fill(dist.begin(),dist.end(),0);
    fill(visit.begin(),visit.end(),0);
    //pre[v].push_back(v);
    for(int i=0;i<vt;++i) {
        dist[i]=a[v][i].length;
        if(a[v][i].length<INF) pre[i].push_back(v);
    }
    visit[v]=1;

    for(;;) {
        int p=findMinDist();
        if(p==-1) break;
        visit[p]=1;
        for(int i=0;i<vt;++i) {
            if(visit[i]==0 && a[p][i].length<INF) {
                if(dist[p]+a[p][i].length<dist[i]) {
                    dist[i]=dist[p]+a[p][i].length;
                    pre[i].clear();
                    pre[i].push_back(p);
                } else if(dist[p]+a[p][i].length==dist[i]) {
                    pre[i].push_back(p);
                }
            }
        }
    }
}
int main() {
    //freopen("/Users/shizhewu/a.in","r",stdin);
    scanf("%d %d",&vt,&ve);
    for(int i=0;i<maxv;++i) {
        for(int j=0;j<maxv;++j){
            a[i][j].length = i==j?0:INF;
            a[i][j].time =i==j?0:INF;
        }
    }
    int way,length,time,c,d;
    for(int i=0;i<ve;++i) {
        scanf("%d %d %d %d %d",&c,&d,&way,&length,&time);
        if(way==1) {
            a[c][d].length=length;
            a[c][d].time=time;
        } else {
            a[d][c].length=length;
            a[d][c].time=time;
            a[c][d].length=length;
            a[c][d].time=time;
        }
    }
    scanf("%d %d",&s,&d);
    dijkstra(s);
    dfs(d);
    int p=dist[d];
    mintime=INF;
    dijkstra_time(s);
    dfs_time(d);
    if(path==newpath) {
        printf("Distance = %d; ",p);
        printf("Time = %d: %d",dist[d],newpath[newpath.size()-1]);
        for(int i=newpath.size()-2;i>=0;--i) printf(" -> %d",newpath[i]);
        printf("\n");
    } else {
        printf("Distance = %d: %d",p,path[path.size()-1]);
        for(int i=path.size()-2;i>=0;--i) printf(" -> %d",path[i]);
        printf("\n");
        printf("Time = %d: %d",dist[d],newpath[newpath.size()-1]);
        for(int i=newpath.size()-2;i>=0;--i) printf(" -> %d",newpath[i]);
        printf("\n");
    }
}
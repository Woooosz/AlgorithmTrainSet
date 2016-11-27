#include<iostream>
#include<stdlib.h>
#include<string.h>

#define inf 0x7fffffff
#define maxv 1024
using namespace std;


int findmindist(int *dist,int nv) {
    int min=inf;
    int minv=-1;
    for(int i=0;i<nv;++i) {
        if(min>dist[i] && dist[i]!=-1) {
            min=dist[i];
            minv=i;
        }
    }
    return minv;
}

void prim(int g[maxv][maxv],int dist[maxv],int nv) {
    int cur;
    int ans=0;
    for(;;) {
        cur=findmindist(dist,nv);
        if(cur==-1) break;
        ans+=dist[cur];
        dist[cur]=-1;
        for(int j=0;j<nv;++j) {
            if(g[cur][j]<dist[j])
                dist[j]=g[cur][j];
        }
    }
    int i;
    for(i=0;i<nv;++i) {
        if(dist[i]!=-1) break;
    }
    if(i<nv) ans=-1;
    printf("%d",ans);
}
int main() {
    int nv,ne,m[maxv][maxv],dist[maxv];
    cin>>nv>>ne;
    for (int i = 0; i < maxv; ++i)
    {
        for (int j = 0; j < maxv; ++j)
        {
            if(i==j) m[i][j]=0;
            else m[i][j]=inf;
        }
    }
    int vin,vout,w;
    for (int i = 0; i < ne; ++i)
    {
        cin>>vin>>vout>>w;
        --vout;
        --vin;
        m[vout][vin]=m[vin][vout]=min(m[vout][vin],w);
    }
    memset(dist,-1,sizeof(dist));
    for(int i=0;i<nv;++i) {
        dist[i]=m[0][i];
    }
    prim(m,dist,nv);
}
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
uisng namespace std;
const int max=1000;
const int inf=0x7fffffff;
vector<int> tmpath,path;
int e[max][max],dist[max],visit[max],vt,ve,s,d,happy[max],maxhappy=-1,maxavg,count[max];
map<string,int> city2num;
map<int,string> num2city;
int find_min_dist() {
    int min=max;
    int index=-1;
    for(int i=0;i<vt;++i) {
        if(dist[i]<min && visit[i]==-1) {
            min=dist[i];
            index=i;
        }
    }
    return index;
}
void dijkstra() {
    for(int i=0;i<vt;++i) {
        dist[i]=e[s][i];
        if(e[s][i]<inf)
            path[i]=s;
    }
    path[s]=-1;
    count[s]=1;
    pre[s].push_back(s);
    for(;;) {
        int tmp=find_min_dist();
        if(tmp==-1) break;
        visit[tmp]=1;
        for(int i=0;i<vt;++i) {
            if(visit[i]==-1 && e[tmp][i]<inf) {
                if(dist[i]>dist[tmp]+e[tmp][i]) {
                    dist[i]=dist[tmp]+e[tmp][i];
                    pre[i].clear();
                    pre[i].push_back(pre);
                    count[i]=count[tmp];
                } else if(dist[i]==dist[tmp]+e[tmp][i]) {
                    pre[i].push_back(pre);
                    cout[i]+=count[tmp];
                }
            }
        }

    }
}
void dfs(int v) {
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    if(v==s) {
        tmpath.push_back(v);
        int thishappy=0,avghappy=0;
        for(int i=0;i<tmpath.size();++i) {
            thishappy+=happy[tmpath[i]];
            if(thishappy>maxhappy || (thishappy==maxhappy) && (int)thishappy/tmpath.size()>avghappy) {
                maxhappy=thishappy;
                maxavg=maxhappy/tmpath.size();
                path=tmpath;
            }
        }
        tmpath.pop_back();
        return;
    }
    tmpath.push_back(v);
    for(int i=0;i<pre[v].size();++i)
        dfs(pre[v][i]);
    tmpath.pop_back();
}
int main() {
    fill(e[0],e[0]+max*max,inf);
    fill(dist,dist+max,-1);
    fill(visit,visit+max,-1);
    fill(happy,happy+max,0);
    fill(count,count+max,0);
    for(int i=0;i<max;++i) {
        for(int j=0;j<max;++j) {
            if(i==j) e[i][j]=0;
        }
    }
    string statCity,s,s1;
    int thishappy;
    cin>>vt>>ve>>statCity;
    city2num["statCity"]=0;
    num2city[0]=statCity;
    for(int i=1;i<=vt;++i) {
        cin>>s>>thishappy;
        city2num[s]=i;
        num2city[i]=s;
        happy[i]=thishappy;
    }
    for(int i=0;i<ve;++i) {
        cin>>s>>s1;
        cin>>e[city2num[s]][city2num[s1]];
        e[city2num[s1]][city2num[s]]=e[city2num[s]][city2num[s1]];
    }
    d=city2num["ROM"];
    dijkstra();
    dfs(d);
    cout<<count[d]<<" "<<dist[d]<<" "<<maxhappy<<" "<<avghappy<<endl;
    for(int i=path.size()-1;i>0)
        cout<<num2city[path[i]]<<"->";
    cout<<num2ciy[path[0]]<<endl;
}
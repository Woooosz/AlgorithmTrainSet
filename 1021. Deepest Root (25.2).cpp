#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#define MAX 10001
using namespace std;
int vt;
int visit[MAX];
vector<int> maps[MAX];
int set[MAX];
int find(int a) {
    return set[a]<0?a:(set[a]=find(set[a]));
}
void unions(int a,int b) {
    int roota=find(a);
    int rootb=find(b);
    if(roota!=rootb)
        set[roota]=rootb;
}
void dfs(int index,int count) {
    visit[index]=count;
    for(int i=0;i<maps[index].size();++i) {
        if(!visit[maps[index][i]]) {
            dfs(maps[index][i],count+1);
        }
    }
}
int main() {
    cin>>vt;
    int va,vb;
    for(int i=0;i<MAX;++i) {
        set[i]=-1;
    }
    for(int i=0;i<vt-1;++i) {
        cin>>va>>vb;
        maps[va].push_back(vb);
        maps[vb].push_back(va);
        unions(va,vb);
    }
    int count=0;
    for(int i=1;i<=vt;++i) {
        if(set[i]<0) count++;
    }
    if(count!=1) {
        cout<<"Error: "<<count<<" components"<<endl;
        return 0;
    }
    //twice dfs;
    memset(visit,0,sizeof(visit));
    dfs(1,1);
    int maxindex=-1,max=-1;
    for(int i=1;i<=vt;++i) {
        if(visit[i]>max) maxindex=i;
    }
    memset(visit,0,sizeof(visit));
    dfs(maxindex,1);
    max=-1;
    for(int i=1;i<=vt;++i)
        if(visit[i]>max) max=visit[i];
    visit[maxindex]=max;
    for(int i=1;i<=vt;++i) {
        if(max==visit[i]) {
            cout<<i<<endl;
        }
    }
}
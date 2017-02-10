#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct a {
    char na[10];
    int hei;
};
bool cmp(const a &b,const a &c) {
    if(b.hei!=c.hei) return b.hei>c.hei;
    else return strcmp(b.na,c.na)<0;
}
int main() {
    //freopen("/Users/shizhewu/a.in","r",stdin);
    int n,row;
    scanf("%d %d",&n,&row);
    vector<a> b(n);
    for(int i=0;i<n;++i)
        scanf("%s %d",&b[i].na,&b[i].hei);
    sort(b.begin(),b.end(),cmp);
    int d,e,f=0,g;
    for(int i=0;i<row;++i) {
        if(i==0) d=n / row + n % row; //该行人数
        else d= n / row;
        deque<a> que;
        e=0;
        while(e<d) {
            if(e%2) que.push_front(b[f++]);
            else que.push_back(b[f++]);
            ++e;
        }
        g=0;
        while(!que.empty()) {
            if(!g) {
                g=1;
                cout<<que.front().na;
            } else cout<<" "<<que.front().na;
            que.pop_front();
        }
        cout<<endl;
    }
}
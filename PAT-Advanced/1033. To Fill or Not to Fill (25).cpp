#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct node {
    double price;
    int kilo;
    int id;
    friend bool operator<(const node &a,const node &b)  {
        return (a.price-b.price>0);
    }
    node& operator-=(const node &a) {
        this->kilo-=a.kilo;
        return *this;
    }
};
bool compare(const node &a,const node &b) {
    return a.kilo<b.kilo;
}

int main() {
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
    int c,D,d,n,index=0;
    cin>>c>>D>>d>>n;
    vector<node> in(n);
    for(int i=0;i<n;++i){
        cin>>in[i].price>>in[i].kilo;
    }
    priority_queue<node> q;
    sort(in.begin(),in.end(),compare);
    for(int i=0;i<in.size();++i) in[i].id=i;
    double ans=.0,des=0;
    node cur=in[0];
    while(true) {
        int lim=c*d;
        for(int i=cur.id+1;in[i].kilo-des<lim;++i)
            q.push(in[i]);
        if(q.empty()) {
            if(des+lim<D) { //附近没有加油站，且无法到达目的地
                des+=lim;
                printf("The maximum travel distance = %.2f\n",des);
                break;
            } else { //附近没有加油站，但是能够到达目的地
                ans+=(D-des)/d*cur.price;
                printf("%.2lf\n",ans);
                break;
            }
        } else { //附近有加油站
            node next=q.top();
            index=next.id;
            if(des+lim>D && next<cur) {//附近有加油站，能够达到目的地->到达目的地
                ans+=(((D-des)/(double)d)*cur.price);
                printf("%.2lf\n",ans);
                break;
            } else { //附近有加油站，但是无法到达目的地->到达加油站
                ans+=((double)(next.kilo-des)/(double)d*cur.price);
                des=next.kilo;
                cur=next;
            }
        }
        while(!q.empty()) q.pop();
    }
}

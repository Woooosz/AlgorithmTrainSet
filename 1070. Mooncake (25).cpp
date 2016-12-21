#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node {
    double weight=.0;
    double price=.0;
};
int compare(const node &a,const node &b) {
    return (a.price/a.weight)-(b.price/b.weight)>0;
}
int main() {
    int num;
    double total;
    scanf("%d %lf",&num,&total);
    vector<node> in(num);
    for(int i=0;i<num;++i)
        scanf("%lf",&in[i].weight);
    for(int i=0;i<num;++i)
        scanf("%lf",&in[i].price);
    sort(in.begin(),in.end(),compare);
    double ans=.0;
    for(int i=0;i<num;++i) {
        if(in[i].weight<total) {
            ans+=in[i].price;
            total-=in[i].weight;
        } else {
            ans+=(total*(in[i].price/in[i].weight));
            break;
        }
    }
    printf("%.2lf",ans);
}
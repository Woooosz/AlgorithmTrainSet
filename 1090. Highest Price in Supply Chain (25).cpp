/*
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.

Input Specification:

Each input file contains one test case. For each case, The first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence they are numbered from 0 to N-1); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then the next line contains N numbers, each number Si is the index of the supplier for the i-th member. Sroot for the root supplier is defined to be -1. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price. There must be one space between the two numbers. It is guaranteed that the price will not exceed 1010.

Sample Input:
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
Sample Output:
1.85 2
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std;

const int maxv=100000+5;
vector<int> arr[maxv];
int visit[maxv],max_deep,vt,dist[maxv],maxp=0;
double a0,per,ans=.0;
map<int,int> id2total;
inline int max(int a,int b) {return a>b?a:b;}
using namespace std;
void bfs(int s) {
    fill(dist,dist+maxv,0);
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int tmp=q.front();
        q.pop();
        for(int i=0;i<arr[tmp].size();++i) {
            if(!visit[arr[tmp][i]]) {
                dist[arr[tmp][i]]=dist[tmp]+1;
                maxp=max(maxp,dist[arr[tmp][i]]);
                visit[arr[tmp][i]]=1;
                q.push(arr[tmp][i]);
            }
        }
        if(arr[tmp].size()==0) {
            double perprice=a0*pow(1+per*0.01,dist[tmp]);
            ans+=perprice*id2total[tmp];
        }
    }
    
}
int main() {
    int root=0;
    //freopen("/Users/shizhewu/a.in","r",stdin);
    scanf("%d %lf %lf",&vt,&a0,&per);
    for(int i=0;i<vt;++i) {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==-1) root=i;
        else arr[tmp].push_back(i);
    }
    fill(visit,visit+maxv,0);
    bfs(root);
    int count=0;
    for(int i=0;i<vt;++i)
        if(dist[i]==maxp) ++count;
    double perprice=a0*pow(1+per*0.01,maxp);
    printf("%.2lf %d\n",perprice,count);
}

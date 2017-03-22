/*
1079. Total Sales of Supply Chain (25)

时间限制
250 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the total sales from all the retailers.

Input Specification:

Each input file contains one test case. For each case, the first line contains three positive numbers: N (<=105), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N-1, and the root supplier's ID is 0); P, the unit price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

Ki ID[1] ID[2] ... ID[Ki]

where in the i-th line, Ki is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. Kj being 0 means that the j-th member is a retailer, then instead the total amount of the product will be given after Kj. All the numbers in a line are separated by a space.

Output Specification:

For each test case, print in one line the total sales we can expect from all the retailers, accurate up to 1 decimal place. It is guaranteed that the number will not exceed 1010.

Sample Input:
10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0 7
2 6 1
1 8
0 9
0 4
0 3
Sample Output:
42.4
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
//int arr[maxv][maxv];
int visit[maxv],max_deep,vt,dist[maxv];
double a0,per,ans=.0;
map<int,int> id2total;
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
    freopen("/Users/shizhewu/a.in","r",stdin);
    scanf("%d %lf %lf",&vt,&a0,&per);
    for(int i=0;i<vt;++i) {
        int k,tmp;
        scanf("%d",&k);
        if(k==0) {
            scanf("%d",&tmp);
            id2total[i]=tmp;
            continue;
        }
        for(int j=0;j<k;++j) {
            scanf("%d",&tmp);
            arr[i].push_back(tmp);
        }
    }
    fill(visit,visit+maxv,0);
    bfs(0);
    printf("%.1lf\n",ans);
}

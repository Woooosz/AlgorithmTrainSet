/*
1017. Queueing at Bank (25)

时间限制
400 ms
1.哨兵值要选取极大值
2.
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

Output Specification:

For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
Sample Output:
8.2
1.哨兵值要选取极值
2.注意客户到达银行时间更新上面的多重情况考虑
3.对于8：00时候的考虑多余，影响排序结果
*/
#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

struct node {
    int unix;
    int dely;
};
bool compare(const node a,const node b) {
    return a.unix<b.unix;
}
int getMin(vector<int> &windows,node a) {
    int cur=0x7fffffff;
    int tmp,index=-1;
    for(int i=0;i<windows.size();++i) {
        tmp=windows[i]-a.unix;
        if(tmp<cur) {
            cur=tmp;
            index=i;
        }
    }
    return index;
}
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#endif
    int persons,windows;
    int hour,min,sec,dely;
    int tmp;
    double ans=0.0;
    node tmpnd;
    vector<node> in;
    scanf("%d %d",&persons,&windows);
    for(int i=0;i<persons;++i) {
        scanf("%d:%d:%d %d",&hour,&min,&sec,&dely);
        if(hour>16 && (min>0||sec>0)) {
            continue;
        } else {
            tmp=hour*3600+min*60+sec;
        }
        tmpnd.unix=tmp;
        tmpnd.dely=dely*60;
        in.push_back(tmpnd);
    }
    sort(in.begin(),in.end(),compare);
    queue<node> que;
    for(int i=0;i<in.size();++i)
        que.push(in[i]);
    vector<int> deal(windows);
    for(int i=0;i<windows;++i)
        deal[i]=3600*8;
    int min_index;
    while(!que.empty()) {
        tmpnd=que.front();
        que.pop();
        min_index=getMin(deal,tmpnd);
        if(deal[min_index]-tmpnd.unix>0) {        //Be care of this.
            ans+=(deal[min_index]-tmpnd.unix);
            deal[min_index]+=tmpnd.dely;
        } else {
            deal[min_index]=tmpnd.unix+tmpnd.dely;
        }
    }
    if(ans<=1e-6)
        printf("0.0\n");
    else
        printf("%.1lf\n",ans/(60.0*in.size()));
}
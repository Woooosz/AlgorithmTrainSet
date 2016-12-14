/*
1020. 月饼 (25)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

输入样例：
3 20
18 15 10
75 72 45
输出样例：
94.50
关键问题是要注意两个点：

(1)注意库存可能不是整数（测试点2）
(2)可能库存不够（测试点3）
所以最好都要用double
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
struct node {
    double weight=0.0;
    double value=0.0;
};
bool compare(const node &a,const node &b) {
    double x=((double)a.value/(double)a.weight);
    double y=((double)b.value/(double)b.weight);
    return (x-y)>0;
}
int main() {
    int num;
    double tmp,total=0.0;
    scanf("%d %lf",&num,&total);
    vector<node> in(num);
    for(int i=0;i<num;++i) {
        scanf("%lf",&tmp);
        in[i].weight=tmp;
    }
    for(int i=0;i<num;++i) {
        scanf("%lf",&tmp);
        in[i].value=tmp;
    }
    sort(in.begin(),in.end(),compare);
    double ans=0.0;
    for(int i=0;i<num;++i) {
        if(total>in[i].weight) {
            ans+=in[i].value;
            total-=in[i].weight;
        } else {
            ans+=(total*(in[i].value/in[i].weight));
            break;
        }
    }
    printf("%.2lf\n",ans);
}
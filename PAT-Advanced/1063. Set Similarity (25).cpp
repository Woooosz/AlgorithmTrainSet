/*
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the number of distinct common numbers shared by the two sets, and Nt is the total number of distinct numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:

Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All the numbers in a line are separated by a space.

Output Specification:

For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3
Sample Output:
50.0%
33.3%
比较之后需要复位原有元素的状态以便下一轮比较
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef map<int,int>::iterator itor;
int main() {
    freopen("/Users/shizhewu/a.in","r",stdin);
    int n;
    scanf("%d",&n);
    int m,k;
    vector<map<int,int>> s(n+1);
    for(int i=1;i<=n;++i) {
        scanf("%d",&m);
        for(int j=0;j<m;++j) {
            scanf("%d",&k);
            s[i][k]=1;
        }
    }
    int l;
    scanf("%d",&l);
    for(int i=0;i<l;++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        int cn=0,ct=0;
        for(itor pi=s[a].begin();pi!=s[a].end();++pi) {
            //cout<<pi->first<<endl;
            itor pj=s[b].find(pi->first);
            if(pj!=s[b].end()) {
                ++cn;
                pj->second=0;
            }
            ++ct;
        }
        for(itor pi=s[b].begin();pi!=s[b].end();++pi) {
            if(pi->second ==1) ++ct;
        }
        double ans=(double)cn/ct;
        printf("%.1lf%%\n",ans*100);
    }
}
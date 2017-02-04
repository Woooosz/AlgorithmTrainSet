/*
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word "on-line" or "off-line".

For each test case, all dates will be within a single month. Each "on-line" record is paired with the chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
class node {
public:
    string name;
    int month;
    int day;
    int hour;
    int min;
    int status; //1表示on-line 0表示off-line
};
typedef map<string,vector<node>>::iterator itor;
typedef vector<node>::iterator v_itor;
bool compare(const node &a,const node &b) {
    if(a.day!=b.day) return a.day<b.day;
    if(a.hour!=b.hour) return a.hour<b.hour;
    return a.min<b.min;
    
}
int day2now(node a) {
    return a.day*1440+a.hour*60+a.min;
}
double price2now(int perday,node x,vector<int> &bill) {
    double ans=.0;
    ans+=x.day*perday*60;
    for(int i=0;i<x.hour;++i)
        ans+=bill[i]*60;
    ans+=bill[x.hour]*x.min;
    return ans;
}
int main() {
    freopen("/Users/shizhewu/a.in","r",stdin);
    vector<int> bill(24);
    int perday=0;
    for(int i=0;i<24;++i) {
        scanf("%d",&bill[i]);
        perday+=bill[i];
    }
    int n;
    scanf("%d",&n);
    map<string,vector<node>> in;
    for(int i=0;i<n;++i) {
        node tmp;
        char stats[10],name[10];
        scanf("%s %d:%d:%d:%d %s",&name[0],&tmp.month,&tmp.day,&tmp.hour,&tmp.min,stats);
        if(strcmp(stats,"on-line")==0) tmp.status=1;
        else tmp.status=0;
        tmp.name=name;
        in[tmp.name].push_back(tmp);
    }
    for(itor pi=in.begin();pi!=in.end();++pi)
        sort(pi->second.begin(),pi->second.end(),compare);
    v_itor next,pj;
    map<string,vector<node>> ans;
    stack<node> stk;
    for(itor pi=in.begin();pi!=in.end();++pi) {
        for(pj=pi->second.begin();pj!=pi->second.end();++pj) {
            if(pj->status==1) {
                stk.push(*pj);
            } else if(pj->status==0) {
                if(stk.empty()) continue;
                node x=stk.top();
                ans[pi->first].push_back(x);
                ans[pi->first].push_back(*pj);
                while(!stk.empty()) stk.pop();
            }
        }
        while(!stk.empty()) stk.pop(); //!!!!!!!记得清理栈中数据
    }
    
    for(itor pi=ans.begin();pi!=ans.end();++pi) {
        double totalbill=0;
        printf("%s %02d\n",pi->first.c_str(),pi->second[0].month);
        for(v_itor pj=pi->second.begin();pj!=pi->second.end();pj+=2) {
            next=pj+1;
            printf("%02d:%02d:%02d %02d:%02d:%02d",pj->day,pj->hour,pj->min,next->day,next->hour,next->min);
            int ans=day2now(*next)-day2now(*pj);
            double total=price2now(perday,*next,bill)-price2now(perday,*pj,bill);
            printf(" %d $%.2lf\n",ans,total/100);
            totalbill+=total;
        }
        printf("Total amount: $%.2lf\n",totalbill/100);
    }
    
}
/*
Zhejiang University has 6 campuses and a lot of gates. From each gate we can collect the in/out times and the plate numbers of the cars crossing the gate. Now with all the information available, you are supposed to tell, at any specific time point, the number of cars parking on campus, and at the end of the day find the cars that have parked for the longest time period.

Input Specification:

Each input file contains one test case. Each case starts with two positive integers N (<= 10000), the number of records, and K (<= 80000) the number of queries. Then N lines follow, each gives a record in the format

plate_number hh:mm:ss status

where plate_number is a string of 7 English capital letters or 1-digit numbers; hh:mm:ss represents the time point in a day by hour:minute:second, with the earliest time being 00:00:00 and the latest 23:59:59; and status is either in or out.

Note that all times will be within a single day. Each "in" record is paired with the chronologically next record for the same car provided it is an "out" record. Any "in" records that are not paired with an "out" record are ignored, as are "out" records not paired with an "in" record. It is guaranteed that at least one car is well paired in the input, and no car is both "in" and "out" at the same moment. Times are recorded using a 24-hour clock.

Then K lines of queries follow, each gives a time point in the format hh:mm:ss. Note: the queries are given in ascending order of the times.

Output Specification:

For each query, output in a line the total number of cars parking on campus. The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length. If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.

Sample Input:
16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00
Sample Output:
1
4
5
2
1
0
1
JH007BD ZD00001 07:20:09
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;
struct node {
    string name;
    int tol;
    int status;
};
typedef map<string,vector<node>>::iterator itor;
typedef map<string,int>::iterator itor2;
bool compare(const node &a,const node &b) {
    return a.tol<b.tol;
}
int main() {
    freopen("/Users/shizhewu/a.in","r",stdin);
    int n,m,hour,min,sec;
    scanf("%d %d",&n,&m);
    node a;
    char sta[10],name[10];
    map<string,vector<node>> in,deal;
    for(int i=0;i<n;++i) {
        scanf("%s %d:%d:%d %s",&name[0],&hour,&min,&sec,&sta[0]);
        a.name=name;
        a.status=sta[0] =='i'?1:0;
        int tol=hour*3600+min*60+sec;
        a.tol=tol;
        in[name].push_back(a);
    }
    for(itor pi=in.begin();pi!=in.end();++pi)
        sort(pi->second.begin(),pi->second.end(),compare);
    stack<node> stk;
    for(itor pi=in.begin();pi!=in.end();++pi) {
        while(!stk.empty()) stk.pop();
        for(int i=0;i<pi->second.size();++i) {
            if(stk.empty() && pi->second[i].status==0) continue;
            if(pi->second[i].status==1) stk.push(pi->second[i]);
            else {
                deal[pi->first].push_back(stk.top());
                deal[pi->first].push_back(pi->second[i]);
                while(!stk.empty()) stk.pop();
            }
        }
    }
    map<string,int> time;
    int maxv=-1;
    for(itor pi=deal.begin();pi!=deal.end();++pi) {
        int maxtime=-1,thistime=0;
        for(int i=0;i<pi->second.size();i+=2) {
            thistime+=pi->second[i+1].tol-pi->second[i].tol;
            if(thistime>maxtime) maxtime=thistime;
            if(thistime>maxv) maxv=thistime;
        }
        time[pi->first]=maxtime;
    }
    vector<int> mm(m),counts(m);
    for(int i=0;i<m;++i){
        scanf("%d:%d:%d",&hour,&min,&sec);
        int tol=hour*3600+min*60+sec;
        mm[i]=tol;
    }

    for(itor pi=deal.begin();pi!=deal.end();++pi) {
        for(int i=0;i<pi->second.size();i+=2) {
            for(int j=0;j<m;++j) {
                if(pi->second[i].tol<=mm[j] && pi->second[i+1].tol>mm[j]) ++counts[j];
            }
        }
    }
    for(int i=0;i<mm.size();++i)
        printf("%d\n",counts[i]);
    int flag=0;
    for(itor2 pi=time.begin();pi!=time.end();++pi) {
        if(pi->second==maxv) {
            if(!flag) {
                flag=1;
                printf("%s",pi->first.c_str());
            } else
                printf(" %s",pi->first.c_str());
        }
    }
    sec=maxv%60;
    min=(maxv/60)%60;
    hour=(maxv/60/60)%60;
    printf(" %02d:%02d:%02d\n",hour,min,sec);
}

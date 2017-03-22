/*
A gas station has to be built at such a location that the minimum distance between the station and any of the residential housing is as far away as possible. However it must guarantee that all the houses are in its service range.

Now given the map of the city and several candidate locations for the gas station, you are supposed to give the best recommendation. If there are more than one solution, output the one with the smallest average distance to all the houses. If such a solution is still not unique, output the one with the smallest index number.

Input Specification:

Each input file contains one test case. For each case, the first line contains 4 positive integers: N (<= 103), the total number of houses; M (<= 10), the total number of the candidate locations for the gas stations; K (<= 104), the number of roads connecting the houses and the gas stations; and DS, the maximum service range of the gas station. It is hence assumed that all the houses are numbered from 1 to N, and all the candidate locations are numbered from G1 to GM.

Then K lines follow, each describes a road in the format
P1 P2 Dist
where P1 and P2 are the two ends of a road which can be either house numbers or gas station numbers, and Dist is the integer length of the road.

Output Specification:

For each test case, print in the first line the index number of the best location. In the next line, print the minimum and the average distances between the solution and all the houses. The numbers in a line must be separated by a space and be accurate up to 1 decimal place. If the solution does not exist, simply output “No Solution”.

Sample Input 1:
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
Sample Output 1:
G1
2.0 3.3
Sample Input 2:
2 1 2 10
1 G1 9
2 G1 20
Sample Output 2:
No Solution
这道题坑爹的地方在题意，标准是，在每条该gas station距离居住区最短距离中，选取最大的。
如果有并列路径，则选取平均距离最短的
如果还是有并列路径，选取标号最小的
题意理解很重要
*/
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxv=1020;
const int inf=0x7ffff;
int visit[maxv],v_h,v_g,ve,lim,vt,e[maxv][maxv],mintotaldis=-1,gas_v,dist[maxv];
int inde=1;
double avgdis=inf,thismin=-1;
vector<int> gas;
map<string,int> gas2num;
map<int,string> num2gas;

int find_min_dist() {
    int min=inf,index=-1;
    for(int i=1;i<=vt;++i) {
        if(dist[i]<min && visit[i]==-1) {
            min=dist[i];
            index=i;
        }
    }
    return index;
}
void dijkstra(int s) {
    fill(visit,visit+vt+1,-1);
    for(int i=1;i<=vt;++i) {
        dist[i]=e[s][i];
    }
    for(;;) {
        int tmp=find_min_dist();
        if(tmp==-1) break;
        visit[tmp]=1;
        for(int i=1;i<=vt;++i) {
            if(visit[i]==-1 && e[tmp][i]<inf) {
                if(dist[i]>dist[tmp]+e[tmp][i]) {
                    dist[i]=dist[tmp]+e[tmp][i];
                }
            }
        }
    }
}
int string2int(string s) {
    int ans=0;
    if(s[0]=='G') {
        if(gas2num.find(s)!=gas2num.end()) {
            ans=gas2num[s];
        } else {
            int tmp;
            tmp=v_h+inde;
            num2gas[tmp]=s;
            gas2num[s]=tmp;
            gas.push_back(tmp);
            inde++;
            ans=tmp;
        }
    } else {
        for(int i=0;i<s.length();++i)
            ans=ans*10+(s[i]-'0');
    }
    return ans;
}
int main() {
    cin>>v_h>>v_g>>ve>>lim;
    vt=v_h+v_g;
    fill(visit,visit+maxv,-1);
    fill(e[0],e[0]+maxv*maxv,inf);
    for(int i=0;i<maxv;++i) {
        for(int j=0;j<maxv;++j)
            if(i==j) e[i][j]=0;
    }
    for(int i=0;i<ve;++i) {
        string s,s2;
        cin>>s>>s2;
        int a,b;
        a=string2int(s),b=string2int(s2);
        int dis;
        cin>>dis;
        e[a][b]=e[b][a]=dis;
    }
    for(int i=0;i<gas.size();++i) {
        dijkstra(gas[i]);
        int minv=inf,maxv=-1;
        double thistotal=0;
        for(int j=1;j<=v_h;++j) {
            if(minv>dist[j])
                minv=dist[j];
            if(maxv<dist[j])
                maxv=dist[j];
            thistotal+=dist[j];
        }
        if(maxv>lim) continue;
        else {
            if(thismin<minv) {
                mintotaldis=thistotal;
                avgdis=thistotal/v_h;
                thismin=minv;
                gas_v=gas[i];
            } else if(thismin==minv && mintotaldis>thistotal) {
                avgdis=thistotal/v_h;
                mintotaldis=thistotal;
                gas_v=gas[i];
            } else if(thismin==minv && mintotaldis==thistotal && num2gas[gas_v]>num2gas[gas[i]]) {
                gas_v=gas[i];
            }
        }
    }
    if(thismin==-1) {
        cout<<"No Solution"<<endl;
        return 0;
    }
    cout<<num2gas[gas_v]<<endl;
    printf("%.1lf %.1lf",thismin,avgdis);
}
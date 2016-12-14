/*
1011. World Cup Betting (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:

 W    T    L
1.1  2.5  1.7
1.2  3.0  1.6
4.1  1.2  1.1
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1*3.0*2.5*65%-1)*2 = 37.98 yuans (accurate up to 2 decimal places).

Input

Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

Output

For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

Sample Input
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1
Sample Output
T T W 37.98
*/
#include<iostream>
#include<vector>

using namespace std;
struct node {
    int index;
    double val;
};
int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("/Users/shizhewu/Desktop/proj/proj/i.txt","r",stdin);
#endif
    vector<double> d(3);
   	char *set=new char[3];
   	double total=1.0;
    set[0]='W',set[1]='T',set[2]='L';
    for(int i=0;i<3;++i) {
        scanf("%lf %lf %lf",&d[0],&d[1],&d[2]);
        double max=-1;
        int index=-1;
        for(int i=0;i<3;++i) {
            if(d[i]>max) {
                max=d[i];
                index=i;
            }
        }
        if(i==0) {
            printf("%c",set[index]);
        } else {
            printf(" %c",set[index]);
        }
        total*=d[index];
    }
    printf(" %.2lf",(total*0.65-1)*2);
    delete[] set;
}
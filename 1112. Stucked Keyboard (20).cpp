#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef map<char,int>::iterator itor;
int main() {
    freopen("/Users/shizhewu/a.in","r",stdin);
    int n;
    scanf("%d",&n);
    char s[1005];
    cin>>s;
    map<char,int> d;
    char *pi=s;
    int f;
    while(*pi!='\0') {
        f=0;
        char thischar=pi[0];
        for(int i=1;i<n;++i) {
            if(pi[i]!=thischar) {
                d[thischar]=0;
                pi++;
                f=1;
                break;
            } else {
                if(d.find(thischar)==d.end()) {
                    d[thischar]=1;
                }
            }
        }
        if(f) continue;
        else pi+=n;
    }
    pi=s;
    f=0;
    set<char> check;
    while(*pi!='\0') {
        if(d[*pi]!=0 && check.find(*pi)==check.end()) {
            f=1;
            printf("%c",*pi);
            check.insert(*pi);
            pi+=n;
            continue;
        }
        ++pi;
    }
    if(f) printf("\n");
    pi=s;
    while(*pi!='\0') {
        if(d[*pi]==0) {
            printf("%c",*pi);
            pi++;
        } else {
            printf("%c",*pi);
            pi+=n;
        }
    }
    printf("\n");
}

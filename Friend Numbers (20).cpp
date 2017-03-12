#include <iostream>
#include <map>
using namespace std;
typedef map<int,int>::iterator itor;
int main () {
    int n,t,m,sum = 0;
    map<int,int> d;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t);
        while(t > 0) {
            sum += (t % 10);
            t /= 10;
        }
        d[sum]++;
        sum = 0;
    }
    int f = 0;
    printf("%d\n", d.size());
    for(itor pi = d.begin(); pi != d.end(); ++pi) {
        if(!f) {
            printf("%d", pi->first);
            f = 1;
        } else {
            printf(" %d", pi->first);
        }
    }
    printf("\n");
    return 0;
}
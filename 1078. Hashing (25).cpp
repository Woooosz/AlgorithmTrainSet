#include <iostream>
#include <vector>
using namespace std;

int find_next_prime(int x) {
    if(x == 1) x++;
    while(true) {
        int f = 1;
        for(int i = 2; i * i <= x; ++i) {
            if(x % i == 0) {
                ++x;
                f = 0;
                break;
            }
        }
        if(f) return x;
    }
}
int main() {
    int n,m;
    scanf("%d %d", &m, &n);
    m = find_next_prime(m);
    vector<bool> isVisit(m);
    int thisnum;
    int p = 0, x;
    for(int i = 0; i < n; ++i) {
        scanf("%d",&thisnum);
        bool exist = false;
        for(int j = 0; j < m; ++j) {
            x = (thisnum + j * j) % m;
            if(!isVisit[x]) {
                if(i != 0) printf(" ");
                isVisit[x] = true;
                exist = true;
                printf("%d", x);
                break;
            } else {
                p++;
            }
        }
        if(!exist) {
            if(i != 0) printf(" ");
            printf("-");
        }
    }
    printf("\n");
}

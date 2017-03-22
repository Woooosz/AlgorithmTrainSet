#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> p;
    vector<bool> isVisit;
    for(int i = 0; i < n; ++i) {
        int thisn;
        bool ans = true;
        scanf("%d", &thisn);
        p.resize(thisn+1);
        isVisit.resize(thisn + 1);
        fill(isVisit.begin(),isVisit.end(),false);
        
        for(int j = 1; j <= thisn; ++j)
            scanf("%d", &p[j]);
        for(int j = 1; j <= thisn; ++j) {
            int current = p[j];
            if(isVisit[current]) ans = false;
            else isVisit[current] = true;
            if(j == 1) continue;
            int f = 1;
            for(int k = j - 1; k >= 1; --k) {
                if(p[k] == current - f) ans = false;
                f++;
            }
            if(!ans) break;
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
}
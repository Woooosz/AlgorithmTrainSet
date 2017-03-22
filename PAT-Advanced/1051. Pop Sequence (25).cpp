#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
    int n, m, k;
    scanf("%d %d %d", &m, &n, &k);
    
    for(int i = 0; i < k; ++i) {
        stack<int> s;
        vector<int> d(n);
        for(int j = 0; j < n; ++j)
            scanf("%d", &d[j]);
        bool ans = false;
        int current = 0;
        for(int j = 1; j <= n; ++j) {
            s.push(j);
            if(s.size() > m) break;
            while(!s.empty() && d[current] == s.top()) {
                s.pop();
                ++current;
            }
        }
        if(current == n) ans = true;
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long int ll;
int main() {
    ll n, m, p, ans = 0;
    priority_queue<ll, vector<ll>, less<ll>> c1, b1;
    priority_queue<ll, vector<ll>, greater<ll>> c2, b2;
    scanf("%lld",&n);
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &p);
        if(p > 0) c1.push(p);
        else c2.push(p);
    }
    scanf("%lld", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%lld", &p);
        if(p > 0) b1.push(p);
        else b2.push(p);
    }
    while(!c1.empty() && !b1.empty()) {
        ans += c1.top() * b1.top();
        c1.pop(); b1.pop();
    }
    while(!c2.empty() && !b2.empty()) {
        ans += c2.top() * b2.top();
        c2.pop(); b2.pop();
    }
    printf("%lld\n", ans);
}
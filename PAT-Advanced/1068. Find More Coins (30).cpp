#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool isChoice[10010][10010];
int dp[10010], v[10010];
int cmp(int a, int b) {return a > b; }
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    fill(dp, dp+10010, 0);
    for(int i = 0; i < n; ++i)
        scanf("%d", &v[i]);
    sort(v, v+n,cmp);
    for(int i = 0; i < n; ++i) {
        for(int j = m; j >= v[i]; --j) {
            if(dp[j] <= dp[j - v[i]] + v[i]) {
                dp[j] = dp[j - v[i]] + v[i];
                isChoice[i][j] = true;
            }
        }
    }
    if(dp[m] != m) {
        printf("No Solution\n");
    } else {
        vector<int> arr;
        int cur = m;
        for(int i = n - 1; i >= 0; --i) {
            if(isChoice[i][cur]) {
                arr.push_back(v[i]);
                cur-=v[i];
            }
        }
        for(int i = 0; i < arr.size(); ++i) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}
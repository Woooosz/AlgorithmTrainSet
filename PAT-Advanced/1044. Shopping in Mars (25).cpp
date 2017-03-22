#include <iostream>
using namespace std;
inline int max(int a, int b) {return a > b ? a : b}
int main() {
	int n;
	cin<<n;
	vector<int> dp(n), a(n);
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	dp[0] = a[0];
	for(int i = 1; i < n; ++i) {
		dp[i] = max(dp[i-1], a[i]);
	}
}
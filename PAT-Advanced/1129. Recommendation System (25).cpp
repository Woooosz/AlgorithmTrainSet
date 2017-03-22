#include <iostream>
#include <vector>
using namespace std;
struct node {
	int id;
	int times;
	node(int _id):id(_id),times(0) {}
	friend bool operator > (node &a, node &b) {
		if(a.times != b.times) return a.times > b.times;
		else return a.id < b.id;
	}
};
int main() {
	int n,k;
	scanf("%d %d", &n, &k);
	vector<node> p;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &p[i]);
	}

}
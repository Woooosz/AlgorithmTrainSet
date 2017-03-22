#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string thisone,nextone;
    scanf("%d\n", &n);
    getline(cin, thisone);
    for(int i = 1; i < n; ++i) {
        getline(cin, nextone);
        int p = thisone.size(), q = nextone.size();
        if(nextone.substr(nextone.size() - thisone.size(), -1) == thisone) continue;
        while(thisone[p--] == nextone[q--]);
        thisone = thisone.substr(p+2, -1);
    }
    if(thisone.size() == 0) cout<<"nai"<<endl;
    else cout<<thisone<<endl;
}
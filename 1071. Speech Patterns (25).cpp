#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;
typedef map<string,int>::iterator itor;
int main() {
    string s;
    getline(cin,s);
    map<string,int> d;
    for(int i = 0; i< s.length(); ++i) {
        if(isalnum(s[i])) {
            s[i] = tolower(s[i]);
        } else {
            s[i] = ' ';
        }
    }
    int j,i = 0;
    while(i < s.length()) {
        if(s[i] == ' ')  {
            ++i;
            continue;
        }
        j = 0;
        while(s[j + i] != ' ' && j < s.length()) ++j;
        d[s.substr(i,j)]++;
        i += j;
    }
    itor max = d.begin();
    for(itor pi = d.begin(); pi != d.end(); ++pi) {
        if(pi->second > max->second) max = pi;
        if(pi->second == max->second && pi->first < max->first) max = pi;
    }
    cout<<max->first<<" "<<max->second<<endl;
}
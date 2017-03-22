#include <iostream>
#include<string>
#include <map>
using namespace std;
int main() {
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    map<char,int> d;
    for(int i=0;i<s2.length();++i)
        d[s2[i]]++;
    for(int i=0;i<s1.length();++i) {
        if(d.find(s1[i])==d.end())
            printf("%c",s1[i]);
    }
}
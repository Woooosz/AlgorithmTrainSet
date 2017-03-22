/*
1065. A+B and C (64bit) (20)

时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
HOU, Qiming
Given three integers A, B and C in [-263, 263], you are supposed to tell whether A+B > C.

Input Specification:

The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

Output Specification:

For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1).

Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
Sample Output:
Case #1: false
Case #2: true
Case #3: false
这道题的思路起源于《深入理解计算机系统》中的一个知识点：
判断是否上溢出：a+b<min(a,b) 
判断是否下溢出：a+b>max(a,b)
对这两种情况分别处理即可
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    long long int a,b,c;
    int num;
    cin>>num;
    for(int i=1;i<=num;++i) {
        cin>>a>>b>>c;
        if(b>a) swap(a,b);
        cout<<"Case #"<<i<<": ";
        if((a>0 && b>0 &&(a+b)<b)) cout<<"true";
        else if(a<0 && b<0 && (a+b)>a) cout<<"false";
        else if(a+b>c) cout<<"true";
        else cout<<"false";
        cout<<endl;
    }
    
}
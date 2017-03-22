/*
1005. Spell It Right (20)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).

Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

Sample Input:
12345
Sample Output:
one five
So easy~
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

int main() {
    char num[100];
    scanf("%s",num);
    char *pi=num;
    int sum=0;
    while(*pi!='\0')
        sum+=*pi++-48;
    vector<string> dict={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int flag=0;
    stack<int> stk;
    if(sum==0) stk.push(0);
    while(sum!=0) {
        stk.push(sum%10);
        sum/=10;
    }
    while(!stk.empty()) {
        if(!flag) {
            flag=1;
            cout<<dict[stk.top()];
        } else {
            cout<<" "<<dict[stk.top()];
        }
        stk.pop();
    }
    
}
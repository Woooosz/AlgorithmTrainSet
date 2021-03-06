/*
Given an increasing sequence S of N integers, the median is the number at the middle position. For example, the median of S1={11, 12, 13, 14} is 12, and the median of S2={9, 10, 15, 16, 17} is 15. The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

Input

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. For each sequence, the first positive integer N (<=1000000) is the size of that sequence. Then N integers follow, separated by a space. It is guaranteed that all the integers are in the range of long int.

Output

For each test case you should output the median of the two given sequences in a line.

Sample Input
4 11 12 13 14
5 9 10 15 16 17
Sample Output
13
内存开销较少，花费时间稍微长一些
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int compare(const long int a,const long int b) {
    return a<b;
}
int main() {
    long int numa,tmp;
    vector<long int> in;
    for(int i=0;i<2;++i) {
        scanf("%ld",&numa);
        while(numa--) {
            scanf("%ld",&tmp);
            in.push_back(tmp);
        }
    }
    sort(in.begin(),in.end(),compare);
    double num=in.size();
    if((((double)(num/2)-(int)(num/2)))>0.4)
        cout<<in[(int)(num/2)];
    else
        cout<<in[(int)num/2-1];
}
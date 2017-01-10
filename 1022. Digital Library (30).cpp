/*
1022. Digital Library (30)

时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:

For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.

Sample Input:
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
Sample Output:
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
struct Book{
    char id[8];
    char title[81];
    char author[81];
    char keywords[81];
    char publisher[81];
    char year[5];
    friend bool operator>(const Book &a,const Book&b) {
        return strcmp(a.id,b.id)>0;
    }
};
bool compare(const Book &a,const Book &b)  {
    return strcmp(a.id,b.id)<0;
}

int main() {
    int n,m,i,flag=0;
    scanf("%d\n",&n);
    vector<Book> in(n);
    string s;
    for(int i=0;i<n;++i) {
        getline(cin,s);
        strcpy(in[i].id,s.c_str());
        getline(cin,s);
        strcpy(in[i].title,s.c_str());
        getline(cin,s);
        strcpy(in[i].author,s.c_str());
        getline(cin,s);
        strcpy(in[i].keywords,s.c_str());
        getline(cin,s);
        strcpy(in[i].publisher,s.c_str());
        getline(cin,s);
        strcpy(in[i].year,s.c_str());
    }
    sort(in.begin(),in.end(),compare);
    scanf("%d\n",&m);
    char query[91];
    for(i=0;i<m;++i) {
        getline(cin,s);
        cout<<s<<endl;
        strcpy(query,s.c_str());
        char *pi=query+3;
        int num=query[0]-'0';
        flag=0;
        for(int j=0;j<in.size();j++) {
            Book cur=in[j];
            if(num==1)
                if(strstr(cur.title,pi)) printf("%s\n",cur.id),flag=1;
            if(num==2)
                if(strstr(cur.author,pi)) printf("%s\n",cur.id),flag=1;
            if(num==3)
                if(strstr(cur.keywords,pi)) printf("%s\n",cur.id),flag=1;
            if(num==4)
                if(strstr(cur.publisher,pi) && strcmp(cur.publisher,pi)==0) printf("%s\n",cur.id),flag=1;
            if(num==5)
                if(strstr(cur.year,pi)) printf("%s\n",cur.id),flag=1;
        }
        if(flag==0) printf("Not Found\n");
    }
}

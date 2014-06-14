#include<bits/stdc++.h>
using namespace std;

inline void readint(int *var)
{
    register char ch=0;
    *var=0;
    //Escaping space and Enter characters
    while (ch<33)
        ch=getchar();
    //Consider only numerals
    while (ch>47 && ch<58)
    {
        *var=(*var * 10) + (ch-'0');
        ch=getchar();
    }
}

int main()
{
 int a;
 readint(&a);
 cout<<a;
}

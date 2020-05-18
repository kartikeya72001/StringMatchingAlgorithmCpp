#include <iostream>
using namespace std;
#define Max_N 100005
int reset[Max_N];

void KMPpre(string p)
{
    int i=0,j=-1;
    reset[0] = -1;
    while (i<p.length()) {
        while(j>=0 and p[i]!=p[j])
        {
            j = reset[j];
        }
        i++;
        j++;
        reset[i] = j;
    }
}

void KMPmain(string s, string p)
{
    KMPpre(p);
    int i=0,j=0;
    while (i<s.length()) {
        while(j>=0 and s[i]!=p[j])
            j = reset[j];
        i++;
        j++;
        if(j==p.length())
        {
            cout<<"Pattern is found at: "<<i-j<<endl;
            j = reset[j];
        }
    }
}

int main(int argc, char const *argv[]) {
    for(int i=0;i<Max_N;i++)
        reset[i] = -1;
    string s,p;
    cin>>s>>p;
    KMPmain(s,p);
    return 0;
}

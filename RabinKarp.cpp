#include <iostream>
#include <math.h>
using namespace std;
#define ll long long int
#define prime 119

ll HashValue(string s, int n)
{
    ll result = 0;
    for(int i=0;i<n;i++)
    {
        result += (ll)(s[i]*(ll)pow(prime,i));
    }
    return result;
}

ll recalculateHash(string s, int oldI, int newI,ll oldHash, int patn)
{
    ll newHash = oldHash - s[oldI];
    newHash/=prime;
    newHash+=(ll)(s[newI]*(ll)pow(prime,patn-1));
    return newHash;
}

bool checkEquality(string s, string p, int s1, int e1, int s2, int e2)
{
    if(e1-s1 != e2-s2)
        return false;

    while(s1<=e1 and s2<=e2)
    {
        if(s[s1]!=p[s2])
            return false;
        s1++;
        s2++;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    string s = "ababcabdab";
    string p = "abd";
    ll pathash = HashValue(p,p.length());
    ll strhash = HashValue(s,p.length());
    for(int i=0;i<(s.length()-p.length());i++)
    {
        if(pathash==strhash and checkEquality(s,p,i,i+p.length()-1,0,p.length()-1))
        {
            cout<<"Pattern is found at: "<<i<<endl;
            return 0;
        }
        if(i<s.length()-p.length())
        {
            strhash = recalculateHash(s,i,i+p.length(),strhash,p.length());
        }
    }
    return 0;
}

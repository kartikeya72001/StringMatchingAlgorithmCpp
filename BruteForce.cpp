#include <iostream>
using namespace std;

void NaiveSearch(string s, string p)
{
    for(int i=0;i<s.length()-p.length();i++)
    {
        int j;
        for(j=0;j<p.length();j++)
        {
            if(s[i+j]!=p[j])
                break;
        }
        if(j==p.length())
        {
            cout<<"Pattern is found at index: "<<i<<endl;
        }
    }
}

int main(int argc, char const *argv[]) {
    string s,p;
    cin>>s>>p;
    NaiveSearch(s,p);
    return 0;
}

#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;


long long int mod(string st, long long int p)
{
    long long int res = 0;
    for(int i = 0; i < st.length(); i++)
    {
        res = (res * 10 + (int)st[i] - '0') % p;
    }

    return res;
}

/* Driver Code */
int main()
{
    long long int tc,p;
    string val;
    cin >> tc;
    while(tc)
    {
        cin >> val >> p;
        cout << mod(val, p) << '\n';
        tc--;
    }

return 0;
}


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int duplicates(string s)
    {

        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << "Given String : " << s << endl;
        Solution ob;
        cout << "Duplicates : "
    }
}

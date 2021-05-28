#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool rotation(string str1, string str2)
    {
        if (str1.length() != str2.length())
            return false;
        string temp = str1 + str1;

        return (temp.find(str2) != string::npos);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        if (ob.rotation(s1, s2))
            cout << "Given String : " << s1 << " is Rotation of : " << s2 << endl;
        else
            cout << "Given String : " << s1 << " is NOT Rotation of : " << s2 << endl;
    }
}

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int start = 0, end = s.length() - 1;
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++, end--;
        }
        return true;
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

        Solution ob;
        if (ob.isPalindrome(s))
            cout << "Given String : " << s << " is Palindrome." << endl;
        else
            cout << "Given String : " << s << " is NOT Palindrome." << endl;
    }
}

*/

class Solution
{
public:
    bool isPalindromeUtil(string s, int start, int end)
    {
        if (start < end)
            return true;

        if (s[start] != s[end + 1])
            return false;

        return isPalindromeUtil(s, start++, end--);
    }
    bool isPalindrome(string s)
    {
        int start = 0, end = s.length() - 1;
        if (end == 0 || end == 1)
            return false;

        bool ans = isPalindromeUtil(s, start, end);

        return ans;
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

        Solution ob;
        if (ob.isPalindrome(s))
            cout << "Given String : " << s << " is Palindrome." << endl;
        else
            cout << "Given String : " << s << " is NOT Palindrome." << endl;
    }
}
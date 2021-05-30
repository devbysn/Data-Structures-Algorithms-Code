#include <iostream>
#include <string>
using namespace std;

/* class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int LCS(int x, int y, string s1, string s2)
    {
        // your code here
        if (x == 0 || y == 0)
            return 0;
        if (s1[x - 1] == s2[y - 1])
        {
            return 1 + LCS(x - 1, y - 1, s1, s2);
        }

        else
        {
            return max(LCS(x - 1, y, s1, s2), LCS(x, y - 1, s1, s2));
        }
    }
};

int main()
{
    string A = "ABCDEFG";
    string B = "DACACBE";
    Solution ob;
    cout << ob.LCS(A.length(), B.length(), A, B, ) << endl;
    return 0;
}
 */

//TOP-DOWN APPROACH
/* int DP[1001][1001];

class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings
    int LCS(int x, int y, string s1, string s2)
    {
        // your code here
        if (x == 0 || y == 0)
            return 0;

        if (DP[x][y] != 0)
            return DP[x][y];

        if (s1[x - 1] == s2[y - 1])
        {
            return DP[x][y] = 1 + LCS(x - 1, y - 1, s1, s2);
        }

        else
        {
            return DP[x][y] = max(LCS(x - 1, y, s1, s2), LCS(x, y - 1, s1, s2));
        }
    }
};

int main()
{
    string A = "UBZVAFSPQPQ";
    string B = "WUZIF";
    Solution ob;
    cout << ob.LCS(A.length(), B.length(), A, B) << endl;
    return 0;
}
 */

class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings
    int LCS(int x, int y, string s1, string s2)
    {
        int DP[x + 1][y + 1];

        for (int i = 0; i <= x; i++)
        {
            DP[i][0] = 0;
        }

        for (int i = 0; i <= y; i++)
        {
            DP[0][i] = 0;
        }

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    DP[i][j] = 1 + DP[i - 1][j - 1];
                }
                else
                {
                    DP[i][j] = max((DP[i][j - 1]), (DP[i - 1][j]));
                }
            }
        }
        return DP[x][y];
    }
};

int main()
{
    string A = "UBZVAFSPQPQ";
    string B = "WUZIF";
    Solution ob;
    cout << ob.LCS(A.length(), B.length(), A, B) << endl;
    return 0;
}

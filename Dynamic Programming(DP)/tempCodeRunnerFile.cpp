int DP[1001][1001];

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
// by watercolor, 2023-03-23

#define MAX_SIZE 45+1

int climbStairs(int n)
{
    int dp[MAX_SIZE];

    dp[0] = 1;

    for(int i = 1; i < n; i++) {
        dp[i] = dp[i-1];
        dp[i] += (i > 1) ? dp[i-2] : 1;
    }

    return dp[n-1];
}

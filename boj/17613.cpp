/*
 * 1 = 1
 * 2 = 1 + 1
 * 3 = 1 + 2
 * 4 = 1 + 2 + 1
 * 5 = 1 + 2 + 1 + 1 = 2^2-1 + 2^1-1 + 2^1 -1
 * 6 = 1 + 2 + 1 + 2
 * 7 = 1 + 2 + 4
 * 8 = 1 + 2 + 4 + 1
 * 9 = 1 + 2 + 4 + 1 + 1
 * 10 = 1 + 2 + 4 + 1 + 2
 * 11 = 1 + 2 + 4 + 1 + 2 + 1
 * 12 = 1 + 2 + 4 + 1 + 2 + 1 + 1
 * 13 = 1 + 2 + 4 + 1 + 2 + 1 + 2
 * 14 = 1 + 2 + 4 + 1 + 2 + 4
 * 15 = 1 + 2 + 4 + 8
 * 16 = 1 + 2 + 4 + 8 + 1
 * 19 = 1 + 2 + 4 + 8 + 1 + 2 + 1
 * dp[n] = dp[m] + dp[n-m] (m = 2^k-1 < n max k)
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int max(int a, int b) {
  return a > b ? a : b;
}

int LCS(char* s1, char* s2, int m, int n) {
  int dp[MAX_LENGTH + 1][MAX_LENGTH + 1];
  int i, j;

  for (i = 0; i <= m; i++) {
    for (j = 0; j <= n; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[m][n];
}

int main() {
  char s1[MAX_LENGTH], s2[MAX_LENGTH];
  int m, n;

  printf("Enter the first string: ");
  scanf("%s", s1);

  printf("Enter the second string: ");
  scanf("%s", s2);

  m = strlen(s1);
  n = strlen(s2);

  printf("The length of the longest common subsequence is: %d\n", LCS(s1, s2, m, n));

  return 0;
}

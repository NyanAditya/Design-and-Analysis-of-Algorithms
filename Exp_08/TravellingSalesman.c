#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 20

int n;
int graph[MAX][MAX];
int dp[MAX][1 << MAX];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int pos, int mask) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }
    
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    
    int ans = INT_MAX;
    
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(city, mask | (1 << city));
            ans = min(ans, newAns);
        }
    }
    
    return dp[pos][mask] = ans;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);
    
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < (1 << MAX); j++) {
            dp[i][j] = -1;
        }
    }
    
    int result = tsp(0, 1);
    
    printf("Minimum cost: %d\n", result);
    
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[505][505] = { 0, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
    
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= i; j++) {
			cin >> dp[i][j];
		}
	}

	int mmax = dp[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i+1; j++) {
			if (j == 1) dp[i][j] += dp[i - 1][j] ;
			else if (j == i) dp[i][j] += dp[i - 1][j-1] ;
			else dp[i][j] += max(dp[i - 1][j-1], dp[i - 1][j]);
			mmax = max(mmax, dp[i][j]);
		}
	}
    
	cout << mmax << '\n';
}
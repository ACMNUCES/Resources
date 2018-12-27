#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 15;
int t;
int n;
int arr[N];
long long sum[N];
int solve(int l , int r){
	if(r <= l){
		return 0;
	}
	long long val = sum[r] - sum[l - 1] >> 1;
	int idx = lower_bound(sum + l , sum + r + 1 , val + sum[l - 1]) - sum;
	if(sum[r] - sum[idx] == sum[idx] - sum[l - 1]){
		return 1 + max(solve(l , idx) , solve(idx + 1 , r));
	}
	return 0;
}
int main(){
	scanf("%d" , &t);
	while(t--){
		scanf("%d" , &n);
		for(int i = 1 ; i <= n ; ++i){
			scanf("%d" , arr + i);
		}
		for(int i = 1 ; i <= n ; ++i){
			sum[i] = sum[i - 1] + arr[i];
		}
		printf("%d\n" , solve(1 , n));
	}
}

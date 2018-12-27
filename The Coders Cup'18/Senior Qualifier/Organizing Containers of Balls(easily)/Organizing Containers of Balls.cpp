#include <iostream>

using namespace std;

#define REP(i,a,b) for(int i=a; i<b; i++)
#define REP2(i,a,b) for(i=a; i<b; i++)

int main(void) {
	int q;
	cin >> q;
	REP(l,0, q) {
		int n;
		cin >> n;
		int a[n] = {0};
		int b[n] = {0};
		int x;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cin >> x;
				a[i] += x;
				b[j] += x;
			}
		}
		int j=0;
		for(int i=0;i<n;i++)
		{
			j=0;
			for(j=i;j<n;j++)
			{
				if(a[i] == b[j])
				{
					int temp = b[j];
					b[j] = b[i];
					b[i] = temp;
					break;
				}
			}
		}
		if (j==n) {
			cout << "Impossible" << endl;
		} else {
			cout << "Possible" << endl;
		}
	}
	return 0;
}

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#define OUT "P15OUT.txt"
using namespace std;

int ugly(int n) {
	vector <int> u(n);
	u[0] = 1;
	int i2 = 0, i3 = 0, i5 = 0;
	for (int i = 1;i < n;i++) {
		u[i] = min({u[i2]*2, u[i3] * 3 , u[i5] * 5 });
		if (u[i] == u[i2] * 2) i2++;
		if (u[i] == u[i3] * 3) i3++;
		if (u[i] == u[i5] * 5) i5++;
	}
	return u[n-1];
}


int main() {
	//freopen(OUT, "r", stdout);

	printf("%d",ugly(1500));

	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
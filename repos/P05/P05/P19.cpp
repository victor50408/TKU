#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#define OUT "P15OUT.txt"
using namespace std;

bool is_ugly(int num) {
	while (num > 0) {
		if (num == 1) return true;

		if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
			if (num % 2 == 0) num = num / 2;
			if (num % 3 == 0) num = num / 3;
			if (num % 5 == 0) num = num / 5;
		}
		else return false;
	}
}



int main19() {
	//freopen(OUT, "r", stdout);

	int times = 0,num=1;
	while (times < 1500) {
		if (is_ugly(num++)) times++;
	}
	cout << num-1;


	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P08IN.txt"
#define OUT "P08OUT.txt"

int main8() {	//若有一樣出現次數:一樣
	freopen(IN, "r", stdin);
	//freopen(OUT, "w", stdout);
	string s1, s2;
	while (cin >> s1 >> s2) {
		int c1[26] = { 0 }, c2[26] = { 0 };
		for (int i = 0;i < s1.size();i++) {	//算ABC...各有多少個
			c1[s1[i] - 'A']++;
			c2[s2[i] - 'A']++;
		}
		sort(c1, c1+ 26);
		sort(c2, c2+ 26);
		bool same = true;
		for (int i = 0;i < 26;i++) {
			if(c1[i] != c2[i]) same = false;
		}
		printf("%s\n",same ? "YES":"NO");
	}


	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}

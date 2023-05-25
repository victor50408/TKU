#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P15IN.txt"
#define OUT "P15OUT.txt"
using namespace std;

int main15() {
	freopen(IN, "r", stdin);
	//freopen(OUT, "r", stdout);
	set <string> dict;
	string s1;
	while (cin >> s1) {
		string s2;
		for (char c : s1) if (isalpha(c)) s2 += tolower(c);
		dict.insert(s2);
	}

	for (string t : dict) {
		cout << t << endl;
	}
	
	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
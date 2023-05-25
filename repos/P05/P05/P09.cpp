#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P09IN.txt"
#define OUT "P09OUT.txt"
using namespace std;

void del_same(string *s) {
	char s_copy[26];
	int c1[26] = { 0 };
	int index = 0;
	for (int i = 0;i < (*s).size();i++) {
		if (c1[(*s)[i] - 'a'] == 0) s_copy[index++] = (*s)[i];
		c1[(*s)[i] - 'a']++;
	}
	s_copy[index] = '\0';
	*s = s_copy;
}


int main9() {
	freopen(IN,"r",stdin);
	//freopen(OUT, "r", stdout);
	int round;
	string ANS, s1;
	while (cin >> round && round != -1) {
		cin >> ANS >> s1;
		del_same(&ANS);
		del_same(&s1);
		//cout << ANS << s1 << endl;

		int win = 0, lose = 0;
		for (int i = 0;i < s1.size();i++) {
			bool same = false;
			for (int j = 0;j < ANS.size();j++) {
				if (s1[i] == ANS[j]) {
					same = true;
				}
			}
			if (same) win++;
			else lose++;
		}
		//cout << win << lose << endl;
		if (win == ANS.size()) cout << "WIN\n";
		else if (lose >= 7) cout << "LOSE\n";
		else cout << "You chicked out.\n";
	}

	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
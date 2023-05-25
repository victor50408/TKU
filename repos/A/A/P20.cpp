#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
#include <queue>

#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P20IN.txt"
#define OUT "P20OUT.txt"
using namespace std;

void P(string s,int len,char chara) {
	if(chara == '-') for (int i = 0;i < 60;i++) cout << chara;
	else {
		cout << s;
		for (int i = 0;i < len - s.size();i++) cout << chara;
	}
}


int main20() {
	freopen(IN, "r", stdin);
	//freopen(OUT, "w", stdout);

	int len,COL,ROW,max_len;
	vector <string> str;
	while (cin >> len) {
		max_len = 0;
		for (int i = 0;i < len;i++) {
			string s;
			cin >> s;
			str.push_back(s);
			//str[i] = s;
			max_len = max(max_len, (int)str[i].size());
		}
		sort(str.begin(), str.end());
		COL = (60 - max_len) / (max_len + 2) + 1;
		ROW = (int) ceil((double)len / COL);
		//cout << ROW << " " << COL << endl;
		//cout << max_len << " "<<len << endl;

		P(str[0],60,'-');
		cout << endl;

		for (int r = 0;r < ROW;r++) {
			for (int c = 0;c < COL;c++) {
				int index = r + ROW * c;
				//printf("%2d %2d %2d %2d ", r, c,index, str.size());
				if (index > str.size()-1) break;
				P(str[index], c == COL - 1 ? max_len : max_len + 2, ' ');
			}
			cout << endl;
		}
		str.clear();
	}


	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}

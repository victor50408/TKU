#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P13IN.txt"
#define OUT "P13OUT.txt"
using namespace std;




int main13() {
	freopen(IN, "r", stdin);
	//freopen(OUT, "r", stdout);
	int stone, Q, question,times=1;
	while (cin >> stone >> Q && stone != 0 && Q != 0) {
		printf("CASE #%d\n",times++);
		vector <int> st(stone);
		for (int i = 0;i < stone;i++) cin >> st[i];
		sort(st.begin(),st.end());

		for (int j = 0;j < Q;j++) {
			cin >> question;
			bool search = false;
			for (int i = 0;i < st.size();i++) {
				if (st[i] == question) {
					printf("%d found at %d\n", question, i+1);
					search = true;
					break;
				}
			}
			if (!search) printf("%d not found\n", question);
		}
	}



	freopen("CON", "r", stdin);
	freopen("CON", "w", stdout);
	return 0;
}
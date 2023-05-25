#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P05IN.txt"
#define OUT "P05OUT.txt"

using namespace std;

int main5()
{
    int len,game = 1;
    freopen(IN,"r",stdin);
    //freopen(OUT, "w", stdout);

    while (cin >> len && len != 0) {
        vector <int> ANS(len), INPUT(len);
        for (int i = 0;i < len;i++) cin >> ANS[i]; //讀答案
        printf("GAME %d\n", game++);

        while (1) {
            int A = 0, B = 0;
            for (int i = 0;i < len;i++) cin >> INPUT[i]; //讀輸入
            if (INPUT[0] == 0) break; //中止
            

            for (int i = 0;i < len;i++) { //A
                if (ANS[i] == INPUT[i]) A++;
            }
            
            for (int num = 1;num <= 9;num++) { //B
                int ansB = 0, inputB = 0;
                for (int i = 0;i < len;i++) {
                    if (ANS[i] == num) ansB++;
                    if (INPUT[i] == num) inputB++;
                }
                B = B + min(ansB, inputB);
            }
            B = B - A;
            printf("(%d, %d)\n",A,B);
        }
    }
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    return 0;
}


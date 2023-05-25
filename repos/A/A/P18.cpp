#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stdio.h>
#include <queue>

#define IN "C:\\Users\\lxu93\\source\\repos\\TEST_INPUT(TXT)\\P18IN.txt"
#define OUT "P18OUT.txt"
using namespace std;


int main18() {
    freopen(IN, "r", stdin);
    //freopen(OUT, "w", stdout);

    int num_teams, num_member,id,times=1;
    map <int, int> G; // id->team G[id]=隊伍
    while (cin >> num_teams && num_teams!=0) {
        cout << "Scenario #" << times++ << endl;
        for (int i = 0;i < num_teams;i++) {
            cin >> num_member;
            for (int j = 0;j < num_member;j++) {
                cin >> id;
                G[id] = i;
            }
        }
        queue <int> first_t;     //紀錄哪一隊先進(因為要先出)
        queue <int> long_t[1000];//紀錄總隊伍[隊伍]id...  ex[team0]: id1 id2 id3 ; [team1]: id4 id5 id6...
        string order;
        while (cin >> order) {       
            if (order == "ENQUEUE") {
                cin >> id;
                if (long_t[G[id]].empty()) first_t.push(G[id]);//如果你是你們隊伍第一個進來的 為自己隊伍創順序
                long_t[G[id]].push(id);//分配至自己的隊伍內            
            }
            if (order == "DEQUEUE") {
                cout << long_t[first_t.front()].front() << endl;//long_t[哪一隊先進].front() = 最先進的隊伍中最先進的第一個人
                long_t[first_t.front()].pop();//刪除此人
                if (long_t[first_t.front()].empty()) first_t.pop();//發現最先進的隊伍已沒人 刪除此隊伍(換下一隊伍)
            }
            if (order == "STOP") {
                cout << endl;
                break;
            }
        }
    }

    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    return 0;
}
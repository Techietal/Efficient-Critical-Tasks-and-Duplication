#include <bits/stdc++.h>
using namespace std;

int main(){
    map<int,string> m;
    m[1] = "cpop";
    m[2] = "heft";
    m[3] = "lstd";
    m[4] = "ippts";
    m[5] = "mpeft";
    m[6] = "new";
    m[7] = "peft";
    ofstream obj1;
    obj1.open("output.txt");
    for(int i = 1;i <= 7;i++){
        for(int j = i + 1;j <= 7;j++){
            ifstream ob1,ob2;
            int count = 0, eq = 0, be = 0, wo = 0;
                ob1.open(m[i] + ".txt");
                ob2.open(m[j] + ".txt");
                for(int x = 0;x < 48;x ++){
                    count++;
                    int a,b;
                    ob1 >> a;
                    ob2 >> b;
                    if(a == b) eq++;
                    else if(a < b) be++;
                    else wo++;
                }
                ob1.close();
                ob1.close();
            double equal = ((double )eq / count) * 100.0;
            double best = ((double )be / count) * 100.0;
            double worst = ((double )wo / count) * 100.0;
            cout << count << endl;
            obj1 << m[i] << " v/s " << m[j] << " : " << best << " " << worst << " " << equal << endl;
        }
    }
    obj1.close();
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> v = {"cpop","heft","ippts","lstd","mpeft","peft","new"};
    ifstream f,f1;
    fstream o;
    f1.open("1.txt");
    int p;
    f1 >> p;
    f1 >> p;
    f1.close();
    for(int j = 0;j < 7;j++){
    string s = v[j];
    f.open(s + ".txt");
    o.open("output.txt", ios::app);
    double sum = 0;
    for(int i = 0;i < 33;i++){
        int x;
        f >> x;
        sum += x;
    }
    o << s << " : ";
    sum = sum/(33 * p);
    o << sum << endl;
    f.close();
    o.close();
    }
}
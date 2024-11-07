#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream f;
    ofstream o;
    int h = 1;
    int tr = 2;
    int u = 1;
    while(tr <= 64){
    string s = to_string(h) + "_" + to_string(tr) + ".txt";
    f.open(s);
    int n,p;
    f >> n >> p;
    cout << n << " " << p << endl;
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < p;j++){
            double x;
            f >> x;
            cout << x << " ";
        }
        cout << endl;
    }
    vector<vector<int>> commc(n,vector<int> (n)), compc(n,vector<int> (p));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < p;j++){
            f >> compc[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            f >> commc[i][j];
        }
    }
    o.open(to_string(u) + ".txt");
    u++;
    o << n << " " << p << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < p;j++){
            o << compc[i][j] << " ";
        }
        o << endl;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            o << commc[i][j] << " ";
        }
        o << endl;
    }
    h++;
    if(h == 3) {
        h = 1;
        tr = tr * 2;
    }
    f.close();
    o.close();
    }
}
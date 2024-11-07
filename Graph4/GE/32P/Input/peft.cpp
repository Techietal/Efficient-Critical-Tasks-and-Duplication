#include <bits/stdc++.h>
using namespace std;

bool mycomp(pair<double,int> a, pair<double,int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void comp(int ind,vector<vector<int>> &oct, vector<vector<int>> compc,vector<vector<int>> commc, vector<int> &fin) {
    vector<int> ans(compc[0].size());
    for(int i = 0;i < compc[0].size();i ++) {
        int octi = 0;
        for(int j = 0;j < commc.size(); j++) {
            int yt = INT_MAX;
            if(commc[ind][j] != -1) {
                if(fin[j] == 0) {
                    comp(j,oct,compc,commc,fin);
                    fin[j] = 1;
                }
                if(fin[j] == 1) {
                    for(int k = 0;k < compc[0].size();k++) {
                        if(i != k) yt = min(yt , (oct[j][k] + compc[j][k] + commc[ind][j]));
                        else yt = min(yt, (oct[j][k] + compc[j][k]));
                    }
                }
                octi = max(octi,yt);
            }
        }
        ans[i] = octi;
    }
    oct[ind] = ans;
}

void findoct(vector<vector<int>> &oct, vector<vector<int>> compc, vector<vector<int>> commc,vector<int> &fin) {
    for(int i = 0;i < fin.size(); i++) {
        if(fin[i] == 0) {
            comp(i,oct,compc,commc,fin);
            fin[i] = 1;
        }
    }
}

void performp(vector<int> seq,vector<int> &avail, vector<vector<int>> commc, vector<vector<int>> compc,vector<vector<int>> &tasks, vector<vector<int>> oct) {
    for(int i = 0;i < seq.size();i++) {
        int eft = 0, oeft = 0, min_eft = INT_MAX, min_oeft = INT_MAX;
        int a1,a2,a3;
        for(int j = 0;j < avail.size() ;j++) {
            int est = 0;
            for(int k = 0;k < commc.size();k ++) {
                if(commc[k][seq[i] - 1] != -1) {
                    if(tasks[k][2] != j + 1) est = max(est, (tasks[k][1] + commc[k][seq[i] - 1]));
                    else est = max(est,tasks[k][1]);
                }
            }
            est = max(avail[j],est);
            eft = est + compc[seq[i] - 1][j];
            oeft = eft + oct[seq[i] - 1][j];
            if(oeft < min_oeft || (oeft == min_oeft && eft < min_eft)) {
                min_oeft = oeft;
                a1 = est;
                a2 = eft;
                a3 = j + 1;
                min_eft = eft;
            }
        }
        tasks[seq[i] - 1][0] = a1;
        tasks[seq[i] - 1][1] = a2;
        tasks[seq[i] - 1][2] = a3;
        avail[a3 - 1] = a2;
    }
}

int main() {
    ifstream f;
    ofstream o;
    int h = 1;
    o.open("peft.txt");
    while(h <= 8){
    f.open(to_string(h) + ".txt");
    int n,p;
    f >> n >> p;
    vector<vector<int>> compc(n, vector<int> (p));
    for(int i = 0;i < n;i ++) {
        for(int j = 0;j < p;j++) f >> compc[i][j];
    }
    vector<vector<int>> commc(n, vector<int> (n));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n; j++) f >> commc[i][j];
    }
    vector<vector<int>> oct(n, vector<int> (p, 0));
    vector<int> fin(n,0);
    for(int i = 0;i < n;i++) {
        int ty = *max_element(commc[i].begin(),commc[i].end());
        if(ty == -1) fin[i] = 1;
    }
    findoct(oct,compc,commc,fin);
    vector<double> rank(n);
    for(int i = 0;i < n;i ++) {
        int u = 0;
        for(int j = 0; j < p;j ++) u += oct[i][j] * 100;
        double y = (double ) u / p;
        y = round(y / 10.0);
        rank[i] = y / 10.0;
    }
    vector<pair<double,int>> pseq(n);
    for(int i = 0;i < n;i ++) {
        pseq[i] = pair<double,int> (rank[i], i + 1);
    }
    sort(pseq.begin(),pseq.end(),mycomp);
    vector<int> seq(n);
    for(int i = 0;i < n;i++) seq[i] = pseq[i].second;
    vector<vector<int>> tasks(n,vector<int> (3));
    vector<int> avail(p,0);
    performp(seq,avail,commc,compc,tasks,oct);
    int maxi = 0;
    // o << "Tasks\tST\tFT\tProc\n";
    for(int i = 0;i < n;i ++) {
        maxi = max(maxi, tasks[i][1]);
        // o << i + 1 << "\t" << tasks[i][0] << "\t" << tasks[i][1] << "\t" << tasks[i][2] << endl;
    }
    int fty = INT_MAX;
    for(int i = 0;i < p;i++){
        int ghj = 0;
        for(int j = 0;j < n;j++){
            ghj += compc[j][i];
        }
        fty = min(ghj,fty);
    }
    double speedup = (double ) fty / (double ) maxi;
    o << speedup << endl;
    cout << speedup << endl;
    f.close();
    h++;
    }
    o.close();
}
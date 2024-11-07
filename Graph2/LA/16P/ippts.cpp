#include <bits/stdc++.h>
using namespace std;

void calpcm(vector<vector<int>> &pcm,vector<vector<int>> &commc, vector<vector<int>> &compc, vector<int> &fin, int &ind){
    for(int i = 0;i < compc[0].size();i++){
        int maxi = 0;
       for(int j = 0;j < commc.size();j++){
            if(commc[ind][j] != -1){
                if(fin[j] == 0){
                    calpcm(pcm,commc,compc,fin,j);
                    fin[j] = 1;
                }
                int mini = INT_MAX;
                for(int k = 0;k < compc[0].size();k++){
                    if(i == k) mini = min(mini, (pcm[j][k] + compc[j][k] + compc[ind][k]));
                    else mini = min(mini,(pcm[j][k] + compc[j][k] + compc[ind][k] + commc[ind][j]));
                }
                maxi = max(mini,maxi);
            }
       }
       pcm[ind][i] = maxi;
    }
}

void getpcm(vector<vector<int>> &pcm,vector<vector<int>> &commc,vector<vector<int>> &compc,vector<int> &fin){
    for(int i = 0;i < fin.size();i++){
        if(fin[i] == 0){
            calpcm(pcm,commc,compc,fin,i);
            fin[i] = 1;
        }
    }
}

void performtask(vector<vector<int>> &task, vector<int> &seq,vector<int> &avail ,vector<vector<int>> &compc,vector<vector<int>> &commc,vector<vector<int>> &pcm){
    for(int i = 0;i < seq.size();i++){
        int lheadm = INT_MAX,eft = 0;
        for(int j = 0;j < avail.size();j++){
            int est = 0,lhet = 0,lhead = 0;
            for(int k = 0;k < commc.size();k++){
                if(commc[k][seq[i] - 1] != -1){
                    if(task[k][2] == j) est = max(est,task[k][1]);
                    else est = max(task[k][1] + commc[k][seq[i] - 1],est);
                }
            }
            est = max(est,avail[j]);
            eft = est + compc[seq[i] - 1][j];
            lhet = pcm[seq[i] - 1][j] - compc[seq[i] - 1][j];
            lhead = eft + lhet;
            if(lhead < lheadm){
                lheadm = lhead;
                task[seq[i] - 1][0] = est;
                task[seq[i] - 1][1] = eft;
                task[seq[i] - 1][2] = j;
            }
        }
        avail[task[seq[i] - 1][2]] = task[seq[i] - 1][1];
    }
}

int main(){
    ifstream f;
    ofstream o("ippts.txt");
    int h = 1;
    while(h <= 10){
    f.open(to_string(h) + ".txt");
    int n,p;
    f >> n >> p;
    vector<vector<int>> commc(n,vector<int> (n)), compc(n,vector<int> (p));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < p;j++) f >> compc[i][j];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) f >> commc[i][j];
    }
    vector<vector<int>> pcm(n,vector<int> (p));
    vector<int> fin(n,0);
    for(int i = 0;i < n;i++){
        if(*max_element(commc[i].begin(),commc[i].end()) == -1){
            for(int j = 0;j < p;j++){
                pcm[i][j] = compc[i][j];
            }
            fin[i] = 1;
        }
    }
    getpcm(pcm,commc,compc,fin);
    vector<int> out(n);
    for(int i = 0;i < n;i++){
        int count = 0;
        for(int j = 0;j < n;j++){
            if(commc[i][j]  != -1) count++;
        }
        out[i] = count;
    }
    vector<double> prank(n);
    for(int i = 0;i < n;i++){
        double k = 0;
        for(int j = 0;j < p;j++){
            k += pcm[i][j];
        }
        prank[i] = (k/p) * (out[i]);
    }
    priority_queue<pair<int,int>> pq;
    for(int i = 0;i < n;i++){
        pq.push({prank[i],-(i + 1)});
    }
    vector<int> seq(n);
    for(int i = 0;i < n;i++){
        int y = -(pq.top().second);
        seq[i] = y;
        pq.pop();
    }
    vector<vector<int>> task(n,vector<int> (3));
    vector<int> avail(p,0);
    performtask(task,seq,avail,compc,commc,pcm);
    int maxi = 0;
    // cout << "TASKS\tST\tFT\tPRO\n";
    for(int i = 0;i < n;i++){
        maxi = max(maxi,task[i][1]);
        // cout << i + 1 << "\t" << task[i][0] << "\t" << task[i][1] << "\t" << task[i][2] + 1 << endl;
    }
    o << maxi << endl;
    cout << maxi << endl;
    f.close();
    h++;
    }
    o.close();
}
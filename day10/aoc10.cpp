#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

void part1();
void part2();

using namespace std;

int main(){
    part2();
}

static vector<int> north = {-1,0};
static vector<int> south = {1,0};
static vector<int> east = {0,1};
static vector<int> west = {0,-1};

static vector<vector<int>> vD{north,south};// |
static vector<vector<int>> hD = {east,west};// -
static vector<vector<int>> lD{north,east};// L north and east
static vector<vector<int>> jD{north,west};// J north and west
static vector<vector<int>> sD{south,west};// 7 south and west
static vector<vector<int>> fD{south,east};// F south and east
static vector<vector<int>> start{north,south,east,west};

bool isCompatibile(char tile,int di,int dj){

    vector<vector<int>> dd;
    if (tile=='|'){
        dd = vD;
    }
    else if (tile=='-'){
        dd = hD;
    }
    else if (tile=='L'){
        dd = lD;
    }
    else if (tile=='J'){
        dd = jD;
    }
    else if (tile=='7'){
        dd = sD;
    }
    else if (tile=='F'){
        dd = fD;
    }else{
        // cout << tile << endl;
        // cout << "SOME ERROR" << endl;
        return false;
    }
    di*=-1;
    dj*=-1;
    for(vector<int> d: dd){
        if(di==d[0] && dj==d[1]){
            return true;
        }
    }
    return false;
}

vector<vector<int>> getNewCoordintates(vector<string>& map,vector<vector<bool>>& visited,vector<vector<int>>& directions,int i,int j){
    vector<vector<int>> newCoordinates;


    return newCoordinates;
}

void part1(){
    fstream file("aoc10.txt");

    vector<string> map;
    string line;

    while (getline(file,line)){
        map.push_back(line);
    }
    int si;
    int sj;
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            if(map[i][j]=='S'){
                si = i;
                sj = j;
            }
        }
    }

    int distance[map.size()][map[0].size()];


    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            distance[i][j] = 0;
        }
    }
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));

    queue<vector<int>> q;
    vector<int> initP{si,sj};
    int maxD = 0;
    q.push(initP);

    while (!q.empty()){
        vector<int> currp = q.front();
        q.pop();
        int curri = currp[0];
        int currj = currp[1];

        char currChar = map[curri][currj];
        int currD = distance[curri][currj];
        maxD = max(currD,maxD);

        visited[curri][currj] = true;

        vector<vector<int>> dd;

        if (currChar=='|'){
            dd = vD;
        }
        else if (currChar=='-'){
            dd = hD;
        }
        else if (currChar=='L'){
            dd = lD;
        }
        else if (currChar=='J'){
            dd = jD;
        }
        else if (currChar=='7'){
            dd = sD;
        }
        else if (currChar=='F'){
            dd = fD;
        }else if(currChar=='S'){
            dd = start;
        }else{
            cout << "Some error" << endl;
        }

        for(vector<int> d:dd){
            int newi = curri + d[0];
            int newj = currj + d[1];
            
            if (newi>=0 && newi<map.size() && newj>=0 && newj<map[0].size() && !visited[newi][newj] && isCompatibile(map[newi][newj],d[0],d[1])){
                q.push(vector<int>{newi,newj});
                distance[newi][newj] = 1 + currD;
            }
        }
    }
 
    // for(int i=0;i<map.size();i++){
    //     for(int j=0;j<map[0].size();j++){
    //         cout << distance[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << maxD << endl;
}


void part2(){
    fstream file("aoc10.txt");

    vector<string> map;
    string line;

    while (getline(file,line)){
        map.push_back(line);
    }
    int si;
    int sj;
    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            if(map[i][j]=='S'){
                si = i;
                sj = j;
            }
        }
    }

    int distance[map.size()][map[0].size()];


    for(int i=0;i<map.size();i++){
        for(int j=0;j<map[0].size();j++){
            distance[i][j] = 0;
        }
    }
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));

    queue<vector<int>> q;
    vector<int> initP{si,sj};
    q.push(initP);

    while (!q.empty()){
        vector<int> currp = q.front();
        q.pop();
        int curri = currp[0];
        int currj = currp[1];

        char currChar = map[curri][currj];
        int currD = distance[curri][currj];
        
        visited[curri][currj] = true;

        vector<vector<int>> dd;

        if (currChar=='|'){
            dd = vD;
        }
        else if (currChar=='-'){
            dd = hD;
        }
        else if (currChar=='L'){
            dd = lD;
        }
        else if (currChar=='J'){
            dd = jD;
        }
        else if (currChar=='7'){
            dd = sD;
        }
        else if (currChar=='F'){
            dd = fD;
        }else if(currChar=='S'){
            dd = start;
        }else{
            cout << "Some error" << endl;
        }

        for(vector<int> d:dd){
            int newi = curri + d[0];
            int newj = currj + d[1];
            
            if (newi>=0 && newi<map.size() && newj>=0 && newj<map[0].size() && !visited[newi][newj] && isCompatibile(map[newi][newj],d[0],d[1])){
                q.push(vector<int>{newi,newj});
            }
        }
    }
    int total = 0;
    for(int i=0;i<map.size();i++){
        bool isInside = false;
        char corner;
        for(int j=0;j<map[0].size();j++){
            
            if(visited[i][j]){
                if (map[i][j]=='|'){
                    isInside = !isInside;
                }else if(map[i][j]=='L'||map[i][j] =='F'){
                    corner = map[i][j];
                }else if (map[i][j]=='7' && corner=='L'){
                    isInside = !isInside;
                }else if (map[i][j]=='J' && corner=='F'){
                    isInside = !isInside;
                }
            }else if (isInside){
               
                total++;
            }

            
        }
    //    cout << endl;
    }
    cout << total << endl;
}
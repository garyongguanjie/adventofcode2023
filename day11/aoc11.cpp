#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

using namespace std;

using ll = long long;

void part1();
void part2();

int main(){
    part2();
}

void part1(){
    fstream file("aoc11.txt");
    string line;

    vector<string> map;

    while(getline(file,line)){
        map.push_back(line);
    }
    vector<int> rows(map.size(),0);
    vector<int> cols(map[0].size(),0);
    int c = 0;
    for (int i=0;i<map.size();i++){
        bool isBlank = true;
        
        for(int j=0;j<map.size();j++){
            if (map[i][j]!='.'){
                isBlank = false;
                break;
            }
        }
        if(isBlank){
            c++;
        }
        rows[i] = c;
        // cout << c ;
    }
    c=0;
    for (int j=0;j<map[0].size();j++){
        bool isBlank = true;
        
        for(int i=0;i<map.size();i++){
            if (map[i][j]!='.'){
                isBlank = false;
                break;
            }
        }
        if(isBlank){
            c++;
        }
        cols[j] = c;
    }

    vector<vector<int>> galaxyMap;

    for (int i=0;i<map.size();i++){
        for(int j=0;j<map.size();j++){
            if (map[i][j]=='#')galaxyMap.push_back(vector<int>{i+rows[i],j+cols[j]});
        }
    }


    int total = 0;
    for(int i=0;i<galaxyMap.size()-1;i++){
        for(int j=i+1;j<galaxyMap.size();j++){
            vector<int> galaxy1 = galaxyMap[i];
            vector<int> galaxy2 = galaxyMap[j];

            int d = abs(galaxy1[0]-galaxy2[0]) + abs(galaxy1[1]-galaxy2[1]);
            // if (i==4 &&j==8){
            //     cout << galaxy1[0] << "," << galaxy1[1] << endl;
            //     cout << galaxy2[0] << "," << galaxy2[1] << endl;
            //     cout << d << endl;
            // }
            
            total +=d;
        }
    }

    cout << total << endl;

}

void part2(){
    fstream file("aoc11.txt");
    string line;

    vector<string> map;

    while(getline(file,line)){
        map.push_back(line);
    }
    vector<ll> rows(map.size(),0);
    vector<ll> cols(map[0].size(),0);
    int c = 0;
    for (int i=0;i<map.size();i++){
        bool isBlank = true;
        
        for(int j=0;j<map.size();j++){
            if (map[i][j]!='.'){
                isBlank = false;
                break;
            }
        }
        if(isBlank){
            c+=999999;
        }
        rows[i] = c;
        // cout << c ;
    }
    c=0;
    for (int j=0;j<map[0].size();j++){
        bool isBlank = true;
        
        for(int i=0;i<map.size();i++){
            if (map[i][j]!='.'){
                isBlank = false;
                break;
            }
        }
        if(isBlank){
            c+=999999;
        }
        cols[j] = c;
    }

    vector<vector<ll>> galaxyMap;

    for (ll i=0;i<map.size();i++){
        for(ll j=0;j<map.size();j++){
            if (map[i][j]=='#')galaxyMap.push_back(vector<ll>{i+rows[i],j+cols[j]});
        }
    }


    ll total = 0;
    for(int i=0;i<galaxyMap.size()-1;i++){
        for(int j=i+1;j<galaxyMap.size();j++){
            vector<ll> galaxy1 = galaxyMap[i];
            vector<ll> galaxy2 = galaxyMap[j];

            ll d = abs(galaxy1[0]-galaxy2[0]) + abs(galaxy1[1]-galaxy2[1]);
            // if (i==4 &&j==8){
            //     cout << galaxy1[0] << "," << galaxy1[1] << endl;
            //     cout << galaxy2[0] << "," << galaxy2[1] << endl;
            //     cout << d << endl;
            // }
            
            total +=d;
            // cout << total << endl;
        }
    }

    cout << total << endl;

}
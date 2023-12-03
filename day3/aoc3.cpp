#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool calculateAdj(int (&directions)[][2],int rows,int i,int j,vector<string> &stringArray){
    for(int r=0;r<rows;r++){
        int di = directions[r][0];
        int dj = directions[r][1];
        // cout << di << " " << dj << endl;

        int newi = i+di;
        int newj = j+dj;

        if (newi<stringArray.size() && newi>=0 && newj<stringArray[0].size() && newj>=0){
            char c = stringArray[newi][newj];
            if (!isdigit(c) && c!='.'){
                return true;
            }
        }
    }
    return false;
}

void part1(){
    fstream file("aoc3.txt");
    string line;
    
    vector<string> stringArray;

    int directions[8][2] = {
        {1,0},
        {0,1},
        {-1,0},
        {0,-1},
        {1,1},
        {-1,-1},
        {1,-1},
        {-1,1}
    };

    while (getline(file,line)){
        stringArray.push_back(line);
    }
    bool isAdjacent = false;
    string currNum = "";
    int totalSum = 0;
    for(int i=0;i<stringArray.size();i++){
        for(int j=0;j<stringArray[0].size();j++){
            char currChar = stringArray[i][j];
            if (isdigit(currChar)){
                isAdjacent = isAdjacent || calculateAdj(directions,8,i,j,stringArray);
                currNum += currChar;
            }
            //if we reach end of the array or we reach a non digit character
            if (!isdigit(currChar) || j==stringArray[0].size()-1){
                if (isAdjacent){
                    totalSum+= stoi(currNum);
                }
                isAdjacent = false;
                currNum = "";
            }
        }
    }

    cout << totalSum << endl;
}



int getProduct(vector<string> &stringArray,int i,int j){
    int count = 0;
    int product = 1;
    int visited[3][3] = {0};
    visited[1][1] = 1;

    for(int di=-1;di<=1;di++){
        for(int dj=-1;dj<=1;dj++){
            if((di==0&&dj==0)||count>2)continue;
            int newi = i+di;
            int newj = j+dj;
            if (newi<stringArray.size() && newi>=0 && newj<stringArray[0].size() && newj>=0){
                char c = stringArray[newi][newj];
                if (isdigit(c) && !visited[di+1][dj+1]){
                    count++;
                    visited[di+1][dj+1] = 1;

                    int l = newj;
                    int r = newj;

                    while (l-1>=0 && isdigit(stringArray[newi][l-1])){
                        l--;
                        int lRelative = dj+1+(l-newj);
                        if (lRelative>=0)visited[di+1][lRelative] = 1;
                    }
                    while (r+1<stringArray[0].size() && isdigit(stringArray[newi][r+1])){
                        r++;
                        int rRelative = dj+1+(r-newj);
                        if (rRelative<=2)visited[di+1][rRelative] = 1;
                    }

                    string numString="";

                    while(l<=r){
                        numString += stringArray[newi][l];
                        l++;
                    }
                    
                    product *= stoi(numString);
                }
            }
        }
    }
    // cout << "Count: " << count << " Product: " << product << endl;
    if (count!=2){
        return 0;
    }
    else{
        return product;
    }
}

void part2(){
    fstream file("aoc3.txt");
    string line;
    
    vector<string> stringArray;

    while (getline(file,line)){
        stringArray.push_back(line);
    }

    string currNum = "";
    int totalSum = 0;
    for(int i=0;i<stringArray.size();i++){
        for(int j=0;j<stringArray[0].size();j++){
            char currChar = stringArray[i][j];
            if (currChar=='*'){
                totalSum += getProduct(stringArray,i,j);
            }
        }
    }
    cout << "Total sum is: " << totalSum << endl;
}

int main(){
    part2();
}
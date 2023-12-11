#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void part1();
void part2();

int main(){
    part2();
}

bool isAllZeros(vector<int>& numbers){
    for(int c: numbers){
        if (c!=0){
            return false;
        }
    }
    return true;
}

void part1(){
    int size = 21;
    fstream file("aoc9.txt");
    string line;
    int total = 0;
    while(getline(file,line)){
        vector<int> numbers;
        istringstream iss(line);
        for(int i=0;i<size;i++){
            int a;
            iss >> a;
            numbers.push_back(a);
        }

        vector<vector<int>> numbersList;
        numbersList.push_back(numbers);
        
        while(!isAllZeros(numbersList[numbersList.size()-1])){
            vector<int> newNumbersList;
            vector<int> currList = numbersList[numbersList.size()-1];
            for(int i=1;i<currList.size();i++){
                newNumbersList.push_back(currList[i]-currList[i-1]);
                // cout << currList[i]-currList[i-1] << endl;
            }
            numbersList.push_back(newNumbersList);
        }

        int diff = 0;
        for(int i=numbersList.size()-1;i>=0;i--){
            vector<int> currList = numbersList[i];
            diff += currList[currList.size()-1];
        }

        total += diff;
    }
    cout << total << endl;
}


void part2(){
    int size = 21;
    fstream file("aoc9.txt");
    string line;
    int total = 0;
    while(getline(file,line)){
        vector<int> numbers;
        istringstream iss(line);
        for(int i=0;i<size;i++){
            int a;
            iss >> a;
            numbers.push_back(a);
        }

        vector<vector<int>> numbersList;
        numbersList.push_back(numbers);
        
        while(!isAllZeros(numbersList[numbersList.size()-1])){
            vector<int> newNumbersList;
            vector<int> currList = numbersList[numbersList.size()-1];
            for(int i=1;i<currList.size();i++){
                newNumbersList.push_back(currList[i]-currList[i-1]);
                // cout << currList[i]-currList[i-1] << endl;
            }
            numbersList.push_back(newNumbersList);
        }

        int diff = 0;
        for(int i=numbersList.size()-1;i>=0;i--){
            vector<int> currList = numbersList[i];
            diff = currList[0] - diff;
        }
        // cout << "TEST"<< diff << endl;
        total += diff;
    }
    cout << total << endl;
}
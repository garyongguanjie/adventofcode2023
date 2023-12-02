#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>


using namespace std;

void part1();
void part2();
vector<string>* split(string str,string delimiter);

int main(){
    part2();
}

string extractNumber(string s){
    regex regexp("\\d+"); 
    smatch m; 
    regex_search(s, m, regexp);
    return m[0];
}

vector<string>* split(string str,string delimiter){
    vector<string>* stringlist = new vector<string>;
    int start = 0;
    int pos = str.find(delimiter, 0);
    while(pos != string::npos)
    {
        if(start!=pos){
            stringlist->push_back(str.substr(start,pos-start));
        }
        start = pos+1;
        pos = str.find(delimiter,start);
    }
    if(start!=str.length()-1){
        stringlist->push_back(str.substr(start,str.length()));
    }
    return stringlist;
}

void part1(){
    fstream file("aoc2.txt");
    string line;
    int sumIds = 0;
    while (getline(file,line)){
        vector<string>* stringListP = split(line,":");
        vector<string> stringList = *stringListP;
        int gameNumber = stoi(extractNumber(stringList[0]));
        vector<string>* gameListP = split(stringList[1],";");
        vector<string> gameList = *gameListP;
        bool isBroken = false;
        for (string s: gameList){
            int totalRed = 12;
            int totalGreen = 13;
            int totalBlue = 14;
            for (string colorString: *split(s,",")){
                if(colorString.find("green")!=string::npos){
                    int greenNum = stoi(extractNumber(colorString));
                    totalGreen -= greenNum;
                }
                if(colorString.find("red")!=string::npos){
                    int redNum = stoi(extractNumber(colorString));
                    totalRed -= redNum;
                }
                if(colorString.find("blue")!=string::npos){
                    int blueNum = stoi(extractNumber(colorString));   
                    totalBlue -= blueNum;
                }
            }
            if (totalGreen<0 || totalRed<0 || totalBlue<0){
                isBroken = true;
                break;
            }
        }
        if (!isBroken){
            // cout << gameNumber << endl;
            sumIds += gameNumber;
        }
    }
    cout << sumIds << endl;
    file.close();
}

void part2(){
    fstream file("aoc2.txt");
    string line;
    int sumTotal = 0;


    while (getline(file,line)){
        vector<string>* stringListP = split(line,":");
        vector<string> stringList = *stringListP;
        vector<string>* gameListP = split(stringList[1],";");
        vector<string> gameList = *gameListP;
        int minRed = 0;
        int minBlue = 0;
        int minGreen = 0;
        for (string s: gameList){
            for (string colorString: *split(s,",")){
                if(colorString.find("green")!=string::npos){
                    int greenNum = stoi(extractNumber(colorString));
                    minGreen = max(greenNum,minGreen);
                }
                if(colorString.find("red")!=string::npos){
                    int redNum = stoi(extractNumber(colorString));
                    minRed = max(redNum,minRed);
                }
                if(colorString.find("blue")!=string::npos){
                    int blueNum = stoi(extractNumber(colorString));
                    minBlue = max(blueNum,minBlue);
                }
            }
        }
        // cout << minRed * minBlue * minGreen<< endl;
        sumTotal += minRed * minBlue * minGreen;
    }
    cout << sumTotal << endl;
    file.close();
}
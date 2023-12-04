#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <regex>

using namespace std;

void part1();
void part2();
vector<string>* split(string str,string delimiter);

int main(){
    // part1();
    part2();
}


void part1(){
    fstream file("aoc4.txt");
    string line;
    int totalPoints = 0;
    while (getline(file,line)){
        vector<string> numberString = (*split((*split(line,":"))[1],"|"));

        string winningNumberString = numberString[0];
        string myNumberString = numberString[1];
        // cout << winningNumberString << endl;
        // cout << myNumberString << endl;

        unordered_set<int> winningNumberSet;

        for(string s:*split(winningNumberString," ")){
            if (s!=""){
                // cout << stoi(s) << " ";
                winningNumberSet.insert(stoi(s));
            }
            
        }
        // cout << endl;
        int currPoints = 0;        
        for(string s:*split(myNumberString," ")){
            // cout << s << " ";
            if (s!=""){
                
                if (winningNumberSet.find(stoi(s))!=winningNumberSet.end()){
                    if (currPoints==0){
                        currPoints=1;
                    }else{
                        currPoints*=2;
                    }
                }

            }
            
        }
        totalPoints += currPoints;
        // cout << "currPoint: " << currPoints << endl;
    }
    cout << totalPoints << endl;
    file.close();
}


void part2(){
    fstream file("aoc4.txt");
    string line;
    int gameNumber = 1;
    int totalCards = 0;
    unordered_map<int,int> cardCount;
    while (getline(file,line)){
        vector<string> numberString = (*split((*split(line,":"))[1],"|"));

        string winningNumberString = numberString[0];
        string myNumberString = numberString[1];
        // cout << winningNumberString << endl;
        // cout << myNumberString << endl;

        unordered_set<int> winningNumberSet;

        for(string s:*split(winningNumberString," ")){
            if (s!=""){
                // cout << stoi(s) << " ";
                winningNumberSet.insert(stoi(s));
            }
            
        }
        // cout << endl;
        int numMatches = 0;        
        for(string s:*split(myNumberString," ")){
            // cout << s << " ";
            if (s!=""){
                if (winningNumberSet.find(stoi(s))!=winningNumberSet.end()){
                    numMatches++;
                }
            }
        }
        cardCount[gameNumber] +=1;
        
        for(int i=1;i<=numMatches;i++){
            int gn = gameNumber + i;
            cardCount[gn]+= cardCount[gameNumber];  
        }

        cout << "game: "<< gameNumber << " Count: "<< cardCount[gameNumber]<< endl;
        totalCards += cardCount[gameNumber];
        gameNumber++;
    }
    file.close();
    cout << totalCards << endl;
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
    if(start!=str.length()){
        stringlist->push_back(str.substr(start,str.length()));
    }
    return stringlist;
}

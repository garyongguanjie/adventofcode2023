#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 
#include <algorithm>

void part1();
void part2();

using namespace std;
using ll = long long;

int main(){
    part2();
}

struct Hb{
    string hand;
    ll bid;
};

int getValue(char c){
    if (isdigit(c)){
        return c-'2';
    }else if (c=='T'){
        return 8;
    }else if (c=='J'){
        return 9;
    }else if (c=='Q'){
        return 10;
    }else if (c=='K'){
        return 11;
    }else if (c=='A'){
        return 12;
    }else{
        cout << "UH OH BUG" << endl;
        return 13;
    }
}

int getType(string hand){
    int countArray[13] = {0};
    for (char c:hand){
        countArray[getValue(c)]++;
    }

    // get two highest values
    int a = 0;
    int b = 0;

    for (int i=0;i<13;i++){
        int c = countArray[i];

        if (c>a && c>b){
            b = a;
            a = c;
        }else if (c>b){
            b = c;
        }
    }

    if(a>=4){
        return a+1;
    }else if (a==3){
        return b+2;
    }else if (a==2){
        return b;
    }else{
        return 0;
    }

}

bool compareHb(const Hb& a, const Hb& b){
    int atype = getType(a.hand);
    int btype = getType(b.hand);

    if (atype!=btype){
        return atype<btype;
    }
    for(int i=0;i<5;i++){
        char ca = a.hand[i];
        char cb = b.hand[i];
        
        int va = getValue(ca);
        int vb = getValue(cb);

        if (va!=vb){
            return va<vb;
        }
    }
    return true;
}


int getJtype(string hand){
    int maxType = getType(hand);
    string all = "23456789TJQKA";
    for (char c:all){
        string temp = hand;
        for (int i=0;i<5;i++){
            if (hand[i]=='J'){
                temp[i] = c;
            }
        }
        maxType = max(maxType,getType(temp));
    }
    return maxType;
}

int getValue2(char c){
    if (isdigit(c)){
        return c-'2';
    }else if (c=='T'){
        return 8;
    }else if (c=='J'){
        return -1;
    }else if (c=='Q'){
        return 10;
    }else if (c=='K'){
        return 11;
    }else if (c=='A'){
        return 12;
    }else{
        cout << "UH OH BUG" << endl;
        return 13;
    }
}

bool compareHb2(const Hb& a, const Hb& b){

    int atype = getJtype(a.hand);
    int btype = getJtype(b.hand);


    if (atype!=btype){
        return atype<btype;
    }
    for(int i=0;i<5;i++){
        char ca = a.hand[i];
        char cb = b.hand[i];
        
        int va = getValue2(ca);
        int vb = getValue2(cb);

        if (va!=vb){
            return va<vb;
        }
    }
    return true;
}

void part1(){
    fstream file("aoc7.txt");
    string line;

    vector<Hb> handbids;

    while (getline(file,line)){
        std::istringstream iss(line);
        Hb hb;
        iss >> hb.hand >> hb.bid;
        handbids.push_back(hb);
    }

    sort(handbids.begin(),handbids.end(),compareHb);

    for(Hb hb:handbids){
        cout << hb.hand << " " << hb.bid << endl;
    }
    ll score = 0;
    for (int i=0;i<handbids.size();i++){
        score += handbids[i].bid*(i+1);
        // cout << score << endl;
    }
    cout << score << endl;
}

void part2(){
    fstream file("aoc7.txt");
    string line;

    vector<Hb> handbids;

    while (getline(file,line)){
        std::istringstream iss(line);
        Hb hb;
        iss >> hb.hand >> hb.bid;
        handbids.push_back(hb);
    }

    sort(handbids.begin(),handbids.end(),compareHb2);

    for(Hb hb:handbids){
        cout << hb.hand << " " << hb.bid << endl;
    }
    ll score = 0;
    for (int i=0;i<handbids.size();i++){
        score += handbids[i].bid*(i+1);
        // cout << score << endl;
    }
    cout << score << endl;
}
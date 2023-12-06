#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;


void part1();
void part2();

int main(){
    // part1();
    part2();
}

void part1(){
    fstream file("aoc6.txt");
    string line;

    vector<string> stringLines;

    string temp;
    int time1;
    int time2;
    int time3;
    int time4;

    int distance1;
    int distance2;
    int distance3;
    int distance4;

    // file >> time1 >> time2 >> time3 >> distance1 >> distance2 >> distance3;
    // cout << "H" << endl;
    // cout << time1 << endl;
    file >> temp;
    file >> time1;
    file >> time2;
    file >> time3;
    file >> time4;

    file >> temp;
    file >> distance1;
    file >> distance2;
    file >> distance3;
    file >> distance4;

    int time[] = {time1,time2,time3,time4};
    int distance[] = {distance1,distance2,distance3,distance4}; 
    int total = 1;
    for(int i=0;i<4;i++){
        int t = time[i];
        int d = distance[i];
        int currCount = 0;
        cout << t << " " << d << endl;
        for(int s=1;s<=t;s++){
            int distanceCovered =  s*(t-s);
            
            if (distanceCovered>d){
                currCount +=1;
            }
            
        }
        // cout << currCount << endl;
        total *= max(currCount,1);
    }
    cout << total << endl;
    file.close();
};


void part2(){
    ll t = 49979494;
    ll d = 263153213781851;

    /**
     * s is the charging time or speed
     * s*(t-s)>d
     * st-s^2-d>0
     * s^2-st+d>0
     * apply quadratic formula to solve for s
     * b=-t
     * a=1
     * c=d
     * 
    */
    
    ll b = -t;
    ll a = 1;
    ll c = d;

    ll root1 = (-b+sqrt(b*b-4*a*c))/(2*a);
    ll root2 = (-b-sqrt(b*b-4*a*c))/(2*a);

    cout << root1 -root2<< endl;
    // cout << root2 << endl;

    

}
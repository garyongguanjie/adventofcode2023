#include <iostream>
#include <fstream>

using namespace std;

void part1();
void part2();

int main(){
    // part1();
    part2();
}


void part2(){
    fstream file("aoc1.txt");
    string line;

    string firstDigit;

    string lastDigit;

    int s = 0;

    string numberArray[] = {"one","two","three","four","five","six","seven","eight","nine"};

    while (getline(file,line)){
        int firstIndex = line.length();
        int lastIndex = -1;
        for(int i=0;i<line.length();i++){
            if(isdigit(line[i])){
                firstDigit = line[i];
                firstIndex = i;   
                break;
            }
        }

        for (int i=0;i<9;i++){
            string numString = numberArray[i];
            int pos  = line.find(numString);

            if (pos!=string::npos && (pos<firstIndex)){
                firstIndex = pos;
                firstDigit = to_string(i+1);
            }
        }

        for(int i=line.length()-1;i>=0;i--){
            if(isdigit(line[i])){
                lastDigit = line[i];
                lastIndex = i;
                break;
            }
        }

        for (int i=0;i<9;i++){
            string numString = numberArray[i];
            int pos  = line.rfind(numString);
            
            if (pos!=string::npos && (pos>lastIndex)){
                lastIndex = pos;
                lastDigit = to_string(i+1);
            }
        }

        // cout << stoi(firstDigit+lastDigit) << endl;

        s+= stoi(firstDigit+lastDigit);
    }
    cout << s << endl;
    file.close();
}

void part1(){
    fstream file("aoc1.txt");
    string line;
    string firstDigit;
    string lastDigit;
    int s = 0;
    while (getline(file,line)){
        for(int i=0;i<line.length();i++){
            if(isdigit(line[i])){
                firstDigit = line[i];
                break;
            }
        }

        for(int i=line.length()-1;i>=0;i--){
            if(isdigit(line[i])){
                lastDigit = line[i];
                break;
            }
        }
        s+= stoi(firstDigit+lastDigit);
    }
    cout << s << endl;
    file.close();
}
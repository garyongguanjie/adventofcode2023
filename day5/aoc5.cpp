#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using ll = long long;

using namespace std;

void part1();
void part2();
vector<string>* split(string str,string delimiter);

int main(){
    part2();
}

vector<long long>* getSeeds(vector<string>& stringLines){
    vector<long long>* seedVector = new vector<long long>;
    for (string s:*split((*split(stringLines[0],":"))[1]," ")){
        seedVector->push_back(stoll(s));
        // cout << s << endl;
    }
    return seedVector;
}

vector<vector<long long>>* getMap(string mapType,vector<string>& stringLines){
    vector<vector<long long>>* mapVector = new vector<vector<long long>>;
    bool inMap = false;
    for(long long i=0;i<stringLines.size();i++){
        if (inMap){
            if (stringLines[i].size()==0){
                break;
            }
            vector<string> numStrings = *split(stringLines[i]," ");
            // cout << numStrings[0] << " "  << numStrings[1] << " " << numStrings[2] <<endl;
            vector<long long>* arr = new vector<long long>{stoll(numStrings[0]),stoll(numStrings[1]),stoll(numStrings[2])};
            
            mapVector->push_back(*arr);
        }
        if(stringLines[i].find(mapType)!=string::npos){
            // cout << stringLines[i] << endl;
            inMap = true;
        }
    }
    return mapVector;
}

long long getDestination(vector<vector<long long>>& map,long long source){
    for (long long i=0;i< map.size();i++){
        ll s = map[i][1];
        ll d = map[i][0];
        ll r = map[i][2];

        ll end = s + r - 1;
        if(source>=s && source<=end){
            return d + source - s;
        }
    }
    return source;
}

vector<vector<long long>>* getDestinations(vector<vector<long long>>& map,vector<vector<long long>>& inputRanges){
    // Referred from implementation https://github.com/jonathanpaulson/AdventOfCode/blob/master/2023/5.py
    vector<vector<long long>>* outputRanges = new vector<vector<long long>>;

    for (vector<ll>m: map){
        ll s = m[1];
        ll d = m[0];
        ll r = m[2];
        ll e = s + r;
        vector<vector<ll>> newInputRange; 
        while(inputRanges.size()>0){
            vector<ll> ir = inputRanges.back();
            ll sir = ir[0];
            ll eir = ir[1];
            inputRanges.pop_back();

            vector<ll> before = *(new vector<ll>{sir,min(eir,s)});
            vector<ll> intersect = *(new vector<ll>{max(sir,s),min(eir,e)});
            vector<ll> after = *(new vector<ll>{max(e,sir),eir});

            if (before[0]<before[1]){
                newInputRange.push_back(before);
            }
            if (intersect[0]<intersect[1]){
                outputRanges->push_back(*(new vector<ll>{intersect[0]-s+d,intersect[1]-s+d}));
            }
            if (after[0]<after[1]){
                newInputRange.push_back(after);
            }
        }
        inputRanges = newInputRange;
    }

    for (vector<ll> r:inputRanges){
        outputRanges->push_back(r);
    }
    return outputRanges;
}

void printRanges(vector<vector<long long>>& ranges){
    for(vector<long long> r: ranges){
        cout << r[0] << "," << r[1] << endl;
    }
}

void part2(){
    fstream file("aoc5.txt");
    string line;

    vector<string> stringLines;

    while(getline(file,line)){
        stringLines.push_back(line);
    }

    vector<long long> seedVector = *getSeeds(stringLines);
    vector<vector<long long>> seedToSoilMap = *getMap("seed-to-soil map",stringLines);
    vector<vector<long long>> soilToFertilizerMap = *getMap("soil-to-fertilizer map",stringLines);
    vector<vector<long long>> fertilizerToWaterMap = *getMap("fertilizer-to-water map",stringLines);
    vector<vector<long long>> waterToLightMap = *getMap("water-to-light map",stringLines);
    vector<vector<long long>> lightToTemperatureMap = *getMap("light-to-temperature map",stringLines);
    vector<vector<long long>> temperatureToHumidityMap = *getMap("temperature-to-humidity map",stringLines);
    vector<vector<long long>> humidityToLocationMap = *getMap("humidity-to-location map",stringLines);

    long long minLocation = LONG_LONG_MAX;
    long long d;

    for (int i = 0;i<seedVector.size();i+=2){

        long long start = seedVector[i];
        long long end = seedVector[i] + seedVector[i+1];

        vector<vector<long long>> outputRanges;
        outputRanges.push_back({start,end});
        outputRanges = *getDestinations(seedToSoilMap,outputRanges);
        outputRanges = *getDestinations(soilToFertilizerMap,outputRanges);
        outputRanges = *getDestinations(fertilizerToWaterMap,outputRanges);
        outputRanges = *getDestinations(waterToLightMap,outputRanges);
        outputRanges = *getDestinations(lightToTemperatureMap,outputRanges);
        outputRanges = *getDestinations(temperatureToHumidityMap,outputRanges);
        outputRanges = *getDestinations(humidityToLocationMap,outputRanges);
    
        for(vector<long long> r:outputRanges){
            // cout << r[0] << endl;
            if (r[0]>0)minLocation = min(minLocation,r[0]);
        }


    }
    cout << minLocation << endl;
}

void part1(){
    fstream file("aoc5.txt");
    string line;

    vector<string> stringLines;

    while(getline(file,line)){
        stringLines.push_back(line);
    }

    vector<long long> seedVector = *getSeeds(stringLines);
    vector<vector<long long>> seedToSoilMap = *getMap("seed-to-soil map",stringLines);
    vector<vector<long long>> soilToFertilizerMap = *getMap("soil-to-fertilizer map",stringLines);
    vector<vector<long long>> fertilizerToWaterMap = *getMap("fertilizer-to-water map",stringLines);
    vector<vector<long long>> waterToLightMap = *getMap("water-to-light map",stringLines);
    vector<vector<long long>> lightToTemperatureMap = *getMap("light-to-temperature map",stringLines);
    vector<vector<long long>> temperatureToHumidityMap = *getMap("temperature-to-humidity map",stringLines);
    vector<vector<long long>> humidityToLocationMap = *getMap("humidity-to-location map",stringLines);

    long long minLocation = LONG_LONG_MAX;
    long long d;
    for (int s:seedVector){
        d = getDestination(seedToSoilMap,s);
        d = getDestination(soilToFertilizerMap,d);
        d = getDestination(fertilizerToWaterMap,d);
        d = getDestination(waterToLightMap,d);
        d = getDestination(lightToTemperatureMap,d);
        d = getDestination(temperatureToHumidityMap,d);
        d = getDestination(humidityToLocationMap,d);

        cout << d << endl;
        if (d>=0)minLocation = min(d,minLocation);
    }
    cout << minLocation << endl;
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
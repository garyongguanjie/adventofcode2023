#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <numeric>

using namespace std;
using ll = long long;

void part1();
void part2();

int main()
{
    part2();
}

struct Node
{
    string left;
    string right;
};

void part1()
{
    fstream file("aoc8.txt");
    string line;
    int c = 0;
    string directions;
    unordered_map<string, Node> map;
    string curr = "AAA";
    while (getline(file, line))
    {
        if (c == 0)
        {
            directions = line;
        }
        else if (c >= 2)
        {
            string startNode;
            string leftNode;
            string rightNode;
            std::istringstream iss(line);
            iss >> startNode >> leftNode >> rightNode;
            Node n;
            n.left = leftNode;
            n.right = rightNode;
            cout << startNode << " " << leftNode << " " << rightNode << endl;

            map[startNode] = n;
        }
        c++;
    }

    long steps = 0;

    while (true)
    {

        for (char c : directions)
        {
            // cout << c << endl;
            // cout << curr << endl;
            if (curr == "ZZZ")
            {
                break;
            }
            if (c == 'L')
            {
                curr = map[curr].left;
            }
            else if (c == 'R')
            {
                curr = map[curr].right;
            }
            steps++;
        }
        if (curr == "ZZZ")
        {
            break;
        }
    }
    cout << steps << endl;
}

void part2()
{
    fstream file("aoc8.txt");
    string line;
    int c = 0;
    string directions;
    unordered_map<string, Node> map;
    vector<string> positions;
    while (getline(file, line))
    {
        if (c == 0)
        {
            directions = line;
        }
        else if (c >= 2)
        {
            string startNode;
            string leftNode;
            string rightNode;
            std::istringstream iss(line);
            iss >> startNode >> leftNode >> rightNode;
            Node n;
            n.left = leftNode;
            n.right = rightNode;
            cout << startNode << " " << leftNode << " " << rightNode << endl;
            if (startNode[2] == 'A')
            {
                positions.push_back(startNode);
            }
            map[startNode] = n;
        }
        c++;
    }

    // vector<ll> stepsList;
    ll n = 1;
    for (string curr : positions)
    {
        ll steps = 0;
        while (true)
        {

            for (char c : directions)
            {
                if (curr[2] == 'Z')
                {
                    break;
                }
                if (c == 'L')
                {
                    curr = map[curr].left;
                }
                else if (c == 'R')
                {
                    curr = map[curr].right;
                }
                steps++;
            }
            if (curr[2] == 'Z')
            {
                break;
            }
        }
        n = lcm(steps,n);
    }
    cout << n << endl;
}
// PA01-Random-Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>
#include <iostream>
#include <vector>

//------------------------------------------------------------------------------
// using symbols
//------------------------------------------------------------------------------
using std::cin;
using std::cout;
using std::vector;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int ITEMCOUNT = 10;

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
bool getMax(int&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    vector<int> vi;
    int maxRand;

    // app banner
    cout << "\nGenerate random numbers from 1 to n, inclusive\n\n";

    // exit loop on 0 input
    while (getMax(maxRand)) {

        // generate random numbers from 1 to user's max
        for (int i = 0; i < ITEMCOUNT; ++i) {
            vi.push_back(rand() % maxRand + 1);
        }

        // display in forward order
        for (int i = 0; i < ITEMCOUNT; ++i) {
            cout << vi.at(i) << ' ';
        }
        cout << '\n';

        // display in backwards order
        for (int i = 0; i < ITEMCOUNT; ++i) {
            cout << vi.back() << ' ';
            vi.pop_back();
        }
        cout << "\n\n";
    }

    cout << "Goodbye!\n";
}

//------------------------------------------------------------------------------
// getMax()
// - get largest random number to generate from user
// - store entered number in reference parameter userMax
// - use the absolute value of the number entered
// - return true if entered number is nonzero, false otherwise
//------------------------------------------------------------------------------
bool getMax(int& userMax) {

    cout << "Enter n (the largest random integer you want, 0 quits): ";
    cin >> userMax;

    if (!userMax) {
        return false;
    }

    // use the absolute value
    if (userMax < 0) {
        userMax = -userMax;
    }

    return (userMax);
}

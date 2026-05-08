#include <iostream>

#include "nfa_loader.h"
#include "nfa_sim.h"

using namespace std;

int main() {
    NFA nfa = loadNFA("data/nfa.json");

    string input;
     cout << "Enter string: ";
     cin >> input;

    if (accepts(nfa, input))
        cout << "ACCEPTED\n";
    else
        cout << "REJECTED\n";
}

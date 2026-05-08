#pragma once
#include "nfa_loader.h"
#include <set>
#include <string>

using namespace std;

set<string> epsilonClosure(
    const NFA& nfa,
    const set<string>& states
);


set<string> move(
    const NFA& nfa,
    const set<string>& states,
    char symbol
);


bool accepts(
    const NFA& nfa,
    const string& input
);

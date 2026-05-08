#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct NFA {
    vector<string> states;
    vector<char> alphabet;
    string start_state;
    unordered_set<string> final_states;
    unordered_map<string, unordered_map<char, vector<string>>> transitions;
};

NFA loadNFA(const string &filename);

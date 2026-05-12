#include "nfa_loader.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <filesystem>

using json = nlohmann::json;
using namespace std;
namespace fs = filesystem;

NFA loadNFA(const string &filename) {
    string config_file = filename;
    string example_file = "data/example_nfa.json";

    if (!fs::exists(config_file)) {
        if (fs::exists(example_file)) {
            fs::copy(example_file, config_file);
            cout << "No nfa.json found. Copied example_nfa.json to nfa.json\n";
        } else {
            throw runtime_error("Neither " + config_file + " nor " + example_file + " found");
        }
    }

    NFA nfa;
    ifstream file(config_file);

    if (!file.is_open())
        throw runtime_error("Cannot open file: " + filename);

    json jsonfile;
    file >> jsonfile;
    json root = jsonfile.at(0);

    // States
    for (const auto& s : root["states"])
        nfa.states.push_back(s.get<string>());

    // Alphabet
    for (const auto& c : root["alphabet"]) {
        string sym = c.get<string>();
        if (!sym.empty())
            nfa.alphabet.push_back(sym[0]);
    }

    // Start state
    nfa.start_state = root["start_state"].get<string>();

    // Final states
    for (const auto& s : root["final_states"])
        nfa.final_states.insert(s.get<string>());

    // Transitions
    for (const auto& [state, transitions] : root["transitions"].items()) {
        for (const auto& [symbol, next_states] : transitions.items()) {
            char c = (symbol == "epsilon") ? '\0' : symbol[0];

            for (const auto& ns : next_states) {
                nfa.transitions[state][c].push_back(ns.get<string>());
            }
        }
    }

    return nfa;
}


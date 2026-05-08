#include "nfa_sim.h"
#include <stack>

using namespace std;

 set<string> epsilonClosure(
    const NFA& nfa,
    const  set<string>& states
) {
     set<string> closure = states;
     stack<string> st;

    for (const auto& s : states)
        st.push(s);

    while (!st.empty()) {
         string current = st.top();
        st.pop();

        auto it = nfa.transitions.find(current);
        if (it == nfa.transitions.end())
            continue;

        auto eps = it->second.find('\0');
        if (eps == it->second.end())
            continue;

        for (const auto& next : eps->second) {
            if (!closure.count(next)) {
                closure.insert(next);
                st.push(next);
            }
        }
    }

    return closure;
}


 set<string> move(
    const NFA& nfa,
    const  set<string>& states,
    char symbol
) {
     set<string> result;

    for (const auto& state : states) {
        auto it = nfa.transitions.find(state);
        if (it == nfa.transitions.end())
            continue;

        auto sym = it->second.find(symbol);
        if (sym == it->second.end())
            continue;

        for (const auto& next : sym->second)
            result.insert(next);
    }

    return result;
}


bool accepts(
    const NFA& nfa,
    const  string& input
) {
     set<string> current =
        epsilonClosure(nfa, { nfa.start_state });

    for (char c : input) {
        current = epsilonClosure(
            nfa,
            move(nfa, current, c)
        );

        if (current.empty())
            return false;
    }

    for (const auto& s : current) {
        if (nfa.final_states.count(s))
            return true;
    }

    return false;
}

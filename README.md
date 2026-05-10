# NFA Checker

A simple C++ implementation of a Nondeterministic Finite Automaton (NFA) checker that validates strings against NFA definitions from JSON files.

## Prerequisites

- [C++17](https://en.cppreference.com/w/cpp/compiler_support/17) compatible compiler (g++, clang, etc.)
- [CMake](https://cmake.org/) (version 3.10 or higher)
- [nlohmann-json](https://github.com/nlohmann/json) library

## Installing nlohmann-json

### Arch Linux
```bash
sudo pacman -S nlohmann-json
```

### Ubuntu/Debian
```bash
sudo apt install nlohmann-json3-dev
```

### Fedora/RHEL
```bash
sudo dnf install nlohmann-json-devel
```

### macOS (Homebrew)
```bash
brew install nlohmann-json
```

### Manual Installation

If your package manager doesn't have nlohmann-json, you can install it manually:
```bash
git clone https://github.com/nlohmann/json.git
cd json && mkdir build && cd build
cmake .. && sudo make install
```

## Building the Project
```bash
git clone https://github.com/AmirrezaSaadi/nfa-checker.git
cd nfa-checker
mkdir build && cd build
cmake ..
make
```

## Running the Program

From the project root directory:
```bash
./build/nfa_checker
```

## JSON File Format

The program reads `data/nfa.json` by default. 

> [!NOTE]
> The `data/nfa.json` file does not exist in the repository by default. You must create or copy it using the example file.
```bash
cp data/example_nfa.json data/nfa.json
```

JSON Structure Example
```json
[
  {
    "states": ["q0", "q1", "q2"],
    "alphabet": ["0", "1"],
    "start_state": "q0",
    "final_states": ["q2"],
    "transitions": {
      "q0": {
        "0": ["q1"],
        "epsilon": ["q0"]
      },
      "q1": {
        "1": ["q2"]
      }
    }
  }
]
```

## Usage
After building and setting up data/nfa.json, run the program:
```bash
./build/nfa_checker
```

Enter a string when prompted. The program will output:

- **ACCEPTED** - if the string is accepted by the NFA
- **REJECTED** - if the string is rejected

## Planned Features

- [ ] **Automatic JSON setup** - Auto-copy `example_nfa.json` to `nfa.json` if missing

   
## Project Structure
```text
nfa-checker/
├── src/           # Source files
├── include/       # Header files
├── data/          # JSON configuration files
│   ├── nfa.json           # Your NFA definition (doesn't exist by default)
│   └── example_nfa.json   # Example reference file
└── CMakeLists.txt # Build configuration
```

## Example
```bash
$ ./build/nfa_checker
Enter string: aa
ACCEPTED

$ ./build/nfa_checker
Enter string: ab
REJECTED
```

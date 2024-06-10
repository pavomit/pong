# Pong Game

This repository contains the source code for a simple yet engaging implementation of the classic Pong game. Developed using CMake for project management, C++ for the core logic, and SFML (Simple and Fast Multimedia Library) for rendering graphics, handling windows, and managing input.

## Features

- [x] Multiplayer mode over the same machine
- [ ] Single-player mode against AI
- [ ] Adjustable difficulty levels for single-player mode
- [ ] High score tracking

## Getting Started

To get started with this project, you will need to have CMake installed on your system. The following steps outline how to set up and run the game:

### Prerequisites

- CMake 3.x
- A C++ compiler that supports C++17 (e.g., GCC 7.0+ or Clang)
- SFML library (version 2.6 or later)

### Basic project structure
```bash
.
├── CMakeLists.txt
├── assets
│   └── fonts
│       └── font.ttf
|
└── main.cpp
```

### Installation

1. **Clone the Repository**

```bash
 git clone git@github.com:pavomit/pong.git
```

```bash
cd pong
```

2. **Create a Build Directory**

```bash
mkdir build && cd build
```
> you can use cmake directly like that while in the main directory
> ```bash
> cmake -S . -B build
> ```

3. **Configure and build the Project**

```bash
cmake ..
```
`This command generates the necessary Makefiles or project files based on your system configuration.` 

4. **Compile the Source Code**

Compile the source code by running: `make`  on linux or the `Msbuild` if on windows or just click the `.sln` to open in microsoft visual studio.

or while in `build` directory run 

```bash
cmake --build .
```

5. **After compilation, you can start the game by running:**
```bash
./pong
```

### Contributing
Contributions to improve the game, fix bugs, or add new features are welcome. Please submit a pull request with your changes.


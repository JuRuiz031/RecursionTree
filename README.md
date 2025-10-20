# Pythagorean Tree
 Juan Fernando Ruiz

## Overview
This project draws a Pythagorean (recursive) tree using SFML for rendering. The core idea is to start with a root rectangle and recursively create two child rectangles at each step, rotating and scaling them according to the Pythagorean tree geometry until a base case (depth limit or minimal size) is reached.

The implementation focuses on abstraction: a `PTree` class encapsulates the geometric state and the recursive drawing logic, and `main.cpp` handles program setup and window management using SFML.

## Files
- `main.cpp` — Program entry point. Sets up the SFML window, creates the initial `PTree` instance(s), and triggers drawing.
- `PTree.hpp` / `PTree.cpp` — The `PTree` class and implementation. Responsible for storing rectangle geometry (position, size, angle), recursion parameters (depth, scale), and the recursive `drawTree` behavior that constructs and renders child rectangles.
- `Makefile` — Build rules. Uses `g++` with C++17 and links SFML libraries (graphics, window, system) and Boost unit test framework (if needed).

## How it works (implementation details)
- PTree as an object: Each `PTree` instance represents one rectangle (a node). It stores its transform (position, width/height, rotation) and a recursion depth counter.
- Recursive drawing: The `drawTree` method is implemented so that a node draws itself (as an SFML rectangle shape) then computes the transforms for its two child rectangles. It constructs child `PTree` objects (or calls an overloaded `drawTree` helper) with updated size, position and rotation, then calls their `drawTree` until the recursion limit or minimum size is reached.
- Geometry: Child rectangles are positioned relative to the parent's top edge, with rotations chosen so their bases align to form a right-triangle arrangement reminiscent of the Pythagorean theorem. Scaling is applied to shrink children appropriately (commonly using trigonometric relationships derived from the chosen angle).
- Overloads and helpers: The code uses overloaded `drawTree` functions to separate concerns (e.g., one overload takes explicit transform parameters for recursive calls while another is a simpler public entry point). This keeps the public API concise and the recursion logic clear.

## Use of SFML
- SFML handles window creation (`sf::RenderWindow`), event polling (close, key events), and 2D drawing (`sf::RectangleShape`, transforms and colors).
- Draw calls are performed in the main render loop. Each `PTree` node uses SFML shapes and transform operations so the visual code stays small and expressive.
- The `Makefile` links against `-lsfml-graphics -lsfml-window -lsfml-system`. If SFML is not installed system-wide, install it for your platform or update the linker flags to point to local builds.

## Build & Run
The repository includes a `Makefile`. On a machine with a POSIX-compatible make/g++ and SFML installed, build and run with:

```
make
./PTree
```

Notes for Windows (MinGW / MSYS or WSL):
- If using MinGW-w64, ensure SFML for MinGW is installed and your PATH contains the SFML DLLs (or place them next to the executable). The `Makefile` uses `g++` and standard flags; adjust the compiler path if needed.
- Alternatively, build using an IDE (Visual Studio) by creating a project and linking SFML libraries accordingly.

## Design & Abstraction
- Encapsulation: The `PTree` class centralizes all tree logic and geometry so `main.cpp` only needs to prepare arguments and trigger drawing. This makes the drawing algorithm reusable and testable.
- Single responsibility: Rendering, geometric math (positions, rotations, scales), and recursion depth control are separated between small helper functions and the `drawTree` overloads.
- Extensibility: The class design makes it straightforward to add features like different branching angles, color gradients per depth, interactive controls, or saving frames to images.

## Acknowledgements
- GeeksForGeeks — conceptual references on recursive drawing and geometry helpers.
- SFML documentation — reference for windowing, events, and drawable shapes.
- Former classmates — discussion and ideas on window sizing and program structure.

## Notes
- The `Makefile` links Boost unit test framework (`-lboost_unit_test_framework`) but tests are not required to run the visual program.
- If you plan to extend or test the code, consider adding unit tests that validate the transform math used to position child rectangles.

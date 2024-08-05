# Game of Life SDL2

## Overview

This project is an implementation of Conway's Game of Life using SDL2 and C. It provides a graphical simulation of cellular automata, allowing you to observe the evolution of patterns over time based on simple rules.

### Todo:
- Add wrap-around feature for the world | **DONE**
- Display statistics
- Player control
- Optimization
- Cross-platform support

![board](https://github.com/maxxim00/game_of_life_sdl2/blob/main/img/image.jpg?raw=true)

## Features

- Real-time graphical representation of Conway's Game of Life.
- Basic implementation for easy understanding and modification.
- Built with SDL2 for rendering.

## Getting Started

To build and run the project, follow these steps:

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/game_of_life_sdl2.git
   cd game_of_life_sdl2
   ```

2. **Build & Run the project:**

   Ensure you have `make` and SDL2 development libraries installed on your system. Then, in the project directory, simply type:

   ```bash
   make
   ```

## Dependencies

- **SDL2:** You need the SDL2 development libraries. Install them using:

  - **Debian-based systems (e.g., Ubuntu):**

    ```bash
    sudo apt-get install libsdl2-dev
    ```

  - **Fedora:**

    ```bash
    sudo dnf install SDL2-devel
    ```

- **Make:** Ensure `make` is installed on your system.

## Notes

- The code is currently not optimized. Contributions for improvements and optimizations are welcome.

## License

This project is licensed under the Unlicense License. See the [LICENSE](LICENSE) file for details.

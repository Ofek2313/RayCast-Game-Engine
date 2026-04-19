# RayCast Game Engine

A Wolfenstein-style raycasting renderer built in C++ using SFML, developed by following a raycasting tutorial as a way to learn 3D rendering fundamentals.

## About

Raycasting is the rendering technique used in classic games like Wolfenstein 3D and the original DOOM engine. It simulates a 3D perspective from a 2D map by casting rays from the player's viewpoint and calculating wall heights based on distance. This project implements that technique using C++ and SFML for windowing and rendering.

## Features

- Real-time raycasting renderer
- First-person perspective from a 2D grid map
- SFML-based window management and rendering
- Fonts, images, and sounds included as assets

## Requirements

- Windows
- Visual Studio 2022 (or later)
- SFML (bundled in `include/` and `lib/`)

## Building

1. Clone the repository:
   ```
   git clone https://github.com/Ofek2313/RayCast-Game-Engine.git
   ```
2. Open `RayCastGame.sln` in Visual Studio.
3. Set the build configuration to **Release** or **Debug**.
4. Press **Ctrl+Shift+B** to build.

SFML is bundled in the `include/` and `lib/` directories and is already linked in the project.

## Project Structure

```
RayCast-Game-Engine/
├── RayCastGame/       # Source files
├── Fonts/             # Font assets
├── Images/            # Texture and image assets
├── Sounds/            # Audio assets
├── include/SFML/      # Bundled SFML headers
├── lib/               # Bundled SFML libraries
└── RayCastGame.sln    # Visual Studio solution file
```

## Learning Reference

This project was built by following a raycasting tutorial as a hands-on way to understand 3D rendering concepts including ray-wall intersection, field of view projection, and distance-based shading.

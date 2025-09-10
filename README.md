# FDF - Fil de Fer (Wire Frame Model)

[![42 School](https://img.shields.io/badge/School-42-black?style=flat-square&logo=42)](https://42.fr/)
[![Language: C](https://img.shields.io/badge/Language-C-blue?style=flat-square&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Graphics Library: MLX42](https://img.shields.io/badge/Graphics-MLX42-green?style=flat-square)](https://github.com/codam-coding-college/MLX42)

A 3D wireframe visualization project that renders elevation maps using isometric projection. This project is part of the 42 School curriculum and demonstrates fundamental computer graphics concepts including 3D transformations, line drawing algorithms, and real-time rendering.

![FDF Demo](./assets/screenshot.png)

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Map Format](#map-format)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Technical Details](#technical-details)
- [Requirements](#requirements)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

FDF (Fil de Fer, French for "wireframe") is a computer graphics project that creates a 3D isometric representation of a landscape by connecting various points (x, y, z) through segments. The program reads elevation data from a file and renders it as a wireframe model that can be manipulated in real-time.

The project demonstrates:
- **3D to 2D projection** using isometric transformation
- **Bresenham's line algorithm** for efficient line drawing
- **Real-time rendering** with interactive controls
- **Memory management** in C
- **Graphics programming** fundamentals

## ✨ Features

- **3D Wireframe Rendering**: Converts elevation maps into beautiful 3D wireframe models
- **Isometric Projection**: Displays the model using isometric perspective for optimal viewing
- **Interactive Controls**:
  - Zoom in/out with mouse scroll
  - Real-time rotation animation
  - Exit with ESC key
- **Multiple Map Support**: Compatible with various map formats and sizes
- **Optimized Performance**: Efficient rendering using MLX42 graphics library
- **Memory Safe**: Proper memory allocation and cleanup
- **Cross-platform**: Works on Linux systems

## 🚀 Installation

### Option 1: Download Pre-compiled Binary (Recommended for Users)

1. **Go to the releases page**
   ```
   https://github.com/PabloMzGa/42-fdf/releases
   ```

2. **Download the latest release** for your system

3. **Make it executable** (Linux/macOS)
   ```bash
   chmod +x fdf
   ```

4. **Run the program**
   ```bash
   ./fdf maps/42.fdf
   ```

### Option 2: Build from Source (For Developers)

### Prerequisites

- **GCC compiler** (with C99 support)
- **Make** build system
- **GLFW library** for window management
- **OpenGL** support
- **Git** for cloning the repository

### Installation Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/PabloMzGa/42-fdf.git
   cd 42-fdf
   ```

2. **Install dependencies** (Ubuntu/Debian)
   ```bash
   sudo apt update
   sudo apt install build-essential libglfw3-dev libgl1-mesa-dev
   ```

3. **Build the project**
   ```bash
   make
   ```

4. **Run the program**
   ```bash
   ./build/fdf maps/42.fdf
   ```

## 🎮 Usage

### Basic Usage

**If you built from source:**
```bash
./build/fdf [map_file]
```

**If you downloaded from releases:**
```bash
./fdf [map_file]
```

### Examples

**Using compiled binary (from releases):**
```bash
# Render the classic 42 logo
./fdf maps/42.fdf

# Visualize a pyramid structure
./fdf maps/pyramide.fdf

# Display Mars terrain data
./fdf maps/mars.fdf

# Show Julia set fractal
./fdf maps/julia.fdf
```

**Using built from source:**
```bash
# Render the classic 42 logo
./build/fdf maps/42.fdf

# Visualize a pyramid structure
./build/fdf maps/pyramide.fdf

# Display Mars terrain data
./build/fdf maps/mars.fdf

# Show Julia set fractal
./build/fdf maps/julia.fdf
```

## 🎮 Controls

| Control | Action |
|---------|---------|
| `ESC` | Exit the program |
| `Mouse Scroll Up` | Zoom in |
| `Mouse Scroll Down` | Zoom out |
| `Automatic` | Continuous rotation animation |

## 📄 Map Format

FDF uses a simple text-based format for elevation maps:

```
0  0  0  0  0
0 10 10 10  0
0 10 20 10  0
0 10 10 10  0
0  0  0  0  0
```

### Format Specifications:
- Each number represents the **Z-coordinate** (elevation) of a point
- Numbers are separated by **spaces**
- Each line represents a **row** in the 3D space
- Numbers **must** be in a square or rectangule form
- **X-coordinate** increases from left to right
- **Y-coordinate** increases from top to bottom
- **Z-coordinate** is the elevation value at each point

**Format is not checked, so the user is responsible for it being well formed**

## 📁 Project Structure

```
fdf/
├── build/                  # Compiled binaries and object files
├── include/
│   └── fdf.h              # Main header file with structures and prototypes
├── lib/
│   ├── libft/             # Custom C library (string manipulation, memory, etc.)
│   └── MLX42/             # Graphics library for rendering
├── maps/                  # Sample elevation map files
├── src/
│   ├── main.c             # Program entry point
│   ├── hooks/             # Event handling (keyboard, mouse)
│   ├── render/            # Rendering engine and camera system
│   ├── utils/             # Utility functions (file I/O, cleanup)
│   └── vect_process/      # Vector processing and transformations
└── Makefile              # Build configuration
```

## 🔧 Technical Details

### Graphics Pipeline

1. **Map Parsing**: Read elevation data from input file
2. **3D Coordinate Generation**: Convert 2D grid to 3D points
3. **Transformation**: Apply scaling, rotation, and translation
4. **Projection**: Convert 3D coordinates to 2D screen coordinates
5. **Rasterization**: Draw lines between connected points using Bresenham's algorithm

### Key Algorithms

- **Isometric Projection**: Mathematical transformation from 3D to 2D
- **Bresenham's Line Algorithm**: Efficient line drawing without floating-point arithmetic
- **Real-time Rotation**: Matrix transformations for smooth animation
- **Adaptive Scaling**: Dynamic zoom functionality

### Performance Optimizations

- **Efficient Memory Management**: Dynamic allocation with proper cleanup
- **Optimized Line Drawing**: Hardware-accelerated rendering where possible
- **Minimal Recomputation**: Caching frequently used calculations
- **Frame Rate Control**: Smooth animation at consistent frame rates

### Configurable Parameters

The program behavior can be customized by modifying macros in `include/fdf.h`:

| Macro | Default Value | Description |
|-------|---------------|-------------|
| `POINT_RADIUS` | `0` | Scale of each dot of the grid (0 = single pixel) |
| `GRAPH_COLOR` | `0xFFFFFFF5` | Color of the wireframe lines |
| `BACKGROUND_COLOR` | `0x00000000` | Background color of the window |
| `Z_MULTIPLIER` | `1` | Multiplier for the Z coordinate (height scaling) |
| `SPACING` | `10` | Space between each point in XY plane |
| `ROT_DEG` | `1` | Degrees the model rotates every frame |
| `ZOOM` | `0.01` | Zoom increment/decrement step |
| `MIN_SCALE` | `0.01` | Minimum allowed zoom scale |
| `MAX_SCALE` | `50` | Maximum allowed zoom scale |
| `WIDTH` | `1920` | Window width in pixels |
| `HEIGHT` | `1080` | Window height in pixels |

**Note**: After modifying these values, recompile the project with `make re`.

## 📋 Requirements

### System Requirements
- **OS**: Linux (Ubuntu 18.04+ recommended)
- **RAM**: Minimum 512MB
- **Graphics**: OpenGL 3.3 compatible GPU
- **Compiler**: GCC 7.0+ or Clang 6.0+

### Library Dependencies
- **MLX42**: Graphics and window management
- **GLFW**: Cross-platform window creation
- **OpenGL**: Graphics rendering
- **libm**: Mathematical functions

### 42 School Norm Compliance
This project follows the strict 42 School coding standards:
- Maximum 25 lines per function
- Maximum 80 columns per line
- No global variables
- Proper error handling
- Comprehensive documentation

## 🏗️ Build System

The project uses a comprehensive Makefile with the following targets:

```bash
make           # Build the project
make clean     # Remove object files
make fclean    # Remove all generated files
make re        # Rebuild everything
make bonus     # Build with bonus features (if applicable)
```

### Compilation Flags
- `-Wall -Wextra -Werror`: Strict warning and error checking
- `-lglfw -lm`: Link against GLFW and math libraries
- Debug symbols included for development

## 🤝 Contributing

This project is part of the 42 School curriculum and is primarily for educational purposes. However, suggestions and improvements are welcome!

### Development Guidelines
1. Follow the 42 School Norm
2. Ensure all memory is properly managed
3. Test with various map files
4. Maintain cross-platform compatibility
5. Document any new features

## 📜 License

This project is part of the 42 School curriculum. The code is available for educational purposes and portfolio demonstration.

---

### 👨‍💻 Author

**Pablo Martínez García**
- GitHub: [@PabloMzGa](https://github.com/PabloMzGa)
- 42 Intra: `pabmart2`
- School: 42 Málaga

---

*This project was completed as part of the 42 School curriculum - a innovative, project-based programming school with a peer-to-peer learning methodology.*

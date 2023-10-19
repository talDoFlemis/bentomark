# Bentomark

![Issues](https://img.shields.io/github/issues/taldoflemis/bentomark)
![Pull requests](https://img.shields.io/github/issues-pr/taldoflemis/bentomark)

Bentomark is a C++ library for benchmarking numeric methods.

## Development

### Prerequisites

Make sure you have the following tools installed:

- [CMake](https://cmake.org/cmake/help/latest/command/install.html): Required for building the project
- [Qt](https://www.qt.io/download): Graphics framework
- [QtCreator](https://www.qt.io/download): QT Helper for UI creation
- [Make](https://stackoverflow.com/questions/32127524/how-to-install-and-use-make-in-windows): Build automation tool

### Running Locally

To run this project locally, follow these steps:

1. Use CMake to generate the Make build system:

   ```bash
   cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
   ```

   The `-DCMAKE_EXPORT_COMPILE_COMMANDS` flag is essential for your Language Server Protocol (LSP), such as CLANG, to acquire symbols.

2. Build the project with Make:

   ```bash
   make
   ```

3. Run the project locally.

### Adding New Resources

To include new resources and executables, modify the `CMakeList.txt` file. Ensure that you add the necessary files to optimize the CMake build system. After making changes, run:

```bash
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON .
```

This step is crucial for CMake to incorporate the new additions into the build system.

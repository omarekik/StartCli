# StartCli
A starting template for a C++ project with unit testing based on gtest and a command line interface based on boost program_option
## Build:
By using the following command, docker image will be built from github repository and by running the container, it will : 
 * Build StartCli solution (Conan + CMake + C++17 compiler)
 * Run unit tests
 * Run examples and remain  bash opened to try more examples of execution
```
git clone git@github.com:omarekik/StartCli.git && cd StartCli/start
docker run --rm -it $(docker build -q .)
```
or build solution localy by using create_package script or conan commands as mentioned in the script: 
```
git clone git@github.com:omarekik/StartCli.git && cd StartCli/start
chmod +x scripts/create_package.sh && ./scripts/create_package.sh
```
## Example of execution:
Remain in the main directory and run the following commands:
```console
# Start -h
Program options:
  -h [ --help ]             display help menu
  -c [ --create ]           option boolean
  -w [ --width ] arg (=10)  option integer with default value

```

## Notes:
 * For every new project, in the CMakeLists.txt, it is possible to specify the target_compile_options by using the variable compiler_warnings initialized in start/scripts/compiler_warnings.cmake  

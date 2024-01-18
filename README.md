# StartCli
A starting template for a C++ project with unit testing based on gtest and a command line interface based on boost program_option. The project is linked to ms-gsl library to help respect cpp core guidelines which are checked by clang-tidy static analyzer.

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
Running the CLI with the program option -h will show the help message:
```console
# cd build/main && Start -h
Program options:
  -h [ --help ]             display help menu
  -c [ --create ]           option boolean
  -w [ --width ] arg (=10)  option integer with default value

```

## Notes:
 * For every new project, in the CMakeLists.txt, it is possible to specify the target_compile_options of warning by using the variable compiler_warnings initialized in start/scripts/compiler_warnings.cmake. And also it is possible to set_target_properties of CXX_CLANG_TIDY to specify clang-tidy as static anlyzer for checking conformity with cppcoreguidelines, and in case of warning it will block the build till fixed as configured in start/scripts/static_checking.cmake

## VSCode:
 * In .vscode/tasks.json, a task named "code_format" is created. To format the code following clang format style defined in .clang-format file, type `ctrl+shift+b` and select the format task.
 * In .vscode/tasks.json, two tasks named "build_debug"/"build_release" are created. To launch the build, type `ctrl+shift+b` and select from the build tasks. 
 * Debugging configuration is defined in .vscode/launch.json. For mac/linux environment, vscode extension of CodeLLDB and lldb debugger are required. For windows environment, cppvsdbg is needed. To start debugging type `F5` and to run without debugging type `ctrl+F5`.

## Git pre-commit hook:
Under .git/hooks add file named pre-commit without extension and put this content in it:  
```
#!/bin/sh

# Relative path to your custom script within the project folder
custom_script_pre_commit="./start/scripts/format_code.sh"

# Run the custom script
if [ -f "$custom_script_pre_commit" ]; then
  echo "pre-commit hook: Running ${custom_script_pre_commit}"
  sh "$custom_script_pre_commit"
else
  echo "${custom_script_pre_commit} not found. Commit aborted."
  exit 1
fi
```  

## Known issues:
 * If there is unstaged source/header files, the script start/scripts/format_code.sh will show "Formatting is wrong" even if clang format did not modify any file. Actually, the script should be used after staging all source files and before commiting, so its result gonna be accurate.


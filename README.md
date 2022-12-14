# CS225-Final-Project
> The repo for final project of CS225 for group FZLX

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

****

### Introduction

This is the UIUC CS225 final project repository for group FZLX, with members Haiyang Qin, Tianyi Liu, Xing Zhao, and David Fu. Our leading question for the project is that given an infectious virus appearing in a specific city in the United States, how will the pandemic develops in the country as virus spreads along the road network and airlines. To answer this question, we implemented several data strucutres and algorithms and finally come up with a simulator that is able to show how the pandemic would develop given a specific infectious virus. The final presentation of the project can be found at: <a href = "https://clipchamp.com/watch/lfz9C5KTt7x"> video </a>

****

### Structure of the repository
    .
    ├── bin                 The result of program
    ├── build               Makefile and compiled output files generated by CMake
    ├── data                The datasets we use in the project
    ├── lib                 All the functions and classes needed
    │   ├── algorithm       The implementation of algorithms we used
    │   ├── data            Data processing utilities   
    │   └── graph           The implementation of graph 
    ├── src                 The main programs
    ├── tests               The unit tests we used
    ├── CMakeLists.txt      The CMake program for compiling
    ├── instruction.md      The instructions on Git operations for the repository
    ├── LICENSE             The license for the repository
    ├── README.md           The ReadMe file for the repository
    ├── result.md           The written report of final project
    ├── team_contract.md    The team contract for the group
    └── team_proposal.md    The proposal for the project

### Getting Started

To run the programs we generated, you need to clone our repository:
```
git clone https://github.com/lnblanke/CS225-Final-Project.git
```

- Running ```main.cpp```
    
    ```main.cpp``` program generates a time sequence representing the status of each city at different time units after the virus starts to spread. To run the program, you need to switch to folder ```/build/``` first (assuming you are in primary folder):
    ```
    cd build
    ```

    and then you can execute the program by command:

    ```bash
    ./main START_POINT LATENCY_PERIOD [BLOCK_TIME BLOCK_1 BLOCK_2 ... ]
    ```

    ```START_POINT``` - a string representing the city that virus first appears. The format should be [city name],[state]. The program would throw an exception if the program cannot find the city.

    ```LATENCY_PERIOD``` - an integer representing the latency period of the virus. The program would throw an exception if the field appears to be not integer.
    
    ```BLOCK_TIME``` - an integer representing the time when the blocking takes place. You need to provide at least one ```BLOCK``` if you use blocking. The program would throw an exception if the field appears to be not integer.

    ```BLOCK``` - an string representing a city to be blocked. The format is the same as ```START_POINT```. The program would throw an exception if the program cannot find the city.

    Examples of the command:

    - Not using blocking
        ```bash
        ./main "Chicago,IL" 5
        ```
    - Using blocking
        ```bash
        ./main "Chicago,IL" 5 10 "San Francisco,CA" "New York,NY" "Washington,DC"
        ```

    The default input path is ```/data/```, and you can change this by modifying constant variables ```airport_file_path, route_file_path, population_file_path, node_file_path, edge_file_path``` in ```/src/load_files.h```. The default output path is ```/bin/```, and you can change this by modifying constant variables ```output_node_path, output_status_path``` in ```/src/main.cpp```.

- Running ```main.py```

    We provide a visualizer of the data we generate with Python. To run the program, you need to make sure that there is ```/bin/nodes.list, /bin/status.list``` (or in other directory if you changed the output path in ```main.cpp```) generated by ```main.cpp```. The program is also dependent on ```MatPlotLib``` library. A method to install this library using pip is
    ```
    pip3 install matplotlib
    ```
    If previous steps are all done, you need to move to the ```/src/``` folder (assuming you are in primary folder) by
    ```
    cd src
    ```
    and then execute the program by
    ```
    python3 -u "main.py"
    ```

- Running test

    We created tests for all of the algorithms, data structures, and functions that we implemented. We included both small, middle, and large tests to check their correctness and efficiency. You can run the tests by first move to ```/build/``` folder (assuming you are at primary folder):
    ```
    cd build
    ```
    and then execute by:
    ```
    ./test
    ```
## How to compile and run this code.
1) Download and install g++.  
**Note**: If you use ***Windows***, then add g++ in PATH.
2) Compile.  
Enter in command line or terminal this command in folder with this code:
`g++ -o Film.[extension] main.cpp Film.cpp FilmList.cpp`  
**Note**: If you use ***Windows***, then change "[extension]" on "exe", if you use ***Linux***, then "out".
3) Run.  
    ***Windows***: In command line write your command: `Film.exe [input file] [output file]`  
    ***Linux***: In terminal enter your command `./Film.out [input file] [output file]`  
    **Note**:  
    "[input file]" contains a path to a file with films data.   
    "[output file]" contains a path to a file where you want to write films data from "[input file]" 

## What films data must contain in [input file].

1. In first line number of films.
2. Line break.
3. Type film(allowed type: *Fiction* or *Cartoon*).
4. Title film
5. If ***Fiction***, then stage director, 
or if ***Cartoon***, then way for creating the cartoon(allowed ways: *Clay*, *Hand drawn*, *Computer*, *Doll*).
6. If your file contains more than one film, then go to point 2.  
**Note**: All allowed values are **CASE-SENSITIVE**.

**Example**:
```
2

Fiction
Pulp Fiction
Quentin Tarantino

Cartoon
9
Doll
```

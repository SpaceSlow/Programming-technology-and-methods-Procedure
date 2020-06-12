## How to compile and run this code.
1) Download and install g++.  
**Note**: If you use ***Windows***, then add g++ in PATH.
2) Compile.  
Enter in command line or terminal this command in folder with this code:
`g++ -o Film.[extension] main.cpp Film.cpp FilmList.cpp UnitTests.cpp`  
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
3. Sorting films(allowed values: *Sort* and *No sort*).  
**Note**: Sorting by the number of vowels in the film title.
4. Filtering films(allowed values: *All* and any type of film, see point 5).
5. Type film(allowed values: *Fiction*, *Cartoon* and *Documentary*).
6. Title film.
7. Country.
8. If ***Fiction***, then stage director, 
or if ***Cartoon***, then way for creating the cartoon(allowed values: *Clay*, *Hand drawn*, *Computer* and *Doll*),
or if ***Documentary***, then year of production.
9. If your file contains more than one film, then go to point 2.  
**Note**: All allowed values are **CASE-SENSITIVE**.

**Example**:
```
4
Sort
All

Fiction
USA
Pulp Fiction
Quentin Tarantino

Cartoon
USA, Germany
9
Doll

Documentary
USA
The Story of Queen: Mercury Rising
2011

Cartoon
UK, USA, France
Chicken Run
Clay
```
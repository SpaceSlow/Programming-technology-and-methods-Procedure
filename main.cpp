#include <iostream>

#include "FilmList.h"
#include "UnitTests.h"

using std::cout;
using std::cerr;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {

//    Unit-tests
//    run_tests();

    if (argc != 3) {
        cerr << "Type input and output files." << endl;
        return -1;
    }

    FilmList *film_list = init_film_list();

    string input_path = argv[1];

    try {
        read_films_from_file(film_list, input_path);
    } catch (const char* msg) {
        cerr << msg << endl;
        return -1;
    }

    string output_path = argv[2];

    try {
        write_films_to_file(film_list, output_path);
    } catch (const char* msg) {
        cerr << msg << endl;
        return -1;
    }

    cout << "Success." << endl;
    return 0;
}

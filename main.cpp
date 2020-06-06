#include <iostream>

#include "FilmList.h"

using std::cout;
using std::endl;
using std::string;


int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Type input and output files." << endl;
        return -1;
    }

    FilmList *film_list = init_film_list();

    string input_path = argv[1];
    bool is_success_read = read_films_from_file(film_list, input_path);
    if (!is_success_read) {
        cout << "Failed to open file for reading." << endl;
        return -1;
    }

    string output_path = argv[2];
    bool is_success_write = write_films_to_file(film_list, output_path);
    if (!is_success_write) {
        cout << "Failed to open file for writing." << endl;
        return -1;
    }

    cout << "Success." << endl;
    return 0;
}
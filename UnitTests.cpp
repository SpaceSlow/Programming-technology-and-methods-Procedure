//
// Created by garry on 12.06.2020.
//

#include <iostream>
#include <sstream>
#include <fstream>

#include "UnitTests.h"

using std::cout;
using std::endl;
using std::stringstream;

void run_tests() {
    test_size_after_add_film();
    test_links_in_film_list();
    test_read_write_from_file();
    test_vowels_number_in_film_title();
    test_sort_film_list();
    test_filter_film_list();
}

void test_size_after_add_film() {
    FilmList *film_list = init_film_list();

    Film *film = new Film();

    assert(film_list->size == 0);
    add_film(film_list, film);
    assert(film_list->size == 1);
    add_film(film_list, film);
    assert(film_list->size == 2);
    add_film(film_list, film);
    assert(film_list->size == 3);

    cout << "Success test_size_after_add_film" << endl;
}

void test_links_in_film_list() {
    FilmList *film_list = init_film_list();

    Film *film1 = new Film();
    Film *film2 = new Film();
    Film *film3 = new Film();

    add_film(film_list, film1);
    assert(film1 == film_list->first_film->film);
    add_film(film_list, film2);
    assert(film2 == film_list->first_film->next_film->film);
    assert(film2 == film_list->last_film->film);
    add_film(film_list, film3);
    assert(film3 == film_list->first_film->next_film->next_film->film);
    assert(film3 == film_list->last_film->film);
    assert(film_list->last_film->next_film == nullptr);

    cout << "Success test_links_in_film_list" << endl;
}

void test_read_write_from_file() {

    string input_path = "test_files/testReadWriteFromFile_in.txt";
    string output_path = "test_files/testReadWriteFromFile_out.txt";

    string expected = "Number of films: 4\n"
                      "\n"
                      "Type film: Fiction\n"
                      "Country: USA\n"
                      "Title: Pulp Fiction\n"
                      "Directed by Quentin Tarantino\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: USA, Germany\n"
                      "Title: 9\n"
                      "Type animation: Doll\n"
                      "\n"
                      "Type film: Documentary\n"
                      "Country: USA\n"
                      "Title: The Story of Queen: Mercury Rising\n"
                      "Year of release: 2011\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: UK, USA, France\n"
                      "Title: Chicken Run\n"
                      "Type animation: Clay\n";

    FilmList *film_list = init_film_list();

    read_films_from_file(film_list, input_path);
    write_films_to_file(film_list, output_path);

    ifstream in_file(output_path);
    stringstream buffer;
    buffer << in_file.rdbuf();
    string real = buffer.str();

    assert(real == expected);

    cout << "Success test_read_write_from_file" << endl;
}

void test_vowels_number_in_film_title() {
    string input_path = "test_files/testVowelsNumberInFilmTitle.txt";

    FilmList *film_list = init_film_list();

    read_films_from_file(film_list, input_path);

    assert(get_vowels_number_in_title(film_list->first_film->film) == 4);
    assert(get_vowels_number_in_title(film_list->first_film->next_film->film) == 0);
    assert(get_vowels_number_in_title(film_list->last_film->film) == 10);

    cout << "Success test_vowels_number_in_film_title" << endl;
}

void test_sort_film_list() {
    string input_path = "test_files/testSortFilmList_in.txt";
    string output_path = "test_files/testSortFilmList_out.txt";


    string expected = "Number of films: 4\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: USA, Germany\n"
                      "Title: 9\n"
                      "Type animation: Doll\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: UK, USA, France\n"
                      "Title: Chicken Run\n"
                      "Type animation: Clay\n"
                      "\n"
                      "Type film: Fiction\n"
                      "Country: USA\n"
                      "Title: Pulp Fiction\n"
                      "Directed by Quentin Tarantino\n"
                      "\n"
                      "Type film: Documentary\n"
                      "Country: USA\n"
                      "Title: The Story of Queen: Mercury Rising\n"
                      "Year of release: 2011\n";

    FilmList *film_list = init_film_list();

    read_films_from_file(film_list, input_path);
    write_films_to_file(film_list, output_path);

    ifstream in_file(output_path);
    stringstream buffer;
    buffer << in_file.rdbuf();
    string real = buffer.str();

    assert(real == expected);

    cout << "Success test_sort_film_list" << endl;
}

void test_filter_film_list() {
    string input_path = "test_files/testFilterFilmList_in.txt";
    string output_path = "test_files/testFilterFilmList_out.txt";


    string expected = "Number of films: 2\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: USA, Germany\n"
                      "Title: 9\n"
                      "Type animation: Doll\n"
                      "\n"
                      "Type film: Cartoon\n"
                      "Country: UK, USA, France\n"
                      "Title: Chicken Run\n"
                      "Type animation: Clay\n";

    FilmList *film_list = init_film_list();

    read_films_from_file(film_list, input_path);
    write_films_to_file(film_list, output_path);

    ifstream in_file(output_path);
    stringstream buffer;
    buffer << in_file.rdbuf();
    string real = buffer.str();

    assert(real == expected);

    cout << "Success test_filter_film_list" << endl;
}

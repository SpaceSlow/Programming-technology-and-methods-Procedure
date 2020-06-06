//
// Created by garry on 02.06.2020.
//

#ifndef FILMLIST_H
#define FILMLIST_H

#include "Film.h"

using std::string;


struct FilmItem {
    Film *film;
    FilmItem *next_film;
};

struct FilmList {
    int size;
    FilmItem *first_film;
    FilmItem *last_film;
};

FilmList* init_film_list();
void add_film(FilmList *film_list, Film *film);
bool read_films_from_file(FilmList *film_list, string filename);
bool write_films_to_file(FilmList *film_list, string filename);
void sort_films_by_vowels_number(FilmList *film_list);

#endif //LAB1_PROCEDURE_FILMLIST_H

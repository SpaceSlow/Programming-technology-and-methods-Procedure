//
// Created by garry on 02.06.2020.
//
#include <fstream>

#include "FilmList.h"

using std::ifstream;
using std::ofstream;
using std::endl;


FilmList* init_film_list() {
    FilmList *film_list = new FilmList();
    film_list->size = 0;
    film_list->first_film = nullptr;
    film_list->last_film = nullptr;
    return film_list;
}

void add_film(FilmList *film_list, Film *film) {
    FilmItem *new_film_item = new FilmItem();
    new_film_item->film = film;
    new_film_item->next_film = nullptr;

    if (film_list->size == 0) {
        film_list->first_film = new_film_item;
    } else if (film_list->size == 1) {
        film_list->first_film->next_film = new_film_item;
        film_list->last_film = new_film_item;
    } else {
        film_list->last_film->next_film = new_film_item;
        film_list->last_film = new_film_item;
    }

    film_list->size++;
}

bool read_films_from_file(FilmList *film_list, string filename) {

    ifstream fin(filename);

    if (!fin.is_open()) {
        return false;
    }

    bool do_sort = false;
    int num_films;
    string tmp, sort_films, filter_films;
    getline(fin, tmp);
    num_films = stoi(tmp);

    getline(fin, sort_films);
    if (sort_films == "Sort") {
        do_sort = true;
    } else if (sort_films != "No sort") {
        return false;
    }

    getline(fin, filter_films);

    for (int i = 0; i < num_films; ++i) {
        Film *film = new Film();
        read_film_from_file(film, &fin);

        if (filter_films == "All" or filter_films == get_type_film(film)) {
            add_film(film_list, film);
        }

    }

    if (do_sort) {
        sort_films_by_vowels_number(film_list);
    }

    fin.close();
    return true;
}

bool write_films_to_file(FilmList *film_list, string filename) {

    ofstream fout(filename);

    fout << "Number of films: " << film_list->size << endl; // Ввод размера списка в файл

    if (!film_list->size) {
        fout.close();
        return true;
    }

    FilmItem *current_film_item = film_list->first_film; // инициализация текущего элемента списка

    for (int i = 0; i < film_list->size; ++i) {
        write_film_to_file(current_film_item->film, &fout);
        current_film_item = current_film_item->next_film;
    }

    fout.close();
    return true;
}

void sort_films_by_vowels_number(FilmList *film_list) {
    for(FilmItem* film_item2 = film_list->first_film; film_item2; film_item2 = film_item2->next_film) {
        for(FilmItem* film_item1 = film_list->first_film; film_item1->next_film; film_item1 = film_item1->next_film) {
            if(get_vowels_number_in_title(film_item1->film) > get_vowels_number_in_title(film_item1->next_film->film)) {
                std::iter_swap(&film_item1->film, &film_item1->next_film->film);
            }
        }
    }
}

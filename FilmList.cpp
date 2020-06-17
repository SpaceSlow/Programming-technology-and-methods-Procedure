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

    int num_films;
    string tmp, title, type_film, optional_field;
    getline(fin, tmp);
    num_films = stoi(tmp);

    for (int i = 0; i < num_films; ++i) {
        Film *film = new Film();
        read_film_from_file(film, &fin);
        add_film(film_list, film);
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

    multimethod(film_list, &fout);

    fout.close();
    return true;
}

void multimethod(FilmList *film_list, ofstream *fout) {
    *fout << endl << endl << "Multimethod" << endl;
    if (!film_list->size) {
        return;
    }

    for(FilmItem* film_item1 = film_list->first_film; film_item1->next_film; film_item1 = film_item1->next_film) {
        for(FilmItem* film_item2 = film_item1->next_film; film_item2; film_item2 = film_item2->next_film) {
            switch (film_item1->film->type_film)
            {
                case Film::typeFilm::FICTION:
                    switch (film_item2->film->type_film) {
                        case Film::typeFilm::FICTION:
                            *fout << "FICTION and FICTION" << endl;
                            break;
                        case Film::typeFilm::CARTOON:
                            *fout << "FICTION and CARTOON" << endl;
                            break;
                        default:
                            *fout << "FICTION and unknown type of film" << endl;
                            break;
                    }
                    break;

                case Film::typeFilm::CARTOON:
                    switch (film_item2->film->type_film) {
                        case Film::typeFilm::FICTION:
                            *fout << "CARTOON and FICTION" << endl;
                            break;
                        case Film::typeFilm::CARTOON:
                            *fout << "CARTOON and CARTOON" << endl;
                            break;
                        default:
                            *fout << "CARTOON and unknown type of film" << endl;
                            break;
                    }
                    break;
                default:
                    *fout << "Unknown type of film" << endl;
                    break;
            }
        }
    }
}

//
// Created by garry on 02.06.2020.
//

#ifndef FILM_H
#define FILM_H

#include <string>

using std::string;
using std::ifstream;
using std::ofstream;


struct Film {
    enum typeFilm {FICTION, CARTOON};
    Film() = default;

    string title;
    string country;
    typeFilm type_film;

    struct FictionFilm {
        string stage_director;
    } fiction_film;

    struct CartoonFilm {
        enum typeCartoon {CLAY, HAND_DRAWN, COMPUTER, DOLL};
        typeCartoon type_cartoon;
    } cartoon_film;
};

void read_film_from_file(Film *film, ifstream *fin);
void read_film_from_file(Film::FictionFilm *fiction_film, ifstream *fin);
void read_film_from_file(Film::CartoonFilm *cartoon_film, ifstream *fin);
void write_film_to_file(Film *film, ofstream *fout);
void write_film_to_file(Film::FictionFilm *fiction_film, ofstream *fout);
void write_film_to_file(Film::CartoonFilm *cartoon_film, ofstream *fout);
string get_type_cartoon(Film::CartoonFilm *cartoon_film);
string get_type_film(Film *film);

#endif //FILM_H

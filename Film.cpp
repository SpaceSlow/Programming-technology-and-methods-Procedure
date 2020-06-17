//
// Created by garry on 03.06.2020.
//

#include <fstream>

#include "Film.h"

using std::endl;


string get_type_cartoon(Film::CartoonFilm *cartoon_film) {

    switch (cartoon_film->type_cartoon) {
        case Film::CartoonFilm::CLAY:
            return "Clay";
        case Film::CartoonFilm::HAND_DRAWN:
            return "Hand Drawn";
        case Film::CartoonFilm::COMPUTER:
            return "Computer";
        case Film::CartoonFilm::DOLL:
            return "Doll";
        default:
            return "";
    }
}

void read_film_from_file(Film *film, ifstream *fin) {
    string tmp, type_film;
    getline(*fin, tmp);              // Пропуск пустой строки
    getline(*fin, type_film);         // Тип фильма
    getline(*fin, film->country);   // Страна, в которой выпустили фильм фильма
    getline(*fin, film->title);            // Название фильма

    if (type_film == "Fiction") {
        film->type_film = Film::FICTION;
        read_film_from_file(&film->fiction_film, fin);
    } else if (type_film == "Cartoon") {
        film->type_film = Film::CARTOON;
        read_film_from_file(&film->cartoon_film, fin);
    } else if (type_film == "Documentary") {
        film->type_film = Film::DOCUMENTARY;
        read_film_from_file(&film->documentary_film, fin);
    } else {
        throw "The input file contains an incorrect film type. See README.";
    }

}

void read_film_from_file(Film::FictionFilm *fiction_film, ifstream *fin) {
    getline(*fin, fiction_film->stage_director);
}

void read_film_from_file(Film::CartoonFilm *cartoon_film, ifstream *fin) {

    string type_cartoon;
    getline(*fin, type_cartoon);

    if (type_cartoon == "Clay") {
        cartoon_film->type_cartoon = Film::CartoonFilm::CLAY;
    } else if (type_cartoon == "Hand drawn") {
        cartoon_film->type_cartoon = Film::CartoonFilm::HAND_DRAWN;
    } else if (type_cartoon == "Computer") {
        cartoon_film->type_cartoon = Film::CartoonFilm::COMPUTER;
    } else if (type_cartoon == "Doll") {
        cartoon_film->type_cartoon = Film::CartoonFilm::DOLL;
    } else {
        throw "The input file contains an incorrect cartoon type. See README.";
    }
}

void read_film_from_file(Film::DocumentaryFilm *documentary_film, ifstream *fin) {
    string year_of_release;
    getline(*fin, year_of_release);
    int year = 0;
    try {
        year = stoi(year_of_release);
        if (std::to_string(year) != year_of_release) {
            throw std::invalid_argument("invalid argument");
        }
    } catch (const std::invalid_argument &msg) {
        throw "The input file contains an incorrect year for the documentary.";
    } catch (const std::out_of_range &msg) {
        throw "The input file contains a very large year for the documentary.";
    }

    documentary_film->year_of_release = year;
}

void write_film_to_file(Film *film, ofstream *fout) {
    string type_film, optional_string;

    *fout << endl; // Пустая строка для читабельности

    *fout << "Type film: " << get_type_film(film) << endl;
    *fout << "Country: " << film->country << endl;
    *fout << "Title: " << film->title << endl;

    switch (film->type_film) {
        case Film::FICTION:
            write_film_to_file(&film->fiction_film, fout);
            break;
        case Film::CARTOON:
            write_film_to_file(&film->cartoon_film, fout);
            break;
        case Film::DOCUMENTARY:
            write_film_to_file(&film->documentary_film, fout);
            break;
    }

}

void write_film_to_file(Film::FictionFilm *fiction_film, ofstream *fout) {
    *fout << "Directed by " + fiction_film->stage_director << endl;
}

void write_film_to_file(Film::CartoonFilm *cartoon_film, ofstream *fout) {
    *fout << "Type animation: " + get_type_cartoon(cartoon_film) << endl;
}

void write_film_to_file(Film::DocumentaryFilm *documentary_film, ofstream *fout) {
    *fout << "Year of release: " << documentary_film->year_of_release << endl;
}

string get_type_film(Film *film) {
    switch (film->type_film) {
        case Film::FICTION:
            return "Fiction";
        case Film::CARTOON:
            return "Cartoon";
        case Film::DOCUMENTARY:
            return "Documentary";
        default:
            return "";
    }
}

int get_vowels_number_in_title(Film *film) {
    string vowels = "aeiou";
    int vowels_count = 0;
    for (char symbol : film->title) {
        if (vowels.find(symbol) != -1) {
            vowels_count++;
        }
    }
    return vowels_count;
}

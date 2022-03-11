//
// Created by liuja on 17/02/2022.
//

#include "CD.h"

const string &CD::getArtist() const {
    return artist;
}

void CD::setArtist(const string &artist) {
    CD::artist = artist;
}

const string &CD::getTitle() const {
    return title;
}

void CD::setTitle(const string &title) {
    CD::title = title;
}

int CD::getYear() const {
    return year;
}

void CD::setYear(int year) {
    CD::year = year;
}

double CD::getPrice() const {
    return price;
}

void CD::setPrice(double price) {
    CD::price = price;
}

void CD::print(){
    cout << "Title: " << title << ", " << "Artist: " << artist << ", " << " made in " << year << ", " << "The price is " << price << endl;
}

CD::CD() {}

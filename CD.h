//
// Created by liuja on 17/02/2022.
//

#ifndef XMLPARSER_CD_H
#define XMLPARSER_CD_H

#include <string>
#include <iostream>
using namespace std;

class CD {
    string artist;
    string title;
    int year;
    double price;

public:
    const string &getArtist() const;

    CD();

    void setArtist(const string &artist);

    const string &getTitle() const;

    void setTitle(const string &title);

    int getYear() const;

    void setYear(int year);

    double getPrice() const;

    void setPrice(double price);

    void print();
};


#endif //XMLPARSER_CD_H

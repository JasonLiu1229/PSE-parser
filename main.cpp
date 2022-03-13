#include <iostream>
#include "tinyxml.h"
#include <string>
#include "CD.h"
#include<cstdlib>
#include <vector>
#include <stdexcept>

int main(){
    TiXmlDocument doc;
    // intro
    try{
        if(!doc.LoadFile("eenCDError.xml")) {
            std::cerr << doc.ErrorDesc() << std::endl;
            throw 1;
        }
    }

    catch(int error){
        if(error == 1){
            std::cout << "File not readable" << std::endl;
            return 0;
        }
    }

    TiXmlElement* root = doc.FirstChildElement();

    if(root == NULL) {
        std::cerr << "Failed to load file: No root element." << std::endl;
        doc.Clear();
        return 1;
    }

    // intro oefening
    /*for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        std::string elemName = elem->Value();

        const char *attr;
        // searching for a specific attribute of a element
        if (elemName == "Element1") {
            attr = elem->Attribute("attribute1");
            if (attr != NULL){
                std::cout << attr << std::endl;
            }// Do stuff with it
        }
        // different elements and attributes
        else if(elemName == "Element2") {
            attr = elem->Attribute("attribute2");
            if (attr != NULL){
                std::cout << attr << std::endl;
            } // Do stuff with it
            attr = elem->Attribute("attribute3");
            if (attr != NULL){
                std::cout << attr << std::endl;
            } // Do stuff with it
        }

        // searching through every element, to find a specific attribute
        for(TiXmlElement* e = elem->FirstChildElement("Element3"); e != NULL; e = e->NextSiblingElement("Element3")){
            attr = e->Attribute("attribute4");
            if(attr != NULL){
                std::cout << attr << std::endl;
            } // Do stuff with it
        }

        // converting atribute data to string
        for(TiXmlNode* e = elem->FirstChild(); e != NULL; e = e->NextSibling()){
            TiXmlText* text = e->ToText();
            if(text == NULL)
                continue;
            std::string t = text->Value(); // Do stuff
            std::cout << t << std::endl;
        }
    }*/

    // oefening 1
    /*for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()){
        std::string elemName = elem->Value();

        const char *attr;
        if(elemName == "TITLE"){
            std::cout << elem->GetText() << std::endl;
        }
        if(elemName == "ARTIST"){
            std::cout << elem->GetText() << std::endl;
        }
    }*/

    // oef 2
    /*CD cd;

    for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
        std::string elemName = elem->Value();

        if (elemName == "TITLE") {
            cd.setTitle(elem->GetText());
        }
        if (elemName == "ARTIST") {
            cd.setArtist(elem->GetText());
        }
        if (elemName == "YEAR"){
            cd.setYear(atoi(elem->GetText()));
        }
        if (elemName == "PRICE"){
            cd.setPrice(atof(elem->GetText()));
        }
    }
    cd.print();*/

    // oef 3
    /*vector<CD> catalog;
    for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()){
            CD cd;
            for (TiXmlElement *nestedElem = elem->FirstChildElement();
                 nestedElem != NULL; nestedElem = nestedElem->NextSiblingElement()) {
                std::string elemName = nestedElem->Value();
                if (elemName == "TITLE") {
                    cd.setTitle(nestedElem->GetText());
                }
                if (elemName == "ARTIST") {
                    cd.setArtist(nestedElem->GetText());
                }
                if (elemName == "YEAR") {
                    cd.setYear(atoi(nestedElem->GetText()));
                }
                if (elemName == "PRICE") {
                    cd.setPrice(atof(nestedElem->GetText()));
                }
            catalog.push_back(cd);
        }
    }
    for (auto Cd : catalog){
        Cd.print();
    }*/

    // oef 4
    // a

    CD cd;
    std::string temp;
    try{
        for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement()) {
            std::string elemName = elem->Value();
            if (elemName == "TITLE") {
                if(elem->GetText() != 0){
                    cd.setTitle(elem->GetText());
                    continue;
                }
                else{
                    throw 1;
                }
            }
            if (elemName == "ARTIST") {
                if(elem->GetText() != 0){
                    cd.setArtist(elem->GetText());
                    continue;
                }
                else{
                    throw 2;
                }

            }
            if (elemName == "YEAR"){
                if(elem->GetText() != 0){
                    cd.setYear(atoi(elem->GetText()));
                    continue;
                }
                else{
                    throw 3;
                }

            }
            if (elemName == "PRICE"){
                if(elem->GetText() != 0){
                    cd.setPrice(atof(elem->GetText()));
                    continue;
                }
                else{
                    throw 4;
                }
            }
            if (elemName == "COUNTRY"){
                if(elem->GetText() != 0){
                    continue;
                }
                else{
                    throw 5;
                }
            }
            if (elemName == "COMPANY"){
                if(elem->GetText() != 0){
                    continue;
                }
                else{
                    throw 6;
                }
            }
            if (elemName != "COUNTRY" and elemName != "YEAR" and elemName != "TITLE" and elemName != "ARTIST" and elemName != "PRICE" and elemName != "COMPANY"){
                throw 7;
            }
        }
        cd.print();
    }
    catch(int error){
        switch (error) {
            case 1:
                std::cout << "No title found";
                break;
            case 2:
                std::cout << "No artist found";
                break;
            case 3:
                std::cout << "No year found";
                break;
            case 4:
                std::cout << "No price found";
                break;
            case 5:
                std::cout << "No country found";
                break;
            case 6:
                std::cout <<  "No company found";
                break;
            case 7:
                std::cout << "Element name not found";
                break;
        }
    }
    doc.Clear();
}

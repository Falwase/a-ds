
#ifndef PATRON_CPP
#define PATRON_CPP

#include "Document.cpp"
#include <vector>

class Patron {

private:
    int patronID;

public:
    Patron(int patronID) {
        this->patronID = patronID;
    }
    int getId() {
        return patronID;
    }
    std::vector<Document> bookList;

};

#endif

#ifndef DOCUMENT_CPP
#define DOCUMENT_CPP

#include <string>

class Document {
private:
    std::string name;
    int id;
    int license_limit;
    int copies;

public:
    Document(std::string name, int id, int license_limit) {
        this->name = name;
        this->id = id;
        this->license_limit = license_limit;
        copies = 0;
    }

    std::string getName() {
        return name;
    }

    int getId() {
        return id;
    }

    bool full() {

        if (copies >= license_limit) {
            return true;
        }

        return false;
    }

    void borrow() {
        copies += 1;
    }
};

#endif
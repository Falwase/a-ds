
#include "DocumentManager.h"

DocumentManager::DocumentManager() {

} //contructor

void DocumentManager::addDocument(string name, int id, int license_limit) {

    lib.push_back(Document(name, id, license_limit));
}

void DocumentManager::addPatron(int patronID) {

    users.push_back(Patron(patronID));
}

int DocumentManager::search(string name) {

    for(int i = 0; i < lib.size(); i++) {
        if (lib[i].getName() == name) {
            return lib[i].getId();
        }
    }

    return 0;
} // returns docid if name is in the document collection or 0 if the name is not in the collection

bool DocumentManager::borrowDocument(int docid, int patronID) {

    //check for patron
    int patronIndex = 0;
    for (int i = 0; i < users.size(); i++) {
        if(patronID == users[i].getId()) {
            patronIndex = i;
            continue;
        }
    }
    if (patronIndex == 0) {
        return false;
    }

    //check for document
    int libIndex = 0;
    for (int i = 0; i < lib.size(); i++) {
        if(docid == lib[i].getId()) {
            libIndex = i;
            continue;
        }
    }
    if (libIndex == 0) {
        return false;
    }

    //checks for licesence limit
    if (lib[libIndex].full()) {
        return false;
    }

    users[patronIndex].bookList.push_back(lib[libIndex]);
    lib[libIndex].borrow();

}  // returns true if document is borrowed, false if it can not be borrowed (invalid patronid or the number of copies current borrowed has reached the license limit)

void DocumentManager::returnDocument(int docid, int patronID) {

    //check for patron
    int patronIndex = 0;
    for (int i = 0; i < users.size(); i++) {
        if(patronID == users[i].getId()) {
            patronIndex = i;
            continue;
        }
    }
    if (patronIndex == 0) {
        return false;
    }

    //check for document
    int libIndex = 0;
    for (int i = 0; i < lib.size(); i++) {
        if(docid == lib[i].getId()) {
            libIndex = i;
            continue;
        }
    }
    if (libIndex == 0) {
        return false;
    }
}
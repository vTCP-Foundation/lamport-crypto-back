#ifndef LAMPORTC_VALIDATIONS_HPP
#define LAMPORTC_VALIDATIONS_HPP


#include <string>
#include "errors.hpp"


using namespace std;


void failIfLessThan(const int i, const int k, const string &message) {
    if (i < k) {
        fatal(message);
    }
}

void failIfEmpty(const string &data, const string &message) {
    if (data.empty()) {
        fatal(message);
    }
}

void failIfNUllptr(void *data, const string &message) {
    if (data == nullptr) {
        fatal(message);
    }
}


#endif //LAMPORTC_VALIDATIONS_HPP

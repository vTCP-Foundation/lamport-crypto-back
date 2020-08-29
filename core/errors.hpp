#ifndef LAMPORTC_ERRORS_HPP
#define LAMPORTC_ERRORS_HPP

#include <string>
#include <stdexcept>


using namespace std;


void fatal(const string &message) {
    throw runtime_error(message);
}

#endif //LAMPORTC_ERRORS_HPP

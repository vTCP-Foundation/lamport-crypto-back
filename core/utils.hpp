#ifndef LAMPORTC_UTILS_HPP
#define LAMPORTC_UTILS_HPP

#include "validations.hpp"

#include <iostream>
#include <cstdint>
#include <vector>
#include <memory>
#include <cstring>

#include "../lib-crypto-lamport/src/lamportkeys.h"
#include "../lib-crypto-lamport/src/lamportscheme.h"


using namespace std;
using namespace crypto::lamport;

shared_ptr<vector<uint8_t>> readFileOrFail(const string &filename, const size_t expectedSize) {
    failIfEmpty(filename, "empty hash filename is not allowed");

    auto file = fopen(filename.c_str(), "rb");
    failIfNUllptr(file, "cant open file " + filename);

    auto container = make_shared<vector<uint8_t>>();
    container->reserve(expectedSize);

    if (fread(container->data(), expectedSize, 1, file) != 1 ) {
        fatal("cant read file " + filename);
    }

    fclose(file);
    return container;
}

void writeFileOrFail(const string &filename, void *data, const size_t size) {
    auto file = fopen(filename.c_str(), "wb");
    if (fwrite(data, size, 1, file) != 1) {
        fatal(strerror(errno));
    }

    fclose(file);
}



#endif //LAMPORTC_UTILS_HPP

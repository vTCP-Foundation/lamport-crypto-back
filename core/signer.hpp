#ifndef LAMPORTC_SIGNER_HPP
#define LAMPORTC_SIGNER_HPP

#include "utils.hpp"
#include "../lib-crypto-lamport/src/lamportkeys.h"
#include "../lib-crypto-lamport/src/lamportscheme.h"
#include "errors.hpp"
#include "validations.hpp"


using namespace crypto::lamport;


int SignHash(int argc, const char* argv[]) {
    failIfLessThan(argc, 5,
"Required amount of arguments is 3: hash filename, private key filename, result sig filename");

    string hashFilename = argv[2];
    auto hash = readFileOrFail(hashFilename, BLAKE2KeyHash::kBytesSize);

    string privateKeyFilename = argv[3];
    auto privateKey = readFileOrFail(privateKeyFilename, PrivateKey::kKeySize());

    PrivateKey pKey(reinterpret_cast<crypto::byte*>(privateKey->data()));
    Signature signature(reinterpret_cast<crypto::byte*>(hash->data()), BLAKE2KeyHash::kBytesSize, &pKey);

    string sigFilename = argv[4];
    writeFileOrFail(sigFilename + ".sig", (void*)signature.data(), Signature::kSize);

    return 0;
}

#endif //LAMPORTC_SIGNER_HPP

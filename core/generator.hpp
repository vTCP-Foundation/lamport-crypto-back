#ifndef LAMPORTC_GENERATOR_HPP
#define LAMPORTC_GENERATOR_HPP

#include "../lib-crypto-lamport/src/lamportkeys.h"
#include "validations.hpp"

#include <stdexcept>


using namespace std;
using namespace crypto::lamport;


int GenerateNewKeyPair(int argc, const char* argv[]) {
    failIfLessThan(argc, 2,
"Required amount of arguments is 1: filename for pair of keys to be generated");

    string keysPairName = argv[2];
    failIfEmpty(keysPairName, "key pair should not be empty");

    PrivateKey pKey;
    {
        auto guard = pKey.data()->unlockAndInitGuard();
        writeFileOrFail(keysPairName + string(".pkey"), guard.address(), PrivateKey::kKeySize());
    }

    auto pubKey = pKey.derivePublicKey();
    writeFileOrFail(keysPairName + string(".pubkey"), (void*)pubKey->data(), PublicKey::kKeySize());

    return 0;
}

#endif //LAMPORTC_GENERATOR_HPP

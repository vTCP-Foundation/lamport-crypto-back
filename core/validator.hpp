#ifndef LAMPORTC_VALIDATOR_HPP
#define LAMPORTC_VALIDATOR_HPP



#include "utils.hpp"
#include "validations.hpp"


using namespace std;


int VerifyHash(int argc, const char* argv[]) {
    failIfLessThan(argc, 5,
       "Required amount of arguments is 3: hash filename, signature filename, pubkey filename");

    string hashFilename = argv[2];
    auto binaryHash = readFileOrFail(hashFilename, BLAKE2KeyHash::kBytesSize);

    string sigFilename = argv[3];
    auto binarySignature = readFileOrFail(sigFilename, Signature::kSize);

    string publicKeyFilename = argv[4];
    auto binaryPublicKey = readFileOrFail(publicKeyFilename, PublicKey::kKeySize());

    auto pubKey = make_shared<PublicKey>(reinterpret_cast<crypto::byte*>(binaryPublicKey->data()));
    Signature signature(reinterpret_cast<crypto::byte*>(binarySignature->data()));

    if (signature.check(
            reinterpret_cast<crypto::byte*>(binaryHash->data()),
            BLAKE2KeyHash::kBytesSize,
            pubKey)) {

        return 0;
    }

    return -1;
}

#endif // LAMPORTC_VALIDATOR_HPP
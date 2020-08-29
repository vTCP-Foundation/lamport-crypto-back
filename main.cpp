// todo: add licence here and in other files


#include "core/validator.hpp"
#include "core/generator.hpp"
#include "core/signer.hpp"
#include "core/modes.hpp"

#include <sodium.h>


int main(int argc, const char* argv[]) {
    auto ok = sodium_init();
    if (ok != 0) {
        throw runtime_error("can't init sodium");
    }

    if (modeIsSetToVerification(argc, argv)) {
        return VerifyHash(argc, argv);

    } else if (modeIsSetToSigning(argc, argv)) {
        return SignHash(argc, argv);

    } else if (modeIsSetToKeypairGeneration(argc, argv)) {
        return GenerateNewKeyPair(argc, argv);

    }

    throw runtime_error("unexpected execution mode");
}


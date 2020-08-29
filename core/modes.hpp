#ifndef LAMPORTC_MODES_HPP
#define LAMPORTC_MODES_HPP

#include <cstring>


static const char *modeVerifier = "verify";
static const char *modeSigner    = "sign";
static const char *modeGenerator    = "generate";


bool modeIsSetToVerification(int argc, const char **argv) {
    if (argc < 2) {
        return false;
    }

    return strcmp(argv[1], modeVerifier) == 0;
}

bool modeIsSetToSigning(int argc, const char* argv[]) {
    if (argc < 2) {
        return false;
    }

    return strcmp(argv[1], modeSigner) == 0;
}

bool modeIsSetToKeypairGeneration(int argc, const char **argv) {
    if (argc < 2) {
        return false;
    }

    return strcmp(argv[1], modeGenerator) == 0;
}




#endif //LAMPORTC_MODES_HPP

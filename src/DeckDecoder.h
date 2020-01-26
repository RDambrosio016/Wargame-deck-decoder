#ifndef WARGAME_DECK_DECODER_DECKDECODER_H
#define WARGAME_DECK_DECODER_DECKDECODER_H

#include <string>
#include <vector>
#include "BinConverter.h"
#include <unordered_map>
#include <stdexcept>

class ParseError : public std::runtime_error {
public:
    explicit ParseError(const std::string &msg)
        : std::runtime_error(msg)
    {};
};

typedef struct deckMetadata {
    std::string faction;
    std::string country;
    std::string specialization;
    char era; //one of A, B, or C

    std::string to_string() {
        return "Faction: " + faction + "\nCountry: " + country + "\nSpecialization: " + specialization;
    }
} deckMetadata;

class DeckDecoder {
public:
    uint16_t header;
    std::vector<BYTE> code;

    explicit DeckDecoder(std::string codeStr);
    deckMetadata decodeMetadata();

    static uint16_t getBits(const uint16_t &byte, int numBits, int position);

private:
    std::string decodeFaction();
    std::string decodeCountry(std::string &faction);
    std::string decodeSpecialization();
    std::string decodeEra();

    static std::string printBits(const uint16_t &bits);
    void throwError(std::string &message);
};

#endif //WARGAME_DECK_DECODER_DECKDECODER_H

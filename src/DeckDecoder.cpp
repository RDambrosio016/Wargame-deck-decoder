/**
 * Decodes deck codes into the units they represent.
 *      1           2
 * [01|010101] [0101|010|1] [0|1010101]
 * ^        Header      ^^era^
 *
 * [2 bits]:
 * Faction, 00 for BLUFOR, 01 for REDFOR
 *
 * [10 bits]:
 * The country the deck represents
 *
 * [3 bits]:
 * The specialization of the deck
 *
 * [2 bits]:
 * The era of the deck
 */

#include "DeckDecoder.h"
#include "BinConverter.h"
#include "Constants/constants.cpp"
#include <algorithm>
#include <iostream>
#include <bitset>
#include <exception>

DeckDecoder::DeckDecoder(std::string codeStr) {
    if(codeStr[0] == '@') codeStr = codeStr.erase(0, 1);
    code = BinConverter::decode(codeStr);
    header = (code[0] << 8) | code[1];
}

deckMetadata DeckDecoder::decodeMetadata() {
    std::string deckFaction = decodeFaction();
    const std::string country = decodeCountry(deckFaction);
    std::string specialization = decodeSpecialization();
    decodeEra();
    deckMetadata data = {
            deckFaction,
            country,
            specialization
    };
    return data;
}

std::string DeckDecoder::decodeFaction() {
    bool faction = getBits(header, 2, 14);
    return faction == 1 ? "REDFOR" : "BLUFOR";
}

std::string DeckDecoder::decodeCountry(std::string &faction) {
    std::unordered_map<uint8_t, std::string> countries_map = faction == "REDFOR" ? Constants::REDFOR_COUNTRIES : Constants::BLUFOR_COUNTRIES;

    auto iter = countries_map.find(getBits(header, 10, 5));

    if(iter == countries_map.cend()) throw ParseError("invalid deck code: invalid country");
    return iter->second;
}

std::string DeckDecoder::decodeSpecialization() {
    uint8_t specializationBits = getBits(header, 3, 12);
    auto iter = Constants::SPECIALIZATIONS.find(specializationBits);

    if(iter == Constants::SPECIALIZATIONS.cend()) throw ParseError("invalid deck code: Invalid specialization");
    return iter->second;
}

std::string DeckDecoder::decodeEra() {
    const uint8_t eraBits = (getBits(header, 1, 1) << 1) | getBits(code[2], 1, 7);
    auto iter = Constants::ERAS.find(eraBits);

    if(iter == Constants::ERAS.cend()) throw ParseError("invalid deck code: invalid era");
    return iter->second;
}

uint16_t DeckDecoder::getBits(const uint16_t &byte, int numBits, int position) {
    return (((1 << numBits) - 1) & (byte >> (position - 1)));
}

std::string DeckDecoder::printBits(const uint16_t &bits) {
    const std::string bitString = std::bitset<16>(bits).to_string();
    std::cout << bitString << " - " << bits << std::endl;
    return bitString;
}




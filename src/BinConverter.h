#ifndef WARGAME_DECK_DECODER_BINCONVERTER_H
#define WARGAME_DECK_DECODER_BINCONVERTER_H

#include <vector>
#include <string>

typedef uint8_t BYTE;

class BinConverter {
public:
    static const std::string base64_chars;

    static bool is_base64(BYTE c);
    static std::string encode(const std::vector<BYTE>&);
    static std::vector<BYTE> decode(const std::string&);
};

#endif //WARGAME_DECK_DECODER_BINCONVERTER_H

#include <iostream>
#include "src/BinConverter.h"
#include "src/DeckDecoder.h"
#include <chrono>

typedef std::chrono::steady_clock steady_clock;

int main() {
    steady_clock::time_point begin = steady_clock::now();

    DeckDecoder decoder = DeckDecoder("@AM8CSgdURG2SFtBHM0EoPaCUHtkg5iTtHqG+j1AyVESeknaKARLIraK3EgowhKWi/osRbGkblZiKiSilpoYuUmknhKKWvRZyWnFlpQSU+A==");
    deckMetadata metadata = decoder.decodeMetadata();

    steady_clock::time_point end = steady_clock::now();
    std::cout << metadata.to_string() << "\nTook: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;
    return 0;
}

#include <cstdint>
#include <unordered_map>

namespace Constants {
    const std::unordered_map<uint8_t, std::string> BLUFOR_COUNTRIES = {
            {12, "USA"},
            {44, "UK"},
            {76, "FRANCE"},
            {108, "WEST_GERMANY"},
            {140, "CANADA"},
            {172, "DENMARK"},
            {204, "SWEDEN"},
            {236, "NORWAY"},
            {268, "ANZAC"},
            {300, "JAPAN"},
            {332, "ROK"},
            {364, "NETHERLANDS"},
            {396, "ISRAEL"},
            {480, "EUROCORPS"},
            {481, "SCANDI"},
            {482, "COMMONWEALTH"},
            {483, "BLUE_DRAGONS"},
            {486, "LANDJUT"},
            {488, "NORAD"},
            {489, "DGC"},
            {492, "BLUFOR"}
    };

    const std::unordered_map<uint8_t, std::string> REDFOR_COUNTRIES = {
            {12, "EAST_GERMANY"},
            {44, "USSR"},
            {76, "POLAND"},
            {108, "CZECH"},
            {140, "CHINA"},
            {172, "NORTH_KOREA"},
            {204, "FINLAND"},
            {236, "YUGOSLAVIA"},
            {292, "RED_DRAGONS"},
            {293, "EASTERN_BLOC"},
            {298, "BALTIC_FRONT"},
            {299, "ENTENTE"},
            {300, "REDFOR"}
    };

    const std::unordered_map<uint8_t, std::string> SPECIALIZATIONS = {
            {0, "MOTORIZED"},
            {1, "ARMORED"},
            {2, "SUPPORT"},
            {3, "MARINE"},
            {4, "MECHANIZED"},
            {5, "AIRBORNE"},
            {6, "NAVAL"},
            {7, "NONE"}
    };

    const std::unordered_map<uint8_t, std::string> ERAS = {
            {0, "1985"},
            {1, "1980"},
            {2, "NONE"}
    };
}

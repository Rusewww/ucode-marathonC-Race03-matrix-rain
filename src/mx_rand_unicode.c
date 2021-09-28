#include "../inc/header.h"

wchar_t mx_get_random_jp() {
    //return 35 + (rand() % 70);
    wchar_t alphabet[] = {L"゠ァアィイゥウェエォオカガキギクグケゲコゴサザシジスズセゼソゾタ"
                            "ダチヂッツヅテデトドナニヌネノハバパヒビピフブプヘベペホボポマミ"
                            "ムメモャヤュユョヨラリルレロヮワヰヱヲンヴヵヶヷヸヹヺ・ーヽヾヿ"};
    return alphabet[rand() % 96];
}

wchar_t mx_get_random_russ() {
    //return 35 + (rand() % 70);
    wchar_t alphabet[] = {L"АаБбВвГгДдЕЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯя"};
    return alphabet[rand() % 65];
}

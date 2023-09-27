#include <cstdlib>

using namespace std;

/*
 * Определите тип Incognizable, для которого следующий код будет корректен:
 * int main() {
 *   Incognizable a;
 *   Incognizable b = {};
 *   Incognizable c = {0};
 *   Incognizable d = {0, 1};
 *   return 0;
 * }
 */

struct Incognizable {
  int x = 0;
  int y = 0;
};

int main(int argc, char** argv) {
    Incognizable a; //  констр-р по умолчанию
    Incognizable b = {};    //  тоже констр-р по умолчанию
    Incognizable c = {0};   //  задается первое поле стр-ры, другое поле задается по умолчанию
    Incognizable d = {0, 1};

    return 0;
}


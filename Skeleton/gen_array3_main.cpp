/**
 * \file gen_array3_main.cpp
 *
 * Egyszerű tesztprogram a Jporta "NHF 3. Skeleton" feladatának bemutatásához.
 *
 * Feladat:
 *   Fix méretű Generikus tömb megvalósítása.
 * A tesztprogramnak az interfész bemutatásakor még nem kell működnie, csak fordulnia kell.
 * Itt egy kicsit részletesebben adjuk meg a tesztprogramot, hogy ötletet adjunk a teszteléshez.
 * A teszteléshez kézenfekvőnek tűnhet template függvény használata.
 */
#include <iostream>
#include <stdexcept>
#include <string>
#include "gen_array3.hpp"           // sablon

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

/// Saját kivételosztály a teszthez.
class BajVan {
public:
    /// @param - nem használjuk semmire
    BajVan(const string&) {}
};


/// TESZT 1.
void test_1() {
    Array<int> arr;                 // default (50) elemű int tömb
    int idx;
    int val;
    cout << "default (50) elemu int tomb" << endl;
    while ( cin >> idx >> val) {
      arr[idx] = val;
      cout << "arr[" << idx << "]=" << arr[idx] << endl;
    }
}

/// TESZT 2
void test_2() {
    Array<double, 100> arr;         // 100 elemű double tömb
    int idx;
    double val;
    cout << "100 elemu double tomb" << endl;
    while ( cin >> idx >> val) {
      arr[idx] = val;
      cout << "arr[" << idx << "]=" << arr[idx] << endl;
    }
}

/// TESZT 3
void test_3() {
    Array<string, 11, BajVan> arr;  // 11 elemű sztring saját kivétellel
    int idx;
    string val;
    cout << "11 elemu sztring saját kivetellel" << endl;
    while ( cin >> idx >> val) {
      arr[idx] = val;
      cout << "arr[" << idx << "]=" << arr[idx] << endl;
    }
}

/// Főprogram a standard inputról olvas egy egész számot, majd
/// meghivja az annak megfelelő tesztesetet.
/// A további inputot és outputot a teszteset kezeli.
int main() {
    try {
      int nr;
      cin >> nr;        // hanyadik teszt eset
      switch (nr) {
        case 1:
            test_1();   // default (50) elemű int tömb
        break;

        case 2:
            test_2();   // 100 elemű double tömb
        break;

        case 3:
            test_3();   // 11 elemű sztring saját kivételosztállyal
        break;
      }
    // kivétel elkapása
    } catch (std::exception& e) {
        cerr << e.what() << endl;
    } catch (BajVan&) {
        cerr << "Sajat kivetel jott" << endl;
    } catch (...) {
        cerr << "*** Nagy baj van! ****" << endl;
    }
	return 0;
}

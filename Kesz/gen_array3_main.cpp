/**
 * \file gen_array3_main.cpp
 *
 * Egyszerű tesztprogram a jporta NHF példafeladat bemutatásához.
 *
 * Feladat:
 *   Fix méretű Generikus tömb megvalósítása.
 *
 * A mintaprogram lokális nyelvi környezetet is állít a magyar ékezetes
 * szövegek megjelenítéséhez.
 * Az ékezetes szövegkonstansok a duma_u8.h és a duma_latin.h fájlokban vannak.
 * A megoldás fordításidejű, és csak egy gyenge próbálkozás, melynek lényege:
 *  - A program minden a szövegkonstansokra makrókkal (#define) defininiált azonosítókkal
 *    hivatkozik pl: cout << T_DUMA1 << endl;
 *  - A makrók két külön fájlban vannak definiálva. At egyikben latin2, a maikban UTF-8 kódolással.
 *  - Attól függően, hogy a fordítás WinX, vagy más rendszerben történik, latin2 kódolású fájl
 *    include-olja, vagy az UTF-8-as kódolásút.
 *
 * Ez a fajta megoldás akár nyelvek közötti váltásra is alkalmas, de az igazi rendes megoldás
 * futásidőben cseréli le szövegkonstansokat a megfelelő nyelvűre.
 * Ilyen pl. a GNU gettext, ami egy komplex, jól használható megoldást ad a problémára.
 *
 * A jelenlegi WinX rendszerek magyar nyelvi beállítással a 1250-es kódlapot használják,
 * ami lényegében latin2.
 * A helyes megjelenéshez magyar Windows alatt az 1250-es kódlapot kell
 * beállítani:
 *   regedit:
 *     [HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage]
 *        OEMCP=1250
 *    Ezen felül az output képernyő fontkészletét Lucida Console típusúra kell
 *    állítani.
 *
 * Linux/UNIX: A modern Linuxok UTF-8-as kódolást használnak alapból: ha a
 * fájlt így mentjük, helyesen fognak megjelenni az ékezetek. (Például
 * LANG=hu_HU.UTF8 beállításokkal.)
 *
 * Linux/UNIX rendszerekben az export LANG=hu_HU paranccsal lehet az adott
 * parancsértelmező számára megadni a használandó locale-t. Ebben az esetben
 * ISO-8859-2 (más néven latin2) kódolással kell a fájlt menteni.
 *
 * Jporta: UTF-8 kódolású fájlokat érdemes használni, ha fontos a helyes
 * ékezetes megjelenítés.
 *
 * Egy fájl karakterkódolása egyszerűen váltható az iconv programmal,
 * a CodeBlocks editorával, vagy pl. a notepad++ programmal.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <locale>
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
  #define WINX
  #include <windows.h>
#endif

#include "memtrace.h"
#include "gen_array3.hpp"           // sablon
#include "cross_platform.h"

#ifdef WINX
  #include "duma_latin.h"
#else
  #include "duma_u8.h"
#endif // WINX


//#define JPORTA_INPUT_SIM  // Jporta std in szimuláció

using std::cout;
using std::endl;
using std::cin;
using std::cerr;
using std::string;

/// Saját kivételosztály a teszthez.
class BajVan {
public:
    /// @param - nem használjuk semmire
    BajVan(const string&) {}
};


/// TESZT 4
/// Adatfájl beolvasásának bemutatásához.
/// Csak demó nincs funkciója ebben a feladatban.
void test_4() {

    // A mintafeladat bemutatja az ékezetes karakterek megjelenítését is:
    cout << T_DUMA1 << endl;


    std::fstream os;                        // file stream
    os.exceptions(std::ifstream::badbit);   // file kezelési hiba esetén dobjon kivétel

    // Most beolvassuk a valami_adat.dat fájlt"
    cout << T_ADAT1 << endl;
    // fájl megnyitása
    os.open("valami_adat.dat", std::fstream::in);

    // beolvasás
    string line;
    while (getline(os, line)) {
       cout << "len:" << line.size() << " " << line << endl;
       memtrace::mem_dump(line.c_str(), line.size(), stdout);
    }
    // fájl lezárása
    os.close();

    // Most beolvassuk újra, de cross-platform getline-nal
    cout << T_ADAT2 << endl;
    // fájl megnyitása
    os.open("valami_adat.dat", std::fstream::in);

    // beolvasas
    while (cp::getline(os, line)) {
       cout << "len:" << line.size() << " " << line << endl;
       memtrace::mem_dump(line.c_str(), line.size(), stdout);
    }
    // fájl lezárása
    os.close();

    // Most beírunk a T_BEIRT_TXT szöveget a fájlba
    cout << T_BEIR << endl;
    // fájl megnyitása írásra
    os.open("valami_adat2.dat", std::fstream::out);

    // Kiírás
    os << T_BEIR_TXT << endl;

    // Most beolvassuk a valami_adat2.dat fájlt"
    cout << T_ADAT3 << endl;
    // fájl megnyitása

    os.close();
    os.open("valami_adat2.dat", std::fstream::in);

    // beolvasás
    // Itt nem fontos (nem is hiba) a cp:getline, mert a környezet
    //    kompatibilis saját magával (reméljük)
    while (getline(os, line)) {
       cout << "len:" << line.size() << " " << line << endl;
       memtrace::mem_dump(line.c_str(), line.size(), stdout);
    }
    os.close();
}

/// TESZT 1
/// standard inputról beolvas egy darabszámot
/// majd számpárokat, akol az első szám az index, a második az érték.
void test_1() {
    Array<int> arr;                 // default (50) elemű int tömb
    cout << T_INT50;
    int sorok;
    (cin >> sorok).ignore(200, '\n'); // elddobjuk az esetleges kommentet
    int i = 0, idx, value;
    while (i++ < sorok && cin >> idx >> value) {
        arr[idx] = value;
        cout << "arr[" << idx << "]=" << arr[idx] << endl;
    }
}

/// TESZT 2
/// standard inputról beolvas egy darabszámot
/// majd számpárokat, akol az első szám az index, a második az érték.
void test_2() {
    Array<double, 100> darr;        // 100 elemű double tömb
    cout << T_DOUBLE100;
    int sorok;
    (cin >> sorok).ignore(200, '\n'); // eldobjuk az esetleges kommentet
    int i = 0, idx;
    double value;
    while (i++ < sorok && cin >> idx >> value) {
        darr[idx] = value;
        cout << "darr[" << idx << "]=" << darr[idx] << endl;
    }
}

/// TESZT 3
/// standard inputról beolvas egy darabszámot
/// majd egy idexet és a sor végéig eg stringet
void test_3() {
    Array<string, 11, BajVan> sarr;  // 11 elemű sztring saját kivétellel
    cout << T_STRING11;
    int sorok;
    (cin >> sorok).ignore(200, '\n'); // eldobjuk az esetleges kommentet
    int i = 0, idx;
    string value;
    while (i++ < sorok && cin >> idx && getline(cin, value)) {
        sarr[idx] = value;
        cout << "sarr[" << idx << "]=" << sarr[idx] << endl;
    }
}

/// Főprogram a standard inputról olvas egy egész számot, majd
/// meghívja az annak megfelelő tesztesetet.
/// A további bemenetet és kimenetet a tesztesetek kezelik.
int main() {
    char *p = setlocale(LC_ALL, "");  // a rendszer környezeti változójában megadott nyelvi környezet beállítása
    string loc;
    if (p != NULL)
	loc = p;
    cout << "Locale: " << loc << endl;
    #ifdef WINX
      if (loc.find("1250") == string::npos) {
        cout << T_NEM1250;
      }
      /// a CP1250 latin2-nek felel meg.
      /// WinX alatt nem sikerült találnom működő utf8-as kódlapot
      SetConsoleCP(1250);
      SetConsoleOutputCP(1250);
    #else
      if (loc.find("UTF-8") == string::npos && loc.find("utf8") == string::npos) {
        cout << T_NEMUTF;
      }
    #endif

/// Jporta std in szimuláció
#ifdef JPORTA_INPUT_SIM
    // Ha definiált, akkor a standard_input.txt nevű fájlból veszi az inputot.
    // Ez az a fájl, amit a Jporta rendszerbe a minta feladatban feltöltünk mint std. in.
    std::ifstream in("standard_input.txt");
    std::cin.rdbuf(in.rdbuf());     // cin mostantól az in-ből olvas
#endif // JPORTASIM


    // Teszteset sorszáma
    cout << T_TNR;
    int nr;
    while (cin >> nr && nr > 0) {    // hanyadik teszteset
        // A sorszám után komment is lehet a sor végéig.
        string megj;
        getline(cin, megj);
        cout << endl << nr << ". teszteset: " << megj << endl;
        try {
            switch (nr) {
                case 4:
                    test_4();   // txt fájl kezelését bemutató demó
                break;

                case 1:
                    test_1();   // default (50) elemű int tömb
                break;

                case 2:
                    test_2();   // 100 elemű double tömb
                break;

                case 3:
                    test_3();   // 11 elemű string saját kivételosztállyal
                break;

                default:
                    cout << T_NINCS << endl;
            } // switch
        // kivételek kezelése
        } catch (std::exception& e) {
            // kiírjuk, hogy milyen kivétel jött
            cout << e.what() << endl;
        } catch (BajVan&) {
            cout << T_SKIV << endl;
        } catch (...) {
            cout << T_NAGYB << endl;
        }
        cout << T_TNR;
    } // while
    return 0;
}


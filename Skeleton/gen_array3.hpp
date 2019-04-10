/**
 * \file gen_array3.hpp
 *
 * Generikus tömb interfész
 *   Jporta "NHF 3. - skeleton" feladatának bemutatásához.
 *
 * Feladat:
 *   Fix méretû Generikus tömb megvalósítása.
 */
/// Tömb sablon
/// @param T - adattípus
/// @param s - méret, defalult: 50
/// @param E - hibaosztály (indexelési hiba esetén hívódik) defalul: std::range_error
template <class T, int s = 50, class E = std::range_error>
class Array {               // osztálysablon
    // private adattagok, tagfüggvények az interfeszen nem látszanak,
    // ezért ezeket a tervezés ezen fázisában nem adjuk meg.
public:
    /// Indexelés.
    /// @param i - index
    /// @return - referencia az adott indexû elemre
    /// @return - hibás indexérték esetén E() kivételt dob
    T& operator[](int i);

    /// Indexelés konstans függvénye.
    /// @param i - index
    /// @return - referencia az adott indexû elemre
    /// @return - hibás indexérték esetén E() kivételt dob
    const T& operator[](int i) const;
};

/**
 * \file gen_array3.hpp
 *
 * Generikus t�mb interf�sz
 *   Jporta "NHF 3. - skeleton" feladat�nak bemutat�s�hoz.
 *
 * Feladat:
 *   Fix m�ret� Generikus t�mb megval�s�t�sa.
 */
/// T�mb sablon
/// @param T - adatt�pus
/// @param s - m�ret, defalult: 50
/// @param E - hibaoszt�ly (indexel�si hiba eset�n h�v�dik) defalul: std::range_error
template <class T, int s = 50, class E = std::range_error>
class Array {               // oszt�lysablon
    // private adattagok, tagf�ggv�nyek az interfeszen nem l�tszanak,
    // ez�rt ezeket a tervez�s ezen f�zis�ban nem adjuk meg.
public:
    /// Indexel�s.
    /// @param i - index
    /// @return - referencia az adott index� elemre
    /// @return - hib�s index�rt�k eset�n E() kiv�telt dob
    T& operator[](int i);

    /// Indexel�s konstans f�ggv�nye.
    /// @param i - index
    /// @return - referencia az adott index� elemre
    /// @return - hib�s index�rt�k eset�n E() kiv�telt dob
    const T& operator[](int i) const;
};

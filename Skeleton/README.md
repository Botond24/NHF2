**NHF 3 - Skeleton**

A házi feladat 3. feltöltési határidejére el kel készíteni az osztályok deklarációját illetve minden olyan függvényt deklarálni kell, ami a főbb algoritmusok vezérléséhez, meghívásához szükséges, valamint a tesztprogram vázát. 

Ebben a tervezési fázisban az interfészekre kell koncentrálni, azaz arra, hogy a külvilág mit lát egy adott objektumból/függvényből, ezért a belső részleteket nem kell megvalósítani. (A függvények törzse üres maradhat, az osztályok privát adatai elhagyhatók.) 

A részfeladat ellenőrzéséhez fel kell tölteni a JPorta rendszerbe olyan nem végleges tesztprogramot, ami a megtervezett osztályokat használva bemutatja azok kapcsolatát, együttműködését. A feltöltött forráskódnak szintaktikailag helyesnek kell lennie, de nem kell érdemben működnie. 

A JPorta rendszer csak a fordítást ellenőrzi (nem linkel, nem futtat), 
így a (tag)függvények törzse teljesen hiányozhat! 

Csak forrásprogramot (\*.cpp, \*.h, \*.hpp) csomagoljon a ZIP fajlba! **Ne legyen a ZIP-ben alkatalogus**!

**Megjegyzések:**

- A CodeBloks legegyszerűbben úgy vehető rá, hogy a *build* parancsra ne linkeljen, hogy *Project build options -> Linker settings -> Other linker options* ablakába egy **-c** kapcsolót kell beírni. Ennek hatására a linker ugyan elindul, de nem készít futtatható fájlt. A letölthető minta project fájljában (*gen_array3.cbp*) ezt beállítottuk.  
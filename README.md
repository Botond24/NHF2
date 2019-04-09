**Végleges házi feladat feltöltése**

A feltöltött programot a feladatbeadó rendszer lefordítja és összeszerkeszti. 
Feltételezheti, hogy a fordítás során a **CPORTA** és **MEMTRACE** azonosítók definiáltak. 
A feladat csak akkor fogadható el, ha a fordítás és szerkesztés eredményeként hibaüzenet nem keletkezik! Sikeres fordítás után a rendszer lefuttatja a programot a megadott tesztadatokkal. Ellenőrizze, hogy a memória szivárgást vizsgáló tesztek sikeresen lefutottak-e. A sikeres automatikus tesztek után, a feladatot laborvezetője fogja elfogadni, akinek a működő programot személyesen is be kell mutatni a tárgykövetelményben megadott határidőig.

**Feltöltendő állományok:** 

1. **Forrásfájlokat** tartalmazó *zip* fájl (pl. *kesz.zip*). A fájlok az archívum gyökérében legyenek, ne legyen alkatalógus az archívumban! 
2. **Adatfájlokat** tartalmazó *zip* fájl (opcionális) (pl. *valami_adat.zip*). Ezt az archívumot a *Jporta* a feladat futtatása előtt abban a katalógusban bontja ki, amelyből a futtatható programot indítja. Így a benne levő állományokat a futó program közvetlenül eléri. (pl. f.open("valami_adat.dat");)    
3. **Szabványos bemenetre** irányítandó szöveg fájl (opcionális) (pl: *standard_input.txt*), melynek tartalmát a *Jporta* futtatáskor a futtatott program szabványos bemenetére irányítja. A fájlt szövegfájlnak tekinti, ezért a *Jporta* futtató környezetének (LINUX) megfelelő formára konvertálja, azaz eldobjuk a \r\n sorozatból a \r karaktert, ha van. 
4. **Dokumentációt** tartalmazó .pdf formátumú fájl (opcionális) (pl. *NHF4.pdf*). A fájl feltöltése a feladat kiértékeléséhez nem szükséges, csak **a végleges beadásnál elvárt**, hiánya a megoldás laborvezetői elutasítását vonja maga után. 
 
**Megjegyzések, tanácsok:**

- A fenti felsorolásban példaként zárójelben a minta HF-ben használt neveket adtuk meg. 
- **Ne** használjon ékezetes karaktereket, szóközöket az állományok nevében!
- **Ne** töltsön fel *memtrace.h*, *memtrace.cpp* és *gtest_lite.h* nevű fájlokat! 
Ha mégis feltöltene ilyen nevű fájlokat, akkor azokat a rendszer **felülírja**.
- A forrásfájlokat **ne** UTF-16 kódban csomagolja a zip-be! (Microsoft VS hajlamos ilyen módon kódolni.)
- Ha az **adatfájlokat** (fenti példában a *valami_adat.zip* tartalma) szövegfájlként dolgozza fel, akkor wegye figyelembe, hogy a feladatbeadó rendszer LINUX operációs rendszer alatt fut, ami feltételezi, hogy a szövegfájlokban a sor végét egyetlen karakter a **\n** jelzi, míg pl. Windows alatt a sorok végét a **\r\n** sorozat jelzi, amiből a beolvasó rutinok eldobják a **\r** karaktert. LINUX alatt beolvasáskor ilyen nem történik, így beolvasáskor **\r** is megjelenik.   
- A szabványos bemenetre irányított fájlnál ezzel a problémával nem kell számolnia, mert a *Jporta* ezt a fájlt a feltöltéskor konvertálja ée eldobja a **\r** karaktereket. Adatfájl esetén konverzió nem történik, hiszen egy adatban bármilyen érték előfordulhat. 
- Elemezze a [NHF 4 - végleges](https://git.ik.bme.hu/Prog2/ell_feladat/NHF.git) mintafeladatot! Próbaként akár fel is töltheti a megfelelő fájlokat!
- Problémakeresésben [segít ez az oldal](https://infocpp.iit.bme.hu/jporta/NHF)
  
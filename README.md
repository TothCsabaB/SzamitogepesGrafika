# SzamitogepesGrafika

Koncepció:
A projekt célja a Superhot című videójáték alapmechanikájára épülő interaktív 3D alkalmazás fejlesztése. A program egy belső nézetű (FPS) akciójáték, ahol a játékmenet központi eleme az idő relatív múlása: az idő csak akkor telik normál sebességgel, ha a játékos karakter mozgásban van (helyváltoztatás vagy nézőpontváltás történik). Nyugalmi állapotban az idő jelentősen lelassul.

Design: az eredeti játékra építve egyszerű, low poly modellek alkalmazása a cél, valamint egyszerű fényhatásokkal a krisályszerű kinézet megvalósítása.

Megvalósítás:

Vezérlés (main.c & app.c): A main.c tartalmazza a fő játékciklust (game loop). Az app.c felelős az erőforrások inicializálásáért (SDL, OpenGL kontextus), az eseménykezelésért (bemeneti perifériák), valamint a frissítési és renderelési folyamatok koordinálásáért.

Idő lassítás: Az eltelt időt egy dinamikus szorzóval korrigáljuk: mozgás esetén ez az érték 1.0 körüli, álló helyzetben pedig egy minimális (pl. 0.05) értékre csökken. Minden fizikai számítás és animáció ezen a módosított időértéken alapul.

Pálya: A statikus környezetet külső CSV fájlban tárolom, amely tartalmazza a falak és akadályok típusát, pozícióját és méretét.

Modellek: Az ellenségek, eszközök és lövedékek saját struktúrával és logikai fájlokkal rendelkeznek a kód tisztasága és az adatok elkülönítése érdekében. A modelleket a gyakorló feladatokban használt modell betöltő segítségével használom. A lövésekhez ütközésvizsgálatot használok. Az ellenfeleket egy egyszerű, a játékos felé haladó ai szerű algoritmussal valósítom meg.

Az időtöl függően a karakterek animálása csontozással vagy csak különálló modell elemek animálásával hierachikus módon oldom meg. Egy pálya tervezése ami vagy isméltődik vagy az ellenségek újra megjelennek, esetleg valamilyen számláló hozzáadása.
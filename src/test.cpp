#include <iostream>
#include <cassert>
#include "Ernaehrung.h"



int main()
{
    std::cout << "\n\n*******************************************" << std::endl;
    std::cout << "*******************************************" << std::endl;
    std::cout << "**********     RUN TEST UNITS    **********" << std::endl;
    std::cout << "*******************************************" << std::endl;
    std::cout << "*******************************************\n" << std::endl;

    /*###############################
    #########     ZUTAT     #########
    ###############################*/

    std::cout << "\nClass Zutat\n-----------------------------\n";
    
    // Testet ob die Flags richtige Werte übernehmen
    static_assert(static_cast<unsigned short>(Zutat::NONE) == 0,
                 "[FAIL] Zutat::NONE != 0");
    std::cout << "[PASS] Zutat::NONE == 0" << std::endl;
    static_assert(static_cast<unsigned short>(Zutat::BEEF) == 1,
                 "[FAIL] Zutat::BEEF != 1");
    std::cout << "[PASS] Zutat::BEEF == 1" << std::endl;
    static_assert(static_cast<unsigned short>(Zutat::PORK) == 2,
                 "[FAIL] Zutat::PORK != 2");
    std::cout << "[PASS] Zutat::PORK == 2" << std::endl;
    static_assert(static_cast<unsigned short>(Zutat::CHICKEN) == 4,
                 "[FAIL] Zutat::CHICKEN != 4");
    std::cout << "[PASS] Zutat::CHICKEN == 4" << std::endl;
    static_assert(static_cast<unsigned short>(Zutat::MILK) == 8,
                 "[FAIL] Zutat::MILK != 8");
    std::cout << "[PASS] Zutat::MILK == 8" << std::endl;
    static_assert(static_cast<unsigned short>(Zutat::EGG) == 16,
                 "[FAIL] Zutat::EGG != 16");
    std::cout << "[PASS] Zutat::EGG == 16" << std::endl;
    static_assert(static_cast<unsigned short>(Zutat::GLUTEN) == 32,
                 "[FAIL] Zutat::GLUTEN != 32");
    std::cout << "[PASS] Zutat::GLUTEN == 32" << std::endl;

    /*************************************
     * Ab hier ist eine Garantie für die unterschiedliche Positionierung
     * der Bits der jeweiligen Zutaten gewährleistet.
     *************************************/

    // Testet die Verknüpfung von Zutaten zueinander
    assert(static_cast<unsigned short>(Zutat::GLUTEN|Zutat::EGG) == static_cast<unsigned short>(32|16));
    std::cout << "[PASS] Zutat::|operator(Zutat, Zutat) works!" << std::endl;
    
    // Testet die bitweise UND von Zutaten
    assert(static_cast<unsigned short>(Zutat::GLUTEN&Zutat::EGG) == static_cast<unsigned short>(32&16));
    std::cout << "[PASS] Zutat::&operator(Zutat, Zutat) works!" << std::endl;

    // Testet die bitweise XOR von Zutaten
    assert(static_cast<unsigned short>(Zutat::GLUTEN^Zutat::EGG) == static_cast<unsigned short>(32^16));
    std::cout << "[PASS] Zutat::^operator(Zutat, Zutat) works!" << std::endl;

    // Testet die bitweise NOT von Zutat
    assert(static_cast<unsigned short>(~Zutat::GLUTEN) == static_cast<unsigned short>(~32));
    std::cout << "[PASS] Zutat::~operator(Zutat) works!" << std::endl;


    /*************************************
     * Ab hier ist eine Garantie für die bitweise Operationen, also in
     * unserem Kontext die Kombination von Zutaten, sowie auch Entfernen
     * Hinzufügen und Prüfen auf Enthaltung, gewährleistet.
     *************************************/

    /*###############################
    #########    GERICHT    ######### (Lebensmittel)
    ###############################*/
    
    std::cout << "\nClass Gericht ->(Lebensmittel)\n-----------------------------\n";
    
    // Testet die Gleichheitsoperator von Gericht / Lebensmittel
    assert( Gericht("a", Zutat::PORK) == Gericht("a", Zutat::PORK) );
    std::cout << "[PASS] Gericht == Gericht works"<< std::endl;

    // Testet die Ungleichheit von Gerichten / Lebensmitteln
    assert( !(Gericht("a", Zutat::PORK) == Gericht("b", Zutat::PORK)) );
    std::cout << "[PASS] Gericht != Gericht works"<< std::endl;

    /*************************************
     * Ab hier ist eine Garantie für die Gleichheit
     * von zwei gleichen Lebensmitteln gewährleistet.
     *************************************/

    // initialisiere zwei verschiedene Gerichte
    Gericht gerichtA("a", Zutat::PORK|Zutat::EGG);
    Gericht gerichtB("a", Zutat::MILK);
    
    // füge Gericht A die Zutat Milch zu
    gerichtA.addFlag(Zutat::MILK);
    // entferne von Gericht A die Zutaten Schwein und Ei
    gerichtA.subFlag(Zutat::PORK|Zutat::EGG);
    
    /* Testet die Gleichheit der oben aufgeführten Gerichte.
     * Durch das Entfernen/Zufügen der Zutaten sollten diese nun gleich sein.
     * aktuelle Werte:
     * gerichtA{"a", Zutat::MILK}; 
     * gerichtB{"a", Zutat::MILK};
     */
    assert( gerichtA == gerichtB );
    std::cout << "[PASS] Gericht::subFlag(Zutat) and Gericht::addFlag(Zutat) works"<< std::endl;
    
    /*************************************
     * Ab hier ist eine Garantie für das Hinzufügen/Entfernen von
     * Zutaten über die Methoden der Lebensmittel-Klasse gewährleistet.
     *************************************/

    // Testet ob vorhandene Zutaten von Gerichten geprüft werden
    assert( gerichtA.checkFlag(Zutat::MILK) );
    std::cout << "[PASS] Gericht::checkFlag(Zutat) works with positive values"<< std::endl;

    // Testet ob NICHT vorhandene Zutaten von Gerichten geprüft werden
    assert( !gerichtA.checkFlag(Zutat::CHICKEN) );
    std::cout << "[PASS] Gericht::checkFlag(Zutat) works with negative values"<< std::endl;

    /*************************************
     * Ab hier ist eine Garantie für das Prüfen von Zutaten
     * über die Methoden der Lebensmittel-Klasse gewährleistet.
     *************************************/

    /*###############################
    #########     LIST      #########
    ###############################*/
    
    std::cout << "\nClass List\n-----------------------------\n";

    // Testet Gleichheitsoperator von List
    assert( List{&gerichtA} == List{&gerichtA} );
    std::cout << "[PASS] List == List works"<< std::endl;

    // Testet Ungleichheit von Listen
    assert( List{&gerichtA} != List{} );
    std::cout << "[PASS] List != List works"<< std::endl;

    /*************************************
     * Ab hier ist eine Garantie für die Gleichheit
     * von zwei gleichen Listen gewährleistet.
     *************************************/

    /*###############################
    #########     MENUE     #########
    ###############################*/
    
    std::cout << "\nClass Menue\n-----------------------------\n";
    
    // Testet ob getFullMenue() eine Liste mit Einträgen liefert und 
    // ob der mehrfache Aufruf den gleichen Effekt hat
    assert( Menue::getFullMenue().size() > 0 && Menue::getFullMenue() == Menue::getFullMenue() );
    std::cout << "[PASS] Menue::getFullMenue() is idempotent"<< std::endl;

    /*************************************
     * Ab hier ist eine Garantie für die Idempotenz der
     * getFullMenue() Methode gewährleistet.
     *************************************/

    // Testet ob clearList() funktioniert, indem die Differenzmenge übereinstimmt
    assert( List{&gerichtA} == Menue::clearList(List{&gerichtA, &gerichtB}, List{&gerichtB}) );
    std::cout << "[PASS] Menue::clearList(List, List) returns expected List"<< std::endl;

    // Testet ob clearList() mit leerer List:l2 funktioniert
    assert( (List{&gerichtA, &gerichtB}) == Menue::clearList(List{&gerichtA, &gerichtB}, List{}) );
    std::cout << "[PASS] Menue::clearList(List, List(empty)) returns expected List"<< std::endl;

    // Testet ob clearList() mit leerer List:l1 funktioniert
    assert( List{} == Menue::clearList(List{}, List{&gerichtA, &gerichtB}) );
    std::cout << "[PASS] Menue::clearList(List(empty), List) returns expected List"<< std::endl;
    
    /*************************************
     * Ab hier ist eine Garantie für die mathematische Korrektheit der
     * clearList() Methode, welche auf die Differenz von zwei Mengen beruht,
     * gewährleistet.
     *************************************/

    /* setzt die Flags der oben initialisierten Gerichten, um weitere Tests durchzuführen.
     * Dabei hat Gericht B keinen Zutat und dient als Dummy, 
     * Gericht A bekommt die jeweilig zu filternde Zutat.
     * Daher sollte jede Filtermethode eine Liste mit der einzigen Element als Gericht A liefern
     */
    gerichtB.setFlag(Zutat::NONE); // dummy

    // Testet ob Menue::filterBeef() nur Lebensmitteln mit Flag Zutat::BEEF liefert
    gerichtA.setFlag(Zutat::BEEF);
    assert( List{} == Menue::filterBeef(List{}) ); 
    assert( List{&gerichtA} == Menue::filterBeef(List{&gerichtA, &gerichtB}) );
    std::cout << "[PASS] Menue::filterBeef(List) returns expected List"<< std::endl;
    
    // Testet ob Menue::filterPork() nur Lebensmitteln mit Flag Zutat::PORK liefert
    gerichtA.setFlag(Zutat::PORK);
    assert( List{} == Menue::filterPork(List{}) );
    assert( List{&gerichtA} == Menue::filterPork(List{&gerichtA, &gerichtB}) );
    std::cout << "[PASS] Menue::filterPork(List) returns expected List"<< std::endl;
    
    // Testet ob Menue::filterChicken() nur Lebensmitteln mit Flag Zutat::CHICKEN liefert
    gerichtA.setFlag(Zutat::CHICKEN);
    assert( List{} == Menue::filterChicken(List{}) );
    assert( List{&gerichtA} == Menue::filterChicken(List{&gerichtA, &gerichtB}) );
    std::cout << "[PASS] Menue::filterChicken(List) returns expected List"<< std::endl;
    
    // Testet ob Menue::filterMilk() nur Lebensmitteln mit Flag Zutat::MILK liefert
    gerichtA.setFlag(Zutat::MILK);
    assert( List{} == Menue::filterMilk(List{}) );
    assert( List{&gerichtA} == Menue::filterMilk(List{&gerichtA, &gerichtB}) );
    std::cout << "[PASS] Menue::filterMilk(List) returns expected List"<< std::endl;
    
    // Testet ob Menue::filterEgg() nur Lebensmitteln mit Flag Zutat::EGG liefert
    gerichtA.setFlag(Zutat::EGG);
    assert( List{} == Menue::filterEgg(List{}) );
    assert( List{&gerichtA} == Menue::filterEgg(List{&gerichtA, &gerichtB}) );
    std::cout << "[PASS] Menue::filterEgg(List) returns expected List"<< std::endl;
    
    // Testet ob Menue::filterGluten() nur Lebensmitteln mit Flag Zutat::GLUTEN liefert
    gerichtA.setFlag(Zutat::GLUTEN);
    assert( List{} == Menue::filterGluten(List{}) );
    assert( List{&gerichtA} == Menue::filterGluten(List{&gerichtA, &gerichtB}) );
    std::cout << "[PASS] Menue::filterGluten(List) returns expected List"<< std::endl;
    
    /*************************************
     * Ab hier ist eine Garantie für die semmantische Richtigkeit, sowie
     * auch Terminierung bei Übergabe von einer leeren Liste,
     * der jeweiligen Filtermethoden gewährleistet
     *************************************/

    /*###############################
    #########  ERNAEHRUNG   #########
    ###############################*/
    
    std::cout << "\nClass Ernaehrung\n-----------------------------\n";
    
    Ernaehrung ernaehrung;

    /* Testet ob der erstelleProfil() mit negativen Werten wie erwartet terminiert.
     * Bei einem Wert kleiner 0 wird eine bestimmte Exception erwartet. 
     * In unserem Fall ist es vom Typ const char *.
     * Theoretisch kann man die Idee mit eigene Exception-Klasse erweitern.
     */
    try
    {
        ernaehrung.erstelleProfil(-1);
    }
    catch(const char* error)
    {
        std::cout << "[PASS] Ernaehrung::erstelleProfil(int) throws expected exception"<< std::endl;
    }
    catch(...)
    {
        std::cout << "[FAIL] Ernaehrung::erstelleProfil(int) throws another exception as expected"<< std::endl;
        return 0;
    }

    /* Testet ob der erstelleProfil() mit negativen Werten wie erwartet terminiert.
     * Bei einem Wert größer 6 wird eine bestimmte Exception erwartet. 
     * In unserem Fall ist es vom Typ const char *.
     * Theoretisch kann man die Idee mit eigene Exception-Klasse erweitern.
     */
    try
    {
        ernaehrung.erstelleProfil(7);
    }
    catch(const char* error)
    {
        std::cout << "[PASS] Ernaehrung::erstelleProfil(int) throws expected exception"<< std::endl;
    }
    catch(...)
    {
        std::cout << "[FAIL] Ernaehrung::erstelleProfil(int) throws another exception as expected"<< std::endl;
        return 0;
    }

    /*************************************
     * Ab hier ist eine Garantie für die Behandlung
     * jeglicher Parameterübergabe (int) durch die Methode
     * erstelleProfil() gewährleistet.
     *************************************/

    /* Folgende Tests haben wenig Mehrwert, da die bis hier hin erfolgreich ausgeführten
     * Test die "Garantie" geben, dass die Methoden der Klasse Ernaehrung fehlerfrei und
     * sinngemäß terminieren.
     * Vollständigkeitshalber werden einige Aufrufe mit Erwartungswerten verglichen.
     */

    
    List menue = Menue::getFullMenue();
    
    assert( ernaehrung.erstelleProfil(0) == menue );
    std::cout << "[PASS] Ernaehrung::erstelleProfil(0) returns expected List"<< std::endl;

    assert( Menue::clearList(menue, ernaehrung.erstelleProfil(3)) == Menue::filterMilk(menue) );
    std::cout << "[PASS] Ernaehrung::erstelleProfil(3) returns expected List"<< std::endl;
    
    assert( Menue::clearList(menue, ernaehrung.erstelleProfil(4)) == Menue::filterGluten(menue) );
    std::cout << "[PASS] Ernaehrung::erstelleProfil(4) returns expected List"<< std::endl;
    
    assert( Menue::clearList(menue, ernaehrung.erstelleProfil(5)) == Menue::filterPork(menue) );
    std::cout << "[PASS] Ernaehrung erstelleProfil(5) returns expected List"<< std::endl;

    // ###############################
    
    std::cout << "\n\n*******************************************" << std::endl;
    std::cout << "*******************************************" << std::endl;
    std::cout << "********** PASSED ALL TEST UNITS **********" << std::endl;
    std::cout << "*******************************************" << std::endl;
    std::cout << "*******************************************\n\n" << std::endl;
    
    std::getchar();
    return 0;
}

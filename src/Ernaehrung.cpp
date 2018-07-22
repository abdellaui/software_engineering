#include "Ernaehrung.h"

const List Ernaehrung::erstelleProfil(const int &option) const
{

    List menue = Menue::getFullMenue();
    // keine Einschränkung
    if (option == 0)
    {
        return menue;
    }
    // vegetarisch
    if (option == 1)
    {
        List beef           = Menue::filterBeef(menue);
        List chicken        = Menue::filterChicken(menue);
        List pork           = Menue::filterPork(menue);
        // Entfernt vom Menü Schwein, Rind und Huhn
        return Menue::clearList(Menue::clearList(Menue::clearList(menue, pork), chicken), beef);
    }
    // vegan
    if (option == 2)
    {
        List milk           = Menue::filterMilk(menue);
        List egg            = Menue::filterEgg(menue);
        // Entfernt vom vegetarischen Menü alle Milch und Eierprodukte
        return Menue::clearList(Menue::clearList(erstelleProfil(1), milk), egg);
    }
    // laktosefrei
    if (option == 3)
    {
        // Entfernt Milchprodukte vom Menü
        return Menue::clearList(menue, Menue::filterMilk(menue));
    }
    // glutenfrei
    if (option == 4)
    {
        // Entfernt Glutenprodukte vom Menü
        return Menue::clearList(menue, Menue::filterGluten(menue));
    }
    // helal
    if (option == 5)
    {
        // Entfernt Schwein vom Menü
        return Menue::clearList(menue, Menue::filterPork(menue));
    }
    // koscher
    if (option == 6)
    {
        List beef               = Menue::filterBeef(menue);
        List chicken            = Menue::filterChicken(menue);
        List milk               = Menue::filterMilk(menue);

        // finde zunächst alle Rindprodukte mit Milch
        List beefWithMilk       = Menue::clearList(beef, Menue::clearList(beef, milk));
        // und finde alle Produkte mit Hühnerfleisch und Milch
        List chickenWithMilk    = Menue::clearList(chicken, Menue::clearList(chicken, milk));
        // entferne diese von der Helalliste
        return Menue::clearList(Menue::clearList(erstelleProfil(5), beefWithMilk), chickenWithMilk);
    }

    throw "Option nicht verfuegbar. Eingabe auf 0-6 einschraenken!";
}

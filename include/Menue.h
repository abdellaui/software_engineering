#pragma once

#include <iostream>
#include <list>
#include "Gericht.h"

/*************************************
 * Definition von Datentyp List
 *************************************/
typedef std::list<Lebensmittel *> List;

class Menue
{
  private:
    // Filterung auf einem Flag
    static const List filterOnFlag(const List &l, const Zutat &flag)
    {
        List result;
        // Liste wird durchlaufen, dabei werden Elemente mit dem gesuchten Flag aussortiert
        // und in Ergebnisliste angehängt.
        for (Lebensmittel *curr : l)
        {
            if (curr->checkFlag(flag))
                result.push_back(curr);
        }
        return result;
    }

  public:
    static const List getFullMenue()
    {
        static List fullmenue;
        // Menü zum testen erstellt, welches alle Filterfälle abdeckt
        if (fullmenue.size() == 0)
        {
            fullmenue.push_back(new Gericht("beef & milk",      Zutat::BEEF | Zutat::MILK));
            fullmenue.push_back(new Gericht("prok & milk",      Zutat::PORK | Zutat::MILK));
            fullmenue.push_back(new Gericht("chicken & milk",   Zutat::CHICKEN | Zutat::MILK));
            fullmenue.push_back(new Gericht("egg & milk",       Zutat::EGG | Zutat::MILK));
            fullmenue.push_back(new Gericht("gluten & milk",    Zutat::GLUTEN | Zutat::MILK));
            fullmenue.push_back(new Gericht("beef",             Zutat::BEEF));
            fullmenue.push_back(new Gericht("pork",             Zutat::PORK));
            fullmenue.push_back(new Gericht("chicken",          Zutat::CHICKEN));
            fullmenue.push_back(new Gericht("milk",             Zutat::MILK));
            fullmenue.push_back(new Gericht("egg",              Zutat::EGG));
            fullmenue.push_back(new Gericht("gluten",           Zutat::GLUTEN));
        }

        return fullmenue;
    }
    // Jede der folgenden Funktionen nutzt die oben definierte private Methode
    // filtert Liste auf Rind
    static const List filterBeef(const List &l)
    {
        return filterOnFlag(l, Zutat::BEEF);
    }
    // filter Liste auf Schwein
    static const List filterPork(const List &l)
    {
        return filterOnFlag(l, Zutat::PORK);
    }
    // filtert Liste auf Huhn
    static const List filterChicken(const List &l)
    {
        return filterOnFlag(l, Zutat::CHICKEN);
    }
    // filtert Liste auf Milchprodukte
    static const List filterMilk(const List &l)
    {
        return filterOnFlag(l, Zutat::MILK);
    }
    // filter Liste auf Produkte mit Eiern
    static const List filterEgg(const List &l)
    {
        return filterOnFlag(l, Zutat::EGG);
    }
    // filtert Liste auf Produkte mit Gluten
    static const List filterGluten(const List &l)
    {
        return filterOnFlag(l, Zutat::GLUTEN);
    }
    // entfernt alle Produkte die auf Liste 2 sind von Liste 1
    static const List clearList(const List &l1, const List &l2)
    {
        // falls l2 leer, dann l1 liefern
        if(l2.size()<1)
            return l1;

        List result;
        // für jedes Element der ersten Liste wird die gesamte 2. Liste auf dieses Element geprüft
        // falls nicht vorhanden füge das Element in die Ergebnis Liste
        for (Lebensmittel *curr1 : l1)
        {
            bool notFound = true;
            for (Lebensmittel *curr2 : l2)
            {
                if (curr1 == curr2)
                {
                    notFound = false;
                    break;
                }
            }

            if (notFound)
                result.push_back(curr1);
        }

        return result;
    }

    // Ausgabe einer Liste
    static void printList(const List l)
    {
        std::cout << "#------------------------" << std::endl;
        std::cout << std::bitset<6>(static_cast<unsigned short>(Zutat::NONE))       << " NONE" << std::endl;
        std::cout << std::bitset<6>(static_cast<unsigned short>(Zutat::BEEF))       << " BEEF" << std::endl;
        std::cout << std::bitset<6>(static_cast<unsigned short>(Zutat::PORK))       << " PORK" << std::endl;
        std::cout << std::bitset<6>(static_cast<unsigned short>(Zutat::CHICKEN))    << " CHICKEN" << std::endl;
        std::cout << std::bitset<6>(static_cast<unsigned short>(Zutat::MILK))       << " MILK" << std::endl;
        std::cout << std::bitset<6>(static_cast<unsigned short>(Zutat::EGG))        << " EGG" << std::endl;
        std::cout << std::bitset<6>(static_cast<unsigned short>(Zutat::GLUTEN))     << " GLUTEN" << std::endl;

        std::cout << std::endl
                  << ". . . . . . M E N U . . . . . ." << std::endl
                  << std::endl;

        if (l.size() > 0)
        {
            for (Lebensmittel *curr : l)
            {
                std::cout << std::bitset<6>(static_cast<unsigned short>(curr->getFlag()));
                std::cout << "  -  ";
                std::cout << curr->getName();
                std::cout << std::endl;
            }
        }
        else
        {
            std::cout << " leer " << std::endl;
        }
        std::cout << "------------------------#" << std::endl;
    }
};

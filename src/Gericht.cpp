#include "Gericht.h"

// constructor
Gericht::Gericht() : Lebensmittel(){};

// Namens Kontruktor
Gericht::Gericht(const std::string &name) : Lebensmittel()
{
    setName(name);
}

// Namens- und Flagkonstruktor
Gericht::Gericht(const std::string &name, const Zutat &flag) : Lebensmittel()
{
    setName(name);
    setFlag(flag);
}

// name
// Um Lebensmitteln unterscheiden zu können, wird ein Prefix verwendet.
const std::string Gericht::getName() const
{
    return "Gericht: " + m_name;
}

#include "Lebensmittel.h"

// constructor
Lebensmittel::Lebensmittel() : m_flag(Zutat::NONE), m_name("undefined"){};

// name
void Lebensmittel::setName(const std::string &name)
{
    m_name = name;
}

// flag
const Zutat Lebensmittel::getFlag() const
{
    return m_flag;
}

void Lebensmittel::setFlag(const Zutat &flag)
{
    m_flag = flag;
}

// Hinzufügen durch bitweises ODER
void Lebensmittel::addFlag(const Zutat &flag)
{
    m_flag = m_flag | flag;
}

// Entfernen durch bitweises XAND
void Lebensmittel::subFlag(const Zutat &flag)
{
    m_flag = m_flag & (~flag);
}

// Prüfen ob Zutaten übereinstimmen
const bool Lebensmittel::checkFlag(const Zutat &flag) const
{
    return (m_flag & flag) == flag;
}

// operator
// Testet ob Name und Flag gleich sind
const bool Lebensmittel::operator==(const Lebensmittel &rhs)
{
    return (this->getName() == rhs.getName() && this->getFlag() == rhs.getFlag());
}

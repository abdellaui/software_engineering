#pragma once

enum class Zutat
{
    NONE        = 0,
    BEEF        = 1 << 0,
    PORK        = 1 << 1,
    CHICKEN     = 1 << 2,
    MILK        = 1 << 3,
    EGG         = 1 << 4,
    GLUTEN      = 1 << 5

    /*
     Zutaten wird als Flag verwaltet, um diese einfacher zu kombinieren.
     000000 NONE
     000001 BEEF
     000010 PORK
     000100 CHICKEN
     001000 MILK
     010000 EGG
     100000 GLUTEN
     */
};

// Bitweises ODER, verknüpfen mehrerer Zutaten
inline Zutat operator|(const Zutat &lhs, const Zutat &rhs)
{
    return static_cast<Zutat>(static_cast<unsigned short>(lhs) | static_cast<unsigned short>(rhs));
}
// Bitweises UND, prüfen von Zutat
inline Zutat operator&(const Zutat &lhs, const Zutat &rhs)
{
    return static_cast<Zutat>(static_cast<unsigned short>(lhs) & static_cast<unsigned short>(rhs));
}
// Bitweises XOR, kein Gebrauch in diesem Kontext
inline Zutat operator^(const Zutat &lhs, const Zutat &rhs)
{
    return static_cast<Zutat>(static_cast<unsigned short>(lhs) ^ static_cast<unsigned short>(rhs));
}
// Bitweises NOT, nicht enhaltenen Zutaten
inline Zutat operator~(const Zutat &rhs)
{
    return static_cast<Zutat>(~static_cast<unsigned short>(rhs));
}

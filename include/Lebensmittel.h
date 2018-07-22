#pragma once

#include <string>
#include "Zutat.h"

class Lebensmittel
{

private:
  // Lebensmittel mit Zutaten, die als Flag festgelegt verwaltet werden
  Zutat m_flag;
    
protected:
  std::string m_name;
    
public:
  // constructor
  Lebensmittel();

  // name
  virtual const std::string getName() const = 0; // rein virtuelle Methode
  virtual void setName(const std::string &name);

  // flag
  virtual const Zutat getFlag() const;
  virtual void setFlag(const Zutat &flag);
    
  // Zutaten hinzufügen
  virtual void addFlag(const Zutat &flag);
  // Zutaten entfernen
  virtual void subFlag(const Zutat &flag);
  // Zutaten prüfen
  virtual const bool checkFlag(const Zutat &flag) const;

  // operator
  virtual const bool operator==(const Lebensmittel &rhs);
};

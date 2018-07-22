#pragma once

#include "Lebensmittel.h"

class Gericht : public Lebensmittel
{
public:
  // default-constructor
  Gericht();
  // nur Namen setzen
  Gericht(const std::string &name);
  // Name und Flag setzen
  Gericht(const std::string &name, const Zutat &flag);

  //name
  const std::string getName() const;
};

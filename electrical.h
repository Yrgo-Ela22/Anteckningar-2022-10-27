/********************************************************************************
* electrical.h: Innehåller funktionalitet för lagring samt utskrift av 
*               elektriska storheter via strukten electrical samt associerade 
*               funktioner.
********************************************************************************/
#ifndef ELECTRICAL_H_
#define ELECTRICAL_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* electrical: Strukt för lagring av elektriska storheter spänning, ström,
*             resistans och effekt.
********************************************************************************/
struct electrical
{
   double voltage;    /* Spänning mätt i V. */
   double current;    /* Ström mätt i mA. */
   double resistance; /* Resistans mätt i kOhm. */
   double power;      /* Effekt mätt i mW. */
};

/********************************************************************************
* electrical_init: Initierar objekt för lagring av elektriska storheter.
*                  Angiven spänning och ström lagras och används för att 
*                  beräkna motsvarande resistans och effekt.
*
*                  - self   : Pekare till objektet som ska initieras.
*                  - voltage: Spänning mätt i V.
*                  - current: Ström mätt i mA.
********************************************************************************/
void electrical_init(struct electrical* self,
                     const double voltage,
                     const double current);

/********************************************************************************
* electrical_clear: Nollställer angivet electrical-objekt. 
* 
*                   - self: Pekare till objektet som ska nollställas.
********************************************************************************/
void electrical_clear(struct electrical* self);

/********************************************************************************
* electrical_print: Skriver ut lagrade elektriska storheter via angiven utström,
*                   där standardutenheten stdout används som default för
*                   utskrift i terminalen.
*
*                   - self: Pekare till electrical-objektet.
*                   - ostream: Pekare till angiven utström (default = stdout).
********************************************************************************/
void electrical_print(const struct electrical* self,
                      FILE* ostream);


#endif /* ELECTRICAL_H_ */
/********************************************************************************
* electrical.h: Inneh�ller funktionalitet f�r lagring samt utskrift av 
*               elektriska storheter via strukten electrical samt associerade 
*               funktioner.
********************************************************************************/
#ifndef ELECTRICAL_H_
#define ELECTRICAL_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* electrical: Strukt f�r lagring av elektriska storheter sp�nning, str�m,
*             resistans och effekt.
********************************************************************************/
struct electrical
{
   double voltage;    /* Sp�nning m�tt i V. */
   double current;    /* Str�m m�tt i mA. */
   double resistance; /* Resistans m�tt i kOhm. */
   double power;      /* Effekt m�tt i mW. */
};

/********************************************************************************
* electrical_init: Initierar objekt f�r lagring av elektriska storheter.
*                  Angiven sp�nning och str�m lagras och anv�nds f�r att 
*                  ber�kna motsvarande resistans och effekt.
*
*                  - self   : Pekare till objektet som ska initieras.
*                  - voltage: Sp�nning m�tt i V.
*                  - current: Str�m m�tt i mA.
********************************************************************************/
void electrical_init(struct electrical* self,
                     const double voltage,
                     const double current);

/********************************************************************************
* electrical_clear: Nollst�ller angivet electrical-objekt. 
* 
*                   - self: Pekare till objektet som ska nollst�llas.
********************************************************************************/
void electrical_clear(struct electrical* self);

/********************************************************************************
* electrical_print: Skriver ut lagrade elektriska storheter via angiven utstr�m,
*                   d�r standardutenheten stdout anv�nds som default f�r
*                   utskrift i terminalen.
*
*                   - self: Pekare till electrical-objektet.
*                   - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void electrical_print(const struct electrical* self,
                      FILE* ostream);


#endif /* ELECTRICAL_H_ */
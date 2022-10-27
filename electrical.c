/********************************************************************************
* electrical.c: Inneh�ller funktionsdefinitioner f�r lagring och utskrift
*               av elektriska storheter via strukten electrical.
********************************************************************************/
#include "electrical.h"

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
                     const double current)
{
   self->voltage = voltage;
   self->current = current;
   self->resistance = voltage / current;
   self->power = voltage * current;
   return;
}

/********************************************************************************
* electrical_clear: Nollst�ller angivet electrical-objekt.
*
*                   - self: Pekare till objektet som ska nollst�llas.
********************************************************************************/
void electrical_clear(struct electrical* self)
{
   self->voltage = 0;
   self->current = 0;
   self->resistance = 0;
   self->power = 0;
   return;
}

/********************************************************************************
* electrical_print: Skriver ut lagrade elektriska storheter via angiven utstr�m,
*                   d�r standardutenheten stdout anv�nds som default f�r
*                   utskrift i terminalen.
*
*                   - self: Pekare till electrical-objektet.
*                   - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void electrical_print(const struct electrical* self,
                      FILE* ostream)
{
   if (!ostream) ostream = stdout;
   fprintf(ostream, "--------------------------------------------------------------------------------\n");
   fprintf(ostream, "Voltage: %lg V\n", self->voltage);
   fprintf(ostream, "Current: %lg mA\n", self->current);
   fprintf(ostream, "Resistance: %lg kOhm\n", self->resistance);
   fprintf(ostream, "Power: %lg mW\n", self->power);
   fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
   return;
}

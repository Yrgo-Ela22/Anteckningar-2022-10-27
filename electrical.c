/********************************************************************************
* electrical.c: Innehåller funktionsdefinitioner för lagring och utskrift
*               av elektriska storheter via strukten electrical.
********************************************************************************/
#include "electrical.h"

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
                     const double current)
{
   self->voltage = voltage;
   self->current = current;
   self->resistance = voltage / current;
   self->power = voltage * current;
   return;
}

/********************************************************************************
* electrical_clear: Nollställer angivet electrical-objekt.
*
*                   - self: Pekare till objektet som ska nollställas.
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
* electrical_print: Skriver ut lagrade elektriska storheter via angiven utström,
*                   där standardutenheten stdout används som default för
*                   utskrift i terminalen.
*
*                   - self: Pekare till electrical-objektet.
*                   - ostream: Pekare till angiven utström (default = stdout).
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

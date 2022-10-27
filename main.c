/********************************************************************************
* main.c: Demonstration av strukt i C för lagring samt utskrift av elektriska
*         storheter spänning, ström, resistans och effekt.
* 
*         OBS! För att använda funktionen fopen i Visual Studio, högerklicka på 
*         projektnamnet i Solution Explorer, klicka på Properties => C/C++ =>
*         Preprocessor. I rutan Preprocessor Definitions, skriv in direktivet 
*         _CRT_SECURE_NO_WARNINGS föregått av ett blanksteg.
********************************************************************************/
#include "electrical.h"

/********************************************************************************
* main: Deklarerar och initierar två objekt döpta e1 samt e2 och skriver sedan
*       ut de elektriska storheterna, både i terminalen samt till en textfil 
*       döpt electrical.txt.
********************************************************************************/
int main(void)
{
   struct electrical e1, e2;
   FILE* ostream;
   
   electrical_init(&e1, 24, 48);
   electrical_init(&e2, 10, 2.5);

   electrical_print(&e1, 0);
   electrical_print(&e2, 0);

   ostream = fopen("electrical.txt", "w");
   electrical_print(&e1, ostream);
   electrical_print(&e2, ostream);
   fclose(ostream);

   return 0;
}
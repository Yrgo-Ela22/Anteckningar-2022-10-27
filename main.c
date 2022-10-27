/********************************************************************************
* main.c: Demonstration av strukt i C f�r lagring samt utskrift av elektriska
*         storheter sp�nning, str�m, resistans och effekt.
* 
*         OBS! F�r att anv�nda funktionen fopen i Visual Studio, h�gerklicka p� 
*         projektnamnet i Solution Explorer, klicka p� Properties => C/C++ =>
*         Preprocessor. I rutan Preprocessor Definitions, skriv in direktivet 
*         _CRT_SECURE_NO_WARNINGS f�reg�tt av ett blanksteg.
********************************************************************************/
#include "electrical.h"

/********************************************************************************
* main: Deklarerar och initierar tv� objekt d�pta e1 samt e2 och skriver sedan
*       ut de elektriska storheterna, b�de i terminalen samt till en textfil 
*       d�pt electrical.txt.
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
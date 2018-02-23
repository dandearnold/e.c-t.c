#include <stdio.h>	
#include <unistd.h>
#include <string.h>

#define MAX_KULCS 100			//ennyi helyet fog lefoglalni
#define BUFFER_MERET 256		//nevesitett változo


int
main (int argc, char **argv)		
{

  char kulcs[MAX_KULCS];		
  char buffer[BUFFER_MERET];

  int kulcs_index = 0;
  int olvasott_bajtok = 0;

  int kulcs_meret = strlen (argv[1]);		//strlen = stringek masolasara szolgal, annyi bájtot másol maximum
  strncpy (kulcs, argv[1], MAX_KULCS);		//strncpy = bemasolja a karaktertombbol ebbe a kulcsba

  while ((olvasott_bajtok = read (0, (void *) buffer, BUFFER_MERET)))		//0 = standard input(itt most=tiszta.szoveg), buffer megszakíthatja az inputokat, de azok nem vesznek el
    {

      for (int i = 0; i < olvasott_bajtok; ++i)			
	{

	  buffer[i] = buffer[i] ^ kulcs[kulcs_index];		//kulcsmeret 1-gyel novelese, szazalekra osztas utan
	  kulcs_index = (kulcs_index + 1) % kulcs_meret;	//

	}

      write (1, buffer, olvasott_bajtok);		//beolvasott bajtokat kiirja a standard kimenetre

    }
}

//aki ismeri ezt a titkos kodot, az tudja ezzel a programmal dekodolni
//ha nem ismerjuk -> brute force: vmi strategiaval vegig jarni a lehetseges eseteket
//most a kulcster csak a szamok(pl. pinkod: 10^4)

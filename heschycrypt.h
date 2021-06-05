#include <string.h>

/* 
 * This file is licenced under the GPL 3.0
 * 
 * This file is still under development.
 * This file is developed by Henry Schynol.
 */

char* heschycrypt(char str[], int mode) {
		int ascii = 0;
		switch ( mode ) {
			case 0: /* Encrpt */
				for (int i = 0 ; i < strlen( str ); i++)
				{
					ascii = str[i] += ( (i + 1) * (i + 1) );
					str[i] = ( char )ascii;
				}
				break;
			case 1: /* Decrypt */
				for (int i = 0; i < strlen( str ); i++)
				{
					ascii = str[i] -= ( (i + 1) * (i + 1) );
					str[i] = ( char )ascii;
				}
				break;
		}
		return str;

	}

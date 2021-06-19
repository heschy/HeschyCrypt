#include <string.h>

const int HESCHYCRYPT_ENCRYPT = 0;
const int HESCHYCRYPT_DECRYPT = 1;

/*
 * This file is licenced under the GPL 3.0
 *
 * Please report any bugs on GitHub.
 * This file is still under development.
 * This file is developed by Henry Schynol.
 */

char* heschycrypt(char str[], int mode) {
	int ascii = 0;
	switch (mode) {
	case HESCHYCRYPT_ENCRYPT: /* Encrpt */
		for (int i = 0; i < strlen(str); i++)
		{
			ascii = str[i] += ((i + 1) * (i + 1));
			str[i] = (char)ascii;
		}
		break;
	case HESCHYCRYPT_DECRYPT: /* Decrypt */
		for (int i = 0; i < strlen(str); i++)
		{
			ascii = str[i] -= ((i + 1) * (i + 1));
			str[i] = (char)ascii;
		}
		break;
	}
	return str;

}


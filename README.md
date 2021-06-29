# HeschyCrypt
is a simple library to encrypt and decrypt strings. It isn't verry secure but simple and okay. ***HeschyCrypt*** is good to save some data, but the decrypting is **verry** simple.

Here are some good Points to start with HeschyCrypt (actualy it's just one point):
- [How to use the HeschyCrypt Library](#how-to-use-heschycrypt)


## Windows
On Windows my Library works verry fine. The Lib is tested on Ubuntu 20.04 with ***WINE 5.0***!

## Linux 
On Linux my Library works verry fine. The Lib is tested on ***Ubuntu 20.04***!

## Todos

### Finished

- [X] HeschyCrypt for Windows    (*Tested with the DEV-CPP IDE*) 
- [X] HeschyCrypt for Linux      (*Tested with the G++ Compiler*)

### Problems in a Table


| In Work? | Problem |
|-|-|
| <ul><li>- [X] In Work</li></ul> | Passwords have to be Longer then the Text. |
| <ul><li>- [ ] Not in Work</li></ul> | The Method is unsecure. |
| <ul><li>- [ ] Not in Work</li></ul> | It may don't  use the complete Password. |

### Problems

#### Passwords have to be Longer then the Text
HeschyCrypt uses the ASCII codes of the letters to encrypt the String. If there are no letters in the Password, then there are no Codes and it wont work.

#### The Method is unsecure
The Algorythm is to simple.

#### It may don't  use the complete Password

If the String has 4 Letters then the Algorythm will only use the first 4 letters of the Password to encrypt.


## How to use HeschyCrypt

### 1.: Include the Lib
To use HeschyCrypt you need to download the HeaderFile. Then you have to include it, just like This:

```cpp
#include "PATH/TO/HEADER/heschycrypt.h"
```

### Encrypt/Decrypt Strings without a Password
To encrypt a String with HeschyCrypt and write it to the Console you can write something like this:

```cpp
#include <string.h>      // Use The 'string' Type
#include <iostream>      // Write to the Console
#include "heschycrypt.h" // Include The HeschyCrypt Library
using namespace std;

int main()
{
    string str = "ThisStringWillBeEncrypted";
    str = heschycrypt(HESCHYCRYPT_ENCRYPT, str);
    cout << "Encrypted String: " << str;
    return 0;
}
    
```
 The Application will Output this:
```
Encrypted String: Ulr�l�������0#ef��2T���
```

To Decrypt we need to add one line more:
 ```cpp
#include <string.h>      // Use The 'string' Type
#include <iostream>      // Write to the Console
#include "heschycrypt.h" // Include The HeschyCrypt Library
using namespace std;

int main()
{
    string str = "ThisStringWillBeEncrypted";
    str = heschycrypt(HESCHYCRYPT_ENCRYPT, str);
    str = heschycrypt(HESCHYCRYPT_DECRYPT, str);
    cout << "Encrypted String: " << str;
    return 0;
}
    
```
Encrypting/Decrypting without a Password works like this:

```cpp
heschycrypt(string MODE, string STRING); // The ArgumentTypes are string,string,string
```

### Encrypt/Decrypt Strings with a Password
Encrypting/Decrypting with a Password works like this:
```cpp
heschycrypt(MODE, STRING, PASSWD);
```
We can write a simple Programm like this with the Password-Function:
 ```cpp
#include <string.h>      // Use The 'string' Type
#include <iostream>      // Write to the Console
#include "heschycrypt.h" // Include The HeschyCrypt Library
using namespace std;

int main()
{
    string str = "PlaceHolder";
    string password = "PlaceHolder";
    string str_COPY = str;
    cout << "Input: ";
    cin >> str;
    cout << "Password: ";
    cin >> password;
    str = heschycrypt(HESCHYCRYPT_ENCRYPT, str, password);
    password = "Placeholder";
    cout << "Encrypted!\n" << endl << "GET ACCESS:\nPassword: ";
    cin >> password;
    str_COPY = heschycrypt(HESCHYCRYPT_DECRYPT, str, password);
    cout << "Output: " << str_COPY << endl;
    
    cout << "\n\n\nPress Enter to Quit...";
    cin.get();
    return 0;
}
    
```

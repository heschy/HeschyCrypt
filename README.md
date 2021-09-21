# HeschyCrypt
is a simple library to encrypt and decrypt strings. It isn't verry secure but easy to use. ***HeschyCrypt*** is good to save some data, but the decrypting is **verry** simple.


## Error Codes

| Code | Descibtion |
|---|---|
|1| `heschycrypt()` has two modes: DECRYPT and ENCRYPT. Error 1 appears if you try to start it in an other mode.



## Linux with Wine
On Wine my Library works verry fine.

```
System: Ubuntu 20.04
IDE: Dev C++ IDE
Compiler: Default
Wine Version: 5.0
Wine Configuration: Windows 7
```

## Windows
On Windows my Library works verry fine.

```
System: Windows 10 Pro x64
IDE: Embarcadero Dev C++ IDE
Compiler: 32 Bit - Release
```

## Linux 
On Linux my Library works verry fine. 

```
System: Ubuntu 20.04
IDE: ---
Compiler: G++
```

## Todos

### Finished

- [X] HeschyCrypt for Windows    (*Tested with the DEV-CPP IDE*) 
- [X] HeschyCrypt for Linux      (*Tested with the G++ Compiler*)
- [X] Problem: Password needs to be longer then the Text

### In Work

If the Password is longer then the text, it won't not use the complete password.

### To do Later...

The Method is unsecure. 
If the INT overloads, some PCs wont react the same way then other.


### Problems

#### The Method is unsecure
The Algorythm is to simple.

#### It may don't  use the complete Password

If the String has 4 Letters then the Algorythm will only use the first 4 letters of the Password to encrypt.


## How to use HeschyCrypt

### Include the Headerfile
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
 The Application will Output something like this:
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

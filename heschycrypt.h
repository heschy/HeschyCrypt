//////////////////////////
// This Library is part of the HeschyCrypt Project.
// The HeschyCrypt Project is licenced under the GNU GPL 3.0
// 


#ifndef __HESCHYCRYPT__
    #define __HESCHYCRYPT__
    #define HESCHYCRYPT_ENCRYPT "HESCHYCRYPT_MODUS_ENCRYPT"
    #define HESCHYCRYPT_DECRYPT "HESCHYCRYPT_MODUS_DECRYPT"
    #include <string.h>
    #include <iostream>
    #include <assert.h>
    using namespace std;
    
    string reverse_str(string str)
    {
        for (int i = 0; i < str.length() / 2; i++)
        {
            swap(str[i], str[str.length() - i - 1]);
        }
        return str;
    }

    string heschycrypt(const string mode, string str)
    {
        int ascii = 0;
    
        
        if(mode == HESCHYCRYPT_ENCRYPT) {
            for (int i = 0; i < str.length(); i++)
            {
                ascii = str.at(i) += ((i + 1) * (i + 1));
                ascii = str.at(i) += ((i - 2) * (i + 1));
                ascii = str.at(i) += ((i - 3) * (i + 2));
                ascii = str.at(i) += ((i - 4) * (i + 3));
                ascii = str.at(i) += ((i - 5) * (i + 4));
                ascii = str.at(i) += ((i - 6) * (i + 5));
                ascii = str.at(i) += ((i - 7) * (i + 6));
                ascii = str.at(i) += ((i - 8) * (i + 7));
                ascii = str.at(i) += ((i - 9) * (i + 8));
                ascii = str.at(i) += ((i - 10) * (i + 9));
                str[i] = (char)ascii;
            }
            str = reverse_str(str);
        }
        else if(mode == HESCHYCRYPT_DECRYPT) {
            str = reverse_str(str);
            for (int i = 0; i < str.length(); i++)
            {
                ascii = str.at(i) -= ((i - 10) * (i + 9));
                ascii = str.at(i) -= ((i - 9) * (i + 8));
                ascii = str.at(i) -= ((i - 8) * (i + 7));
                ascii = str.at(i) -= ((i - 7) * (i + 6));
                ascii = str.at(i) -= ((i - 6) * (i + 5));
                ascii = str.at(i) -= ((i - 5) * (i + 4));                
                ascii = str.at(i) -= ((i - 4) * (i + 3));
                ascii = str.at(i) -= ((i - 3) * (i + 2));
                ascii = str.at(i) -= ((i - 2) * (i + 1));
                ascii = str.at(i) -= ((i + 1) * (i + 1));
                str[i] = (char)ascii;
            }
            
        }
        
        return str;
    }
    
    string heschycrypt(const string mode, string str, string passwd)
    {
        int ascii = 0;

        while(passwd.length()<str.length())
        {
            passwd.append(passwd);
        }

        if(mode == HESCHYCRYPT_ENCRYPT) {
            for (int i = 0; i < str.length(); i++)
            {
                ascii = str.at(i) += ((i + 1) * (i + passwd.at(i)));
                ascii = str.at(i) += ((i - 2) * (i + 1));
                ascii = str.at(i) += ((i - 3) * (i + 2));
                ascii = str.at(i) += ((i - 4) * (i + 3));
                ascii = str.at(i) += ((i - 5) * (i + 4));
                ascii = str.at(i) += ((i - 6) * (i + 5));
                ascii = str.at(i) += ((i - 7) * (i + 6));
                ascii = str.at(i) += ((i - 8) * (i + 7));
                ascii = str.at(i) += ((i - 9) * (i + 8));
                ascii = str.at(i) += ((i - 10) * (i + 9));
                str[i] = (char)ascii;
            }
            str = reverse_str(str);
        }
        else if(mode == HESCHYCRYPT_DECRYPT) {
            str = reverse_str(str);
            for (int i = 0; i < str.length(); i++)
            {
                ascii = str.at(i) -= ((i - 10) * (i + 9));
                ascii = str.at(i) -= ((i - 9) * (i + 8));
                ascii = str.at(i) -= ((i - 8) * (i + 7));
                ascii = str.at(i) -= ((i - 7) * (i + 6));
                ascii = str.at(i) -= ((i - 6) * (i + 5));
                ascii = str.at(i) -= ((i - 5) * (i + 4));                
                ascii = str.at(i) -= ((i - 4) * (i + 3));
                ascii = str.at(i) -= ((i - 3) * (i + 2));
                ascii = str.at(i) -= ((i - 2) * (i + 1));
                ascii = str.at(i) -= ((i + 1) * (i + passwd.at(i)));
                str[i] = (char)ascii;
            }
        }
        else {
            cerr << "\aError" << endl;
        }
        return str;
    }
    
#endif

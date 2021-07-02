//////////////////////////
// This Library is part of the HeschyCrypt Project.
// The HeschyCrypt Project is licenced under the GNU GPL 3.0
// 


#ifndef __HESCHYCRYPT__
    #define __HESCHYCRYPT__
    #define HESCHYCRYPT_ENCRYPT "HESCHYCRYPT_MODUS_ENCRYPT"
    #define HESCHYCRYPT_DECRYPT "HESCHYCRYPT_MODUS_DECRYPT"
    #include <string.h>
    #include <fstream>
    #include <assert.h>
    using namespace std;

    string heschycrypt(const string mode, string str)
    {
        int ascii = 0;
        if(mode == HESCHYCRYPT_ENCRYPT) {
            for (int i = 0; i < str.length(); i++)
            {
                ascii = str.at(i) += ((i + 1) * (i + 1));
                str[i] = (char)ascii;
            }
        }
        else if(mode == HESCHYCRYPT_DECRYPT) {
            for (int i = 0; i < str.length(); i++)
            {
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
                str[i] = (char)ascii;
            }
        }
        else if(mode == HESCHYCRYPT_DECRYPT) {
            for (int i = 0; i < str.length(); i++)
            {
                ascii = str.at(i) -= ((i + 1) * (i + passwd.at(i)));
                str[i] = (char)ascii;
            }
        }
        else {
            cerr << "\aError" << endl;
        }
        return str;
    }
    
    bool heschycrypt_file(string mode,string filename)
    {
        string filename = "/tmp/moz/test.txt";
        string line;
        ifstream ifile;
        ifile.open(filename);
        ofstream ofile;
        ofile.open(filename.append(".heschycrypt"));
        if(!ofile.is_open())
        {
            return false;
        }    
        if(!assert(ifile.is_open())
        {
           return false;
        }

        if(mode == HESCHYCRYPT_ENCRYPT)
        {
            while(getline(ifile, line))
            {
                ofile << heschycrypt(HESCHYCRYPT_ENCRYPT,line) << endl;
            }
        }
        else if(mode == HESCHYCRYPT_DECRYPT)
        {
            while(getline(ifile, line))
            {
                ofile << heschycrypt(HESCHYCRYPT_DECRYPT,line) << endl;
            }
        }
        ifile.close();
        ofile.close();
        return true;
    }
           
    bool heschycrypt_file(string mode,string filename, string passwd)
    {
        string filename = "/tmp/moz/test.txt";
        string line;
        ifstream ifile;
        ifile.open(filename);
        ofstream ofile;
        ofile.open(filename.append(".heschycrypt"));
        if(!ofile.is_open())
        {
            return false;
        }    
        if(!assert(ifile.is_open())
        {
           return false;
        }

        if(mode == HESCHYCRYPT_ENCRYPT)
        {
            while(getline(ifile, line))
            {
                ofile << heschycrypt(HESCHYCRYPT_ENCRYPT,line,passwd) << endl;
            }
        }
        else if(mode == HESCHYCRYPT_DECRYPT)
        {
            while(getline(ifile, line))
            {
                ofile << heschycrypt(HESCHYCRYPT_DECRYPT,line,passwd) << endl;
            }
        }
        ifile.close();
        ofile.close();
        return true;
    }
    
#endif

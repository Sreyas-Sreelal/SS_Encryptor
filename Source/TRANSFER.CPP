
#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <process.h>
/*

Data Transfer  Tool Scripted by Sreyas

.............Capabilities..........................
|*Custom data encrypting algorithm  71 ascii       |
|*Custom Decrypting algorithm       71 ascii       |
|*Stores data in .dat file for remote transfering  |
|..................................................|

Date of Update : 20/08/16

*/

#define MAX_LETTERS 500

typedef char string[MAX_LETTERS];

/*Base Classs*/

class __ss {

protected:
    char _charft[345];
    char E_CHAR[345];

public:
    __ss()
    {
    }
    string _charlt;
    void Input();
    void Output()
    {
        cout << _charlt;
    }
    ~__ss()
    {
    }
};

/*Data Processing Class*/

class _process : public __ss {
public:
    void inti()
    {
        strcpy(_charft, "ABCDEFGHIJKLMNOPQRSTUVWXYZ.;:#@abcdefghijklmnopqrstuvwxyz?!$&1234567890");
        strcpy(E_CHAR, "?zxXW#!:;~-=mODor097813$&|P@,a`AyYp245IHKlcCNQRTtSZ^nJjdEefF*+><ÞVv)_b");
    }
    void make()
    {
        inti();
        ofstream fout("bin.dat", ios::out);
        __ss::Input();
        encrypt();
        fout << _charlt;
        fout.close();
        cout << "\n!!!!Encrypted File created successfully !!!\n";
        cout << "Press any key to continue \n";
        getch();
    }

    void encrypt();
    void ency(int);
    void decrypt();
    char decy(char);
} s;

void __ss::Input()
{
    int n;
    cout << "Input number of lines ";
    cin >> n;
    char _dtemp[100];
    for (int i = 0; i < n; i++) {
        gets(_dtemp);
        strcat(_charlt, _dtemp);
        strcat(_charlt, "\n");
    }
}
void _process::decrypt()
{
    inti();
    int i;
    char _dtemp[56];
    string data_;
    ifstream fin("bin.dat", ios::in);
    fin.seekg(0);
    while (!fin.eof()) {
        fin >> _dtemp;
        for (i = 0; i < strlen(_dtemp); i++) {
            _dtemp[i] = decy(_dtemp[i]);
        }
        strcat(data_, _dtemp);
        strcat(data_, " ");
    }
    fin.close();
    cout << "\n...........Decrypted Successfully..........\n\n";
    for (i = 0; i < strlen(data_); i++)
        cout << data_[i];
    cout << endl;
    cout << "Press any key to continue \n";
    getch();
}

char _process::decy(char chara)
{
    for (int j = 0; j < strlen(__ss::E_CHAR); j++) {
        if (chara == __ss::E_CHAR[j]) {
            chara = __ss::_charft[j];
            break;
        }
    }
    return chara;
}

void _process::encrypt()
{
    int i;

    for (i = 0; i < strlen(__ss::_charlt); i++)
        ency(i);
}

void _process::ency(int x)
{
    for (int i = 0; i < strlen(__ss::_charft); i++) {
        if (__ss::_charlt[x] == __ss::_charft[i]) {
            __ss::_charlt[x] = __ss::E_CHAR[i];
            break;
        }
    }
}

void main()
{
    clrscr();
    int opt;
    while (1) {
        clrscr();
        cout << "\n\n\
1.Make Encrypted file\n\
2.Decrypt existing  file\n\
3.Close the Application\n";
        cout << "\nInput your option : ";
        cin >> opt;
        switch (opt) {
        case 1:
            s.make();
            break;
        case 2:
            s.decrypt();
            break;
        case 3:
            exit(0);
        default:
            cout << "Wrong Option selected select correct option from the list \n";
            break;
        }
    }
    getch();
}

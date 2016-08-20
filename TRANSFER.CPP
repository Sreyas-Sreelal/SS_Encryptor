
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

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

class __ss
{

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
cout<<_charlt;
}
};

/*Data Processing Class*/

class _process:public __ss
{
public:
void inti(){
strcpy(_charft,"ABCDEFGHIJKLMNOPQRSTUVWXYZ.;:#@abcdefghijklmnopqrstuvwxyz?!$&1234567890");
strcpy(E_CHAR ,"?zxXW#!:;~-=mODor097813$&|P@,a`AyYp245IHKlcCNQRTtSZ^nJjdEefF*+><ÞVv)_b");
}
void make()
{
inti();
ofstream fout("bin.dat",ios::out);
cout<<"Input your data to be encrypted \n";
__ss::Input();
encrypt();
fout<<_charlt;
fout.close();
}

void encrypt();
void ency(int);
void decrypt();

}s;

void __ss::Input()
{
int n;
cout<<"Input number of lines ";
cin>>n;
cout<<"Input data \n";
char _dtemp[100];
for(int i=0;i<n;i++)
{
gets(_dtemp);
strcat(_charlt,_dtemp);
strcat(_charlt,"\n");
}
}
void _process::decrypt()
{
inti();
int i,j,x=0;
char _dtemp;
string data_;
ifstream fin("bin.dat",ios::in);
fin.seekg(0);
while(!fin.eof())
{
fin.get(_dtemp);
for(i=0;i<strlen(__ss::E_CHAR);i++)
{
if(_dtemp==__ss::E_CHAR[i])
{
data_[x]=__ss::_charft[i];
x++;
}
}
}
fin.close();
cout<<"Decrypted Successfully \n\n";
for(i=0;i<x;i++)
cout<<data_[i];
}
void _process::encrypt()
{
int i;

for(i=0;i<strlen(__ss::_charlt);i++)
ency(i);
}
void _process::ency(int x)
{
for(int i=0;i<strlen(__ss::_charft);i++)
{
if(__ss::_charlt[x]==__ss::_charft[i])
{
__ss::_charlt[x]=__ss::E_CHAR[i];
break;
}
}
}
void main()
{
clrscr();
s.make();
s.decrypt();
getch();
}


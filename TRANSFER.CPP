
#include<fstream.h>//for filehandling and echo services
#include<conio.h>//clrscr() and getch()
#include<stdio.h>//gets()
#include<string.h>//strcpy(),strycat() etc
/*
Data Transfer Security Tool Scripted by Sreyas

.............Capabilities............
*Custom data patterns
*Encryption
*Decryption
*File handling for transferring data
.....................................

Date of Update : 20/8/16*/

#define MAX_LETTERS 500//MAX_LETTERS IN FILE DATA 

typedef char string[MAX_LETTERS];//new data type 


/*Base Class*/

class __ss
{

protected:
char _charft[345];
char E_CHAR[345];
public:

__ss()
{
}

string _charlt;//data storing var
void Input();
void Output()
{
cout<<_charlt;
}
};


class _process:public __ss
{
public:
void inti(){
strcpy(_charft,"ABCDEFGHIJKLMNOPQRSTUVWXYZ.;:#@abcdefghijklmnopqrstuvwxyz?!$&1234567890");//raw data sheet 71 ascii
strcpy(E_CHAR ,"?zxXW#!:;~-=mODor097813$&|P@,a`AyYp245IHKlcCNQRTtSZ^nJjdEefF*+><ÞVv)_b");//encryption copy 71 ascii

}

void make()
{
inti();
ofstream fout("bin.dat",ios::out);//data file
cout<<"Input your data to be encrypted \n";
__ss::Input();
encrypt();
fout<<_charlt;
fout.close();
}

void encrypt();
void decrypt();

};

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
cout<<"\n\nDEBUG:_charlt "<<_charlt<<endl;
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
  //cout<<"DEBUG temp "<<_dtemp<<endl;
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
int i,j;

  for(i=0;i<strlen(__ss::_charlt);i++)
  {
    for(j=0;j<strlen(__ss::_charft);j++)
    {

      if(__ss::_charlt[i]==__ss::_charft[j])
      {
      cout<<"DEBUG RAW lt "<<__ss::_charlt[i]<<endl;
      cout<<"DEBUG RAW FT "<<__ss::_charft[j]<<endl;
      __ss::_charlt[i]=__ss::E_CHAR[j];

      cout<<"Debug:loop encryption "<<__ss::E_CHAR[j]<<endl;
      continue;
      }
    }
  }
}

void main()
{
clrscr();
cout<<"hello";
s.make();
s.decrypt();
getch();
}


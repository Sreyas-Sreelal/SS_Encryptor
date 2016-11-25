#include <fstream.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <process.h>
/*
                            Data Transfer  Tool Scripted by Sreyas
                        ................Capabilities........................
                        |*Custom data encrypting algorithm  71 ascii       |
                        |*Custom Decrypting algorithm       71 ascii       |
                        |*Stores data in .dat file for remote transfering  |
                        |..................................................|
                        Date of Update : 25/11/16
*/


/*Base Classs*/

char const RAW_DATA[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ.;:#@abcdefghijklmnopqrstuvwxyz?!$&1234567890",
	   ENCRYPTED_DATA[]="?zxXW#!:;~-=mODor097813$&|P@,a`AyYp245IHKlcCNQRTtSZ^nJjdEefF*+><ÞVv)_b";
class __ss
{
	public:
		char INPUTTED_DATA[500];
		void Input();
		void Output()
		{
			cout << INPUTTED_DATA;
		}
		~__ss() {}
};

/*Data Processing Class*/
class _process : protected __ss
{
	public:
		void make()
		{
			ofstream fout("bin.dat", ios::out);
			__ss::Input();
			encrypt();
			fout << INPUTTED_DATA;
			fout.close();
			cout << "\n!!!!Encrypted File created successfully !!!\n";
			cout << "Press any key to continue \n";
			getch();
		}
		void encrypt();
		void decrypt();
};

void __ss::Input()
{
	int n;
	cout << "Input number of lines ";
	cin >> n;
	char TEMPORARY_DATA[500];
	for (int i = 0; i < n; i++)
	{
		gets(TEMPORARY_DATA);
		strcat(INPUTTED_DATA, TEMPORARY_DATA);
		strcat(INPUTTED_DATA, "\n");
	}
}
void _process::decrypt()
{
	int i,h,j,k;
	char TEMPORARY_DATA[500];
	char OUTPUT_DATA[500];
	ifstream fin("bin.dat", ios::in);
	fin.seekg(0);
	while (!fin.eof())
	{       if(fin.eof())break;
		fin >> TEMPORARY_DATA;
		for (i = 0,j,h=strlen(TEMPORARY_DATA); i < h; i++)
		{
			for (j=0,k= strlen(ENCRYPTED_DATA); j <k; j++)
			{
				if (TEMPORARY_DATA[i] == ENCRYPTED_DATA[j])
				{
					TEMPORARY_DATA[i] = RAW_DATA[j];
					break;
				}
			}

		}
		strcat(OUTPUT_DATA, TEMPORARY_DATA);
		strcat(OUTPUT_DATA, " ");
	}
	fin.close();
	cout << "\n...........Decrypted Successfully..........\n\n";
	for (i = 0,h=strlen(OUTPUT_DATA); i <h ; i++)
		cout << OUTPUT_DATA[i];
	cout << endl;
	cout << "Press any key to continue \n";
	getch();
}


void _process::encrypt()
{
	int i,h=strlen(RAW_DATA),k=strlen(__ss::INPUTTED_DATA),j;
	for(i=0;i<k;i++)
	{
		for (j = 0; j < h; j++)
		{
			if (__ss::INPUTTED_DATA[i] == RAW_DATA[j])
			{
				__ss::INPUTTED_DATA[i] = ENCRYPTED_DATA[j];
				cout << "ENCRYPTING\n";
				break;
			}
		}

	}

}
void main()
{
	clrscr();
	int opt;
	_process s;
	while (opt!=3)
	{
		clrscr();
		cout << "\n\n\
			1.Make Encrypted file\n\
			2.Decrypt existing  file\n\
			3.Close the Application\n";
		cout << "\nInput your option : ";
		cin >> opt;
		switch (opt)
		{
			case 1:
				s.make();
			break;
			case 2:
				s.decrypt();
			break;
			case 3:
			break;
			default:
				cout << "Wrong Option selected select correct option from the list \n";
			break;
		}
	}
	getch();
}

/***Dots laukums NxN. Janis un Peteris spele interesantu speli “desas”.
Katrs pec kartas izdara pa gajienam, noradot koordinatas, kur liek savu atzimi (X vai O).
Spele beidzas, ja kadam ir izdevies savas atzimes salikt garuma N rinda vai kolonna vai
pa diagonali vai ari izdariti NxN gajieni un neviens nav uzvarejis.***/

#include <iostream>
using namespace std;
int main(){

int ok;
int N;

do{
 cout << "Ievadiet laukuma lielumu, kas ir vismaz 3: ";     ///Laukums ir vismaz 3, lai nodrosinatu abiem speletajiem iespeju uzvaret
cin >> N;
if(N<3)cout<<"Ievadiet korektu vertibu!"<<endl;
}while(N<3);

char a[N][N];


do{
int izdg=0;         ///Mainigais, kas uzskaitis izdaritos gajienus
int uzvarejiso=0;
int uzvarejisx=0;
int xi,xj, oi,oj;

                                                ///Laukuma izprintesana
for(int i=0; i<N; i++)
    for (int j=0; j<N; j++) a[i][j]='.';       ///"." apzime tuksos laukumus

for(int i=0; i<N; i++){cout<<endl;
    for (int j=0; j<N; j++) cout<<a[i][j]<<" ";}
cout<<endl;



cout<<endl;
cout<<"Kadas koordinatas bus 'X'?"<< endl;
do{
                                                                    ///Cikls parbaudei, vai koordinatas ir laukuma ietvaros
cin>>xi>>xj;                                                        ///Pirmo reizi ievada 'X' koordinatas


if (xi>N || xj>N ||xi<1 ||xj<1)
    cout<<"Ievadiet koordinatas laukuma ietvaros"<<endl;


}while(xi>N || xj>N ||xi<1 ||xj<1);

xi=xi-1;
xj=xj-1;

a[xi][xj]= 'X';

izdg++;

for(int i=0; i<N; i++){cout<<endl;                          ///Laukuma izdruka, kura paradas izdaritais gajiens
    for (int j=0; j<N; j++) cout<<a[i][j]<<" ";}
cout<<endl;

while(izdg<N*N){                        ///Cikls gajienu izdarisanai

do{                                                     ///Cikls "O" ievadisanai un parbaudem

cout<<endl;
cout<<"Kadas koordinatas bus 'O'?"<< endl;
cin>>xi>>xj;


if(xi>N || xj>N ||xi<1 ||xj<1)                       ///Parbaude, vai koordinatas ievaditas laukuma ietvaros
do{
    cout<<"Ievadiet koordinatas laukuma ietvaros"<<endl;
    cin>>xi>>xj;
}while (xi>N || xj>N ||xi<1 ||xj<1);

xi=xi-1;
xj=xj-1;

if (a[xi][xj]=='X' || a[xi][xj]=='O')                   ///Parbaude, vai izveletais laucins ir aiznemts
cout<<"Izvelieties citu laucinu!"<<endl;
}while(a[xi][xj]=='X'|| a[xi][xj]=='O');

a[xi][xj]= 'O';
izdg++;

for(int i=0; i<N; i++){cout<<endl;                      ///Laukuma izdruka ar ievaditajiem gajieniem
    for (int j=0; j<N; j++) cout<<a[i][j]<<" ";}
cout<<endl;

int do1=0, do2=0;
int diagonale1aro=0, diagonale2aro=0;                   ///Parbaude, vai viena kolonna sastav tikai no 'O'
    for (int i=0; i<N; i++) if (a[i][i]=='O') do1++;
if (do1==N) {diagonale1aro++; uzvarejiso=1;break;}
    for (int i=0; i<N; i++) if(a[i][N-i-1]=='O') do2++;     ///Parbaude, vai otra kolonna sastav tikai no 'O'
if (do2==N) {diagonale2aro++; uzvarejiso=1;break;}


int rindaaroir=0;
for(int i=0; i<N; i++){
        int viensoir=0;
        for(int j=0; j<N; j++){if(a[i][j]=='O') viensoir++;}    ///Parbaude, vai rinda sastav tikai no 'O'
if (viensoir==N) {rindaaroir++;uzvarejiso=1;break;}
}
if(uzvarejiso!=0){break;}


int kolonnaaroir=0;
for(int i=0; i<N; i++){
        int viensoir=0;
        for(int j=0; j<N; j++){if(a[j][i]=='O') viensoir++;}    ///Parbaude, vai kolonna sastav tikai no 'O'
if (viensoir==N) {kolonnaaroir++;uzvarejiso=1;break;}
}
if(uzvarejiso!=0){break;}
if (izdg==N*N) {break;}


do{                                                         ///Cikls "X" ievadisanai un parbaudem
cout<<endl;
cout<<"Kadas koordinatas bus 'X'?"<< endl;
cin>>xi>>xj;


if(xi>N || xj>N ||xi<1 ||xj<1)                       ///Parbaude, vai koordinatas ievaditas laukuma ietvaros
do{
    cout<<"Ievadiet koordinatas laukuma intervala"<<endl;
    cin>>xi>>xj;
}while (xi>N || xj>N ||xi<1 ||xj<1);

xi=xi-1;
xj=xj-1;

if (a[xi][xj]=='O'|| a[xi][xj]=='X')                    ///Parbaude, vai izveletais laucins ir aiznemts
cout<<"Izvelieties citu laucinu!"<<endl;
}while(a[xi][xj]=='O'|| a[xi][xj]=='X');

a[xi][xj]= 'X';
izdg++;

for(int i=0; i<N; i++){cout<<endl;                      ///Laukuma izdruka ar ievaditajiem gajieniem
    for (int j=0; j<N; j++) cout<<a[i][j]<<" ";}
cout<<endl;

int dx1=0, dx2=0;
int diagonale1arx=0, diagonale2arx=0;
    for (int i=0; i<N; i++) if (a[i][i]=='X') dx1++;        ///Parbaude, vai viena diagonale sastav tikai no 'X'
if (dx1==N) {diagonale1arx++; uzvarejisx=1;break;}
    for (int i=0; i<N; i++) if(a[i][N-i-1]=='X') dx2++;     ///Parbaude, vai otra diagonale sastav tikai no 'X'
if (dx2==N) {diagonale2arx++; uzvarejisx=1;break;}


int rindaarxir=0;
for(int i=0; i<N; i++){
        int viensxir=0;
        for(int j=0; j<N; j++){if(a[i][j]=='X') viensxir++;}    ///Parbaude, vai rinda sastav tikai no 'X'
if (viensxir==N) {rindaarxir++;uzvarejisx=1;break;}
}
if(uzvarejisx!=0){break;}


int kolonnaarxir=0;
for(int i=0; i<N; i++){
        int viensxir=0;
        for(int j=0; j<N; j++){if(a[j][i]=='X') viensxir++;}    ///Parbaude, vai kolonna sastav tikai no 'X'
if (viensxir==N) {kolonnaarxir++;uzvarejisx=1;break;}
}
if(uzvarejisx!=0){break;}
if (izdg==N*N) {break;}

}
if(uzvarejisx!=0) cout<<"Uzvarejis ir 'X'. Spele ir beigusies."<<endl;
else if(uzvarejiso!=0) cout<<"Uzvarejis ir 'O'. Spele ir beigusies."<<endl;
else cout<<"Neviens nav uzvarejis. Spele ir beigusies."<<endl;

cout<<endl;
cout<<"Ja veleties turpinat spelet ar tadu pasu laukumu, spiediet 1. Ja velaties beigt, spiediet 0."<<endl;
cin>>ok;
if(ok!=1) cout<<"Paldies par speli!"<<endl;

}while(ok!=0);

for(int i=0; i<N; i++)          /// Masiva dzesana
    for(int j=0; j<N; j++)
    delete[]a[i];
delete[]a;
}


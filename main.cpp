#include <iostream>
#include <string>
#include <bitset>
using namespace std;
void podziel(string string1, char kropka, int tab[]){
 int pIndex = 0, kIndex = 0;
 int n;
 int tabIndex=0;
 for (n=0; n<=string1.size(); n++){
     if(string1[n]==kropka || n == string1.size()){
         kIndex=n;
         string subIPV4=string1.substr(pIndex, kIndex);
         tab[tabIndex]=stoi(subIPV4);
         pIndex=n+1;
         tabIndex+=1;
         }
 }
}
int main() {
    string ipv4;
    string maska;
    int tabIPV4[4];
    int tabMASKA[4];
    int tabPODSIEC[4];
    cout << "Podaj adres IPv4:";
    cin >> ipv4;
    cout << "Podaj maske:";
    cin >> maska;
    //Maska
    char kropka='.';
    podziel(maska,kropka, tabMASKA);
    //Maska dwojkowo
    cout << "Maska dwojkowo:" << endl;
    bitset<8> a(tabMASKA[0]);
    bitset<8> b(tabMASKA[1]);
    bitset<8> c(tabMASKA[2]);
    bitset<8> d(tabMASKA[3]);
    cout << a << "." << b << "." << c << "." << d << endl;
    //Maska szesnastkowo
    printf("Maska szesnastkowo:\n%x.%x.%x.%x\n",a,b,c,d);
    //Maska dziesietnie
    printf("Maska dziesietnie:\n%d.%d.%d.%d\n",tabMASKA[0],tabMASKA[1],tabMASKA[2],tabMASKA[3]);
    //Adres
    podziel(ipv4,kropka,tabIPV4);
    //IPV4 dwojkowo
    cout << "IPV4 dwojkowo:" << endl;
    bitset<8> e(tabIPV4[0]);
    bitset<8> f(tabIPV4[1]);
    bitset<8> g(tabIPV4[2]);
    bitset<8> h(tabIPV4[3]);
    cout << e << "." << f << "." << g << "." << h << endl;
    //IPV4 szesnastkowo
    printf("IPV4 szesnastkowo:\n%x.%x.%x.%x\n",e,f,g,h);
    //IPV4 dziesietnie
    printf("IPV4 dziesietnie:\n%d.%d.%d.%d\n",tabIPV4[0],tabIPV4[1],tabIPV4[2],tabIPV4[3]);
    //Podsiec
    tabPODSIEC[0]=(tabIPV4[0]&tabMASKA[0]);
    tabPODSIEC[1]=(tabIPV4[1]&tabMASKA[1]);
    tabPODSIEC[2]=(tabIPV4[2]&tabMASKA[2]);
    tabPODSIEC[3]=(tabIPV4[3]&tabMASKA[3]);
    //Tworzenie adresu podsieci
    string podsiec;
    for (int k = 0; k<4; k++){
         podsiec+=to_string(tabPODSIEC[k]);
         if(k!=3) podsiec+='.';
    }
    //Podsiec dwojkowo
    cout << "Podsiec dwojkowo:" << endl;
    bitset<8> x(tabPODSIEC[0]);
    bitset<8> y(tabPODSIEC[1]);
    bitset<8> z(tabPODSIEC[2]);
    bitset<8> v(tabPODSIEC[3]);
    cout << x << "." << y << "." << z << "." << v << endl;
    //Podsiec szesnastkowo
    printf("Podsiec szesnastkowo:\n%x.%x.%x.%x\n",x,y,z,v);
    //Podsiec dziesietnie
    printf("Podsiec dziesietnie:\n%i.%i.%i.%i\nKoniec.",x,y,z,v);
    return 0;
}

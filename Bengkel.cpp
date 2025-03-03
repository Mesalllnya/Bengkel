#include <iostream>
#include <string>
using namespace std;

/*jadi, buat jumlah sparepat, harga servis, memperbarui data(menambah,mengurangi stok), nota pembayaran, 
opsional= jika servis penuh ada opsi delay diservis */

//sesi login
struct usnpasslogin{
    string id= "k123";
    string pass= "123";
};usnpasslogin login;

struct sparepat{
    string nama;
    int jumlah;
    int harga;
};sparepat sp[100]={{"busi",10,20000},{"oli",20,50000},{"kampas rem",15,30000},{"lampu",5,10000}};

struct servis{
    string nama;
    int harga;
};servis sr[100]={{"ganti oli",20000},{"ganti busi",15000},{"ganti kampas rem",25000},{"ganti lampu",10000}};

void sesilogin(){

}

int main(){
    system("cls");
    int x=3;
    do{
    cout<<"Masukkan Id: ";getline(cin>>ws,login.id);
    cout<<"Masukkan Password: ";getline(cin>>ws,login.pass);
    if(login.id!="k123"||login.pass!="123"){
        cout<<"id atau password anda salah\n\n";
        x--;
    }
    else{
        cout<<"halo admin\n";
        x=0;
    }
    }while(x>0);

    cout<<"====LIST====\n";
    cout<<"1. Sparepat\n";
    cout<<"2. Servis\n";
    cout<<"3. Bayar\n";
    cout<<"4. Keluar \n";
}
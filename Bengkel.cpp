#include <iostream>
#include <string>
using namespace std;

/*jadi, buat jumlah sparepat, harga servis, memperbarui data(menambah,mengurangi stok), nota pembayaran, 
opsional= jika servis penuh ada opsi delay diservis */

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

//bagian login
void sesilogin(int x,bool bagLogin){
    if(x>=0){
        cout<<"Masukkan Id: ";getline(cin>>ws,login.id);
        cout<<"Masukkan Password: ";getline(cin>>ws,login.pass);
        if(login.id!="k123"||login.pass!="123"){
            cout<<"id atau password anda salah\n";
            cout<<"anda memiliki "<<x<<" kesempatan lagi\n\n";
            sesilogin(x-1,bagLogin);
        }
        else{
            cout<<"halo admin\n";
            x=-2;
            bagLogin=true;
            
        }
    }
    if(x=-1){
        bagLogin=false;
    }
}

int main(){
    system("cls");
    //masih ngebug dibagian loginnya kesempatan habis malah masuk ke menu utama
    int x=2;
    bool bagLogin=true;
    sesilogin(x,bagLogin);
    cout<<x<<endl;
    if (bagLogin==false){
        cout<<"cihuy";
        return 0;
    }
    else{
    int pilih;
    cout<<"====LIST====\n";
    cout<<"1. Sparepat\n";//istilahnya cuman jual barangnya aja 
    cout<<"2. Servis\n";//lebih ke jual barangnya+jasanya(ganti oli/aki) pengecekan/servis,sama kalau ganti oli,bersihin cvt, dll
    cout<<"3. pesanan\n";//lihat pesanan sekaligus, terus mau nambah/bayar/ubah pesanan
    cout<<"4. edit \n";//buat ngedit sparepat/servis
    cout<<"5. Keluar \n";//proses selesai
    cout<<"============\n";
    cout<<"Pilih: ";cin>>pilih;
    switch (pilih)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    default:
        break;
    }
}
}

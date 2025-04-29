#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*jadi, buat jumlah sparepat, harga servis, memperbarui data(menambah,mengurangi stok), nota pembayaran, 
opsional= jika servis penuh ada opsi delay diservis */
bool bagLogin=true;

//konsep tabel baru= sparepart sama servis dijadiin satu, isi nya struct nama, harga, jumlah(sparepart sama sevis dijadiin satu) 

struct usnpasslogin{
    string id= "k123";
    string pass= "123";
};usnpasslogin login;

struct sparepat{
    string nama;
    int jumlah;
    int harga;
};sparepat sp[]={{"busi",10,20000},{"oli",20,50000},{"kampas rem",15,30000},{"lampu",5,10000},{"spion(sepasang)",8,40000}};

struct servis{
    string nama;
    int harga;
};servis sr[]={{"ganti oli",70000},{"ganti busi",50000},{"ganti kampas rem",40000},{"ganti lampu",20000}};

//bagian login
void sesiLogin(int x){
    system("cls");
    if(x>0){
        string usn,password;
        cout<<"Username: ";cin>>usn;
        cout<<"Password: ";cin>>password;
        if(usn!=login.id||password!=login.pass){
            x--;
            cout<<"Username atau Password salah\n";
            cout<<"Tersisa "<<x<<" kesempatan\n\n";
            system("pause");
            sesiLogin(x);
        }
        else{
            cout<<"Login berhasil\n";
            return;
        }
    }
    else{
        cout<<"Kesempatan habis\n";
        exit(0);
    }
}

//sorting taro di list sparepart&servis / di nota juga oke
//nampilin list sparepart
string header1="LIST SPAREPART";
void funcSparepart(){
    cout<<setfill('=')<<setw(44)<<""<<endl;
    cout<<setfill(' ')<<"|"<<left<<setw(42)<<header1<<"|"<<endl;
    cout<<setfill('-')<<"|"<<right<<setw(43)<<"|";
    cout<<setfill(' ')<<"\n| No "<<left<<setw(22)<<"| Nama Barang"<<setw(9)<<"| Harga"<<"| Stok |"<<endl;
    for(int i=0;i<sizeof(sp)/sizeof(sp[0]);i++){
        cout<<setfill(' ')<<left<<"| "<<setw(3)<<i+1<<"| "<<setw(20)<<sp[i].nama<<"| "<<setw(7)<<sp[i].harga<<"| "<<setw(5)<<sp[i].jumlah<<"|"<<endl;
    }
    cout<<setfill('=')<<setw(44)<<""<<endl;
}

//nampilin list servis
string header2="LIST SERVIS";
void funcServis(){
    cout<<setfill('=')<<setw(44)<<""<<endl;
    cout<<setfill(' ')<<"|"<<left<<setw(42)<<header2<<"|"<<endl;
    cout<<setfill('-')<<"|"<<right<<setw(43)<<"|";
    cout<<setfill(' ')<<"\n| No "<<left<<setw(28)<<"| servis"<<setw(10)<<"| Harga"<<"|"<<endl;
    cout<<setfill('-')<<"|"<<right<<setw(43)<<"|"<<endl;
    for(int i=0;i<sizeof(sr)/sizeof(sr[0]);i++){
        cout<<setfill(' ')<<left<<"| "<<setw(3)<<i+1<<"| "<<setw(26)<<sr[i].nama<<"| "<<setw(8)<<sr[i].harga<<"|"<<endl;
    }
    cout<<setfill('=')<<right<<setw(44)<<"";
}

//nampilin apa aja yang udah dipesan abistuh nanya mau nambah pesanan atau nggak, kalau nggak langsung bayar
//niatnya serching pengen ditaro sini
void listNota(){
//pertama dia ngeluarin listnya dulu(keduanya/yang servis aja/dll)
//contoh 1. spion 2.servis cvt 3.ganti oli(servis+oli nya) (sekip dulu lah) tabelnya ubah aja dah jadiin 1 ae biar simple 
    int pilih;

    cout<<"Pilih: ";cin>>pilih;//milih yang ada di list 
    
}

//bagian ngedit layanan(sparepart/servis)
//nah kalo nanti diedit, panjang dari si tabel ga bakal ngikut sama panjang dari konten (done)
void edit(){

}

//berisi sparepart/servis
void layanan(){
    int pilih;
    cout<<"Layanan Produk/Servis\n";
    cout<<"1. Sparepart\n";
    cout<<"2. Servis\n";
    cout<<"Pilih: ";cin>>pilih;
    switch (pilih)
    {
    case 1:
        funcSparepart();
        break;
    case 2:
        funcServis();
        break;
    
    default:
        break;
    }
}

//bagian buat nota/pesanan
void buatPesanan(){
    layanan();
    cout<<"eak";
}

void mainMenu(){
    int pilih;
    cout<<"====LIST====\n";
    cout<<"1. List Layanan\n";//istilahnya cuman jual barangnya aja 
    cout<<"2. Membuat Pesanan\n";//ngebuat pesanan (sparepart sama servis jadi satu)
    cout<<"3. List nota\n";//lihat pesanan sekaligus, terus mau nambah/bayar/ubah pesanan
    cout<<"4. Edit Layanan \n";//buat ngedit isi sparepat/servis
    cout<<"5. Keluar \n";//proses selesai
    cout<<"============\n";
    cout<<"Pilih: ";cin>>pilih;
    switch (pilih)
    {
    case 1:
        layanan();
        break;
    case 2:
        buatPesanan();
        break;
    case 3:
        listNota();
        break;
    case 4:
        edit();
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }

}


int main(){
    system("cls");
    sesiLogin(3);
    mainMenu();
}

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*jadi, buat jumlah sparepat, harga servis, memperbarui data(menambah,mengurangi stok), nota pembayaran, 
opsional= jika servis penuh ada opsi delay diservis */
bool bagLogin=true;

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

void listNota(){
//nampilin apa aja yang udah dipesan abistuh nanya mau nambah pesanan atau nggak, kalau nggak langsung bayar
}

//bagian ngedit layanan(sparepart/servis)
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
    char back;
    do{
        int pilih;
        system("cls");
        cout<<"====LIST====\n";
        cout<<"1. List Layanan\n";//istilahnya cuman jual barangnya aja 
        cout<<"2. Membuat Pesanan\n";//ngebuat pesanan (sparepart sama servis jadi satu)
        cout<<"3. List nota\n";//lihat pesanan sekaligus, terus mau nambah/bayar/ubah pesanan
        cout<<"4. Edit Layanan \n";//buat ngedit isi sparepat/servis
        cout<<"5. Keluar \n";//proses selesai
        cout<<"============\n";
        cout<<"Pilih: ";cin>>pilih; cout<<endl;

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
            cout << "Input tidak valid!\n";
            break;
        }

        cout << "\ningin kembali ke menu utama? (y/n): ";
        cin >> back;
        
        if (back == 'n' || back == 'N'){
        cout << "Terima kasih telah menggunakan program ini.\n";
        exit(0);
        }
        else{
            cout << "Input tidak valid!\n";
            system("pause");
            return mainMenu();
    }
    }while(back=='y'||back=='Y');
}


int main(){
    system("cls");
    sesiLogin(3);
    mainMenu();
}

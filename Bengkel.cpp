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
};sparepat sp[]={
    {"busi",10,20000},
    {"oli",20,50000},
    {"kampas rem",15,30000},
    {"lampu",5,10000},
    {"spion",8,40000}};

struct servis{
    string nama;
    int harga;
};servis sr[]={
    {"ganti oli",70000},
    {"ganti busi",50000},
    {"ganti kampas rem",40000},
    {"ganti lampu",20000}};

struct notes{
    string nama;
    int jumlah;
    int harga;

};

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

void sortingsp(sparepat* sp, int jenis_sparepart){
    for(int i=0;i<jenis_sparepart-1;i++){
        for(int j=0;j<jenis_sparepart-i-1;j++){
            if(sp[j].jumlah<sp[j+1].jumlah){
                swap(sp[j],sp[j+1]);
            }
        }
    }
}

//nampilin list sparepart
string header1="LIST SPAREPART";
void funcSparepart(){
    int x = sizeof(sp)/sizeof(sp[0]);
    sortingsp(sp, x);
    cout<<setfill('=')<<setw(44)<<""<<endl;
    cout<<setfill(' ')<<"|"<<left<<setw(42)<<header1<<"|"<<endl;
    cout<<setfill('-')<<"|"<<right<<setw(43)<<"|";
    cout<<setfill(' ')<<"\n| No "<<left<<setw(22)<<"| Nama Barang"<<setw(9)<<"| Harga"<<"| Stok |"<<endl;
    for(int i=0;i<sizeof(sp)/sizeof(sp[0]);i++){
        cout<<setfill(' ')<<left<<"| "<<setw(3)<<i+1<<"| "<<setw(20)<<sp[i].nama<<"| "<<setw(7)<<sp[i].harga<<"| "<<setw(5)<<sp[i].jumlah<<"|"<<endl;
    }
    cout<<setfill('=')<<setw(44)<<""<<endl;
}

void sortingsr(servis* sr, int jenis_servis){
    for(int i=0;i<jenis_servis-1;i++){
        for(int j=0;j<jenis_servis-i-1;j++){
            if(sr[j].harga<sr[j+1].harga){
                swap(sr[j],sr[j+1]);
            }
        }
    }
}

//nampilin list servis
string header2="LIST SERVIS";
void funcServis(){
    int x = sizeof(sr)/sizeof(sr[0]);
    sortingsr(sr, x);
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

void caricoy(int x){
    string dicari;bool found=false;int l;
    switch (x)
    {
    case 1://sparepart
        cout<<"dicari: ";getline(cin>>ws,dicari);
        for ( int i = 0; i < sizeof(sp)/sizeof(sp[0]); i++)
        {
            if (dicari == sp[i].nama)
            {
                found=true;l=i;
            }
        }
        if (found)
        {
            cout<<"Data ditemukan\n";
            cout<<"Nama : "<<sp[l].nama<<endl;
            cout<<"Stok : "<<sp[l].jumlah<<endl;
            cout<<"Harga: "<<sp[l].harga<<endl;
        }else{cout<<"Data ga ada boi\n";}
        
    break;
    case 2://servis
        cout<<"dicari: ";getline(cin>>ws,dicari);
        for ( int i = 0; i < sizeof(sr)/sizeof(sr[0]); i++)
        {
            if (dicari == sr[i].nama)
            {
                found=true;l=i;
            }
        }
        if (found)
        {
            cout<<"Data ditemukan\n";
            cout<<"Nama : "<<sr[l].nama<<endl;
            cout<<"Harga: "<<sr[l].harga<<endl;
        }else{cout<<"Data ga ada boi\n";}
        
    break;
    
    default:
        break;
    }
}

void searching(){
    int search;
    cout<<"SEARCHING: "<<endl;
    cout<<"1. Sparepart\n";
    cout<<"2. Servis\n";
    cout<<">>";cin>>search;
    switch (search)
    {
    case 1:
        caricoy(search);
        break;
    case 2:
        caricoy(search);
        break;
    
    default:
        searching();
        break;
    }
}

//menmapilkan apa saja yang dipesan serta rinciannya
void listNota(){

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

void fullNota(int *bnykPesanan, notes *&nota){
    cout<<"masuk fullNota\n";
    (*bnykPesanan)+=1;
    notes *baru=new notes[*bnykPesanan];
    for(int i=0; i<*bnykPesanan;i++){
        baru[i]=nota[i];
    }
    delete[] nota;
    nota=baru;
    cout<<"loop selesai\n";
}

//bagian buat nota/pesanan
void buatPesanan(int *bnykPesanan, notes *&nota){
    layanan();
    cout<<"\nPesanan ke-"<<*bnykPesanan+1<<endl;
    //menambah kapasitas struk banyaknya pesanan
    fullNota(bnykPesanan, nota);
    cout<<"banyaknya total pesanan: "<<*bnykPesanan<<endl;
    

}

void mainMenu(int *jmlhPesanan, notes *&nota){
    char back;
    do{
        int pilih;
        system("cls");
        cout<<"====LIST====\n";
        cout<<"1. List Layanan\n";//istilahnya cuman jual barangnya aja 
        cout<<"2. Membuat Pesanan\n";//ngebuat pesanan (sparepart sama servis jadi satu)
        cout<<"3. List nota\n";//lihat pesanan sekaligus, terus mau nambah/bayar/ubah pesanan
        cout<<"4. Edit Layanan \n";//buat ngedit isi sparepat/servis
        cout<<"5. Searching \n";//buat mencari isi sparepat/servis
        cout<<"0. Keluar \n";//proses selesai
        cout<<"============\n";
        cout<<"Pilih: ";cin>>pilih; cout<<endl;

        switch (pilih)
        {
        case 1:
            layanan();
            break;
        case 2:
            buatPesanan(jmlhPesanan,nota);
            cout<<"jumlh pesanan: "<<*jmlhPesanan<<endl;
            break;
        case 3:
            listNota();
            break;
        case 4:
            edit();
            break;
        case 5:
            searching();
            break;
        case 0:
            cout << "teima kasih telah menggunakan program ini.\n";
            exit(0);
            break;
        default:
            cout << "Input tidak valid!\n";
            break;
        }

        cout << "\ningin kembali ke menu utama? (y/n): ";
        cin >> back;
        
    }while(back=='y'||back=='Y');

    if (back == 'n' || back == 'N'){
        cout << "Terima kasih telah menggunakan program ini.\n";
        exit(0);
    }else{
        cout << "Input tidak valid!\n";
        system("pause");
        return mainMenu(jmlhPesanan,nota);
    }
}


int main(){
    int pesanan=0;
    notes *nota=new notes [pesanan];
    system("cls");
    sesiLogin(3);
    mainMenu(&pesanan,nota);
    cout<<"jumlh pesanan(di main menu): "<<pesanan<<endl;
}

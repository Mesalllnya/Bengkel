// Program Bengkel versi final (dengan interface awal & fitur edit hapus layanan)
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct usnpasslogin {
    string id = "k123";
    string pass = "123";
} login;

struct Sparepart {
    string nama;
    int jumlah;
    int harga;
};

struct Servis {
    string nama;
    int harga;
};

struct notes {
    string nama;
    int jumlah;
    int harga;
};

Sparepart* data_sp = nullptr;
Servis* data_sr = nullptr;
int jumlahSparepart = 0;
int jumlahServis = 0;
int jmlhPesanan=0;


void bacaDataSparepart() {
    ifstream file("data_sp.txt");
    if (!file.is_open()) {
        cerr << "Gagal membuka file data_sp.txt\n";
        return;
    }
    string line;
    jumlahSparepart = 0;
    while (getline(file, line)) jumlahSparepart++;
    file.clear(); file.seekg(0);
    data_sp = new Sparepart[jumlahSparepart];
    int i = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        getline(ss, data_sp[i].nama, ',');
        string jumlahStr, hargaStr;
        getline(ss, jumlahStr, ',');
        getline(ss, hargaStr);
        data_sp[i].jumlah = stoi(jumlahStr);
        data_sp[i].harga = stoi(hargaStr);
        i++;
    }
    file.close();
}

void bacaDataServis() {
    ifstream file("data_sr.txt");
    if (!file.is_open()) {
        cerr << "Gagal membuka file data_sr.txt\n";
        return;
    }
    string line;
    jumlahServis = 0;
    while (getline(file, line)) jumlahServis++;
    file.clear();                                       //buat clear status eof dan pindah ke awal file
    file.seekg(0);
    data_sr = new Servis[jumlahServis];
    int i = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        getline(ss, data_sr[i].nama, ',');
        string hargaStr;
        getline(ss, hargaStr);
        data_sr[i].harga = stoi(hargaStr);
        i++;
    }
    file.close();
}

void data_sp_baru(){
    ofstream spare("data_sp.txt");
    if (!spare.is_open()){
        cout<<"file tidak terbuka\n";
        return;
    }
    string temp;
    for (int j = 0; j < jumlahSparepart; j++)
    {
        spare << data_sp[j].nama << "," << data_sp[j].jumlah << "," << data_sp[j].harga << endl;
    }
    //data yang baru akan disimpan ke file data_sp.txt secara urut dari banyaknya stok (sudah ke sorting )
    spare.close();
}

void tambahSparepart() {
    ofstream file("data_sp.txt", ios::app);
    if (!file.is_open()) {
        cout << "Gagal membuka file sparepart untuk ditulis.\n";
        return;
    }
    Sparepart s;
    jumlahSparepart++;
    cout << "\nNama sparepart: "; getline(cin >> ws, s.nama);
    cout << "Jumlah: "; cin >> s.jumlah;
    cout << "Harga: "; cin >> s.harga;
    file << s.nama << "," << s.jumlah << "," << s.harga << endl;
    file.close();
    cout << "Data sparepart ditambahkan.\n";
}

void tambahServis() {
    ofstream file("data_sr.txt", ios::app);
    if (!file.is_open()) {
        cout << "Gagal membuka file servis untuk ditulis.\n";
        return;
    }
    Servis s;
    cout << "\nNama servis: "; getline(cin >> ws, s.nama);
    cout << "Harga: "; cin >> s.harga;
    file << s.nama << "," << s.harga << endl;
    file.close();
    cout << "Data servis ditambahkan.\n";
}

void hapusSparepart() {
    string target;
    cout << "\nNama sparepart yang ingin dihapus: ";
    getline(cin >> ws, target);

    ifstream in("data_sp.txt");
    ofstream out("temp.txt");                   //buat temp
    bool found = false;
    string line;

    while (getline(in, line)) {
        istringstream ss(line);
        string namaSp;
        getline(ss, namaSp, ',');

        if(namaSp == target){
            found = true;
        } else {
            out << line << endl;                //nyimpen line selain target hapus
        }
    }

    in.close();
    out.close();
    remove("data_sp.txt");
    rename("temp.txt", "data_sp.txt");

    if (found) 
        cout << "Sparepart berhasil dihapus.\n";
    else 
        cout << "Sparepart tidak ditemukan.\n";
}

void hapusServis() {
    string target;
    cout << "\nNama servis yang ingin dihapus: ";
    getline(cin >> ws, target);

    ifstream in("data_sr.txt");
    ofstream out("temp.txt");
    bool found = false;
    string line;

    while (getline(in, line)) {
        istringstream ss(line);
        string namaSr;
        getline(ss, namaSr, ',');

        if(namaSr == target){
            found = true;
        } else {
            out << line << endl;       
        }
    }

    in.close();
    out.close();
    remove("data_sr.txt");
    rename("temp.txt", "data_sr.txt");

    if(found) 
        cout << "Servis berhasil dihapus.\n";
    else 
        cout << "Servis tidak ditemukan.\n";
}

void sesiLogin(int x) {
    system("cls");
    if (x > 0) {
        string usn, password;
        cout << "Username: "; cin >> usn;
        cout << "Password: "; cin >> password;
        if (usn != login.id || password != login.pass) {
            x--;
            cout << "\nUsername atau Password salah\n";
            cout << "Tersisa " << x << " kesempatan\n";
            system("pause");
            sesiLogin(x);
        } else {
            cout << "\nLogin berhasil\n";
            system("pause");
        }
    } else {
        cout << "Kesempatan habis";
        exit(0);
    }
}

void sortSparepart() {
    for(int i = 0; i < jumlahSparepart - 1; i++){
        for(int j = 0; j < jumlahSparepart - i - 1; j++){
            if(data_sp[j].jumlah < data_sp[j + 1].jumlah){
                swap(data_sp[j], data_sp[j + 1]);
            }
        }
    }
}

void sortServis() {
    for(int i = 0; i < jumlahServis - 1; i++){
        for(int j = 0; j < jumlahServis - i - 1; j++){
            if(data_sr[j].harga < data_sr[j + 1].harga){
                swap(data_sr[j], data_sr[j + 1]);
            }
        }
    }
}

string header1 = "LIST SPAREPART";
void funcSparepart() {
    system("cls");
    sortSparepart();
    cout << endl;
    cout << setfill('=') << setw(44) << "" << endl;
    cout << setfill(' ') << "|" << left << setw(42) << header1 << "|" << endl;
    cout << setfill('-') << "|" << right << setw(43) << "|" << endl;
    cout << setfill(' ') << "| No " << left << setw(22) << "| Nama Barang" << setw(9) << "| Harga" << "| Stok |" << endl;
    cout << setfill('-') << "|" << right << setw(43) << "|" << endl;
    for(int i = 0; i < jumlahSparepart; i++){
        cout << setfill(' ') << left << "| " << setw(3) << i + 1 << "| " << setw(20) << data_sp[i].nama << "| " << setw(7) << data_sp[i].harga << "| " << setw(5) << data_sp[i].jumlah << "|" << endl;
    }
    cout << setfill('=') << setw(44) << "" << endl;
}

string header2 = "LIST SERVIS";
void funcServis() {
    system("cls");
    sortServis();
    cout << endl;
    cout << setfill('=') << setw(44) << "" << endl;
    cout << setfill(' ') << "|" << left << setw(42) << header2 << "|" << endl;
    cout << setfill('-') << "|" << right << setw(43) << "|" << endl;
    cout << setfill(' ') << "| No " << left << setw(28) << "| Servis" << setw(10) << "| Harga" << "|" << endl;
    cout << setfill('-') << "|" << right << setw(43) << "|" << endl;
    for (int i = 0; i < jumlahServis; i++) {
        cout << setfill(' ') << left << "| " << setw(3) << i + 1 << "| " << setw(26) << data_sr[i].nama << "| " << setw(8) << data_sr[i].harga << "|" << endl;
    }
    cout << setfill('=') << setw(44) << "" << endl;
}

void editLayanan() {
    int pilih, opsi;
    system("cls");
    cout << "\n=== EDIT LAYANAN === \n1. Sparepart\n2. Servis\nPilih: ";
    cin >> pilih;

    if(pilih == 1){
        cout << "\n1. Tambah Sparepart\n2. Hapus Sparepart\nPilih: ";
        cin >> opsi;

        funcSparepart();
        if(opsi == 1) 
            tambahSparepart();
        else if(opsi == 2)     
            hapusSparepart();
        else     
            cout << "Pilihan tidak valid.\n";
        
        delete[] data_sp;    
        bacaDataSparepart();                                           //nyimpen perubahan

    } else if(pilih == 2){
        cout << "\n1. Tambah Servis\n2. Hapus Servis\nPilih: ";
        cin >> opsi;

        funcServis();
        if(opsi == 1) 
            tambahServis();
        else if(opsi == 2)     
            hapusServis();
        else     
            cout << "Pilihan tidak valid.\n";
        
        delete[] data_sr;    
        bacaDataServis();

    } else {
        cout << "Pilihan tidak valid.\n";
        editLayanan();
    }    
}    

void layanan() {
    int pilih;
    cout << "\nLayanan Sparepart/Servis\n";
    cout << "1. Sparepart\n";
    cout << "2. Servis\n";
    cout << "Pilih: "; 
    cin >> pilih;
    switch(pilih){
        case 1: funcSparepart(); 
            break;
        case 2: funcServis(); 
            break;
        default: cout << "Pilihan tidak valid"; 
            return ;
            break;
    }
}

void caricoy(int pilih) {
    string dicari;
    cout << "\nMau Cari Apa? ";
    getline(cin >> ws, dicari);
    bool found = false;

    if (pilih == 1) {
        for (int i = 0; i < jumlahSparepart; i++) {
            if (data_sp[i].nama == dicari) {
                found = true;
                system("cls"); 
                cout << "\nData ditemukan!\n\n";
                cout << "Nama  : " << data_sp[i].nama << endl;
                cout << "Stok  : " << data_sp[i].jumlah << endl;
                cout << "Harga : " << data_sp[i].harga << endl;
                break;
            }
        }
    } else if (pilih == 2) {
        for (int i = 0; i < jumlahServis; i++) {
            if (data_sr[i].nama == dicari) {
                found = true;
                system("cls");
                cout << "\nData ditemukan!\n\n";
                cout << "Nama  : " << data_sr[i].nama << endl; 
                cout << "Harga : " << data_sr[i].harga << endl;
                break;
            }
        }
    }
    if (!found) cout << "\nData tidak ditemukan.\n";
}

void searching() {
    int pilihan;
    system("cls");
    cout << "\n=== SEARCHING ===\n";
    cout << "1. Sparepart\n";
    cout << "2. Servis\n";
    cout << "Pilih : "; cin >> pilihan;
    switch(pilihan){
        case 1:
            caricoy(pilihan);
            break;
        case 2:
            caricoy(pilihan);
            break;
        default: 
            cout << "Pilihan tidak valid!\n"; 
            system("pause");
            searching();
    }
}

//menambah array dinamis
void fullNota(int* bnykPesanan, notes*& nota, int* maksData) {
    (*bnykPesanan)++;
    (*maksData)++;
    notes* baru = new notes[*maksData];
    for (int i = 0; i < *bnykPesanan - 1; i++) {
        baru[i] = nota[i];
    }
    delete[] nota;
    nota = baru;
}

void buatPesanan(int* bnykPesanan, notes*& nota, int* maksData) {
    system("cls");
    layanan();
    
    string input;int jumlahBeli;
    cout << "Pesanan ke-" << *bnykPesanan + 1 << endl;
    cout << "Masukkan nama pesanan: "; getline(cin >> ws, input);
    fullNota(bnykPesanan, nota, maksData);
    
    bool found = false;
    for (int i = 0; i < jumlahSparepart; i++) {
        if (input == data_sp[i].nama) {
            cout<<"jumlah: ";cin>>jumlahBeli;
            //pengecekan bila banyak barang yang dibeli tidak bisa lebih banyak dari stok yang ada
            if(!(jumlahBeli>data_sp[i].jumlah)){
                data_sp[i].jumlah-=jumlahBeli;//stok langsung berkurang
                //menginput banyaknya pesanan dan mengkalikannya dng harga
                nota[*bnykPesanan - 1] = {input, jumlahBeli, (data_sp[i].harga)*jumlahBeli};
                found = true;
                cout << "Berhasil Membuat Pesanan Sparepart.\n";
                data_sp_baru();
                
            }else{
                cout<<"jumlah tidak mencukupi\n";
                found = true;
                (*bnykPesanan)--;
            }
            break;
        }
    }
    
    for (int i = 0; i < jumlahServis && !found; i++) {
        if (input == data_sr[i].nama) {
            nota[*bnykPesanan - 1] = { input, 0, data_sr[i].harga };
            found = true; 
            cout << "Berhasil Membuat Pesanan Servis.\n";
            break;
        }
    }
    if (!found) {
        cout << "Produk/jasa tidak ditemukan!";
        (*bnykPesanan)--;
    }
}

void hapusPesanan(int nodihapus, int *bnykPesanan,notes *&nota, int *maksData){
    if (nodihapus<0 && nodihapus>*bnykPesanan){
        cout<<"data tidak valid\n";
    }else{
        //pengembalian stok jika sparepart
        bool sparepart=false;
        for (int i = 0; i < jumlahSparepart; i++){
            if (nota[nodihapus].nama==data_sp[i].nama){
                data_sp[i].jumlah+=nota[nodihapus].jumlah;
                sparepart=true;
            }
        }

        //geser urutan pesanan
        for (int i = nodihapus; i < *bnykPesanan-1; i++){
            nota[i]=nota[i+1];
        }
        //pengurangan jumlah nota & struct array dinamis nota 
        (*bnykPesanan)--;
        (*maksData)--;

        //maksimal datanya diturunkan
        notes *temp=new notes[*maksData];
        for (size_t i = 0; i < *bnykPesanan; i++){
            temp[i]=nota[i];
        }
        delete[] nota;
        nota=temp;
        cout<<"Pesanan berhasil dihapus\n";
    }
    
}

void listNota(int* bnykPesanan, notes*& nota, int* maksData, string waktu) {
    if (*bnykPesanan == 0) {
        cout << "Belum ada pesanan.\n";
        return;
    }
    int totalHarga=0;
    cout << "=== LIST NOTA PESANAN ===\n";
    cout<<setw(57)<<setfill('-')<<""<<endl;
    cout<<setw(6)<<"| No |"<<setfill(' ')<<setw(20)<<right<<"Nama Produk/Jasa"<<setfill(' ')<<setw(16)<<"| Jumlah "<<"| "<<setw(14)<<"Harga  |\n";    
    for (int i = 0; i < *bnykPesanan; i++) {
        cout<<"| "<< i + 1 << ". |"<<setw(16)<<setfill(' ')<<left<<nota[i].nama<<setfill(' ')<<right<<setw(13)<<"| "<<setw(4)<<nota[i].jumlah<<setw(5)<<"| "<<setw(10)<< nota[i].harga <<"  |\n";
        totalHarga+=nota[i].harga;
    }
    cout<<setw(57)<<setfill('-')<<""<<endl;
    cout<<"Total: "<<totalHarga<<endl<<endl;

    string pilih;
    cout<<"1. hapus\n";
    cout<<"2. bayar\n";
    cout<<"!(1&2)=default\n";
    cout<<">> ";cin>>pilih;
    switch (pilih[0])
    {
    case '1':{
        int hapus;
        cout<<"menu hapus pesanan\n";
        int totalHarga=0;
        cout<<setw(57)<<setfill('-')<<""<<endl;
        cout<<setw(6)<<"| No |"<<setfill(' ')<<setw(20)<<right<<"Nama Produk/Jasa"<<setfill(' ')<<setw(16)<<"| Jumlah "<<"| "<<setw(14)<<"Harga  |\n";    
        for (int i = 0; i < *bnykPesanan; i++) {
        cout<<"| "<< i + 1 << ". |"<<setw(16)<<setfill(' ')<<left<<nota[i].nama<<setfill(' ')<<right<<setw(13)<<"| "<<setw(4)<<nota[i].jumlah<<setw(5)<<"| "<<setw(10)<< nota[i].harga <<"  |\n";
        totalHarga+=nota[i].harga;
        }
        cout<<setw(57)<<setfill('-')<<""<<endl;
        cout<<"Total: "<<totalHarga<<endl<<endl;
        cout<<"no pesanan yang ingin di hapus: ";cin>>hapus;
        if (hapus>0&&hapus<=*bnykPesanan){
            hapusPesanan(hapus-1,bnykPesanan,nota,maksData);
        }else{
            cout<<"data tidak valid\n";
        }
    }
    break;

    case '2':{
        bool loop=true;

        while(loop){
        int totalHarga=0;
        system("cls");
        cout<<"menu bayar\n";
        int nominal,kembalian;

        // bayar dulu abistuh baru simpen datanya ke file
        cout<<setw(57)<<setfill('-')<<""<<endl;
        cout<<setw(6)<<"| No |"<<setfill(' ')<<setw(20)<<right<<"Nama Produk/Jasa"<<setfill(' ')<<setw(16)<<"| Jumlah "<<"| "<<setw(14)<<"Harga  |\n";    
        for (int i = 0; i < *bnykPesanan; i++) {
        cout<<"| "<< i + 1 << ". |"<<setw(16)<<setfill(' ')<<left<<nota[i].nama<<setfill(' ')<<right<<setw(13)<<"| "<<setw(4)<<nota[i].jumlah<<setw(5)<<"| "<<setw(10)<< nota[i].harga <<"  |\n";
        totalHarga+=nota[i].harga;
        }
        cout<<setw(57)<<setfill('-')<<""<<endl;
        cout<<"Total: "<<totalHarga<<endl<<endl;

        cout<<"masukkan nominal: ";cin>>nominal;
        if (nominal<totalHarga){
            cout<<"uang kurang\n";
            system("pause");
        }else{
            kembalian=nominal-totalHarga;
            ofstream file("RT("+waktu+").txt",ios::app);
            if(file.is_open()){
            for (int i = 0; i < *bnykPesanan; i++)
            {
                file<<nota[i].nama<<","
                    <<nota[i].jumlah<<","
                    <<nota[i].harga<<endl;
            }
            file<<"total harga: "<<totalHarga<<endl<<endl;
            file.close();

            (*maksData)=1;
            (*bnykPesanan)=0;
            notes *temp=new notes[*maksData];
            delete[] nota;
            nota=temp;
            loop=false;
            }else{
                cout<<"file tidak terbuka\n";
            }
        }
        }
    }   
    break;
    
    default:
        cout<<"pilihan tidak valid!!!\n";
        return;
    break;
    }
    
}

void mainMenu(int* jmlhPesanan, notes*& nota, int* maksData,string waktu) {
    char back;
    do {
        int pilih;
        system("cls");
        cout << "==== MENU UTAMA ====" << endl;
        cout << "1. List Layanan" << endl;
        cout << "2. Buat Pesanan" << endl;
        cout << "3. List Nota" << endl;
        cout << "4. Searching" << endl;
        cout << "5. Edit Layanan" << endl;
        cout << "0. Logout" << endl;
        cout << "Pilih: "; cin >> pilih;

        switch (pilih) {
            case 1: layanan(); 
                break;
            case 2: buatPesanan(jmlhPesanan, nota, maksData); 
                break;
            case 3: listNota(jmlhPesanan, nota, maksData,waktu); 
                break;
            case 4: searching(); 
                break;
            case 5: editLayanan(); 
                break;
            case 0: 
                return;
            default: 
                cout << "Pilihan tidak valid!\n"; 
                break;
        }

        cout << "\nKembali ke menu utama? (y/n) : "; cin >> back;
        if(back!='y'||back!='Y'){
            cout<<"Terima kasih telah menggunakan program ini.\n";
        }
    } while (back == 'y' || back == 'Y');
}

// void data_sp_baru(){
//     ofstream spare("data_sp.txt");
//     if (!spare.is_open()){
//         cout<<"file tidak terbuka\n";
//         return;
//     }
//     string temp;
//     for (int j = 0; j < jumlahSparepart; j++)
//     {
//         spare << data_sp[j].nama << "," << data_sp[j].jumlah << "," << data_sp[j].harga << endl;
//     }
//     //data yang baru akan disimpan ke file data_sp.txt secara urut dari banyaknya stok (sudah ke sorting )
//     spare.close();
// }

void interfaceAwal() {
    while (true) {
        int pilih; 
        system("cls");
        cout << "=== Menu Awal ===\n";
        cout << "1. Login\n";
        cout << "2. Exit\n";
        cout << "Pilih : ";
        cin >> pilih;
        if (pilih == 1) {
            sesiLogin(3);
            system("cls");
            int pesanan = 0, maksData = 1;string waktu;
            notes* nota = new notes[maksData];
            bacaDataSparepart();
            bacaDataServis();
            cout<<"masukkan tgl(dd-mm-yyyy): ";cin>>waktu;
            mainMenu(&pesanan, nota, &maksData,waktu);
            data_sp_baru();

            delete[] nota;
            delete[] data_sp;
            delete[] data_sr;
        } else if (pilih == 2) {
            cout << "Terima kasih telah menggunakan program ini.";
            exit(0);
        } else {
            cout << "Pilihan tidak valid!";
        }
        system("pause");
    }
}

int main() {
    interfaceAwal();
    return 0;
}

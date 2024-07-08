#include <iostream> 
using namespace std;
class MasukUniversitas {
protected: // isi access modifier disini 
    int uangPendaftaran;
    int uangSemesterPertama;
    int uangBangunan;
    int totalBiaya;// isi daftar variable yang dibutuhkan di bawah ini 

public:
    MasukUniversitas() {
        uangPendaftaran = 0;
        uangSemesterPertama = 0;
        uangBangunan = 0;
        totalBiaya = 0;  // isi nilai default variable yang dibutuhkan di bawah ini 
    }

    virtual void namaJalurMasuk() { return; }
    // isi disini dengan fungsi virtual yang dibutuhkan 
    virtual string namaJalurMasuk() const = 0;

    void setUangPendaftaran(int upendaftaran) {uangPendaftaran = upendaftaran;
        this->uangPendaftaran = upendaftaran;
    }
    void setUangSemesterPertama(int usemesterp) { uangSemesterPertama = usemesterp; 
        this ->uangSemesterPertama = usemesterp;
    }

    void setUangBangunan(int ubangunan) { uangBangunan = ubangunan; 
        this->uangBangunan = ubangunan;
    }

    void setTotalBiaya(int totalbiaya) { totalBiaya = totalbiaya; 
        this->totalBiaya = totalbiaya;
    }

    float setUangPendaftaran() { 
        return uangPendaftaran;
        return uangSemesterPertama;
        return uangBangunan;
        return totalBiaya;
    }


    // isi setter dan getter variable yang dibutuhkan di bawah ini 
    virtual void input() = 0;
    virtual void hitungTotalBiaya() = 0;
    virtual void tampilkanTotalBiaya() const = 0;
   
};

class SNBT: public MasukUniversitas{
    // isi disini untuk melengkapi class SNBT 

    public:
        string namaJalurMasuk() const override {
            return "SNBT";
        }

        void input() override {
            cout << "Masukkan uang pendaftaran: ";
            cin >> uangPendaftaran;
            cout << "Masukkan uang semester pertama: ";
            cin >> uangSemesterPertama;
            cout << "Masukkan uang bangunan: ";
            cin >> uangBangunan;
        }

        void hitungTotalBiaya() override {
            totalBiaya = uangPendaftaran + uangSemesterPertama + uangBangunan;
        }

        void tampilkanTotalBiaya() const override {
            cout << "Total Biaya (SNBT): " << totalBiaya << endl;
            if (totalBiaya > 20000000) {
                cout << "Kategori: Mahal" << endl;
            }
            else if (totalBiaya > 10000000) {
                cout << "Kategori: Sedang" << endl;
            }
            else {
                cout << "Kategori: Murah" << endl;
            }
        }
};

class SNBP : public MasukUniversitas {
    // isi disini untuk melengkapi class SNBP 
public:
    string namaJalurMasuk() const override {
        return "SNBP";
    }

    void input() override {
        cout << "Masukkan uang pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan uang semester pertama: ";
        cin >> uangSemesterPertama;
    }

    void hitungTotalBiaya() override {
        totalBiaya = uangPendaftaran + uangSemesterPertama;
    }

    void tampilkanTotalBiaya() const override {
        cout << "Total Biaya (SNBP): " << totalBiaya << endl;
        if (totalBiaya > 20000000) {
            cout << "Kategori: Mahal" << endl;
        }
        else if (totalBiaya > 10000000) {
            cout << "Kategori: Sedang" << endl;
        }
        else {
            cout << "Kategori: Murah" << endl;
        }
    }
};

int main() {
    // isi disini untuk fungsi main
    cout << "Selamat datang di jalur masuk universitas" << endl;
    cout << "Pilih jalur masuk:" << endl;
    cout << "1. SNBT" << endl;
    cout << "2. SNBP" << endl;
    int pilihan;
    cout << "Masukkan pilihan Anda: ";
    cin >> pilihan;


    MasukUniversitas* jalurMasuk = nullptr;

    if (pilihan == 1) {
        jalurMasuk = new SNBT();
    }
    else if (pilihan == 2) {
        jalurMasuk = new SNBP();
    }
    else {
        cout << "Pilihan tidak tersedia" << endl;
        return 1;
    }

    jalurMasuk->input();
    jalurMasuk->hitungTotalBiaya();
    jalurMasuk->tampilkanTotalBiaya();

    delete jalurMasuk;
    return 0;


}
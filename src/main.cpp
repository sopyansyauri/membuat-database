#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Mahasiswa{
    public:
        string nama;
        string jurusan;

        Mahasiswa(string isiNama, string isiJurusan)
        {
            Mahasiswa::nama = isiNama;
            Mahasiswa::jurusan = isiJurusan;
        }

        string stringData() {
            return "Nama: " + nama + "\n" + "Jurusan: " + jurusan + "\n \n";
        }

};

class DB {
    public:
        ifstream in;
        ofstream out;
        string filenama;

        DB(const char *isifilename)
        {
            DB::filenama = isifilename;
        }

        void save(Mahasiswa IsiData) {
            cout << IsiData.nama << endl;
            cout << IsiData.jurusan << endl;

            DB::out.open(DB::filenama,ios::app);
            DB::out << IsiData.stringData();
            DB::out.close();

        }
};

int main()
{
    string Nama, Jurusan;

    cout << "MASUKAN DATA MAHASISWA \n";
    cout << "Nama: ";
    getline(cin, Nama);
    cout << "Jurusan: ";
    getline(cin, Jurusan);

    // Membuat Objek Objek yang diperlukan
    Mahasiswa murid1 = Mahasiswa(Nama, Jurusan);
    DB database = DB("data.txt");

    // Save data ke database
    database.save(murid1);
    return 0;
}
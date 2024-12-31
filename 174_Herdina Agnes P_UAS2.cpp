#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient {
public:
    string name;
    int age;

    Patient(string n, int a) : name(n), age(a) {}
};

void displayPatients(const vector<Patient>& patients) {
    cout << "Daftar Pasien:" << endl;
    for (size_t i = 0; i < patients.size(); ++i) {
        cout << i + 1 << ". Nama: " << patients[i].name << ", Usia: " << patients[i].age << " tahun" << endl;
    }
}

void addPatient(vector<Patient>& patients) {
    string name;
    int age;
    cout << "Masukkan nama pasien: ";
    cin.ignore();
    getline(cin, name);
    cout << "Masukkan usia pasien: ";
    cin >> age;
    patients.push_back(Patient(name, age));
    cout << "Pasien berhasil ditambahkan!" << endl;
}

void displayPatientsByAge(const vector<Patient>& patients, int minAge, int maxAge) {
    cout << "Daftar Pasien dengan Usia antara " << minAge << " dan " << maxAge << " tahun:" << endl;
    for (const auto& patient : patients) {
        if (patient.age >= minAge && patient.age <= maxAge) {
            cout << "Nama: " << patient.name << ", Usia: " << patient.age << " tahun" << endl;
        }
    }
}

int main() {
    vector<Patient> patients;
    int choice;

    do {
        cout << "\nAplikasi Pengelolaan Data Pasien" << endl;
        cout << "1. Tambah Pasien" << endl;
        cout << "2. Lihat Semua Pasien" << endl;
        cout << "3. Lihat Pasien Berdasarkan Usia" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addPatient(patients);
            break;
        case 2:
            displayPatients(patients);
            break;
        case 3:
            int minAge, maxAge;
            cout << "Masukkan usia minimum: ";
            cin >> minAge;
            cout << "Masukkan usia maksimum: ";
            cin >> maxAge;
            displayPatientsByAge(patients, minAge, maxAge);
            break;
        case 4:
            cout << "Keluar dari aplikasi." << endl;
            break;
        default:
            cout << "Opsi tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}
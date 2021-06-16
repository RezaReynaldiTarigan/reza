#include <iostream>
#include "kamus.h"
#include <windows.h>
#include <string.h>
using namespace std;

int main()
{
    ListP L1;
    ListC L2;
    ListR L3;
    createListP(L1);
    createListC(L2);
    createListR(L3);
    adrC C;
    adrP P;
    adrR R;
    string ayah,ibu,nama_anak;
    int pil;

    do{
        system("cls");
        cout << " 1. Input Data Orang Tua "<<endl;
        cout << " 2. Input Data Anak "<<endl;
        cout << " 3. Relasi Orang Tua dengan Anak "<<endl;
        cout << " 4. Hapus Orang Tua "<<endl;
        cout << " 5. Hapus Anak "<<endl;
        cout << " 6. Tampil Data Orang Tua beserta Data Anak "<<endl;
        cout << " 7. Tampil Data Anak tertentu dan Orang Tua "<<endl;
        cout << " 8. Tampil Data Orang Tua tertentu dan anak "<<endl;
        cout << " 9. Tampil Data Orang Tua dengan anak paling banyak dan paling sedikit "<<endl;
        cout << " 0. EXIT "<<endl;
        cout << " Masukkan Pilihan : ";
        cin >> pil;
        switch(pil){
        case 1 :
            system("cls");
            cout<< "Masukkan Nama Ayah : ";
            getline(cin >> std::ws,ayah);
            cout<<endl;
            cout<< "Masukkan Ibu : ";
            getline(cin >> std::ws,ibu);
            cout<<endl;
            if(ayah != "" && ibu != ""){
                P = alokasiParent(ayah,ibu);
                tambahOrangTua(L1,P);
                cout<< "Data Orang Tua berhasil ditambahkan"<<endl;
            }
            system("pause");
            break;
        case 2 :
            system("cls");
            cout<< "Masukkan Nama Anak : "; getline(cin >> std::ws,nama_anak);
            cout<<endl;
            if(!searchAnak(L2,nama_anak)){
                C = alokasiChild(nama_anak);
                tambahAnak(L2,C);
                cout<< "Data Anak berhasil ditambahkan"<<endl;
            }else{
                cout<< "Data Anak Sudah ada"<<endl;
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(first(L1) != NULL && first(L2) != NULL){
                printOnlyOrangTua(L1);
                cout<<endl;
                cout<<endl;
                printOnlyAnak(L2);
                cout<<endl;
                cout<<endl;

                cout<< "Masukkan Nama Ayah yang ingin ditambahkan relasi : ";  getline(cin >> std::ws,ayah);
                cout<<endl;
                P = searchOrangTua(L1,ayah);
                if(P == NULL){
                    cout << "Salah Input Nama Ayah"<<endl;

                }
                cout<<endl;
                cout << "Masukkan Nama Anak yang ingin direlasikan dengan Orang Tua : "; getline(cin >> std::ws,nama_anak);
                C = searchAnak(L2,nama_anak);
                if(C == NULL){
                    cout<<"Salah Input Nama Anak"<<endl;
                }
                cout<<endl;
                if(P != NULL && C != NULL){
                        R = alokasiRelasi(P,C);
                        tambahRelasi(L3,R);
                        cout<<endl;
                        cout<< "Data Orang Tua dan Anak Berhasil direlasikan"<<endl;

                }else{
                    cout<< "Anak atau Orang Tua salah Nama Ayah / Anak"<<endl;

                }
            }else{
                cout << "Data Orang Tua atau Data Anak Kosong"<<endl;
            }
            system("pause");
            break;
        case 5 :
            system("cls");
            printOnlyAnak(L2);
            cout<<endl;
            if(first(L2) != NULL){
                cout<< "Masukkan Anak yang ingin dihapus : "; getline(cin >> std::ws,nama_anak);
                C = searchAnak(L2,nama_anak);
                cout<<endl;
                if(C != NULL){
                    R = first(L3);
                    while(R != NULL){
                        if(C == addressC(R)){
                            deleteRelasi(L3,R);
                        }
                        R = next(R);
                    }
                    deleteAnak(L2,C);
                    cout << "Data Anak berhasil dihapus"<<endl;
                }else{
                    cout << "Data Anak tidak ada"<<endl;
                }
            }else{
                cout << "Data Anak tidak ada"<<endl;
            }
            system("pause");
            break;
        case 4 :
            system("cls");
            printOnlyOrangTua(L1);
            cout<<endl;
            if(first(L1) != NULL){
                cout<< "Masukkan Nama Ayah yang ingin dihapus : "; getline(cin >> std::ws,ayah);
                P = searchOrangTua(L1,ayah);
                cout<<endl;
                if(P != NULL){
                    R = first(L3);
                    while(R != NULL){
                        if(P == addressP(R)){
                            deleteRelasi(L3,R);
                        }
                        R = next(R);
                    }
                    deleteOrangTua(L1,P);
                    cout << "Data Orang Tua berhasil dihapus"<<endl;
                }else{
                    cout << "Data Orang Tua tidak ada"<<endl;
                }
            }else{
                cout << "Data Orang Tua tidak ada"<<endl;
            }
            system("pause");
            break;
        case 6 :
            system("cls");
            printOrangTua(L1,L3);
            cout<<endl;
            system("pause");
            break;
        case 8 :
            system("cls");
            printOnlyOrangTua(L1);
            cout<<endl;
            if(first(L1) != NULL){
                cout<< "Masukkan Nama Ayah yang ingin dicari data Anak : "; getline(cin >> std::ws,ayah);
                cout<<endl;
                P = searchOrangTua(L1,ayah);
                if(P != NULL){
                    cout<<endl;
                    printOrangTuaTertentu(L1,L3,P);
                    cout<<endl;
                }else{
                    cout<< "Inputan nama Ayah SALAH"<<endl;
                }
            }else{
                cout << "Data Orang Tua Kosong"<<endl;
            }
            system("pause");
            break;
        case 7:
            system("cls");
            printOnlyAnak(L2);
            cout<<endl;
            if(first(L2) != NULL){
                cout<< "Masukkan Nama Anak  yang ingin dicari data Orang Tuanya : "; getline(cin >> std::ws,nama_anak);
                cout<<endl;
                C = searchAnak(L2,nama_anak);
                cout<<endl;
                if(C != NULL){
                    printAnakTertentu(L2,L3,C);
                    cout<<endl;
                }else{
                    cout<< "Salah input nama Anak "<<endl;
                }
            }else{
                cout << "Data Anak tidak ada"<<endl;
            }
            system("pause");
            break;
        case 9:
            system("cls");
            printOnlyOrangTua(L1);
            cout<<endl;
            if(first(L2) != NULL){
                printMinMax(L1,L3);
                cout<<endl;
            }else{
                cout << "Data Orang Tua Kosong"<<endl;
            }
            system("pause");
            break;
        default :
            system("cls");
            break;
            cout<<endl;

        }

    }while(pil != 0);

}

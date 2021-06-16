#include "kamus.h"

void createListP(ListP &L1){
    first(L1) = NULL;
}
void createListC(ListC &L2){
    first(L2) = NULL;
}
void createListR(ListR &L3){
    first(L3) = NULL;
}
adrP alokasiParent(string ayah,string ibu){
    adrP P = new elmParent;
    info(P).ayah = ayah;
    info(P).ibu = ibu;
    next(P) = NULL;
    prev(P) = NULL;

    return P;

}
adrC alokasiChild (string nama_anak){
    adrC C = new elmChild;
    info(C).nama_anak = nama_anak;
    next(C) = NULL;

    return C;

}
adrR alokasiRelasi (adrP P,adrC C){
    adrR R = new elmRelasi;
    addressP(R) = P;
    addressC(R) = C;
    next(R) = NULL;

    return R;

}

void tambahOrangTua(ListP &L1, adrP P){
    if(first(L1) == NULL){
        first(L1) = P;
    }else{
        if(info(first(L1)).ayah > info(P).ayah){
            //Insert First
            next(P) = first(L1);
            prev(first(L1)) = P;
            first(L1) = P;

        }else if(info(first(L1)).ayah < info(P).ayah){
            // Insert Last
            adrP C = first(L1);
            while(next(C) != NULL){
                C = next(C);
            }
            next(C) = P;
            prev(P) = C;

        }
    }

}
void deleteOrangTua(ListP &L1,adrP &P){
    if(first(L1) != NULL){
        if(first(L1) == P){
            // Delete First
            if(next(first(L1)) == NULL){
                P = first(L1);
                next(P) = NULL;
                prev(P) = NULL;
                first(L1) = NULL;
            }else{
                P = first(L1);
                first(L1) = next(P);
                next(P) = NULL;

            }
        }else{
            adrP C = first(L1);
            while(next(C) != P){
                C = next(C);
            }
            if(next(P) == NULL){
                // Delete Last
                next(C) = NULL;
            }else{
                // Delete After
                next(C) = next(P);
                prev(next(P)) = C;
                next(P) = NULL;
            }


        }
    }

}

void tambahAnak(ListC &L2, adrC C){
    if(first(L2) == NULL){
        // Insert First
        first(L2) = C;
        next(C) = first(L2);
    }else{
        // Insert Last
        adrC P = first(L2);
        while (next(P) != first(L2)){
            P = next(P);
        }
        next(C) = first(L2);
        next(P) = C;
        first(L2) = C;
    }


}
void deleteAnak(ListC &L2, adrC &C){
    if(first(L2) != NULL){
        if(first(L2) == C){
            //Delete First
            if(next(first(L2)) == first(L2)){
                C = first(L2);
                next(C) = NULL;
                first(L2) = NULL;
            }else{
                adrC P = first(L2);
                while (next(P) != first(L2)){
                    P = next(P);
                }
                C = first(L2);
                next(P) = next(C);
                first(L2) = next(C);
                next(C) = NULL;
            }
        }else{
            adrC P = first(L2);
            while (next(P) != C){
                P = next(P);
            }
            // Delete Last
            if(next(C) == first(L2)){
                next(P) = first(L2);
                next(C) = NULL;
            }else{
            // Delete After
                next(C) = next(P);
                next(P) = NULL;
            }
        }
    }

}
void tambahRelasi(ListR &L3, adrR R){
    if(first(L3) == NULL){
        first(L3) = R;
    }else{
        // Insert Last
        adrR P = first(L3);
        while(next(P) != NULL){
            P = next(P);
        }
        next(P) = R;
    }

}
void deleteRelasi(ListR &L3, adrR &R){
    if(first(L3) != NULL){
        if(R == first(L3)){
            // Delete First
            if(next(first(L3)) == NULL){
                R = first(L3);
                next(R) = NULL;
                first(L3) = NULL;
            }else{
                R = first(L3);
                first(L3) = next(R);
                next(R) = NULL;
            }
        }else{
            adrR P = first(L3);
            while(next(P) != R){
                P = next(P);
            }
            if(next(R) == NULL){
                //Delete Last
                next(P) = NULL;
            }else{
                //Delete After
                next(P) = next(R);
                next(R) = NULL;
            }
        }
    }

}
adrP searchOrangTua(ListP L1, string ayah){
    if(first(L1) != NULL){
        adrP P = first(L1);
        while(next(P) != NULL && info(P).ayah != ayah){
            P = next(P);
        }
        if(info(P).ayah == ayah){
            return P;
        }
        return NULL;
    }else{
        cout<<"Data Kosong"<<endl;
        return NULL;
    }

}


adrC searchAnak(ListC L2,string nama){
    if(first(L2) != NULL){
        adrC P = first(L2);
        while(next(P) != first(L2) && info(P).nama_anak != nama){
            P = next(P);
        }
        if(info(P).nama_anak == nama){
            return P;
        }
        return NULL;
    }else{
        cout<<"Data Kosong"<<endl;
        return NULL;
    }

}
void printOrangTua(ListP L1, ListR L3){
    if(first(L1) != NULL && first(L3) != NULL){
        adrP P;
        adrR R;
        cout << "Data Detail Orang Tua "<<endl;
        cout << "Nama Ayah : "<< "\t\t\tNama Ibu "<<"\t\t\t Nama Anak"<<endl;
        P = first(L1);
        do{
             R = first(L3);
            do{
                if(P == addressP(R)){
                    cout<<info(P).ayah<<"\t\t\t\t"<<info(P).ibu<<"\t\t\t\t\t"<<info(addressC(R)).nama_anak<<endl;
                }
                R = next(R);

            }while(R != NULL);

            P = next(P);

        }while(P != NULL);

    }else{
        cout<<"Data Kosong"<<endl;
    }

}
void printAnak(ListC L2, ListR L3){
    if(first(L2) != NULL && first(L3) != NULL){
        adrC P = first(L2);
        cout<< "Data Detail Anak"<<endl;
        cout<< "Nama Anak"<<"\t\t\t Nama Ayah"<<"\t\t"<<"Nama Ibu "<<endl;
        do{
            adrR R = first(L3);
            do{
                if(P == addressC(R)){
                    cout<< info(P).nama_anak<<"\t\t\t"<<info(addressP(R)).ayah<<"\t\t"<<info(addressP(R)).ibu<<endl;
                }
                R = next(R);

            }while(R != NULL);

            P = next(P);

        }while(P != first(L2));

    }else{
        cout<< "Data Kosong "<<endl;
    }

}
void printMinMax (ListP L1,ListR L3){
    if(first(L1) != NULL && first(L3) != NULL){
        adrP P = first(L1);
        adrP simpanMax;
        adrP simpanMin;
        int counter = 0;
        int max = 0;
        int min = 0;
        do{
            adrR R = first(L3);
            do{
                if(P == addressP(R)){
                    counter++;
                }
                R = next(R);
            }while(R != NULL);
            if(counter > max){
                max = counter;
                simpanMax = P;
            }
            if(counter < min || min == 0){
                min = counter;
                simpanMin = P;
            }
            P = next(P);

        }while(P != NULL);
        cout << endl;
        cout << "Data Orang Tua Yang Memiliki Anak Terbanyak Adalah : "<<info(simpanMax).ayah<<"\t"<<info(simpanMax).ibu<<endl;
        cout << "Data Orang Tua Yang Memiliki Anak Paling Sedikit Adalah : "<<info(simpanMin).ayah<<"\t"<<info(simpanMin).ibu <<endl;


    }else{
        cout<<"Data Kosong"<<endl;
    }

}

void printOnlyOrangTua(ListP L1){
    if(first(L1) != NULL){
        adrP P = first(L1);
        cout<< "Data Orang Tua"<<endl;
        cout<<endl;
        while(next(P) != NULL){
            cout<< "Nama Ayah : "<<info(P).ayah <<"\t Ibu : "<<info(P).ibu<<endl;
            P = next(P);
        }
         cout<< "Nama Ayah : "<<info(P).ayah <<"\t Ibu : "<<info(P).ibu<<endl;

    }else{
        cout<<"Data Kosong"<<endl;
    }

}
void printOnlyAnak(ListC L2){
    if(first(L2) != NULL){
        adrC P = first(L2);
        cout<<"Data Anak"<<endl;
        cout<<endl;
        while(next(P) != first(L2)){
            cout<< "Nama Anak : "<<info(P).nama_anak <<endl;
            P = next(P);
        }
         cout<< "Nama Anak : "<<info(P).nama_anak <<endl;
    }else{
        cout<< "Data Kosong "<<endl;
    }

}
void printOrangTuaTertentu(ListP L1, ListR L3, adrP P){
    if(first(L1) != NULL && first(L3) != NULL){
        adrP C = first(L1);
        cout << "Data Detail Orang Tua "<<endl;
        cout << "Nama Ayah : "<<"\t\t\t Ibu : "<<"\t\tNama Anak "<<endl;
        cout<<endl;
        cout << info(P).ayah <<"\t\t\t"<<info(P).ibu<<endl;
        do{
            if(C == P){
                adrR R = first(L3);
                do{
                    if(P == addressP(R)){
                        cout <<"\t\t\t\t\t\t\t"<<info(addressC(R)).nama_anak<<endl;
                    }
                    R = next(R);

                }while(R != NULL);
            }
            C = next(C);

        }while(C != NULL);

    }else{
        cout << "Orang Tua Tidak mempunyai anak"<<endl;
    }


}
void printAnakTertentu(ListC L2, ListR L3, adrC P){
     if(first(L2) != NULL && first(L3) != NULL){
        adrC C = first(L2);
        cout << "Data Detail Anak "<<endl;
        cout<<endl;
        cout <<"Nama Anak \t\t"<< "Nama Ayah  "<< "\t\tNama Ibu "<<endl;
        cout<<endl;
        cout << info(P).nama_anak<<endl;
        do{
            if(C == P){
                adrR R = first(L3);
                do{
                    if(P == addressC(R)){
                        cout <<"\t\t\t\t"<<info(addressP(R)).ayah<<"\t\t\t\t"<<info(addressP(R)).ibu<<endl;
                    }
                    R = next(R);

                }while(R != NULL);
            }
            C = next(C);

        }while(C != first(L2));

    }else{
        cout << "Data Anak ini belum direlasikan oleh Orang Tua "<<endl;
    }

}


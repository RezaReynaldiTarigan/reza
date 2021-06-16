#ifndef KAMUS_H_INCLUDED
#define KAMUS_H_INCLUDED

#include <iostream>

#define Nil NULL
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define addressC(P) P->addressC
#define addressP(P) P->addressP

using namespace std;

struct OrangTua{
    string ayah;
    string ibu;
};

struct Anak{
    string nama_anak;

};

typedef struct elmParent *adrP;
typedef struct elmChild  *adrC;
typedef struct elmRelasi *adrR;

struct elmParent{
    OrangTua info;
    adrP next;
    adrP prev;

};


struct elmChild{
    Anak info;
    adrC next;
};


struct elmRelasi{
   adrP addressP;
   adrC addressC;
   adrR next;

};

struct ListP{
    adrP first;
};

struct ListC{
    adrC first;
};

struct ListR{
    adrR first;
};


void createListP(ListP &L1);
void createListC(ListC &L2);
void createListR(ListR &L3);

adrP alokasiParent(string ayah,string ibu);
adrC alokasiChild (string nama_anak);
adrR alokasiRelasi (adrP P,adrC C);

void tambahOrangTua(ListP &L1, adrP P);
void deleteOrangTua (ListP &L1,adrP &P);
void tambahAnak(ListC &L2, adrC C);
void deleteAnak(ListC &L2, adrC &C);
void tambahRelasi(ListR &L3, adrR R);
void deleteRelasi(ListR &L3, adrR &R);

adrP searchOrangTua(ListP L1, string ayah);
adrC searchAnak(ListC L2,string nama_anak);

void printOrangTua(ListP L1, ListR L3);
void printOnlyOrangTua(ListP L1);
void printOnlyAnak(ListC L2);
void printAnak(ListC L2, ListR L3);
void printMinMax (ListP L1,ListR L3);
void printOrangTuaTertentu(ListP L1, ListR L3, adrP P);
void printAnakTertentu(ListC L2, ListR L3, adrC P);




#endif // KAMUS_H_INCLUDED

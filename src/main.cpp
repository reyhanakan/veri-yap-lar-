/**
* @file main.cpp
* @description uygulamanın ana ekran kısmı
* @course 1. Öğretim B grubu
* @assignment 2. Ödev
* @date 16.12.24
* @author Didem Reyhan AKAN b231210002@sakarya.edu.tr
*/

#include "BST.hpp"
#include "ListedList.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream> 

using namespace std;

int sayfaBaslangic = 0; 
int sayfaBoyutu = 10;  
int main() {
    int indeks = 0;
    ListedList list;
    list.dosyadanOkuVeEkle();

    while (true) {
        system("cls");  

        int toplamNodeSayisi = list.nodeSayisi();
        if (toplamNodeSayisi == 0) {
            cout << "Liste bos" << endl;
            break;
        }

        if (indeks >= toplamNodeSayisi) {
            indeks = toplamNodeSayisi - 1; 
        } else if (indeks < 0) {
            indeks = 0; 
        }

        sayfaBaslangic = (indeks / sayfaBoyutu) * sayfaBoyutu;

        list.sayfaGoster(sayfaBoyutu);
        list.isaretYaz(indeks);

        list.gez(indeks);  

        char secim;
        cin >> secim;

        if (secim == 'a') {
            indeks--;
            if (indeks < 0) {
                indeks = 0;  
            }

            if (indeks < 10) {
                sayfaBoyutu = 10;  
                sayfaBaslangic = 0;
            } else {
                sayfaBoyutu = 5;  
                sayfaBaslangic = (indeks / sayfaBoyutu) * sayfaBoyutu;
            }

            system("cls"); 
            list.sayfaGoster(sayfaBoyutu);
            list.isaretYaz(indeks);

        } else if (secim == 'd') {
            indeks++;
            if (indeks < 10) {
                sayfaBoyutu = 10;  
                sayfaBaslangic = 0;
            } else {
                sayfaBoyutu = 5;  
                sayfaBaslangic = (indeks / sayfaBoyutu) * sayfaBoyutu;
            }

            system("cls");  
            list.sayfaGoster(sayfaBoyutu);
            list.isaretYaz(indeks);

        } else if (secim == 's') {
    list.nodeSil(indeks);  
    toplamNodeSayisi = list.nodeSayisi();  

    if (toplamNodeSayisi == 0) {
        cout << "Liste bos" << endl;
        break;
    }

    if (indeks >= toplamNodeSayisi) {
        indeks = toplamNodeSayisi - 1;  
    }

    if (toplamNodeSayisi <= 10) {
        sayfaBoyutu = 10;  
    } else {
        sayfaBoyutu = 5;  
    }

   
    sayfaBaslangic = (indeks / sayfaBoyutu) * sayfaBoyutu;

    if (sayfaBaslangic + sayfaBoyutu > toplamNodeSayisi) {
        sayfaBoyutu = toplamNodeSayisi - sayfaBaslangic;
    }

    if (indeks < sayfaBaslangic) {
        sayfaBaslangic = (indeks / sayfaBoyutu) * sayfaBoyutu;
    }

    if (sayfaBaslangic < 0) {
        sayfaBaslangic = 0;
    }
    
    system("cls");  
    list.sayfaGoster(sayfaBoyutu);  
    list.isaretYaz(indeks);         
}
else if (secim == 'w') {
 
    Node* currentNode = list.nodeGetir(indeks);  

    if (currentNode != nullptr) {
        list.aynala(indeks);  
        cout << "Düğüm " << indeks << " aynalandı." << endl;
    }

    system("cls");
    list.sayfaGoster(sayfaBoyutu);  
    list.isaretYaz(indeks); 
}
 else if (secim == 'x') {
            break;
        }
    }
    return 0;
}

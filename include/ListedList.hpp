/**
* @file ListedList.hpp
* @description bağlı liste tanımı
* @course 1. Öğretim B grubu
* @assignment 2. Ödev
* @date 16.12.24
* @author Didem Reyhan AKAN b231210002@sakarya.edu.tr
*/
#ifndef LISTEDLIST_HPP
#define LISTEDLIST_HPP

#include "Node.hpp"
#include <string>

class ListedList {
private:
    Node* head;  
    int indeks;
    int boslukMiktari;
     int sayfaBaslangic;  
    int sayfaBoyutu; 

public:
    ListedList();  
    ~ListedList();  

    bool isEmpty() const;  
    int nodeSayisi() const;  
    Node* nodeGetir(int sira);  
    void ekleNode(const std::string& satir);  
    void drawAllTrees(int indeks);  
    void dosyadanOku(const std::string& dosyaAdi);  
    void Adres(int sayfaBaslangic, int sayfaBoyutu); 
    void sonrakiAdres(int sayfaBaslangic, int sayfaBoyutu); 
    void degerYaz(int sayfaBaslangic, int sayfaBoyutu);
    void dosyadanOkuVeEkle();
    void yazdirBST(Node* node);
    void gez(int indeks);
    void nodeSil(int indeks);
    Node* getHead() const;
    void sayfaGoster(int sayfaBoyutu);
    void isaretYaz(int indeks);
    void aynala(int indeks);
    int hesaplaToplamDeger(Node* node);


};

#endif

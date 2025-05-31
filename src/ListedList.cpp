
#include "ListedList.hpp"
#include "BST.hpp"
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

ListedList::ListedList() : head(nullptr), boslukMiktari(5) {}

ListedList::~ListedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

bool ListedList::isEmpty() const {
    return head == nullptr;
}

int ListedList::nodeSayisi() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
Node* ListedList::getHead() const {
            return head;
        }

Node* ListedList::nodeGetir(int sira) {
    Node* current = head;
    int index = 0;
    while (current != nullptr) {
        if (index == sira) {
            return current;
        }
        current = current->next;
        index++;
    }
    return nullptr;
}


void ListedList::ekleNode(const std::string& satir) {
    Node* newNode = new Node();
    for (char c : satir) {
        newNode->bst.insert(c);  
    }

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void ListedList::drawAllTrees(int indeks) {
    Node* current = nodeGetir(indeks);
    if (current != nullptr) {
        std::cout << "Ağaç Kökü: " << current->bst.root->harf << std::endl;  
    }
}


void ListedList::dosyadanOkuVeEkle() {
    ifstream inputFile("agaclar.txt");
    if (!inputFile) {
        cout << "Dosya açılırken bir hata oluştu!" << endl;
        return;
    }

    string satir;
    while (getline(inputFile, satir)) {
        if (satir.empty()) continue;

        Node* yeniNode = new Node();
        yeniNode->deger = 0;

        for (char ch : satir) {
            yeniNode->deger += static_cast<int>(ch);  
            yeniNode->bst.insert(ch);  
        }

        if (head == nullptr) {
            head = yeniNode;
            yeniNode->prev = nullptr;  
            yeniNode->next = nullptr;  
        } else {

            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;  
            }
            current->next = yeniNode;  
            yeniNode->prev = current;  
            yeniNode->next = nullptr;  
        }
    }

    inputFile.close();
}

int ListedList::hesaplaToplamDeger(Node* node) {
    return node->bst.hesaplaToplamDeger(node->bst.getRoot(), false);
}


void ListedList::degerYaz(int sayfaBaslangic, int sayfaBoyutu) {
    Node* current = head;  
    ifstream inputFile("agaclar.txt"); 

    if (!inputFile) {
        cout << "Dosya açılırken bir hata oluştu!" << endl;
        return;
    }

    string satir;
    int index = 0;  

    while (current && getline(inputFile, satir)) {  
        if (satir.empty()) continue;  

        // Sayfa aralığında olan düğüm için işlem yapalım
        if (index >= sayfaBaslangic && index < sayfaBaslangic + sayfaBoyutu) {
            for (int i = 0; i < boslukMiktari; i++) {
                cout << " ";
            }

            cout << "*";

            // Şu anki düğümün toplam değerini hesapla
            int toplamDeger = hesaplaToplamDeger(current);  // sadece bu düğümün toplam değeri

            cout << setw(6) << toplamDeger;  // Düğümün toplam değerini yazdır

            cout << "*";
        }

        current = current->next;
        index++;  
    }

    cout << endl;  
    inputFile.close();  
}



void ListedList::Adres(int sayfaBaslangic, int sayfaBoyutu) {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count < sayfaBaslangic) {
            current = current->next;
            count++;
            continue;
        }

        if (count < sayfaBaslangic + sayfaBoyutu) {
            for (int i = 0; i < boslukMiktari; i++)
                cout << " ";

            uintptr_t address = reinterpret_cast<uintptr_t>(current);  
            cout << "*";
            cout << setw(6) << address % 10000;  
            cout << "*";

            current = current->next;
            count++;
        } else {
            break;  
        }
    }
    cout << endl; 
}



void ListedList::sonrakiAdres(int sayfaBaslangic, int sayfaBoyutu) {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        if (count < sayfaBaslangic) {
            current = current->next;
            count++;
            continue;
        }

        if (count < sayfaBaslangic + sayfaBoyutu) {
            for (int i = 0; i < boslukMiktari; i++)
                cout << " ";

            if (current->next == nullptr) {
                cout << "*" << setw(6) << "0" << "*";  
                break; 
            } else {
                cout << "*";
                uintptr_t address = reinterpret_cast<uintptr_t>(current->next);
                cout << setw(6) << address % 10000;
                cout << "*";
            }

            current = current->next;
            count++;
        } else {
            break;  
        }
    }
    cout << endl;
}


void ListedList::yazdirBST(Node* node) {
    if (node == nullptr) {
        cout << "Node boş!" << endl;
        return;
    }

    if (&node->bst == nullptr) {
        cout << "BST boş!" << endl;
        return;
    }

    node->bst.printTree();  
}

void ListedList::aynala(int indeks) {
    Node* current = head;
    
    for (int i = 0; i < indeks && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr && current->bst.root != nullptr) {
        current->bst.aynalama(current->bst.root);
    }
}

void ListedList::gez(int indeks) {
    Node* seciliNode = head;
    int nodeCount = nodeSayisi();  

    if (indeks < 0 || indeks >= nodeCount) {
        cout << "Geçersiz indeks!" << endl;
        return;
    }

    for (int i = 0; i < indeks && seciliNode != nullptr; i++) {
        seciliNode = seciliNode->next;
    }

    if (seciliNode != nullptr) {
        yazdirBST(seciliNode); 
    } else {
        cout << "Geçerli bir node bulunamadı." << endl;  
    }
}


void ListedList::nodeSil(int indeks) {
    if (head == nullptr) {  
        cout << "Liste boş!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int count = 0;

    while (temp != nullptr && count < indeks) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Düğüm bulunamadı!" << endl;
        return;
    }

    temp->bst.silAltAgac(temp->bst.root);  

    if (temp->next == nullptr) {
        if (prev == nullptr) {
            head = nullptr;
        } else {
            prev->next = nullptr;
        }
    } else {
        if (prev != nullptr) {
            prev->next = temp->next;
        } else {
            head = temp->next;
        }
    }

    delete temp; 
}



void ListedList::isaretYaz(int indeks) {
    if (indeks < 10) {
        sayfaBoyutu = 10;  
    } else {
        sayfaBoyutu = 5;  
    }

    sayfaBaslangic = (indeks / sayfaBoyutu) * sayfaBoyutu;

    int sayfaIndeksi = indeks % sayfaBoyutu;

    for (int i = 0; i < sayfaIndeksi; i++) {
        for (int j = 0; j < boslukMiktari; j++)
            cout << " ";
        cout << "        ";
    }
    for (int j = 0; j < boslukMiktari; j++)
        cout << " ";
    cout << "^^^^^^^^" << endl; 
}

 void ListedList::sayfaGoster(int sayfaBoyutu) {
    system("cls");  
    int sayfaBaslangic = 0;  
    Node* current = head;
    int nodeSayisi = 0;
    current = head;
    while (current != nullptr) {
        nodeSayisi++;
        current = current->next;
    }

    for (int i = 0; i < std::min(sayfaBoyutu, nodeSayisi); ++i) {
         for (int j = 0; j < 5; j++) {
            cout << " ";
        }
        cout << "********";  
    }
    cout << endl;

    Adres(sayfaBaslangic, sayfaBoyutu);

    current = head;  

    for (int i = 0; i < std::min(sayfaBoyutu, nodeSayisi); ++i) {
         for (int j = 0; j < 5; j++) {
            cout << " ";
        }
        cout << "********";  
    }
    cout << endl;

    degerYaz(sayfaBaslangic, sayfaBoyutu);

    for (int i = 0; i < std::min(sayfaBoyutu, nodeSayisi); ++i) {
         for (int j = 0; j < 5; j++) {
            cout << " ";
        }
        cout << "********";  
    }
    cout << endl;

    current = head;  

    sonrakiAdres(sayfaBaslangic, sayfaBoyutu);

    for (int i = 0; i < std::min(sayfaBoyutu, nodeSayisi); ++i) {
         for (int j = 0; j < 5; j++) {
            cout << " ";
        }
        cout << "********";  
    }
    cout << endl;

  
} 


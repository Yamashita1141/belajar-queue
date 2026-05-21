#include <iostream>
using namespace std;

class Node {
public:
    string nama;
    Node *next;

    Node() { 
        nama = "";
        next = NULL; }
    Node(string nama) { 
        this->nama = nama; 
        this->next = NULL; 
    }
};

class Queue {
private:
    Node *head;
    Node *tail;
    int kapasitas;

public:
    Queue() { 
        head = NULL; 
        tail = NULL; 
        kapasitas = 100; 
    }
    Queue(int kapasitas) { 
        head = NULL; tail = NULL; 
        this->kapasitas = kapasitas; 
    }

    bool isEmpty() { 
        return head == NULL; 
    }

    int panjang() {
        int count = 0;
        Node *cur = head;
        while (cur != NULL) { 
            count++; 
            cur = cur->next; 
        }
        return count;
    }

    bool isFull() { 
        return panjang() == kapasitas; 
    }

    string peek() {
        if (isEmpty()) 
        return "";
        return head->nama;
    }

    void cetak() {
        Node *cur = head;
        while (cur != NULL) {
            cout << "[" << cur->nama << " | " << cur->next << "]";
            if (cur->next != NULL) 
            cout << " --> ";
            cur = cur->next;
        }
        cout << endl;
    }

    void enqueue(string nama) {
        if (isFull()) {
            cout << "Maaf, kapasitas penuh" << endl; 
        } else {
            Node *baru = new Node(nama);
            if (isEmpty()) head = tail = baru;
            else { 
                tail->next = baru; 
                tail = baru; }
        }
    }

    void enqueuePriority(string nama) {
        if (isFull()) {
            dequeuebelakang(); 
            cout << "Maaf, kapasitas penuh" << endl;
        }
        Node *baru = new Node(nama);
        if (isEmpty()) {
            head = tail = baru;
        } else { 
            baru->next = head; 
            head = baru; }
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue kosong" << endl; return; }
        Node *hapus = head;
        head = head->next;
        if (head == NULL) 
        tail = NULL;
        delete hapus;
    }

    void dequeuebelakang() {
        if (isEmpty()) { cout << "Queue kosong" << endl; return; }
        if (head == tail) { delete head; 
            head = tail = NULL; 
            return; }
        Node *cur = head;
        while (cur->next != tail) cur = cur->next;
        delete tail;
        tail = cur;
        tail->next = NULL;
    }
};

int main() {
    cout << "Queue dengan class" << endl;
    Queue hokage(3);

    hokage.enqueue("Sasuke");   
    hokage.enqueue("Sakura");
    hokage.cetak();

    hokage.enqueuePriority("Naruto");
    hokage.cetak();
    cout << "Calon Hokage urutan pertama adalah " << hokage.peek() << endl;

    
    hokage.enqueuePriority("Kakashi");
    hokage.cetak();
    cout << "Calon Hokage urutan pertama adalah " << hokage.peek() << endl;

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

struct Music
{
    string judul;
    string artis;
};

struct Node
{
    Music data;
    Node *next;
};

struct Playlist
{
    string name;
    Node *head;

    Playlist(string namaPlayList) : name(namaPlayList), head(nullptr) {}

    void viewPlaylist()
    {
        Node *current = head;
        int index = 1;
        while (current != nullptr)
        {
            cout << index << ". judul: " << current->data.judul << " | artis: " << current->data.artis << endl;
            current = current->next;
            index++;
        }
    }

    void addSong(string judul, string artis)
    {
        Node *newNode = new Node;
        newNode->data.judul = judul;
        newNode->data.artis = artis;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void removeSong(int index)
    {
        if (index < 1)
        {
            cout << "Invalid index." << endl;
            return;
        }

        if (index == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Lagu berhasil di hapus." << endl;
            return;
        }

        Node *current = head;
        Node *prev = nullptr;
        int currentIndex = 1;

        while (current != nullptr && currentIndex < index)
        {
            prev = current;
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr)
        {
            cout << "Invalid index." << endl;
            return;
        }

        prev->next = current->next;
        delete current;
        cout << "Lagu berhasil di hapus." << endl;
    }
};

int main()
{
    Playlist myPlaylist("My Playlist");

    int pilihan;
    string judul, artis;
    int index;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Lihat Playlist" << endl;
        cout << "2. Tambah Lagu" << endl;
        cout << "3. Hapus Lagu" << endl;
        cout << "4. Exit" << endl;
        cout << "Masukan Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Clear the input buffer

        switch (pilihan)
        {
        case 1:
            cout << "Playlist:" << endl;
            myPlaylist.viewPlaylist();
            break;
        case 2:
            cout << "Enter the judul of the new song: ";
            getline(cin, judul);
            cout << "Enter the artis of the new song: ";
            getline(cin, artis);
            myPlaylist.addSong(judul, artis);
            cout << "Song added to the playlist." << endl;
            break;
        case 3:
            cout << "Enter the index of the song to remove: ";
            cin >> index;
            myPlaylist.removeSong(index);
            break;
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid pilihan. Please try again." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
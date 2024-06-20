#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, string> users; // przechowuje nazwe uzytkownika i haslo
string currentUser = "";

// Funkcja do czyszczenia ekranu
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Funkcja do rejestracji nowego uzytkownika
void registerUser() {
    if (currentUser != "") {
        cout << "Musisz sie wylogowac, aby zarejestrowac nowe konto!\n";
        return;
    }
    string username, password;
    cout << "=== Rejestracja ===\n";
    cout << "Podaj nazwe uzytkownika: ";
    cin >> username;
    if (users.find(username) != users.end()) {
        cout << "Uzytkownik juz istnieje!\n";
        return;
    }
    cout << "Podaj haslo: ";
    cin >> password;
    users[username] = password;
    cout << "Rejestracja zakonczona sukcesem!\n";
}

// Funkcja do logowania
void loginUser() {
    if (currentUser != "") {
        cout << "Jestes juz zalogowany jako " << currentUser << ". Wyloguj sie, aby zalogowac sie na inne konto.\n";
        return;
    }
    string username, password;
    cout << "=== Logowanie ===\n";
    cout << "Podaj nazwe uzytkownika: ";
    cin >> username;
    cout << "Podaj haslo: ";
    cin >> password;
    if (users.find(username) != users.end() && users[username] == password) {
        currentUser = username;
        cout << "Logowanie zakonczone sukcesem!\n";
    } else {
        cout << "Bledna nazwa uzytkownika lub haslo!\n";
    }
}

// Funkcja do zmiany hasla
void changePassword() {
    if (currentUser == "") {
        cout << "Musisz byc zalogowany, aby zmienic haslo!\n";
        return;
    }
    string oldPassword, newPassword;
    cout << "=== Zmiana hasla ===\n";
    cout << "Podaj stare haslo: ";
    cin >> oldPassword;
    if (users[currentUser] == oldPassword) {
        cout << "Podaj nowe haslo: ";
        cin >> newPassword;
        users[currentUser] = newPassword;
        cout << "Haslo zmienione pomyslnie!\n";
    } else {
        cout << "Bledne stare haslo!\n";
    }
}

// Funkcja do wyswietlania profilu uzytkownika
void displayProfile() {
    if (currentUser == "") {
        cout << "Musisz byc zalogowany, aby wyswietlic profil!\n";
        return;
    }
    cout << "=== Profil uzytkownika ===\n";
    cout << "Nazwa uzytkownika: " << currentUser << "\n";
}

// Funkcja do wylogowania
void logoutUser() {
    if (currentUser == "") {
        cout << "Nie jestes zalogowany!\n";
        return;
    }
    currentUser = "";
    cout << "Wylogowano pomyslnie!\n";
}

// Funkcja do usuniecia konta uzytkownika
void deleteUser() {
    if (currentUser == "") {
        cout << "Musisz byc zalogowany, aby usunac konto!\n";
        return;
    }
    users.erase(currentUser);
    currentUser = "";
    cout << "Konto usuniete pomyslnie!\n";
}

// Funkcja do wyswietlania wszystkich zarejestrowanych uzytkownikow
void displayAllUsers() {
    if (users.empty()) {
        cout << "Brak zarejestrowanych uzytkownikow.\n";
        return;
    }
    cout << "=== Lista uzytkownikow ===\n";
    for (const auto& user : users) {
        cout << user.first << "\n";
    }
}

int main() {
    int choice;
    do {
        clearScreen();
        if (currentUser != "") {
            cout << "Dzien dobry, " << currentUser << "!\n";
        }
        cout << "\n=== Menu ===\n";
        cout << "1. Rejestracja\n";
        cout << "2. Logowanie\n";
        cout << "3. Zmiana hasla\n";
        cout << "4. Wyswietl profil\n";
        cout << "5. Wylogowanie\n";
        cout << "6. Usun konto\n";
        cout << "7. Wyswietl wszystkich uzytkownikow\n";
        cout << "8. Wyjscie\n";
        cout << "Wybierz opcje: ";
        cin >> choice;

        clearScreen();

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                displayProfile();
                break;
            case 5:
                logoutUser();
                break;
            case 6:
                deleteUser();
                break;
            case 7:
                displayAllUsers();
                break;
            case 8:
                cout << "Do widzenia!\n";
                break;
            default:
                cout << "Nieprawidlowa opcja! Wybierz ponownie.\n";
        }

        if (choice != 8) {
            cout << "Nacisnij Enter, aby kontynuowac...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 8);

    return 0;
}

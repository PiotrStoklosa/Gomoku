Hi!
This is my first major project. There is the documantation for programers and for players below here, unfortunally only in polish right now (I am going to add english version soon). More info about Gomoku is here: https://en.wikipedia.org/wiki/Gomoku
Good luck!

Dokumentacja dla użytkownika programu

1. Instrukcja gry:

Gomoku toczy się na planszy o rozmiarach 10x10, 15x15 lub 19x19.
Gracze kładą na planszy na przemian po jednym swoim kamieniu (gracz
rozpoczynający grę używa kamieni różowych, drugi niebieskich). Celem każdego
z graczy jest ułożenie nieprzerwanego łańcucha dokładnie pięciu kamieni
własnego koloru (w poziomie, pionie lub po przekątnej). Ustawienie więcej niż
5 kamieni w linii, zwane “overline”, nie daje wygranej.

2. Aplikacja:

Użytkownik po otworzeniu aplikacji ma możliwość stworzenia nowej gry,
wczytania zapisu gry oraz wyjścia do pulpitu. Po wczytaniu zapisu gry
użytkownikowi od razu wyświetli się stan partii, którą zapisał, natomiast po
kliknięciu nowej gry, użytkownik wybiera rozmiar planszy i przechodzi
bezpośrednio do nowej rozgrywki. Podczas trwania partii, gracz może zapisać
stan gry, a także wyjść do menu, po wcześniejszym kliknięciu przycisku “opcje”
znajdującego się w lewym górnym rogu. Kiedy jeden z graczy wygra, wyświetli
się odpowiedni komunikat ogłaszający zwycięzcę (podczas remisu gra także
zakończy się i wyświetli się odpowiednia informacja).

3. Uwagi:

Gra przechowuje maksymalnie jeden zapis gry.


Opis struktury programu

1. Podział programu:

Program jest podzielony na dwa moduły. W pierwszym znajduje się
główna pętla gtk_main() i komendy tworzące cały układ graficzny wraz z
sygnałami. W drugim znajdują się funkcje, które odpowiadają za poprawność
działania gry oraz takie, które obsługują sygnały.

2. Funkcje:

a. Funkcje test_gora, test_dol itp. sprawdzają czy któryś z graczy nie wygrał
  po wstawieniu nowego kamienia.
b. Funkcja gra resetuje i wyświetla nową planszę o wymiarach podanych
  przez gracza (resetuje przyciski, przygotowuje obrazki do wyświetlania,
  zeruje status, ustawia turę na różowego).
c. Funkcja wygral wyświetla odpowiedni komunikat z wygraną bądź
  remisem.
d. Funkcje klikniety_przycisk dezaktywują przyciski oraz wyświetlają
  odpowiednie kamienie.
e. Funkcje wczytaj_gre, zapisz_gre zajmują się wczytywaniem i
  zapisywaniem planszy do pliku tekstowego.
f. Funkcja quit wychodzi z gtk_main()
g. Funkcje nowagra, powrot, powrot_z_gry, powrot_z_okna_wygranej
  wyświetlają i ukrywają odpowiednie panele.
h. Pozostałe funkcje obsługują przyciski i zajmują się pokazywaniem i
  ukrywaniem odpowiednich paneli.
  
3. Użyte biblioteki:

gtk/gtk.h, stdio.h, stdlib.h, stdbool.h

4. Pozostałe:

a. Tablice (plansza1, plansza2, plansza3) przechowują planszę do gry, gdzie
  0 oznacza nienaciśnięty przycisk, 1 oznacza kamień różowy, a 2 - kamień
  niebieski.
b. Tablice stone przechowują zdjęcia kamieni.
c. Widgety napis_koncowy1, napis_koncowy2, remis, napis_gomoku
  przechowują zdjęcia z napisami wyświetlane w odpowiednich
  momentach uzależnionych od interakcji.

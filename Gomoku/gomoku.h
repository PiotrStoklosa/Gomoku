extern GtkWidget *panel_gry;
extern GtkWindow *okno;

extern GtkWidget *przyciski10x10[100];
extern GtkWidget *przyciski15x15[225];
extern GtkWidget *przyciski19x19[361];

extern GtkWidget *stone[200];
extern GtkWidget *stone1[450];
extern GtkWidget *stone2[722];

extern GtkWidget *aktualny_ruch;
extern GtkWidget *pokaz_ilosc_ruch;

extern GtkWidget *Vbox_z_panelem_startowym;
extern GtkWidget *vbox_z_panelem_wyboru_planszy;
extern GtkWidget *vboxkoniec;

extern GtkWidget *napis_koncowy1;
extern GtkWidget *napis_koncowy2;
extern GtkWidget *remis;

extern GtkWidget *plansza10x10;
extern GtkWidget *plansza15x15;
extern GtkWidget *plansza19x19;

char x[50][17];
char y[50][17];

extern int wx;
extern int wy;
extern int znak;
extern int wariant;
extern int status;
extern int gracz1;

extern int plansza1[10][10];
extern int plansza2[15][15];
extern int plansza3[19][19];

int test_lewo(int x2, int y2, int gracz, int war);
int test_prawo(int x2, int y2, int gracz, int war);
int test_gora(int x2, int y2, int gracz, int war);
int test_dol(int x2, int y2, int gracz, int war);
int test_prawogora(int x2, int y2, int gracz, int war);
int test_lewogora(int x2, int y2, int gracz, int war);
int test_prawodol(int x2, int y2, int gracz, int war);
int test_lewodol(int x2, int y2, int gracz, int war);
bool wyniki(int x1, int y1, int ruch, int wartosc);

void quit (GtkWidget *widget, gpointer data);
void gra (GtkWidget *widget, gpointer data);
void nowagra (GtkWidget *widget, gpointer data);
void powrot(GtkWidget *widget, gpointer data);
void powrot_z_gry(GtkWidget *widget, gpointer data);
void wygral(int zwyciezca);
void klikniety_przycisk10x10(GtkWidget *widget, int *data);
void klikniety_przycisk15x15(GtkWidget *widget, int *data);
void klikniety_przycisk19x19(GtkWidget *widget, int *data);
void wczytaj_gre(GtkWidget *widget, int *data);
void zapisz_gre(GtkWidget *widget, int *data);
void powrot_z_okna_wygranej(GtkWidget *widget, gpointer data);

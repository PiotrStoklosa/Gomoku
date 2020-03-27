#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gomoku.h"

GtkWidget *panel_gry;
GtkWindow *okno;

GtkWidget *przyciski10x10[100];
GtkWidget *przyciski15x15[225];
GtkWidget *przyciski19x19[361];

GtkWidget *stone[200];
GtkWidget *stone1[450];
GtkWidget *stone2[722];

GtkWidget *aktualny_ruch;
GtkWidget *pokaz_ilosc_ruch;

GtkWidget *Vbox_z_panelem_startowym;
GtkWidget *vbox_z_panelem_wyboru_planszy;
GtkWidget *vboxkoniec;

GtkWidget *napis_koncowy1;
GtkWidget *napis_koncowy2;
GtkWidget *remis;

GtkWidget *plansza10x10;
GtkWidget *plansza15x15;
GtkWidget *plansza19x19;

char x[50][17];
char y[50][17];

int wx;
int wy;
int znak;
int wariant;
int status=0;
int gracz1=1;

int plansza1[10][10];
int plansza2[15][15];
int plansza3[19][19];


int test_gora(int x2, int y2, int gracz, int war)
{
    if (war==1)
    {
    if (y2>0 && plansza1[x2][y2-1]==gracz)
        return test_gora(x2,y2-1,gracz,war) + 1;
    else
        return 0;
    }
    else if (war==2)
    {
        if (y2>0 && plansza2[x2][y2-1]==gracz)
        return test_gora(x2,y2-1,gracz,war) + 1;
    else
        return 0;
    }
    else
    {
        if (y2>0 && plansza3[x2][y2-1]==gracz)
            return test_gora(x2,y2-1,gracz, war) + 1;
        else
            return 0;
    }
}
int test_dol(int x2, int y2, int gracz, int war)
{
    if (war==1)
    {
        if (y2<9 && plansza1[x2][y2+1]==gracz)
            return test_dol(x2,y2+1,gracz,war) + 1;
        else
            return 0;
    }
    else if (war==2)
    {
        if (y2<14 && plansza2[x2][y2+1]==gracz)
            return test_dol(x2,y2+1,gracz,war) + 1;
        else
            return 0;
    }
    else
    {
        if (y2<18 && plansza3[x2][y2+1]==gracz)
            return test_dol(x2,y2+1,gracz,war) + 1;
        else
            return 0;
    }
}
int test_lewo(int x2, int y2, int gracz, int war)
{
    if (war==1)
    {
        if (x2>0 && plansza1[x2-1][y2]==gracz)
            return test_lewo(x2-1,y2,gracz,war) + 1;
        else
            return 0;
    }
    else if (war==2)
    {
        if (x2>0 && plansza2[x2-1][y2]==gracz)
            return test_lewo(x2-1,y2,gracz,war) + 1;
        else
            return 0;
    }
    else
    {
        if (x2>0 && plansza3[x2-1][y2]==gracz)
            return test_lewo(x2-1,y2,gracz,war) + 1;
        else
            return 0;
    }
}
int test_prawo(int x2, int y2, int gracz, int war)
{
    if (war==1)
    {
        if (x2<9 && plansza1[x2+1][y2]==gracz)
            return test_prawo(x2+1,y2,gracz,war) + 1;
        else
            return 0;
    }
    else if (war==2)
    {
        if (x2<14 && plansza2[x2+1][y2]==gracz)
            return test_prawo(x2+1,y2,gracz,war) + 1;
        else
            return 0;
    }
    else
    {
        if (x2<18 && plansza3[x2+1][y2]==gracz)
            return test_prawo(x2+1,y2,gracz,war) + 1;
        else
            return 0;
    }
}
int test_lewodol(int x2, int y2, int gracz, int war)
{
    if (war==1)
    {
        if (y2<9 && x2>0 && plansza1[x2-1][y2+1]==gracz)
            return test_lewodol(x2-1,y2+1,gracz,war) + 1;
        else
            return 0;
    }
    else if (war==2)
    {
        if (y2<14 && x2>0 && plansza2[x2-1][y2+1]==gracz)
            return test_lewodol(x2-1,y2+1,gracz,war) + 1;
        else
            return 0;
    }
    else
    {
        if (y2<18 && x2>0 && plansza3[x2-1][y2+1]==gracz)
            return test_lewodol(x2-1,y2+1,gracz,war) + 1;
        else
            return 0;
    }
}
int test_prawodol(int x2, int y2, int gracz, int war)
{
    if (war==1)
    {
        if (y2>0 && x2>0 && plansza1[x2-1][y2-1]==gracz)
            return test_prawodol(x2-1,y2-1,gracz,war) + 1;
        else
            return 0;
    }
    else if (war==2)
    {
        if (y2>0 && x2>0 && plansza2[x2-1][y2-1]==gracz)
            return test_prawodol(x2-1,y2-1,gracz,war) + 1;
        else
            return 0;
    }
    else
    {
        if (y2>0 && x2>0 && plansza3[x2-1][y2-1]==gracz)
            return test_prawodol(x2-1,y2-1,gracz,war) + 1;
        else
            return 0;
    }
}
int test_lewogora(int x2, int y2, int gracz, int war)
{
    if (war==1)
    {
        if (y2<9 && x2<9 && plansza1[x2+1][y2+1]==gracz)
            return test_lewogora(x2+1,y2+1,gracz,war) + 1;
        else
            return 0;
    }
    else if (war==2)
    {
        if (y2<14 && x2<14 && plansza2[x2+1][y2+1]==gracz)
            return test_lewogora(x2+1,y2+1,gracz,war) + 1;
        else
            return 0;
    }
    else
    {
        if (y2<18 && x2<18 && plansza1[x2+1][y2+1]==gracz)
            return test_lewogora(x2+1,y2+1,gracz,war) + 1;
        else
            return 0;
    }
}
int test_prawogora(int x2, int y2, int gracz, int war)
{
    if (war==1)
    {
        if (y2>0 && x2<9 && plansza1[x2+1][y2-1]==gracz)
            return test_prawogora(x2+1,y2-1,gracz,war) + 1;
        else
            return 0;
    }
    else if (war==2)
    {
        if (y2>0 && x2<14 && plansza2[x2+1][y2-1]==gracz)
            return test_prawogora(x2+1,y2-1,gracz,war) + 1;
        else
            return 0;
    }
    else
    {
        if (y2>0 && x2<18 && plansza3[x2+1][y2-1]==gracz)
            return test_prawogora(x2+1,y2-1,gracz,war) + 1;
        else
            return 0;
    }
}
bool wyniki(int x1, int y1, int ruch, int wartosc)
{
    if (test_gora(x1,y1,ruch,wartosc)+test_dol(x1,y1,ruch,wartosc)==4)
        return 1;
    if (test_lewo(x1,y1,ruch,wartosc)+test_prawo(x1,y1,ruch,wartosc)==4)
        return 1;
    if (test_lewogora(x1,y1,ruch,wartosc)+test_prawodol(x1,y1,ruch,wartosc)==4)
        return 1;
    if (test_prawogora(x1,y1,ruch,wartosc)+test_lewodol(x1,y1,ruch,wartosc)==4)
        return 1;
    return 0;
}
void quit (GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;
    gtk_main_quit ();
}
void gra (GtkWidget *widget, gpointer data)
{
    (void)widget;
    wariant=GPOINTER_TO_INT(data);
    gtk_widget_show_all(panel_gry);
    if (wariant==1)
    {
        gtk_widget_hide(plansza15x15);
        gtk_widget_hide(plansza19x19);
    }
    if (wariant==2)
    {
        gtk_widget_hide(plansza10x10);
        gtk_widget_hide(plansza19x19);
    }
    if (wariant==3)
    {
        gtk_widget_hide(plansza15x15);
        gtk_widget_hide(plansza10x10);
    }
    if (wariant==1)
    for (int i=0; i<100; i++)
    {
        gtk_widget_set_sensitive(przyciski10x10[i], TRUE);
        gtk_button_set_always_show_image (GTK_BUTTON(przyciski10x10[i]), FALSE);
        plansza1[i/10][i%10]=0;
    }
    if (wariant==2)
    for (int i=0; i<225; i++)
    {
        gtk_widget_set_sensitive(przyciski15x15[i], TRUE);
        gtk_button_set_always_show_image (GTK_BUTTON(przyciski15x15[i]), FALSE);
        plansza2[i/15][i%15]=0;
    }
    if (wariant==3)
    for (int i=0; i<361; i++)
    {
        gtk_widget_set_sensitive(przyciski19x19[i], TRUE);
        gtk_button_set_always_show_image (GTK_BUTTON(przyciski19x19[i]), FALSE);
        plansza3[i/19][i%19]=0;
    }
    for (int i=0; i<200; i++)
        if (i%2)
            stone[i]= gtk_image_new_from_file ("Grafika/Niebieskie_kamienie/Niebieski_kamien10x10.png");
        else
            stone[i]= gtk_image_new_from_file ("Grafika/Czerwone_kamienie/Czerwony_kamien10x10.png");
    for (int i=0; i<450; i++)
        if (i%2)
            stone1[i]= gtk_image_new_from_file ("Grafika/Niebieskie_kamienie/Niebieski_kamien15x15.png");
        else
            stone1[i]= gtk_image_new_from_file ("Grafika/Czerwone_kamienie/Czerwony_kamien15x15.png");
    for (int i=0; i<722; i++)
        if (i%2)
            stone2[i]= gtk_image_new_from_file ("Grafika/Niebieskie_kamienie/Niebieski_kamien19x19.png");
        else
            stone2[i]= gtk_image_new_from_file ("Grafika/Czerwone_kamienie/Czerwony_kamien19x19.png");
    status=0;
    gracz1=1;
    gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:       Różowego</b>");
    gtk_label_set_markup(GTK_LABEL(pokaz_ilosc_ruch), "<b>0</b>");
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER);
    gtk_widget_hide(vbox_z_panelem_wyboru_planszy);
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER_ALWAYS);
}
void nowagra (GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;
    gtk_widget_hide(Vbox_z_panelem_startowym);
    gtk_widget_show_all(vbox_z_panelem_wyboru_planszy);
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER_ALWAYS);
}
void powrot(GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;
    gtk_widget_hide(vbox_z_panelem_wyboru_planszy);
    gtk_widget_show_all(Vbox_z_panelem_startowym);
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER_ALWAYS);
}
void powrot_z_gry(GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER);
    gtk_widget_hide(panel_gry);
    gtk_widget_show_all(Vbox_z_panelem_startowym);
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER_ALWAYS);
}
void wygral(int zwyciezca)
{
    gtk_widget_hide(panel_gry);
    gtk_widget_show_all(vboxkoniec);
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER_ALWAYS);
    if (zwyciezca==1)
        {
            gtk_widget_hide(napis_koncowy2);
            gtk_widget_hide(remis);
        }
    else if (zwyciezca==2)
        {
            gtk_widget_hide(napis_koncowy1);
            gtk_widget_hide(remis);
        }
    else
    {
        gtk_widget_hide(napis_koncowy1);
        gtk_widget_hide(napis_koncowy2);
    }
}
void klikniety_przycisk10x10(GtkWidget *widget, int *data)
{

    gtk_widget_set_sensitive (widget, FALSE);
    gtk_button_set_image (GTK_BUTTON(widget), stone[status]);
    gtk_button_set_always_show_image (GTK_BUTTON(widget), TRUE);
    status++;
    char *result;
    result = malloc(4);
    sprintf(result, "<b>%d</b>", status);
    gtk_label_set_markup(GTK_LABEL(pokaz_ilosc_ruch), result);
    if (status%2==0)
         gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:       Różowego</b>");
    else
         gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:  Niebieskiego</b>");
    wx=*data/10;
    wy=*data%10;
    plansza1[wx][wy]=gracz1;
    if (wyniki(wx,wy,gracz1,1)==true)
        wygral(gracz1);
    if (gracz1==1)
        gracz1=2;
    else
        gracz1=1;
    if (status==100)
        wygral(0);
}
void klikniety_przycisk15x15(GtkWidget *widget, int *data)
{
    gtk_widget_set_sensitive (widget, FALSE);
    gtk_button_set_image (GTK_BUTTON(widget), stone1[status]);
    gtk_button_set_always_show_image (GTK_BUTTON(widget), TRUE);
    status++;
    char *result;
    result = malloc(4);
    sprintf(result, "<b>%d</b>", status);
    gtk_label_set_markup(GTK_LABEL(pokaz_ilosc_ruch), result);
    if (status%2==0)
         gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:       Różowego</b>");
    else
         gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:  Niebieskiego</b>");
    wx=*data/15;
    wy=*data%15;
    plansza2[wx][wy]=gracz1;
    if (wyniki(wx,wy,gracz1,2)==true)
        wygral(gracz1);
    if (gracz1==1)
        gracz1=2;
    else
        gracz1=1;
    if (status==225)
        wygral(0);
}
void klikniety_przycisk19x19(GtkWidget *widget, int *data)
{

    gtk_widget_set_sensitive (widget, FALSE);
    gtk_button_set_image (GTK_BUTTON(widget), stone2[status]);
    gtk_button_set_always_show_image (GTK_BUTTON(widget), TRUE);
    status++;
    char *result;
    result = malloc(4);
    sprintf(result, "<b>%d</b>", status);
    gtk_label_set_markup(GTK_LABEL(pokaz_ilosc_ruch), result);
    if (status%2==0)
         gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:     Różowego</b>");
    else
         gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:  Niebiskiego</b>");
    wx=*data/19;
    wy=*data%19;
    plansza3[wx][wy]=gracz1;
    if (wyniki(wx,wy,gracz1,3)==true)
        wygral(gracz1);
    if (gracz1==1)
        gracz1=2;
    else
        gracz1=1;
    if (status==361)
        wygral(0);
}
void powrot_z_okna_wygranej(GtkWidget *widget, gpointer data)
{
    (void)widget;
    (void)data;
    gtk_widget_hide(vboxkoniec);
    gtk_widget_show_all(Vbox_z_panelem_startowym);
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER_ALWAYS);
}
void wczytaj_gre(GtkWidget *widget, int *data)
{
    (void)widget;
    (void)data;
    int wariant_wczytu;
    gtk_widget_hide(Vbox_z_panelem_startowym);

    FILE *wczyt = fopen("Zapis_gry/Zapis.txt", "r");

    fscanf(wczyt, "%d", &wariant_wczytu);

    if (wariant_wczytu==1)
    {
        gra(NULL, (gpointer)1);
        GtkWidget *zdjecie[10][10];

        for (int j=0; j<10; j++)
        {
            for (int i=0; i<10; i++)
            {
                fscanf(wczyt, "%d" , &znak);
                if (znak!=0)
                {
                    if (znak==1)
                    {
                        zdjecie[i][j]=gtk_image_new_from_file("Grafika/Czerwone_kamienie/Czerwony_kamien10x10.png");
                        plansza1[i][j]=1;
                        gracz1++;
                    }
                    else
                    {
                        zdjecie[i][j]=gtk_image_new_from_file("Grafika/Niebieskie_kamienie/Niebieski_kamien10x10.png");
                        plansza1[i][j]=2;
                        gracz1--;
                    }
                    gtk_button_set_image (GTK_BUTTON(przyciski10x10[i*10+j]), zdjecie[i][j]);
                    gtk_widget_set_sensitive(przyciski10x10[i*10+j],FALSE);
                    status++;
                    gtk_button_set_always_show_image (GTK_BUTTON(przyciski10x10[i*10+j]), TRUE);
                }

            }
        }

    }
    if (wariant_wczytu==2)
    {
        gra(NULL, (gpointer)2);
        GtkWidget *zdjecie[15][15];
        for (int j=0; j<15; j++)
        {
            for (int i=0; i<15; i++)
            {
                fscanf(wczyt, "%d" , &znak);
                if (znak!=0)
                {
                    if (znak==1)
                    {
                        zdjecie[i][j]=gtk_image_new_from_file("Grafika/Czerwone_kamienie/Czerwony_kamien15x15.png");
                        plansza2[i][j]=1;
                        gracz1++;
                    }
                    else
                    {
                        zdjecie[i][j]=gtk_image_new_from_file("Grafika/Niebieskie_kamienie/Niebieski_kamien15x15.png");
                        plansza2[i][j]=2;
                        gracz1--;
                    }
                    gtk_button_set_image (GTK_BUTTON(przyciski15x15[i*15+j]), zdjecie[i][j]);
                    gtk_widget_set_sensitive(przyciski15x15[i*15+j],FALSE);
                    status++;
                    gtk_button_set_always_show_image (GTK_BUTTON(przyciski15x15[i*15+j]), TRUE);
                }

            }
        }

    }
    if (wariant_wczytu==3)
    {
        gra(NULL, (gpointer)3);
        GtkWidget *zdjecie[19][19];
        for (int j=0; j<19; j++)
        {
            for (int i=0; i<19; i++)
            {
                fscanf(wczyt, "%d" , &znak);
                if (znak!=0)
                {
                    if (znak==1)
                    {
                        zdjecie[i][j]=gtk_image_new_from_file("Grafika/Czerwone_kamienie/Czerwony_kamien19x19.png");
                        plansza3[i][j]=1;
                        gracz1++;
                    }
                    else
                    {
                        zdjecie[i][j]=gtk_image_new_from_file("Grafika/Niebieskie_kamienie/Niebieski_kamien19x19.png");
                        plansza3[i][j]=1;
                        gracz1--;
                    }
                    gtk_button_set_image (GTK_BUTTON(przyciski19x19[i*19+j]), zdjecie[i][j]);
                    gtk_widget_set_sensitive(przyciski19x19[i*19+j],FALSE);
                    status++;
                    gtk_button_set_always_show_image (GTK_BUTTON(przyciski19x19[i*19+j]), TRUE);
                }
            }
        }

    }
    char *result;
    result = malloc(4);
    sprintf(result, "<b>%d</b>", status);
    gtk_label_set_markup(GTK_LABEL(pokaz_ilosc_ruch), result);
    if (status%2==0)
         gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:      Różowego</b>");
    else
         gtk_label_set_markup(GTK_LABEL(aktualny_ruch), "<b>Teraz tura:  Niebiskiego</b>");
    fclose(wczyt);
}
void zapisz_gre(GtkWidget *widget, int *data)
{
    (void)widget;
    (void)data;
    FILE *zapis = fopen("Zapis_gry/Zapis.txt", "w");
    fprintf(zapis, "%d\n", wariant);
    if (wariant==1)
    {
       for (int i=0; i<10; i++)
        {
            for (int j=0; j<10; j++)
                fprintf(zapis, "%d ", plansza1[j][i]);
            fprintf(zapis,"\n");
        }
    }
    if (wariant==2)
    {
       for (int i=0; i<15; i++)
        {
            for (int j=0; j<15; j++)
                fprintf(zapis, "%d ", plansza2[j][i]);
            fprintf(zapis,"\n");
        }
    }
    if (wariant==3)
    {
       for (int i=0; i<19; i++)
        {
            for (int j=0; j<19; j++)
                fprintf(zapis, "%d ", plansza3[j][i]);
            fprintf(zapis,"\n");
        }
    }
    fclose(zapis);
}

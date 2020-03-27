#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gomoku.h"
int main( int argc, char *argv[])
{
    gtk_init(&argc,&argv);

    // okno programu

    okno=(GtkWindow*)gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_resizable(okno, FALSE);
    gtk_window_set_title (okno, "Gomoku");
    gtk_window_set_position(okno, GTK_WIN_POS_CENTER_ALWAYS);

    g_signal_connect(G_OBJECT(okno),"destroy",G_CALLBACK(gtk_main_quit),NULL);

    GtkWidget *manadzerpaneli;

    manadzerpaneli=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_container_add(GTK_CONTAINER(okno),manadzerpaneli);

    // panelstart

    GtkWidget *przycisknowagra;
    GtkWidget *przyciskwczytajgre;
    GtkWidget *przyciskwyjscie;
    GtkWidget *napis_gomoku;
    GtkWidget *panelstart;

    napis_gomoku=gtk_image_new_from_file("Grafika/Napisy/Gomoku.png");

    Vbox_z_panelem_startowym=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);
    panelstart=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

    gtk_box_pack_start(GTK_BOX(Vbox_z_panelem_startowym),napis_gomoku,TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(Vbox_z_panelem_startowym),panelstart,TRUE, FALSE,0);

    gtk_widget_set_margin_start (Vbox_z_panelem_startowym, 40);
    gtk_widget_set_margin_end (Vbox_z_panelem_startowym, 40);
    gtk_widget_set_margin_bottom (Vbox_z_panelem_startowym, 40);
    gtk_widget_set_margin_top (Vbox_z_panelem_startowym, 40);

    gtk_box_pack_start(GTK_BOX(manadzerpaneli),Vbox_z_panelem_startowym,TRUE, FALSE,0);

    przycisknowagra = gtk_button_new_with_label("Nowa gra");
    przyciskwczytajgre = gtk_button_new_with_label("Wczytaj grę");
    przyciskwyjscie = gtk_button_new_with_label("Wyjście");

    gtk_box_pack_start(GTK_BOX(panelstart), przycisknowagra,TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(panelstart), przyciskwczytajgre,TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(panelstart), przyciskwyjscie,TRUE, FALSE,0);

    gtk_widget_set_size_request(przycisknowagra, 100, 50);
    gtk_widget_set_margin_start(przycisknowagra,40);
    gtk_widget_set_margin_end(przycisknowagra,40);

    gtk_widget_set_size_request(przyciskwczytajgre, 100, 50);
    gtk_widget_set_margin_start(przyciskwczytajgre,40);
    gtk_widget_set_margin_end(przyciskwczytajgre,40);

    gtk_widget_set_size_request(przyciskwyjscie, 100, 50);
    gtk_widget_set_margin_start(przyciskwyjscie,40);
    gtk_widget_set_margin_end(przyciskwyjscie,40);

    g_signal_connect (G_OBJECT (przyciskwyjscie), "clicked",G_CALLBACK (quit), NULL);
    g_signal_connect (G_OBJECT (przycisknowagra), "clicked",G_CALLBACK (nowagra), NULL);
    g_signal_connect (G_OBJECT (przyciskwczytajgre), "clicked",G_CALLBACK (wczytaj_gre), NULL);

    // wybor planszy

    GtkWidget *przycisk10x10;
    GtkWidget *przycisk15x15;
    GtkWidget *przycisk19x19;
    GtkWidget *przyciskpowrot;
    GtkWidget *panelwybor;

    przyciskpowrot = gtk_button_new_with_label("Powrót");
    gtk_widget_set_size_request(przyciskpowrot, 50, 60);
    gtk_widget_set_margin_start(przyciskpowrot, 30);
    gtk_widget_set_margin_end(przyciskpowrot, 30);

    vbox_z_panelem_wyboru_planszy=gtk_box_new(GTK_ORIENTATION_VERTICAL,20);

    gtk_widget_set_margin_start (vbox_z_panelem_wyboru_planszy, 40);
    gtk_widget_set_margin_end (vbox_z_panelem_wyboru_planszy, 40);
    gtk_widget_set_margin_bottom (vbox_z_panelem_wyboru_planszy, 40);
    gtk_widget_set_margin_top (vbox_z_panelem_wyboru_planszy, 40);

    gtk_box_pack_start(GTK_BOX(manadzerpaneli), vbox_z_panelem_wyboru_planszy,TRUE, FALSE,0);

    panelwybor=gtk_box_new(GTK_ORIENTATION_HORIZONTAL,20);
    gtk_box_pack_start(GTK_BOX(vbox_z_panelem_wyboru_planszy), panelwybor, TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(vbox_z_panelem_wyboru_planszy), przyciskpowrot, TRUE, FALSE,0);

    przycisk10x10 = gtk_button_new_with_label("10x10");
    gtk_widget_set_size_request(przycisk10x10, 90, 60);
    gtk_box_pack_start(GTK_BOX(panelwybor), przycisk10x10,TRUE, FALSE,0);

    przycisk15x15 = gtk_button_new_with_label("15x15");
    gtk_widget_set_size_request(przycisk15x15, 90, 60);
    gtk_box_pack_start(GTK_BOX(panelwybor), przycisk15x15,TRUE, FALSE,0);

    przycisk19x19 = gtk_button_new_with_label("19x19");
    gtk_widget_set_size_request(przycisk19x19, 90, 60);
    gtk_box_pack_start(GTK_BOX(panelwybor), przycisk19x19,TRUE, FALSE,0);

    g_signal_connect (G_OBJECT (przycisk10x10), "clicked",G_CALLBACK (gra), (gpointer)1);
    g_signal_connect (G_OBJECT (przycisk15x15), "clicked",G_CALLBACK (gra), (gpointer)2);
    g_signal_connect (G_OBJECT (przycisk19x19), "clicked",G_CALLBACK (gra), (gpointer)3);
    g_signal_connect (G_OBJECT (przyciskpowrot), "clicked",G_CALLBACK (powrot), NULL);

    // plansza

    // plansza/menu_bar

    GtkWidget *menu_bar;
    GtkWidget *opcje;
    GtkWidget *menu_opcje;
    GtkWidget *menu_zapisz_gre;
    GtkWidget *menu_wyjscie_do_menu;
    GtkWidget *iloscruchowbox;
    GtkWidget *iloscruchow;
    int tablica_sygnaly10x10[100];
    int tablica_sygnaly15x15[225];
    int tablica_sygnaly19x19[361];

    menu_bar=gtk_menu_bar_new();
    opcje=gtk_menu_new();

    menu_opcje=gtk_menu_item_new_with_label("Opcje");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_opcje), opcje);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_opcje);

    menu_zapisz_gre=gtk_menu_item_new_with_label("Zapisz gre");
    gtk_menu_shell_append(GTK_MENU_SHELL(opcje), menu_zapisz_gre);

    menu_wyjscie_do_menu=gtk_menu_item_new_with_label("Wyjscie do menu");
    gtk_menu_shell_append(GTK_MENU_SHELL(opcje), menu_wyjscie_do_menu);

    // plansza/tworzenie trzech plansz

    GtkWidget *etykieta;

    plansza10x10=gtk_grid_new();

    for (int i=0; i<12; i++)
    {
        for (int j=0; j<12; j++)
        {
            sprintf(x[i], "<b>%d</b>", i);
            sprintf(y[j], "<b>%d</b>", j);
            if (i==0 && j==0)
            {
                etykieta=gtk_label_new("");
                gtk_widget_set_size_request(etykieta, 50, 50);
                gtk_grid_attach(GTK_GRID(plansza10x10), etykieta, i, j, 1, 1);
            }
            else if ((i==0 && j==11) || (i==11 && (j==0 || j==11)))
            {
                etykieta=gtk_label_new("");
                gtk_widget_set_size_request(etykieta, 50, 50);
                gtk_grid_attach(GTK_GRID(plansza10x10), etykieta, i, j, 1, 1);
            }
            else if (i==0 || i==11)
            {
                etykieta=gtk_label_new(NULL);
                gtk_label_set_markup(GTK_LABEL(etykieta), y[j]);
                gtk_widget_set_size_request(etykieta, 50, 50);
                gtk_grid_attach(GTK_GRID(plansza10x10), etykieta, i, j, 1, 1);
            }
            else if (j==0 || j==11)
            {
                etykieta=gtk_label_new(NULL);
                gtk_label_set_markup(GTK_LABEL(etykieta), x[i]);
                gtk_widget_set_size_request(etykieta,50,50);
                gtk_grid_attach(GTK_GRID(plansza10x10), etykieta, i, j, 1, 1);
            }
            else
            {
                przyciski10x10[(i-1)*10+j-1] = gtk_button_new_with_label("");
                gtk_widget_set_size_request(przyciski10x10[(i-1)*10+j-1], 50, 50);
                gtk_grid_attach(GTK_GRID(plansza10x10), przyciski10x10[(i-1)*10+j-1], i, j, 1, 1);
            }
        }
    }

   plansza15x15=gtk_grid_new();

    for (int i=0; i<17; i++)
    {
        for (int j=0; j<17; j++)
        {
            sprintf(x[i], "<b>%d</b>", i);
            sprintf(y[j], "<b>%d</b>", j);
            if (i==0 && j==0)
            {
                etykieta=gtk_label_new("");
                gtk_widget_set_size_request(etykieta, 40, 40);
                gtk_grid_attach(GTK_GRID(plansza15x15), etykieta, i, j, 1, 1);
            }
            else if ((i==0 && j==16) || (i==16 && (j==0 || j==16)))
            {
                etykieta=gtk_label_new("");
                gtk_widget_set_size_request(etykieta, 40, 40);
                gtk_grid_attach(GTK_GRID(plansza15x15), etykieta, i, j, 1, 1);
            }
            else if (i==0 || i==16)
            {
                etykieta=gtk_label_new(NULL);
                gtk_label_set_markup(GTK_LABEL(etykieta), y[j]);
                gtk_widget_set_size_request(etykieta, 40, 40);
                gtk_grid_attach(GTK_GRID(plansza15x15), etykieta, i, j, 1, 1);
            }
            else if (j==0 || j==16)
            {
                etykieta=gtk_label_new(NULL);
                gtk_label_set_markup(GTK_LABEL(etykieta), x[i]);
                gtk_widget_set_size_request(etykieta, 40, 40);
                gtk_grid_attach(GTK_GRID(plansza15x15), etykieta, i, j, 1, 1);
            }
            else
            {
                przyciski15x15[(i-1)*15+j-1] = gtk_button_new_with_label("");
                gtk_widget_set_size_request(przyciski15x15[(i-1)*15+j-1], 40, 40);
                gtk_grid_attach(GTK_GRID(plansza15x15), przyciski15x15[(i-1)*15+j-1], i, j, 1, 1);
            }
        }
    }

    plansza19x19=gtk_grid_new();

    for (int i=0; i<21; i++)
    {
        for (int j=0; j<21; j++)
        {
            sprintf(x[i], "<b>%d</b>", i);
            sprintf(y[j], "<b>%d</b>", j);
            if (i==0 && j==0)
            {
                etykieta=gtk_label_new("");
                gtk_widget_set_size_request(etykieta, 35, 35);
                gtk_grid_attach(GTK_GRID(plansza19x19), etykieta, i, j, 1, 1);
            }
            else if ((i==0 && j==20) || (i==20 && (j==0 || j==20)))
            {
                etykieta=gtk_label_new("");
                gtk_widget_set_size_request(etykieta, 35, 35);
                gtk_grid_attach(GTK_GRID(plansza19x19), etykieta, i, j, 1, 1);
            }
            else if (i==0 || i==20)
            {
                etykieta=gtk_label_new(NULL);
                gtk_label_set_markup(GTK_LABEL(etykieta), y[j]);
                gtk_widget_set_size_request(etykieta,35,35);
                gtk_grid_attach(GTK_GRID(plansza19x19), etykieta,i,j,1,1);
            }
            else if (j==0 || j==20)
            {
                etykieta=gtk_label_new(NULL);
                gtk_label_set_markup(GTK_LABEL(etykieta), x[i]);
                gtk_widget_set_size_request(etykieta,35,35);
                gtk_grid_attach(GTK_GRID(plansza19x19), etykieta,i,j,1,1);
            }
            else
            {
                przyciski19x19[(i-1)*19+j-1] = gtk_button_new_with_label("");
                gtk_widget_set_size_request(przyciski19x19[(i-1)*19+j-1], 35, 35);
                gtk_grid_attach(GTK_GRID(plansza19x19), przyciski19x19[(i-1)*19+j-1],i,j,1,1);
            }
        }
    }

    panel_gry=gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
    gtk_box_pack_start(GTK_BOX(manadzerpaneli), panel_gry, TRUE, FALSE, 0);

    gtk_box_pack_start(GTK_BOX(panel_gry),menu_bar,0,0,0);

    aktualny_ruch=gtk_label_new(NULL);
    gtk_widget_set_size_request(aktualny_ruch,100,50);

    gtk_box_pack_start(GTK_BOX(panel_gry),aktualny_ruch,TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(panel_gry),plansza10x10,TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(panel_gry),plansza15x15,TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(panel_gry),plansza19x19,TRUE, FALSE,0);

    iloscruchowbox=gtk_box_new(GTK_ORIENTATION_VERTICAL,10);

    iloscruchow=gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(iloscruchow), "<b>Ilość wszystkich ruchów:</b>");

    pokaz_ilosc_ruch=gtk_label_new(NULL);
    gtk_box_pack_start(GTK_BOX(iloscruchowbox), iloscruchow, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(iloscruchowbox), pokaz_ilosc_ruch, TRUE, FALSE, 0);

    gtk_widget_set_margin_start(iloscruchowbox,400);
    gtk_widget_set_margin_end(iloscruchowbox,50);
    gtk_widget_set_size_request(iloscruchowbox,50,50);
    gtk_widget_set_margin_bottom(iloscruchowbox, 30);

    gtk_box_pack_start(GTK_BOX(panel_gry),iloscruchowbox,TRUE, FALSE,0);

    for (int j=0; j<100; j++)
    {
        tablica_sygnaly10x10[j]=j;
        g_signal_connect (G_OBJECT (przyciski10x10[j]), "clicked",G_CALLBACK (klikniety_przycisk10x10), &tablica_sygnaly10x10[j]);
    }
    for (int j=0; j<225; j++)
    {
        tablica_sygnaly15x15[j]=j;
        g_signal_connect (G_OBJECT (przyciski15x15[j]), "clicked",G_CALLBACK (klikniety_przycisk15x15), &tablica_sygnaly15x15[j]);
    }
    for (int j=0; j<361; j++)
    {
        tablica_sygnaly19x19[j]=j;
        g_signal_connect (G_OBJECT (przyciski19x19[j]), "clicked",G_CALLBACK (klikniety_przycisk19x19), &tablica_sygnaly19x19[j]);
    }
    g_signal_connect(G_OBJECT(menu_wyjscie_do_menu), "activate", G_CALLBACK(powrot_z_gry), NULL);
    g_signal_connect(G_OBJECT(menu_zapisz_gre), "activate", G_CALLBACK(zapisz_gre), NULL);

    //koncowe_okno

    GtkWidget *wyjscie;

    napis_koncowy1=gtk_image_new_from_file("Grafika/Napisy/Wygral_rozowy.png");
    napis_koncowy2=gtk_image_new_from_file("Grafika/Napisy/Wygral_niebieski.png");
    remis=gtk_image_new_from_file("Grafika/Napisy/Remis.png");

    vboxkoniec=gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    gtk_widget_set_margin_start (vboxkoniec, 30);
    gtk_widget_set_margin_end (vboxkoniec, 30);
    gtk_widget_set_margin_bottom (vboxkoniec, 30);
    gtk_widget_set_margin_top (vboxkoniec, 30);

    gtk_box_pack_start(GTK_BOX(vboxkoniec), napis_koncowy1, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vboxkoniec), napis_koncowy2, TRUE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vboxkoniec), remis, TRUE, FALSE, 0);

    wyjscie=gtk_button_new_with_label("Powrót do menu");
    gtk_widget_set_margin_start(wyjscie,120);
    gtk_widget_set_margin_end(wyjscie,120);
    gtk_widget_set_size_request(wyjscie,100,70);
    gtk_box_pack_start(GTK_BOX(vboxkoniec), wyjscie,TRUE, FALSE,0);

    gtk_box_pack_start(GTK_BOX(manadzerpaneli), vboxkoniec,TRUE, FALSE,0);

    g_signal_connect (G_OBJECT (wyjscie), "clicked",G_CALLBACK (powrot_z_okna_wygranej), NULL);

    gtk_widget_show(GTK_WIDGET(okno));
    gtk_widget_show(manadzerpaneli);
    gtk_widget_show_all(Vbox_z_panelem_startowym);

    gtk_main();

    return 0;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TP11Main.c
 * Author: ebatemarco
 *
 * Created on 29 de octubre de 2020, 13:59
 */

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

void must_init(bool test, const char *description)
{
    if(test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");

    ALLEGRO_DISPLAY* display = al_create_display(256, 128);
    must_init(display, "display");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_image_addon(), "image addon");//Para trabajar con imagenes
    
    ALLEGRO_BITMAP* BitsPanel = al_load_bitmap("EstadoBase.jpg");
    must_init(BitsPanel, "BitsPanel");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));

    bool done = false;
    bool redraw = true;
    bool close_display = false; 
    ALLEGRO_EVENT ev;

    
    while(!close_display)
    {
        al_wait_for_event(queue, &ev);

        if (al_get_next_event(queue, &ev)) //Toma un evento de la cola, VER RETURN EN DOCUMENT.
        {
            if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                close_display = true;
        }
        
        if(redraw && al_is_event_queue_empty(queue))
        {
            al_draw_bitmap(BitsPanel, 0, 0, 0);

            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_bitmap(BitsPanel);
    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(queue);

    return 0;
}

#include <stdio.h>
#include "playlist.h"
#include <stdlib.h>


typedef struct mysongT {
    song tune;
    int played;
} mysong;

struct playlistType{
    int first, last;
    mysong * Q;
    int size, next, mode;
};

int initSize = 10;


/* EFFECTS: allocates and initialises an empty playlist which will play in normal mode.*/
playlist initialisePlaylist() {
    playlist p = malloc(sizeof(playlist));
    p->first = -1;
    p->last = -1;
    p->Q = malloc(sizeof(mysong) * initSize);
    p->size = initSize;
    p->next = 0;
    p->mode = 0;
	return p;
}


//EFFECTS: copies array aux into array Q
void copy(mysong * aux, mysong * Q, int size) {
    int i;
    for (i=0; i<size; i++) {
        Q[i] = aux[i];
    }
}


// EFFECTS: checks whether arrray p->Q needs expanding
void check(playlist p) {
    if (p->last == p->size - 1) {
        mysong * aux = p->Q;
        p->size = p->size * 2;
        p->Q = malloc(sizeof(mysong) * p->size);
        copy(aux, p->Q, p->size);
       //free(aux);
    }
}


/* EFFECTS: returns position of next song to be played */
int findnext(playlist p) {
    if (p->next == p->last)
        p->next = 0;
    else
        p->next++;
    return p->next;
}


/* EFFECTS: adds s as the last element of p.*/
void addSong(playlist p, song s){
    check (p);
    mysong newsong;
    newsong.tune = s;
    newsong.played = 0;
    p->last++;
    p->Q[p->last] = newsong;
}


/* EFFECTS: returns the ID of the next song of p to be played.*/
int playSong(playlist p) {
    int aux;
    aux = p->next;
    if (p->mode == 1) {
        if (p->Q[p->next].played == 0) { //unplayed
            p->Q[p->next].played = 1;
            p->next = findnext(p);
            return p->Q[aux].tune->id;
        }

        else { // already played
            int r;
            int i;
            p->next = findnext(p);
            while (i <= p->last) {
                if (p->Q[p->next].played == 0) {
                    r = p->Q[p->next].tune->id;
                    p->Q[p->next].played = 1;
                    p->next = findnext(p);
                    break;
                }

                else {
                    r = -1;
                    p->next = findnext(p);
                }
                i++;
            }
            return r;
        }
    }

    else { // p->mode == 0
        p->Q[p->next].played = 1;
        p->next = findnext(p);
        return p->Q[aux].tune->id;
    }
}


/* EFFECTS: set p to play from the ith song. I.e., after the call the ith song will be the next song to be played.*/
void playFrom(playlist p, int i){
    if (i-1 <= p->last)
        p->next = i - 1;
}


/* EFFECTS: if p is not empty, skips the next song which will not be played.*/
void skipSong(playlist p) {
    if (p)
        p->next = findnext(p);
}


/* EFFECTS: if mode is 1 (skip Mode) then set the playlist p to play only songs that were not played before.
 * If mode is 0 (normal mode) resets p and sets it to play all songs.*/
void skipAllPlayedSongs(playlist p, int mode){
    if (mode == 1) {
        p->mode = 1;
    }
    else {
        p->mode = 0;
        int i = 0;
        p->next = 0;
        for (i=0; i<=p->last; i++)
            p->Q[i].played = 0;
    }
}


/* EFFECTS: resets p making the first song in the sequence to be played the next to be played.*/
void restart(playlist p){
    p->next = 0;
}


/* EFFECTS: if i and j are smaller than or equal to the number of songs in p,
 * the function swaps the ith song and the jth song in p.*/
void swapSongs(playlist p, int i, int j){
    int a = i-1;
    int b = j-1;

    if (a <= p->last && b <= p->last) {
        mysong aux;
        aux = p->Q[a];
        p->Q[a] = p->Q[b];
        p->Q[b] = aux;
    }
}


/* EFFECTS: deallocate all the memory required by p.*/
void freePlaylist(playlist p){
    free(p);
}


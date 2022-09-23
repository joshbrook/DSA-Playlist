/*Songs are modelled using the following struct*/

struct songT{
	int id; //id that uniquely identifies a song.
	char * title; //title of the song.
	float duration; //duration of the song.
};

typedef struct songT * song;

/*We will now define the interface of the ADT playlist*/


/*OVERVIEW: is a dynamic sequence of songs. Songs can be inserted in the playlist and will be played in the same order in which they were inserted unless the prder og the sequence was modified using swapSongs, the restart, or playFrom.  Once all the songs have being played or skipped the playlist will restart from the first song in the list.
*/


typedef struct playlistType * playlist;

/* EFFECTS: allocates and initialises an empty playlist which will play in normal mode.*/
playlist initialisePlaylist();

/* EFFECTS: adds s as the last element of p.*/
void addSong(playlist p, song s);

/* EFFECTS: returns the ID of the next song of p to be played.*/
int playSong(playlist p);

/* EFFECTS: set p to play from the ith song. I.e., after the call the ith song will be the next song to be played.*/
void playFrom(playlist p, int i);

/* EFFECTS: if p is not empty, skips the next song which will not be played.*/
void skipSong(playlist p);

/* EFFECTS: if mode is 1 (skip Mode) then set the playlist p to play only songs that were not played before. If mode is 0 (normal mode) resets p and sets it to play all songs.*/
void skipAllPlayedSongs(playlist p, int mode);

/* EFFECTS: resets p making the first song in the sequence to be played the next to be played.*/
void restart(playlist p);

/* EFFECTS: if i and j are smaller than or equal to the number of songs in p, the function swaps the ith song and the jth song in p.*/
void swapSongs(playlist p, int i, int j);


/* EFFECTS: deallocate all the memory required by p.*/
void freePlaylist(playlist p);


# Data Structures & Algorithms - Playlist

# Introduction
This repo contains work for Assignment 2 of the Data Structures & Algorithms course.
In this project, I implement functionality for a playlist of songs, based on a queue-style dynamic array data structure.
The bulk of the code is stored in the [main](main.c) file, and a detailed report containing all my descisions can be found in the [report](report.pdf) pdf, which has been generated through LaTeX written in [OrgMode](https://orgmode.org/) for [Emacs](https://www.gnu.org/software/emacs/).
Below is the project brief with more details.

# Project Brief
Your company is developing a new program to stream songs. 

For this reason you were asked to implement some of the functionalities that allow to manage the playlists of this new software.


## Definintions
The main entity of the software you are developing are songs. 

A song consists of a struct which has three ﬁelds, id, title, and duration. 

Where id is an integer that uniquely identiﬁes a song, title is the title of the song, and duration is a ﬂoat that speciﬁes the duration of the song in seconds.


## Playlist Behaviours to Implement
A playlist will be used by the program to keep track of which song should be played next.

You can think of a playlist as a dynamic sequence of songs where songs can be added to the end of the sequence using the function addSong. 

Unless the playlist was modiﬁed, songs are usually played in the same order in which they were added.

The user is also allowed to skip songs using the skipSong function. 

Once all the songs are played or skipped the playlist will restart playing from the first song.

The user program can also start to play the playlist from any given position in the sequence using the function playFrom. 

Moreover, the playlist has two modes of playing songs: 
- Skip Mode: in which songs that were played at least once before are skipped
- Normal Mode: in which all the songs in the playlist are played unless they are explicitly skipped. 

The user program can change the play mode using the function skipAllPlayedSongs. 

Finally, the user can modify the playlist using the function swapSongs which swaps the position of two songs in the playlist.



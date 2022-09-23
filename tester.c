#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"
#include <time.h>


const int TESTNUMBER=10;//number of random operations to be tested
const int OPNUMBER=7; //number of operations implemented
const int INPUTFROMFILE=1;//set to 0 if you do not want the random data to be read from file and to 1 otherwise
const int SAVETOFILE=0;//set to 0 if you do not want the random data generated by the tester to be saved 1 otherwise.

const char* INPUT="RANDOMIN";//Name of the file containing test data for the program
const char* OUTPUT="RANDOMOUT";//Name of the file where the test data will be saved

int main(){
	int i;
	int op;
	int  testData[TESTNUMBER*3];
	FILE * randomIn=NULL;
	FILE * randomOut=NULL;
	if(SAVETOFILE) randomOut=fopen(OUTPUT,"w+");
	if(INPUTFROMFILE){
		i=0;
		randomIn=fopen(INPUT,"r");
		if(randomIn){
			while(fscanf(randomIn," %d ",&testData[i])==1 && i<TESTNUMBER*3) i++;
			fclose(randomIn);
		}else{
			printf("Input file not found\n");
			return 1;
		}
	}
	int songCounter=0;
	int songIndex=0;
	int start;
	int swap1;
	int swap2;
	int mode;
	song songs[TESTNUMBER];
	for(i=0;i<TESTNUMBER;i++){
		song s=malloc(sizeof(struct songT));
		s->id=i;
		s->title="song";
		s->duration=rand();
		songs[i]=s;
	}
	playlist p=initialisePlaylist();
	srand(time(0));
	i=0;
	int dataIndex=0;
	while(i<TESTNUMBER){
			if(INPUTFROMFILE){
				op=testData[dataIndex];
				dataIndex++;
			}
			else op=rand()%OPNUMBER;
			switch(op){
				case 0:
					printf("add song with ID %d\n",songIndex);
					addSong(p,songs[songIndex]);
					songCounter++;
					songIndex++;
					i++;
					if(SAVETOFILE) fprintf(randomOut,"%d\n",op);
					break;
				case 1:
					printf("Play song with ID %d\n", playSong(p));
					i++;
					if(SAVETOFILE) fprintf(randomOut,"%d\n",op);
					break;
				case 2:
					if(songCounter>0){
						if(INPUTFROMFILE){
							start=testData[dataIndex];
							dataIndex++;
						}else start=rand()%songCounter;
						printf("Play From the %dth song\n",start);
						playFrom(p,start);
						i++;
						if(SAVETOFILE) fprintf(randomOut,"%d\n%d\n",op,start);

					}
					break;
				case 3:
					printf("Skip song\n");
					skipSong(p);
					i++;
					if(SAVETOFILE) fprintf(randomOut,"%d\n",op);
					break;
				case 4:
					printf("Restart\n");
					restart(p);
					i++;
					if(SAVETOFILE) fprintf(randomOut,"%d\n",op);
					break;
				case 5:
					if(songCounter>1){
						if(INPUTFROMFILE){
							swap1=testData[dataIndex];
							swap2=testData[dataIndex+1];
							dataIndex+=2;
						}else{
							swap1=rand()%(songCounter+1);
							swap2=rand()%(songCounter+1);
						}
						printf("Swap %d  %d\n", swap1,swap2);
						swapSongs(p,swap1,swap2);
						i++;
						if(SAVETOFILE) fprintf(randomOut,"%d\n%d\n%d\n",op,swap1,swap2);
					}
					break;
				case 6:
					if(INPUTFROMFILE){
						mode=testData[dataIndex];
						dataIndex++;
					}else mode=rand()%2;
					if(mode){
						printf("Skip All Played Songs ON\n");
					}else printf("Skip All Played Songs OFF\n");
					skipAllPlayedSongs(p,mode);
					i++;
					if(SAVETOFILE) fprintf(randomOut,"%d\n%d\n",op,mode);
					break;
			}
		}
	if(SAVETOFILE) fclose(randomOut);
 	freePlaylist(p);
	return 0;
}
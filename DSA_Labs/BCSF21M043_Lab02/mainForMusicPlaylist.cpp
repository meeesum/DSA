#include<iostream>
#include "CDLL2.h"
#include "CDLL2.cpp"
using namespace std;
int main(){
    
    CDLL2<string> playlist;
    playlist.addSong("Song1");
    playlist.addSong("Song2");
    playlist.addSong("Song3");
    playlist.addSong("Song4");
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();
    playlist.playNext();  


    return 0;
}
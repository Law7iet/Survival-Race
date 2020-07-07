# Descrizione del progetto:
Survival Race è un gioco di corse automobilistiche a livelli infinito.
La macchina rappresentata dal carattere 'V'.
Per muovere la macchina a sinistra e destra si clicca A e D.
Sulla strada ci possono essere degli ostacoli, rappresentati dai simboli 'x', '+', '\*'.
Al superamento di un punteggio multiplo di 200 e dopo aver finito il blocco di strada sale di livello.
Più si sale di livello e ci sono più ostacoli oppure la velocità aumenta.
Se dato un livello x si scende sotto al punteggio minimo (x * 200) si scende di livello, e si ristampa il blocco di strada già percorso.
Il gioco termina quando il punteggio scende a 0, oppure cliccando il tasto Q.

Il progetto utilizza le seguenti librerie esterne:
* Windows.h
* conio.h
* iostream
* stdlib.h
* time.h

Per una corretta visualizzazione dal terminale si consiglia di avere una finestra di dimensioni 75x25.
Si può accedere al debug inserendo ``#define DEBUG``, e si consiglia di ingrandire la finestra al massimo.
Nell'esecuzione col DEBUG, si possono vedere a destra della schermata alcuni valori che verificano la correttezza del gioco.

Il programma usa la tabella ASCII estesa; se si hanno problemi con tale codifica, bisogna cambiare del codice in Graphics.cpp e Road.cpp (leggi i commenti iniziali).

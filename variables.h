#define fichier "stock.txt"

typedef char CH50[51];
typedef char CH30[31];
int lengh = 5;
int indice = 0;

typedef struct client{
    CH50 nom;
    CH30 pnom;
    int place;
}client;

typedef struct client client;
client CLIENTS[5];
client *p_CL = &CLIENTS[0];

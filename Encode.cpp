using namespace std;
#include <string>
#include "Rotore.cpp"
#include "Collegamento.cpp"

string Codifica (string s, Rotore* r1, Rotore* r2, Rotore* r3, Collegamento* coll){
	int f = 0;
        char h;
        string Return;
        while (f < Return.length()){
            h = Return.at(f++);
            if (h != ' '){
                h = coll->Ritorna(h);
                h = r1->Encode(h, *r1);                
                h = r2->Encode(h, *r1);             
                h = r3->Encode(h, *r2);
                r1->AumentaFase();
                r2->AumentaFase();
                r3->AumentaFase();                
            }
            Return + h;
        }
        return Return;
}

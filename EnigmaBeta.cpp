using namespace std;
#include <string>
#include <iostream>

//Trasforma un char in un numero.
int TrasfInt(char x){
	switch (x){ 
		case 'a': return 1;
        case 'b': return 2;
        case 'c': return 3;
        case 'd': return 4;
        case 'e': return 5;
        case 'f': return 6;
        case 'g': return 7;    
        case 'h': return 8;    
        case 'i': return 9;    
        case 'j': return 10;    
        case 'k': return 11;    
        case 'l': return 12;
        case 'm': return 13;
        case 'n': return 14;    
        case 'o': return 15;    
        case 'p': return 16;    
        case 'q': return 17;    
        case 'r': return 18;    
        case 's': return 19;    
        case 't': return 20;    
        case 'u': return 21;    
        case 'v': return 22;
        case 'w': return 23;
        case 'x': return 24;
        case 'y': return 25;
        case 'z': return 26;
		case 'A': return 1;
        case 'B': return 2;
        case 'C': return 3;
        case 'D': return 4;
        case 'E': return 5;
        case 'F': return 6;
        case 'G': return 7;    
        case 'H': return 8;    
        case 'I': return 9;    
        case 'J': return 10;    
        case 'K': return 11;    
        case 'L': return 12;
        case 'M': return 13;
        case 'N': return 14;    
        case 'O': return 15;    
        case 'P': return 16;    
        case 'Q': return 17;    
        case 'R': return 18;    
        case 'S': return 19;    
        case 'T': return 20;    
        case 'U': return 21;    
        case 'V': return 22;
        case 'W': return 23;
        case 'X': return 24;
        case 'Y': return 25;
        case 'Z': return 26;                
    }
    return 0;	
}

//Trasforma un numero in un char.
char TrasfChar (int x){
    switch (x){    
        default: return ' ';
        case 1: return 'a';
        case 2: return 'b';
        case 3: return 'c';
        case 4: return 'd';
        case 5: return 'e';
        case 6: return 'f';
        case 7: return 'g';    
        case 8: return 'h';    
        case 9: return 'i';    
        case 10: return 'j';    
        case 11: return 'k';    
        case 12: return 'l';
        case 13: return 'm';
        case 14: return 'n';    
        case 15: return 'o';    
        case 16: return 'p';    
        case 17: return 'q';    
        case 18: return 'r';    
        case 19: return 's';    
        case 20: return 't';    
        case 21: return 'u';    
        case 22: return 'v';
        case 23: return 'w';
        case 24: return 'x';
        case 25: return 'y';
        case 26: return 'z';                
    }
}

//Oggetto Rotore.
class Rotore {
	public: 
		//Rappresenta la lettera che si legge.
		int StatoRotazione;
		//La lettera che si legge quando il rotore a fianco scatta.
		int CambiaRotazione;
		//Puntatore alla funzione che rappresenta i collegamenti interni.
		char (*Ritorna) (int);
		
		//Costruttore dei rotori normali.
		Rotore(char chiave, char (*Ret) (int), char cr){
			StatoRotazione = TrasfInt(chiave);			
			Ritorna = Ret;
			CambiaRotazione = TrasfInt(cr);
		}
		
		//Costruttore di Plugboard e Riflettore;
		Rotore (char (*Ret) (int)){
			Ritorna = Ret;
			StatoRotazione = 1;
		}
		
		//Serve per ruotare manualmente il rotore dopo averlo creato.
		void setKey (char c){
			StatoRotazione = TrasfInt(c);
		}
		
		//Ritorna la lettera che si legge nella finestrella.
		char readKey(){
			return TrasfChar(StatoRotazione);
		}
		
		//Rimette il rotore nella posizione originaria.
		void Reset(){
			setKey('a');
		}
		
		//Funzione inversa di ritorna. Rappresenta i collegamenti interni in direzione opposta.
		char RitornaInv (int x){
			int f = 1;
			while (f<=26){			
				if(TrasfInt(Ritorna(f)) == x)
					return TrasfChar(f);
				f++;
			}
		}
		
		//Fa lo scatto che ruota di una lettera il rotore.
		void AumentaFase(){
		StatoRotazione++;
		if (StatoRotazione == 27)
			StatoRotazione = 1;
		}
		
		//Se vera significa che il rotore a fianco deve esser fatto girare.
		bool FaGirare(){
			return StatoRotazione == CambiaRotazione;
		}
		
		//Ritorna la rotazione.
		int GetRotazione(){
			return StatoRotazione;
		}	
		
		//Prende una lettera dal contatto precedente, la fa passare attraverso il rotore.
		char Encode (char c, int RotRel){
			int x = TrasfInt(c);
			x = x + StatoRotazione - RotRel;
			while (x > 26)
				x -= 26;
			while (x < 1)
				x += 26;
			//cout<<x;
			return Ritorna (x);
		}
		
		//Encode dalla direzione opposta.
		char EncodeInv(char c, int RotRel){
			int x = TrasfInt(c);
			x = x + StatoRotazione - RotRel;
			while (x > 26)
				x -= 26;
			while (x < 1)
				x += 26;
			//cout<<x;
			return RitornaInv (x);
		}
};

//Fa ruotare i rotori di quanto devono. Chiamato dopo ogni lettera.
void AumentaRotazioni  (Rotore* R1, Rotore* R2, Rotore *R3){
	R1->AumentaFase();
	if (R1->FaGirare()){
		R2->AumentaFase();
		if (R2->FaGirare())
			R3->AumentaFase();
	}
}

//Codifica una lettera attraverso tutta la macchina.
string Codifica (string s, Rotore* R1, Rotore* R2, Rotore* R3, Rotore* Plugboard, Rotore* Riflettore){
	int f = 0;
    char h;
    string Return = "";
    while (f < s.length()){
		h = s.at(f++);
        if (h != ' '){
        	AumentaRotazioni(R1, R2, R3); 
        	//cout<<h;
            h = Plugboard->Encode(h, 1);
            //cout<<h;
            h = R1->Encode(h, 1); 
			//cout<<h;             
            h = R2->Encode(h, R1->GetRotazione());  
            //cout<<h;
			h = R3->Encode(h, R2->GetRotazione());
			//cout<<h;
			h = Riflettore->Encode(h, R3->GetRotazione());
			//cout<<h;
			h = R3->EncodeInv(h, 1);
			//cout<<h;
			h = R2->EncodeInv(h, R3->GetRotazione());
			//cout<<h;
			h = R1->EncodeInv(h, R2->GetRotazione());
			//cout<<h;
			h = Plugboard->EncodeInv(h, R1->GetRotazione());
			//cout<<h;                          
        }
        Return += h;
       
    }
    return Return;
}

//Imposta la chiave dei rotori e poi chiama codifica.
string Codifica (string s, Rotore* R1, Rotore* R2, Rotore* R3, Rotore* Plugboard, Rotore* Riflettore, string key){
	R1->setKey(key[0]);
	R2->setKey(key[1]);
	R3->setKey(key[2]);
	return Codifica (s, R1, R2, R3, Plugboard, Riflettore);
}

//Rappresentano i collegamenti interni.

string map1 = "ekmflgdqvzntowyhxuspaibrcj";

string map2 = "ajdksiruxblhwtmcqgznpyfvoe";

string map3 = "bdfhjlcprtxvznyeiwgakmusqo";

string map4 = "esovpzjayquirhxlnftgkdcmwb";

string map5 = "vzbrgityupsdnhlxawmjqofeck";

string mapriflB = "yruhqsldpxngokmiebfzcwvjat";

string mapriflC = "fvpjiaoyedrzxwgctkuqsbnmhl";

string mapplug = "abcdefghijklmnopqrstuvwxyz";

//Funzioni che assegnano a un numero una lettera

char C1 (int x){
	return map1[x-1];	
}

char C2 (int x){
	return map2[x-1];
}

char C3 (int x){
	return map3[x-1];
}

char C4 (int x){
	return map4[x-1];
}

char C5 (int x){
	return map5[x-1];
}

char Plug (int x){
	return mapplug[x-1];
}

char RiflB (int x){
	return mapriflB[x-1];
}

char RiflC (int x){
	return mapriflC[x-1];
}

//Rimette la pb in ordine
void ResetPlugboard() {
	mapplug = "abcdefghijklmnopqrstuvwxyz";
}

//Scambia due cavi della plugboard.
void SwapPlugCables(char a, char b){
	int x = TrasfInt(a);
	int y = TrasfInt(b);
	mapplug[x] = b;
	mapplug[y] = a;
}


int main (){
	//Rotori, plugboard e riflettore.
	Rotore* Plugboard = new Rotore(&Plug);
	Rotore* RiflettoreB = new Rotore(&RiflB);
	Rotore* RiflettoreC = new Rotore(&RiflC);
	Rotore* R1 = new Rotore('a', &C1, 'r');
	Rotore* R2 = new Rotore('a', &C2, 'f');
	Rotore* R3 = new Rotore('a', &C3, 'w');
	Rotore* R4 = new Rotore('a', &C4, 'k');
	Rotore* R5 = new Rotore('a', &C5, 'a');
	//Per provarlo:
	cout << Codifica ("ciao", R3, R2, R1, Plugboard, RiflettoreB, "aaa");
}

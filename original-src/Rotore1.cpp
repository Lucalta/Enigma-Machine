#include "Rotore.cpp"
#include "CharAInt.hpp"

class Rotore1 : Rotore {
	public:
		Rotore1(int chiave, Collegamento c) : Rotore(chiave, c){}
		
		void AumentaFase(){
			StatoRotazione++;
			Fase++;
			while (StatoRotazione > 26)
				StatoRotazione -=26;
		}
		
		char Encode (char input, Rotore nonserve){			
        int x = TrasfInt(input);
        
        if (x == 0)
            return ' ';
        
        x += StatoRotazione;
        
        while (x <= 0)
            x += 26;
        while (x > 26)
            x -= 26;
			
		return Collegamenti.Ritorna(x);
		}
};

#include "Rotore.cpp"
#include "CharAInt.hpp"

class Rotore3 : Rotore {
	public:
		Rotore3(int chiave, Collegamento c) : Rotore(chiave, c){}
		
		void AumentaFase(){
        Fase++;
        float y = Fase / 676;
        int z = 0;
        while (z+1 <= y)
            z++;
        StatoRotazione = RotazioneBase + z;
        while (StatoRotazione > 26)
            StatoRotazione -= 26;
   		}
		
		
		char Encode (char input, Rotore rotore2) {
        
        int x = TrasfInt(input);
        
        if (x == 0)
            return ' ';
        
        x += StatoRotazione - rotore2.GetRotazione();
        
        while (x <= 0)
            x += 26;
        while (x > 26)
            x -= 26;        
			
		return Collegamenti.Ritorna(x);
		}
};

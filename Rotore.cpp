#include "Collegamento.cpp"

class Rotore {
	public: 
		int RotazioneBase;
		int StatoRotazione;
		int Fase;
		Collegamento Collegamenti;
		
		Rotore(int chiave, Collegamento c){
			Fase = 0;
			RotazioneBase = chiave;			
			Collegamenti = c;
			while (RotazioneBase > 26)
				RotazioneBase -=26;
			StatoRotazione = RotazioneBase;
		}
	
		virtual void AumentaFase(){};
		
		int GetRotazione(){
			return StatoRotazione;
		}	
		
		virtual char Encode (char input, Rotore rotore){};
		
		~Rotore(){};
		Rotore(){};
};

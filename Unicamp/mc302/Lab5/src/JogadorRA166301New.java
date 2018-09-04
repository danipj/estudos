import java.util.ArrayList;

public class JogadorRA166301New extends JogadorRA166301{

	public JogadorRA166301New(ArrayList<Carta> maoInicial, boolean primeiro) {
		super(maoInicial, primeiro);
		// TODO Auto-generated constructor stub
	}

	public ArrayList<Jogada> processarTurno (Mesa mesa, Carta cartaComprada, ArrayList<Jogada> jogadasOponente){
		int minhaMana, minhaVida;
		if(cartaComprada != null)
			mao.add(cartaComprada);
		if(primeiroJogador){
			minhaMana = mesa.getManaJog1();
			minhaVida = mesa.getVidaHeroi1();
			lacaios = mesa.getLacaiosJog1();
			lacaiosOponente = mesa.getLacaiosJog2();
			//System.out.println("--------------------------------- Começo de turno pro jogador1");
		}
		else{
			minhaMana = mesa.getManaJog2();
			minhaVida = mesa.getVidaHeroi2();
			lacaios = mesa.getLacaiosJog2();
			lacaiosOponente = mesa.getLacaiosJog1();
			//System.out.println("--------------------------------- Começo de turno pro jogador2");
		}
		
		ArrayList<Jogada> minhasJogadas = new ArrayList<Jogada>();
		
		boolean usouLacaio = false,usouMagia = false;
		// O laço abaixo cria jogas de baixar lacaios da mão para a mesa se houver mana disponível.
		for(int i = 0; i < mao.size(); i++){
			if (usouMagia && usouLacaio) {
				continue;
			}
			Carta card = mao.get(i);
			if(card instanceof CartaMagia && card.getMana() <= minhaMana){
				Jogada magia = new Jogada(TipoJogada.MAGIA, card, null);
				minhasJogadas.add(magia);
				minhaMana -= card.getMana();
				System.out.println("Jogada: Decidi uma jogada de usar magia: "+ card);
				mao.remove(i);
				i--;
				usouMagia = true;
				continue;
			}
			if(card instanceof CartaLacaio && card.getMana() <= minhaMana){
				Jogada lac = new Jogada(TipoJogada.LACAIO, card, null);
				minhasJogadas.add(lac);
				minhaMana -= card.getMana();
				System.out.println("Jogada: Decidi uma jogada de baixar o lacaio: "+ card);
				mao.remove(i);
				i--;
				usouLacaio = true;
			}
		}
		//bubblesort pra deixar os lacaios mais fortes no comeco do vetor
		CartaLacaio c = null;
		for(int i=0;i<lacaios.size()-1;i++){
			if(lacaios.get(i).getAtaque()<lacaios.get(i+1).getAtaque()){
				 c = lacaios.get(i);
				lacaios.set(i, lacaios.get(i+1));
				lacaios.set(i+1, c);
			}
		}
		//atacar com todos os lacaios vivos
		for(CartaLacaio lac:lacaios){
			
			if (lac.getMana()<=minhaMana) {
				Jogada atq = new Jogada(TipoJogada.ATAQUE,lac,null);
				minhasJogadas.add(atq);
				minhaMana-=lac.getMana();
			}
		}
		return minhasJogadas;
	}
}

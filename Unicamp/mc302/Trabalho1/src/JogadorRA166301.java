import java.util.ArrayList;

/*No cabeçalho do código-fonte deve haver um texto comentado, de pelo
menos 30 e no máximo 60 linhas, descrevendo organizadamente a estratégia adotada pelo seu jogador
para cada comportamento, ou seja, quais critérios são utilizados para baixar lacaios, utilizar
magias, utilizar poder heróico, escolher os alvos e quando utilizar magias de área. Além disso,
descreva em poucas palavras qual o critério que seu jogador utiliza para trocar entre os comportamentos*/

/*Estratégias por comportamento:
 * AGRESSIVO:
 * Baixar lacaios: Prioriza os lacaios de maior ataque ao baixar
 * Utilizar magias: Magias de alvo são utilizadas no herói enquanto houver mana
 * Utilizar poder: Utiliza poder heroico sempre que houver mana disponível para tal
 * Escolher os alvos: Esse comportamento não realiza trocas, uma vez que seu foco está em atacar o herói adversário
 * Utilizar magias de área: Utiliza sempre que há mana disponível
 * * Esse comportamento prioriza a mana na seguinte ordem:
 * Magias de buff nos lacaios de maior ataque, baixar lacaios, magias de alvo, magias de área, poder heroico e por fim, uma vez que não utliiza mana, atacar o herói com os lacaios.
 * CONTROLE:
 * Baixar lacaios: Baixa lacaios dentro da mana disponível
 * Utilizar magias: Magias de alvo são utilizadas quando a vida restante do lacaio adversário for zero ou 1. Buffs não são usados.
 * Utilizar poder: Utiliza poder heroico sempre que houver mana disponível para tal
 * Escolher os alvos: Realiza trocas favoráveis (descrição abaixo). Quando não for possível, ataca o herói.
 * Utilizar magias de área: Utiliza quando há 2 ou mais lacaios adversários na mesa
 * * Esse comportamento prioriza a mana na seguinte ordem:
 * Magias de alvo e magias de área na ordem da mão, baixar lacaios, poder heroico e por fim, uma vez que não utliiza mana, atacar com os lacaios.
 * CURVA DE MANA:
 * Baixar lacaios: Priorizar lacaios de maior mana ao baixar
 * Utilizar magias: Magias de alvo são utilizadas quando a mana do lacaio for maior que a mana da magia e esse lacaio for eliminado pelo dano. Buffs não são usados.
 * Utilizar poder: Utiliza poder heroico sempre que houver mana disponível para tal
 * Escolher os alvos: Realiza trocas favoráveis (descrição abaixo). Quando não for possível, ataca o herói.
 * Utilizar magias de área: Magias de area são utilizadas quando a soma de mana dos lacaios for maior que a mana da magia
 * * Esse comportamento prioriza a mana na seguinte ordem:
 * Baixar lacaios, magias de alvo e magias de área na ordem da mão, poder heroico e por fim, uma vez que não utliiza mana, atacar com os lacaios.
 * TROCAS FAVORÁVEIS: Ocorrem de acordo com o enunciado
 * 
 * Quando utilizar cada comportamento:
 * Quando poucos lacaios em mesa (2 ou menos), utiliar a jogada agressiva para baixar lacaios sem deixar de atacar o adversário diretamente.
 * Após essa situação, a mesa ja deve ter alguns lacaios para atacar, e ainda não deve ter passado do turno 10. Portanto, quando houver menos que 10 mana,
 * utilizar o comportamento Curva de Mana, para além de baixar mais lacaios e trocar favoravelmente, atacar também com magias.
 * Caso ja tenha passado do turno 8, tal comportamento se torna inviável por ter muita mana para gastar, então se concentrar no Controle,
 * a menos que a vida seja menor ou igual a 28. Nesse caso, voltar para o Agressivo, para focar em atacar diretamente o herói, possivelmente ganhando com pouca vida.
 * O comportamento Agressivo se mostrou muito mais efetivo que os outros dois, portanto é o mais utilizado.
 * */
public class JogadorRA166301 extends Jogador {
	protected ArrayList<CartaLacaio> lacaios;
	protected ArrayList<CartaLacaio> lacaiosOponente;
	
	/**
	  * O mÃ©todo construtor do JogadorAleatorio.
	  * 
	  * @param maoInicial ContÃ©m a mÃ£o inicial do jogador. Deve conter o nÃºmero de cartas correto dependendo se esta classe Jogador que estÃ¡ sendo construÃ­da Ã© o primeiro ou o segundo jogador da partida. 
	  * @param primeiro   Informa se esta classe Jogador que estÃ¡ sendo construÃ­da Ã© o primeiro jogador a iniciar nesta jogada (true) ou se Ã© o segundo jogador (false).
	  */
	public JogadorRA166301(ArrayList<Carta> maoInicial, boolean primeiro){
		primeiroJogador = primeiro;
		
		mao = maoInicial;
		lacaios = new ArrayList<CartaLacaio>();
		lacaiosOponente = new ArrayList<CartaLacaio>();
		
		// Mensagens de depuraÃ§Ã£o:
		//System.out.println("*Classe JogadorRAxxxxxx* Sou o " + (primeiro?"primeiro":"segundo") + " jogador (classe: JogadorRA)");
		//System.out.println("Mao inicial:");
		//for(int i = 0; i < mao.size(); i++)
			//System.out.println("ID " + mao.get(i).getID() + ": " + mao.get(i));
	}
	
	/**
	  * Um mÃ©todo que processa o turno de cada jogador. Este mÃ©todo deve retornar as jogadas do Jogador decididas para o turno atual (ArrayList de Jogada).
	  * 
	  * @param mesa   O "estado do jogo" imediatamente antes do inÃ­cio do turno corrente. Este objeto de mesa contÃ©m todas as informaÃ§Ãµes 'pÃºblicas' do jogo (lacaios vivos e suas vidas, vida dos herÃ³is, etc).
	  * @param cartaComprada   A carta que o Jogador recebeu neste turno (comprada do Baralho). Obs: pode ser null se o Baralho estiver vazio ou o Jogador possuir mais de 10 cartas na mÃ£o.
	  * @param jogadasOponente   Um ArrayList de Jogada que foram os movimentos utilizados pelo oponente no Ãºltimo turno, em ordem.
	  * @return            um ArrayList com as Jogadas decididas
	  */
	public ArrayList<Jogada> processarTurno (Mesa mesa, Carta cartaComprada, ArrayList<Jogada> jogadasOponente){
		int minhaMana, minhaVida;
		if(cartaComprada != null)
			mao.add(cartaComprada);
		if(primeiroJogador){
			minhaMana = mesa.getManaJog1();
			minhaVida = mesa.getVidaHeroi1();
			lacaios = mesa.getLacaiosJog1();
			lacaiosOponente = mesa.getLacaiosJog2();
		} else {
			minhaMana = mesa.getManaJog2();
			minhaVida = mesa.getVidaHeroi2();
			lacaios = mesa.getLacaiosJog2();
			lacaiosOponente = mesa.getLacaiosJog1();
		}
		
		///////////////////////////////////////////////////////Definir qual comportamento usar
		////Agressivo: Preparação da mesa com os lacaios, atacando o herói com magias enquanto isso
		////////////// Utilizar enquanto tiver 2 ou menos lacaios em mesa
		////Controle: Ataca os lacaios, se não o herói. Não foca em baixar lacaios
		///////////// Utilizar quando tiver mana pra atacar com magias e lacaios suficientes
		////CurvaDeMana: Usar toda mana disponível
		//System.out.println("Mana na jogada:"+minhaMana);
		//System.out.println("Lacaios na jogada:"+lacaios.size());
		if (lacaios.size()<=2 || minhaVida <=28) {
			//System.out.println("Jogada agressiva");
			return jogadaAgressivo(minhaMana);
		} else if(minhaMana<8){
			//System.out.println("Jogada curva");
			return jogadaCurvaDeMana(minhaMana);
		} else {
			//System.out.println("Jogada Controle");
			return jogadaControle(minhaMana);
		}
		
	}
	
	
	public ArrayList<Jogada> jogadaAgressivo(int manaAtual){
		/*As prioridades desse comportamento são baixar lacaios de ataque alto, usar magias de alvo no herói do
oponente e quase nunca realizar trocas com os lacaios do oponente*/
		ArrayList<Jogada> jogada = new ArrayList<Jogada>();
		ArrayList<Carta> removerCartas = new ArrayList<Carta>();
		int lacaiosRodada = lacaios.size();

		//buffar lacaios da mesa de maior ataque para posteriormente atacar o heroi
		manaAtual = buffar(jogada,  manaAtual, 1);
		
		ArrayList<CartaLacaio> lacaiosAgressivos = getLacaiosAtributo(getLacaiosMao(),1);
		for(Carta card:lacaiosAgressivos){
			if (card.getMana()<=manaAtual && !cartaUsada(card, removerCartas) && lacaiosRodada<7) {
				//baixar lacaios de maior ataque
				jogada.add(new Jogada(TipoJogada.LACAIO,card,null));
				lacaiosRodada++;
				manaAtual-=card.getMana();
				removerCartas.add(card);
			}
		}
		for(int i=0;i<removerCartas.size();i++){
			mao.remove(removerCartas.get(i));
		}
		for(Carta card:mao){
			if (card instanceof CartaMagia && card.getMana()<=manaAtual && ((CartaMagia) card).getMagiaTipo()==TipoMagia.ALVO
					 && !cartaUsada(card, removerCartas)) {
				//usar no heroi
				jogada.add(new Jogada(TipoJogada.MAGIA, card, null));
				manaAtual-=card.getMana();
				removerCartas.add(card);
			}
		}
		for(int i=0;i<removerCartas.size();i++){
			mao.remove(removerCartas.get(i));
		}
		
		for(Carta card:mao){
			if (card instanceof CartaMagia && card.getMana()<=manaAtual && ((CartaMagia) card).getMagiaTipo()==TipoMagia.AREA
					 && !cartaUsada(card, removerCartas)) {
				jogada.add(new Jogada(TipoJogada.MAGIA, card, null));
				manaAtual-=card.getMana();
				removerCartas.add(card);
				//aplicar dano em todos os lacaios
				for(CartaLacaio l:lacaiosOponente){
					l.setVidaAtual(l.getVidaAtual()-((CartaMagia)card).getMagiaDano());
				}
			}
		}
		for(int i=0;i<removerCartas.size();i++){
			mao.remove(removerCartas.get(i));
		}

		//se tiver mana, ataca heroi com poder
		if (manaAtual-2>=0) {
			jogada.add(new Jogada(TipoJogada.PODER,null,null));
			manaAtual-=2;
		}
		

		//se tiver lacaios, ataca heroi
		for(CartaLacaio l:lacaios){
			jogada.add(new Jogada(TipoJogada.ATAQUE,l,null));
		}


		////////nao parece boa estrategia realizar trocas com poucos lacaios, seria sacrificar bons ataques
		return jogada;
	}
	
	public ArrayList<Jogada> jogadaControle(int manaAtual){
		ArrayList<Jogada> jogada = new ArrayList<Jogada>();
		/*: (i) magias de área
são usadas somente se houver dois ou mais lacaios do oponente em campo; (ii) magias de dano em alvo
são usadas apenas para eliminar lacaios e onde a diferença entre o dano da magia e a vida atual do lacaio
é pequena (no máximo 1)*/
		ArrayList<Carta> removerCartas = new ArrayList<Carta>();
		for(Carta c:mao){
				if (c instanceof CartaMagia && ((CartaMagia) c).getMagiaTipo()==TipoMagia.AREA && lacaiosOponente.size()>=2 
						&& c.getMana()<=manaAtual &&!cartaUsada(c, removerCartas)) {
					jogada.add(new Jogada(TipoJogada.MAGIA,c,null));
					manaAtual-=c.getMana();
					removerCartas.add(c);
					//aplicar dano em todos os lacaios
					for(CartaLacaio l:lacaiosOponente){
						l.setVidaAtual(l.getVidaAtual()-((CartaMagia)c).getMagiaDano());
					}
				} else if (c instanceof CartaMagia && ((CartaMagia) c).getMagiaTipo()==TipoMagia.ALVO && c.getMana()<=manaAtual){
					acharAlvo:for(CartaLacaio l:lacaiosOponente){
						if(cartaUsada(c, removerCartas)){
							break;
						}
						if(l.getVidaAtual()<=0){
							continue;
						}
						//////////priorizar magias que matam o lacaio????
						if (l.getVidaAtual()-((CartaMagia)c).getMagiaDano()<=1&&l.getVidaAtual()-((CartaMagia)c).getMagiaDano()>=0) {
							jogada.add(new Jogada(TipoJogada.MAGIA,c,l));
							manaAtual-=c.getMana();
							l.setVidaAtual(l.getVidaAtual()-((CartaMagia)c).getMagiaDano());
							//mao.remove(c);
							removerCartas.add(c);
							break acharAlvo;
						}
					}
				}
		}
		for(int i=0;i<removerCartas.size();i++){
			mao.remove(removerCartas.get(i));
		}

		//baixar mais lacaios dentro da mana restante
		int lacaiosRodada = lacaios.size();
		for(CartaLacaio l:getLacaiosMao()){
			if(l.getMana()<=manaAtual && !cartaUsada(l, removerCartas)&& lacaiosRodada<7){
				jogada.add(new Jogada(TipoJogada.LACAIO,l,null));
				lacaiosRodada++;
				manaAtual-=l.getMana();
				removerCartas.add(l);
			}
		}
		for(int i=0;i<removerCartas.size();i++){
			mao.remove(removerCartas.get(i));
		}
		
		if (manaAtual-2>=0) {
			jogada.add(new Jogada(TipoJogada.PODER,null,null));
			manaAtual-=2;
		}
		//buffar nesse comportamento se provou menos efetivo
		//manaAtual = buffar(jogada, manaAtual, 3);

		/*acumulando mais lacaios vivos do
que o oponente e assim podendo realizar “trocas favoráveis”
Quando não há trocas favoráveis, a estratégia controle usa seus lacaios para atacar o herói do oponente*/
		trocarFavoravelmente(jogada);
		return jogada;
	}
	
	public ArrayList<Jogada> jogadaCurvaDeMana(int manaAtual){
		/*Esse comportamento procura usar as cartas da mão de maneira a utilizar toda a mana disponível em cada
turno.*/
		ArrayList<Jogada> jogada = new ArrayList<Jogada>();
		ArrayList<Carta> removerCartas = new ArrayList<Carta>();
		int lacaiosRodada = lacaios.size();
		//baixar lacaios
		for(Carta c:getLacaiosAtributo(getLacaiosMao(),2)){
			if (c instanceof CartaLacaio && c.getMana()<=manaAtual  && !cartaUsada(c, removerCartas)&& lacaiosRodada<7) {
				jogada.add(new Jogada(TipoJogada.LACAIO,c,null));
				manaAtual-=c.getMana();
				lacaiosRodada++;
				removerCartas.add(c);
			}
		}
		for(int i=0;i<removerCartas.size();i++){
			mao.remove(removerCartas.get(i));
		}
		/*As magias somente são utilizadas se forem eliminar lacaio(s) que somem mais do que o custo de mana
da própria magia*/
		for(Carta c:mao){
				if (c instanceof CartaMagia && c.getMana()<=manaAtual) {
					//ver se existe lacaio que morre com esse dano
					if (((CartaMagia)c).getMagiaTipo()==TipoMagia.ALVO) {
						for(CartaLacaio l:lacaiosOponente){
							if(l.getVidaAtual()<=0)
								continue;
							if(l.getVidaAtual()<=((CartaMagia)c).getMagiaDano()	&& l.getMana()<=c.getMana()&&!cartaUsada(c, removerCartas)) {
								jogada.add(new Jogada(TipoJogada.MAGIA,c,l));
								manaAtual-=c.getMana();
								l.setVidaAtual(l.getVidaAtual()-((CartaMagia)c).getMagiaDano());
								removerCartas.add(c);
								break;
							}
						}
					}
					else if(((CartaMagia)c).getMagiaTipo()==TipoMagia.AREA){
						//checar se a soma dos lacaios compensa
						int somaManaLacaios=0;
						for(CartaLacaio l:lacaiosOponente){
							somaManaLacaios+=l.getMana();
						}
						if (somaManaLacaios<=c.getMana()) {
							jogada.add(new Jogada(TipoJogada.MAGIA,c,null));
							manaAtual-=c.getMana();
							removerCartas.add(c);
							for(CartaLacaio l:lacaiosOponente){
								l.setVidaAtual(l.getVidaAtual()-((CartaMagia)c).getMagiaDano());
							}
						}
					}
					
				}
		}
		for(int i=0;i<removerCartas.size();i++){
			mao.remove(removerCartas.get(i));
		}
		/*As trocas
são realizadas de maneira parecidas ao do controle*/
		trocarFavoravelmente(jogada);
		if (manaAtual-2>=0) {
			jogada.add(new Jogada(TipoJogada.PODER,null,null));
		}
		//buffar se provou menos efetivo, seja por ataque ou por vida
		return jogada;
	}
	
	
	public ArrayList<CartaLacaio> getLacaiosAtributo(ArrayList<CartaLacaio> lacaios,int tipo){
		//Java não aceita enums dentro de classes não estáticas, logo definindo tipo via int
		//1 = Ataque
		//2 = Mana
		//3 = Vida Atual
		CartaLacaio l;
		//bubblesort pra deixar os de maior atributo no inicio do vetor
		for(int i =0; i<lacaios.size()-1;i++){
			if (tipo ==1) {
				if(lacaios.get(i).getAtaque()<lacaios.get(i+1).getAtaque()){
					l = lacaios.get(i);
					lacaios.set(i, lacaios.get(i+1));
					lacaios.set(i+1, l);
				}
			} else if (tipo==2){
				if(lacaios.get(i).getMana()<lacaios.get(i+1).getMana()){
					l = lacaios.get(i);
					lacaios.set(i, lacaios.get(i+1));
					lacaios.set(i+1, l);
				}
			} else if (tipo==3){
				if(lacaios.get(i).getVidaAtual()<lacaios.get(i+1).getVidaAtual()){
					l = lacaios.get(i);
					lacaios.set(i, lacaios.get(i+1));
					lacaios.set(i+1, l);
				}
			}
		}
		return lacaios;
	}
	
	public void trocarFavoravelmente(ArrayList<Jogada> jogada){
		boolean achouTroca=false;
		for(CartaLacaio meuLacaio:lacaios){
			//checar se ocorre troca favoravel com esse lacaio
		acharTroca: for (CartaLacaio l:lacaiosOponente) {
			//se lacaio ja foi morto em jogada, procura proximo
			if(l.getVidaAtual()<=0){
				continue;
			}
				if ((meuLacaio.getAtaque()>l.getVidaAtual() && meuLacaio.getVidaAtual()>l.getAtaque())||
						(meuLacaio.getAtaque()>=l.getVidaAtual() && meuLacaio.getVidaAtual()<=l.getAtaque() && meuLacaio.getMana()<l.getMana())||
						(meuLacaio.getVidaAtual()<meuLacaio.getVidaMaxima() && meuLacaio.getAtaque()>=l.getVidaAtual()
								&& meuLacaio.getVidaAtual()<=l.getAtaque())) {
					
							jogada.add(new Jogada(TipoJogada.ATAQUE,meuLacaio,l));
							l.setVidaAtual(l.getVidaAtual()-meuLacaio.getAtaque());
							meuLacaio.setVidaAtual(meuLacaio.getVidaAtual()-l.getAtaque());
							achouTroca = true;
							break acharTroca;
					}
				}
			if (!achouTroca) {
				jogada.add(new Jogada(TipoJogada.ATAQUE,meuLacaio,null));
			}
		}
	}
	
	public ArrayList<CartaLacaio> getLacaiosMao(){
		ArrayList<CartaLacaio> lacs = new ArrayList<CartaLacaio>();
		for(Carta c:mao){
			if (c instanceof CartaLacaio) {
				lacs.add((CartaLacaio)c);
			}
		}
		return lacs;
	}
	
	public boolean cartaUsada(Carta carta, ArrayList<Carta> cartasUsadas){
		for(Carta c:cartasUsadas){
			if (c.getID()==carta.getID()) {
				return true;
			}
		}
		return false;
	}
	
	public int buffar(ArrayList<Jogada> jogada,int manaAtual, int tipo ){
		//pegar lacaios da mesa ordenados por atributo
		ArrayList<CartaLacaio> lacs = getLacaiosAtributo(lacaios,tipo);
		ArrayList<Carta> removerCarta = new ArrayList<Carta>();
		for(Carta c:mao){
			if(c instanceof CartaMagia && ((CartaMagia) c).getMagiaTipo()==TipoMagia.BUFF && c.getMana()<=manaAtual){
				for(CartaLacaio l:lacs){
					jogada.add(new Jogada(TipoJogada.MAGIA,c,l));
					l.setAtaque(((CartaMagia) c).getMagiaDano());
					l.setVidaAtual(((CartaMagia) c).getMagiaDano());
					manaAtual-=c.getMana();
					removerCarta.add(c);
					break;
				}
			}
		}
		for(Carta c:removerCarta){
			mao.remove(c);
		}
		return manaAtual;
	}
}
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.EnumSet;
import java.util.HashSet;

public class MotorRA166301 extends Motor {

	public MotorRA166301(Baralho deck1, Baralho deck2, ArrayList<Carta> mao1,
			ArrayList<Carta> mao2, Jogador jogador1, Jogador jogador2,
			int verbose, int tempoLimitado, PrintWriter saidaArquivo, EnumSet<Funcionalidade> funcionalidadesAtivas) {
		super(deck1, deck2, mao1, mao2, jogador1, jogador2, verbose,
				tempoLimitado, saidaArquivo, funcionalidadesAtivas);
		imprimir("========================");
		imprimir("*** Classe "+this.getClass().getName()+" inicializada.");
		imprimir("Funcionalidade ativas no Motor:");
		imprimir("INVESTIDA: "+(this.funcionalidadesAtivas.contains(Funcionalidade.INVESTIDA)?"SIM":"NAO"));
		imprimir("ATAQUE_DUPLO: "+(this.funcionalidadesAtivas.contains(Funcionalidade.ATAQUE_DUPLO)?"SIM":"NAO"));
		imprimir("PROVOCAR: "+(this.funcionalidadesAtivas.contains(Funcionalidade.PROVOCAR)?"SIM":"NAO"));
		imprimir("========================");
	}
	
	private int jogador; // 1 == turno do jogador1, 2 == turno do jogador2.
	private int turno;
	private int nCartasHeroi1;
	private int nCartasHeroi2;
	
	private Mesa mesa;
	
	// "Apontadores" - Assim podemos programar genericamente os m√©todos para funcionar com ambos os jogadores
	private ArrayList<Carta> mao;
	private ArrayList<Carta> lacaios;
	private ArrayList<Carta> lacaiosOponente;
	
	// "Mem√≥ria" - Para marcar a√ß√µes que s√≥ podem ser realizadas uma vez por turno.
	private boolean poderHeroicoUsado;
	private HashSet<Integer> lacaiosAtacaramID;
	private boolean investida, provocar, ataqueDuplo = false;
	HashSet<Integer> naoPodeAtacar;

	@Override
	public int executarPartida() throws LamaException {
		vidaHeroi1 = vidaHeroi2 = 30;
		manaJogador1 = manaJogador2 = 1;
		nCartasHeroi1 = cartasIniJogador1; 
		nCartasHeroi2 = cartasIniJogador2;
		ArrayList<Jogada> movimentos = new ArrayList<Jogada>();
		int noCardDmgCounter1 = 1;
		int noCardDmgCounter2 = 1;
		turno = 1;
		
		if(this.funcionalidadesAtivas.contains(Funcionalidade.INVESTIDA)){
			 investida = true;
		}
		if(this.funcionalidadesAtivas.contains(Funcionalidade.PROVOCAR)){
			 provocar = true;
		}
		if(this.funcionalidadesAtivas.contains(Funcionalidade.ATAQUE_DUPLO)){
			 ataqueDuplo = true;
		}
		
		for(int k = 0; k < 60; k++){
			imprimir("\n=== TURNO "+turno+" ===\n");
			
			//atualiza mana
			if(turno>10)
				manaJogador1 = manaJogador2 = 10;
			else
				manaJogador1 = manaJogador2 = turno;
			
			// Atualiza mesa (com c√≥pia profunda)
			@SuppressWarnings("unchecked")
			ArrayList<CartaLacaio> lacaios1clone = (ArrayList<CartaLacaio>) UnoptimizedDeepCopy.copy(lacaiosMesa1);
			@SuppressWarnings("unchecked")
			ArrayList<CartaLacaio> lacaios2clone = (ArrayList<CartaLacaio>) UnoptimizedDeepCopy.copy(lacaiosMesa2);
			mesa = new Mesa(lacaios1clone, lacaios2clone, vidaHeroi1, vidaHeroi2, nCartasHeroi1+1, nCartasHeroi2, turno>10?10:turno, turno>10?10:(turno==1?2:turno));
			
			// Apontadores para jogador1
			mao = maoJogador1;
			lacaios = lacaiosMesa1;
			lacaiosOponente = lacaiosMesa2;
			jogador = 1;
			
			// Processa o turno 1 do Jogador1
			imprimir("\n----------------------- Come√ßo de turno para Jogador 1:");
			long startTime, endTime, totalTime;
			
			// C√≥pia profunda de jogadas realizadas.
			@SuppressWarnings("unchecked")
			ArrayList<Jogada> cloneMovimentos1 = (ArrayList<Jogada>) UnoptimizedDeepCopy.copy(movimentos);
			
			startTime = System.nanoTime();
			if( baralho1.getCartas().size() > 0){
				if(nCartasHeroi1 >= maxCartasMao){
					movimentos = jogador1.processarTurno(mesa, null, cloneMovimentos1);
					comprarCarta(); // carta descartada
				}
				else
					movimentos = jogador1.processarTurno(mesa, comprarCarta(), cloneMovimentos1);
			}
			else{
				imprimir("Fadiga: O Her√≥i 1 recebeu "+noCardDmgCounter1+" de dano por falta de cartas no baralho. (Vida restante: "+(vidaHeroi1-noCardDmgCounter1)+").");
				vidaHeroi1 -= noCardDmgCounter1++;
				if( vidaHeroi1 <= 0){
					// Jogador 2 venceu
					imprimir("O jogador 2 venceu porque o jogador 1 recebeu um dano mortal por falta de cartas ! (Dano : " +(noCardDmgCounter1-1)+ ", Vida Her√≥i 1: "+vidaHeroi1+")");
					return 2;
				}
				movimentos = jogador1.processarTurno(mesa, null, cloneMovimentos1);
			}
			endTime = System.nanoTime();
			totalTime = endTime - startTime;
			if( tempoLimitado!=0 && totalTime > 3e8){ // 300ms
				// Jogador 2 venceu, Jogador 1 excedeu limite de tempo
				return 2;
			}
			else
				imprimir("Tempo usado em processarTurno(): "+totalTime/1e6+"ms");

			// Come√ßa a processar jogadas do Jogador 1
			this.poderHeroicoUsado = false;
            this.lacaiosAtacaramID = new HashSet<Integer>();
            this.naoPodeAtacar = new HashSet<Integer>();
			for(int i = 0; i < movimentos.size(); i++){
				processarJogada (movimentos.get(i));
			}
			
			if( vidaHeroi2 <= 0){
				// Jogador 1 venceu
				return 1;
			}
			
			// Atualiza mesa (com c√≥pia profunda)
			@SuppressWarnings("unchecked")
			ArrayList<CartaLacaio> lacaios1clone2 = (ArrayList<CartaLacaio>) UnoptimizedDeepCopy.copy(lacaiosMesa1);
			@SuppressWarnings("unchecked")
			ArrayList<CartaLacaio> lacaios2clone2 = (ArrayList<CartaLacaio>) UnoptimizedDeepCopy.copy(lacaiosMesa2);
			mesa = new Mesa(lacaios1clone2, lacaios2clone2, vidaHeroi1, vidaHeroi2, nCartasHeroi1, nCartasHeroi2+1, turno>10?10:turno, turno>10?10:(turno==1?2:turno));
			
			// Apontadores para jogador2
			mao = maoJogador2;
			lacaios = lacaiosMesa2;
			lacaiosOponente = lacaiosMesa1;
			jogador = 2;
			
			// Processa o turno 1 do Jogador2
			imprimir("\n\n----------------------- Come√ßo de turno para Jogador 2:");
			if(turno==1){
				manaJogador2++;
			}
			// C√≥pia profunda de jogadas realizadas.
			@SuppressWarnings("unchecked")
			ArrayList<Jogada> cloneMovimentos2 = (ArrayList<Jogada>) UnoptimizedDeepCopy.copy(movimentos);
			
			startTime = System.nanoTime();

			
			if( baralho2.getCartas().size() > 0){
				if(nCartasHeroi2 >= maxCartasMao){
					movimentos = jogador2.processarTurno(mesa, null, cloneMovimentos2);
					comprarCarta(); // carta descartada
				}
				else
					movimentos = jogador2.processarTurno(mesa, comprarCarta(), cloneMovimentos2);
			}
			else{
				imprimir("Fadiga: O Her√≥i 2 recebeu "+noCardDmgCounter2+" de dano por falta de cartas no baralho. (Vida restante: "+(vidaHeroi2-noCardDmgCounter2)+").");
				vidaHeroi2 -= noCardDmgCounter2++;
				if( vidaHeroi2 <= 0){
					// Vitoria do jogador 1
					imprimir("O jogador 1 venceu porque o jogador 2 recebeu um dano mortal por falta de cartas ! (Dano : " +(noCardDmgCounter2-1)+ ", Vida Her√≥i 2: "+vidaHeroi2 +")");
					return 1;
				}
				movimentos = jogador2.processarTurno(mesa, null, cloneMovimentos2);
			}
			
			endTime = System.nanoTime();
			totalTime = endTime - startTime;
			if( tempoLimitado!=0 && totalTime > 3e8){ // 300ms
				// Limite de tempo pelo jogador 2. Vitoria do jogador 1.
				return 1;
			}
			else
				imprimir("Tempo usado em processarTurno(): "+totalTime/1e6+"ms");
			
			this.poderHeroicoUsado = false;
            this.lacaiosAtacaramID = new HashSet<Integer>();
            this.naoPodeAtacar = new HashSet<Integer>();
			for(int i = 0; i < movimentos.size(); i++){
				processarJogada (movimentos.get(i));
			}
			if( vidaHeroi1 <= 0){
				// Vitoria do jogador 2
				return 2;
			}
			turno++;
		}
		
		// Nunca vai chegar aqui dependendo do n√∫mero de rodadas
		imprimir("Erro: A partida n√£o pode ser determinada em mais de 60 rounds. Provavel BUG.");
		throw new LamaException(-1, null, "Erro desconhecido. Mais de 60 turnos sem termino do jogo.", 0);
	}

	protected void processarJogada(Jogada umaJogada) throws LamaException {
		int cartaID = (umaJogada.getCartaJogada()!=null?umaJogada.getCartaJogada().getID():0);
		String message;
		switch(umaJogada.getTipo()){
		case ATAQUE:
			if( !lacaios.contains(umaJogada.getCartaJogada())){
				message = "ERRO: Lacaio inv·lido para ataque. Lacaio_id="+cartaID;
				imprimir(message);
				throw new LamaException(5, umaJogada, message, jogador==1?2:1);
				//break;
			}
			CartaLacaio lacaioAtacante = (CartaLacaio) lacaios.get(lacaios.indexOf(umaJogada.getCartaJogada()));
			CartaLacaio lacaioAtacado = null;
			
			//verificar se lacaio ja atacou antes
			if(lacaiosAtacaramID.contains(cartaID)){
				//verifica se tem ataque duplo
				if(ataqueDuplo && lacaioAtacante.getEfeito()==TipoEfeito.ATAQUE_DUPLO){
					imprimir("Lacaio "+cartaID+" usou ATAQUE DUPLO!");
					int countAtaques=0;
					for(int id:lacaiosAtacaramID)
						if(id==cartaID)
							countAtaques++;
					if(countAtaques==2){
						message = "ERRO: O lacaio_id="+cartaID+" com Ataque Duplo j· atacou 2 vezes neste turno.";
						imprimir(message);
						throw new LamaException(7, umaJogada, message, jogador==1?2:1);
					}
				} else {
					message = "ERRO: O lacaio_id="+cartaID+" j· atacou neste turno.";
					imprimir(message);
					throw new LamaException(7, umaJogada, message, jogador==1?2:1);
					//break;
				}
			}
			
			//verificar se lacaio acabou de ser baixado / sem investida
			if(naoPodeAtacar.contains(cartaID)){			
				message = "ERRO: O lacaio_id="+cartaID+" nao pode atacar pois acabou de ser baixado ‡ mesa.";
				imprimir(message);
				throw new LamaException(6, umaJogada, message, jogador==1?2:1);
				//break;
			}

			//verificar se lacaio ja morreu 
			if(lacaioAtacante.getVidaAtual()<=0 ){
				message = "ERRO: Lacaio inv·lido para ataque. Lacaio_id="+cartaID;
				imprimir(message);
				throw new LamaException(5, umaJogada, message, jogador==1?2:1);
				//break;
			}
			
			if(provocar){
				//procura se tem algum provocar
				int provocarID=0;
				for(Carta l: lacaiosOponente){
					if(((CartaLacaio) l).getEfeito()==TipoEfeito.PROVOCAR){
						provocarID = l.getID();
					}
				}
				if (provocarID>0){
					imprimir("Lacaio "+provocarID+" usou PROVOCAR!");
				}
				if (provocarID>0 && provocarID!=umaJogada.getCartaAlvo().getID()) {
					message = "ERRO: Tentativa de ataque em lacaio_id="+(umaJogada.getCartaAlvo() != null?umaJogada.getCartaAlvo().getID():" heroi")+" sem Provocar. Lacaio com provocar="+provocarID;
					imprimir(message);
					throw new LamaException(13, umaJogada, message, jogador==1?2:1);
				}
			}
			
			//aplicar danos
			if(umaJogada.getCartaAlvo() != null){ //null = atacou heroi
				if(!lacaiosOponente.contains(umaJogada.getCartaAlvo())){
					message = "ERRO: O lacaio_id= "+cartaID+ " tentou realizar um ataque. O lacaio_id="+umaJogada.getCartaAlvo().getID()+" n„o È um alvo v·lido. ";
					imprimir(message);
					throw new LamaException(8, umaJogada, message, jogador==1?2:1);
				//	break;
				}
				lacaioAtacado = (CartaLacaio) lacaiosOponente.get(lacaiosOponente.indexOf(umaJogada.getCartaAlvo()));
				
				//verificar se alvo È inv·lido
				if(lacaioAtacado.getVidaAtual()<=0){
					message = "ERRO: O lacaio_id= "+cartaID+ " tentou realizar um ataque. O lacaio_id="+lacaioAtacado.getID()+" n„o È um alvo v·lido. ";
					imprimir(message);
					throw new LamaException(8, umaJogada, message, jogador==1?2:1);
				//	break;
				}
				
				imprimir("JOGADA: O lacaio_id="+cartaID+" atacou o lacaio_id="+lacaioAtacado.getID()+" e sofreu "+lacaioAtacado.getAtaque()+" de dano.");
				lacaioAtacante.setVidaAtual(lacaioAtacante.getVidaAtual()-lacaioAtacado.getAtaque());
				processaAtaque(lacaioAtacado, lacaioAtacante.getAtaque());
				
				//verificar se lacaio morre 
				if(lacaioAtacante.getVidaAtual()<=0){
					imprimir("O lacaio_id="+cartaID+" morreu");
					lacaios.remove(lacaioAtacante);
				}
				/*if(!ataqueDuplo)
					lacaiosAtacaramID.add(cartaID);
				else {
					if (lacaioAtacante.getEfeito()!=TipoEfeito.ATAQUE_DUPLO) {
						lacaiosAtacaramID.add(cartaID); // mais de 2 vezes?
					}
				}*/
				lacaiosAtacaramID.add(cartaID);
			} else {
				//reduzir vida do heroi
				if(jogador==1)
					vidaHeroi2-=lacaioAtacante.getAtaque();
				else
					vidaHeroi1-=lacaioAtacante.getAtaque();
				
				imprimir("JOGADA: O lacaio_id="+cartaID+" atacou o herÛi advers·rio.");
				imprimir("O herÛi "+(jogador==1?2:1)+" sofreu "+lacaioAtacante.getAtaque()+" de dano.");
			}		
			break;
		case LACAIO:
			if(!mao.contains(umaJogada.getCartaJogada())){
				String erroMensagem = "Erro: Tentou-se usar a carta_id="+cartaID+", por√©m esta carta n√£o existe na mao. IDs de cartas na mao: ";
				for(Carta card : mao){
					erroMensagem += card.getID() + ", ";
				}
				imprimir(erroMensagem);
				// Dispara uma LamaException passando o c√≥digo do erro, uma mensagem descritiva correspondente e qual jogador deve vencer a partida.
				throw new LamaException(1, umaJogada, erroMensagem, jogador==1?2:1);
			}
			
			Carta lacaioBaixado = mao.get(mao.indexOf(umaJogada.getCartaJogada()));
			
			if(lacaios.size()>=7){ 
				message = "ERRO: Mesa j· contÈm 7 lacaios. Lacaio "+lacaioBaixado.getNome()+" (ID "+cartaID+") n„o pode ser baixado.";
				imprimir(message);
				throw new LamaException(4, umaJogada, message, jogador==1?2:1);
			}
			
			if(lacaioBaixado instanceof CartaMagia){
				message = "ERRO: Jogador tentou baixar carta magia como carta lacaio. Carta "+lacaioBaixado.getNome()+" (ID "+cartaID+") n„o pode ser baixada.";
				imprimir(message);
				throw new LamaException(3, umaJogada, message, jogador==1?2:1);
			}
			
			if(lacaioBaixado.getMana()>(jogador==1?manaJogador1:manaJogador2)){
				message = "ERRO: N„o h· mana disponÌvel. TipoJogada=LACAIO, mana necess·ria="+lacaioBaixado.getMana()+", mana atual ="+(jogador==1?manaJogador1:manaJogador2);
				imprimir(message);
				throw new LamaException(2, umaJogada, message, jogador==1?2:1);
			}
			
			imprimir("JOGADA: O lacaio_id="+cartaID+" foi baixado para a mesa.");
			//imprimir("Vida do lacaio = "+((CartaLacaio)lacaioBaixado).getVidaAtual());
			lacaios.add(lacaioBaixado); // lacaio adicionado √† mesa
			mao.remove(umaJogada.getCartaJogada()); // lacaio retirado da m√£o
			//marcar como recem baixado, checar investida
			if(!investida){
				naoPodeAtacar.add(cartaID);
			} else {
				//checar se carta tem investida
				if(((CartaLacaio) lacaioBaixado).getEfeito() != TipoEfeito.INVESTIDA){
					naoPodeAtacar.add(cartaID);
				} else{
					imprimir("Lacaio "+cartaID+" possui INVESTIDA!");
				}
					
			}
			if(jogador==1)
				manaJogador1-=lacaioBaixado.getMana();
			else {
				manaJogador2-=lacaioBaixado.getMana();
			}
			break;
		case MAGIA:

			if(!mao.contains(umaJogada.getCartaJogada())){
				String erroMensagem = "Erro: Tentou-se usar a carta_id="+cartaID+", por√©m esta carta n√£o existe na mao. IDs de cartas na mao: ";
				for(Carta card : mao){
					erroMensagem += card.getID() + ", ";
				}
				imprimir(erroMensagem);
				// Dispara uma LamaException passando o c√≥digo do erro, uma mensagem descritiva correspondente e qual jogador deve vencer a partida.
				throw new LamaException(1, umaJogada, erroMensagem, jogador==1?2:1);
			}
			Carta cartaMagia = mao.get(mao.indexOf(umaJogada.getCartaJogada()));
			if(cartaMagia instanceof CartaLacaio){
				message = "ERRO: Jogador tentou baixar carta lacaio como carta magia. Carta "+cartaMagia.getNome()+" (ID "+cartaID+") n„o pode ser baixada.";
				imprimir(message);
				throw new LamaException(3, umaJogada, message, jogador==1?2:1);
			}
			if(cartaMagia.getMana()>(jogador==1?manaJogador1:manaJogador2)){
				message = "ERRO: N„o h· mana disponÌvel. TipoJogada=MAGIA, mana necess·ria="+cartaMagia.getMana()+", mana atual ="+(jogador==1?manaJogador1:manaJogador2);
				imprimir(message);
				throw new LamaException(2, umaJogada, message, jogador==1?2:1);
			}

			//verificar tipo
			if (((CartaMagia)cartaMagia).getMagiaTipo()==TipoMagia.ALVO) {
				if(umaJogada.getCartaAlvo()==null){//alvo = heroi
					if(jogador==1)
						vidaHeroi2-=((CartaMagia)cartaMagia).getMagiaDano();
					else
						vidaHeroi1-=((CartaMagia)cartaMagia).getMagiaDano();
					
					imprimir("JOGADA: A magia de area id="+cartaID+" atacou o herÛi advers·rio.");
					imprimir("O herÛi "+jogador+" sofreu "+((CartaMagia)cartaMagia).getMagiaDano()+" de dano.");
				}else {
					if(!lacaiosOponente.contains(umaJogada.getCartaAlvo())){
						message = "ERRO: A magia carta_id= "+cartaID+ " tentou realizar uma ataque. O lacaio_id="+umaJogada.getCartaAlvo().getID()+" n„o È um alvo v·lido";
						imprimir(message);
						throw new LamaException(10, umaJogada, message, jogador==1?2:1);
					}

					lacaioAtacado =  (CartaLacaio) lacaiosOponente.get(lacaiosOponente.indexOf(umaJogada.getCartaAlvo()));

					if(lacaioAtacado.getVidaAtual()<=0){
						message = "ERRO: A magia carta_id= "+cartaID+ " tentou realizar uma ataque. O lacaio_id="+lacaioAtacado.getID()+" n„o È um alvo v·lido";
						imprimir(message);
						throw new LamaException(10, umaJogada, message, jogador==1?2:1);
					}
					
					imprimir("JOGADA: O jogador usou a magia_id="+cartaID+" no lacaio_id="+lacaioAtacado.getID()+".");
					processaAtaque(lacaioAtacado,((CartaMagia)cartaMagia).getMagiaDano());
				}
			} else if (((CartaMagia)cartaMagia).getMagiaTipo()==TipoMagia.AREA){
				//ataca todos os lacaios e heroi
				//for(Carta lacaio : lacaiosOponente){
				int i;
				for( i=0;i<lacaiosOponente.size();i++){
					imprimir("JOGADA: A magia de area id="+cartaID+" atacou o lacaio_id="+lacaiosOponente.get(i).getID()+".");
					processaAtaque((CartaLacaio) lacaiosOponente.get(i), ((CartaMagia)cartaMagia).getMagiaDano());
				}
				
				if(jogador==1)
					vidaHeroi2-=((CartaMagia)cartaMagia).getMagiaDano();
				else
					vidaHeroi1-=((CartaMagia)cartaMagia).getMagiaDano();
				
				imprimir("JOGADA: A magia de area id="+cartaID+" atacou o herÛi advers·rio.");
				imprimir("O herÛi "+jogador+" sofreu "+((CartaMagia)cartaMagia).getMagiaDano()+" de dano.");
				//imprimir("Vida do herÛi "+jogador+" = "+(jogador==1?vidaHeroi1:vidaHeroi2));
				
			} else if  (((CartaMagia)cartaMagia).getMagiaTipo()==TipoMagia.BUFF){
				if(!lacaios.contains(umaJogada.getCartaAlvo())){
					message = "ERRO: A magia carta_id= "+cartaID+ " tentou realizar um buff. O lacaio_id="+(umaJogada.getCartaAlvo()!=null?umaJogada.getCartaAlvo().getID():" heroi")+" n„o È um alvo v·lido";
					imprimir(message);
					throw new LamaException(10, umaJogada, message, jogador==1?2:1);
				}
				lacaioAtacado = (CartaLacaio) lacaios.get(lacaios.indexOf(umaJogada.getCartaAlvo()));
				if(lacaioAtacado.getVidaAtual()<=0){
					message = "ERRO: A magia carta_id= "+cartaID+ " tentou realizar um buff. O lacaio_id="+lacaioAtacado.getID()+" n„o È um alvo v·lido";
					imprimir(message);
					throw new LamaException(10, umaJogada, message, jogador==1?2:1);
				}
				imprimir("Magia de BUFF usada no lacaio_id="+lacaioAtacado.getID());
				imprimir("Novo ataque do lacaio= "+lacaioAtacado.getAtaque()+((CartaMagia)cartaMagia).getMagiaDano());
				imprimir("Nova vida do lacaio= "+lacaioAtacado.getVidaAtual()+((CartaMagia)cartaMagia).getMagiaDano());
				lacaioAtacado.setAtaque(lacaioAtacado.getAtaque()+((CartaMagia)cartaMagia).getMagiaDano());
				lacaioAtacado.setVidaAtual(lacaioAtacado.getVidaAtual()+((CartaMagia)cartaMagia).getMagiaDano());
			}
			mao.remove(cartaMagia);
			if(jogador==1)
				manaJogador1-=cartaMagia.getMana();
			else {
				manaJogador2-=cartaMagia.getMana();
			}
			break;
		case PODER:
			if(poderHeroicoUsado){
				message = "ERRO: Poder heroico ja foi usado neste turno. Alvo id="+(umaJogada.getCartaAlvo()!=null?umaJogada.getCartaAlvo().getID():" heroi");
				imprimir(message);
				throw new LamaException(11, umaJogada, message, jogador==1?2:1);
			}
			if(provocar){
				//procura se tem algum provocar
				int provocarID=0;
				for(Carta l: lacaiosOponente){
					if(((CartaLacaio) l).getEfeito()==TipoEfeito.PROVOCAR){
						provocarID = l.getID();
					}
				}
				if (provocarID>0)
					imprimir("Lacaio "+provocarID+" usou PROVOCAR!");
				if (provocarID>0 && provocarID!=umaJogada.getCartaAlvo().getID()) {
					message = "ERRO: Tentativa de poder heroico em lacaio_id="+(umaJogada.getCartaAlvo() != null?umaJogada.getCartaAlvo().getID():" heroi")+" sem Provocar. Lacaio com provocar="+provocarID;
					imprimir(message);
					throw new LamaException(13, umaJogada, message, jogador==1?2:1);
				}
			}
			
			if(umaJogada.getCartaAlvo() != null){
				if(!lacaiosOponente.contains(umaJogada.getCartaAlvo())){
					message = "ERRO: Jogador tentou usar poder heroico. O lacaio_id="+umaJogada.getCartaAlvo().getID()+" n„o È um alvo v·lido";
					imprimir(message);
					throw new LamaException(12, umaJogada, message, jogador==1?2:1);
				}
				
				lacaioAtacado = (CartaLacaio) lacaiosOponente.get(lacaiosOponente.indexOf(umaJogada.getCartaAlvo()));
				if(lacaioAtacado.getVidaAtual()<=0){
					message = "ERRO: Jogador tentou usar poder heroico. O lacaio_id="+lacaioAtacado.getID()+" n„o È um alvo v·lido";
					imprimir(message);
					throw new LamaException(12, umaJogada, message, jogador==1?2:1);
				}
				
				imprimir("Poder heroico usado no lacaio "+lacaioAtacado.getID());
				processaAtaque(lacaioAtacado, 1);
				
				//heroi recebe o dano do lacaio
				if(jogador==1)
					vidaHeroi1-=lacaioAtacado.getAtaque();
				else
					vidaHeroi2-=lacaioAtacado.getAtaque();
				imprimir("O herÛi recebe "+lacaioAtacado.getAtaque()+" de dano.");
				imprimir("Vida do herÛi "+jogador+" = "+(jogador==1?vidaHeroi1:vidaHeroi2));
				
			} else {
				//atacou o heroi
				imprimir("Poder heroico usado no herÛi "+(jogador==1?2:1));
				if(jogador==1)
					vidaHeroi2-=1;
				else
					vidaHeroi1-=1;
				imprimir("Vida do herÛi "+(jogador==1?2:1)+" = "+(jogador==1?vidaHeroi2:vidaHeroi1));
			}
			
			poderHeroicoUsado = true;
			if(jogador==1)
				manaJogador1-=2;
			else {
				manaJogador2-=2;
			}
			break;
		default:
			break;
		}
		return;
	}
	
	private Carta comprarCarta(){
		if(this.jogador == 1){
			if(baralho1.getCartas().size() <= 0)
				throw new RuntimeException("Erro: N√£o h√° mais cartas no baralho para serem compradas.");
			Carta nova = baralho1.comprarCarta();
			//imprimir("Carta comprada: "+nova.getID());
			mao.add(nova);
			nCartasHeroi1++;
			return (Carta) UnoptimizedDeepCopy.copy(nova);
		}
		else{
			if(baralho2.getCartas().size() <= 0)
				throw new RuntimeException("Erro: N√£o h√° mais cartas no baralho para serem compradas.");
			Carta nova = baralho2.comprarCarta();
			//imprimir("Carta comprada: "+nova.getID());
			mao.add(nova);
			nCartasHeroi2++;
			return (Carta) UnoptimizedDeepCopy.copy(nova);
		}
	}
	
	private void processaAtaque(CartaLacaio lacaioAtacado, int dano) {
		lacaioAtacado.setVidaAtual(lacaioAtacado.getVidaAtual()-dano);
		imprimir("O lacaio adversario de ID="+lacaioAtacado.getID()+" sofreu "+dano+" de dano.");
		if(lacaioAtacado.getVidaAtual()<=0){
			imprimir("O lacaio_id="+lacaioAtacado.getID()+" morreu");
			lacaiosOponente.remove(lacaioAtacado);
		}
	}

}

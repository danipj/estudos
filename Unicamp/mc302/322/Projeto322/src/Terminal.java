import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Terminal {
	
	public static Usuario login(String user, String senha){
		if(user.equals("dani@bus.com")&&senha.equals("123"))
			return new Usuario("Dani",user,senha);
		else if(user.equals("funn@bus.com")&&senha.equals("1234"))
			return new Funcionario("Funcinonario", user, senha);
		System.out.println("Login não efetuado - Verifique suas credenciais");
		return null;
	}
	
	
	public static  void imprimeMenu(Usuario u){
		System.out.println("OPÇÕES:");
		System.out.println("v - Visualizar viagens");
		System.out.println("r - Reservar assento");
		if(u.getClass()==Funcionario.class){
			System.out.println("n - Nova viagem");
			System.out.println("f - Fechar reservas");
			System.out.println("o - Comprar ônibus");
			System.out.println("l - Visualizar lucro");
		}
		System.out.println("q - Sair");
	}
	
	public static void novaViagem(Usuario user, ArrayList<Viagem> viagens, Scanner keyboard) throws InputMismatchException{
		int ano,mes,dia,hora,min,km,dist;
		String origem,destino,tv,sb;
		if(user.getClass()==Funcionario.class){
			System.out.println("Origem:");
			origem = keyboard.next();
			System.out.println("Destino:");
			destino = keyboard.next();
			System.out.println("Distância:");
			dist = keyboard.nextInt();
			System.out.println("Partida:");
			ano = keyboard.nextInt();
			mes = keyboard.nextInt();
			dia = keyboard.nextInt();
			hora = keyboard.nextInt();
			min = keyboard.nextInt();
			System.out.println("Quilometragem:");
			km = keyboard.nextInt();
			System.out.println("Overnight? S ou N");
			String overnight = keyboard.next();
			if(overnight.toUpperCase().charAt(0)=='S'){
				System.out.println("Tem tv? S ou N");
				tv = keyboard.next();
				System.out.println("Tem servico de bordo? S ou N");
				sb = keyboard.next();
				viagens.add(new Viagem(origem,destino,dist,new GregorianCalendar(ano,mes,dia,hora,min),new OnibusOvernight(km, 
						sb.toLowerCase().charAt(0)=='s'?true:false, tv.toLowerCase().charAt(0)=='s'?true:false)));
			}
			else
				viagens.add(new Viagem(origem,destino,dist, new GregorianCalendar(ano,mes,dia,hora,min), new Onibus(km)));
		} else 
			System.out.println("Opção não encontrada, tente de novo");
	}
		
		
	public static boolean initTerminal(Scanner keyboard){
		Usuario user = null;
		int nroViagem;
		String username,senha;
		
		System.out.println("Bem vind@ ao Terminal. Para sair digite SAIR");
		do{
			System.out.println("Digite seu username: ");
			username = keyboard.nextLine();
			if(username.toLowerCase().equals("SAIR"))
				return false;
			System.out.println("Digite sua senha: ");
			senha = keyboard.nextLine();
			user = login(username, senha);
		}while(user==null);
		System.out.println("Bem vind@ "+user.getNome());
		
		ArrayList<Viagem> viagens = new ArrayList<Viagem>();
		viagens = ControlaViagens.criaTestes();
		
		String opcao = "-";
		while(opcao.charAt(0)!='q'&&user!=null){
			imprimeMenu(user);
			opcao = keyboard.next();
			switch (opcao.toLowerCase()) {
			case "n":
				try {
					novaViagem(user,viagens,keyboard);
				} catch (InputMismatchException e) {
					System.out.println(e.getMessage());
				}
				
				break;
			case "r":
				try{
					System.out.println("Viagem desejada:");
					nroViagem = keyboard.nextInt();
					System.out.println("Poltrona desejada:");
					char poltrona = keyboard.next().charAt(0);
					System.out.println("Fileira desejada:");
					int fileira = keyboard.nextInt();
					try {
						if(viagens.get(nroViagem-1).getOnibus().estaVago(poltrona, fileira)){
							viagens.get(nroViagem-1).getOnibus().reservar(poltrona, fileira);
							System.out.println("Reserva efetuada!");
						} else {
							System.out.println("Assento ocupado! Tente outro.");
						}
					} catch (LugarException e) {
						System.out.println(e.getMessage());
					}
				} catch (InputMismatchException e) {
					System.out.println(e.getMessage()!=null?e.getMessage():"Digite números para viagem e fileira e letras para poltrona");
				}
				break;
			case "v":
				ControlaViagens.imprimeViagens(viagens);
				break;
			case "f":
				if(user.getClass()==Funcionario.class){
					System.out.println("Viagem desejada:");
					nroViagem = keyboard.nextInt();
					if (viagens.get(nroViagem-1).getOnibus().estaCheio()) {
						System.out.println("Ônibus partiu cheio.");
					} else {
						System.out.println("Ônibus partiu com "+viagens.get(nroViagem-1).getOnibus().totalVagos()+" lugares vagos.");
					}
					viagens.remove(nroViagem-1);
				} else 
					System.out.println("Opção não encontrada, tente de novo");
				break;
			case "q":
				System.out.println("Obrigada por usar nosso sistema. Volte sempre!");
				user = null;
				break; 
			case "o":
				if(user.getClass()==Funcionario.class){
				
				}
				break;
			case "l":
				if(user.getClass()==Funcionario.class){
					
				}
				break;
			default:
				System.out.println("Opção não encontrada, tente de novo.");
				break;
			}
		}
		return true;
	}
}

import java.util.ArrayList;
import java.util.GregorianCalendar;
import java.util.Scanner;

import javax.net.ssl.SSLException;

public class principal {

	public static void imprimeMenu(){
		System.out.println("OPÇÕES:");
		System.out.println("n - Nova viagem");
		System.out.println("r - Reservar assento");
//		System.out.println("v - Visualizar viagens");
		System.out.println("f - Fechar reservas");
		System.out.println("q - Sair");
	}
	
	public static void imprimeViagens(ArrayList<Onibus> v){
		if(v.size()==0)
			System.out.println("Não existem viagens.");
		else
			for(Onibus o : v){
				System.out.println(o.toString());
			}
	}
	
	
	public static void main(String[] args) {
		ArrayList<Onibus> viagens = new ArrayList<Onibus>();
		String destino = "";
		int ano,mes,dia,hora,min,nroViagem;
		
		//criar onibus
		viagens.add(new Onibus("Limeira", new GregorianCalendar(2017,9,26,18,25)));
		viagens.add(new Onibus("Sumaré", new GregorianCalendar(2017, 9, 26, 23, 00)));
		viagens.add(new OnibusOvernight("Paulínia", new GregorianCalendar(2017, 9, 27, 00, 15)));
		
		Scanner keyboard = new Scanner(System.in);
		
		//loop do programa
		String opcao = "-";
		while(opcao.charAt(0)!='q'){
			imprimeViagens(viagens);
			imprimeMenu();
			opcao = keyboard.next();
			switch (opcao.toLowerCase()) {
			case "n":
				System.out.println("Destino:");
				destino = keyboard.next();
				System.out.println("Partida:");
				ano = keyboard.nextInt();
				mes = keyboard.nextInt();
				dia = keyboard.nextInt();
				hora = keyboard.nextInt();
				min = keyboard.nextInt();
				System.out.println("Overnight? S ou N");
				String overnight = keyboard.next();
				if(overnight.toUpperCase().charAt(0)=='S')
					viagens.add(new OnibusOvernight(destino,new GregorianCalendar(ano,mes,dia,hora,min)));
				else
					viagens.add(new Onibus(destino, new GregorianCalendar(ano,mes,dia,hora,min)));
				break;
			case "r":
				//imprimeViagens(viagens);
				System.out.println("Viagem desejada:");
				nroViagem = keyboard.nextInt();
				System.out.println("Poltrona desejada:");
				char poltrona = keyboard.next().charAt(0);
				System.out.println("Fileira desejada:");
				int fileira = keyboard.nextInt();
				if(viagens.get(nroViagem-1).estaVago(poltrona, fileira)){
					viagens.get(nroViagem-1).reservar(poltrona, fileira);
					System.out.println("Reserva efetuada!");
				} else {
					System.out.println("Assento ocupado! Tente outro.");
				}
				break;
	/*		case "v":
				imprimeViagens(viagens);
				break;*/
			case "f":
				System.out.println("Viagem desejada:");
				nroViagem = keyboard.nextInt();
				if (viagens.get(nroViagem-1).estaCheio()) {
					System.out.println("Ônibus partiu cheio.");
				} else {
					System.out.println("Ônibus partiu com "+viagens.get(nroViagem-1).totalVagos()+" lugares vagos.");
				}
				viagens.remove(nroViagem-1);
				break;
			case "q":
				break; // só sai
			default:
				System.out.println("Opção não encontrada, tente de novo.");
				break;
			}
		}
		keyboard.close();
	}

}

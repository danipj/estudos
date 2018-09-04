import java.util.ArrayList;
import java.util.GregorianCalendar;

public class ControlaViagens {
	public static ArrayList<Viagem> criaTestes() {
		ArrayList<Viagem> viagens = new ArrayList<Viagem>();
		viagens.add(new Viagem("Campinas","Limeira",80, new GregorianCalendar(2017,9,26,18,25), new Onibus(12)));
		viagens.add(new Viagem("Campinas","Sumaré",40, new GregorianCalendar(2017, 9, 26, 23, 00), new Onibus(10)));
		viagens.add(new Viagem("Campinas","Paulínia",20, new GregorianCalendar(2017, 9, 27, 00, 15), new OnibusOvernight(8, false,true)));
		return viagens;
	}
	
	public static  void imprimeViagens(ArrayList<Viagem> v){
		if(v.size()==0)
			System.out.println("Não existem viagens.");
		else
			for(Viagem o : v){
				System.out.println(o.toString());
			}
	}
}

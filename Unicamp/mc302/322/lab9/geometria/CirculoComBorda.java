

public class CirculoComBorda extends Circulo{
	int espessura;
	
	public int obterEspessuraBorda(){
		return espessura;
	}
	public void alterarEspessuraBorda(int e){
		espessura=e;
	}
	public void mostra(){
		super.mostra();
	}
	
	public static void main(String args[]) {
		 Circulo circ = new Circulo(1, 1, 1);
		 circ.mostra();
	}
}

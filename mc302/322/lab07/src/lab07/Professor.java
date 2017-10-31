package lab07;

public class Professor extends Usuario{
	public Professor() {
		super();
		// TODO Auto-generated constructor stub
	}

	public void bloquear(Exemplar e){
		e.setBloqueado(true);
	}
	
	public void desbloquear(Exemplar e){
		e.setBloqueado(false);
	}
}

package lab07;

import java.util.Date;
import java.util.GregorianCalendar;

public class Usuario {
	
	private Exemplar exemplarEmprestado;
	private Date dataEmprestimo;

	public void emprestar(Exemplar e){
		this.exemplarEmprestado = e;
		this.dataEmprestimo = new GregorianCalendar().getTime();
		e.emprestar();
	}
	
	public void devolver(Exemplar e){
		this.exemplarEmprestado = null;
		this.dataEmprestimo = null;
	}

	public Usuario() {
		super();
	}

	public Exemplar getExemplarEmprestado() {
		return exemplarEmprestado;
	}

	public void setExemplarEmprestado(Exemplar exemplarEmprestado) {
		this.exemplarEmprestado = exemplarEmprestado;
	}

	public Date getDataEmprestimo() {
		return dataEmprestimo;
	}

	public void setDataEmprestimo(Date dataEmprestimo) {
		this.dataEmprestimo = dataEmprestimo;
	}
}

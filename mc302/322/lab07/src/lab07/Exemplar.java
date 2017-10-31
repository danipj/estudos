package lab07;

import java.sql.Date;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Exemplar {
	private boolean emprestado;
	private boolean bloqueado;
	private Date dataDevolucao;
	private int tempoEmprestimo;
	
	public Date getDataDevolucao() {
		return dataDevolucao;
	}

	public void setDataDevolucao(Date dataDevolucao) {
		this.dataDevolucao = dataDevolucao;
	}

	public boolean isEmprestado() {
		return emprestado;
	}

	public void setEmprestado(boolean emprestado) {
		this.emprestado = emprestado;
	}

	public boolean isBloqueado() {
		return bloqueado;
	}

	public void setBloqueado(boolean bloqueado) {
		this.bloqueado = bloqueado;
	}

	public void emprestar() {
		this.emprestado = true;
		Calendar c = Calendar.getInstance(); 
		c.setTime(new GregorianCalendar().getTime()); 
		c.add(Calendar.DATE, tempoEmprestimo);
		this.dataDevolucao = (Date) c.getTime();
	}

	public Exemplar(boolean emprestado, boolean bloqueado, Date dataDevolucao, int tempoEmprestimo) {
		super();
		this.emprestado = emprestado;
		this.bloqueado = bloqueado;
		this.dataDevolucao = dataDevolucao;
		this.tempoEmprestimo= tempoEmprestimo;
	}

}

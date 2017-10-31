package lab07;

import java.sql.Date;

public class Livro extends Exemplar{

	public Livro(boolean emprestado, boolean bloqueado, Date dataDevolucao) {
		super(emprestado, bloqueado, dataDevolucao, 3);
	}

}

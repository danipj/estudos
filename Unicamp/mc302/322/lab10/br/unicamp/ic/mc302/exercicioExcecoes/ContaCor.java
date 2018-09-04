package br.unicamp.ic.mc302.exercicioExcecoes;

public class ContaCor {
	private int estado; // 1=conta ativa 2=conta inativa
	private int senha;
	private int numConta;
	private String titular;
	private float saldoAtual;

	public static final int ATIVADA = 1;
	public static final int DESATIVADA = 2;

	public void creditaValor(float val) throws ContaCorExc {
		if (estado != ATIVADA)
			throw new ContaCorExc(ContaCorExc.CREDITA_VALOR, ContaCorExc.CONTA_INATIVA, this);
		if (val <= 0)
			throw new ContaCorExc(ContaCorExc.CREDITA_VALOR, ContaCorExc.VALOR_INVALIDO, this);
		saldoAtual += val; // credita valor
	} // fim creditaValor()

	public void debitaValor(float val, int pwd) throws ContaCorExc {
		if (estado != ATIVADA)
			throw new ContaCorExc(ContaCorExc.DEBITA_VALOR, ContaCorExc.CONTA_INATIVA, this);
		if (val <= 0)
			throw new ContaCorExc(ContaCorExc.DEBITA_VALOR, ContaCorExc.VALOR_INVALIDO, this);
		if (pwd != senha)
			throw new ContaCorExc(ContaCorExc.DEBITA_VALOR, ContaCorExc.SENHA_INVALIDA, this);
		if (val > saldoAtual)
			throw new ContaCorExc(ContaCorExc.DEBITA_VALOR, ContaCorExc.SALDO_INSUFICIENTE, this);
		saldoAtual -= val; // debita valor
		if (saldoAtual == 0) // se saldo=0, torne a conta inativa
			estado = DESATIVADA;
	}// fim debitaValor()

	public float getSaldo(int pwd) throws ContaCorExc {
		if (estado != ATIVADA)
			throw new ContaCorExc(ContaCorExc.GET_SALDO, ContaCorExc.CONTA_INATIVA, this);
		if (pwd != senha)
			throw new ContaCorExc(ContaCorExc.GET_SALDO, ContaCorExc.SENHA_INVALIDA, this);
		return (saldoAtual);
	}// fim getSaldo()

	public ContaCor(String nome, float val, int num, int pwd) {
		titular = nome;
		numConta = num;
		senha = pwd;
		saldoAtual = val;
		estado = ATIVADA; // conta é ativada quando criada
	}// fim do método construtor ContaCor()

	public void mostraInformacoes(int pwd) throws ContaCorExc {
		String est = "Ativada.";
		if (this.estado == DESATIVADA) {
			est = "Desativada.";
		}
		float saldo = getSaldo(pwd);

		System.out.println("Conta numero: " + numConta);
		System.out.println("Estado: " + est);
		System.out.println("Titular: " + titular);
		System.out.println("Saldo: " + saldo);
	}

}// fim da classe ContaCor


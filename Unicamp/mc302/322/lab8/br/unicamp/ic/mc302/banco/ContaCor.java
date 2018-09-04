package br.unicamp.ic.mc302.banco;

public class ContaCor {
	private int estado; // 1=conta ativa 2=conta inativa
	private int senha;
	private int numConta;
	private String titular;
	private double saldoAtual;

	public int getNumConta() {
		return this.numConta;
	}

	public boolean creditaValor(double val) {
		if (estado != 1) return (false); // conta deve estar ativa
		if (val <= 0) return (false);// val>0;
		saldoAtual += val; // credita valor
		return (true); // operação terminada com sucesso
	} // fim creditaValor()

	public boolean debitaValor(double val, int pwd) {
		if (estado != 1) return (false); // conta deve estar ativa
		if (val < 0) return (false); // val>0;
		if (pwd != senha) return (false);// senha deve ser válida
		if (val > saldoAtual) return (false); // val<=saldoAtual
		saldoAtual -= val; // debita valor
		if (saldoAtual == 0) // se saldo=0, torne a conta inativa
			estado = 2;
		return (true);
	}// fim debitaValor()

	public double getSaldo(int pwd) {
		if (estado != 1) return (-1);// conta deve estar ativa
		if (pwd != senha) return (-1);// senha deve ser válida
		return (saldoAtual);
	}// fim getSaldo()

	public ContaCor(String nome, double val, int num, int pwd) {
		titular = nome;
		numConta = num;
		senha = pwd;
		saldoAtual = val;
		estado = 1; // conta é ativada quando criada
	}// fim do método construtor ContaCor()
}// fim da classe ContaCor


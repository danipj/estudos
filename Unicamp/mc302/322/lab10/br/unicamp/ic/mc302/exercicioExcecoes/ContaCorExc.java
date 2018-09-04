package br.unicamp.ic.mc302.exercicioExcecoes;

public class ContaCorExc extends Exception {

	private int operacao; // operação que criou a exceção
	public int erro; // tipo de erro
	private ContaCor conta;

	// nome das operações
	public final static int CREDITA_VALOR = 1;
	public final static int DEBITA_VALOR = 2;
	public final static int GET_SALDO = 3;

	// dados da operação
	public final static int VALOR_INVALIDO = 1;
	public final static int CONTA_INATIVA = 2;
	public final static int SALDO_INSUFICIENTE = 3;
	public final static int SENHA_INVALIDA = 4;

	public ContaCorExc(int op, int er, ContaCor cc) {
		operacao = op;
		erro = er;
		conta = cc;
	} // fim do construtor

	public int getOperacao() {
		return operacao;
	}

	public int getErro() {
		return erro;
	}
} // fim da classe ContaCorException

package br.unicamp.ic.mc302.banco;

public interface IRepositorioContas {

	public boolean inserir(ContaCor cc);

	public boolean remover(int num);

	public ContaCor procurar(int num);

	public boolean atualizar(ContaCor cc);
}
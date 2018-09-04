package br.unicamp.ic.mc302.oficina;

public class Funcionario {
	private int salario;
	private float comissao;
	private int total1;
	private int total2;
	private int total3;

	public Funcionario(int salario, float comissao, int t1, int t2,int t3) {
		this.salario = salario;
		this.comissao = comissao;
		total1=t1;
		total2=t2;
		total3=t3;
	}
	
	

	public int getSalario() {
		return salario;
	}



	public void setSalario(int salario) {
		this.salario = salario;
	}



	public float getComissao() {
		return comissao;
	}



	public void setComissao(float comissao) {
		this.comissao = comissao;
	}



	public int getTotal1() {
		return total1;
	}



	public void setTotal1(int total1) {
		this.total1 = total1;
	}



	public int getTotal2() {
		return total2;
	}



	public void setTotal2(int total2) {
		this.total2 = total2;
	}



	public int getTotal3() {
		return total3;
	}



	public void setTotal3(int total3) {
		this.total3 = total3;
	}



	public String toString() {
		return "Funcionario [salario=" + salario + ", comissao=" + comissao + ", total1=" + total1 + ", total2="
				+ total2 + ", total3=" + total3 + "]";
	}

}

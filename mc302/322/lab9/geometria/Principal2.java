


public class Principal2 {

  public static void main (String args[]){
  Circulo acirc;
  //acirc.x=(float)10.0; Erro!! atributo encapsulado(modo package)
  Ponto apto;
  acirc= new Circulo((float)0.0,(float)0.0,(float)1.0);
  acirc.mostra();
  apto=new Ponto((float)4.0,(float)3.0);
  apto.mostra();
  System.out.println("Distância:"+acirc.distancia(apto));


  }
}

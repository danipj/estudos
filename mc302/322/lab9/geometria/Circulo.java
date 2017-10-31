


public class Circulo {
  float raio,x,y;
  
  public Circulo() {
	this.x=0; this.y=0; this.raio=0;
  }
  
  public Circulo(float ax, float ay, float ar) {
    this.x=ax; this.y=ay; this.raio=ar;
  }

  public void altera_raio(float a){
   this.raio=a;
  }

  public float retorna_raio(){
  return this.raio;
  }


  public void move(float dx, float dy){
  this.x+=dx; this.y+=dy;
  }

  public float distancia(Ponto ap){
  float dcp; // dist. do centro do círculo ao ponto
  dcp=(float)Math.sqrt((double) ((x-ap.x)*(x-ap.x)+(y-ap.y)*(y-ap.y)));
  // acesso direto aos atributos de ap, pois as classes pertencem ao
  // mesmo package
  if (dcp<raio){
    return dcp-raio;
  }
  else{
    return dcp-raio;
  }
  }
  protected void mostra(){
   System.out.println("("+this.x+","+this.y+","+this.raio+")");
   }
 }







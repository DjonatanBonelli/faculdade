
package oop1;

    public class Radio {
        private int volume;
        private boolean ligado;
        private int faixa;

    public Radio(int volume, boolean ligado, int faixa) {
        this.volume = volume;
        this.ligado = ligado;
        this.faixa = faixa;
    }   
        
    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public boolean isLigado() {
        return ligado;
    }

    public void setLigado(boolean ligado) {
        this.ligado = ligado;
    }

    public int getFaixa() {
        return faixa;
    }

    public void setFaixa(int faixa) {
        this.faixa = faixa;
    }
               
        
    public void aumentar_volume(){
        if(volume < 100 && ligado == true){
            this.volume += 5;
        }
        if(ligado == false){
            System.out.println("Primeiro ligue o radio!");
        }
        if(volume >= 100){
            System.out.println("Volume maximo!");
        }
    }
    
    public void diminuir_volume(){
        if(volume > 0 && ligado == true){
            this.volume -= 5;
        }
        if(ligado == false){
            System.out.println("Primeiro ligue o radio!");
        }
        if(volume <= 0){
            System.out.println("Volume minimo!");
        }    
    }
    
    public void ligar_radio(){
        if(ligado == false){
            this.ligado = true;
        }
        else{
            System.out.println("O radio ja esta ligado!");
        }       
    }
    
    public void desligar_radio(){
        if(ligado == true){
            this.ligado = true;
        }
        else{
            System.out.println("O radio ja esta desligado!");
        }            
    }
    
    public void passar_faixa(){
        if(faixa < 50 && ligado == true){
            this.faixa += 1;
        }
        if (ligado == false){
            System.out.println("Primeiro ligue o radio!");
        }
        if(faixa >= 50){
            System.out.println("Ultima faixa da lista!");
        }
    }
    
    public void voltar_faixa(){
        if(faixa > 0 && ligado == true){
            this.faixa -= 1;
        }
        if (ligado == false){
            System.out.println("Primeiro ligue o radio!");
        }
        if(faixa <= 0){
            System.out.println("Primeira faixa da lista!");
        }
    }
}

package oop1;

public class OOP1 {

    public static void main(String[] args) {
        
        Radio radio = new Radio(0, false, 1);
        
        radio.ligar_radio();
        radio.aumentar_volume();
        
        System.out.printf("Volume: "+radio.getVolume()+"%nLigado: "+radio.isLigado()+"%nFaixa: "+radio.getFaixa()+"%n");
       
    }
    
}

#include <Servo.h>
//#include <Hexapod.h>

Servo pata_dir[3];
Servo pata_esq[3];
Servo rotula_dir[3];
Servo rotula_esq[3];
Servo coxa_dir[3];
Servo coxa_esq[3];

int home_pata_dir   = 30;
int home_pata_esq   = 150;
int home_rotula_dir = 45;
int home_rotula_esq = 135;
int home_coxa_dir   = 90;
int home_coxa_esq   = 90;

void setup(){
  
  pata_dir[0].attach(13);
  pata_dir[1].attach(10);
  pata_dir[2].attach(7);
  pata_esq[0].attach(4);
  pata_esq[1].attach(44);
  pata_esq[2].attach(49);  

  rotula_dir[0].attach(12);
  rotula_dir[1].attach(8);
  rotula_dir[2].attach(6);
  rotula_esq[0].attach(2);
  rotula_esq[1].attach(46);
  rotula_esq[2].attach(47);

  coxa_dir[0].attach(11);
  coxa_dir[1].attach(9);
  coxa_dir[2].attach(5);
  coxa_esq[0].attach(3);
  coxa_esq[1].attach(48);
  coxa_esq[2].attach(45);

  setCoxas(90);
  setRotulas(90);
  setPatas(90);

  //encolher();
  //levantar();

  // pinMode(47, OUTPUT);

}

void loop(){

  home();

  // setCoxas(90);
  // setRotulas(90);
  // setPatas(90);

  // pata_dir[0].write(125);  // OK
  // pata_dir[1].write(125);  // OK
  // pata_dir[2].write(125);  // OK
  // pata_esq[0].write(55);   // OK  
  // pata_esq[1].write(55);   // OK
  // pata_esq[2].write(55);   // OK

  // rotula_dir[0].write(125);  // OK
  // rotula_dir[1].write(125);  // OK
  // rotula_dir[2].write(125);  // OK
  // rotula_esq[0].write(125);  // OK
  // rotula_esq[1].write(125);  // OK

  // rotula_esq[2].write(55);  // NOK
  // delay(500);
  // rotula_esq[2].write(125); 
  // delay(500);

  // coxa_dir[0].write(60);   // OK
  // coxa_dir[1].write(60);   // OK
  // coxa_dir[2].write(60);   // OK
  // coxa_esq[0].write(125);  // OK   
  // coxa_esq[1].write(125);  // OK  
  // coxa_esq[2].write(125);  // OK  

  // testeCoxas();

  // andarParaFrente();

  // pata_dir[1].write(90);
  // pata_dir[2].write(90);
  // pata_esq[0].write(90);
  // pata_esq[1].write(90);
  // pata_esq[2].write(90);

  // rotula_dir[0].write(90);
  // rotula_dir[1].write(90);
  // rotula_dir[2].write(90);
  // rotula_esq[0].write(90);
  // rotula_esq[1].write(90);
  // rotula_esq[2].write(90);
  
  // coxa_dir[0].write(90);
  // coxa_dir[1].write(90);
  // coxa_dir[2].write(90);
  // coxa_esq[0].write(90);
  // coxa_esq[1].write(90);
  // coxa_esq[2].write(90);

  // current_pata_esq[0]   = 80;
  // current_pata_esq[1]   = 75;
  // current_pata_esq[2]   = 80;
  // current_rotula_esq[0] = 85;
  // current_rotula_esq[1] = 88;
  // current_rotula_esq[2] = 80;

  // for(int i = 0; i < 3; i++){

    // pata_dir[i].write(current_pata_dir[i]);
    // pata_esq[i].write(current_pata_esq[i]);
    // rotula_dir[i].write(current_rotula_dir[i]);
    // rotula_esq[i].write(current_rotula_esq[i]);
    // coxa_dir[i].write(current_coxa_dir[i]);
    // coxa_esq[i].write(current_coxa_esq[i]);

  // }

  // setCoxas(90);
  // setRotulas(90);
  // setPatas(90);

  /*  
  **  Examplo:
  ** 
  **    coxa 1 da direita move 30 graus para cima
  **    mexer(0, 1, 1, 30, 0)
  **
  **  membro:       0 - coxa, 1 - rotula ou 2 - pata
  **
  **  pos_membro:   0, 1 ou 2
  **
  **  dir_esq:      0 - direita ou 1 - esquerda
  **
  **  cima_baixo :  0 - cima ou 1 - baixo
  **
  */

  // current_pata_esq[0]   = 80;
  // current_pata_esq[1]   = 75;
  // current_pata_esq[2]   = 80;
  // current_rotula_esq[0] = 85;
  // current_rotula_esq[1] = 88;
  // current_rotula_esq[2] = 80;

  //setPatas(135);
  // setPatas(45);

  //andarParaFrente();

  // andarParaDireita();

  // andarParaEsquerda();

  //setPatas(90);

  // virarParaDireita();

  // virarParaEsquerda();

  //delay(3000);
  
  
  //testeRotulas();
  //testeCoxas();
  //testePatas();

  // encolher();

  // delay(6000);

  // setPatas(90);
  // delay(500);

  // setRotulas(90);
  // delay(500);

  // setCoxas(90);
  // delay(500);

  // setCoxas(90);
  // delay(500);

  // setCoxas(120);
  // delay(500);

  // setCoxas(90);
  // delay(500);

}

void home(){

  for(int i = 0; i < 3; i++){

    pata_dir[i].write(home_pata_dir);
    pata_esq[i].write(home_pata_esq);
    rotula_dir[i].write(home_rotula_dir);
    rotula_esq[i].write(home_rotula_esq);
    coxa_dir[i].write(home_coxa_dir);
    coxa_esq[i].write(home_coxa_esq);

  }

}

void encolher(){

  //Levanta rotulas
  for(int i = 0; i < 4500; i++){

      rotula_dir[0].write(90 - 0.015*i);
      rotula_dir[1].write(90 - 0.015*i);
      rotula_dir[2].write(90 - 0.015*i);
      rotula_esq[0].write(90 + 0.015*i);
      rotula_esq[1].write(90 + 0.015*i);
      rotula_esq[2].write(90 + 0.015*i);

  }   

  //Levantar patas
  for(int i = 0; i < 2000; i++){

        pata_dir[0].write(90 - 0.015*i);
        pata_dir[1].write(90 - 0.015*i);
        pata_dir[2].write(90 - 0.015*i);
        pata_esq[0].write(90 + 0.015*i);
        pata_esq[1].write(90 + 0.015*i);
        pata_esq[2].write(90 + 0.015*i);
  }

  //Baixar patas
  for(int i = 0; i < 1500; i++){

        pata_dir[0].write(60 - 0.015*i);
        pata_dir[1].write(60 - 0.015*i);
        pata_dir[2].write(60 - 0.015*i);
        pata_esq[0].write(120 + 0.015*i);
        pata_esq[1].write(120 + 0.015*i);
        pata_esq[2].write(120 + 0.015*i);
  }
}

void agachar(){

  //Levanta rotula
  for(int i = 0; i < 4500; i++){

      rotula_dir[0].write(90 - 0.01*i);
      rotula_dir[1].write(90 - 0.01*i);
      rotula_dir[2].write(90 - 0.01*i);
      rotula_esq[0].write(90 + 0.01*i);
      rotula_esq[1].write(90 + 0.01*i);
      rotula_esq[2].write(90 + 0.01*i);

      delay(4500/1000);

  }

  // Pata pra dentro
  for(int i = 0; i < 9000; i++){

      pata_dir[0].write(90 - 0.01*i);
      pata_dir[1].write(90 - 0.01*i);
      pata_dir[2].write(90 - 0.01*i);
      pata_esq[0].write(90 + 0.01*i);
      pata_esq[1].write(90 + 0.01*i);
      pata_esq[2].write(90 + 0.01*i);

  }

  //Baixa rotula
  for(int i = 0; i < 1500; i++){

      rotula_dir[0].write(45 + 0.01*i);
      rotula_dir[1].write(45 + 0.01*i);
      rotula_dir[2].write(45 + 0.01*i);
      rotula_esq[0].write(135 - 0.01*i);
      rotula_esq[1].write(135 - 0.01*i);
      rotula_esq[2].write(135 - 0.01*i);

  }

  //Baixa rotula
  for(int i = 0; i < 4500; i++){

      rotula_dir[0].write(60 - 0.01*i);
      rotula_dir[1].write(60 - 0.01*i);
      rotula_dir[2].write(60 - 0.01*i);
      rotula_esq[0].write(120 + 0.01*i);
      rotula_esq[1].write(120 + 0.01*i);
      rotula_esq[2].write(120 + 0.01*i);

  }

}

void levantar(){

  // Levantar
  for(int i = 0; i < 4500; i++){

      rotula_dir[0].write(45 + 0.01*i);
      rotula_dir[1].write(45 + 0.01*i);
      rotula_dir[2].write(45 + 0.01*i);
      rotula_esq[0].write(135 - 0.01*i);
      rotula_esq[1].write(135 - 0.01*i);
      rotula_esq[2].write(135 - 0.01*i);

      delayMicroseconds(1000000/11250);

  }

  // Ajeitar patas

  rotula_esq[0].write(135);
  rotula_dir[0].write(45);
  delay(500);
  pata_esq[0].write(90);
  pata_dir[0].write(90);
  delay(500);
  rotula_esq[0].write(90);
  rotula_dir[0].write(90);

  // rotula_dir[0].write(45);
  // delay(500);
  // pata_dir[0].write(90);
  // delay(500);
  // rotula_dir[0].write(90);

  rotula_esq[1].write(135);
  delay(500);
  pata_esq[1].write(90);
  delay(500);
  rotula_esq[1].write(90);

  rotula_dir[1].write(45);
  delay(500);
  pata_dir[1].write(90);
  delay(500);
  rotula_dir[1].write(90);

  rotula_esq[2].write(135);
  delay(500);
  pata_esq[2].write(90);
  delay(500);
  rotula_esq[2].write(90);

  rotula_dir[2].write(45);
  delay(500);
  pata_dir[2].write(90);
  delay(500);
  rotula_dir[2].write(90);

  // Ajeitar patas

  rotula_esq[0].write(135);
  delay(500);
  pata_esq[0].write(90);
  delay(500);
  rotula_esq[0].write(90);

  rotula_dir[0].write(45);
  delay(500);
  pata_dir[0].write(90);
  delay(500);
  rotula_dir[0].write(90);

  rotula_esq[1].write(135);
  delay(500);
  pata_esq[1].write(90);
  delay(500);
  rotula_esq[1].write(90);

  rotula_dir[1].write(45);
  delay(500);
  pata_dir[1].write(90);
  delay(500);
  rotula_dir[1].write(90);

  rotula_esq[2].write(135);
  delay(500);
  pata_esq[2].write(90);
  delay(500);
  rotula_esq[2].write(90);

  rotula_dir[2].write(45);
  delay(500);
  pata_dir[2].write(90);
  delay(500);
  rotula_dir[2].write(90);

 
}

void andarParaFrente(){

  for(int j = 1; j < 9; j=j*2)
  {

    for(int k = 0; k < 3; k++){

      // Erguer grupo 1
      for(int i = 0; i < 3000; i = i + 1*j){

          rotula_dir[0].write(90 - 0.01*i);
          rotula_dir[2].write(90 - 0.01*i);
          rotula_esq[1].write(90 + 0.01*i);

      }

      // Avançar grupo 1
      for(int i = 0; i < 3000; i = i + 1*j){

          coxa_dir[0].write(90 - 0.01*i);
          coxa_dir[2].write(90 - 0.01*i);
          coxa_esq[1].write(90 + 0.01*i);

      }

      // Baixar grupo 1
      for(int i = 0; i < 3000; i = i + 1*j){

          rotula_dir[0].write(60 + 0.01*i);
          rotula_dir[2].write(60 + 0.01*i);
          rotula_esq[1].write(120 - 0.01*i);

      }

      // Erguer grupo 2
      for(int i = 0; i < 3000; i = i + 1*j){

          rotula_esq[0].write(90 + 0.01*i);
          rotula_esq[2].write(90 + 0.01*i);
          rotula_dir[1].write(90 - 0.01*i);

      }

      // Avançar grupo 2
      for(int i = 0; i < 3000; i = i + 1*j){

          coxa_esq[0].write(90 + 0.01*i);
          coxa_esq[2].write(90 + 0.01*i);
          coxa_dir[1].write(90 - 0.01*i);

      }

      // Baixar grupo 2
      for(int i = 0; i < 3000; i = i + 1*j){

          rotula_esq[0].write(120 - 0.01*i);
          rotula_esq[2].write(120 - 0.01*i);
          rotula_dir[1].write(60 + 0.01*i);

      }

      // Avançar todos
      for(int i = 0; i < 3000; i = i + 1*j){

          coxa_dir[0].write(60 + 0.01*i);
          coxa_dir[1].write(60 + 0.01*i);
          coxa_dir[2].write(60 + 0.01*i);
          coxa_esq[0].write(120 - 0.01*i);
          coxa_esq[1].write(120 - 0.01*i);
          coxa_esq[2].write(120 - 0.01*i);

      }

    }

  }

}

void andarParaDireita(){

  // Erguer grupo 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(90 - 0.01*i);
      rotula_dir[2].write(90 - 0.01*i);
      rotula_esq[1].write(90 + 0.01*i);

  }

  // Movimentar grupo 1 para direita
  for(int i = 0; i < 4500; i++){

      pata_dir[0].write(90 + 0.01*i);
      pata_dir[2].write(90 + 0.01*i);
      pata_esq[1].write(90 + 0.01*i);

  }

  // Baixar grupo 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(60 + 0.01*i);
      rotula_dir[2].write(60 + 0.01*i);
      rotula_esq[1].write(120 - 0.01*i);

  }

  // Erguer grupo 2
  for(int i = 0; i < 3000; i++){

      rotula_esq[0].write(90 + 0.01*i);
      rotula_esq[2].write(90 + 0.01*i);
      rotula_dir[1].write(90 - 0.01*i);

  }

  // Movimentar grupo 2 para direita
  for(int i = 0; i < 4500; i++){

      pata_esq[0].write(90 + 0.01*i);
      pata_esq[2].write(90 + 0.01*i);
      pata_dir[1].write(90 + 0.01*i);

  }

  // Baixar grupo 2
  for(int i = 0; i < 3000; i++){

      rotula_esq[0].write(120 - 0.01*i);
      rotula_esq[2].write(120 - 0.01*i);
      rotula_dir[1].write(60 + 0.01*i);

  }

  // Puxar corpo
  pata_dir[0].write(90);
  pata_dir[1].write(90);
  pata_dir[2].write(90);
  pata_esq[0].write(90);
  pata_esq[1].write(90);
  pata_esq[2].write(90);

}

void andarParaEsquerda(){

  // Erguer grupo 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(90 - 0.01*i);
      rotula_dir[2].write(90 - 0.01*i);
      rotula_esq[1].write(90 + 0.01*i);

  }

  // Movimentar grupo 1 para direita
  for(int i = 0; i < 4500; i++){

      pata_dir[0].write(90 - 0.01*i);
      pata_dir[2].write(90 - 0.01*i);
      pata_esq[1].write(90 - 0.01*i);

  }

  // Baixar grupo 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(60 + 0.01*i);
      rotula_dir[2].write(60 + 0.01*i);
      rotula_esq[1].write(120 - 0.01*i);

  }

  // Erguer grupo 2
  for(int i = 0; i < 3000; i++){

      rotula_esq[0].write(90 + 0.01*i);
      rotula_esq[2].write(90 + 0.01*i);
      rotula_dir[1].write(90 - 0.01*i);

  }

  // Movimentar grupo 2 para direita
  for(int i = 0; i < 4500; i++){

      pata_esq[0].write(90 - 0.01*i);
      pata_esq[2].write(90 - 0.01*i);
      pata_dir[1].write(90 - 0.01*i);

  }

  // Baixar grupo 2
  for(int i = 0; i < 3000; i++){

      rotula_esq[0].write(120 - 0.01*i);
      rotula_esq[2].write(120 - 0.01*i);
      rotula_dir[1].write(60 + 0.01*i);

  }

  // Puxar corpo
  pata_dir[0].write(90);
  pata_dir[1].write(90);
  pata_dir[2].write(90);
  pata_esq[0].write(90);
  pata_esq[1].write(90);
  pata_esq[2].write(90);

}

void virarParaDireita(){

  // Erguer grupo 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(90 - 0.01*i);
      rotula_dir[2].write(90 - 0.01*i);
      rotula_esq[1].write(90 + 0.01*i);

  }

  // Vira grupo 1
  for(int i = 0; i < 3000; i++){

      coxa_dir[0].write(90 + 0.01*i);
      coxa_dir[2].write(90 + 0.01*i);
      coxa_esq[1].write(90 + 0.01*i);

  }

  // Baixar grupo 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(60 + 0.01*i);
      rotula_dir[2].write(60 + 0.01*i);
      rotula_esq[1].write(120 - 0.01*i);

  }

  // Erguer grupo 2
  for(int i = 0; i < 3000; i++){

      rotula_esq[0].write(90 + 0.01*i);
      rotula_esq[2].write(90 + 0.01*i);
      rotula_dir[1].write(90 - 0.01*i);

  }

  // Vira grupo 2
  for(int i = 0; i < 3000; i++){

      coxa_esq[0].write(90 + 0.01*i);
      coxa_esq[2].write(90 + 0.01*i);
      coxa_dir[1].write(90 + 0.01*i);

  }

  // Baixar grupo 2
  for(int i = 0; i < 3000; i++){

      rotula_esq[0].write(120 - 0.01*i);
      rotula_esq[2].write(120 - 0.01*i);
      rotula_dir[1].write(60 + 0.01*i);

  }

  // Girar corpo
  for(int i = 0; i < 3000; i++){

      coxa_dir[0].write(120 - 0.01*i);
      coxa_dir[1].write(120 - 0.01*i);
      coxa_dir[2].write(120 - 0.01*i);
      coxa_esq[0].write(120 - 0.01*i);
      coxa_esq[1].write(120 - 0.01*i);
      coxa_esq[2].write(120 - 0.01*i);

  }

}

void virarParaEsquerda(){

  // Erguer grupo 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(90 - 0.01*i);
      rotula_dir[2].write(90 - 0.01*i);
      rotula_esq[1].write(90 + 0.01*i);

  }

  // Vira grupo 1
  for(int i = 0; i < 3000; i++){

      coxa_dir[0].write(90 - 0.01*i);
      coxa_dir[2].write(90 - 0.01*i);
      coxa_esq[1].write(90 - 0.01*i);

  }

  // Baixar grupo 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(60 + 0.01*i);
      rotula_dir[2].write(60 + 0.01*i);
      rotula_esq[1].write(120 - 0.01*i);

  }

  // Erguer grupo 2
  for(int i = 0; i < 3000; i++){

      rotula_esq[0].write(90 + 0.01*i);
      rotula_esq[2].write(90 + 0.01*i);
      rotula_dir[1].write(90 - 0.01*i);

  }

  // Vira grupo 2
  for(int i = 0; i < 3000; i++){

      coxa_esq[0].write(90 - 0.01*i);
      coxa_esq[2].write(90 - 0.01*i);
      coxa_dir[1].write(90 - 0.01*i);

  }

  // Baixar grupo 2
  for(int i = 0; i < 3000; i++){

      rotula_esq[0].write(120 - 0.01*i);
      rotula_esq[2].write(120 - 0.01*i);
      rotula_dir[1].write(60 + 0.01*i);

  }

  // Girar corpo
  for(int i = 0; i < 3000; i++){

      coxa_dir[0].write(60 + 0.01*i);
      coxa_dir[1].write(60 + 0.01*i);
      coxa_dir[2].write(60 + 0.01*i);
      coxa_esq[0].write(60 + 0.01*i);
      coxa_esq[1].write(60 + 0.01*i);
      coxa_esq[2].write(60 + 0.01*i);

  }

}


/*  
**  Examplo:
** 
**    coxa 1 da direita move 30 graus para cima
**    mexer(0, 1, 1, 30, 0)
**
**  membro:       0 - coxa, 1 - rotula ou 2 - pata
**
**  pos_membro:   0, 1 ou 2
**
**  dir_esq:      0 - direita ou 1 - esquerda
**
**  cima_baixo :  0 - cima ou 1 - baixo
**
*/
void mexer(unsigned int membro, unsigned int pos_membro, unsigned int dir_esq, unsigned int angulo, unsigned int cima_baixo){

  switch (membro) {
      //-------------------------------------------- COXA
      case 0:
          switch (dir_esq) {

            case 0: //--------------------------- DIREITA
              if(cima_baixo == 0){ //------------ cima
                coxa_dir[pos_membro].write(angulo);
              }else{ //-------------------------- baixo
                coxa_dir[pos_membro].write(-(angulo));
              }
              break;
            case 1: //--------------------------- ESQUERDA
              if(cima_baixo == 0){ //------------ cima
                coxa_esq[pos_membro].write(-angulo);
              }else{ //-------------------------- baixo
                coxa_esq[pos_membro].write(angulo);
              }
              break;
            default:
              break;
          }
        break;

      //-------------------------------------------- ROTULA  
      case 1:
          switch (dir_esq) {
            case 0: //--------------------------- DIREITA
              if(cima_baixo == 0){ //------------ cima
                rotula_dir[pos_membro].write(-(angulo));
              }else{ //-------------------------- baixo
                rotula_dir[pos_membro].write(angulo);
              }
              break;
            case 1: //--------------------------- ESQUERDA
              if(cima_baixo == 0){ //------------ cima
                rotula_esq[pos_membro].write(angulo);
              }else{ //-------------------------- baixo
                rotula_esq[pos_membro].write(-(angulo));
              }
              break;
            default:
              break;
          }
        break;

      //-------------------------------------------- PATA
      case 2:
          switch (dir_esq) {
            case 0: //--------------------------- DIREITA
              if(cima_baixo == 0){ //------------ cima
                pata_dir[pos_membro].write(angulo);
              }else{ //-------------------------- baixo
                pata_dir[pos_membro].write(-(angulo));
              }
              break;
            case 1: //--------------------------- ESQUERDA
              if(cima_baixo == 0){ //------------ cima
                pata_esq[pos_membro].write(-angulo);
              }else{ //-------------------------- baixo
                pata_esq[pos_membro].write(angulo);
              }
              break;
            default:
              break;
          }
        break;

      default:
        break;
  }
}

// void testeCoxas(){
  
//   coxa_dir[0].write(85);
//   coxa_dir[1].write(100);
//   coxa_dir[2].write(90);
//   coxa_esq[0].write(90);
//   coxa_esq[1].write(90);
//   coxa_esq[2].write(100);

// }


void testeRotulas(){
 
  rotula_dir[0].write(90);
  rotula_dir[1].write(90);
  rotula_dir[2].write(90);
  rotula_esq[0].write(90);
  rotula_esq[1].write(90);
  rotula_esq[2].write(90);

  delay(3000);

  rotula_dir[0].write(60);
  rotula_dir[1].write(60);
  rotula_dir[2].write(60);
  rotula_esq[0].write(120);
  rotula_esq[1].write(120);
  rotula_esq[2].write(120);

  delay(3000);

  rotula_dir[0].write(90);
  rotula_dir[1].write(90);
  rotula_dir[2].write(90);
  rotula_esq[0].write(90);
  rotula_esq[1].write(90);
  rotula_esq[2].write(90);

  delay(3000);

  rotula_dir[0].write(130);
  rotula_dir[1].write(120);
  rotula_dir[2].write(120);
  rotula_esq[0].write(60);
  rotula_esq[1].write(60);
  rotula_esq[2].write(60);

  delay(3000);

}

void testePatas(){
  
  pata_dir[0].write(90);
  pata_dir[1].write(90);
  pata_dir[2].write(90);
  pata_esq[0].write(90);
  pata_esq[1].write(90);
  pata_esq[2].write(90); 

  delay(3000);

  pata_dir[0].write(45);
  pata_dir[1].write(45);
  pata_dir[2].write(45);
  pata_esq[0].write(135);
  pata_esq[1].write(135);
  pata_esq[2].write(135); 

  delay(3000);

  pata_dir[0].write(90);
  pata_dir[1].write(90);
  pata_dir[2].write(90);
  pata_esq[0].write(90);
  pata_esq[1].write(90);
  pata_esq[2].write(90); 

  delay(3000);

  pata_dir[0].write(135);
  pata_dir[1].write(135);
  pata_dir[2].write(135);
  pata_esq[0].write(45);
  pata_esq[1].write(45);
  pata_esq[2].write(45); 

  delay(3000);

}

void setCoxas(int angulo){

  if( angulo > 90 ){

    coxa_dir[0].write(90 - (angulo - 90));
    coxa_dir[1].write(90 - (angulo - 90));
    coxa_dir[2].write(90 - (angulo - 90));
    coxa_esq[0].write(angulo);
    coxa_esq[1].write(angulo);
    coxa_esq[2].write(angulo);

  }else{

    coxa_dir[0].write((90 - angulo) + 90);
    coxa_dir[1].write((90 - angulo) + 90);
    coxa_dir[2].write((90 - angulo) + 90);
    coxa_esq[0].write(angulo);
    coxa_esq[1].write(angulo);
    coxa_esq[2].write(angulo);

  }

}

void setRotulas(int angulo){

  if( angulo > 90 ){

    rotula_dir[0].write(90 - (angulo - 90));
    rotula_dir[1].write(90 - (angulo - 90));
    rotula_dir[2].write(90 - (angulo - 90));
    rotula_esq[0].write(angulo);
    rotula_esq[1].write(angulo);
    rotula_esq[2].write(angulo);

  }else{

    rotula_dir[0].write((90 - angulo) + 90);
    rotula_dir[1].write((90 - angulo) + 90);
    rotula_dir[2].write((90 - angulo) + 90);
    rotula_esq[0].write(angulo);
    rotula_esq[1].write(angulo);
    rotula_esq[2].write(angulo);

  }

}

void setPatas(int angulo){

  if( angulo > 90 ){

    pata_dir[0].write(90 - (angulo - 90));
    pata_dir[1].write(90 - (angulo - 90));
    pata_dir[2].write(90 - (angulo - 90));
    pata_esq[0].write(angulo);
    pata_esq[1].write(angulo);
    pata_esq[2].write(angulo);

  }else{

    pata_dir[0].write((90 - angulo) + 90);
    pata_dir[1].write((90 - angulo) + 90);
    pata_dir[2].write((90 - angulo) + 90);
    pata_esq[0].write(angulo);
    pata_esq[1].write(angulo);
    pata_esq[2].write(angulo);

  }
}


void teste1(){
 
  pata_dir[0].write(180);
  pata_esq[0].write(0);
  delay(1000);
  
  rotula_dir[0].write(45);
  rotula_esq[0].write(135);
  delay(3000);
  
  rotula_dir[0].write(90);
  rotula_esq[0].write(90);
  delay(1000);
  
  pata_dir[0].write(90);
  pata_esq[0].write(90);
  delay(500);

}

void marchar(){

  //Perna direita para frente
  pata_dir[0].write(0);             
  delay(15);
  coxa_dir[0].write(0);
  delay(15);
  rotula_dir[0].write(90);
  delay(15);
  delay(500);
  
  pata_dir[0].write(90);             
  delay(15);
  coxa_dir[0].write(90);
  delay(15);
  rotula_dir[0].write(90);
  delay(15);
  delay(500);
  
  //--------------------------
  
  pata_esq[1].write(180);             
  delay(15);
  coxa_esq[1].write(180);
  delay(15);
  rotula_esq[1].write(90);
  delay(15);
  delay(500);
  pata_esq[1].write(90);             
  delay(15);
  coxa_esq[1].write(90);
  delay(15);
  rotula_esq[1].write(90);
  delay(15);
  delay(500);

  //--------------------------
  
  pata_dir[2].write(0);             
  delay(15);
  coxa_dir[2].write(0);
  delay(15);
  rotula_dir[2].write(90);
  delay(15);
  delay(500);
  pata_dir[2].write(90);             
  delay(15);
  coxa_dir[2].write(90);
  delay(15);
  rotula_dir[2].write(90);
  delay(15);
  delay(500);

  //--------------------------
  
  pata_esq[0].write(180);             
  delay(15);
  coxa_esq[0].write(180);
  delay(15);
  rotula_esq[0].write(90);
  delay(15);
  delay(500);
  pata_esq[0].write(90);             
  delay(15);
  coxa_esq[0].write(90);
  delay(15);
  rotula_esq[0].write(90);
  delay(15);
  delay(500);
  
  //--------------------------
  
  pata_dir[1].write(0);             
  delay(15);
  coxa_dir[1].write(0);
  delay(15);
  rotula_dir[1].write(90);
  delay(15);
  delay(500);
  pata_dir[1].write(90);             
  delay(15);
  coxa_dir[1].write(90);
  delay(15);
  rotula_dir[1].write(90);
  delay(15);
  delay(500);

  //--------------------------
  
  pata_esq[2].write(180);             
  delay(15);
  coxa_esq[2].write(180);
  delay(15);
  rotula_esq[2].write(90);
  delay(15);
  delay(500);
  pata_esq[2].write(90);             
  delay(15);
  coxa_esq[2].write(90);
  delay(15);
  rotula_esq[2].write(90);
  delay(15);
  delay(500);

}

void caminhar() {

  //Move perna 1 da esquerda para frente
  coxa_esq[0].write(105);
  delay(100);
  rotula_esq[0].write(120);
  delay(100);
  coxa_esq[0].write(90);
  delay(100);

  //Move perna 2 da direita para frente  
  coxa_dir[1].write(75);
  delay(100);
  rotula_dir[1].write(60);
  delay(100);
  coxa_dir[1].write(90);
  delay(100);

  //Move perna 2 da esquerda para frente  
  coxa_esq[2].write(105);
  delay(100);
  rotula_esq[2].write(120);
  delay(100);
  coxa_esq[2].write(90);
  delay(100);
  
  //Puxa o corpo
  rotula_esq[0].write(80);
  delay(100);
  rotula_dir[1].write(90);
  delay(100);
  rotula_esq[2].write(90);
  delay(100);
  
  //---------------------------------------------------
  
  //Move perna 1 da direita para frente
  coxa_dir[0].write(75);
  delay(100);
  rotula_dir[0].write(60);
  delay(100);
  coxa_dir[0].write(90);
  delay(100);

  //Move perna 2 esquerda para frente  
  coxa_esq[1].write(105);
  delay(100);
  rotula_esq[1].write(120);
  delay(100);
  coxa_esq[1].write(90);
  delay(100);

  //Move perna 3 da direita para frente  
  coxa_dir[2].write(75);
  delay(100);
  rotula_dir[2].write(60);
  delay(100);
  coxa_dir[2].write(90);
  delay(100);
  
  //Puxa o corpo
  rotula_dir[0].write(90);
  delay(100);
  rotula_esq[1].write(90);
  delay(100);
  rotula_dir[2].write(90);
  delay(100);
  

}

void testeCoxas(){

  setCoxas(90);

  for(int i = 0; i < 3000; i++){

    coxa_esq[2].write(90 - 0.02*i);

    delayMicroseconds(1000000/12000);  

  }   

  setCoxas(90);

  for(int i = 0; i < 3000; i++){

    coxa_esq[2].write(90 + 0.02*i);

    delayMicroseconds(1000000/12000);  

  }   

  for(int j = 0; j < 3; j++){

    for(int i = 0; i < 3000; i++){

      coxa_dir[j].write(90 - 0.02*i);

      delayMicroseconds(1000000/6000);

    }

    setCoxas(90);

    for(int i = 0; i < 3000; i++){

      coxa_dir[j].write(90 + 0.02*i);

      delayMicroseconds(1000000/6000);  

    }

    setCoxas(90);

    for(int i = 0; i < 3000; i++){

      coxa_esq[j].write(90 - 0.02*i);

      delayMicroseconds(1000000/6000);

    }

    setCoxas(90);

    for(int i = 0; i < 3000; i++){

      coxa_esq[j].write(90 + 0.02*i);

      delayMicroseconds(1000000/6000);  

    }

  }

}

// void encolher(){

//   pata_dir[0].write(0);             
//   delay(15);
//   coxa_dir[0].write(0);
//   delay(15);
//   rotula_dir[0].write(90);
//   delay(15);
  
//   pata_esq[1].write(180);             
//   delay(15);
//   coxa_esq[1].write(180);
//   delay(15);
//   rotula_esq[1].write(90);
//   delay(15);
  
//   pata_dir[2].write(0);             
//   delay(15);
//   coxa_dir[2].write(0);
//   delay(15);
//   rotula_dir[2].write(90);
//   delay(15);
  
//   pata_esq[0].write(180);             
//   delay(15);
//   coxa_esq[0].write(180);
//   delay(15);
//   rotula_esq[0].write(90);
//   delay(15);
  
//   pata_dir[1].write(0);             
//   delay(15);
//   coxa_dir[1].write(0);
//   delay(15);
//   rotula_dir[1].write(90);
//   delay(15);
  
//   pata_esq[2].write(180);             
//   delay(15);
//   coxa_esq[2].write(180);
//   delay(15);
//   rotula_esq[2].write(90);
//   delay(15);
// }

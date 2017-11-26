#include <Servo.h>

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

int walkAhead_Speed = 1;
int walkRight_Speed = 1;
int walkLeft_Speed  = 1;


void setup(){

  Serial.begin(9600); // opens serial port, sets data rate to 57600 baud
  
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

  home();

}

void loop(){

  home();

  char incomingByte;

  while(!(Serial.available() > 0)){
    /*Wait until take data */
  }

  incomingByte = Serial.read();

  switch(incomingByte){

    case '0': // Serial test
    Serial.write(incomingByte); // send it back
    break;

    case '1': // Go ahead
    walkAhead();
    Serial.write(incomingByte); // send it back
    break;

    case '2': // Stop
    home();
    Serial.write(incomingByte); // send it back
    break;

    case '3': // Go right
    walkToRight(walkRight_Speed);
    Serial.write(incomingByte); // send it back
    break;

    case '4': // Go left
    walkToLeft(walkLeft_Speed);
    Serial.write(incomingByte); // send it back
    break;

    case '5': // Turn right
    Serial.write(incomingByte); // send it back
    break;

    case '6': // Turn left
    Serial.write(incomingByte); // send it back
    break;

    case '7': // Squat
    walkToRight(walkRight_Speed);
    Serial.write(incomingByte); // send it back
    break;

    case '8': // Rise
    Serial.write(incomingByte); // send it back
    break;

    case '9': // Rise
    Serial.write(incomingByte); // send it back
    break;

    default:
    break;

  }

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

void walkAhead(int speed = 1){

  home();

  // Rise group 1
  for(int degree = 0; degree < 30; degree += speed){

    rotula_dir[0].write(home_rotula_dir - degree);
    rotula_dir[2].write(home_rotula_dir - degree);
    rotula_esq[1].write(home_rotula_esq + degree);

    delay(1000/60);

  }

  // Move group 1
  for(int degree = 0; degree < 30; degree += speed){

    coxa_dir[0].write(home_coxa_dir - degree);
    coxa_dir[2].write(home_coxa_dir - degree);
    coxa_esq[1].write(home_coxa_esq + degree);

    delay(1000/60);

  }

  // Down group 1

  for(int degree = 0; degree < 30; degree += speed){

    rotula_dir[0].write(home_rotula_dir - 30 + degree);
    rotula_dir[2].write(home_rotula_dir - 30 + degree);
    rotula_esq[1].write(home_rotula_esq + 30 - degree);

    delay(1000/60);

  }

  // Rise group 2

  for(int degree = 0; degree < 30; degree += speed){

    rotula_esq[0].write(home_rotula_esq + degree);
    rotula_esq[2].write(home_rotula_esq + degree);
    rotula_dir[1].write(home_rotula_dir - degree);

    delay(1000/60);

  }

  // Move grupo 2

  for(int degree = 0; degree < 30; degree += speed){

    coxa_esq[0].write(home_coxa_esq + degree);
    coxa_esq[2].write(home_coxa_esq + degree);
    coxa_dir[1].write(home_coxa_dir - degree);

    delay(1000/60);

  }
  // Down grupo 2

  for(int degree = 0; degree < 30; degree += speed){

    rotula_esq[0].write(home_rotula_esq + 30 - degree);
    rotula_esq[2].write(home_rotula_esq + 30 - degree);
    rotula_dir[1].write(home_rotula_dir - 30 + degree);

    delay(1000/60);

  }

  // Puxar corpo

  for(int degree = 0; degree < 30; degree += speed){

    coxa_dir[0].write(home_coxa_dir - 30 + degree);
    coxa_dir[1].write(home_coxa_dir - 30 + degree);
    coxa_dir[2].write(home_coxa_dir - 30 + degree);
    coxa_esq[0].write(home_coxa_esq + 30 - degree);
    coxa_esq[1].write(home_coxa_esq + 30 - degree);
    coxa_esq[2].write(home_coxa_esq + 30 - degree);

    delay(1000/60);

  }


  home();

}

void walkToRight(int speed = 1){

  home();

  // Rise group 1
  for(int degree = 0; degree < 30; degree += speed){

    rotula_dir[0].write(home_rotula_dir - degree);
    rotula_dir[2].write(home_rotula_dir - degree);
    rotula_esq[1].write(home_rotula_esq + degree);

    delay(1000/60);

  }

  // Movimentar group 1 para direita
  for(int degree = 0; degree < 20; degree += speed){

    pata_dir[0].write(home_pata_dir + degree);
    pata_dir[2].write(home_pata_dir + degree);
    pata_esq[1].write(home_pata_esq + degree);

    delay(1000/80);

  }

  // Down group 1
  for(int degree = 0; degree < 30; degree += speed){

    rotula_dir[0].write(home_rotula_dir - 30 + degree);
    rotula_dir[2].write(home_rotula_dir - 30 + degree);
    rotula_esq[1].write(home_rotula_esq + 30 - degree);

    delay(1000/60);

  }

  // Rise group 2

  for(int degree = 0; degree < 30; degree += speed){

    rotula_esq[0].write(home_rotula_esq + degree);
    rotula_esq[2].write(home_rotula_esq + degree);
    rotula_dir[1].write(home_rotula_dir - degree);

    delay(1000/60);

  }

  // Movimentar grupo 2 para direita
  for(int degree = 0; degree < 20; degree += speed){

    pata_esq[0].write(home_pata_esq + degree);
    pata_esq[2].write(home_pata_esq + degree);
    pata_dir[1].write(home_pata_dir + degree);

    delay(1000/80);

  }

  // Down grupo 2
  for(int degree = 0; degree < 30; degree += speed){

    rotula_esq[0].write(home_rotula_esq + 30 - degree);
    rotula_esq[2].write(home_rotula_esq + 30 - degree);
    rotula_dir[1].write(home_rotula_dir - 30 + degree);

    delay(1000/60);

  }

  for(int degree = 0; degree < 20; degree += speed){

    pata_dir[0].write(home_pata_dir + 20 - degree);
    pata_dir[1].write(home_pata_dir + 20 - degree);
    pata_dir[2].write(home_pata_dir + 20 - degree);
    pata_esq[0].write(home_pata_esq + 20 - degree);
    pata_esq[1].write(home_pata_esq + 20 - degree);
    pata_esq[2].write(home_pata_esq + 20 - degree);

    delay(1000/80);

  }

  home();

}

void walkToLeft(int speed = 1){

  home();

  // Rise group 1
  for(int degree = 0; degree < 30; degree += speed){

    rotula_dir[0].write(home_rotula_dir - degree);
    rotula_dir[2].write(home_rotula_dir - degree);
    rotula_esq[1].write(home_rotula_esq + degree);

    delay(1000/60);

  }

  // Movimentar group 1 para direita
  for(int degree = 0; degree < 20; degree += speed){

    pata_dir[0].write(home_pata_dir - degree);
    pata_dir[2].write(home_pata_dir - degree);
    pata_esq[1].write(home_pata_esq - degree);

    delay(1000/80);

  }

  // Down group 1
  for(int degree = 0; degree < 30; degree += speed){

    rotula_dir[0].write(home_rotula_dir - 30 + degree);
    rotula_dir[2].write(home_rotula_dir - 30 + degree);
    rotula_esq[1].write(home_rotula_esq + 30 - degree);

    delay(1000/60);

  }

  // Rise group 2

  for(int degree = 0; degree < 30; degree += speed){

    rotula_esq[0].write(home_rotula_esq + degree);
    rotula_esq[2].write(home_rotula_esq + degree);
    rotula_dir[1].write(home_rotula_dir - degree);

    delay(1000/60);

  }

  // Movimentar grupo 2 para direita
  for(int degree = 0; degree < 20; degree += speed){

    pata_esq[0].write(home_pata_esq - degree);
    pata_esq[2].write(home_pata_esq - degree);
    pata_dir[1].write(home_pata_dir - degree);

    delay(1000/80);

  }

  // Down grupo 2
  for(int degree = 0; degree < 30; degree += speed){

    rotula_esq[0].write(home_rotula_esq + 30 - degree);
    rotula_esq[2].write(home_rotula_esq + 30 - degree);
    rotula_dir[1].write(home_rotula_dir - 30 + degree);

    delay(1000/60);

  }

  for(int degree = 0; degree < 20; degree += speed){

    pata_dir[0].write(home_pata_dir - 20 + degree);
    pata_dir[1].write(home_pata_dir - 20 + degree);
    pata_dir[2].write(home_pata_dir - 20 + degree);
    pata_esq[0].write(home_pata_esq - 20 + degree);
    pata_esq[1].write(home_pata_esq - 20 + degree);
    pata_esq[2].write(home_pata_esq - 20 + degree);

    delay(1000/80);

  }

  home();

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

  //Down patas
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

      rotula_dir[0].write(45-15);
      rotula_dir[1].write(45-15);
      rotula_dir[2].write(45-15);
      rotula_esq[0].write(135+15);
      rotula_esq[1].write(135+15);
      rotula_esq[2].write(135+15);

      // delay(4500/1000);

  }

  // Pata pra dentro
  for(int i = 0; i < 9000; i++){

      pata_dir[0].write(90 - 75);
      pata_dir[1].write(90 - 75);
      pata_dir[2].write(90 - 75);
      pata_esq[0].write(90 + 75);
      pata_esq[1].write(90 + 75);
      pata_esq[2].write(90 + 75);

  }

  // //Baixa rotula
  // for(int i = 0; i < 1500; i++){

  //     rotula_dir[0].write(45 + 0.01*i);
  //     rotula_dir[1].write(45 + 0.01*i);
  //     rotula_dir[2].write(45 + 0.01*i);
  //     rotula_esq[0].write(135 - 0.01*i);
  //     rotula_esq[1].write(135 - 0.01*i);
  //     rotula_esq[2].write(135 - 0.01*i);

  // }

  // //Baixa rotula
  // for(int i = 0; i < 4500; i++){

  //     rotula_dir[0].write(60 - 0.01*i);
  //     rotula_dir[1].write(60 - 0.01*i);
  //     rotula_dir[2].write(60 - 0.01*i);
  //     rotula_esq[0].write(120 + 0.01*i);
  //     rotula_esq[1].write(120 + 0.01*i);
  //     rotula_esq[2].write(120 + 0.01*i);

  // }

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

void andarAcelerando(){

  for(int j = 1; j < 9; j=j*2)
  {

    for(int k = 0; k < 3; k++){

      // Erguer group 1
      for(int i = 0; i < 3000; i = i + 1*j){

          rotula_dir[0].write(90 - 0.01*i);
          rotula_dir[2].write(90 - 0.01*i);
          rotula_esq[1].write(90 + 0.01*i);

      }

      // Avançar group 1
      for(int i = 0; i < 3000; i = i + 1*j){

          coxa_dir[0].write(90 - 0.01*i);
          coxa_dir[2].write(90 - 0.01*i);
          coxa_esq[1].write(90 + 0.01*i);

      }

      // Down group 1
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

      // Down grupo 2
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


void virarParaDireita(){

  // Erguer group 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(90 - 0.01*i);
      rotula_dir[2].write(90 - 0.01*i);
      rotula_esq[1].write(90 + 0.01*i);

  }

  // Vira group 1
  for(int i = 0; i < 3000; i++){

      coxa_dir[0].write(90 + 0.01*i);
      coxa_dir[2].write(90 + 0.01*i);
      coxa_esq[1].write(90 + 0.01*i);

  }

  // Down group 1
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

  // Down grupo 2
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

  // Erguer group 1
  for(int i = 0; i < 3000; i++){

      rotula_dir[0].write(90 - 0.01*i);
      rotula_dir[2].write(90 - 0.01*i);
      rotula_esq[1].write(90 + 0.01*i);

  }

  // Vira group 1
  for(int i = 0; i < 3000; i++){

      coxa_dir[0].write(90 - 0.01*i);
      coxa_dir[2].write(90 - 0.01*i);
      coxa_esq[1].write(90 - 0.01*i);

  }

  // Down group 1
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

  // Down grupo 2
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
**    coxa 1 da direita move 30 degrees para cima
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

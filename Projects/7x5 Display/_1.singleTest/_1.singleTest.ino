byte led_row[7] = {5,2,6,11,7,13,8};
byte led_col[5] = {3,9,10,4,12};
long prevTime = -1000;
long interval = 5000;

byte draw_task[7][5] = {
  { 0,1,1,0,0},
  { 0,0,1,0,0},
  { 0,0,1,0,0},
  { 0,0,1,0,0},
  { 0,0,1,0,0},
  { 0,0,1,0,0},
  { 0,0,1,0,0}};
  
byte zero[7][5] = {
  { 0,1,1,1,0},
  { 1,0,0,0,1},
  { 1,0,0,0,1},
  { 1,0,0,0,1},
  { 1,0,0,0,1},
  { 1,0,0,0,1},
  { 0,1,1,1,0}};
  
  byte one[7][5] = {
  { 0,1,1,0,0},
  { 1,0,1,0,0},
  { 0,0,1,0,0},
  { 0,0,1,0,0},
  { 0,0,1,0,0},
  { 0,0,1,0,0},
  { 1,1,1,1,1}};
  
  byte two[7][5] = {
  { 1,0,0,0,1},
  { 0,1,0,1,0},
  { 0,1,0,1,0},
  { 0,0,1,0,0},
  { 0,1,0,1,0},
  { 0,1,0,1,0},
  { 1,0,0,0,1}};
  
  byte three[7][5] = {
  { 1,0,0,0,1},
  { 0,1,0,1,0},
  { 0,1,0,1,0},
  { 0,0,1,0,0},
  { 0,1,0,1,0},
  { 0,1,0,1,0},
  { 1,0,0,0,1}};
  
  byte four[7][5] = {
  { 1,0,0,0,1},
  { 0,1,0,1,0},
  { 0,1,0,1,0},
  { 0,0,1,0,0},
  { 0,1,0,1,0},
  { 0,1,0,1,0},
  { 1,0,0,0,1}};

void setup() { 
  pinMode( 3, OUTPUT );
  pinMode( 9, OUTPUT );
  pinMode( 10, OUTPUT );
  pinMode( 4, OUTPUT );
  pinMode( 12, OUTPUT );

  pinMode( 5, OUTPUT );
  pinMode( 2, OUTPUT );
  pinMode( 6, OUTPUT );
  pinMode( 11, OUTPUT );
  pinMode( 7, OUTPUT );
  pinMode( 13, OUTPUT );
  pinMode( 8, OUTPUT );
  
  for (int i = 0; i < 7; i++) {
    digitalWrite(led_row[i], 1);
  }
  for (int i = 0; i < 5; i++) {
    digitalWrite(led_col[i], 0);
  }
  
  delay(500);
    draw();
}

void draw() {
  draw_task[7][5] = zero[7][5];
//  unsigned long currentTime = millis();
//  
//  if (currentTime - prevTime > interval) {
//    prevTime = currentTime;
//    draw_task[7][5] = one[7][5];
//  }
//  else {
//   
//  }  
}

void loop() {
  for (int i = 0; i < 7; i++) {
  digitalWrite(led_row[i], 1);
  for (int j = 0; j < 5; j++) {
    digitalWrite(led_col[j], (draw_task[i][j] == 1 ? 0 : 1));
  }
  delayMicroseconds(900);
  digitalWrite(led_row[i], 0);
  }

}

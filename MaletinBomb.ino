#include <Keypad.h>
#include <LiquidCrystal.h>

// Config

char enteredText[8];
char password[8];
int key2 = -1;
char lastKey;
char var;
byte team = 0;

/*  Configuracion de botones
 *     button_R -> boton derecho
 *     button_L -> boton izquierdo
 *     button_Up -> boton arriba
 *     button_Down -> boton abajo
 *     button_Selec -> boton seleccionar
 *     button_Cancel -> boton cancelar
 */
const char button_R = '4';
const char button_L = '6';
const char button_Up = '2';
const char button_Down = '8';
const char button_Selec = 'A';
const char button_Cancel = 'B';

/*  Configuracion de sonidos */
const int tonePin = 8;
const int tonoPitido = 3000;
const int tonoAlarma1 = 700;
const int tonoAlarma2 = 2600;
const int tonoActivada = 1330;
const int tonoERROR = 100;

/*  Configuracion de tiempos */
int gameHours = 0;
int gameMinutes = 45;
int bombMinutes = 4;
int activateSeconds = 5;
unsigned long iTime;
unsigned long timeCalcVar;
unsigned long redTime;
unsigned long greenTime;
unsigned long iZoneTime;

/*  Estados
 *     sdStatus -> buscar y destruir
 *     saStatus -> Sabotaje
 *     deStatus -> Demolicion
 *     soundEnable -> habilitar sonidos
 */
boolean sdStatus = false;
boolean saStatus = false;
boolean deStatus = false;
boolean endGame = false;
boolean strat = true;
boolean defuseando;
boolean cancelado;
boolean soundEnable = true;
boolean passEnable = true;

const int ledRed = 13;
const int ledGreen = 12;

const byte cols = 4;
const byte filas = 4;

char key[filas][cols] =
    {
        {'1', '2', '3', 'A'},
        {'4', '5', '6', 'B'},
        {'7', '8', '9', 'C'},
        {'#', '0', '*', 'D'},
};

byte pinesFilas[filas] = {A0, A1, 9, 8};
byte pinesCols[cols] = {A2, A3, A5, A4};

Keypad teclado = Keypad(makeKeymap(key), pinesFilas, pinesCols, filas, cols);

LiquidCrystal lcd(1, 2, 3, 4, 5, 6);

void setup()
{
  /*Configuracion de caracteres especiales*/
  byte up[8] = {
      B00000,
      B00100,
      B01110,
      B11111,
      B11111,
      B00000,
      B00000,
  };

  byte down[8] = {
      B00000,
      B00000,
      B11111,
      B11111,
      B01110,
      B00100,
      B00000,
  };

  byte bar1[8] = {
      B10000,
      B10000,
      B10000,
      B10000,
      B10000,
      B10000,
      B10000,
  };

  byte bar2[8] = {
      B11000,
      B11000,
      B11000,
      B11000,
      B11000,
      B11000,
      B11000,
  };

  byte bar3[8] = {
      B11100,
      B11100,
      B11100,
      B11100,
      B11100,
      B11100,
      B11100,
  };

  byte bar4[8] = {
      B11110,
      B11110,
      B11110,
      B11110,
      B11110,
      B11110,
      B11110,
  };

  byte bar5[8] = {
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
  };

  byte carita_feliz[8] = {
    B00000,
    B01010,
    B00000,
    B00000,
    B10001,
    B01110,
    B00000,
  };


  lcd.createChar(0,bar1);
  lcd.createChar(1,bar2);
  lcd.createChar(2,bar3);
  lcd.createChar(3,bar4);
  lcd.createChar(4,bar5);
  lcd.createChar(6,up);
  lcd.createChar(7,down);
  lcd.createChar(8,carita_feliz);

  /*Seteo de pines*/
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

  // Seteo keyPad
  teclado.setDebounceTime(50);
  teclado.setHoldTime(50);

  /*Seteo pantalla lcd*/
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("NAHUELITO");
  lcd.setCursor(4, 1);
  lcd.write(byte(8));
  lcd.print("GAMES");
  lcd.write(byte(8));

  delay(3000);

  //Serial.begin(9600);
}

void loop()
{
    //Serial.print(teclado.waitForKey());
    menuPrincipal();
}
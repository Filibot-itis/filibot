#include "Servo.h"

#define var_mov 3
#define n_servo 13
#define delay_mov 3
int mystate[n_servo]; // posizione corrente di ogni servomotore
Servo s[n_servo]; // imposto ogni servomotore
int pos[n_servo]; //

void dritto();

void mov(int a, int b, int c, int d, int e, int f, int h, int l, int m, int n, int o, int p, int q);
void movgdx(int a, int b, int c);
void movgsx(int a, int b, int c);
void movbdx(int a, int b, int c);
void movbsx(int a, int b, int c);

void rotgdx(int z);
void ginocchiodx(int z);
void piededx(int z);

void rotgsx(int z);
void ginocchiosx(int z);
void piedesx(int z);

void rotbdx(int z);
void spalladx(int z);
void gomitodx(int z);

void rotbsx(int z);
void spallasx(int z);
void gomitosx(int z);

void bacino(int z);

void setup() {
  // imposto porta seriale
  Serial.begin(9600);

  // imposto servomotori
  s[0].attach(11); // rot gamba dx
  s[1].attach(10); // ginocchio dx
  s[2].attach(9); // piede dx

  s[3].attach(21); // rot gamba sx
  s[4].attach(20); // giniocchio sx
  s[5].attach(19); // piede sx

  s[6].attach(7); // rot braccio dx
  s[7].attach(4); // spalla dx ////// NON SONO SICURO CHE IL PIN SIA GIUSTO
  s[8].attach(5); // gomito dx

  s[9].attach(17); // rot braccio sx
  s[10].attach(16); // spalla sx
  s[11].attach(15); // gomito sx

  s[12].attach(1); // bacino

  mystate[0] = 90; // rot gamba dx
  mystate[1] = 90; // ginocchio dx
  mystate[2] = 90; // piede dx
  mystate[3] = 90; // rot gamba sx
  mystate[4] = 90; // giniocchio sx
  mystate[5] = 90; // piede sx
  mystate[6] = 90; // rot braccio dx
  mystate[7] = 90; // spalla dx
  mystate[8] = 90; // gomito dx
  mystate[9] = 90; // rot braccio sx
  mystate[10] = 90; // spalla sx
  mystate[11] = 90; // gomito sx
  mystate[12] = 90; // bacino

  // imposto variabili
  dritto();
}

void loop() {
  dritto();
}

/////////////////////////////////////////////////// funzioni preimpostate

void dritto() {
  mov(90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90);
  //mov(mystate[0], mystate[1], mystate[2], mystate[3], mystate[4], mystate[5], mystate[6], mystate[7], mystate[8], mystate[9], mystate[10], mystate[11], mystate[12]);
}

//////////////////////////////////////////////////// mov
void mov(int a, int b, int c, int d, int e, int f, int h, int l, int m, int n, int o, int p, int q)
{
  int var[n_servo] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // var: di quanto muovere i servi
  int g[n_servo] = {a, b, c, d, e, f, h, l, m, n, o, p, q}; // ogni parametro passato viene messo in un vettore

  for (int j = 0; j < n_servo; j++) // scelgo se muovere avanti o indietro i servomotori
  {
    if (mystate[j] < g[j] - var_mov)
      var[j] = var_mov;
    else if (mystate[j] > g[j] + var_mov)
      var[j] = -var_mov;
    else
      var[j] = 0;
  }

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    for (int i = 0; i < n_servo; i++)
      if (!mysequalg(mystate[i], var[i], g[i]))
      {
        s[i].write(mystate[i] + var[i]);
        delay(delay_mov);
        mystate[i] += var[i];
      }
}

// mov gambe
void movgdx(int a, int b, int c)
{
  int var[3] = {0, 0, 0};  // var: di quanto muovere i servi
  int g[3] = {a, b, c}; // ogni parametro passato viene messo in un vettore

  for (int j = 0; j < 3; j++) // scelgo se muovere avanti o indietro i servomotori
  {
    if (mystate[j] < g[j] - var_mov)
      var[j] = var_mov;
    else if (mystate[j] > g[j] + var_mov)
      var[j] = -var_mov;
    else
      var[j] = 0;
  }

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    for (int i = 0; i < 3; i++)
      if (!mysequalg(mystate[i], var[i], g[i]))
      {
        s[i].write(mystate[i] + var[i]);
        delay(delay_mov);
        mystate[i] += var[i];
      }
}
void movgsx(int a, int b, int c)
{
  int var[3] = {0, 0, 0};  // var: di quanto muovere i servi
  int g[3] = {a, b, c}; // ogni parametro passato viene messo in un vettore

  for (int j = 0; j < 3; j++) // scelgo se muovere avanti o indietro i servomotori
  {
    if (mystate[j + 3] < g[j] - var_mov)
      var[j] = var_mov;
    else if (mystate[j + 3] > g[j] + var_mov)
      var[j] = -var_mov;
    else
      var[j] = 0;
  }

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    for (int i = 0; i < 3; i++)
      if (!mysequalg(mystate[i + 3], var[i], g[i]))
      {
        s[i + 3].write(mystate[i + 3] + var[i]);
        delay(delay_mov);
        mystate[i + 3] += var[i];
      }
}

// mov braccia
void movbdx(int a, int b, int c)
{
  int var[3] = {0, 0, 0};  // var: di quanto muovere i servi
  int g[3] = {a, b, c}; // ogni parametro passato viene messo in un vettore

  for (int j = 0; j < 3; j++) // scelgo se muovere avanti o indietro i servomotori
  {
    if (mystate[j + 6] < g[j] - var_mov)
      var[j] = var_mov;
    else if (mystate[j + 6] > g[j] + var_mov)
      var[j] = -var_mov;
    else
      var[j] = 0;
  }

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    for (int i = 0; i < 3; i++)
      if (!mysequalg(mystate[i + 6], var[i], g[i]))
      {
        s[i + 6].write(mystate[i + 6] + var[i]);
        delay(delay_mov);
        mystate[i + 6] += var[i];
      }
}
void movbsx(int a, int b, int c)
{
  int var[3] = {0, 0, 0};  // var: di quanto muovere i servi
  int g[3] = {a, b, c}; // ogni parametro passato viene messo in un vettore

  for (int j = 0; j < 3; j++) // scelgo se muovere avanti o indietro i servomotori
  {
    if (mystate[j + 9] < g[j] - var_mov)
      var[j] = var_mov;
    else if (mystate[j + 9] > g[j] + var_mov)
      var[j] = -var_mov;
    else
      var[j] = 0;
  }

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    for (int i = 0; i < 3; i++)
      if (!mysequalg(mystate[i + 9], var[i], g[i]))
      {
        s[i + 9].write(mystate[i + 9] + var[i]);
        delay(delay_mov);
        mystate[i + 9] += var[i];
      }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// gamba dx
void rotgdx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[0] < g - var_mov)
    var = var_mov;
  else if (mystate[0] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[0], var, g))
    {
      s[0].write(mystate[0] + var);
      delay(delay_mov);
      mystate[0] += var;
    }
}
void ginocchiodx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[1] < g - var_mov)
    var = var_mov;
  else if (mystate[1] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[1], var, g))
    {
      s[1].write(mystate[1] + var);
      delay(delay_mov);
      mystate[1] += var;
    }
}
void piededx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[2] < g - var_mov)
    var = var_mov;
  else if (mystate[2] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[2], var, g))
    {
      s[2].write(mystate[2] + var);
      delay(delay_mov);
      mystate[2] += var;
    }
}

// gamba sx
void rotgsx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[3] < g - var_mov)
    var = var_mov;
  else if (mystate[3] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[3], var, g))
    {
      s[3].write(mystate[3] + var);
      delay(delay_mov);
      mystate[3] += var;
    }
}
void ginocchiosx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[4] < g - var_mov)
    var = var_mov;
  else if (mystate[4] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[4], var, g))
    {
      s[4].write(mystate[4] + var);
      delay(delay_mov);
      mystate[4] += var;
    }
}
void piedesx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[5] < g - var_mov)
    var = var_mov;
  else if (mystate[5] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[5], var, g))
    {
      s[5].write(mystate[5] + var);
      delay(delay_mov);
      mystate[5] += var;
    }
}

// braccio dx
void rotbdx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[6] < g - var_mov)
    var = var_mov;
  else if (mystate[6] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[6], var, g))
    {
      s[6].write(mystate[6] + var);
      delay(delay_mov);
      mystate[6] += var;
    }
}
void spalladx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[7] < g - var_mov)
    var = var_mov;
  else if (mystate[7] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[7], var, g))
    {
      s[7].write(mystate[7] + var);
      delay(delay_mov);
      mystate[7] += var;
    }
}
void gomitodx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[8] < g - var_mov)
    var = var_mov;
  else if (mystate[8] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[8], var, g))
    {
      s[8].write(mystate[8] + var);
      delay(delay_mov);
      mystate[8] += var;
    }
}

// braccio sx
void rotbsx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[9] < g - var_mov)
    var = var_mov;
  else if (mystate[9] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[9], var, g))
    {
      s[9].write(mystate[9] + var);
      delay(delay_mov);
      mystate[9] += var;
    }
}
void spallasx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[10] < g - var_mov)
    var = var_mov;
  else if (mystate[10] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[10], var, g))
    {
      s[10].write(mystate[10] + var);
      delay(delay_mov);
      mystate[10] += var;
    }
}
void gomitosx(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[11] < g - var_mov)
    var = var_mov;
  else if (mystate[11] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[11], var, g))
    {
      s[11].write(mystate[11] + var);
      delay(delay_mov);
      mystate[11] += var;
    }
}

// bacino
void bacino(int z)
{
  int var = 0;  // var: di quanto muovere i servi
  int g = z; // ogni parametro passato viene messo in un vettore

  if (mystate[12] < g - var_mov)
    var = var_mov;
  else if (mystate[12] > g + var_mov)
    var = -var_mov;
  else
    var = 0;

  for (int k = 0; k < 162; k++) // massimo cambiamento che può fare es: da 10 può passare massimo a 172 (per ridurre i cicli)
    if (!mysequalg(mystate[12], var, g))
    {
      s[12].write(mystate[12] + var);
      delay(delay_mov);
      mystate[12] += var;
    }
}

// myst equal g
bool mysequalg(int mys, int varr, int gg) // da leggere myst equal g (mystate confrontato con g per un ulteriore controllo)
{
  if (varr < 0) // se muovo servomotori indietro
  {
    if (mys <= gg) // e se la mia pos attuale è <= della pos da raggiungere
      return true;
    else
      return false;
  }
  else // se muovo servomotori avanti
  {
    if (mys >= gg) // e se la mia pos attuale è >= della pos da raggiungere
      return true;
    else
      return false;
  }
}

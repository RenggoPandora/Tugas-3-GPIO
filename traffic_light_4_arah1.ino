// BARAT
int B_M = 2;
int B_K = 3;
int B_H = 4;

// TIMUR
int T_M = 5;
int T_K = 6;
int T_H = 7;

// SELATAN
int S_M = 8;
int S_K = 9;
int S_H = 10;

// UTARA
int U_M = 11;
int U_K = 12;
int U_H = 13;

void setup() {
  pinMode(B_M, OUTPUT); pinMode(B_K, OUTPUT); pinMode(B_H, OUTPUT);
  pinMode(T_M, OUTPUT); pinMode(T_K, OUTPUT); pinMode(T_H, OUTPUT);
  pinMode(S_M, OUTPUT); pinMode(S_K, OUTPUT); pinMode(S_H, OUTPUT);
  pinMode(U_M, OUTPUT); pinMode(U_K, OUTPUT); pinMode(U_H, OUTPUT);
}

void loop() {
  aktifkanSimpang(U_M, U_K, U_H); // Utara
  aktifkanSimpang(T_M, T_K, T_H); // Timur
  aktifkanSimpang(S_M, S_K, S_H); // Selatan
  aktifkanSimpang(B_M, B_K, B_H); // Barat
}

// ===== FUNGSI UTAMA =====
void aktifkanSimpang(int merah, int kuning, int hijau) {
  semuaMerah();

  digitalWrite(merah, LOW);
  digitalWrite(hijau, HIGH);
  delay(5000); // hijau 5 detik

  digitalWrite(hijau, LOW);
  kedipKuning(kuning);

  digitalWrite(kuning, LOW);
  digitalWrite(merah, HIGH);
}

// ===== KUNING KEDIP 3x (2 detik) =====
void kedipKuning(int pinKuning) {
  for (int i = 0; i < 3; i++) {
    digitalWrite(pinKuning, HIGH);
    delay(333);
    digitalWrite(pinKuning, LOW);
    delay(333);
  }
}

// ===== KONDISI DEFAULT =====
void semuaMerah() {
  digitalWrite(B_M, HIGH);
  digitalWrite(T_M, HIGH);
  digitalWrite(S_M, HIGH);
  digitalWrite(U_M, HIGH);

  digitalWrite(B_K, LOW); digitalWrite(B_H, LOW);
  digitalWrite(T_K, LOW); digitalWrite(T_H, LOW);
  digitalWrite(S_K, LOW); digitalWrite(S_H, LOW);
  digitalWrite(U_K, LOW); digitalWrite(U_H, LOW);
}
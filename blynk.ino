#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C untuk LCD

const int sensorPin = 2;  // Pin untuk sensor infrared
int count = 0;  // Variabel untuk menyimpan jumlah barang
bool objectDetected = false;  // Variabel untuk menandai apakah objek telah terdeteksi

void setup() {
  lcd.init();  // Inisialisasi LCD
  lcd.backlight();  // Nyalakan backlight LCD
  pinMode(sensorPin, INPUT);  // Atur pin sensor sebagai input
  lcd.print("Jumlah: ");  // Tampilkan teks awal di LCD
  lcd.setCursor(8, 0);  // Pindah kursor ke posisi 8, baris 1
  lcd.print(count);  // Tampilkan jumlah awal di LCD
}

void loop() {
  if (digitalRead(sensorPin) == LOW && !objectDetected) {  // Jika sensor mendeteksi objek dan belum mendeteksi sebelumnya
    count++;  // Tambahkan jumlah barang
    updateLCD();  // Update tampilan LCD
    objectDetected = true;  // Set objek telah terdeteksi
    delay(3000);  // Tunda eksekusi selama 15 detik
    objectDetected = false;  // Set objek tidak lagi terdeteksi setelah 15 detik
  }
}

void updateLCD() {
  lcd.setCursor(8, 0);  // Pindah kursor ke posisi 8, baris 1
  lcd.print("   ");  // Hapus jumlah sebelumnya
  lcd.setCursor(8, 0);  // Kembali ke posisi 8, baris 1
  lcd.print(count);  // Tampilkan jumlah terbaru
}

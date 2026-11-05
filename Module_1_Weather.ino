#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite canvas = TFT_eSprite(&tft);  

int x[50];
int y[50];

void setup() {
  tft.init();
  tft.setRotation(1);
  canvas.createSprite(240, 135);

  // start every drop at a random spot
  for (int i = 0; i < 50; i++) {
    x[i] = random(240);
    y[i] = random(135);
  }
}

void loop() {
  
  bool snowing = false;
  if ((millis() / 10000) % 2 == 1) {
    snowing = true;
  }

  // Sky
  if (snowing) {
    canvas.fillSprite(TFT_LIGHTGREY);
  } else {
    canvas.fillSprite(TFT_NAVY);
  }

  // move and draw each drop
  for (int i = 0; i < 50; i++) {
    if (snowing) {
      y[i] = y[i] + 1; // snow falls slowly
      x[i] = x[i] + random(-1, 2); // and drifts left/right
      canvas.fillCircle(x[i], y[i], 2, TFT_WHITE);
    } else {
      y[i] = y[i] + 5; // rain falls fast
      canvas.drawLine(x[i], y[i], x[i], y[i] + 5, TFT_BLUE);
    }

    if (y[i] > 135) {
      y[i] = 0;
      x[i] = random(240);
    }
  }

  // ground
  if (snowing) {
    canvas.fillRect(0, 120, 240, 15, TFT_WHITE);
  } else {
    canvas.fillRect(0, 120, 240, 15, TFT_DARKGREEN);
  }

  canvas.pushSprite(0, 0); 
  delay(20);
}
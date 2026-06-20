# Servo Motor Control with Potentiometer — Arduino

A project that controls a servo motor's position using a potentiometer. Rotating the knob maps the analog input (0–1023) directly to the servo angle (0°–180°). Built and simulated in [Tinkercad Circuits](https://www.tinkercad.com/).

---

## 📸 Circuit Photo

<!-- Replace the path below with your actual Tinkercad screenshot -->
![Circuit Screenshot](https://github.com/user-attachments/assets/2152b305-c081-4ebb-a60c-6b87ac02f348
)

---

## ⚙️ How It Works

1. The **potentiometer** outputs an analog voltage read on pin **A0** (value range: 0–1023)
2. The value is mapped to a servo angle between **0° and 180°** using `map()`
3. The **servo motor** instantly moves to the corresponding angle
4. This repeats every **15ms** for smooth, responsive control

---

## 🔧 Components Used

| Component              | Quantity |
|-----------------------|----------|
| Arduino Uno            | 1        |
| Servo Motor (SG90 or similar) | 1 |
| Potentiometer (10kΩ)   | 1        |
| Breadboard             | 1        |
| Jumper Wires           | Several  |

---

## 🔌 Pin Connections

### Servo Motor → Arduino

| Servo Wire | Function      | Arduino Pin |
|------------|---------------|-------------|
| Orange / Yellow | Signal   | D9 (PWM)    |
| Red        | Power (5V)    | 5V          |
| Brown / Black | Ground    | GND         |

### Potentiometer → Arduino

| Pot Pin    | Function      | Arduino Pin |
|------------|---------------|-------------|
| Left leg   | Ground        | GND         |
| Middle (wiper) | Signal    | A0          |
| Right leg  | Power         | 5V          |

---

## 💻 Code

```cpp
#include <Servo.h>

Servo servo1;   // Create object for Servo motor 1
int angle = 0;  // Variable to store the position

void setup() {
  servo1.attach(9); // Attach servo to pin 9
}

void loop() {
  int potValue = analogRead(A0);            // Read analog value from potentiometer (0–1023)
  angle = map(potValue, 0, 1023, 0, 180);   // Map to servo angle range (0°–180°)
  servo1.write(angle);                      // Set servo position
  delay(15);                                // Short delay for stability
}
```

---

## 📦 Library Required

The `Servo` library is **built into the Arduino IDE** — no installation needed.

---

## ▶️ How to Run

**In Tinkercad:**
1. Open the [Tinkercad project](https://www.tinkercad.com/) *(replace with your share link)*
2. Click **Start Simulation**
3. Drag the potentiometer knob and watch the servo arm rotate in real time

**On a real Arduino:**
1. Open `servo_moter1.ino` in the [Arduino IDE](https://www.arduino.cc/en/software)
2. Select **Board:** Arduino Uno and the correct **Port**
3. Click **Upload**
4. Turn the potentiometer knob to control the servo angle

---

## 📁 Project Structure

```
├── servo_moter1.ino   # Arduino source code
├── assets/
│   └── circuit.png   # Tinkercad circuit screenshot
└── README.md
```

String data = "CO=5650, SO2=978, NO=0, _O2=19.95, NO2=10";

void setup() {
  Serial.begin(115200);
  for (int i = 2; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

// CO, NO, dải là 0 đến 2000PPM, SO2 0 đến 1000ppm, NO2 là 0 đến 500ppm, O2 0 đến 22%
void loop() {
  // Your code here
  delay(1000); // Delay for serial initialization
  if (Serial.available() > 0) {
    String send_data = Serial.readString();
    int co = getValue(send_data, "CO=");
    int so2 = getValue(send_data, "SO2=");
    int no = getValue(send_data, "NO=");
    int o2 = getValue(send_data, "_O2=");
    int no2 = getValue(send_data, "NO2=");

    Serial.println(
     "co=" + String(co) +
     "so2=" + String(so2) +
     "no=" + String(no) +
     "o2=" + String(o2) +
     "no2=" + String(no2)
    );
    analogWrite(2, co);
    analogWrite(3, so2);
    analogWrite(4, no);
    analogWrite(5, o2);
    analogWrite(6, no2);
  }
//  Serial.println(data);

}

int getValue(String data, String parameter) {
  int startIndex = data.indexOf(parameter);
  if (startIndex != -1) { // If parameter is found
    startIndex += parameter.length(); // Move index to the start of value
    int endIndex = data.indexOf(',', startIndex); // Find the end index of the value
    if (endIndex == -1) { // If comma not found, consider until the end of string
      endIndex = data.length();
    }
//    Serial.println(startIndex);
//    Serial.println(endIndex);
    String valueString = data.substring(startIndex, endIndex);
//    Serial.println(valueString);
    int value = valueString.toInt(); // Convert string to float
    // Serial.print(parameter);
    // Serial.println(value);
    return value;
  }
}


// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings

#define BLYNK_TEMPLATE_ID "TMPL7UbyFHbc"
#define BLYNK_DEVICE_NAME "led"
#define BLYNK_AUTH_TOKEN "x1Yi-BNq7yu8qqbvFE0P2AUFNZvoLVd5"

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <ESP8266_Lib.h>

#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Harsh";
char pass[] = "12345678";

BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  Serial.println("Light function");
// Set incoming value from pin V0 to a variable
  int value = param.asInt();
// Update state
  if(value == 1)
    digitalWrite(D5,LOW);
  else
    digitalWrite(D5,HIGH);
}

BLYNK_WRITE(V1)
{
  Serial.println("Fan function");
// Set incoming value from pin V1 to a variable
  int value = param.asInt();
// Update state
  if(value == 1)
    digitalWrite(D6,LOW);
  else
    digitalWrite(D6,HIGH);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  //  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}

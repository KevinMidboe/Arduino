#include <SPI.h>
#include <Ethernet.h>
#include <Servo.h>

byte mac[] = {
	0x90, 0xA2, 0xDA, 0x0D, 0xA7, 0x51};

IPAddress ip(10,0,0,5);
EthernetServer server(81);

int relayPins[] = {7, 6, 5, 4};
int buttonPins[] = {8, 9, 10, 11, 12, 13};
int relayState[] = {0, 0, 0, 0};
int buttonState = 0;

Servo speakerServo;

String readString = String(100);

void setup()
{
	Serial.begin(9600);
	for (int i = 0; i < 6; i++)
	{
		Serial.println("RUN");
		if (i < 4)
			pinMode(relayPins[i], OUTPUT);
		pinMode(buttonPins[i], INPUT_PULLUP);
	}

	speakerServo.attach(3);

	Serial.println(F("Initialaizing ethernet..."));
	Ethernet.begin(mac, ip);

	delay(1000);

	server.begin();
	Serial.print(F("Kevin's RelayController ready at: "));
	Serial.println(Ethernet.localIP());
}

void loop()
{
	int cmd = 0;
	boolean done = false;

	//checkButtons();

	EthernetClient client = server.available();

	if (client)
	{
		Serial.println(F("new client"));
		readString = "";

		while (client.connected())
		{
			if (client.available())
			{
				char c = client.read();
				Serial.write(c);
				if (readString.length() < 100)
					readString += (c);

				// Check serverInputs
				if (c == '\n')
				{
					if (readString.indexOf("GET") != -1)
					{
						if (readString.indexOf("?1") != -1)
							cmd = 1;
						if (readString.indexOf("?2") != -1)
							cmd = 2;
						if (readString.indexOf("?3") != -1)
							cmd = 3;
						if (readString.indexOf("?4") != -1)
							cmd = 4;
						if (readString.indexOf("?5") != -1)
							cmd = 5;
						if (readString.indexOf("?6") != -1)
							cmd = 6;
						if (readString.indexOf("?7") != -1)
							cmd = 7;
						if (readString.indexOf("?8") != -1)
							cmd = 8;
						if (readString.indexOf("?9") != -1)
							cmd = 9;
						if (readString.indexOf("?10") != -1)
							cmd = 10;
					}
					//Serial.println(cmd);
					if (readString.length() >= 2)
					{
						changeState(cmd);
						Serial.println(F("Sending web page"));
						SendWebPage(client);
						Serial.println(F("Web page sent!"));
						cmd = 0;
						break;
					}
					readString = "";
				}
			}
		}
		Serial.println(F("Delay before disconnecting"));
		delay(50);
		client.stop();
		Serial.println(F("Client disconnected"));
	}
}

void changeState(int n)
{
	Serial.println(n);
	if (n > 0 && n <= 4)
	{
		Serial.println(F("Activate Button"));
		digitalWrite(relayPins[n - 1], HIGH);
	}
	else if (n > 4 && n <= 8)
	{
		Serial.println(F("Activate Button"));
		digitalWrite(relayPins[n - 5], LOW);
	}
	else if (n == 9)
	{
		Serial.println(F("Activate Button"));
		speakerServo.write(156);
		delay(500);
		speakerServo.write(140);
	}
	else if (n == 10)
	{
		Serial.println(F("Activate Button"));
		// Do something
	}
}

void checkButtons()
{
	for (int i = 0; i < 6; i++)
	{
		buttonState = digitalRead(buttonPins[i]);
    if (buttonState == LOW)
    {
      switch (i)
      {
        case 4:
          //
          break;
        case 3:
          // Turn on the servo for speaker
          speakerServo.write(156);
          delay(500);
          speakerServo.write(140);
          break;
        default:
          relayChange(i);
          break;
      }
    }
    while (buttonState == LOW)
    {
      delay(50);
      buttonState = digitalRead(buttonPins[i]);
    }
	}
}

void relayChange(int i)
{
  if (relayState[i] == 0)
  {
    digitalWrite(relayPins[i], HIGH);
    relayState[i] = 1;
  }
  else
  {
    digitalWrite(relayPins[i], LOW);
    relayState[i] = 0;
  }
}

void SendWebPage(EthernetClient client)
{
	client.println(F("HTTP/1.1 200 OK"));
	client.println(F("Content-Type: text/html"));
	client.println(F("Connection: close"));
	client.println();
	client.println(F("<!DOCTYPE HTML>"));
	client.println(F("<html>"));
	client.println(F("<head>"));
	client.println(F("<meta name=\"viewport\" content=\"width=370\">"));
	client.println(F("<link rel=\"apple-touch-icon\" href=\"http://i.imgur.com/zOjuLwC.png\"/>"));
	client.println(F("<link href='http://fonts.googleapis.com/css?family=Pontano+Sans' rel='stylesheet' type='text/css'>"));
	client.println(F("<title>RelayController</title>"));
	client.println(F("<style type='text/css'>"));
	client.println(F(".label {display:label; color: white; font-size: 30px; font-family: 'Pontano Sans', sans-serif; text-align:center;}"));
	client.println(F("button {position: relative; vertical-align: top; width: 140px; height: 60px; padding: 0; font-size: 22px; color: white; text-align: center; text-shadow: 0 1px 2px rgba(0, 0, 0, 0.25); background: #e74c3c; border: 0; border-bottom: 2px solid #c0392b; cursor: pointer; -webkit-box-shadow: inset 0 -2px #c0392b; box-shadow: inset 0 -2px #c0392b;}"));
	client.println(F("</style>"));
	client.println(F("<script type ='text/javascript'>"));
	client.println(F("function OnButtonClicked(parm) { window.location.href=\"X?\" + parm; }"));
	client.println(F("</script>"));
	client.println(F("<body style=\"background-color:#1b354f\">"));
	client.println(F("<div class=\"label\">"));
	client.println(F("<br/>RelayController<br/><br/>"));

	// Buttons
	if (digitalRead(relayPins[0]) == LOW)
		client.println(F("<button onclick=\"OnButtonClicked('1');\">1ON</button>"));
	else
		client.println(F("<button onclick=\"OnButtonClicked('5');\">1OFF</button>"));
	if (digitalRead(relayPins[1]) == LOW)
		client.println(F("<button onclick=\"OnButtonClicked('2');\">2ON</button><br/><br/>"));
	else
		client.println(F("<button onclick=\"OnButtonClicked('6');\">2OFF</button><br/><br/>"));
	if (digitalRead(relayPins[2]) == LOW)
		client.println(F("<button onclick=\"OnButtonClicked('3');\">3ON</button>"));
	else
		client.println(F("<button onclick=\"OnButtonClicked('7');\">3OFF</button>"));
	if (digitalRead(relayPins[3]) == LOW)
		client.println(F("<button onclick=\"OnButtonClicked('4');\">4ON</button><br/><br/>"));
	else
		client.println(F("<button onclick=\"OnButtonClicked('8');\">4OFF</button><br/><br/>"));

	client.println(F("<button onclick=\"OnButtonClicked('9');\">5</button>"));
	client.println(F("<button onclick=\"OnButtonClicked('10');\">6</button><br/><br/>"));

	client.println(F("</div>"));
	client.println(F("</body>"));
	client.println(F("</html>"));
	client.println("");
}


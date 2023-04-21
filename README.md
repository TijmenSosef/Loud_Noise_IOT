# Loud noise detection

This project gives a way to detect loud noises with an ESP and a sound sensor.

WARNING:
It does not work perfectly and there are better ways to do this.

## Requirements
- ESP8266 12-E
- 3 x female to female cables
- KY-037 MICROPHONE SOUND SENSOR
- Arduino IDE
- IFTTT acount

# Installation
## Getting started
### IFTTT
In this project I use IFTTT to get push notifications on my phone.

1. goto the IFTTT website https://ifttt.com and make sure you are logged in.

3. Goto my **Create**.

![image](https://user-images.githubusercontent.com/73581008/233634681-c0bbd272-1fb8-4b5f-a97a-cc839699877f.png)

3. Then click **Add** and search for **webhooks**.

![image](https://user-images.githubusercontent.com/73581008/233634909-92d79c9e-561d-4f26-a1ec-f920c20ac9fd.png)

4. Select **Receive a web reqeust**.

![image](https://user-images.githubusercontent.com/73581008/233635124-0e3fd532-2ef5-49ca-a6a6-80010e5435df.png)

5. Enter a event name that is easy to remember (I recommend using the same one I use) and click **create trigger**.

![image](https://user-images.githubusercontent.com/73581008/233635824-382e41c6-29ac-4984-ba4f-e76969e07bbf.png)

6. click **Add** again and search for **notifications**.

![image](https://user-images.githubusercontent.com/73581008/233636794-106bc81a-6d21-4142-b9a0-b81b79fd075d.png)

7. Select **Send a notification from the IFTTT app**

![image](https://user-images.githubusercontent.com/73581008/233637444-dadabec6-305e-4e89-813d-b56ecd4463c9.png)

8. Enter the message you'd like to receive on your phone once a loud noice is detected and click **Create action**.

![image](https://user-images.githubusercontent.com/73581008/233637745-96071f79-24f8-460a-9757-b634f3bc12ce.png)

9. To finish click **Continue** and **Finish**.

### ESP and sound sensor

1. the ESP should be connected to sound senser

The contacts that should be conected (in order from ESP to sound sensor)
3.3V -> +
GND -> G
A0 -> A0

![image](https://user-images.githubusercontent.com/73581008/233642282-f00ea8ce-7766-43cc-b6e2-2bcf8df7279a.png)

2. You can connect the ESP to your computer and upload the code using the ARDUINO IDE https://www.arduino.cc/en/software and select the option you need from the **Download options** list

![image](https://user-images.githubusercontent.com/73581008/233642712-4c28919f-f9e4-402c-83ba-699ad7e7a4b9.png)

3. Once installed you need to download the arduino support to connect your ESP.

only follow the section **Installing using Arduino IDE**
https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html

4. Now make sure to connect to the ESP by pressing the box in the top left and select the propper ESP and Port.

![image](https://user-images.githubusercontent.com/73581008/233644882-9558c55c-49c9-4c5e-a2b1-ab125413c47f.png)


![image](https://user-images.githubusercontent.com/73581008/233644771-0c32608b-8a8d-49ec-9a7e-a575a1b3b45c.png)

5. Paste the code from loud_noise_iot.ino into the IDE and change all the settings to your need.

6. Upload the code to your ESP.

7. Play around with the settings and the screw on sensor until you find a sensitivity that suits your needs.


### Features
- push notification to your phone
- Detecting loud noises 

### Usage
Once everything is up and running you can place it somewhere you'd like to detect loud noises.

### License
This project is licensed under the MIT License - see the LICENSE file for details.

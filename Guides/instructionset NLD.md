# Landje Robot Instructieset


De Landje robot heeft zijn eigen set van opdrachten die je hem kunt geven, een instructie-set.
Met deze instructies kun je de robot eenvoudig besturen.

Elke programma voor een Landje Robot moet beginnen met de volgende instructies. Deze instructies hoef je niet te begrijpen.

```
#include <LandjeRobot.h>// Aansluitingen van de robot.const int motor[2][4] = {  {2, 3, 4, 5}, {6, 7, 8, 9}} ;// Aansluitingen van de lijn sensorenconst int lineSensors[2] = { 10, 11 } ;const bool lineSensorInverse = false ;// Omtrek van de wielen in cmconst int wheelRadiusMM = 21 ;// Afstand tussen de wielen in cmconst int trackWidthMM = 55 ;// Aansluiting van de ultrasoon sensor// Ultrasoon sensor meet de afstandint ultraPin = 13 ;// Aansluiting van de servo// De servo motor beweegt het hoofd van links naar rechtsint servoPin = 14 ;// Aansluiting van het led // Lampje in de mond van de robotint mouthledPin = 15 ;// Aansluiting van de mode schakelaarint switchPin = 0 ;LandjeRobot landjerobot(motor, LandjeRobotMotorController::STEPMODE::FULL_STEP, wheelRadiusMM , trackWidthMM, lineSensors, lineSensorInverse, ultraPin, servoPin, mouthledPin, switchPin) ;```

Deze instructies moeten voor de functie *setup()* in het programma geplaatst worden. Knip en plak deze instructies voor aan ieder programma dat je voor de robot schrijft.


## De robot instructie set             

De Landje robot heeft verschillende eigen instructies. Je hebt instructies om te bewegen, te draaien of bijvoorbeeld om de afstand te meten. Deze instructies geeft je aan de Landje Robot die deze instructies dan weer opvolgd. In het eerste gedeelte van het programma zie je als laatste regel staan. 

`LandjeRobot landjerobot(motor, LandjeRobotMotorController::STEPMODE::FULL_STEP, wheelRadiusMM ,
trackWidthMM, lineSensors, lineSensorInverse, ultraPin, servoPin,mouthledPin) ;`

Met deze lange instructie wordt de robot ingesteld. Na het uitvoeren van deze regel kun je de variabele `landjerobot` gebruiken om instructies voor de robot te geven. Je geeft een instructie door aan de variabele `landjerobot` de instructie te plakken. Je plakt een instructie aan landjerobot door middel van een punt. Bijvoorbeeld;   

`landjerobot.talk(5) ;` 

Het plakken van een instructie heet een instructie *geven*. Als er dus ergens staat '*geef de instructie move*' programmeer je dus `landjerobot.move()'. In de volgende paragraaf staan alle speciale instructies die de Landje robot begrijpt. 

### De Landje robot instructieset

De Landje robot heeft verschillende instructies. Bij sommige instructies kun of moet je iets extra's aan de instructie vertellen. Als je de robot wilt laten bewegen kun je bijvoorbeeld vertellen welke richting hij moet op rijden. Het iets extra's vertellen aan een instructie noemen we *doorgeven*. Je *geeft* dus aan de instructie `move` *door* welke richting hij op moet rijden.

`landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ; `

Met `LandjeRobot::DIRECTION::FORWARD` geeft je aan de landjerobot door dat hij vooruit moet bewegen. Het engelse woord `FORWARD` betekent vooruit, `DIRECTION` betekent richting. Je vertelt `LandjeRobot` robot dus dat hij in de `DIRECTION` `FORWARD` moet bewegen. Je zult in andere instructies zien dat de robot kan draaien (`TURN`) naar links (`LEFT`) en rechts (`RIGHT`) of kan kijken (`LOOK`). 

Wat je aan de robot doorgeeft heet *parameter*. Aan elke instructie kan geen, één of meerdere parameters worden doorgegeven. Hoeveel en welke parameters je kan doorgeven verschilt per instructie.

Bij sommige instructies mag je sommige parameters opgegeven, maar hoeft dit niet. Als je de instructie `move` opgeeft mag je de parameter *wachten* opgeven, maar het hoeft niet. Je mag dus de instructie `landerobot.move(LandjeRobot::DIRECTION::FORWARD,10)` geven maar ook `landerobot.move(LandjeRobot::DIRECTION::FORWARD)`. Bij de eerste instructie zal de robot 10 centimeter vooruit gaan rijden. Bij de tweede instructie zal de robot net zolang vooruit blijven rijden totdat je de instructie geeft om te stoppen. Als je een parameter niet opgeeft zal een waarde gekozen worden. Deze gekozen waarde noemt men de standaard waarde. Voor de parameter *afstand* is dit oneindig (∞). 

Als je in deze handleiding de parameter voor instructies opzoekt is er één waarde voor een parameter _onderstreept_. Dit is de waarde welke voor de parameter gekozen zal worden als je de parameter niet doorgeeft aan de instructie. Kijk eens bij de instructie *move*, daar staat dat de waarde '∞' onderstreept. Het teken '∞' betekend oneindig. Als je de parameter *afstand* niet opgeeft blijft de robot oneindig doorrijden.

Instructies kunnen ook een waarde teruggeven. Als een instructie een waarde teruggeeft staat dit bij de instructie vermeld. De instructie *doIMove* heeft geen parameters, maar geeft wel een waarde terug. Als de robot beweegt krijg je *true*, anders *false*.
   
### Instructies

#### move

**Omschrijving**

Laat de robot in een richting bewegen

**Syntax**

move( richting ) ;   
move( richting , afstand) ;   
move( richting , afstand, wachten) ;


**Parameters**

|Parameter|Type|Waarden|Opmerkingen|
|:--------|:---|:------|:----------|
| richting | | LandjeRobot::DIRECTION::STOP </br>LandjeRobot::DIRECTION::FORWARD</br>LandjeRobot::DIRECTION::BACKWARD | |
| afstand |int| 0.._∞_| De afstand die bewogen moet worden in centimeters |
| wachten |bool| true</br>_false_ | Wacht (true) met het uitvoeren van de volgende instructie totdat de opgegeven afstand is afgelegd |

        
**Geeft terug**

niets

**Voorbeeld**

```
// beweeg de robot vooruit
landjerobot.beweeg(LandjeRobot::DIRECTION::FORWARD) ;

// beweeg de robot 10cm achteruit
landjerobot.beweeg(LandjeRobot::DIRECTION::BACKWARD,10) ;

// beweeg de robot 20cm vooruit en wacht 
// totdat de opgegeven afstand is afgelegd
landjerobot.beweeg(LandjeRobot::DIRECTION::FORWARD,20,true) ;

```

#### doIMove

**Omschrijving**

Geeft aan of de robot beweegt.

**Syntax**

doIMove() ;   

**Parameters**

geen
        
**Geeft terug**

|Type|Waarde|Opmerkingen|
|:--------|:--------|:------|
|bool| true | Deze waarde wordt teruggegeven als de robot aan het bewegen is |
|bool| false | Als de robot niet beweegt wordt deze waarde teruggeveven |

**Voorbeeld**

```
// beweeg de robot vooruit
landjerobot.move(LandjeRobot::DIRECTION::FORWARD) ;

if (doIMove()) {
    Serial.println("Ik beweeg!") ;
}

```


#### turn

**Omschrijving**

Laat de robot in een bepaalde richting draaien 

**Syntax**

turn( richting ) ;   
turn( richting , hoek) ;   
turn( richting , hoek, wachten) ;


**Parameters**

|Parameter|Type|Waarden|Opmerkingen|
|:--------|:---|:------|:----------|
| richting | | LandjeRobot::TURN::STRAIGHT</br>LandjeRobot::TURN::LEFT</br>LandjeRobot::TURN::RIGHT | De draairichting van de robot. De waarde STRAIGHT laat de robot weer recht voor- of achteruit rijden |
| hoek |int| 0..360 </br>_90_| Het aantal graden dat de robot moet draaien. Een hoek van 90 graden is een rechte hoek |
| wachten |bool| true</br>_false_ | Wacht (true) met het uitvoeren van de volgende instructie totdat de opgegeven afstand is afgelegd |

**Draairichtingen van de robot**
<img src="./instruction manual/img_2.png" width="640">
        
**Geeft terug**

niets

**Voorbeeld**

```
// draai de robot naar links
landjerobot.draai(LandjeRobot::TURN::LEFT) ;

// laat de robot een rondje rechtsom draaien
landjerobot.draai(LandjeRobot::TURN::RIGHT,360) ;

```


#### look

**Omschrijving**

Laat de robot in een richting kijken

**Syntax**

look( richting ) ;   


**Parameters**

|Parameter|Type|Waarden|Opmerkingen|
|:--------|:---|:------|:----------|
| richting | | LandjeRobot::LOOK::FORWARD</br>LandjeRobot::LOOK::LEFT</br>LandjeRobot::LOOK::RIGHT</br>LandjeRobot::LOOK::FAR\_LEFT</br>LandjeRobot::LOOK::FAR\_RIGHT | |

   
   

**Kijkrichtingen van de robot**
<img src="./instruction manual/img_1.png" width="640">

        
**Geeft terug**

niets

**Voorbeeld**

```
// Kijk naar links
landjerobot.look(LandjeRobot::LOOK::LEFT) ;
```

#### talk

**Omschrijving**

Laat de robot 'praten' door een lichtje in de mond te laten knipperen.

**Syntax**

talk( duur ) ;   


**Parameters**

|Parameter|Type|Waarden|Opmerkingen|
|:--------|:---|:------|:----------|
| duur | int | 0..∞ | Aantal seconden dat de robot 'praat'|

        
**Geeft terug**

niets

**Voorbeeld**

```
// Praat 7 seconden
landjerobot.talk(7);
```

#### doITalk

**Omschrijving**

Geeft aan of de robot aan het praten is.

**Syntax**

doITalk() ;   

**Parameters**

geen
        
**Geeft terug**

|Type|Waarde|Opmerkingen|
|:--------|:--------|:------|
|bool| true | Deze waarde wordt teruggegeven als de robot aan het praten is |
|bool| false | Als de robot niet praat wordt deze waarde teruggeveven |

**Voorbeeld**

```
// Laat de robot praten
landjerobot.talk(60) ;

if (doITalk()) {
    Serial.println("Ik praat!") ;
}

```



#### mouthClosed

**Omschrijving**

Laat de robot zijn mond 'dicht' doen door het led-je uit te zetten

**Syntax**

mouthClosed() ;   


**Parameters**

geen
        
**Geeft terug**

niets

**Voorbeeld**

```
// Laat de robot zijn mond dicht doen
landjerobot.mouthClosed();
```

#### mouthOpen

**Omschrijving**

Laat de robot zijn mond 'open' doen door het led-je aan te zetten

**Syntax**

mouthOpen() ;   


**Parameters**

geen
        
**Geeft terug**

niets

**Voorbeeld**

```
// Laat de robot zijn mond open doen
landjerobot.mouthOpen();
```



#### measureDistance

**Omschrijving**

Meet de afstand van de robot tot een ander object

**Syntax**

measureDistance() ;   

**Parameters**

geen
        
**Geeft terug**

|Type|Waarde|Opmerkingen|
|:--------|:--------|:------|
|int| 2..400 | Afstand in centimeters |


**Voorbeeld**

```
int gemetenAfstand = 0 ;
// Meet de afstand van de robot tot een ander object
gemetenAfstand  = landjerobot.measureDistance() ;

Serial.print("Gemeten afstand ") ;
Serial.print(gemetenAfstand) ;
Serial.println(" cm") ;

```

#### detectLine

**Omschrijving**

Geeft aan of er een lijn wordt gedetecteerd

**Syntax**

detectLine() ;   

**Parameters**

geen
        
**Geeft terug**

|Type|Waarde|Opmerkingen|
|:--------|:--------|:------|
|| LandjeRobot::LINE::NONE</br>LandjeRobot::LINE::LEFT</br> LandjeRobot::LINE::RIGHT</br> LandjeRobot::LINE::BOTH | NONE geeft aan dat er geen lijn gedetecteerd wordt. Bij BOTH wordt zowel links als rechts een lijn gedetecteerd |


**Voorbeeld**

```

if (detectLine() != LandjeRobot::LINE::NONE) {
    Serial.println("Er is een lijn gedetecteerd") ;
}

```


## Arduino instructies

#### delay

**Omschrijving**

Wacht een aantal milliseconden. Duizend (1000) milliseconden is gelijk aan 1 seconde.

**Syntax**

delay( duur ) ;   

**Parameters**

|Parameter|Type|Waarden|Opmerkingen|
|:--------|:---|:------|:----------|
| duur | int | 0..∞ | Aantal milliseconden dat er gewacht wordt.|

        
**Geeft terug**

niets

**Voorbeeld**

```
// Wacht twee seconden
delay(2000) ; 
```

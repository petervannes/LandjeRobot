# Studenten Handboek Oplossingen

## Les 3, variabelen

### Opdracht 1

Maak drie variabelen en druk deze af

    /*
    

### Opdracht 1

    /*
    
    
### Opdracht 2  
    
    /*
    
    
    /*

### Opdracht 4
    
    /*
      
      Serial.println(klein >= klein);
      Serial.println(groot <= groot);
      Serial.println(klein >= groot);
      Serial.println(groot <= klein);
    }
    
    /*
      
      Serial.println(klein >= klein);
      Serial.println(groot <= groot);
      Serial.println(klein >= groot);
      Serial.println(groot <= klein);
      Serial.println(klein != klein);    
      Serial.println(klein != groot);          
    
    
## Les 5, voorwaardelijke statements

### Opdracht 1

    /*
    
### Opdracht 2

    /*
        Serial.println("klein is groter dan groot");      
      }
    
## Les 6, Herhalingen 

### Opdracht 1

Het juiste antwoord is 9x
    
    getal 1
    "Dit herhaal ik" 
    getal 2
    "Dit herhaal ik" 
    getal 3
    "Dit herhaal ik" 
    getal 4
    "Dit herhaal ik" 
    getal 5
    "Dit herhaal ik" 
    getal 6
    "Dit herhaal ik" 
    getal 7
    "Dit herhaal ik" 
    getal 8
    "Dit herhaal ik" 
    getal 9
    "Dit herhaal ik" 
    getal 10


### Opdracht 2

    /*
    
    
## Les 7, Debuggen

### Opdracht 1

### Opdracht 2

    /*
    
    */
    
    void setup() {
      
      Serial.begin(9600);
      delay(2000);
      
      Serial.println("Gaat het wel goed?");
        
    }
    
    void loop() {
        
    }
    
    
### Opdracht 3

#### Oplossing 1

    void setup() {
      Serial.begin(9600);
      delay(2000);
      pinMode(A1,INPUT);
      randomSeed(analogRead(A1)); 
  
      int getal = 10;
      Serial.println("start getal");
      Serial.println(getal);
  
      int teller = random(1, 10);
      Serial.println("start teller");
      Serial.println(teller);
      
      while (getal != teller) {
        Serial.println("teller");
        Serial.println(teller);
        teller++;
      }
  
      Serial.println("Klaar!");
    
    }

    void loop() {
        
    }

#### Oplossing 2

    void setup() {
      Serial.begin(9600);
      delay(2000);
      pinMode(A1,INPUT);
      randomSeed(analogRead(A1)); 
  
      int getal = 5;
      Serial.println("start getal");
      Serial.println(getal);
  
      int teller = random(1, 5);
      Serial.println("start teller");
      Serial.println(teller);
      
      while (getal != teller) {
        Serial.println("teller");
        Serial.println(teller);
        teller++;
      }
  
      Serial.println("Klaar!");
    
    }

    void loop() {
        
    }
    
## Les 8, The Robot instructionset

### Opdracht 1

    void setup() {
    
### Opdracht 2

    void setup() {
    }
    
### Opdracht 3

    void setup() {
    
### Opdracht 4

Geen specifieke oplossing

### Opdracht 5

    void setup() {
    
## Les 9, Lijnen volgen 
    
### Opdracht 1

    void setup() {


    
### Opdracht 2

Als de robot met de linker of rechter sensor een lijn detecteert (ziet). Wacht dan even om te kijken of de status van de sensor wijzigt. Wanneer de robot bij de draai markerking een beetje schuint aankomt zal de status van de sensor dan wijzigen van `LandjeRobot::LINE::LEFT` of `LandjeRobot::LINE::RIGHT` naar `
LandjeRobot::LINE::BOTH`. Dus als je heel even wacht voordat je reageert op de status van een sensor, zal de draai markering juist gedetecteerd worden.

Hoe je dit moet gaan programmeren is onderdeel van de volgende opdracht.

### Opdracht 3

    void setup() {


### Opdracht 4

```
int mode = 0;
```


## Les 10, meer sensoren en motors

### Opdracht 1


```
void setup() {
```

```
void setup() {
    delay(2000);
    delay(2000);

```

### Opdracht 2

```
void setup() {
```

### Opdracht 3

Geluid verplaatst zich met een snelheid van 343 meter per seconde. Dus als het 12 seconden duurt voordat je de echt hoort heeft het geluid 343 * 12 of 4116 meter afgelegd. Maar het geluid moet zich verplaatsen naar de berg en weer terug. Daarom is de werkelijke afstand tot de berg 4116 meter gedeeld door 2. De afstand is dus 2058 meter of ongeveer 2km. 


### Opdracht 4


```

    int afstand = 400;
```



## Les 11, Een nieuw programma

### Opdracht 1

De oplossing is;

* Als de linker sensor een lijn detecteert, ga dan 10cm terug en draai 45 graden naar rechts. Ga dan verder vooruit.
* Als de rechter sensor een lijn detecteert, ga dan 10cm terug en draai 45 graden naar links. Ga dan verder vooruit.
* Als beide sensors een lijn detecteren, ga dan 10cm terug en draai 180 graden naar links of rechts. Ga dan verder vooruit.

### Opdracht 2

De robot moet vooruit gaan rijden als de mode witch op mode "2" is ingesteld en de robot wordt aangezet. Dus in de functie ```setup()``` moet een instructie toegevoegd worden zodat de robot vooruit gaat rijden.

Dit kan op twee manieren bereikt worden. Als eerste door een if-statement waardoor de robot vooruit gaat rijden als het in mode 2 staat.

```
void setup() {
    // Als schakelaar op "2" staat
    // Start met rijden als de robot aangezet wordt en
    // wacht niet
    landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
  }
```

Hetzelfde resultaat kan bereikt worden door uit het bestaande programma wat regels te verwijderen. Ongeacht in welke stand de mode schakelaar staat moet de robot vooruit gaan rijden.


```
void setup() {
  // wacht niet
```

### Opdracht 3

Dit is een basis versie van de programma regels om de robot binnen de lijnen te laten blijven rijden.

```
    // Als er niet niets (!) gedetecteerd wordt door de 
    // reflectie sensors doe dan iets
    if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {
    
      // wacht 30 milliseconden (0,03 seconde)
      delay(30);
    
      if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }

      if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      }

      if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, 180, true);
      }
      
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    } // einde if
```

Met de basis versie van de programma regels kan de robot in een eindeloze herhaling blijven hangen. Dezelfde beweging zal dan telkens herhaald worden. Dit kan vooral gebeuren wanneer de robot in een hoek van de lijnen beland. Door wat willekeur toe te voegen wordt dit probleem opgelost. 


```
    // Als er niet niets (!) gedetecteerd wordt door de 
    // reflectie sensors doe dan iets
    if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {
    
      // wacht 30 milliseconden (0,03 seconde)
      delay(30);
    
      if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, random(5,10), true);
        landjerobot.turn(LandjeRobot::TURN::RIGHT, random(20,90), true);
      }

      if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, random(5,10), true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, random(20,90), true);
      }

      if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, random(5,10), true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, random(160,200), true);
      }
      
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    } // einde if
```

### Opdracht 4

```
void setup() {

  // "Lees" de stand van de mode schakelaar
  mode = landjerobot.mode();

  // Laat de robot naar voren kijken
  landjerobot.look(LandjeRobot::LOOK::FORWARD);
  
  // Start met rijden als de robot aangezet wordt en
  // wacht niet
  landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
  
}
```

### Opdracht 5

```
    // Meet de afstand
    int afstand = landjerobot.measureDistance();

    // Stop als de afstand minder dan 10 cm is.
    if (afstand < 10) {
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
    }
```

### Opdracht 6

Naar welke richting wil je de robot sturen?; Naar links

Gebaseerd op afstand; De langst gemeten afstand.


```
    // Meet de afstand
    int afstand = landjerobot.measureDistance();

    // Stop als de afstand minder dan 10 cm is.
    if (afstand < 10) {
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
      
      // Meet afstand links van de robot
      landjerobot.look(LandjeRobot::LOOK::LEFT);
      delay(1000);
      int links = landjerobot.measureDistance();

      // Meet afstand rechts van de robot
      landjerobot.look(LandjeRobot::LOOK::RIGHT);
      delay(1000);
      int rechts = landjerobot.measureDistance();
      
      // Kijk weer naar voren
      landjerobot.look(LandjeRobot::LOOK::FORWARD);
      
      if (links > rechts) {
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      } else {
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }
      
      // Rijd weer vooruit
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    } // einde if 
  }
```
    
    
#Les 12, verbeteringen


## Opdracht 1

Wanneer de robot moet draaien, ga dan eerst een stukje achteruit om wat ruimte te maken zodat de robot vrij kan draaien.


```
    // Meet de afstand
    int afstand = landjerobot.measureDistance();

    // Stop als de afstand minder dan 10 cm is.
    if (afstand < 10) {
      // Stop met rijden
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
      
      // Meet afstand links van de robot
      landjerobot.look(LandjeRobot::LOOK::LEFT);
      delay(1000);
      int links = landjerobot.measureDistance();

      // Meet afstand rechts van de robot
      landjerobot.look(LandjeRobot::LOOK::RIGHT);
      delay(1000);
      int rechts = landjerobot.measureDistance();
      
      // Kijk weer naar voren
      landjerobot.look(LandjeRobot::LOOK::FORWARD);
      
      // Rij iets achteruit en draai naar links of rechts
      if (links > rechts) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      } else {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }
      
      // Rijd weer vooruit
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    } // einde if
  }
```

Of eenvoudiger geprogrammeerd met minder herhaling van programmaregels. Denk aan de DRY regel!

```
    // Meet de afstand
    int afstand = landjerobot.measureDistance();

    // Stop als de afstand minder dan 10 cm is.
    if (afstand < 10) {
      // Stop met rijden
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
      
      // Meet afstand links van de robot
      landjerobot.look(LandjeRobot::LOOK::LEFT);
      delay(1000);
      int links = landjerobot.measureDistance();

      // Meet afstand rechts van de robot
      landjerobot.look(LandjeRobot::LOOK::RIGHT);
      delay(1000);
      int rechts = landjerobot.measureDistance();
      
      // Kijk weer naar voren
      landjerobot.look(LandjeRobot::LOOK::FORWARD);
      
      // Rij iets achteruit
      landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
      
      // Draai naar links of rechts
      if (links > rechts) {
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      } else {
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }
      
      // Rijd weer vooruit
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    } // einde if
  }
```

## Opdracht 2

```
    // Meet de afstand
    int afstand = landjerobot.measureDistance();

    // Stop als de afstand minder dan 10 cm is.
    if (afstand < 10) {
    
      // Stop met rijden
      landjerobot.move(LandjeRobot::DIRECTION::STOP);
   
      // Mopper
      landjerobot.talk(5);
              
      // Meet afstand links van de robot
      landjerobot.look(LandjeRobot::LOOK::LEFT);
      delay(1000);
      int links = landjerobot.measureDistance();

      // Meet afstand rechts van de robot
      landjerobot.look(LandjeRobot::LOOK::RIGHT);
      delay(1000);
      int rechts = landjerobot.measureDistance();
      
      // Kijk weer naar voren
      landjerobot.look(LandjeRobot::LOOK::FORWARD);
      
      // Rij iets achteruit
      landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
      
      // Draai naar links of rechts
      if (links > rechts) {
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      } else {
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }
      
      // Rijd weer vooruit
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    } // einde if
  }
```
    
    
## Opdracht 3

```
    // Meet de afstand
    int afstand = landjerobot.measureDistance();

    // Stop als de afstand minder dan 10 cm is.
    if (afstand < 10) {
      
      // Controleer de gemeten afstand
      int totaalafstand = 0;
      for (int x=1; x<=5;x++) {
        totaalafstand = totaalafstand + landjerobot.measureDistance(); 
      }
      
      if (totaalafstand < 50) {
      
        // Stop met rijden
        landjerobot.move(LandjeRobot::DIRECTION::STOP);
        
        // Mopper
        landjerobot.talk(5);
      
        // Meet afstand links van de robot
        landjerobot.look(LandjeRobot::LOOK::LEFT);
        delay(1000);
        int links = landjerobot.measureDistance();
  
        // Meet afstand rechts van de robot
        landjerobot.look(LandjeRobot::LOOK::RIGHT);
        delay(1000);
        int rechts = landjerobot.measureDistance();
        
        // Kijk weer naar voren
        landjerobot.look(LandjeRobot::LOOK::FORWARD);
        
        if (links > rechts) {
          landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
          landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
        } else {
          landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
          landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
        }
        
         // Rijd weer vooruit
         landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
      } // einde if
    }

```


# Appendix

## Voorbeeld oplossing

```

#include <LandjeRobot.h>

// Aansluitingen van de robot motors.
const int motor[2][4] = {
  {2, 3, 4, 5}, {6, 7, 8, 9}
} ;

// Aansluitingen van de lijn sensoren
const int lineSensors[2] = { 10, 11 } ;
// Lichte vloer met donker lijnen = true
// Donkere vloer met lichte lijnen = false 
const bool lineSensorInverse = true ;

// Omtrek van de wielen in cm
const int wheelRadiusMM = 21 ;
// Afstand tussen de wielen in cm
const int trackWidthMM = 98 ;

// Aansluiting van de ultrasoon sensor
int ultraPin = 13 ;

// Aansluiting van de servo
int servoPin = 14 ;

// Aansluiting van het led 
int mouthledPin = 15 ;

// Aansluiting van de mode schakelaar
int switchPin = 0 ;

LandjeRobot landjerobot(motor, LandjeRobotMotorController::STEPMODE::FULL_STEP, wheelRadiusMM , trackWidthMM, lineSensors, lineSensorInverse, ultraPin, servoPin, mouthledPin, switchPin) ;

int mode = 0;

void setup() {

  // "Lees" de stand van de mode schakelaar
  mode = landjerobot.mode();

  // Laat de robot naar voren kijken
  landjerobot.look(LandjeRobot::LOOK::FORWARD);
  
  // Start met rijden als de robot aangezet wordt en
  // wacht niet
  landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
  
}

void loop() {

  // Als de schakelaar op "1" staat.
  if (mode == 1) {
    // Als er niet niets (!) gedetecteerd wordt door de 
    // reflectie sensors doe dan iets
    if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {
      
      // wacht 30 milliseconden (0,03 seconde)
      delay(30);
      
      // Als beide reflectie sensors een lijn detecteren
      if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {
        // keer de robot om en wacht
        landjerobot.turn(LandjeRobot::TURN::LEFT,180,true);
      }
      
      // Als de reflectie sensors links een lijn detecteren
      if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {
        // Draai 10 graden naar links en wacht
        landjerobot.turn(LandjeRobot::TURN::LEFT,10,true);
      }
      
      // Als de reflectie sensors rechts een lijn detecteren
      if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {
        // Draai 10 graden naar rechts en wacht
        landjerobot.turn(LandjeRobot::TURN::RIGHT,10,true);
      }
      
      // Laat de robot weer verder rijden
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
      
    } // einde if
    
  } else { // Als de schakelaar op "2" staat
  
    // Als er niet niets (!) gedetecteerd wordt door de 
    // reflectie sensors doe dan iets
    if (landjerobot.detectLine() != LandjeRobot::LINE::NONE) {
    
      // wacht 30 milliseconden (0,03 seconde)
      delay(30);
    
      if (landjerobot.detectLine() == LandjeRobot::LINE::LEFT) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
      }

      if (landjerobot.detectLine() == LandjeRobot::LINE::RIGHT) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
      }

      if (landjerobot.detectLine() == LandjeRobot::LINE::BOTH) {
        landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
        landjerobot.turn(LandjeRobot::TURN::LEFT, 180, true);
      }
      
      landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
    } // einde if
  
    // Meet de afstand
    int afstand = landjerobot.measureDistance();

    // Stop als de afstand minder dan 10 cm is.
    if (afstand < 10) {
      
      // Controleer de gemeten afstand
      int totaalafstand = 0;
      for (int x=1; x<=5;x++) {
        totaalafstand = totaalafstand + landjerobot.measureDistance(); 
      }
      
      if (totaalafstand < 50) {
      
        // Stop met rijden
        landjerobot.move(LandjeRobot::DIRECTION::STOP);
        
        // Mopper
        landjerobot.talk(5);
      
        // Meet afstand links van de robot
        landjerobot.look(LandjeRobot::LOOK::LEFT);
        delay(1000);
        int links = landjerobot.measureDistance();
  
        // Meet afstand rechts van de robot
        landjerobot.look(LandjeRobot::LOOK::RIGHT);
        delay(1000);
        int rechts = landjerobot.measureDistance();
        
        // Kijk weer naar voren
        landjerobot.look(LandjeRobot::LOOK::FORWARD);
        
        if (links > rechts) {
          landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
          landjerobot.turn(LandjeRobot::TURN::LEFT, 45, true);
        } else {
          landjerobot.move(LandjeRobot::DIRECTION::BACKWARD, 10, true);
          landjerobot.turn(LandjeRobot::TURN::RIGHT, 45, true);
        }
        
         // Rijd weer vooruit
         landjerobot.move(LandjeRobot::DIRECTION::FORWARD);
      }
    }
  }
}
```
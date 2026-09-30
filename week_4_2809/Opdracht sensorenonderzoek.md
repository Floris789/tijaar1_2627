
Voor de realisatie van een functionele flipperkast is het essentieel om de juiste sensor(en) 
te selecteren die de gewenste interacties en functionaliteiten mogelijk maken. Om tot een 
onderbouwde keuze te komen, is onderzoek nodig. Dit onderzoek leg je vast in een 
onderzoeksverslag en is uiteraard onderdeel van de opleverset. Het onderzoek wordt 
individueel uitgevoerd en iedere student levert een eigen onderzoeksverslag in.  

Het onderzoeksonderwerp richt zich op het analyseren en vergelijken van verschillende 
sensoren op basis van de gegeven requirements. Uit het onderzoeksverslag wordt duidelijk 
waarom voor een bepaalde sensor of bepaalde sensoren is gekozen. Bij de verslaglegging 
is rekening gehouden met de (beperkte) voorkennis van de lezer. 
Bij het selecteren van de sensor voor het detecteren van de metalen speelbal zijn de 
volgende requirements van belang: 

- De sensor moet een metalen speelbal van 12 mm diameter en een massa van 7 
  gram kunnen detecteren. 
- De sensor moet de speelbal binnen 200 ms detecteren. 
- De sensor moet de speelbal minimaal 99 keer detecteren wanneer de speelbal 100 
  keer langskomt. 
  
Het doel van dit onderzoek is om op basis van objectieve criteria een onderbouwde keuze 
te maken voor één of meerdere sensoren. Bronnen zoals literatuur en datasheets worden 
gebruikt en correct vermeld in de bronvermelding. 
## De structuur van het verslag

#### Inleiding 
Het is belangrijk om een onderzoeksverslag te beginnen met een inleiding. De lezer komt zo 
meer te weten over de aanleiding, het onderwerp en het doel van het onderzoek. Omschrijf 
kort het project waaraan gewerkt wordt en waarom onderzoek nodig was. Licht vervolgens 
toe wat het onderzoeksonderwerp is, zonder in detail te treden. Benoem tevens wat dit 
onderzoek zou moeten opleveren (doel).  
#### Onderzoek 
Tijdens dit project onderzoek je in hoeverre verschillende sensoren voldoen aan de vooraf 
opgestelde requirements, zoals hierboven beschreven. 

Voor elke requirement maak je een apart hoofdstuk of paragraaf in je verslag. I

in deze hoofdstukken analyseer je per sensor 
welke eigenschappen relevant zijn en benoem je de relevante technische specificaties.

Per requirement geef je een onderbouwde voorlopige conclusie. Je gebruikt hierbij datasheets 
en literatuur.
 Uiteraard verwijs je naar de gebruikte bronnen. Denk ook na over het 
overzichtelijk brengen van de informatie, waarbij het gebruik van afbeeldingen, tabellen of 
grafieken behulpzaam kan zijn. In dit deel van het verslag maak je dus een vergelijking tussen de verschillende sensoren op basis van de drie gestelde requirements. Deze vergelijkingen vormen de basis voor een gefundeerde keuze voor de meest geschikte sensor(en) voor de flipperkast. De uiteindelijke keuze vermeld je bij de conclusie. 
#### Conclusie  
In de conclusie wordt duidelijk welke sensor(en) het beste is/zijn. De gemaakte keuze wordt 
beschreven, waarbij de keuze onderbouwd wordt met de informatie uit de voorgaande 
hoofdstukken.  In de conclusie mag géén nieuwe informatie over de sensoren naar voren 
komen. 
#### Bronvermelding 
Vermeld de bronnen volgende de IEEE-standaard.

#### Eisen aan het verslag 
• Het verslag is geschreven in markdown;
• Het verslag bevat je studentnummer en de datum waarop je het geschreven hebt; 
• Maximaal 800 woorden (exclusief voorblad en bronnenlijst); 
• Er is een duidelijke inleiding geschreven waarin aanleiding, onderzoeksonderwerp 
  en doel duidelijk worden; 
• Per requirement is getoond welke (technische) specificaties relevant zijn en is een 
  voorlopige conclusie gegeven; 
• Er is een algehele conclusie geschreven die overeenkomt met de deelconclusies en 
  dus geen nieuwe informatie bevat; 
• Er is aantoonbaar gewerkt met bronnen; 
• Er is rekening gehouden met de beperkte voorkennis van de lezer; 
• Het verslag is geschreven in het Nederlands, waarbij we ervan uitgaan dat je een 
  spellingcheck hanteert voordat het ingeleverd wordt. 


#### Floris Kemper      113697      29 september 2026
### 1. Inleiding

Ik ben bezig met een schoolproject waarbij wij een flipperkast moeten maken. Het is belangrijk dat de flipperkast het balletje op verschillende locaties kan detecteren. Hier zou je echter verschillende sensoren voor kunnen gebruiken en in dit onderzoek ga ik verschillende sensoren vergelijken om te kijken welke het best past bij dit project.

Het onderzoeksonderwerp is het analyseren en vergelijken van deze sensoren op basis van drie belangrijke requirements: de sensor moet een metalen speelbal van 12 mm (7 gram) kunnen detecteren, dit binnen 200 ms doen, en minimaal 99% van de keren detecteren.

Het doel van dit onderzoek is om met behulp van bronnen een onderbouwde keuze te maken voor de beste sensor(en).

### 2. Sensoren
In deze paragraaf kijk ik naar welke sensoren er zijn die ik kan gebruiken en vergelijk ze, ik heb hier voor alle sensoren gekozen die in de brooddoos zaten die een balletje kunnen detecteren. Je ziet in dit schema de naam en beschrijving van de sensor, ook heb ik de afstand waarin hij kan detecteren erbij gezet en de snelheid waarop hij detecteert. Daarnaast staat de prijs en beschikbaarheid erbij. Met de beschikbaarheid bedoel ik hoeveel van deze sensor ik al had voor dit project.

|naam|beschrijving|afstand|prijs|beschikbaar|binnen 200 ms detecteren|99% succes?|
|-|-|-|-|-|-|-|
|ir-sensor|Deze sensor gebruikt infrarood licht om de nabijheid te bepalen. Je kan de detectie afstand veranderen door de potmeter die er op zit|2 ~ 30 cm|€0,50 - €1,50|2|✓|✓|
|hefboomknop|Detecteert de bal als hij er tegenaan komt met een vaartje|0 cm|~€0,40|3|✓|X|
|ultrasoon sensor|Deze sensor gebruikt geluid om te kijken hoe ver iets is. Deze geeft wel de afstand maar is niet super precies|2 - 400 cm|€1 - €2|1|✓|X|
|ldr + laser|Hierbij gebruik je een laser om op een ldr te schijnen, dan kan je aan je weerstand van de ldr zien of er iets tussen de laser en ldr zit.|100+ cm|€2,50| 2|✓|✓|
|inductive proximity sensor (LJ18A3-8-Z BX)|Detecteert of er metaal in de buurt is vlak voor de voorkant, maar is vrij groot en onhandig|0.8 cm|~€5|0|✓|✓|

#### requirements
Zoals je kan zien in het diagram hierboven vallen de meeste sensoren binnen de requirements van binnen 200 ms de bal 99 op de 100 keer kunnen detecteren. Alleen de Ultrasoon en hefboomknop werkte niet 99% van de keren nadat ik ze vaak zelf heb getest met de arduino, dus die zal ik niet verder nemen in mijn onderzoek.

#### waar heb ik ze nodig
###### Energizers
In mijn flipperkast wil ik 2 sensoren gebruiken voor de 2 energizers. Hij moet de bal kunnen detecteren als je er overheen gaat. Een sensor zoals de ldr + laser werkt hier niet omdat de ldr tegenover de laser moet staan en dat kan niet als de sensor naar boven is gericht. De proximity en ir sensoren zijn hier wel allebei voor geschikt, dus kies ik hiervoor de ir sensor omdat die goedkoper is.

###### Balverliesdetectie
De bal moet ook kunnen worden gedetecteerd wanneer deze tussen de flippers vallen. Omdat de bal niet altijd precies in het midden valt is hier de proximity sensor niet ideaal. Hier kan ik dus de ir of de ldr gebruiken. Ik heb allebei de ir sensoren al gebruikt bij de energizers dus gebruik ik hier de laser+ldr. Deze is ook heel precies dus is goed te gebruiken

###### Spookjes
Ik moet ook kunnen detecteren of de bal in een van de portjes/spookjes komt. In zo'n spookje wordt de bal geleid op een klein randje. De bal ligt dan op een erg specifieke plek op. Ik zou dit kunnen gaan detecteren met de proximity of ir sensor maar in dit geval werkt het ook om 2 stukjes metaal aan allebei de kanten van de gleuf te plaatsen zodat de stroomkring zich sluit wanneer de bal ertussen zit. Je kan in mijn video zien hoe dit eruit gaat zien.

#### Conclusie
Ik heb gekeken naar de ir, hefboomknop, ultrasoon, inductive proximity en ldr + laser sensoren. Uiteindelijk heb ik gekozen om voor de energizers de ir sensor te kiezen en voor de balverliesdetectie de laser+ldr te nemen. Voor de spookjes gebruik ik elektrisch geleidend materiaal om de bal te detecteren.


[1] "Inductive Proximity Switch LJ18A3-8-Z/BX," Datasheet, Geeks Valley. [Online]. Available: https://geeksvalley.com/wp-content/uploads/2021/06/Proximity-Switch-LJ18A3-8-Z-BX.pdf. [Accessed: Sep. 29, 2026].

[2] "Arduino IR Infrared Obstacle Avoidance Sensor Module," Datasheet, IndiaMART. [Online]. Available: https://5.imimg.com/data5/YT/KV/MY-1833510/arduino-ir-infrared-obstacle-avoidance-sensor-module.pdf. [Accessed: Sep. 29, 2026].

[3] "Ultrasonic Ranging Module HC-SR04," Datasheet, Elec Freaks / SparkFun Electronics. [Online]. Available: https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf. [Accessed: Sep. 29, 2026].
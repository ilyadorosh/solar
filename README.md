# Solar Laser Tag


Notes

- Signal source = switch ( color ) { case BLUE : player = PLAYER1; break; }
  - или PWM or specific frequencies

----------------------------------

Data sheet

| Item | Purpose | Qty |
| --- | --- | --- |
| Arduino nano | &quot;Enemy fire&quot; - generate 100Hz laser beams, gun logic, sound, | 1 |
| Solar panels | Detecting laser, charge the battery | 5 |
| ADC **Pi** Plus or MCP3008 | High sample rate signal from solar panels for Raspberry | 1 |
| Raspberry pi | Signal processing, neural network, ctrl lights | 1 |
| Camera on servos | Detect laser by looking at it&#39;s body | 1 |

Game logic

Ammo

Clips

Empty? Reloading\_time

Health  Damage distribution model Time Win

Sound

TODO list

- --LED damage analog.write();
- -- Surface detection lenses+photoresistors or solar  ✓
- --PULL\_UP mode , remove resistor 10kOm , light sensor

 ![](https://pbs.twimg.com/media/DHI9k2hWAAAPusz.png)
 
 ## Roadmap
 
Project &quot;Photosynth&quot;

Servos raise &#39;leaves&#39; panels to the sun when it&#39;s safe. It synthesizes music based on its surroundings  by neural net.


# Solar Laser Tag


### Notes

```c 
Signal_source = switch ( color ) { case BLUE : player = PLAYER1; break; } 
```
  - или PWM or specific frequencies

----------------------------------

### Data sheet

| Item | Purpose | Qty |
| --- | --- | --- |
| Arduino nano | &quot;Enemy fire&quot; - generate 100Hz laser beams, gun logic, sound, | 1 |
| Solar panels | Detecting laser, charge the battery | 5 |
| ADC **Pi** Plus or MCP3008 | High sample rate signal from solar panels for Raspberry | 1 |
| Raspberry pi | Signal processing, neural network, ctrl lights | 1 |
| Camera on servos | Detect laser by looking at it&#39;s body | 1 |

### Game logic
- Ammo
- Clips
- Empty? Reloading\_time
- Health  Damage distribution model Time Win
- Sound

### TODO list

- `analogWrite(ledPin, damage); ` ✓
- Surface detection lenses+photoresistors or solar  ✓
- PULL\_UP mode , remove resistor 10kOm , light sensor  ✓

 ![](https://pbs.twimg.com/media/DHI9k2hWAAAPusz.png)
 
## Roadmap

### Perpetual watchman
- hours of purposeless wandering around places, unreachable for self-driving vehicles before
- realtime action with voting about the directions and missions from people sorted by distance from it, among other factors
- bids to serve a purpose, like "go see if my son is ok", which provides monetization for maintenance
- a way to cryptographically prove incredible or rare incidents for everybody who cares
- publishes events on blockchain 
- open source nature guarantees the transparancy and ability to collaborate on the development (we1c0m3!)
- durability and sustainability competition

#### Market size
- on-demand economy, which literrally means, that there's a demand
- asks are too specific, so it is trading like a different service
- the thresholds are 
  - internet of animals
- the goal is to provide liquidity for the market on the supply side

value = - anxiety
anxiety is the cumulative effect of pending tasks over time 

<img src="https://latex.codecogs.com/gif.latex?\textsl{anxiety}&space;=&space;\sum&space;\limits_{t_{0}}^{t_{now}}&space;\mathbf{Importance}&space;(&space;\texttt{Tasks}[t]&space;)*t" title="\textsl{anxiety} = \sum \limits_{t_{0}}^{t_{now}} \mathbf{Importance} ( \texttt{Tasks}[t] )*t" />




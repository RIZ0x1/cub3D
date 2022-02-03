# cub3D

cub3D is a pseudo 3D first person game that is most similar to Wolfenstein3D

## Wolfenstein:
![wolf](https://user-images.githubusercontent.com/62781747/152361688-d184dd5a-4654-4678-a7bc-0f8cda89db60.jpeg)

## Cub3D
<img width="1197" alt="cub3D" src="https://user-images.githubusercontent.com/62781747/152361858-e48ffad2-526f-4132-b0b0-cd14bd097c61.png">

## MacOS

First, of course, you need to clone the repo
```
git clone https://github.com/RIZ0x1/cub3D.git
```
Now in the cloned repository root:
```
make
```
To run the game, you have to specify a path to configuration file that contains following options:

Window resolution: R WIDTH HEIGHT </br>
Path to west walls texture file: WE PATH </br>
Path to east walls texture file: EA PATH </br>
Path to north walls texture file: NO PATH </br>
Path to south walls texture file: SO PATH </br>
Color of the ceiling: C R,G,B </br>
Color of the floor: F R,G,B </br>
A map where symbol '1' is a wall, '0' is an empty space and W/E/N/S is player's initial location. </br>

## Configuration file example

```
R 1200 800
WE ./TXT/silent_hill_we.png
EA ./TXT/silent_hill_ea.png
SO ./TXT/silent_hill_so.png
NO ./TXT/silent_hill_no.png
C 250,0,0
F 0,250,0

111111111111111111111111111111111
1000000000000000S0000000000000001
111111111000000111111111111111111
111111111000000111111111111111111
111111111000000111111111111111111
100000000000000000000000000000001
100000000000000000000000000000001
100000000000000000000000000000001
100000000000000000000000000000001
111111111111111111111111111111111
```

## Running

To start a game write this line to console:

```
./cub3D ./path_to_config.cub
```

Where ./path_to_config.cub is obviously path to config file (it must have .cub extension). </br>
Also you can take a picture from the game doing this:

```
./cub3D ./path_to_config.cub --save
```

Option <b> --save </b> creates a .bmp image in <b>.</b> directory

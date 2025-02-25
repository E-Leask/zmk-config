# Fast Hotswappable Keyboard Design and Development Guide
![image](https://github.com/user-attachments/assets/aa6bfe46-b2ad-4530-afa4-f838601ec1d9)
This guide covers the following keyboard development stages: 
- Layout
- Plate 
- Shell 
- Wiring(Solderless)
- Firmware
  
This will include details on what I found to be the fastest way to go from a keyboard idea to a functioning prototype and hopefully save you time in your development process. This project focuses on simple CAD Design, minimal soldering, and flexibility to experiment layout changes at any point in the design process. 
For reference this guide will show the development of a split bluetooth keyboard with a custom layout.
## Bill of Materials(Aliexpress)
|Quantity| Part | Cost(CAD) |
|---|---|---|
|110| Outemu Half Height Switches| 30$ |
|2| ProMicro NRF52840 | 10$ |
|2|Li-Ion Battery | 10$ |
|100|1N5252B Diode|5$|
|1|22 AWG Copper Wire|5$|
|1|Insulated 22 AWG Solid Core Wire|5$|
|N/A|Filament|5$|
|Total||70$|
## Requirements 
This guide is expecting you have access to a 3d printer, basic CAD modeling experience, and some minimal experience soldering. While not a requirement all CAD modeling is done in Fusion 360, your mileage may vary on my CAD procedures if you model in other software.
## This Is Not 
Intended for keyboards with 3D formations such as key wells. Chosen process for defining layouts was not intended for designing in 3D space(If you prove me wrong though I have no complaints).
## Defining a Layout
![image](https://github.com/user-attachments/assets/870445ac-7433-4bbb-8294-93b21517fd1b)
[keyboard-layout-editor.com](https://www.keyboard-layout-editor.com/#/) meets two criteria.
1. Intuitive UI, that supports quickly development 
2. Exports to a format that can be used later for CAD modelling
If starting from scratch, I recommend loading the ANSI 104 preset from the Preset dropdown. Here you can remove and reorganze keys as desired. Remember you can save you layouts to tweak at a later time.
## Experimental Plates
Before building a complete keyboard shell I recommend hands-on experimenting and iterating with your layout. 
![image](https://github.com/user-attachments/assets/a6075627-a38d-4c1b-8052-ccc8ebc6e0e3)
After deciding on a layout, copy the text in the raw data tab and head over to [kbplate.ai03.com](https://kbplate.ai03.com/)
![image](https://github.com/user-attachments/assets/c7a72260-71e1-497e-8871-4ca8b1e62f28)
Paste the kle data you just copied to generate a plate for your layout. Download your plate in the .dxf format. 
![image](https://github.com/user-attachments/assets/faf80720-9cc3-424e-b29a-aedf89527ab2)
### Warnings/Tips
I've encountered some issues with some switches not fitting if these fillet radius are not 0.
![image](https://github.com/user-attachments/assets/1925cb3d-0e65-4ac3-ad63-664989b19de5)
### Load in CAD Software
In Fusion 360, the .dxf you just downloaded can be inserted to create a sketch.
![image](https://github.com/user-attachments/assets/a95f1e57-2d80-4ad0-82b7-a9e40c505a0c)
![image](https://github.com/user-attachments/assets/2b8d8b10-43a0-4954-9f2e-28dd10560e50)
Extrude the sketch. 1.6mm thick is a good starting point, and export for printing.
![image](https://github.com/user-attachments/assets/6662ad78-3aff-4223-b00b-5c18680e3b85)
#### Hindsight 
Technically I could have made two seperate layouts on keyboard layout editor. However, with the requirement to fit back together into non-split keyboard, I had an extra step here making the seam for the plates.
### Try it out!
Grab those switches you've been planning to build the keyboard around and pop them into the plate. This is the easiest point to make modifications to your layout so experiment and see what is most comfortable for your hands. If you think you need to try your layout with some keycaps and you don't have any yet, try these easy to print [low profile keycaps](https://www.thingiverse.com/thing:5180641)  from thingiverse.
![image](https://github.com/user-attachments/assets/1804e2ae-1ecc-414e-a06b-128a8ff101d8)
- Do you like the layout?
- As there any wiggle due to wrong plate thickness?
- Any issues with fillet radius as mentioned in Warnings above?

When you're satisified with the plate move onto the shell
### Warnings/Tips
Fill the plate with switches. Switch fit in the plate holes will tighten as you put more switches, so some looseness with a single switch may actually be fine when you put all the swtiches in. This is not a guarentee, just a point to check.
## Shell
For prototyping purpose a very simple shell like this one will be enough to get you to a functional board.
![image](https://github.com/user-attachments/assets/53094511-7962-4719-8693-33fd0b9d0319)
### Depth of Shell (And Context at Future Steps)
![image](https://github.com/user-attachments/assets/92a83315-7435-4016-830b-cf89038bf150)
This keyboard will be using [No Solder Hot Swap Sockets](https://www.printables.com/model/983852-no-solder-hot-swap-socket-for-handwired-mechanical/files) for wiring. Print one out, pop it on a switch to get an idea of the depth your shell needs. Give an extra mm of depth for wires.
### Other Notes
My shell includes additional space on the top edge to include 2mm holes for wiring.
![image](https://github.com/user-attachments/assets/84535ae2-5850-4d09-97cc-86d30b26212d)

## Wiring
### (Mostly)Solderless Hotswappable Matrix 
By the end of this section, you will have a matrix that looks something like this 
![image](https://github.com/user-attachments/assets/ce7c51ba-3474-493f-8679-c043caf95330)

The keyboard uses [No Solder Hot Swap Sockets](https://www.printables.com/model/983852-no-solder-hot-swap-socket-for-handwired-mechanical/files) for switch connections. One big benefit is these sockets also hold the [diode](https://www.digikey.com/en/products/detail/microchip-technology/1N5252B-DO-35/261375).
Follow this [Building Sockets](https://github.com/stingray127/handwirehotswap/tree/main/Socket) guide to assemble as many as you need.
After that follow the guide to make the [Matrix](https://github.com/stingray127/handwirehotswap/tree/main/Matrix)
#### Warnings/Tips
- Documents use SWG for wire gauge. The equivalent in AWG is 22 AWG wire. I accidentally used 24 AWG wire for the columns on the left split which caused some connectivity issues for switches. 
- If you want to use a breadboard like i did and want to skip some soldering, leave yourself an extra 5cm of wire on the top side of the columns to hook directly into the breadboard.
![image](https://github.com/user-attachments/assets/2effd49b-bde8-4eed-a25b-9869f224f7b4)
- The section on making the rows uses outdated photos. The steps are correct, the last photo in the row instructions is how it should look.
- Giving yourself slack in the column wires and very handing if you decide to change the layout.
#### Benefits of this Hotswappable Matrix
Even at this stage after making this matrix, the layout is still very easy to adjust. Rows and columns can be shifted and added to for layout adjustments. I literally printed a plate flipped and was able to reuse the matrix by shifting the rows.  
### Soldering
The only soldering required is to solder wires to the rows for connecting to the microcontroller
![image](https://github.com/user-attachments/assets/e6e06d50-6d43-4ac6-a3d7-51484a6cdc1a)

## Hindsight
Alternatively, you could try to connect to the rows at the row ends. Benefit is better adjustability in the future without redoing the rows, but you run the risk of some issues getting the wires out. Replace the row wiring is very simple so i went with the soldering points that were easiest to me.

### Breadboard
Getting into the breadboard I should mention the microcontroller used, the ProMicro NRF52840. It's cheap, supports bluetooth, and is compatible with Nice! Nano V2.0 in the ZMK Firmware
Hooking up to the NRF52840, the only reason followed was to keep row pins and column pins together, review its schematics for more details.
![image](https://github.com/user-attachments/assets/009de487-ca23-4c1b-9c7c-5905e72ff37d)

## Firmware(ZMK)
From here this is up to. If you've imitated my keyboard exactly, you could hypothetically use the firmware compiled from this repo and try it out. Feel free to use this repo as reference for your own designs.
### Tips
When making a config from scratch start simple, and add functionality piece by piece. For example: I start with a 1 key keyboard, then add rows and columns, then add bluetooth, then add the split support.

## Conclusion
Future development could include encoders and mouse control using the remaining space on the breadboard or replacing a switch.
3D Printed keycaps are not recommended. The print bed texture is very rough on your hands and is not a great typing experience. 













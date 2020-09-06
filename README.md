# Prototype Series No.02
Chord-like sounds with a ribbon controller.

## Preparation
- OSC
  - LFO depth : S100
- ARP
  - On/Latch
  - Arpegglator setting : Octave (= Default)

## How to play
Change these parameters.
- OSC
  - A knob (Range of arpegglator)
  - B knob (Threshold for arpegglator pattern)
  - parameter 1 (Chord Type)
  - LFO rate (Arpegglator pattern)
- ARP
  - ARP pattern length (Arpegglator pattern)

# Parameters
- shape (NTS-1: A, other: Shape)  
Range of arpegglator.
- shiftshape (NTS-1: B, other: Shift+Shape)  
Threshold for arpegglator pattern.
- parameter 1  
Chord Type (1 .. 5)
- parameter 2  
Octave (1 .. 6)
- parameter 3  
  1. Pulse
  1. Saw
  1. Tri

# How to build
1. Clone (or download) and setup [logue-sdk](https://github.com/korginc/logue-sdk).
1. Clone (or download) this project.
1. Change `PLATFORMDIR` of Makefile according to your environment.

# LICENSE
Copyright 2020 Tomoaki Itoh
This software is released under the MIT License, see LICENSE.txt.

# AUTHOR
Tomoaki Itoh(neko) techno.cat.miau@gmail.com

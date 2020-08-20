# RSLK LINE FOLLOWER

## Table Of Contents

1. [Introduction](#introduction)

2. [Build Status](#build-status)

3. [Requirement](#requirement)

4. [Installation](#installation)

5. [Usage](#usage)

6. [Contribute](#contribute)

## Introduction

In this project, we used a path sensing RLSK car to follow a track. The track consisted of turns, straight lines, intersection and a section for the car to do a U-turn. Our objective was to complete the entire tracks (Straight and Ribbon) within a limit of time (5 minutes for both tracks). Additionally, we also want to understand the basic theory behind a path sensing car as well as the microcontroller system to have the car appropriately respond as it is moving through the track. The software we used to
program our car is called Energia. Since the car has photosensors underneath, we used the measurements from these sensors to calculate a single value that roughly represent the position of the car, which is known as sensor fusion. From this we then used a feedback system that will calculate adjustments for the speed of the wheels as it is turning, doing a u-turn, or maintaining its center on the track. Our feedback system consisted of using PID theory to calculate the adjustments.

## Build Status

[![Build Status](https://travis-ci.com/travis-ci/travis-web.svg?branch=master)](https://travis-ci.com/travis-ci/travis-web)

## Requirement

1. [`RSLK`](https://www.ti.com/tool/TIRSLK-EVM?utm_source=google&utm_medium=cpc&utm_campaign=corp-uni-null-TI_RSLK-cpc-evm-google-wwe&utm_content=TI_RSLK&ds_k=%7b_dssearchterm%7d&DCM=yes&gclsrc=aw.ds&&gclid=Cj0KCQjwvvj5BRDkARIsAGD9vlJI1zqnnREgF4mMczEKBWxNPQkQg95l3UNlO9_cNLXXlml4rl71JPUaApbkEALw_wcB) and build the robot with the guideline

2. Download and install the latest version of [`Energia`](https://energia.nu/download/)

3. Download [`Driver`](http://s3.amazonaws.com/energiaUS/files/energia_drivers.zip) for Energia  

## Installation

1. Open Energia after unzipping

2. *Tools -> Board -> Boards Manager*

3. Install *Energia MSP432 ENT RED boards* package

4. *Sketch -> Include Library -> Add .ZIP Library*

5. Browse to the RSLK_library.zip

## Usage

1. Connect RSLK car to the computer

2. Open Energia

3. *File -> Open* and browse to RSLK_car.ino file

4. Upload to the RSLK by click -> underneath the Edit menu

5. Enjoy the ride

## Contribute

1. Fork it

2. Create your feature branch

3. Commit your changes

4. Push to the branch

5. Create a new Pull Request  

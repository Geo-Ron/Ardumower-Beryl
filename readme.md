# Beryl

Beryl could be the daughter firmware of Azurit and AzuritBer.

## My Objectives
- Learn the software aspects and (hardware) components of the Ardumower platform and C++
- Learn to build and improve functional software for the Ardumower
- Learn how a differential drive robot lawn mower can and should function in the real world that is 'my garden'
- Try to create a functional firmware for the Ardumower that has all the best of both firmwares.
- If I succeed in the above objectives, give the firmware back to the Ardumower community and work together on improving it

To sum this up:
- Learn
- Try
- Improve
- Repeat the above ;-)

## High Level Firmware Objective

Create an Ardumower firmware that:
- [ ] Is modular built
- [ ] Everything is built on the service model
- [ ] Is based on a more robust architecture
  - [ ] [Subsumption](https://en.wikipedia.org/wiki/Subsumption_architecture)
  - [ ] [DAMN](https://en.wikipedia.org/wiki/Distributed_architecture_for_mobile_navigation)
- [ ] Honours perimeter wire boundaries
- [ ] Can mow in lanes
- [ ] Tries to avoid an object, and continue it's path
- [ ] Moves in a smooth way
  - [ ] Makes full use of the odometry capabilities
- [ ] Tries to use the shortest path to the charging station as possible
- [ ] Has App integration (the Ardumower app)
- [ ] Has HomeAssistant integration
  - [ ] To not start mowing if rain is coming

## Current State

Non working - complete onder development.